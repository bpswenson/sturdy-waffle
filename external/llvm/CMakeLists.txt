message(STATUS "Looking for LLVM...")
find_package(LLVM 14.0.0 REQUIRED
        COMPONENTS
        Core
        Passes
        Support
        CodeGen
        )

# BRING INTO GLOBAL NAMESPACE
if ( LLVM_FOUND )

    message(STATUS "LLVM Found.")
    set_target_properties(
            LLVMCore
            LLVMSupport
            LLVMPasses
            LLVMX86CodeGen

            PROPERTIES IMPORTED_GLOBAL TRUE)
    target_include_directories(LLVMCore INTERFACE ${LLVM_INCLUDE_DIRS})
    add_library(llvm::core ALIAS LLVMCore)
    add_library(llvm::support ALIAS LLVMSupport)
    add_library(llvm::passes ALIAS LLVMPasses)
    add_library(llvm::codegen ALIAS LLVMX86CodeGen)

endif()

