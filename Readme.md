# 🐜 Proyecto 2 - Hormigas por doquier (HPD)

 👨‍💻 Autores
- Nombres: Florencia Pereira, Jose Carrillo, Renato Quezada


📌 Descripción del programa

Este proyecto simula el comportamiento de la Hormiga de Langton, un autómata celular que se mueve sobre una grilla bidimensional de celdas blancas y negras, modificando su entorno según reglas simples:

- Si la hormiga está sobre una celda blanca, gira 90° a la derecha, cambia la celda a negra y avanza una casilla.
- Si la hormiga está sobre una celda negra, gira 90° a la izquierda, cambia la celda a blanca y avanza una casilla.

La simulación genera imágenes con cada paso que muestra la evolución de la grilla, utilizando OpenCV para la visualización.

---

## ⚙️ Instrucciones para compilar y ejecutar

### 1. Requisitos

- CMake (versión 3.10 o superior)
- C++17 o superior

### 2. Compilación

Desde la carpeta raíz del proyecto, ejecuta:

```bash
make
```

Esto generará el ejecutable del programa.

### 3. Ejecución

Una vez compilado, ejecuta el programa desde la carpeta `build`:

```bash
./main
```

El programa pedirá al usuario:

- El tamaño de la grilla (N x M) 
- Se espera la entrada de un digito luego se presiona ENTER y luego se introduce el segundo digito
- La cantidad de pasos a simular

Las imágenes se guardarán en la carpeta `output/` con nombres como `paso_0001.png`, `paso_0002.png`, etc.

---

## 🖼️ Formato de salida

-  Formato: `.png`
-  Nombre de archivo: `paso_XXXX.png` (con ceros a la izquierda)
-  Contenido:
- La posición y dirección actual de la hormiga.
- Celdas blancas y negras.
- La hormiga se visualiza con una flecha de color rojo apuntando en su orientación actual.

---

## 💬 Notas adicionales

- La grilla es de tamaño finito, y si la hormiga alcanza el borde, rebota.
- La distribución inicial de colores es aleatoria.

