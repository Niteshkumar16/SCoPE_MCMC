#!/bin/sh

#export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:/data1/pdf/cjayanti/Software/cfitsio/lib:/opt/openmpi/1.3/lib:/usr/lib/gcc/x86_64-redhat-linux/4.1.1:/usr/lib/gcc/x86_64-redhat-linux/4.1.1:/app/run/cskumar/backupcet/dir/mywork/ur_softwares/intel/fce/10.1.015/lib:/data1/soft/gsl/lib
#./test
#export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:/app/run/csantanud/intel/composer_xe_2011_sp1.9.293/compiler/lib/intel64:/app/run/csantanud/intel/Compiler/11.0/083/lib/intel64/original

#export PATH=/data1/student/csantanud/gsl-1.9/gsl-1.9/lib:/usr/lib64/:/opt/software/intel/impi/4.1.0.024/intel64/lib:/opt/soft/lib:${PATH}
#mpirun -np 31 mcmc1

LD_LIBRARY_PATH=$HOME/gsl/lib:/usr/lib64/:/opt/software/intel/impi/4.1.0.024/intel64/lib:/opt/soft/lib:/scratch/csantanud/intel/composer_xe_2011_sp1.9.293/compiler/lib/intel64:$LD_LIBRARY_PATH
export LD_LIBRARY_PATH

ulimit -s unlimited
#bsub -n 16 -e test.err -o test.out 
nohup mpirun -np 16 ./mcmc1 &

