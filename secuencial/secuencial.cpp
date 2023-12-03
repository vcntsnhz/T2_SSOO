#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>

using namespace cv;
using namespace std;
using namespace chrono;

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Error: Por favor, ingresar parametros válidos." << endl;
        return -1;
    }

    Mat imagen = imread(argv[1], IMREAD_COLOR);

    if (imagen.empty()) {
        cout << "Error: No se encontró la imagen a color, por favor ingrese un nombre válido.\n";
        return -1;
    }

    auto inicio = high_resolution_clock::now();

    Mat imagen_gris(imagen.rows, imagen.cols, CV_8UC1);

    for (int i = 0; i < imagen.rows; i++) {
        for (int j = 0; j < imagen.cols; j++) {
            Vec3b pixel = imagen.at<Vec3b>(i, j);
            uchar luminosity = static_cast<uchar>(0.3 * pixel[2] + 0.59 * pixel[1] + 0.11 * pixel[0]);
            imagen_gris.at<uchar>(i, j) = luminosity;
        }
    }

    auto fin = high_resolution_clock::now();

    cout << "El tiempo de ejecución total: " << duration_cast<duration<float>>(fin - inicio).count() << " segundos" << endl;

    imwrite(argv[2], imagen_gris);
    imshow("Imagen en escala de grises", imagen_gris);
    waitKey(0);

    return 0;
}