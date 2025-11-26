#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 2000000

struct args {
  int data[ARRAY_SIZE];
  int *value;
  int size;
};

pthread_mutex_t lock;
void *oddCount(void *arg) {
  struct args *thread_data = (struct args *)arg;

  int odd_counter = 0;

  for (int i = 0; i < thread_data->size; i++) {
    if (thread_data->data[i] % 2 != 0) {
      odd_counter++;
      pthread_mutex_lock(&lock);
      if (*thread_data->value == 5) {
        *thread_data->value = 6;
        pthread_mutex_unlock(&lock);
        continue;
      }
      if (*thread_data->value == 6) {
        odd_counter += 500000;
        *thread_data->value = 5;
        pthread_mutex_unlock(&lock);
        continue;
      }
    }
  }

  int *result = malloc(sizeof(int));
  if (result == NULL) {
    pthread_exit(NULL);
  }
  *result = odd_counter;

  pthread_exit(result);
}

int main() {
  pthread_t thread1;
  struct args data;
  int *odd_count_ptr = NULL;
  int *value = malloc(sizeof(int));
  *value = 5;
  
  data.value = value;

  data.size = ARRAY_SIZE/2;

  srand(time(NULL));
  for (int i = 0; i < ARRAY_SIZE; i++) {
    data.data[i] = rand();
  }

  pthread_create(&thread1, NULL, oddCount, &data);

  int odd_counter = 0;
  
  for (int i = ARRAY_SIZE/2; i < ARRAY_SIZE; i++) {
    if (data.data[i] % 2 != 0) {
      odd_counter++;
      pthread_mutex_lock(&lock);
      if (*value == 5) {
        *value = 6;
        pthread_mutex_unlock(&lock);
        continue;
      }
      if (*value == 6) {
        odd_counter -= 500000;
        *value = 5;
        pthread_mutex_unlock(&lock);
        continue;
      }
    }
  }
  
  pthread_join(thread1, (void **)&odd_count_ptr);
  printf("Done, there were %d odd numbers generated\n", *odd_count_ptr + odd_counter);

  if (odd_count_ptr != NULL) {
    free(odd_count_ptr);
  }
  free(value);

  return 0;
}
