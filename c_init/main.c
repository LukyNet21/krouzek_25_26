#include "pthread.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>

void *clogUpCore(void *arg) {
  int i = 0;
  for (;;) {
    i++;
  }
}
int main() {
  int thread_count = 16;
  for (int i = 0; i < thread_count; i++) {
    pthread_t *thread = malloc(sizeof(pthread_t));
    pthread_create(thread, NULL, clogUpCore, NULL);
  }
  for (;;) {
  }
  return 0;
}
