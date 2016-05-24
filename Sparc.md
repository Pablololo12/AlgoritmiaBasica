# Sparc M7

## Información General

**Información:**
  - Frecuencia: 4133 MHZ
  - Año lanzamiento: 2015
  - Nº núcleos: 32
  - Nº threads: 8x32 = 256
  - Proceso: 20nm
  - L1 datos: 16x32 = 512 KiB
  - L1 instrucciones: 16x32 = 512 KiB
  - L2: 256x24 = 6144 KiB
  - L3: 64MB

> The M7 is a 4.13GHz 32-core, 256-hardware-thread CPU with 64MB of on-chip L3 cache.
It can scale up to 512 cores and 4,096 threads, and address up to 8TB of physical RAM.
The CPU architecture is Sparc V9.

## Seguridad

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
