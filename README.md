# SISTOS-L5
Sistemas Operativos, S.10 2018 - Laboratorio 5

## Respuestas
1. ¿Qué es una race condition y por qué hay que evitarlas?

2. ¿Cuál es la relación entre ```pthreads``` y ```clone()```? ¿Hay diferencia al crear threads con uno o con otro?¿Qué es más recomendable?

3. ¿Dónde, en su programa, hay paralelización de tareas, y dónde de datos?

4. Al  agregar  los ```#pragmas```  a  los  ciclos for,  ¿cuántos  LWP’s hay  abiertos  antes  de  terminar  el main(), y cuántos durante la revisión de columnas? ¿Cuántos user threads deben haber abiertos en cada caso entonces?

5. Al limitar el número de threads en ```main()``` a uno, ¿cuántos LWP’s hay abiertos durante la revisión de columnas? Compare esto con el número de LWP’s abiertos antes de limitar el  número  de threads en ```main()```. ¿Cuántos threads crea OpenMP (en general) por defecto?

6. Observe cuáles LWP’s están abiertos durante la revisión de columnas segúnps. ¿Qué significa la primera columna de  resultados de  este comando? ¿Cuál es  el LWP que  está inactivo y por qué está inactivo?

7. Compare los resultados de ```ps``` en la pregunta anterior con los que son desplegados por el método de revisión de columnas per se. ¿Qué es un thread ```team``` en OpenMP y cuál es el master thread en  este caso? ¿Por  qué  parece  haber  un thread "corriendo", pero que  no  está  haciendo  nada? ¿Qué significa el término busy-wait? ¿Cómo maneja OpenMP su thread ```pool```?

8. Luego  de  agregar por  primera  vez la  cláusula schedule (dynamic) y  ejecutar  su  programa repetidas veces, ¿cuál es el máximo número de threads trabajando según el método de revisión de columnas? Al comparar este número con la cantidad de LWP’s que se creaban antes de agregar ```schedule()```, ¿qué deduce sobre la distribución de trabajo que OpenMP hace por defecto?

9. Luego de agregar las llamadas ```omp_num_threads()``` a cada método donde se usa OpenMP, y luego  de ejecutar  su  programa  con  y  sin  la  cláusula ```schedule()``` en  cada for,  ¿hay  más  o menos concurrencia en su programa? ¿Es esto sinónimo de un mejor desempeño? Explique.

10. ¿Cuál es el efecto de agregar ```omp_set_nested(true)```? Explique.

### Screenshots
![1](https://github.com/gbrolo/SISTOS-L5/blob/master/img/1.PNG)
![2](https://github.com/gbrolo/SISTOS-L5/blob/master/img/2.PNG)
