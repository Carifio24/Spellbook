# Spellbook
A spellbook program for D&amp;D 5e. The current version of the program can be found in binaries, for either Windows (.zip) or Linux (.tar.gz). The Windows version was cross-compiled using MXE. If you're using a Mac, you'll unfortunately need to build this yourself as I haven't found a Linux -> Mac cross compiler.

When using this, make sure to keep Spells.json and BookBackground.jpg in the same folder as the program.

### Building
If you try to build this yourself, the easiest way is probably to install QtCreator and open the .pro file, then use QtCreator's build function. The only external dependencies are Qt and Boost (the program also relies on jsoncpp, but that's included in this repo).

### Things to improve
* Make spell text copyable
* Make spell fields non-editable
* Add scrolling with arrow keys
