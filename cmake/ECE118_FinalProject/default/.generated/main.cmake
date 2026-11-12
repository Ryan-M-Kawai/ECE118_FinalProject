include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(ECE118_FinalProject_default_library_list )

set(OUTPUT_SUFFIX elf)
# Handle files with suffix s, for group default-XC32
if(ECE118_FinalProject_default_default_XC32_FILE_TYPE_assemble)
add_library(ECE118_FinalProject_default_default_XC32_assemble OBJECT ${ECE118_FinalProject_default_default_XC32_FILE_TYPE_assemble})
    ECE118_FinalProject_default_default_XC32_assemble_rule(ECE118_FinalProject_default_default_XC32_assemble)
    list(APPEND ECE118_FinalProject_default_library_list "$<TARGET_OBJECTS:ECE118_FinalProject_default_default_XC32_assemble>")

endif()

# Handle files with suffix S, for group default-XC32
if(ECE118_FinalProject_default_default_XC32_FILE_TYPE_assembleWithPreprocess)
add_library(ECE118_FinalProject_default_default_XC32_assembleWithPreprocess OBJECT ${ECE118_FinalProject_default_default_XC32_FILE_TYPE_assembleWithPreprocess})
    ECE118_FinalProject_default_default_XC32_assembleWithPreprocess_rule(ECE118_FinalProject_default_default_XC32_assembleWithPreprocess)
    list(APPEND ECE118_FinalProject_default_library_list "$<TARGET_OBJECTS:ECE118_FinalProject_default_default_XC32_assembleWithPreprocess>")

endif()

# Handle files with suffix [cC], for group default-XC32
if(ECE118_FinalProject_default_default_XC32_FILE_TYPE_compile)
add_library(ECE118_FinalProject_default_default_XC32_compile OBJECT ${ECE118_FinalProject_default_default_XC32_FILE_TYPE_compile})
    ECE118_FinalProject_default_default_XC32_compile_rule(ECE118_FinalProject_default_default_XC32_compile)
    list(APPEND ECE118_FinalProject_default_library_list "$<TARGET_OBJECTS:ECE118_FinalProject_default_default_XC32_compile>")

endif()

# Handle files with suffix cpp, for group default-XC32
if(ECE118_FinalProject_default_default_XC32_FILE_TYPE_compile_cpp)
add_library(ECE118_FinalProject_default_default_XC32_compile_cpp OBJECT ${ECE118_FinalProject_default_default_XC32_FILE_TYPE_compile_cpp})
    ECE118_FinalProject_default_default_XC32_compile_cpp_rule(ECE118_FinalProject_default_default_XC32_compile_cpp)
    list(APPEND ECE118_FinalProject_default_library_list "$<TARGET_OBJECTS:ECE118_FinalProject_default_default_XC32_compile_cpp>")

endif()

# Handle files with suffix [cC], for group default-XC32
if(ECE118_FinalProject_default_default_XC32_FILE_TYPE_dependentObject)
add_library(ECE118_FinalProject_default_default_XC32_dependentObject OBJECT ${ECE118_FinalProject_default_default_XC32_FILE_TYPE_dependentObject})
    ECE118_FinalProject_default_default_XC32_dependentObject_rule(ECE118_FinalProject_default_default_XC32_dependentObject)
    list(APPEND ECE118_FinalProject_default_library_list "$<TARGET_OBJECTS:ECE118_FinalProject_default_default_XC32_dependentObject>")

endif()


# Main target for this project
add_executable(ECE118_FinalProject_default_image_r_kkloEx ${ECE118_FinalProject_default_library_list})

set_target_properties(ECE118_FinalProject_default_image_r_kkloEx PROPERTIES
    OUTPUT_NAME "default"
    SUFFIX ".elf"
    RUNTIME_OUTPUT_DIRECTORY "${ECE118_FinalProject_default_output_dir}")
target_link_libraries(ECE118_FinalProject_default_image_r_kkloEx PRIVATE ${ECE118_FinalProject_default_default_XC32_FILE_TYPE_link})
# Add the link options from the rule file.
ECE118_FinalProject_default_link_rule( ECE118_FinalProject_default_image_r_kkloEx)

# Add bin2hex target for converting built file to a .hex file.
string(REGEX REPLACE [.]elf$ .hex ECE118_FinalProject_default_image_name_hex ${ECE118_FinalProject_default_image_name})
add_custom_target(ECE118_FinalProject_default_Bin2Hex ALL
    COMMAND ${MP_BIN2HEX} \"${ECE118_FinalProject_default_output_dir}/${ECE118_FinalProject_default_image_name}\"
    DEPENDS "${ECE118_FinalProject_default_output_dir}/${ECE118_FinalProject_default_image_name}"
    BYPRODUCTS ${ECE118_FinalProject_default_output_dir}/${ECE118_FinalProject_default_image_name_hex}
    COMMENT "Convert built file to .hex")
add_dependencies(ECE118_FinalProject_default_Bin2Hex ECE118_FinalProject_default_image_r_kkloEx)




