function(SwigLib name lib TMP_DIR)

    if(NOT BORNAGAIN_PYTHON)
        message(FATAL_ERROR "Function SwigLib called though BORNAGAIN_PYTHON=false")
    endif()

    message(STATUS "SwigLib ${name}: ${lib} ${TMP_DIR}")

    if(CONFIGURE_BINDINGS)

        file(MAKE_DIRECTORY ${TMP_DIR})

        GeneratePythonDocs(${AUTO_DIR}/doxygen${name}.i ${WRAP_DIR}/swig)

        set(swig_dependencies
            ${WRAP_DIR}/swig/lib${lib}.i
            ${WRAP_DIR}/swig/deprecation.i
            ${WRAP_DIR}/swig/warnings.i
            ${WRAP_DIR}/swig/ignoreBase.i
            ${WRAP_DIR}/swig/ignoreSample.i
            )
        foreach(FNAM ${swig_dependencies})
            if(NOT EXISTS ${FNAM})
                message(FATAL_ERROR "Could NOT find SWIG input ${FNAM}")
            endif()
        endforeach()
        list(APPEND swig_dependencies ${AUTO_DIR}/doxygen${name}.i)

        # Run Swig.
        #     Please keep -Werror, in order not to overlook critical warnings.
        #     Dispensable warnings are disabled in Wrap/swig/warnigs.i.
        #     Joachim, oct20.
        set(SWIG_FLAGS "-c++;-python;-Werror;-o;${AUTO_DIR}/lib${lib}_wrap.cpp;-outdir;${TMP_DIR}"
                               ";-I${CMAKE_SOURCE_DIR};-I${CMAKE_BINARY_DIR}/inc")

        add_custom_command(
            OUTPUT ${AUTO_DIR}/lib${lib}.py
            COMMAND ${Python3_EXECUTABLE} ${WRAP_DIR}/swig/tweaks.py
                   ${TMP_DIR}/lib${lib}.py
                   ${AUTO_DIR}/lib${lib}.py
            DEPENDS ${TMP_DIR}/lib${lib}.py
            )
        add_custom_command(
            OUTPUT ${TMP_DIR}/lib${lib}.py
                   ${AUTO_DIR}/lib${lib}_wrap.h
                   ${AUTO_DIR}/lib${lib}_wrap.cpp
            COMMAND ${SWIG_EXECUTABLE} ${SWIG_FLAGS} ${WRAP_DIR}/swig/lib${lib}.i
            DEPENDS ${swig_dependencies} ${include_files}
            )

    endif(CONFIGURE_BINDINGS)

    add_custom_target(
        ${lib}_python
        COMMAND ${CMAKE_COMMAND}
            -E copy ${AUTO_DIR}/lib${lib}.py ${CMAKE_BINARY_DIR}/lib/lib${lib}.py
        COMMAND ${CMAKE_COMMAND}
            -E copy ${AUTO_DIR}/lib${lib}.py ${CMAKE_BINARY_DIR}/lib/bornagain/lib${lib}.py
        DEPENDS ${AUTO_DIR}/lib${lib}.py
        )

    if((CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
            OR (CMAKE_CXX_COMPILER_ID STREQUAL "GNU"))
        # suppress warnings from auto-generated code (last updated for Swig 4.0.1)
        set_source_files_properties(${AUTO_DIR}/lib${lib}_wrap.cpp
            PROPERTIES COMPILE_OPTIONS
            "-Wno-unused-parameter;-Wno-missing-field-initializers;-Wno-sometimes-uninitialized;\
-Wno-deprecated-declarations")
    endif()

    add_dependencies(${lib} ${lib}_python)

    target_compile_definitions(${lib} PUBLIC -DBORNAGAIN_PYTHON)
    target_include_directories(${lib} PUBLIC ${Python3_INCLUDE_DIRS} ${Python3_NumPy_INCLUDE_DIRS})
    target_link_libraries(${lib} ${Python3_LIBRARIES})

    install(FILES ${CMAKE_BINARY_DIR}/lib/lib${lib}.py
        DESTINATION ${destination_lib} COMPONENT Libraries) # required by swig

    if(WIN32)
        # python in windows required .pyd extension for the library name
        if(BORNAGAIN_PYTHON)
            add_custom_command(
                TARGET ${lib}
                POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_BINARY_DIR}/bin/${libprefix}${lib}${libsuffix}
                ${CMAKE_BINARY_DIR}/lib/${libprefix}${lib}".pyd"
                )
            install(FILES ${CMAKE_BINARY_DIR}/lib/${libprefix}${lib}.pyd
                DESTINATION ${destination_lib} COMPONENT Libraries)
            add_custom_command(
                TARGET ${lib}
                POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_BINARY_DIR}/bin/${libprefix}${lib}${libsuffix}
                ${CMAKE_BINARY_DIR}/lib/${libprefix}${lib}${libsuffix}
                )
        endif()
    endif()

endfunction()
