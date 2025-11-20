echo "running build, assuming Windows dev powershell is active";
echo "running CMake build generator";
cmake -G "Ninja" -B out --preset default;
echo "running the build";
cmake --build out --config Debug;
echo "build complete";
copy out/compile_commands.json .
