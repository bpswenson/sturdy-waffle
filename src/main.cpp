#include <iostream>

#include <common.hpp>
#include <version.hpp>
#include <lexer.hpp>

#include <llvm/Support/Host.h>
#include <llvm/Support/CommandLine.h>

using namespace xeon;

constexpr char program_name[] = "Xeon Compiler";

//https://opensource.apple.com/source/llvmCore/llvmCore-3418.0.78/docs/CommandLine.html
llvm::cl::opt<String> input_filename(llvm::cl::Positional, llvm::cl::desc("<input file>"), llvm::cl::Required);
llvm::cl::opt<String> output_filename("o", llvm::cl::desc("Output File Name"), llvm::cl::value_desc("filename"));

void output_version(llvm::raw_ostream &os) {
    StringView cpu = llvm::sys::getHostCPUName();
    os << program_name << " " << "0.0.1" << "\n";
    os << " Host CPU: " << xeon::get_xeon_full_version() << "\n";
    os.flush();
}

int main(int argc, char** argv) {
    llvm::cl::SetVersionPrinter(&output_version);
    llvm::cl::ParseCommandLineOptions(argc, argv, program_name);

    llvm::ErrorOr<std::unique_ptr<MemoryBuffer>> file_buffer = llvm::MemoryBuffer::getFile(input_filename);
    if(!file_buffer) {

    }

    sptr<SourceManager> source_manager = std::make_shared<SourceManager>();

    source_manager->AddNewSourceBuffer(std::move(*file_buffer), SourceLocation());

    Lexer lex = Lexer(source_manager);

    return 0;
}
