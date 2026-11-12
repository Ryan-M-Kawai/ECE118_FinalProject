set(DEPENDENT_MP_BIN2HEXECE118_FinalProject_default_r_kkloEx "c:/Program Files/Microchip/xc32/v5.10/bin/xc32-bin2hex.exe")
set(DEPENDENT_DEPENDENT_TARGET_ELFECE118_FinalProject_default_r_kkloEx ${CMAKE_CURRENT_LIST_DIR}/../../../../out/ECE118_FinalProject/default.elf)
set(DEPENDENT_TARGET_DIRECE118_FinalProject_default_r_kkloEx ${CMAKE_CURRENT_LIST_DIR}/../../../../out/ECE118_FinalProject)
set(DEPENDENT_BYPRODUCTSECE118_FinalProject_default_r_kkloEx ${DEPENDENT_TARGET_DIRECE118_FinalProject_default_r_kkloEx}/${sourceFileNameECE118_FinalProject_default_r_kkloEx}.c)
add_custom_command(
    OUTPUT ${DEPENDENT_TARGET_DIRECE118_FinalProject_default_r_kkloEx}/${sourceFileNameECE118_FinalProject_default_r_kkloEx}.c
    COMMAND ${DEPENDENT_MP_BIN2HEXECE118_FinalProject_default_r_kkloEx} --image ${DEPENDENT_DEPENDENT_TARGET_ELFECE118_FinalProject_default_r_kkloEx} --image-generated-c ${sourceFileNameECE118_FinalProject_default_r_kkloEx}.c --image-generated-h ${sourceFileNameECE118_FinalProject_default_r_kkloEx}.h --image-copy-mode ${modeECE118_FinalProject_default_r_kkloEx} --image-offset ${addressECE118_FinalProject_default_r_kkloEx} 
    WORKING_DIRECTORY ${DEPENDENT_TARGET_DIRECE118_FinalProject_default_r_kkloEx}
    DEPENDS ${DEPENDENT_DEPENDENT_TARGET_ELFECE118_FinalProject_default_r_kkloEx})
add_custom_target(
    dependent_produced_source_artifactECE118_FinalProject_default_r_kkloEx 
    DEPENDS ${DEPENDENT_TARGET_DIRECE118_FinalProject_default_r_kkloEx}/${sourceFileNameECE118_FinalProject_default_r_kkloEx}.c
    )
