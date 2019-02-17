#!/bin/bash


name="$1"_"$2"_"$3"_"$4"_"$5"_"$6"

echo "#!/bin/bash" > "$name".sh

echo "" >> "$name".sh
echo "" >> "$name".sh

echo "#SBATCH -J "$name"           # Job name" >> "$name".sh
echo "#SBATCH -o "$name".out       # Name of stdout output file" >> "$name".sh
echo "#SBATCH -e "$name".err       # Name of stderr error file" >> "$name".sh
echo "#SBATCH -p skx-normal          # Queue (partition) name" >> "$name".sh
echo "#SBATCH -N 1               # Total # of nodes (must be 1 for serial)" >> "$name".sh
echo "#SBATCH -n 1               # Total # of mpi tasks (should be 1 for serial)" >> "$name".sh
echo "#SBATCH -t 05:00:00        # Run time (hh:mm:ss)" >> "$name".sh
echo "#SBATCH --mail-user=anjana.subramanian@utexas.edu" >> "$name".sh
echo "#SBATCH --mail-type=all    # Send email at begin and end of job" >> "$name".sh
echo "#SBATCH -A EE382N-20 # Allocation name (req'd if you have more than 1)" >> "$name".sh


echo "" >> "$name".sh
echo "" >> "$name".sh

echo "module unload xalt" >> "$name".sh

echo "/opt/apps/gcc/7.1.0/bin/gcc -O2 -DSIZE="$2" -DB1="$3" -DB2="$4" "$1".c -o "$name"" >> "$name".sh

echo "../../../pin -t obj-intel64/dcache_2level.so -a 8 -b 64 -c "$5" -aa 16 -bb 64 -cc "$6" -o "$name".txt -- ./"$name"" >> "$name".sh

sbatch "$name".sh

#echo "lscpu" >> "$1"_loads.sh

#echo "echo \"Script loop beginning - Total of \$N iterations\"" >> "$1"_loads.sh

#echo "for i in {1..20} #Change number of iterations here." >> "$1"_loads.sh
#echo "do" >> "$1"_loads.sh
#for i in {1..20}
#do
#echo "./pmu-tools/pmu-tools/ocperf.py stat -e cycles:u,instructions:u,L1-dcache-loads:u,l2_rqsts.demand_data_rd_hit:u,l2_rqsts.demand_data_rd_miss:u,LLC-load-misses:u ./"$1"" >> "$1"_loads.sh
#echo "./pmu-tools/pmu-tools/ocperf.py stat -e cycles:u,instructions:u,L1-dcache-loads:u,L1-dcache-load-misses:u,l2_rqsts.demand_data_rd_hit:u,offcore_response.demand_data_rd.l3_hit.any_snoop:u ./"$1"" >> "$1"_loads.sh
#done
#echo "done" >> "$1"_loads.sh



