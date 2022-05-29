#include <iostream>

#include <common.hpp>

#include <llvm/Support/CommandLine.h>

using xeon::ConsoleLog;
using xeon::MemoryBuffer;
using xeon::ErrorOr;

constexpr char program_name[] = "Xeon Compiler";

int main(int argc, char** argv) {
    ParseCommandLineOptions(argc, argv, program_name);


    ErrorOr<std::unique_ptr<MemoryBuffer>> file_buffer = llvm::MemoryBuffer::getFile("test.x");
    if(!file_buffer) {

    }

    return 0;
}
