#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
#include <string>

// Biblioteca header-only para exportar PNG (descargar de https://github.com/nothings/stb)
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

const int CELL_SIZE = 10; // tamaño de cada celda en píxeles

enum Direction { UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3 };

// Función para guardar la imagen como PNG
void savePNG(const std::string& filename, const std::vector<unsigned char>& img, int width, int height) {
    // img contiene datos en RGB (3 canales)
    stbi_write_png(filename.c_str(), width, height, 3, img.data(), width * 3);
}

int main() {
    int N, M, steps;
    std::cout << "Dimensiones de la grilla (filas y columnas): \n Respuesta esperada (N M) = 5 6\n";
    std::cin >> N >> M;
    std::cout << "Cantidad de pasos de la hormiga: ";
    std::cin >> steps;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 1);

    // Inicializar grilla con 0 (blanco) o 1 (negro)
    std::vector<std::vector<int>> grid(N, std::vector<int>(M));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            grid[i][j] = dist(gen);

    // Posición inicial: centro
    int antX = N / 2;
    int antY = M / 2;
    Direction dir = UP;

    int width = M * CELL_SIZE;
    int height = N * CELL_SIZE;
    std::vector<unsigned char> image(width * height * 3);

    for (int step = 1; step <= steps; ++step) {
        // Regla de Langton
        if (grid[antX][antY] == 0) {
            dir = static_cast<Direction>((dir + 1) % 4);
            grid[antX][antY] = 1;
        } else {
            dir = static_cast<Direction>((dir + 3) % 4);
            grid[antX][antY] = 0;
        }
        // Avanzar con envoltura
        switch (dir) {
            case UP:    antX = (antX - 1 + N) % N; break;
            case RIGHT: antY = (antY + 1) % M; break;
            case DOWN:  antX = (antX + 1) % N; break;
            case LEFT:  antY = (antY - 1 + M) % M; break;
        }

        // Dibujar grilla en el buffer
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                unsigned char color = grid[i][j] == 0 ? 255 : 0;
                for (int dy = 0; dy < CELL_SIZE; ++dy) {
                    for (int dx = 0; dx < CELL_SIZE; ++dx) {
                        int x = j * CELL_SIZE + dx;
                        int y = i * CELL_SIZE + dy;
                        int idx = (y * width + x) * 3;
                        image[idx + 0] = color;
                        image[idx + 1] = color;
                        image[idx + 2] = color;
                    }
                }
            }
        }
        // Dibujar hormiga: celda roja
        for (int dy = 0; dy < CELL_SIZE; ++dy) {
            for (int dx = 0; dx < CELL_SIZE; ++dx) {
                int x = antY * CELL_SIZE + dx;
                int y = antX * CELL_SIZE + dy;
                int idx = (y * width + x) * 3;
                // Rojo
                image[idx + 0] = 255;
                image[idx + 1] = 0;
                image[idx + 2] = 0;
            }
        }

        std::ostringstream oss;
        oss << "paso_" << std::setw(4) << std::setfill('0') << step << ".png";
        savePNG(oss.str(), image, width, height);
    }

    std::cout << "Simulacion completada. Archivos generados." << std::endl;
    return 0;
}
