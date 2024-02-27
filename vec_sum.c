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
    for (int i = 0; i < n; i++)
    {
        v[i] = rand() % 10000; // gera um valor aleatório de 0 a 9999
    }
}

void *funcao_thread(void *arg)
{
    cord *task = (cord *)arg;

    task->result = 0;
    for (int i = task->from; i < task->to; i++)
    {
        task->result += task->vector[i];
    }
    pthread_exit(NULL);
}

int juncao(int *vet, size_t tam_vet)
{
    pthread_t *threads = malloc(NTHREADS * sizeof(*threads));
    cord *result_tarefa = malloc(NTHREADS * sizeof(*result_tarefa));

    int start = 0;
    int step = tam_vet / NTHREADS;

    for (size_t i = 0; i < NTHREADS; i++)
    {
        result_tarefa[i].vector = vet;
        result_tarefa[i].from = start;
        result_tarefa[i].to = start + step;
        start += step;
    }

    for (size_t i = 0; i < NTHREADS; i++)
    {
        pthread_create(threads + i, NULL, funcao_thread, result_tarefa + i);
    }

    int total = 0;

    for (size_t i = 0; i < NTHREADS; i++)
    {
        pthread_join(threads[i], NULL);
        total += result_tarefa[i].result;
    }

    free(result_tarefa);
    free(threads);
    return total;
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "Portuguese");

    srand(time(NULL));

    int tam_vet = 0;
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

    int resultado = juncao(vet, tam_vet);

    printf("Soma total: %d\n", resultado);

    free(vet);

    return 0;
}
