
@mkdir Sample1
@cd Sample1

@del /s /q "./CMakeCache.txt"
@cmake ../../Source/Sample1 -G "Visual Studio 17 2022" -A x64 -T v143

@cd ..
