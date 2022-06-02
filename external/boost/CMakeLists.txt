
message(STATUS "To hell with Boost...")
#set( BOOST_VERSION 1.74.0 )

#set( Boost_USE_STATIC_LIBS      FALSE )
#set( Boost_USE_MULTITHREADED    TRUE )
#set( Boost_USE_STATIC_RUNTIME   FALSE )
#set( Boost_ADDITIONAL_VERSIONS  "${BOOST_VERSION}" )

#find_package( Boost ${BOOST_VERSION} EXACT REQUIRED
#        COMPONENTS
#            program_options
#        )

# BRING INTO GLOBAL NAMESPACE
#if ( Boost_FOUND )
#    message(STATUS "Boost Found.")
#    set_target_properties(
#            Boost::boost
#            Boost::program_options

#            PROPERTIES IMPORTED_GLOBAL TRUE)
#endif()

