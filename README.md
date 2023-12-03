# Procesamiento paralelo de imagenes utilizando hebras.

## Integrantes

* **Victor Herrera Merino**
* **Vicente Sanhueza Muñoz**


## Indice

* [Integrantes](#integrantes)
* [Introducción](#introducción)
* [Pre-requisitos](#pre-requisitos)
* [Compilación y ejecución](#compilación-y-ejecución)

## Introducción

El procesamiento paralelo implica realizar múltiples tareas simultáneamente, ofreciendo ventajas como mayor velocidad y rendimiento, eficiencia en el manejo de grandes volúmenes de datos, escalabilidad y aplicabilidad en diversas áreas. Además, puede contribuir a una mayor eficiencia energética.

Para la conversión RGB a escala de grises, existen varios métodos como el  Lightness Method (promedio de componentes máximo y mínimo), el Average Method (promedio simple de componentes) y, finalmente, el Luminosity Method. Este último es el método que se utilizo en este proyecto para la conversión de una imagen RGB a escala de grises, se destaca por abordar las limitaciones de los métodos anteriores mediante un promedio ponderado, donde la contribución de azul disminuye, y la de verde aumenta. La ecuación resultante es:

Escala de grises= **0.3×R + 0.59×G + 0.11×B**

Este enfoque tiene en cuenta la sensibilidad del ojo humano a cada color y proporciona una representación más precisa de la luminosidad en una imagen en escala de grises.

![Imagen a color](https://i.imgur.com/JIgXlRx.jpg)
![Imagen procesada en gris](https://i.imgur.com/o9ECxwp.png)


### Pre-requisitos

_Es importante ejecutar estos comandos antes de compilar los códigos proporcionados en tu proyecto para asegurarte de tener todas las dependencias instaladas._


_Este comando instala el **compilador de C++** en tu sistema._

```bash
   sudo apt-get install g++
   ```

_Este comando instala la **herramienta make** en tu sistema. make es una utilidad que simplifica el proceso de compilación de proyectos al automatizar la ejecución de comandos necesarios para construir un programa a partir de su código fuente._

   ```bash
   sudo apt-get install make
   ```

_Este comando instala las **bibliotecas de desarrollo de OpenCV**en el sistema. OpenCV es una librería esencial para el procesamiento de imágenes y visión por computadora en lenguaje C++ y otros._

   ```bash
   sudo apt install libopencv-dev
   ```

### Compilación y ejecución

_A continuación se encontra un índice el cual redirecciona al proceso de compilación y ejecución de cada método de procesamiento de imagenes empleado, con sus respectivas pruebas._

* [Secuencial](/secuencial/README.md)
* [Paralela Threads](/thread/README.md)
* [Paralela OpenMP](/openMP/README.md)

---
