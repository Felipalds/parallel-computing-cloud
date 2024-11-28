#include  <stdio.h>
#include  <omp.h>

int  main()
{
     printf("--Fora da regiao paralela--\n");

     // omp_set_num_threads(10002); //Função para definir o número de threads
     #pragma omp parallel // num_threads(2) //Função para definir o número de threads
     {
        int id = omp_get_thread_num(); //Função para obter a identificação da thread
        int nt = omp_get_num_threads(); //Função para obter o número de threads
        printf("Regiao Paralela - Hello, world da thread %d! - %d\n",id, nt);
     }

     printf("--Fora da regiao paralela--\n");
     return  0;
}
