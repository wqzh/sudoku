# Compile sudoku solver C code to WebAssembly using Emscripten
# Usage: make  (requires emcc to be in PATH)

TARGET = ../wasm/solver
CFLAGS = -O2 -std=c99
EMSCRIPTEN_FLAGS = -O2 -s EXPORTED_FUNCTIONS='["_solve_sudoku"]' -s EXPORTED_RUNTIME_METHODS='["ccall","cwrap"]' -s ALLOW_MEMORY_GROWTH=1 -s ENVIRONMENT='web,worker'

all: $(TARGET).wasm $(TARGET).js

$(TARGET).wasm $(TARGET).js: solver.c
	mkdir -p ../wasm
	emcc solver.c $(CFLAGS) $(EMSCRIPTEN_FLAGS) -o $(TARGET)

clean:
	rm -f $(TARGET).wasm $(TARGET).js $(TARGET).wasm.map

.PHONY: all clean
