
@mkdir Sample0
@cd Sample0

@del /s /q "./CMakeCache.txt"
@cmake ../../Source/Sample0 -G "Visual Studio 17 2022" -A x64 -T v143

@cd ..
