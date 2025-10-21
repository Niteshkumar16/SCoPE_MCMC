The main CAMB code supports smooth dark energy models with constant equation of state and sound speed of one, or a quintessence model based on a potential. This modified code generalizes it to support a time-dependent equation of state w(a) that is allowed to cross the phantom divide, i.e. w=-1 multiple times by implementing a Parameterized Post-Friedmann(PPF) prescription for the dark energy perturbations (see references below). 

The originally released code is based on the CAMB version of September 2008. This release updates it to the current CAMB version of January 2012. NOTE: currently, this updated version is incomplete in including perturbations of massive neutrinoes. You may want to use the original version, or check this website at a later date, if you want to use the PPF module to study massive neutrinoes. Three files are modified: equations.f90, inidriver.F90, and params.ini. The modified code supports two options to specify w(a), 

 - By setting usew0wa in params_cross.ini to be true, the code reads in w_0, w_a, and w(a) is given by w(a)=w_0+w_a(1-a). 

 - By setting usew0wa to be false, w(a) is specified by a user-supplied file whose name is given by wafile in params_cross.ini. The file should provide a series of (a_i,w_i) in increasing order of {a_i}, and the size of the series should always <=nwmax, which is set to be 5000 by default. You can increase nwmax in LambdaGeneral in equations_cross.f90 if your wafile has a larger size. The code then does an interpolation for w(a) for a within the range spanned by {a_i}, otherwise it just extrapolates the corresponding boundary value outwards. The extrapolation is irrelevant if a_max>=1, and when a<a_min, dark energy is negligible.

Then to use the code, you only need to rename the modified files as the original ones, or modify the Makefile to use the alternative f90 files, and all remaining procedures are the same as you do with the original CAMB.

Note, the outputted matter power spectra may have up to 10% difference from direct calculations of scalar field dark energy models when k is approaching 10^{-4}h/Mpc, but accurate to a level of better than 0.2% once k is smaller than 10^{-3}h/Mpc. 

References:
W. Hu & I. Sawicki, A Parameterized Post-Friedmann Framework for Modified Gravity, Phys. Rev. D 76:104043 (2007).
W. Hu, Parametrized Post-Friedmann Signatures of Acceleration in the CMB, Phys. Rev. D 77:103524 (2008).
W. Fang et al., Challenges to the DGP Model from Horizon-Scale Growth and Geometry, Phys. Rev. D submitted (2008).
W. Fang, W. Hu & A. Lewis, Crossing the Phantom Divide with Parameterized Post-Friedmann Dark Energy, Phys. Rev. D submitted (2008).
