void Runs_insertionSort(uint64_t arr[], uint64_t n)  
{  
	/*Creamos las variables iniciales que usaremos. El valor de "secuencia" representa la posición en arr del ultimo elemento que agregamos a nuestro vector*/
    int64_t i, j, secuencia;  
    /*key funciona igual que la llave de insertion sort, pero una secuencia completa también se tomara como una key, es por esto que se usara un vector donde se guardan los elementos*/
    vector<uint64_t> key;
    
    for (i = 1; i < n; i++) 
    {  
		secuencia = i;
		j = i - 1;
		/*Comenzamos agregando el primer valor que estará en la secuencia el la iteración actual*/
		key.push_back(arr[secuencia]);

		/*Agregamos primero que todo todos los elementos repetidos, si es que existen*/
		while( (secuencia != (n-1)) && (arr[secuencia] == arr[secuencia+1]) ){
	        	
	        secuencia=secuencia+1;
	        key.push_back(arr[secuencia]);
	        	
		}
		
		/*Si la secuencia es ascendente, entramos a este if*/
		if(arr[secuencia] <= arr[secuencia+1] || (secuencia == (n-1))){

			/*Agregamos todos los valores mayores que esten delante del elemento anterior*/
	        while( (secuencia != (n-1)) && (arr[secuencia] <= arr[secuencia+1]) ){
	        	
	        	secuencia=secuencia+1;
	        	key.push_back(arr[secuencia]);
	        	
			}
			
			/*Actualizamos el valor de "i", ya que la secuencia mueve el valor de i para la siguiente iteración*/
	        i=secuencia;
	  		
	  		/*Seccion de ordenamiento*/
			while (key.size() != 0){
				/*Se iran moviendo hacia delante los valores que sean mayores a el ultimo valor agregado a key*/
				while (j >= 0 && arr[j] > key.back()) 
		        {  
		            arr[secuencia] = arr[j];
					secuencia = secuencia - 1;
		            j = j - 1;  
		        } 
				 /*Colocamos el ultimo valor de key (el mayor valor de la secuencia) en donde debe ir. Esto se realizara hasta que key quede vacio*/
		        arr[secuencia] = key.back(); 
		        secuencia = secuencia -1;
		        key.pop_back();
		        /*recordar que se agrega en cada iteración solo el ultimo elemento de key para volver a 
	        	comprobar que no existan elementos mayores al nuevo elemento de key que quedo como ultimo*/
			}
		}
		/*Se entra al else if si es que la secuencia sera descendente*/
		else if(arr[secuencia] >= arr[secuencia+1]){
			/*Agregamos todos los valores menores que esten delante del elemento anterior*/
			while( (secuencia != (n-1)) && (arr[secuencia] >= arr[secuencia+1]) ){
	        	
	        	secuencia=secuencia+1;
	        	key.push_back(arr[secuencia]);
	        	
			}
			
	        i=secuencia;
	  		/*Seccion de ordenamiento*/
			while (key.size() != 0){
				/*Se iran moviendo hacia delante los valores que sean mayores a el primer valor agregado a key*/
				while (j >= 0 && arr[j] > key.front()) 
		        {  
		            arr[secuencia] = arr[j];
					secuencia = secuencia - 1;
		            j = j - 1;  
		        } 
				 /*Colocamos el primer valor de key (el mayor valor de la secuencia) en donde debe ir. Esto se realizara hasta que key quede vacio*/
		        arr[secuencia] = key.front(); 
		        secuencia = secuencia -1;
		        key.erase(key.begin());
			}
		}

		
        i=secuencia;
  		
	}

} 