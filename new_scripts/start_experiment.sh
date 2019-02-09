gcc -O2 ../matmul_cache_oblivious.c -o ./cobli_$1.o
./create_jobscript_loads.sh cobli_$1.o
./create_jobscript_stores.sh cobli_$1.o
sbatch --wait ./cobli_$1.o_loads.sh 
sbatch --wait ./cobli_$1.o_stores.sh
python parse_output_loads.py ./cobli_$1.o $2
python parse_output_stores.py ./cobli_$1.o $2
cp *$1*.csv results/
