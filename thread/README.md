# Procesamiento paralelo de imagenes utilizando hebras.

## Instrucciones:

(1) Para compilar, primero ubicarse en el directorio **/thread** y ejecutar el siguiente comando:

```bash
make
```

(2) Luego para su ejecución, se debe ejecutar el siguiente comando:

```bash
./thread nombre_imagen nombre_imagen_procesada hebras
```
* **nombre_imagen:** Nombre de la imagen que se quiere aplicar el filtro de blanco y negro.
* **nombre_imagen_procesada:** Nombre que se le quiere dar a la imagen procesada con el filtro de blanco y negro aplicado.
* **hebras:** Numero de hebras/hilos que se desea utilizar para aplicar el filtro de blanco y negro a la imagen.

## Ejemplos y pruebas

```bash
./thread imagen.jpg imagenGris.jpg 4
```

![Ejemplo de Thread](https://i.imgur.com/u6xMNfX.png)

_A continuación se puede apreciar una prueba realizada con distinto números de hilos, en este caso 4,8 y 16 hilos, evidenciado así las diferencia en velocidades de procesamiento._
![Prueba de Thread](https://i.imgur.com/hXjsFoN.png)

