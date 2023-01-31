echo "Compiling..."
clang++-7 -pthread -std=c++17 -o main.bin main.cpp
chmod +777 main.bin
echo "Running..."
./main.bin