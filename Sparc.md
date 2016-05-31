# Sparc M7

## Información General
<http://www.oracle.com/us/products/servers-storage/servers/sparc-enterprise/migration/m7-next-gen-sparc-presentation-2326292.html>

**Información:**
  - Frecuencia: 4133 MHZ
  - Año lanzamiento: 2015
  - Nº núcleos: 32
  - Nº threads: 8x32 = 256
  - Proceso: 20nm
  - L1 datos: 16x32 = 512 KiB
  - L1 instrucciones: 16x32 = 1024 KiB
  - L2: 256x24 = 6144 KiB
  - L3: 64MB
  - 8 unidades DAX

> The M7 is a 4.13GHz 32-core, 256-hardware-thread CPU with 64MB of on-chip L3 cache.
It can scale up to 512 cores and 4,096 threads, and address up to 8TB of physical RAM.
The CPU architecture is Sparc V9.

Sparc M7 tiene 32 Cores con threads dinámicos e independientes entre 1 y 8 por core.
La memoria cache L2 es compartida dentro del cluster de 4 cores, en total hay 8 clusters.
La memoria cache L3 es compartida por todos pero está fragmentada y repartida por el chip.
Soporta memoria RAM DDR4 hasta 2TB de memoria física por procesador. Es escalable hasta
32 procesadores.  

Cada core es un fuera de orden, capaz de extraer hasta 2 instrucciones a la vez de la
etapa de issue. Tiene 2 ALUs, 1 unidad load store, 1 unidad de punto flotante, 1
unidad de resolución de saltos, y 1 unidad criptográfica.  




## DAX
<https://swisdev.oracle.com/DAX/DAXwhatis.php>

DAX es tanto una nueva unidad dentro del chip como un nuevo conjunto de instrucciones.
Esta enfocada principalmente en operaciones de big data y base de datos. Permite
separar tareas de analisis de grandes cantidades de datos, de la parte lógica
del procesador. Se encuentra junto al controlador de memoria y es capaz de trabajar
al ancho de banda de memoria quitando estres a las memorias cache.

> DAX units perform 4 basic tasks:
 * Extract: Creates an unpacked output stream from an input stream that may be
    * Fixed-width byte packed
    * Fixed-width bit packed
    * Run-length encoded (RLE)
    * N-gram Huffman compressed
    * Variable-width byte-packed
 * Scan: Compares elements of an input vector to two or more boundary values
 * Select: Given an input data vectors and an input bit vector, it produces an output vector elements that matches the input bit vector
 * Translate: Transforms an input source vector using a bit vector translate table pattern into corresponding bits at those indices.

__Ejemplos de uso:__

> These advantages can be used in several algorithms. Here are some examples:
 * Key Value pairs: both simple and complex
 * Building Analytic Cubes
 * Finding top <N> items from an ordered list
 * In-memory Merge Sort
 * JSON processing
 * Outlier Detection

## Seguridad
<http://www.theregister.co.uk/2015/10/28/oracle_sparc_m7/>

Las memorias utilizan Silicon Secured Memory (SSM). El cual hace que cuando un programa
reserve memoria con malloc() por ejemplo al bloque de memoria se le asigne un tag
con un numero de versión en los últimos 4 bits de la memoria los cuales no se utilizan de
normal.

 - - -

# SPARC64 XIfx (Fujitsu)

## Información General

**Información:**
  - Frecuencia: 2200
  - Año lanzamiento: 2015
  - Nº núcleos: 32 cores más 2 de asistencia
  - Nº threads: 1×(32+2)=34
  - Proceso: 20nm
  - L1 datos: 64x34 = 2176 KiB
  - L1 instrucciones: 64x34 = 2176 KiB
  - L2: 12 x 2 MB
  - L3: no tiene

# Bibliografía

  * <http://www.theregister.co.uk/2015/10/28/oracle_sparc_m7/>
  * <https://en.wikipedia.org/wiki/SPARC>
  * <https://www.fujitsu.com/hk/Images/20140811hotchips26.pdf>
  * <http://www.enterprisetech.com/2014/08/13/oracle-cranks-cores-32-sparc-m7-chip/>
  * <https://cr.yp.to/2005-590/sparcv9.pdf>
  * <http://www.hotchips.org/wp-content/uploads/hc_archives/hc26/HC26-12-day2-epub/HC26.12-7-Dense-Servers-epub/HC26.12.721-SPARC-cache-Sivaramakrishan-Oracle_final_2.pdf>
