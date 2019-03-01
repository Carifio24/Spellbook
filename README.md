# Spellbook
A spellbook program for D&amp;D 5e. The current version of the program can be found in binaries, for either Windows (.exe), Linux (no extension), or macOS (.app). The program was written using Qt Creator on an Ubuntu 16.04 LTS system, and the Linux version was compiled there. The Windows version was cross-compiled using MXE on the same machine, and the macOs version was compiled on a 2009 MacBook.

The list of favorite spells is stored in a file called Favorites.txt. This file needs to be in the same directory as the executable.

### Building
If you want to build this yourself, the easiest way is probably to install [QtCreator](https://github.com/qt-creator/qt-creator) and open the .pro file, then use QtCreator's build function. The only external dependencies are [Qt](https://www.qt.io/download) and [Boost](https://www.boost.org/users/download/) (the program also relies on [jsoncpp](https://github.com/open-source-parsers/jsoncpp), but that's included in this repo).
