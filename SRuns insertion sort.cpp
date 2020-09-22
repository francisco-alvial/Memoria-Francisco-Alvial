void SRuns_Insertion_Sort(uint64_t arreglo[], uint64_t n)  
{
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
    uint64_t i, j;  
    /*Recorremos A_prima*/
    for (i = 1; i < Cantidad_De_Paquetes; i++) 
    {  
        /*Creamos una key de tipo secuencia para poder igualarlo al
          elemento i de A_prima. Cabe destacar que key es el elemento
          que se ira verificando si tiene secuencias mayores a el
          en el arreglo, desde j = i-1*/
        secuencia key = A_prima[i];  
        j = i - 1;  
  
        /* Mueve las secuencias de A_prima[0..i-1] que son
        mayores que la secuencia key una posicion adelante */
        while (j >= 0 && A_prima[j].Inicio > key.Inicio) 
        {  
            A_prima[j + 1] = A_prima[j];  
            j = j - 1;  
        } 
        /*Agrega la secuencia key a la ultima posicion en la 
          que no encontro secuencias mayores a ella*/ 
        A_prima[j + 1] = key;  
    } 


} 