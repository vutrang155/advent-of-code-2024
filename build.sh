#!/bin/bash

if [ "$#" -lt 1 ]; then
    echo "Usage: $0 <day>"
    echo "Optional parameters:"
    echo "  -d: debug"
    echo "  -r: run"
    exit 1
fi

problem=$1
shift
debug_mode=false
run_after_build=false

if [ "$#" -gt 0 ]; then
    for param in "$@"; do
        if [ $param == "-d" ]; then
            debug_mode=true
        elif [ $param == "-r" ]; then
            run_after_build=true
        fi
    done
fi

if [ ! -d "build" ]; then
    echo "build folder not found, creating one..."
    mkdir build
fi

cd build || { echo "Failed to enter 'build' directory."; exit 1; }

if [ "$debug_mode" == true ]; then
    echo "Building in Debug mode..."
    cmake -DTARGET_PROBLEM="$problem" -DCMAKE_BUILD_TYPE=Debug ..
else
    echo "Building in Release mode..."
    cmake -DTARGET_PROBLEM="$problem" -DCMAKE_BUILD_TYPE=Release ..
fi

echo "Running build..."
cmake --build . || { echo "Build failed"; exit 1; }
echo "Build completed successfully"

if [ -f "compile_commands.json" ]; then
    echo "Copying compile_commands.json to the project root..."
    cp compile_commands.json ..
    echo "compile_commands.json copied successfully."
else
    echo "compile_commands.json not found. Skipping copy."
fi

if [ "$run_after_build" = true ]; then
    ./solution_part1 || { echo "Failed to run"; exit 1; }
    ./solution_part2 || { echo "Failed to run"; exit 1; }
fi

cd ..
