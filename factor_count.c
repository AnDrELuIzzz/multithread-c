#include <pthread.h>
#include <inttypes.h>
#include <stdio.h>

int input = 0;

int result1 = 0;
void* fact_worker1(void* arg){
    result1 = 0;
    for (int i = 1; i < input/2; i++)
    {
        if (input % i == 0 )
        {
            result1++;
        }
        
    }
    return NULL;
}

int result2 = 0;

void* fact_worker2 (void* arg){
    result2 = 0;
    for (int i = input/2; i <= input; i++)
    {
        if (input % i == 0)
        {
            result2++;
        }
        
    }
    return NULL;
}

int factors_mp (int num){
    input = num;
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, fact_worker1, NULL);
    pthread_create(&thread2, NULL, fact_worker2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    return result1 + result2;
}

int main(void){
    int input = 2000000000;
    printf("Factors of %d: %d",
    input, factors_mp(input));

    return 0;
}
