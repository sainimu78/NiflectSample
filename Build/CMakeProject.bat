
@mkdir MyApp
@cd MyApp

@del /s /q "./CMakeCache.txt"
@cmake ../../ -G "Visual Studio 17 2022" -A x64 -T v143

@cd ..
