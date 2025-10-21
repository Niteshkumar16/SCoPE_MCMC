rm *.o
#mpicc -I/data0/soft/gsl/include -c cmbans.c
mpicc -I/data1/soft/gsl/include -c test.c -lrt

#mpif90 -o mcmc1 -nofor-main -L/opt/openmpi/1.3/lib -lmpi_f90 /data1/pdf/cjayanti/Software/lapack-3.2.2/lapack_LINUX.a  /data1/pdf/cjayanti/Software/lapack-3.2.2/blas_LINUX.a -L/usr/lib/gcc/x86_64-redhat-linux/4.1.1 -lgfortran -D__GFORTRAN__ -DGFORTRAN -L/usr/lib/gcc/x86_64-redhat-linux/4.1.1 -lstdc++ -L/app/run/cskumar/backupcet/dir/mywork/ur_softwares/intel/fce/10.1.015/lib -lguide -L/data1/soft/gsl/lib -lgmp -lgsl -lgslcblas -lm 

#mpicc -o mcmc1 mcmc1.o cmbans.o -I/data1/soft/gsl/include -L/data1/soft/gsl/lib -lgmp -lmpi -lgsl -lgslcblas -lm


mpicc -o test test.o -I/data1/soft/gsl/include -L/data1/pdf/cjayanti/Software/cfitsio/lib -lcfitsio -L/opt/intel.org/composer_xe_2011_sp1.8.273/compiler/lib/intel64 -lifcore -L/opt/intel.org/composer_xe_2011_sp1.8.273/compiler/lib/intel64 -lsvml /data1/student/csantanud/lapack-3.4.1/liblapack.a  /data1/student/csantanud/lapack-3.4.1/librefblas.a -L/usr/lib/gcc/x86_64-redhat-linux/4.1.1 -lstdc++ -L/app/run/cskumar/backupcet/dir/mywork/ur_softwares/intel/fce/10.1.015/lib -lguide -L/usr/lib64 -lpthread -L/data1/soft/gsl/lib -lmpi -lgmp -lgsl -lgslcblas -lm -limf -lsvml -lintlc -lrt

rm test.err
rm test.out
#-L/usr/lib/gcc/x86_64-redhat-linux/4.1.1 -lgfortran -D__GFORTRAN__ -DGFORTRAN
# -L/opt/openmpi/1.3/lib -lmpi_f90
# -L/opt/hpmpi/lib/linux_amd64 -lmpi 
#-I/data1/student/csantanud/likelihood_v4#-L/opt/pgi/linux86/7.0-7/liblf -lpgc -L/opt/pgi.9.0-4/linux86-64/9.0-4/lib -lacc1 -L/usr/lib -ldl -L/opt/pgi/linux86/7.0-7/lib -lnspgc
