# educational-robot-sumo #

> Autonomous sumo-like robot for educational use  

* * *

## Resumen ##

Robot autónomo tipo sumo diseñado por los alumnos de la actividad de robótica
[Taller de Inventores](http://tallerinventores.github.io/). Ha sido desarrollado
y optimizado para impresión 3D y pensando en su bajo coste y facilidad de
montaje y uso.

## Instalación ##

En esta sección se cubre la instalación de software y hardware para el montaje
recomendado, mediante [Arduino](http://www.arduino.cc/).

### Requerimientos de software ###

Para poder usar Arduino (v1.6+) con el código fuente proporcionado, son
necesarias la librerías [NewPing](http://playground.arduino.cc/Code/NewPing) y
Servo (incluida en el IDE de Arduino). Para generar los archivos aptos para la
impresora 3D desde los archivos `.stl` será necesario adicionalmente un software
para esta función, como puede ser [Slic3r](http://slic3r.org/).

### Requerimientos de hardware ###

Será necesario para su montaje y uso cuatro pilas tipo AA, dos motores con
reductora en miniatura, un sensor de distancia por ultrasonidos HC-SR04, un
servomotor tipo 9g con sus correspondientes accesorios (tornillos y cuernos) y
una placa Robgednaut Zond con un Arduino Nano o compatible. El robot está
optimizado para usar el servo **TowerPro SG90**. Adicionalmente hará falta
tornillería variada de métrica tres y cinco. Se recomienda un macho de las
mismas métricas.  

## Uso ##

Instrucciones de montaje y puesta en marcha.

### Montaje del robot ###

1.  Imprimir una unidad de los archivos `shovel-mount.stl`, `shovel.stl` y
    `base.stl`. Imprimir dos unidades de `wheel.stl`, `driving-wheel.stl` y
    `motor-cover.stl`. Imprimir cincuenta y dos unidades de `track-link.stl`.
    Puede ser necesario repasar las piezas impresas con el fin de eliminar
    rebabas.  
2.  Insertar un pasador de 3mm (trozo de filamento) de veinte milímetros de
    largo para unir cada pareja de eslabones (_track-link_), haciendo dos
    cadenas cerradas de la misma longitud.
3.  Montar el servo sobre el chasis del robot (_base_) y fijarlo usando uno de
    los tornillos de montaje del servo. Colocar el cuerno y asegurarse de que el
    ángulo de reposo está orientado hacia la parte delantera. Atornillar el
    cuerno con el tornillo proporcionado por el servo.
4.  Fijar el portapilas sobre la base, atornillándolo con dos tornillos de
    métrica tres por seis, roscando sobre el portapilas.
5.  Con dos tramos de varilla roscada de métrica cinco y setenta milímetros de
    largo, roscar un extremo sobre la pala (_shovel_), con la rosca previamente
    hecha. Colocar el sensor de distancia en su sitio e insertar el conjunto
    sobre el soporte (_shovel-mount_).
6.  Crear los dos ejes delanteros a partir de dos tornillos de métrica tres por
    treinta con caña. Insertar en el tornillo dos arandelas planas, la rueda
    loca (_wheel_), otras dos arandelas planas, fijar con tuerca y contratuerca,
    de forma que permita girar libremente la rueda, insertar una arandela plana
    y colocar en la ranura del eje delantero. Fijar con otra arandela en el
    extremo contrario y una tuerca sin apretar. El conjunto del eje delantero
    debe poder correr libremente por la guía.
7.  Presentar el conjunto de la pala sobre la estructura principal y fijarla a
    la misma con dos tornillos de métrica tres por dieciséis, habiendo creado
    rosca sobre el soporte de la pala previamente.
8.  Insertar el eje del motor en las ruedas motrices (_driving-wheel_) y fijarlo
    con un tornillo de métrica tres por seis sobre la cara plana del eje del
    motor. Crear previamente la rosca en el agujero para el prisionero de la
    rueda.
9.  Colocar los dos motores con las ruedas motrices sobre la estructura
    principal, y sujetar apretando las tapas (_motor-cover_) contra la base,
    roscando dos tornillos de métrica tres por dieciséis en la rosca previamente
    realizada.
10. Alinear las ruedas de ambos extremos si fuera necesario, ajustando el
    tornillo prisionero de la rueda motriz.
11. Colocar en su sitio las orugas, asegurando que coinciden correctamente.
    Tensar levemente la oruga con el eje delantero y fijarlo en el sitio.
12. Realizar las uniones eléctricas y la gestión de cables pertinente.

### Conexión eléctrica ###

Este proyecto usa [Robgednaut](http://akornsys-rdi.github.io/robgednaut/) Zond
como placa de conexionado, si no dispones de ella puedes ver su esquema de
conexiones en la página oficial.  

Las alimentaciones para todos los dispositivos las provee la placa de control.
El cable de dato del servomotor se conecta a A, las señales del sensor de
distancia ECHO y TRIGGER se conectan a B y D respectivamente. Los motores de
cada lado van conectados a un canal de la salida para motores, respetando su
polaridad.

### Firmware ###

El Arduino deberá tener cargado el firmware incluido en la carpeta `src` de este
repositorio.  

### Bugs ###

Se han observado los siguientes problemas:  

-   Es necesario sellar los pasadores a los eslabones para evitar que éstos se
    salgan durante el movimiento del robot.  
-   Para ser robot de sumo le faltan los sensores de proximidad que detectan el
    borde del tatami.  

## Enlaces externos ##

Este proyecto también está presente en:  

-   [Thingiverse](http://www.thingiverse.com/thing:1656919).  

## Créditos ##

Proyecto realizado por Taller de Inventores 2016, representado por:  

-   kwendenarmo <kwendenarmo@akornsys-rdi.net>  

Alumnos del Centro de Formación Padre Piquer:  

-   A, Daniel  
-   L, Mario  
-   L, Omar  
-   L, Tarek  
