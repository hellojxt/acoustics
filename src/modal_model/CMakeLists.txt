set(MODAL_MODEL_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/ModalAnalysisObject.h
    ${CMAKE_CURRENT_SOURCE_DIR}/ModalAnalysisObject.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ImpulseSeriesObject.h
    ${CMAKE_CURRENT_SOURCE_DIR}/ImpulseSeriesObject.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ModalODESolver.h
    ${CMAKE_CURRENT_SOURCE_DIR}/ModalODESolver.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/SparseModalEncoder.h
    ${CMAKE_CURRENT_SOURCE_DIR}/SparseModalEncoder.cpp
    CACHE FILE "Modal model sources")

set(MODAL_MATERIAL_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/ModalMaterial.h
    ${CMAKE_CURRENT_SOURCE_DIR}/ModalMaterialList.h
    CACHE FILE "Modal material sources")

set(BEM_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/BEMSolutionMode.h
    ${CMAKE_CURRENT_SOURCE_DIR}/KirchhoffIntegralSolver.h
    ${CMAKE_CURRENT_SOURCE_DIR}/KirchhoffIntegralSolver.cpp
    CACHE FILE "BEM Source"
    ) 
