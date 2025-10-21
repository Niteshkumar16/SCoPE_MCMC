#Setting CAMB
1. Put the interface2.f90 file in CAMB/fortran
2. then change the Makefile_main in CAMB/fortran folder with the one here in the standard_6_param one 
3. after that run these commands in series :-
- make all
- make python
this will create the Release and Releaselib in the fortran folder which conatins both libcamb.a and camblib.so files and this will also compile the interface2.f90 as .o and .mod file in the Release and Releaselib folder
4. give the path for the planck libraries and header fles, camblib.so and other while compiling.
