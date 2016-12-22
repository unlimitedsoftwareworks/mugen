Mugen
===
[![Build Status](https://travis-ci.org/unlimitedsoftwareworks/mugen.svg?branch=master)](https://travis-ci.org/unlimitedsoftwareworks/mugen)
## Notice
> WIP

## About

Mugen is a multi-paradigm high level programming language designed to build robust and scalable applications. The language makes it easier for developers to write safe and maintable code while still maintaining a very good performance. Mugen is not only a language but a complete toolchain that provides dependencies manager, lua based makefiles, post-compilation processing (running unit tests, report generation, etc).

- Object Oriented
- Interface based type inference
- Functional
- Generic
- Concurrent
- Operator Overloading
- Function Overloading
- Static Typing
- Easy FFI (can easily communicate with C)
- Lua based build scripts
- Easily Import precompiled libraries (similar to Java's Jars)

```mu
/*
 * A Hello, World
 */

import(
	mugen.std.io.Console
)

function main(args: String[]) -> UInt32 {
	Console.println("Hello, World!")
	return 0
}
```

## 3rd Party Tools

|Library|Purpose|
|:---|:---|
|https://github.com/unlimitedsoftwareworks/PDFGen| PDF report generation |
|https://github.com/unlimitedsoftwareworks/microtar| Library compression/decompression |
|https://github.com/unlimitedsoftwareworks/tinycthread|Concurrency|
|https://github.com/unlimitedsoftwareworks/smallprofiler|Profiling|
|https://github.com/unlimitedsoftwareworks/utf8.h|UTF-8 Encoding|
|https://github.com/unlimitedsoftwareworks/vec|Vector container|
|https://github.com/unlimitedsoftwareworks/qrintf|sprintf fast alternative|
|https://github.com/unlimitedsoftwareworks/map|Map Container|
|https://github.com/unlimitedsoftwareworks/dmt|Dynamic Memory Tracker|
|https://github.com/unlimitedsoftwareworks/lua|Creating build scripts/makefiles|

## License
See `LICENSE` for more license information.