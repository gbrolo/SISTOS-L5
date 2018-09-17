# SISTOS-L5
Sistemas Operativos, S.10 2018 - Laboratorio 5

## Como correrlo
Descargar o clonar el repositorio y luego ingresar al directorio donde se descargo el proyecto. Luego ejecute el comando ```make```. Esto compilara el proyecto y correra el validador de sudoku.

## Respuestas
1. ¿Qué es una race condition y por qué hay que evitarlas? Ocurre cuando dos o mas threads pueden acceder a data compartida y tratan de cambiarla al mismo tiempo. Ya que el algoritmo de thread scheduling puede intercambiar entre threads en cualquier momento, no se sabe el orden en el que los threads tratarian de acceder a la data compartida.

2. ¿Cuál es la relación entre ```pthreads``` y ```clone()```? ¿Hay diferencia al crear threads con uno o con otro?¿Qué es más recomendable? ```clone``` crea un proceso nuevo que es un clon del proceso existente. Esta es una vulnerabilidad, ya que crear un proceso nuevo tiene una poca cantidad de overhead. Significaria tambien que la comunicacion entre los procesos tendria que hacerse a traves de un canal aprovado, i.e., ```pipes, sockets, archivos```, etc. Usar ```pthreads``` es una fortaleza, ya que provee mucho mas encapsulacion entre el proceso padre e hijo

3. ¿Dónde, en su programa, hay paralelización de tareas, y dónde de datos? La paralelizacion de tareas ocurre cuando se crean los ```pthreads```, mientras que cada uno de esos threads es ejecutado en diferentes componentes de la data del sudoku, en donde se efectua la parelizacion de datos.

4. Al  agregar  los ```#pragmas```  a  los  ciclos for,  ¿cuántos  LWP’s hay  abiertos  antes  de  terminar  el main(), y cuántos durante la revisión de columnas? ¿Cuántos user threads deben haber abiertos en cada caso entonces? Hay 6 LWP's abiertos antes de terminar el main y 2 durante la revision de columnas. Hay 4 user threads abiertos.

5. Al limitar el número de threads en ```main()``` a uno, ¿cuántos LWP’s hay abiertos durante la revisión de columnas? Compare esto con el número de LWP’s abiertos antes de limitar el  número  de threads en ```main()```. ¿Cuántos threads crea OpenMP (en general) por defecto?  Hay 4 LWP's al principio. Sin limite hay 6. Por defecto crea 4.

6. Observe cuáles LWP’s están abiertos durante la revisión de columnas según ```ps```. ¿Qué significa la primera columna de  resultados de  este comando? ¿Cuál es  el LWP que  está inactivo y por qué está inactivo? En la primera columna se aprecian los process id's de los procesos que se estan ejecutando. El LWP del main esta inactivo, ya que son los otros procesos los que estan en ejecucion.

7. Compare los resultados de ```ps``` en la pregunta anterior con los que son desplegados por el método de revisión de columnas per se. ¿Qué es un thread ```team``` en OpenMP y cuál es el master thread en  este caso? ¿Por  qué  parece  haber  un thread "corriendo", pero que  no  está  haciendo  nada? ¿Qué significa el término busy-wait? ¿Cómo maneja OpenMP su thread ```pool```? Un thread team es un conjunto de threads que trabajan en equipo. El master thread es el padre. Porque esta esperando a que los hijos terminen con sus procesos. Significa que esta esperando pero realiza alguna accion mientras espera. Se van seleccionando threads de un "pool" de threads hasta que ya no existan o el padre especifique que las ejecuciones terminaron.

8. Luego  de  agregar por  primera  vez la  cláusula schedule (dynamic) y  ejecutar  su  programa repetidas veces, ¿cuál es el máximo número de threads trabajando según el método de revisión de columnas? Al comparar este número con la cantidad de LWP’s que se creaban antes de agregar ```schedule()```, ¿qué deduce sobre la distribución de trabajo que OpenMP hace por defecto? Son 4 threads. Que OpenMP distribuye las tareas en pares y cuando se finalicen las tareas del pool, cierra los threads.

9. Luego de agregar las llamadas ```omp_num_threads()``` a cada método donde se usa OpenMP, y luego  de ejecutar  su  programa  con  y  sin  la  cláusula ```schedule()``` en  cada for,  ¿hay  más  o menos concurrencia en su programa? ¿Es esto sinónimo de un mejor desempeño? Explique. Hay mas, por que son mas los threads que OpenMP asigna. No necesariamente significa un mejor desempeno, ya que luego de cierto numero de procesos el rendimiento tendera a ser el mismo.

10. ¿Cuál es el efecto de agregar ```omp_set_nested(true)```? Explique. Se crea paralelismo anidado, lo que significa que los threads estaran anidados uno dentro de otro, por lo que el rendimiento aumenta un poco ya que ciertos threads se ejecutaran concurrentemente y paralelamente ademas.

### Screenshots
![1](https://github.com/gbrolo/SISTOS-L5/blob/master/img/1.PNG)
![2](https://github.com/gbrolo/SISTOS-L5/blob/master/img/2.PNG)
