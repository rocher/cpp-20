# SUMMARY

This is the build directory.

The script in this directory can help you build different release types for a
number of targets. Possible release are `debug` and  `release`. Targets are
specified with a _toolchain_ file. For now, `linux-native` is the only target
available.

## Invocation

The `build` script can be configured with variables:

```bash
  $ ./build -h
  Usage: [VARIABLES] ./build
  VARIABLES:
    clean={y|n}              (default 'n')
    toolchain=FILE           (default 'linux-native')
    type={debug|release}     (default 'debug')
```

For example:

```bash
  clean=y type=release ./build
```

These variables are stored in the `.config` file and use in subsequent
invocations. Note how the default values changed according to the last
invocation:

```bash
  $ ./build -h
  Usage: [VARIABLES] ./build
  VARIABLES:
    clean={y|n}              (default 'y')
    toolchain=FILE           (default 'linux-native')
    type={debug|release}     (default 'release')
```
