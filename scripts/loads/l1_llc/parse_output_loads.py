#!/bin/python

import sys

infile = open(sys.argv[1]+"_loads.err", "r")
outfile = open(sys.argv[1]+"_loads.csv", "w")

def mean(data):
    """Return the sample arithmetic mean of data."""
    n = len(data)
    if n < 1:
        raise ValueError('mean requires at least one data point')
    return sum(data)/float(n) # in Python 2 use sum(data)/float(n)

def _ss(data):
    """Return sum of square deviations of sequence data."""
    c = mean(data)
    ss = sum((x-c)**2 for x in data)
    return ss

def stddev(data, ddof=0):
    """Calculates the population standard deviation
    by default; specify ddof=1 to compute the sample
    standard deviation."""
    n = len(data)
    if n < 2:
        raise ValueError('variance requires at least two data points')
    ss = _ss(data)
    pvar = ss/(n-ddof)
    return pvar**0.5




gflops_list = []
l1_locality_list = []
l2_locality_list = []
l3_locality_list = []

outfile.write("Cycles, Instructions, L1 Loads, L1 Load Misses, LLC Loads, LLC Load Misses, Time Elapsed, GFLOPS, L1 Load Locality, LLC Load Locality\n")

while(1):
	line = infile.readline()
	if line.isspace():
		continue
        else:
		break

while(1):
	line = infile.readline()
        if not line:
		break
	if line.lstrip().split(' ', 1)[0] == 'Performance':
		continue
        if line.isspace():
		continue
	
	cycles = line.lstrip().split(' ',1)[0]
	cycles = cycles.replace(',', '')
        line = infile.readline()
        instructions = line.lstrip().split(' ',1)[0]
        instructions = instructions.replace(',', '')
        line = infile.readline()
        l1_loads = line.lstrip().split(' ',1)[0]
	l1_loads = l1_loads.replace(',', '')
        line = infile.readline()
        l1_load_misses = line.lstrip().split(' ',1)[0]
	l1_load_misses = l1_load_misses.replace(',', '')
        line = infile.readline()
        llc_loads = line.lstrip().split(' ',1)[0]
	llc_loads = llc_loads.replace(',', '')
        line = infile.readline()
        llc_load_misses = line.lstrip().split(' ',1)[0]
        llc_load_misses = llc_load_misses.replace(',', '')
        line = infile.readline()
	line = infile.readline()
	time_elapsed = line.lstrip().split(' ',1)[0]
	time_elapsed = time_elapsed.replace(',', '')     

	
	float_ops = 2 * int(sys.argv[2]) * int(sys.argv[2]) * int(sys.argv[2])
	total_time = float(cycles) / (2100 * 1000000.0)        
	gflops = float_ops  / (total_time * 1000000 * 1000)

	l1_load_hits = int(l1_loads) - int(l1_load_misses)
	l1_load_locality = float(l1_load_hits)/float(l1_loads) 


	l3_load_hits = int(llc_loads) - int(llc_load_misses)
 	l3_load_locality = float(l3_load_hits)/float(llc_loads)

	gflops_list.append(gflops)
	l1_locality_list.append(l1_load_locality)
	l3_locality_list.append(l3_load_locality)

	outfile.write(cycles + ", " + instructions + ", " + l1_loads + ", " + l1_load_misses + ", " + llc_loads + ", " + llc_load_misses + ", " + time_elapsed + ", " + str(gflops) + ", " + str(l1_load_locality) + ", " + str(l3_load_locality) + "\n")		



outfile.write("\n\n")
gflops_mean = mean(gflops_list)
gflops_stddev = stddev(gflops_list)
gflops_rel_sd = gflops_stddev * 100.00 / gflops_mean 
outfile.write("GFLOPS, " + str(gflops_mean) + ", " + str(gflops_stddev) + ", " + str(gflops_rel_sd) + "%" + "\n")


l1_locality_mean = mean(l1_locality_list)
l1_locality_stddev = stddev(l1_locality_list)
l1_locality_rel_sd = l1_locality_stddev * 100.00 / l1_locality_mean
outfile.write("L1 LOAD LOCALITY, " + str(l1_locality_mean) + ", " + str(l1_locality_stddev) + ", " + str(l1_locality_rel_sd) + "%" + "\n")

#l2_locality_mean = mean(l2_locality_list)
#l2_locality_stddev = stddev(l2_locality_list)
#l2_locality_rel_sd = l2_locality_stddev * 100.00 / l2_locality_mean
#outfile.write("L2 LOAD LOCALITY, " + str(l2_locality_mean) + ", " + str(l2_locality_stddev) + ", " + str(l2_locality_rel_sd) + "%" + "\n")

l3_locality_mean = mean(l3_locality_list)
l3_locality_stddev = stddev(l3_locality_list)
l3_locality_rel_sd = l3_locality_stddev * 100.00 / l3_locality_mean
outfile.write("L3 LOAD LOCALITY, " + str(l3_locality_mean) + ", " + str(l3_locality_stddev) + ", " + str(l3_locality_rel_sd) + "%" + "\n")











