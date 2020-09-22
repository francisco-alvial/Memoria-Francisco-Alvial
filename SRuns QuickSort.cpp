void SRuns_QuickSort(secuencia *A_prima, uint64_t Menor, uint64_t Mayor)  
{  
    uint64_t i = Menor;
    uint64_t j = Mayor;
    /*Se tomara como pivote el Inicio de la secuencia que esta en la mitad de A_prima*/
    uint64_t pivote = A_prima[(i + j) / 2].Inicio;
    /*Creamos una variable temporal que usaremos para realizar el
      intercambio de secuencias dentro de la recursion*/
    secuencia variable_temporal;
    
    /*Se realiza el mismo procedimiento que en quicksort, la diferencia es que usamos 
      el arreglo de secuencias como nuestro arreglo principal al cual le aplicaremos
      recursion. Cabe destacar que siempre usamos el valor de Inicio de una secuencia
      para realizar las comparaciones*/
    while (i <= j)
    {
        while (A_prima[i].Inicio < pivote)
            i++;
        while (A_prima[j].Inicio > pivote)
            j--;
        if(i <= j)
        {
            variable_temporal = A_prima[i];
            A_prima[i] = A_prima[j];
            A_prima[j] = variable_temporal;
            i++;
            j--;
        }
    }
    if(j > Menor)
        SRuns_QuickSort(A_prima, Menor, j);
    if(i < Mayor)
        SRuns_QuickSort(A_prima, i, Mayor);
} 

void SRuns_QuickSort_PreBuild(uint64_t arreglo[], uint64_t n){
    
    
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

    
    SRuns_QuickSort(A_prima, 0, Cantidad_De_Paquetes-1);
    
}