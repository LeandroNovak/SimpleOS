echo "This installer was created on 02/24/2018"

echo "Creating a folder for sources..."
mkdir -p ~/.opt/cross/temp
cd ~/.opt/cross/temp

echo "Downloading binutils and gcc..."
wget ftp://ftp.gnu.org/gnu/binutils/binutils-2.30.tar.xz
wget ftp://ftp.gnu.org/gnu/gcc/gcc-7.3.0/gcc-7.3.0.tar.gz

echo "Extracting binutils and gcc..."
tar -xvf binutils-2.30.tar.xz
tar -zxvf gcc-7.3.0.tar.gz
cd gcc-7.3.0/
contrib/download_prerequisites
cd ~/.opt/cross/temp

echo "Preparating to install..."
export PREFIX="$HOME/.opt/cross"
export TARGET=i686-elf
export PATH="$PREFIX/bin:$PATH"

echo "Installing binutils..."
mkdir build-binutils
cd build-binutils
../binutils-2.30/configure --target=$TARGET --prefix="$PREFIX" --with-sysroot --disable-nls --disable-werror
make
make install

echo "Installing gcc..."
cd ~/.opt/cross/temp
which -- $TARGET-as || echo $TARGET-as is not in the PATH
mkdir build-gcc
cd build-gcc
../gcc-7.3.0/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --enable-languages=c,c++ --without-headers
make all-gcc
make all-target-libgcc
make install-gcc
make install-target-libgcc

echo "Removing temporary files..."
cd ./.opt/cross
rm -rf temp

echo "Exporting compiler to bashrc..."
echo "alias gccx='$HOME/.opt/cross/bin/i686-elf-gcc'" >> ~/.bashrc
echo "alias gccx='$HOME/.opt/cross/bin/i686-elf-g++'" >> ~/.bashrc
echo "alias asx='$HOME/.opt/cross/bin/i686-elf-as'" >> ~/.bashrc
