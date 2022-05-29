####### LLVM #######
message(STATUS "Looking for LLVM...")
find_package(LLVM 14.0.0 REQUIRED CONFIG)
#message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
#message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
#message(STATUS "LLVM_INCLUDE_DIRS=${LLVM_INCLUDE_DIRS}")
#message(STATUS "LLVM_DEFINITIONS=${LLVM_DEFINITIONS}")


# BRING INTO GLOBAL NAMESPACE
if ( LLVM_FOUND )
    message(STATUS "LLVM Found.")
    set_target_properties(LLVMCore PROPERTIES IMPORTED_GLOBAL TRUE)
    set_target_properties(LLVMSupport PROPERTIES IMPORTED_GLOBAL TRUE)
    set_target_properties(LLVMPasses PROPERTIES IMPORTED_GLOBAL TRUE)
    set_target_properties(LLVMX86CodeGen PROPERTIES IMPORTED_GLOBAL TRUE)
    target_include_directories(LLVMCore INTERFACE ${LLVM_INCLUDE_DIRS})
    add_library(llvm::core ALIAS LLVMCore)
    add_library(llvm::support ALIAS LLVMSupport)
    add_library(llvm::passes ALIAS LLVMPasses)
    add_library(llvm::codegen ALIAS LLVMX86CodeGen)
endif()

####### LLVM #######