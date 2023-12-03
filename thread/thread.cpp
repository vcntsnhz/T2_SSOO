#include <iostream>
#include <opencv2/opencv.hpp>
#include <thread>
#include <chrono>
#include <vector>

using namespace cv;
using namespace std;
using namespace chrono;

void aplicarFiltro(Mat& imagen, Mat& imagen_gris, int inicioFila, int finFila) {
    for (int i = inicioFila; i < finFila; ++i) {
        for (int j = 0; j < imagen.cols; ++j) {
            Vec3b pixel = imagen.at<Vec3b>(i, j);
            uchar luminosity = static_cast<uchar>(0.3 * pixel[2] + 0.59 * pixel[1] + 0.11 * pixel[0]);
            imagen_gris.at<uchar>(i, j) = luminosity;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cout << "Error: Por favor, ingresar parametros válidos." << endl;
        return -1;
    }

    Mat imagen = imread(argv[1], IMREAD_COLOR);

    if (imagen.empty()) {
        cout << "Error: No se encontró la imagen a color, por favor ingrese un nombre válido.\n";
        return -1;
    }

    int nroHilos = atoi(argv[3]);
    if (nroHilos <= 0) {
        cout << "Error: El número de hilos debe ser un número entero positivo.\n";
        return -1;
    }

    cout << "Nro de filas (altura): " << imagen.rows << endl;
    cout << "Nro de columnas (ancho): " << imagen.cols << endl;

    auto inicio = high_resolution_clock::now();

    Mat imagen_gris(imagen.rows, imagen.cols, CV_8UC1);

    int numHilos = atoi(argv[3]);
    vector<thread> hilos;

    int filasPorHilo = imagen.rows / numHilos;
    int inicioFila = 0;

    for (int i = 0; i < numHilos - 1; ++i) {
        int finFila = inicioFila + filasPorHilo;
        hilos.emplace_back(aplicarFiltro, ref(imagen), ref(imagen_gris), inicioFila, finFila);
        inicioFila = finFila;
    }

    hilos.emplace_back(aplicarFiltro, ref(imagen), ref(imagen_gris), inicioFila, imagen.rows);

    for (auto& thread : hilos) {
        thread.join();
    }

    auto fin = high_resolution_clock::now();

    cout << "El tiempo de ejecución total: " << duration_cast<duration<float>>(fin - inicio).count() << " segundos" << endl;

    imwrite(argv[2], imagen_gris);
    imshow("Imagen en escala de grises", imagen_gris);
    waitKey(0);

    return 0;
}



