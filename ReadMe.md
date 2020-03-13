# QtJsonExample

## Overview

This toy program simply shows one possible program structure of `QJsonObject`
and demonstrate how it works.

## Install and run

### Compiler

Currently we tested the program under the following cases:

| Compiler                | Qt     | CMake      |
| ----------------------- | ------ | ---------- |
| MSVC 14.0 (2015) 64-bit | 5.12.5 | 3.16.0-rc3 |
| MSVC 14.0 (2015) 64-bit | 5.13.1 | 3.16.0-rc3 |
| MSVC 14.0 (2015) 64-bit | 5.14.1 | 3.16.0-rc3 |
| MinGW 7.3.0 64-bit      | 5.12.5 | 3.16.0-rc3 |
| MinGW 7.3.0 64-bit      | 5.13.1 | 3.16.0-rc3 |
| MinGW 7.3.0 64-bit      | 5.14.1 | 3.16.0-rc3 |

### Build system

We use CMake to generate the program. Please install CMake in order to build
this program.

| Build system | Requirement    |
| ------------ | -------------- |
| CMake        | At least 3.1.0 |

### Library

This program use Qt as the framework. The earliest possible version is 5.10.

| Library | Requirement (Suggested) | Role              |
| ------- | ----------------------- | ----------------- |
| Qt5     | At least 5.10           | Overall framework |

### How to

Below used cmake-gui as the example:

1. Open cmake-gui.
2. Select this folder as the source code folder and choose the proper binary
   folder.
3. Configure the project using your favorite compiler.
4. Choose correct Qt folder.
5. Generate the program.
6. You can find the generated program in the bin folder.
