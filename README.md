# hidrun

[![Build status](https://ci.appveyor.com/api/projects/status/cbmhdv7yo5s60ebg?svg=true)](https://ci.appveyor.com/project/myfreeer/hidrun)

run something without opening a new window

## Release

[![Download](https://img.shields.io/github/downloads/myfreeer/hidrun/total.svg)](https://github.com/myfreeer/hidrun/releases/latest)

## Usage

* `hidrun` command to run command without waiting for it.
* `hidrunwait` to run command and wait for it to end.
    * use `start /wait hidrunwait command` to run command and wait for it to end in a console or batch file.

## Compile

Builds with `cmake` and `ninja`.

```sh
mkdir -p "build"
cd "build"
cmake -GNinja ..
ninja
```

## Credits

* <https://github.com/myfreeer/win-startup-headers>