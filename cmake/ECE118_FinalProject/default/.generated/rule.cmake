# The following functions contains all the flags passed to the different build stages.

set(PACK_REPO_PATH "C:/Users/ry442/.mchp_packs" CACHE PATH "Path to the root of a pack repository.")

function(ECE118_FinalProject_default_default_XC32_assemble_rule target)
    set(options
        "-g"
        "${ASSEMBLER_PRE}"
        "-mprocessor=32MX320F128H"
        "-Wa,--defsym=__MPLAB_BUILD=1${MP_EXTRA_AS_POST},--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1"
        "-g,-I${CMAKE_CURRENT_SOURCE_DIR}/../../..,-Ic:/ECE118"
        "-mdfp=${PACK_REPO_PATH}/Microchip/PIC32MX_DFP/1.7.380")
    list(REMOVE_ITEM options "")
    target_compile_options(${target} PRIVATE "${options}")
    target_compile_definitions(${target} PRIVATE "__DEBUG=1")
    target_include_directories(${target} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../..")
endfunction()
function(ECE118_FinalProject_default_default_XC32_assembleWithPreprocess_rule target)
    set(options
        "-x"
        "assembler-with-cpp"
        "-g"
        "${MP_EXTRA_AS_PRE}"
        "${DEBUGGER_NAME_AS_MACRO}"
        "-mdfp=${PACK_REPO_PATH}/Microchip/PIC32MX_DFP/1.7.380"
        "-mprocessor=32MX320F128H"
        "-Wa,--defsym=__MPLAB_BUILD=1${MP_EXTRA_AS_POST},--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-I${CMAKE_CURRENT_SOURCE_DIR}/../../..")
    list(REMOVE_ITEM options "")
    target_compile_options(${target} PRIVATE "${options}")
    target_compile_definitions(${target}
        PRIVATE "__DEBUG"
        PRIVATE "XPRJ_default=default")
    target_include_directories(${target} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../..")
endfunction()
function(ECE118_FinalProject_default_default_XC32_compile_rule target)
    set(options
        "-g"
        "${CC_PRE}"
        "-x"
        "c"
        "-c"
        "-mprocessor=32MX320F128H"
        "-mdfp=${PACK_REPO_PATH}/Microchip/PIC32MX_DFP/1.7.380")
    list(REMOVE_ITEM options "")
    target_compile_options(${target} PRIVATE "${options}")
    target_compile_definitions(${target}
        PRIVATE "__DEBUG"
        PRIVATE "XPRJ_default=default")
    target_include_directories(${target}
        PRIVATE "c:/ECE118"
        PRIVATE "../../../ECE118;."
        PRIVATE "c:/ECE118/include")
endfunction()
function(ECE118_FinalProject_default_default_XC32_compile_cpp_rule target)
    set(options
        "-g"
        "${CC_PRE}"
        "${DEBUGGER_NAME_AS_MACRO}"
        "-mprocessor=32MX320F128H"
        "-frtti"
        "-fexceptions"
        "-fno-check-new"
        "-fenforce-eh-specs"
        "-fno-common"
        "-mdfp=${PACK_REPO_PATH}/Microchip/PIC32MX_DFP/1.7.380")
    list(REMOVE_ITEM options "")
    target_compile_options(${target} PRIVATE "${options}")
    target_compile_definitions(${target}
        PRIVATE "__DEBUG"
        PRIVATE "XPRJ_default=default")
    target_include_directories(${target}
        PRIVATE "c:/ECE118"
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../..")
endfunction()
function(ECE118_FinalProject_default_dependentObject_rule target)
    set(options
        "-mprocessor=32MX320F128H"
        "-mdfp=${PACK_REPO_PATH}/Microchip/PIC32MX_DFP/1.7.380")
    list(REMOVE_ITEM options "")
    target_compile_options(${target} PRIVATE "${options}")
endfunction()
function(ECE118_FinalProject_default_link_rule target)
    set(options
        "-g"
        "${MP_EXTRA_LD_PRE}"
        "${DEBUGGER_OPTION_TO_LINKER}"
        "${DEBUGGER_NAME_AS_MACRO}"
        "-mprocessor=32MX320F128H"
        "-Wl,--defsym=__MPLAB_BUILD=1${MP_EXTRA_LD_POST},--script=${ECE118_FinalProject_default_LINKER_SCRIPT},--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--no-code-in-dinit,--no-dinit-in-serial-mem,-L${CMAKE_CURRENT_SOURCE_DIR}/../../..,-Map=mem.map,--memorysummary,memoryfile.xml"
        "-mdfp=${PACK_REPO_PATH}/Microchip/PIC32MX_DFP/1.7.380")
    list(REMOVE_ITEM options "")
    target_link_options(${target} PRIVATE "${options}")
    target_compile_definitions(${target} PRIVATE "XPRJ_default=default")
endfunction()
