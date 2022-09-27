# Metodología de Programación
## De bits a imágenes

Proyectos de Metodología de Programación
1º Doble Grado Ingeniería Informática y Administración y Dirección de Empresas

Curso 2021-2022![g2](https://user-images.githubusercontent.com/82287587/192602943-0e90484d-0300-4ff2-93fe-c77e87203e50.png)


Una imagen digital en blanco y negro, como las que figuran en la
portada  un conocido ejemplo de procesamiento
digital de imágenes..), puede verse como una matriz de puntos, llamados
píxeles, determinada por sus dimensiones (altura x anchura). Por el hecho
de ser en blanco y negro, cada píxel se puede representar mediante un
byte, el rango de valores que este puede tomar es el intervalo [0,255]).
Una ilustración puede verse en la imagen derecha de la portada.
De forma general, una imagen se almacena en fichero en un determinado
formato, reconocible por su extensión, que contiene además de la matriz,
unos metadatos o informacion interna para su visualización, así los hay
.jpg, .png, .gif etc. Para visualizar imágenes de fotos, dibujos, logos,
creadas o transformadas es necesario un programa de visualización como
ImageMagick o gimp entre otros muchos, ambos 
disponibles para linux y windows. 
Se recomienda la instalación de ImageMagick
para las practicas. 
A lo largo de las prácticas se va a reconocer, leer y escribir imágenes
en formato PGM (.pgm), sobre las que vamos a realizar algunas transformaciones
comunes en cualquier editor de imágenes, avanzando hacia otras operaciones
más complejas que trabajan con varias imágenes. 
Durante el desarrollo
de las prácticas se van a elaborar estructuras y métodos necesarios para
la realización de una atractiva práctica final que consiste en la implementación
de un proceso de esteganografía que nos permitir ´a ocultar una imagen y/o
texto, dentro de una imagen portadora sin que la alteración sea perceptible
