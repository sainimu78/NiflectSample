cmake_minimum_required(VERSION 3.20.0)

set(ModuleName MyApp)
project(${ModuleName})
add_executable(${ModuleName} Main.cpp MyClass.h)

add_library(Niflect SHARED IMPORTED)
get_filename_component(AbsRootSourceDirPath "${CMAKE_CURRENT_SOURCE_DIR}" ABSOLUTE)
set_target_properties(Niflect PROPERTIES IMPORTED_IMPLIB "${AbsRootSourceDirPath}/ThirdParty/Niflect/bin/Niflect.lib")

set(NiflectGeneratedRootDirPath "${CMAKE_CURRENT_SOURCE_DIR}/Build")

target_link_libraries(${ModuleName} PRIVATE Niflect)
target_include_directories(${ModuleName} 
	PRIVATE "ThirdParty/Niflect/include"
	PRIVATE "${NiflectGeneratedRootDirPath}/NiflectGenerated"
	PRIVATE "${NiflectGeneratedRootDirPath}/NiflectGenerated/${ModuleName}/GenH"
	)
target_link_libraries(${ModuleName} PRIVATE Niflect)

set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT MyApp)
set_target_properties(${ModuleName} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "$<IF:$<CONFIG:Debug>,${CMAKE_BINARY_DIR}/Debug,${CMAKE_BINARY_DIR}/Release>")