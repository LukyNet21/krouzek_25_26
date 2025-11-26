#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int sum(int *a, int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
  }
  return sum;
}

int max(int *a, int n) {
  int max = INT_MIN;
  for (int i = 0; i < n; i++) {
    if (a[i] > max)
      max = a[i];
  }
  return max;
}

void printArr(int *a, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

int main(void) {
  /*
  1: printf a formátování
  Zadání:
  - Použijte proměnné name a hourlySalary.
  - Vypište větu ve tvaru: "Tomáš vydělává 19.60 Kč za hodinu." (2 desetinná
  místa).
  */
  char name[] = "Jonáš";
  float hourlySalary = 192.6f;

  printf("%s vydělává %.2f Kč za hodinu.\n\n", name, hourlySalary);

  /*
  2: Načítání vstupu pomocí scanf
  Zadání:
  - Načtěte od uživatele věk (int) a výšku v metrech (float).
  - Výsledek vypište a formátujte, zkombinujte a jménem z předchozí části.
  */

  int age;
  float height;

  scanf("%d %f", &age, &height);

  printf("%s má %d let a měří %.2f metrů. \n\n", name, age, height);

  /*
  3: Ukazatele – základní práce s adresou
  Zadání:
  - Použijte proměnnou x.
  - Vytvořte ukazatel px na proměnnou x a vypište x, adresu x, hodnotu ukazatele
  a hodnotu na adrese.
  - Změňte hodnotu přes ukazatel (na 25) a znovu vypište.
  */
  int x = 10;
  int *px = &x;
  printf("Před úpravou: \nx = %d \n&x = %p \npx = %p \n*px = %d\n\n", x,
         (void *)&x, (void *)px, *px);

  *px = 25;

  printf("Po úpravě: \nx = %d \n&x = %p\npx = %p\n*px = %d\n\n", x, (void *)&x,
         (void *)px, *px);

  /*
  4: Pole a ukazatele
  Zadání:
  - Použijte pole arr.
  - Vypište prvky dvěma různými způsoby ([] a *).
  - Změňte prostřední prvek přes ukazatel na 20 a ověřte výpisem.
  */
  int arr[] = {1, 2, 3, 8, 13, 6, 12};
  int size = sizeof(arr) / sizeof(int);

  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  for (int i = 0; i < size; i++) {
    printf("%d ", *(arr + i));
  }
  printf("\n");

  // změna
  *(arr + 3) = 20;

  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  for (int i = 0; i < size; i++) {
    printf("%d ", *(arr + i));
  }
  printf("\n\n");

  /*
  5: Dynamická paměť – malloc/free + náhodná čísla
  Zadání:
  - Načtěte od uživatele kladné n (velikost pole intů).
  - Dynamicky alokujte pole, zkontrolujte úspěch alokace.
  - Naplňte náhodnými čísly v rozsahu 0–2893, vypište.
  - Uvolněte paměť.
  */

  int n;
  scanf("%d", &n);

  if (n <= 0) {
    printf("n musí být > 0\n");
    return 1;
  }

  int *dyn_arr = malloc(n * sizeof(int));
  if (!dyn_arr) {
    printf("malloc failed");
    return 1;
  }

  srand(time(NULL));
  for (int i = 0; i < n; i++) {
    dyn_arr[i] = rand() % 2894;
  }

  for (int i = 0; i < n; i++) {
    printf("%d ", dyn_arr[i]);
  }
  printf("\n\n");

  free(dyn_arr);
  dyn_arr = NULL;

  /*
  6: Funkce pracující s polem
  Zadání (implementujte dané funkce):
  - int sum(int *a, int n) – součet prvků.
  - int max(int *a, int n) – maximum.
  - void printArr(int *a, int n) – pěkný výpis pole.

  Definujte si vlastní pole a fce otestujte.
  */

  int demo[] = {5, 2, 9, -3, 7};
  int dn = sizeof(demo) / sizeof(int);
  printf("demo pole: ");
  printArr(demo, dn);
  printf("sum(demo) = %d\n", sum(demo, dn));
  printf("max(demo) = %d\n\n", max(demo, dn));

  /*
  7: Řetězce
  Zadání:
  - Načtěte od uživatele dva řetězce bez mezer do dvou char polí.
  - Porovnejte je a vypište, zda jsou stejná, nebo které je abecedně dřív.
  - Ošetřete rozumně maximální délku vstupu.
  */

  char a[100];
  char b[100];
  if (scanf("%99s %99s", &a, &b) == 2) {
    int cmp = strcmp(a, b);
    if (cmp == 0) {
      printf("Řetězce jsou stejné.\n");
    } else if (cmp < 0) {
      printf("'%s' je abecedně dříve než '%s'.\n", a, b);
    } else {
      printf("'%s' je abecedně dříve než '%s'.\n", b, a);
    }
  }

  return 0;
}
