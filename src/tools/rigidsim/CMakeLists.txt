add_definitions(-DUSE_RECORDER)

# =============================================================================
#   Builds a rigid-body solver
# =============================================================================
if ( BUILD_RIGIDSIM )
    # ===================
    # Target
    # ===================

    	find_package(LibConfig 1.0 REQUIRED)

        add_executable(rigidsim
            RigidSimDrop.cpp
            ${RIGID_SRC} 		  ${RIGID_IO_SRC}
            ${LOGGING_SRC}        
            ${DEFORMABLE_SRC}     ${LINEARALGEBRA_SRC}
            ${GENERIC_SRC}        ${IO_SRC}
            ${SNDGEN_SRC}
            ${RIGID_PARSER_SRC}
            )
#        target_include_directories(rigidsim
#            PUBLIC ${Boost_INCLUDE_DIR}
#            )

        target_link_libraries(rigidsim
                              ${LibConfig_LIBRARY}   ${BLAS_LAPACK_LIBS}
                              ${MKL_LIBRARY})

        set_target_properties(rigidsim PROPERTIES LINK_FLAGS ${LINK_FLAGS})

endif ( BUILD_RIGIDSIM )

# =============================================================================
#   Builds a rigid-body solver GUI
# =============================================================================
if( 0 )
if ( BUILD_RIGIDSIM_GUI )
    # ===================
    # Dependencies
    # ===================
    
        # package for opengl and glut
        find_package(OpenGL REQUIRED)
        find_package(GLUT REQUIRED)

        find_package(LibConfig 1.0 REQUIRED)

        if(USE_QT5)
            find_package(Qt5Widgets REQUIRED)
            include_directories(${QT_USE_FILE})
        else(USE_QT5)
            find_package(Qt4 REQUIRED)
            include(${QT_USE_FILE})
        endif(USE_QT5)

        # check the existence of libQGLViewer
        find_package(QGLViewer 1.0 REQUIRED)

        set(RIGID_SIM_GUI_APP_SRCS
            RigidSim.h    		RigidSim.cpp
            RigidSim.ui 		images.qrc

            RigidCanvas.h 					RigidCanvas.cpp
            demo/DemoDropObjs.h 			demo/DemoDropObjs.cpp
            demo/DemoDropObjsWithFixed.h 	demo/DemoDropObjsWithFixed.cpp
            demo/DemoShakingPiggy.h 		demo/DemoShakingPiggy.cpp
            )

    # ===================
    # Settings
    # ===================
        set(QT_USE_QTXML 1)
        set(QT_USE_QTOPENGL 1)

    # ===================
    # Target
    # ===================

        set(CMAKE_INCLUDE_CURRENT_DIR ON)

        add_executable(rigidsim-gui-old
        	${RIGID_SIM_GUI_APP_SRCS}
            ${GENERIC_SRC}                  ${DEFORMABLE_SRC}
			${IO_SRC}                       ${RIGID_SRC}
			${LOGGING_SRC}                  ${LINEARALGEBRA_SRC}
            ${RIGID_IO_SRC}
            ${SNDGEN_SRC}
            ${RIGID_PARSER_SRC}
            )

        target_include_directories(rigidsim-gui-old
            PUBLIC ${GLUT_INCLUDE_DIR}
            PUBLIC ${OPENGL_INCLUDE_DIR}
            PUBLIC ${QGLViewer_INCLUDE_DIR}
            PUBLIC ${Boost_INCLUDE_DIR}
            )

        target_link_libraries(rigidsim-gui-old
            ${GLUT_LIBRARIES}       ${QT_LIBRARIES}         
            ${QGLViewer_LIBRARY}	${OPENGL_LIBRARIES}
            ${LibConfig_LIBRARY}	${BLAS_LAPACK_LIBS}
            ${MKL_LIBRARY}
            )

        set_target_properties(rigidsim-gui-old PROPERTIES AUTOMOC TRUE)
        set_target_properties(rigidsim-gui-old PROPERTIES AUTOMOC_MOC_OPTIONS -DBOOST_TT_HAS_OPERATOR_HPP_INCLUDED)
        set_target_properties(rigidsim-gui-old PROPERTIES AUTOUIC TRUE)
        set_target_properties(rigidsim-gui-old PROPERTIES AUTORCC TRUE)

        if(USE_QT5)
            qt5_use_modules(rigidsim-gui-old Xml OpenGL)
        endif(USE_QT5)

        set_target_properties(rigidsim-gui-old PROPERTIES LINK_FLAGS ${LINK_FLAGS})
