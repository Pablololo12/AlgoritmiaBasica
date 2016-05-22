# Práctica 1 Compresor Huffman

### **Universidad de Zaragoza**
##### Mario Arcega 679192 Y Pablo Hernández 616923

 * * *

## Decisiones y Funcionamiento

La primera decisión que se tomó fue en que lenguaje realizar la práctica. El
lenguaje elegido fue C, debido a tres factores, la velocidad de  ejecución
que tienen los programas escritos en C, la facilidad de C para trabajar con
bits, y la facilidad que se tiene con C para manejar llamadas al sistema.  

A la hora de programar se realizó de una forma muy modular para mejorar
la lectura del código. Todos los ficheros .c tienen una cabecera con los
métodos publicos.

### Compresión

A la hora de comprimir se llama a la función 'comprimir()' situada en el fichero
compactador.c. En nuestra solución hemos considerado que los caracteres
coinciden con los carácteres de C de 8 bits. Así pues la primera tarea que
realiza nuestro algoritmo es recorrer el fichero comprobando la frecuencia de
aparición de cada palabra utilizando para ello una tabla indexada con los
propios carácteres.  

Una vez se tienen las frecuencias se pasa a crear un montículo y a poblarlo. Se
crea directamente un monticulo de arboles para compatibilizar las operaciones,
de este modo primero se insertan arboles que son solo raices. Para la realización
del montículo nos basamos en uno encontrado en <http://www.thelearningpoint.net/computer-science/data-structures-heaps-with-c-program-source-code> del cual se extrajeron las operaciones básicas y se adaptó al
uso que se le iba a dar en la práctica.  

Tras obtener el montículo se escribe en el nuevo fichero el numero de elementos
del montículo y el propio montículo para poder recuperarlo al descomprimir, así
como el numero de carácteres del fichero original para evitar problemas de bits
sueltos. Antes de pasar a escribir se forma el árbol sintactico a partir del
montículo, y de él para obtener mayor velocidad al comprimir se extraen en otra
tabla indexada por carácter, los códigos comprimidos de cada carácter.  

Por último se pasa a comprimir el fichero. Para mejorar las velocidades se
utilizan dos bufferes de 256 carácteres uno para leer y otro para escribir, de
este modo se realizan menos llamadas al sistema.

### Descompresión
