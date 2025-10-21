
#!/bin/bash

set -e  # Exit on any error

# Use current directory as base
BASE_DIR="$(pwd)"
INSTALL_PREFIX="$BASE_DIR/libs"

mkdir -p "$INSTALL_PREFIX"

# ---- CFITSIO ----
echo "Installing CFITSIO..."
cd "$BASE_DIR/cfitsio-4.6.2"
./configure --prefix="$INSTALL_PREFIX" --enable-shared
make -j$(nproc)
make install

# ---- GSL ----
echo "Installing GSL..."
cd "$BASE_DIR/gsl-2.8"
./configure --prefix="$INSTALL_PREFIX" --enable-shared
make -j$(nproc)
make install

# ---- LAPACK ----
echo "Installing LAPACK..."
cd "$BASE_DIR/lapack-3.12.1"
mkdir -p build && cd build
cmake -DCMAKE_INSTALL_PREFIX="$INSTALL_PREFIX" -DBUILD_SHARED_LIBS=ON ..
make -j$(nproc)
make install

echo ""
echo "✅ All libraries installed successfully to: $INSTALL_PREFIX"
echo ""
echo "🔧 Add the following lines to your ~/.bashrc *or* to your virtualenv activation script:"
echo ""
cat << EOF
# === Planck Likelihood Dependencies (Virtualenv) ===
export PLANCK_LIBS="$INSTALL_PREFIX"
export LD_LIBRARY_PATH="\$PLANCK_LIBS/lib:\$LD_LIBRARY_PATH"
export CPATH="\$PLANCK_LIBS/include:\$CPATH"
export LIBRARY_PATH="\$PLANCK_LIBS/lib:\$LIBRARY_PATH"
EOF
echo ""

