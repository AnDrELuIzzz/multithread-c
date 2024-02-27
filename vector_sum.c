#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <locale.h>

#define NTHREADS 2

struct vector_sum
{
    int *vector;
    int from, to;
    int result;
};

typedef struct vector_sum cord;

void gera_vetor(int *v, int n)
{
    for (size_t i = 0; i < n; i++)
    {
        v[i] = rand() % 10000; // gera um valor aleatorio de 0 á 9999
    }
}


void *funcao_thread(void *arg){
    cord* const task = arg; //precisa de um casting para (cord*)??

    task->result = 0;
    for (int i = 0; task->from < task->to; i++)
    {
        task->result += task->vector[i];
    }
    pthread_exit(NULL);

}


int juncao(int *vet, size_t n_threads)
{

    pthread_t *threads = malloc(NTHREADS * sizeof(*threads));
    cord *result_tarefa = malloc(NTHREADS * sizeof(*result_tarefa));

    int tam_vet = sizeof(vet) / sizeof(int);
    gera_vetor(vet, tam_vet);
    int start = 0;
    int step = tam_vet / NTHREADS ;

    for (size_t i = 0; i < n_threads; i++)
    {
        result_tarefa[i].vector = vet; //isso esta caro
        result_tarefa[i].from = start;
        result_tarefa[i].to = start + step;
        start += step;
    }
    

    for (size_t i = 0; i < NTHREADS; i++)
    {
        pthread_create(threads + 1, NULL, funcao_thread, result_tarefa +1 );
    }

    int total = 0;

    for (size_t i = 0; i < NTHREADS; i++)
    {
        pthread_join(threads[i],NULL);
        total += result_tarefa[i].result;
    }
    free(result_tarefa);
    free(threads);
    return total;
}

int tam_vet = 0;

int main (int argc, char *argv[]){
    setlocale(LC_ALL,"Portuguese");

    int num_thr;
    switch (argc)
    {
    case 1:
        tam_vet = 9000;
        break;
    case 2:
        tam_vet = atoi(argv[1]);
        break;
    }

    int *vet = (int *)malloc(tam_vet * sizeof(int));
    gera_vetor(vet, tam_vet);

    int resultado = juncao(vet, NTHREADS);

    printf("Soma total: %d\n", resultado);

    free(vet);

    return 0;
}
