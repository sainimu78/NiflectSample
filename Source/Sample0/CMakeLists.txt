cmake_minimum_required(VERSION 3.20.0)

set(ModuleName Sample0)
project(${ModuleName})

file(GLOB_RECURSE SrcAll *.*)
list(APPEND SrcAll ${ModuleSrc})
add_executable(${ModuleName} ${SrcAll})

target_include_directories(${ModuleName} PRIVATE ./)

add_library(Niflect SHARED IMPORTED)
get_filename_component(AbsRootSourceDirPath "${CMAKE_CURRENT_SOURCE_DIR}/../.." ABSOLUTE)
set_target_properties(Niflect PROPERTIES IMPORTED_IMPLIB "${AbsRootSourceDirPath}/ThirdParty/Niflect/bin/Niflect.lib")

set(NiflectGeneratedRootPath "${AbsRootSourceDirPath}/Build/NiflectGenerated")
set(ModuleGenPath ${NiflectGeneratedRootPath}/${ModuleName})
set(GenIncludePath ${ModuleGenPath}/_GenInclude)

target_link_libraries(${ModuleName} PRIVATE Niflect)
target_include_directories(${ModuleName} 
	PRIVATE "${AbsRootSourceDirPath}/ThirdParty/Niflect/include"
)
target_include_directories(${ModuleName}
	PRIVATE ${ModuleGenPath}
	PUBLIC ${GenIncludePath}
)
target_link_libraries(${ModuleName} PRIVATE Niflect)

set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT ${ModuleName})
set_target_properties(${ModuleName} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "$<IF:$<CONFIG:Debug>,${CMAKE_BINARY_DIR}/Debug,${CMAKE_BINARY_DIR}/Release>")