
# Compilador y opciones
CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall

# Archivos
SRC = main.cpp
HDR = stb_image_write.h
TARGET = main

# Regla por defecto
all: $(TARGET)

# Compilar ejecutable
$(TARGET): $(SRC) $(HDR)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Limpiar ejecutables e imágenes generadas
.PHONY: clean
clean:
	rm -f $(TARGET) paso_*.png
