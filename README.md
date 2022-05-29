Memorial Day 2022 Project
	playing around with LLVM and modern cmake

	bswenson3@Ubu2204:~/Code/xeonlang$ mkdir build && cd build
	bswenson3@Ubu2204:~/Code/xeonlang/build$ cmake .. && make -j8
	-- The C compiler identification is GNU 11.2.0
	-- The CXX compiler identification is GNU 11.2.0

	...

	[100%] Linking CXX executable xeon
	[100%] Built target xeon
	bswenson3@Ubu2204:~/Code/xeonlang/build$ ./src/xeon --help
	OVERVIEW: Xeon Compiler
	USAGE: xeon [options] \<input file\>

	OPTIONS:

	Color Options:

	--color       - Use colors in output (default=autodetect)

	General options:

	-o=<filename> - Output File Name

	Generic Options:

	--help        - Display available options (--help-hidden for more)
	--help-list   - Display list of available options (--help-list-hidden for more)
	--version     - Display the version of this program
	bswenson3@Ubu2204:~/Code/xeonlang/build$ ./src/xeon --version
	Xeon Compiler 0.0.1
	Host CPU: znver3
	