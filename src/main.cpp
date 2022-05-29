#include <iostream>

#include <common.hpp>

#include <llvm/Support/Host.h>
#include <llvm/Support/CommandLine.h>

using xeon::ConsoleLog;
using xeon::MemoryBuffer;
using xeon::String;
using xeon::StringView;
using namespace llvm;

constexpr char program_name[] = "Xeon Compiler";

//https://opensource.apple.com/source/llvmCore/llvmCore-3418.0.78/docs/CommandLine.html
cl::opt<String> input_filename(cl::Positional, cl::desc("<input file>"), cl::Required);
cl::opt<String> output_filename("o", cl::desc("Output File Name"), cl::value_desc("filename"));

void output_version(raw_ostream &os) {
    StringView cpu = llvm::sys::getHostCPUName();
    os << program_name << " " << "0.0.1" << "\n";
    os << " Host CPU: " << cpu << "\n";
    os.flush();
}

int main(int argc, char** argv) {
    cl::SetVersionPrinter(&output_version);
    cl::ParseCommandLineOptions(argc, argv, program_name);

    ErrorOr<std::unique_ptr<MemoryBuffer>> file_buffer = llvm::MemoryBuffer::getFile("test.x");
    if(!file_buffer) {

    }

    return 0;
}
