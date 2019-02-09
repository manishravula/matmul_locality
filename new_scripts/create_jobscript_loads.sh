#!/bin/bash



echo "#!/bin/bash" > "$1"_loads.sh

echo "" >> "$1"_loads.sh
echo "" >> "$1"_loads.sh

echo "#SBATCH -J myjob           # Job name" >> "$1"_loads.sh
echo "#SBATCH -o "$1"_loads.out       # Name of stdout output file" >> "$1"_loads.sh
echo "#SBATCH -e "$1"_loads.err       # Name of stderr error file" >> "$1"_loads.sh
echo "#SBATCH -p skx-dev          # Queue (partition) name" >> "$1"_loads.sh
echo "#SBATCH -N 1               # Total # of nodes (must be 1 for serial)" >> "$1"_loads.sh
echo "#SBATCH -n 1               # Total # of mpi tasks (should be 1 for serial)" >> "$1"_loads.sh
echo "#SBATCH -t 00:10:00        # Run time (hh:mm:ss)" >> "$1"_loads.sh
echo "#SBATCH --mail-user=anjana.subramanian@utexas.edu" >> "$1"_loads.sh
echo "#SBATCH --mail-type=all    # Send email at begin and end of job" >> "$1"_loads.sh
echo "#SBATCH -A EE382N-20 # Allocation name (req'd if you have more than 1)" >> "$1"_loads.sh


echo "" >> "$1"_loads.sh
echo "" >> "$1"_loads.sh

echo "lscpu" >> "$1"_loads.sh

#echo "echo \"Script loop beginning - Total of \$N iterations\"" >> "$1"_loads.sh

#echo "for i in {1..20} #Change number of iterations here." >> "$1"_loads.sh
#echo "do" >> "$1"_loads.sh
for i in {1..20}
do
#echo "./pmu-tools/pmu-tools/ocperf.py stat -e cycles:u,instructions:u,L1-dcache-loads:u,l2_rqsts.demand_data_rd_hit:u,l2_rqsts.demand_data_rd_miss:u,LLC-load-misses:u ./"$1"" >> "$1"_loads.sh
echo "./pmu-tools/pmu-tools/ocperf.py stat -e cycles:u,instructions:u,L1-dcache-loads:u,L1-dcache-load-misses:u,l2_rqsts.demand_data_rd_hit:u,offcore_response.demand_data_rd.l3_hit.any_snoop:u ./"$1"" >> "$1"_loads.sh
done
#echo "done" >> "$1"_loads.sh



