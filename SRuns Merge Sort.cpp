void SRuns_merge(secuencia A_prima[], uint64_t l, uint64_t m, uint64_t r) 
{ 
    uint64_t i, j, k; 
    uint64_t n1 = m - l + 1; 
    uint64_t n2 =  r - m; 

    /* Creamos arreglos temporales de tipo secuencia. Cabe mencionar que
       L=izquierda y R=derecha, es decir, los arreglos hacen referencia
       a la manera en que merge realiza recursividad creando arreglos
       que se van ramificando hacia la izquierda y la derecha. */
    secuencia* L = new secuencia[n1];
    secuencia* R = new secuencia[n2];
  
    /* Copiamos las secuencias de nuestro lado izquierdo a L[]
       y el derecho a R[] */
    for (i = 0; i < n1; i++) 
        L[i] = A_prima[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = A_prima[m + 1+ j]; 
  
    /* Realizaremos merge de los arreglos temporales a A_prima[1...r]*/
    i = 0; // index inicial del primer subarreglo
    j = 0; // index inicial del segundo subarreglo
    k = l; // index inicial del subarreglo mergeado
    while (i < n1 && j < n2) 
    { 
        if (L[i].Inicio <= R[j].Inicio) 
        { 
            A_prima[k] = L[i]; 
            i++; 
        } 
        else
        { 
            A_prima[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copiamos los elementos restantes de L[], si es que
       sobran*/
    while (i < n1) 
    { 
        A_prima[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copiamos los elementos restantes de R[], si es que
       sobran*/
    while (j < n2) 
    { 
        A_prima[k] = R[j]; 
        j++; 
        k++; 
    }
	
	delete[] L;
    delete[] R; 
} 
  

void SRuns_mergeSort(secuencia A_prima[], uint64_t l, uint64_t r) 
{ 
    /* l es por el indice izquierdo y r el derecho del sub-arreglo de arr que sera ordenado  */
    if (l < r) 
    { 
        /*m sera la mitad entre l y r. Al inicio toma como valor
          la mitad del largo de A_prima*/
        uint64_t m = (l+r)/2; 
  
        /*Ordenaremos la primera y la segunda mitad de A_prima*/
        SRuns_mergeSort(A_prima, l, m); 
        SRuns_mergeSort(A_prima, m+1, r); 
        /*Al ordenarlo todo en pequeños arreglos producto de la recursividad
          solo falta realizar merge y unir todo*/
        SRuns_merge(A_prima, l, m, r); 


    } 
} 


void SRuns_mergeSort_PreBuild(uint64_t arreglo[], uint64_t n){
	
    /*Es la cantidad de paquetes con secuencias ordenadas que 
      tendremos en nuestro arreglo*/
    int Cantidad_De_Paquetes;

    /*A_prima sera un arreglo de tipo secuencia en el cual se agregaran
      los paquetes de las secuencias ordenadas del arreglo de entrada*/
    secuencia* A_prima = new secuencia[n];
    
    /*Llamamos a la funcion Crear_Arreglo_de_secuencias la cual agregara los
      paquetes de secuencias a A_prima y ademas nos entregara la cantidad
      de paquetes agregados a A_prima*/
    Cantidad_De_Paquetes = Crear_Arreglo_de_secuencias(arreglo,n, A_prima);

    /*Se realiza un procedimiento parecido al a Insertion Sort, pero se a
      adaptado para realizarse con A_prima*/

	SRuns_mergeSort(A_prima, 0, Cantidad_De_Paquetes-1);
	
}