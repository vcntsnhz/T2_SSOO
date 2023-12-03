# Procesamiento paralelo de imagenes utilizando OpenMP.

## Instrucciones:

(1) Para compilar, primero ubicarse en el directorio **/openMP** y ejecutar el siguiente comando:

```bash
make
```

(2) Luego para su ejecución, se debe ejecutar el siguiente comando:

```bash
./openMP nombre_imagen procesada hebras
```
* **nombre_imagen:** Nombre de la imagen que se quiere aplicar el filtro de blanco y negro.
* **nombre_imagen_procesada:** Nombre que se le quiere dar a la imagen procesada con el filtro de blanco y negro aplicado.
* **hebras:** Numero de hebras/hilos que se desea utilizar para aplicar el filtro de blanco y negro a la imagen.

## Ejemplos y pruebas

```bash
./openMP imagen.jpg imagenGris.jpg 4
```

![Ejemplo de openMP](https://i.imgur.com/Z9t0HVh.png)

_A continuación se puede apreciar una prueba realizada con distinto números de hilos, en este caso 4,8 y 16 hilos, evidenciado así las diferencia en velocidades de procesamiento._
![Prueba de openMP](https://i.imgur.com/nKzBvd4.png)

