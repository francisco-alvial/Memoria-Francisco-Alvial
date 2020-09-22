struct secuencia {
  uint64_t  Inicio;
  uint64_t Fin;
} paquete;


int Crear_Arreglo_de_secuencias(uint64_t arreglo[], uint64_t n, secuencia* A_prima){
	
	/* Esta variable sirve para comprobar si todavia estamos en una secuencia. 
	   Si es 0 acabamos de salir de una secuencia, si es 1 estamos en una secuencia*/
	int comprobar_consecutivo=1; 

	/*/ Esta variable guardara la cantidad de paquetes o secuencias que agregaremos a A_prima*/
	int Cantidad_De_Paquetes=0;

	/* Se toma el primer valor del arreglo y si guarda en una variable que llamaremos Inicio
	   el cual hace referencia al Inicio del struct secuencia. Por otra parte dejamos creada la
	   varible fin */
  	uint64_t inicio = arreglo[0];
	uint64_t fin;

	/* Esta variable comprobara si estamos en una secuencia ascendente o descendente.
	   Si el valor es 0 no es descendente y 1 si lo es*/
  	int descendente = 0;
  	
  	for (uint64_t i = 1; i < n; ++i) 
    {
    	/*Comprobamos si existe un valor mayor consecutivo en la posicion i con el elemento de i-1.
    	  Esto se hace de esta manera por el hecho de que partimos en i=1 comparando con i=0*/
    	if( (arreglo[i] == (arreglo[i-1]+1)) ){
    		comprobar_consecutivo=1;
    		descendente = 0;
		}
		/*Comprobamos si existe un valor menor consecutivo en la posicion i con el elemento de i-1*/
		else if( (arreglo[i] == (arreglo[i-1]-1)) ){
			comprobar_consecutivo = 1;
    		descendente = 1;
		}
		/* Se entra al else cuando ya no existen numeros consecutivos, de esta forma comienza el proceso
		   De crear el paquete con los valores y agregarlos a A_prima*/
        else{
        	//si la secuencia es ascendente entramos al if
        	if(descendente == 0){
        		/*cambiamos el valor de comprobar_consecutivos a 0 ya que el elemento en i rompe la secuencia*/
	        	comprobar_consecutivo=0;
	        	/* Agregamos como fin el elemento de i-1, ya que es el ultimo 
	        	   valor de la secuencia encontrada */
	        	fin=arreglo[i-1];

	        	/*Agregamos a nuestro paquete de tipo struct secuencia el inicio y el fin guardados anteriormente*/
	        	paquete.Inicio = inicio;
	        	paquete.Fin = fin;

	        	/*Agregamos la secuencia a A_prima*/
	        	A_prima[Cantidad_De_Paquetes] = paquete;
	        	/*Cambiamos nuestro inicio con el elemento en i actual, ya que este rompe la secuencia anterior*/
	        	inicio = arreglo[i];
	        	/*Sumamos los paquetes en 1, ya que se agrego una secuencia*/
	        	Cantidad_De_Paquetes++;

	        	/*Esto es un caso que ocurre al llegar al ultimo elemento del arreglo. Esto se realiza
	        	  por el hecho de que si justo el ultimo elemento del arreglo rompe la secuencia se 
	        	  necesita agregarlo de inmediato, ya que el "for" terminara en esta fase (i<n)*/
	        	if(i==(n-1)){
	        		fin=arreglo[i];
	        		paquete.Inicio = inicio;
	        		paquete.Fin = fin;
	        		A_prima[Cantidad_De_Paquetes] = paquete;
	        		Cantidad_De_Paquetes++;
				}
			}
			/*si la secuencia es descendente entramos al else if.
			  Se realiza el mismo proceso que con el if para secuencias ascendentes
			  (descendente == 0) */
			else if(descendente == 1){
	        	comprobar_consecutivo=0;
	        	fin=arreglo[i-1];
	        	paquete.Inicio = fin;
	        	paquete.Fin = inicio;
	        	A_prima[Cantidad_De_Paquetes] = paquete;
	        	inicio = arreglo[i];
	        	Cantidad_De_Paquetes++;
	        	if(i==(n-1)){
	        		fin=arreglo[i];
	        		paquete.Inicio = inicio;
	        		paquete.Fin = fin;
	        		A_prima[Cantidad_De_Paquetes] = paquete;
	        		Cantidad_De_Paquetes++;
				}
			}    	
		}
		/*Este if se enfoca en agregar la secuencia si es que el ultimo
		  elemento del arreglo formaba parte de ella. Esto se debe a que normalmente
		  las secuencias se crean con un i="elemento que rompe la secuencia", pero
		  en este caso estamos en la ultima posicion y el for esta en su ultima fase
		  por lo que necesitamos agregar la secuencia antes de que este termine.
		  El procedimiento de agregar los paquetes es el mismo que en las 
		  fases anteriores*/
		if( i==(n-1) && comprobar_consecutivo==1){
			if(descendente == 0){
				fin=arreglo[i];
	        	paquete.Inicio = inicio;
	        	paquete.Fin = fin;
	        	A_prima[Cantidad_De_Paquetes] = paquete;
	        	Cantidad_De_Paquetes++;
			}
        	else if(descendente == 1){
        		fin=arreglo[i];
        		paquete.Inicio = fin;
	        	paquete.Fin = inicio;
	        	A_prima[Cantidad_De_Paquetes] = paquete;
	        	Cantidad_De_Paquetes++;
			}
		}
    }
    /*Por ultimo retornamos la cantidad de secuencias agregadas a nuestro A_prima*/
	return Cantidad_De_Paquetes;
}