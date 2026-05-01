# mpicc -std=gnu99 -O3 -o mcmc_local mcmc.c -I/Users/deathmac/Documents/scope/mcmc/CAMB-1.6.1/fortran/Release /Users/deathmac/Documents/scope/mcmc/CAMB-1.6.1/fortran/Releaselib/camblib.so -I/opt/homebrew/include -L/opt/homebrew/lib -L/opt/homebrew/opt/lapack/lib -L/Users/deathmac/Documents/scope/mcmc/code/plc_3.0/plc-3.1/lib -I/Users/deathmac/Documents/scope/mcmc/code/plc_3.0/plc-3.1/_install/include -I/Users/deathmac/Documents/scope/mcmc/code/plc_3.0/plc-3.1/src/minipmc -lgsl -lgslcblas -lcfitsio -llapack -lblas -lpthread -lm -lclik


#!/bin/bash

# Exit immediately if a command fails
set -e

echo "Compiling mcmc on local machine"

# ---- Paths ----
BASE="$HOME/Documents/scope/mcmc"
CAMB_LIB_DIR="$BASE/CAMB-1.6.1/fortran/Releaselib"
CLIK_BASE="$BASE/code/plc_3.0/plc-3.1"
CLIK_LIB_DIR="$CLIK_BASE/lib"

# Homebrew libs
BREW_INCLUDE="/opt/homebrew/include"
BREW_LIB="/opt/homebrew/lib"
LAPACK_LIB="/opt/homebrew/opt/lapack/lib"

# ---- Optional: source clik env if present ----
if [ -f "$CLIK_BASE/bin/clik_profile.sh" ]; then
    source "$CLIK_BASE/bin/clik_profile.sh"
fi

# ---- Compile ----
mpicc -std=gnu99 -O3 -o mcmc1 mcmc.c \
    -I"$BREW_INCLUDE" \
    -I"$BASE/CAMB-1.6.1/fortran/Release" \
    -I"$CLIK_BASE/_install/include" \
    -I"$CLIK_BASE/src/minipmc" \
    "$CAMB_LIB_DIR/camblib.so" \
    -L"$BREW_LIB" \
    -L"$LAPACK_LIB" \
    -L"$CLIK_LIB_DIR" \
    -lclik -lgsl -lgslcblas -lcfitsio -llapack -lblas \
    -lpthread -lm \
    -Wl,-rpath,"$CAMB_LIB_DIR" \
    -Wl,-rpath,"$BREW_LIB" \
    -Wl,-rpath,"$CLIK_LIB_DIR"

echo "--- Compile successful! ---"