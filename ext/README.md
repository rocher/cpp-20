# SUMMARY
This folder contains external libraries.

For each library, it contains the source code and a local installation for
development purposes only. If dynamic libraries must be deployed, they can be
taken from the respective locations.


## Adding new libraries

Just as an example, the current libraries have been installed with the
following commands. Please add detailed instructions when new libs are added.

### Boost

```bash
  cd ext
  tar xf ~/Downloads/boost_1_86_0.tar.bz2 --transform='s:^boost_1_86_0:boost_1_86_0/src/:'
  cd boost_1_86_0/src
  ./bootstrap.sh --prefix=../ --with-libraries=chrono,date_time,filesystem,json,serialization
  ./b2 install
```

##### Fragment added to `CMakeLists.txt`

```cmake
find_package(Boost
    1.86.0 EXACT REQUIRED
    CONFIG
    PATHS ${CMAKE_SOURCE_DIR}/ext/boost_1_86_0/lib/cmake
    COMPONENTS
        date_time
)
```

### Google Test

```bash
  cd ext
  tar xf googletest-1.15.2.tar.gz --transform='s:^googletest-1.15.2/:googletest-1.15.2/src/:'
  cd googletest-1.15.2/src
  mkdir build
  cd build
  cmake ../ --install-prefix=$PWD/../../
  make install
```

##### Fragment added to `CMakeLists.txt`

```cmake
find_package(GTest
    1.15.2 EXACT REQUIRED
    CONFIG
    PATHS ${CMAKE_SOURCE_DIR}/ext/googletest-1.15.2/lib/cmake
)
```

## Setting up a development environment

Assuming all required files are located in `~/Downloads`, use the following
snipped (extracted from above instructions) to setup your development
environment.

#### Required files

  + [boost_1_86_0.tar.bz2](https://archives.boost.io/release/1.86.0/source/boost_1_86_0.tar.bz2)
  + [googletest-1.15.2.tar.gz](https://github.com/google/googletest/releases/download/v1.15.2/googletest-1.15.2.tar.gz)


#### Bash script

```bash
  # launch it at the project root directory
  export PROJECT_DIR=$PWD

  cd ${PROJECT_DIR}/ext
  if [ ! -d boost_1_86_0 ]; then
      tar xf ~/Downloads/boost_1_86_0.tar.bz2 --transform='s:^boost_1_86_0:boost_1_86_0/src/:'
      cd boost_1_86_0/src
      ./bootstrap.sh --prefix=../ --with-libraries=chrono,date_time,filesystem,json,serialization
      ./b2 install
  fi

  cd ${PROJECT_DIR}/ext
  if [ ! -d googletest-1.15.2 ]; then
    tar xf ~/Downloads/googletest-1.15.2.tar.gz --transform='s:^googletest-1.15.2/:googletest-1.15.2/src/:'
    cd googletest-1.15.2/src
    mkdir build
    cd build
    cmake ../ --install-prefix=$PWD/../../
    make install
  fi
```

## Maintenance

Please note that all files in this directory (except this file you're reading)
are ignored by git because it's only used for development environments and is
100% reproducible with external libraries.

Only the fragments added to the file `CMakeLists.txt` are under version
control.

When adding a new external library or module, please do the following tasks:

  + add a new section, like boost and google test, with detailed instructions
  + update the file `CMakeLists.txt`
  + append bash instructions to the global script with the corresponding modifications