endif ( BUILD_RIGIDSIM_GUI ) 


# =============================================================================
#   Also build a simple "replayer" that we can use to make quick OpenGL renderings
# =============================================================================
if ( BUILD_RIGIDSIM_GUI )
    # ===================
    # Dependencies
    # ===================
    
        # package for opengl and glut
        find_package(OpenGL REQUIRED)
        find_package(GLUT REQUIRED)

        find_package(LibConfig 1.0 REQUIRED)

        if(USE_QT5)
            find_package(Qt5Widgets REQUIRED)
        else(USE_QT5)
            find_package(Qt4 REQUIRED)
        endif(USE_QT5)

        # check the existence of libQGLViewer
        find_package(QGLViewer 1.0 REQUIRED)

        set(REPLAYER_APP_SRCS
            replayer_multiobj.h 			replayer_multiobj.cpp
            )

    # ===================
    # Settings
    # ===================
        set(QT_USE_QTXML 1)
        set(QT_USE_QTOPENGL 1)

    # ===================
    # Target
    # ===================

        if(USE_QT5)
            include_directories(${QT_USE_FILE})
        else(USE_QT5)
            include(${QT_USE_FILE})
        endif(USE_QT5)

        set(CMAKE_INCLUDE_CURRENT_DIR ON)

        add_executable(replayer
        	${RIGID_SIM_GUI_APP_SRCS}
            ${GENERIC_SRC}                  ${DEFORMABLE_SRC}
			${IO_SRC}                       ${RIGID_SRC}
			${LOGGING_SRC}                  ${LINEARALGEBRA_SRC}
            ${RIGID_IO_SRC}
            ${SNDGEN_SRC}
            ${RIGID_PARSER_SRC}
            )

        target_include_directories(replayer
            PUBLIC ${GLUT_INCLUDE_DIR}
            PUBLIC ${OPENGL_INCLUDE_DIR}
            PUBLIC ${QGLViewer_INCLUDE_DIR}
            PUBLIC ${Boost_INCLUDE_DIR}
            )

        target_link_libraries(replayer
            ${GLUT_LIBRARIES}       ${QT_LIBRARIES}         
            ${QGLViewer_LIBRARY}	${OPENGL_LIBRARIES}
            ${LibConfig_LIBRARY}
            )

        set_target_properties(replayer PROPERTIES AUTOMOC TRUE)
        set_target_properties(replayer PROPERTIES AUTOMOC_MOC_OPTIONS -DBOOST_TT_HAS_OPERATOR_HPP_INCLUDED)
        set_target_properties(replayer PROPERTIES AUTOUIC TRUE)
        set_target_properties(replayer PROPERTIES AUTORCC TRUE)

        if(USE_QT5)
            qt5_use_modules(replayer Xml OpenGL)
        endif(USE_QT5)

        set_target_properties(replayer PROPERTIES LINK_FLAGS ${LINK_FLAGS})
endif ( BUILD_RIGIDSIM_GUI ) 
endif ( 0 )

# # =============================================================================
# #   Builds a rigid-body solver
# # =============================================================================
# if ( BUILD_RIGIDSIM )
#     add_executable(rigidsim
#         tools/RigidSimDrop.cpp
#         ${GENERIC_SRC}                    ${DEFORMABLE_SRC}
#         ${IO_SRC}                         ${RIGID_SRC}
#         ${LOGGING_SRC}                    ${LINEARALGEBRA_SRC}
#         ${RIGID_IO_SRC})

#     # Turn on impact and displacement recording
#     add_definitions(-DUSE_RECORDER)

#     target_link_libraries(rigidsim
#         ${LibConfig_LIBRARY}              ${BLAS_LAPACK_LIBS}
#         ${MKL_LIBRARY})
# endif ( BUILD_RIGIDSIM )
