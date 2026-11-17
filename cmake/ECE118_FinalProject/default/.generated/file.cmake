# The following variables contains the files used by the different stages of the build process.
set(ECE118_FinalProject_default_default_XC32_FILE_TYPE_assemble)
set_source_files_properties(${ECE118_FinalProject_default_default_XC32_FILE_TYPE_assemble} PROPERTIES LANGUAGE ASM)

# For assembly files, add "." to the include path for each file so that .include with a relative path works
foreach(source_file ${ECE118_FinalProject_default_default_XC32_FILE_TYPE_assemble})
        set_source_files_properties(${source_file} PROPERTIES INCLUDE_DIRECTORIES "$<PATH:NORMAL_PATH,$<PATH:REMOVE_FILENAME,${source_file}>>")
endforeach()

set(ECE118_FinalProject_default_default_XC32_FILE_TYPE_assembleWithPreprocess)
set_source_files_properties(${ECE118_FinalProject_default_default_XC32_FILE_TYPE_assembleWithPreprocess} PROPERTIES LANGUAGE ASM)

# For assembly files, add "." to the include path for each file so that .include with a relative path works
foreach(source_file ${ECE118_FinalProject_default_default_XC32_FILE_TYPE_assembleWithPreprocess})
        set_source_files_properties(${source_file} PROPERTIES INCLUDE_DIRECTORIES "$<PATH:NORMAL_PATH,$<PATH:REMOVE_FILENAME,${source_file}>>")
endforeach()

set(ECE118_FinalProject_default_default_XC32_FILE_TYPE_compile
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../ECE118/bumpers.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../ECE118/tape_detector.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../AD.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../BOARD.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../ES_CheckEvents.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../ES_Framework.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../ES_KeyboardInput.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../ES_PostList.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../ES_Queue.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../ES_TattleTale.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../ES_Timers.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../IO_Ports.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../LED.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../Motor.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../RC_Servo.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../TemplateES_Main.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../TemplateEventChecker.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../TemplateFSM.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../TemplateHSM.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../TemplateService.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../TemplateSubHSM.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../bumpers.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../newmainXC16.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../pwm.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../roach.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../serial.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../timers.c")
set_source_files_properties(${ECE118_FinalProject_default_default_XC32_FILE_TYPE_compile} PROPERTIES LANGUAGE C)
set(ECE118_FinalProject_default_default_XC32_FILE_TYPE_compile_cpp)
set_source_files_properties(${ECE118_FinalProject_default_default_XC32_FILE_TYPE_compile_cpp} PROPERTIES LANGUAGE CXX)
set(ECE118_FinalProject_default_default_XC32_FILE_TYPE_link)

# The linker script used for the build.
set(ECE118_FinalProject_default_LINKER_SCRIPT "${CMAKE_CURRENT_SOURCE_DIR}/../../../../ECE118/bootloader320.ld")
set(ECE118_FinalProject_default_image_name "default.elf")
set(ECE118_FinalProject_default_image_base_name "default")

# The output directory of the final image.
set(ECE118_FinalProject_default_output_dir "${CMAKE_CURRENT_SOURCE_DIR}/../../../out/ECE118_FinalProject")

# The full path to the final image.
set(ECE118_FinalProject_default_full_path_to_image ${ECE118_FinalProject_default_output_dir}/${ECE118_FinalProject_default_image_name})
