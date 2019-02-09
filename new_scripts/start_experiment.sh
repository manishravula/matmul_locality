#Script to start experiments easily and generate results.
#The script holds the terminal busy until the results are processed. So you might want
#to multiplex it with tmux/screen. Also, you can't submit jobs while these are going on.

#args: $1: Name of the code executing. $2 Name of the experiment, $3 Size of the matrix to be passed on to the Python script.

#Make a results subfolder if it doesn't already exist.
#Expected directory structure: base1/matmul_locality/    -> All c programs
#			       base1/matmul_locality/newscripts -> This shell script.

gcc -O2 ../$1 -o ./$2.o
./create_jobscript_loads.sh $2.o
./create_jobscript_stores.sh $2.o
sbatch --wait ./$2.o_loads.sh 
sbatch --wait ./$2.o_stores.sh
python parse_output_loads.py ./$2.o $3
python parse_output_stores.py ./$2.o $3
cp *$2*.csv results/
tail results/*$2*.csv -n 4
