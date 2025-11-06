#include <stdio.h>
#include <stdlib.h>

int main() {
  // ==== printf ====
  // Příkaz pro vypisování do konzole.
  // Nepřidává automaticky znak nového řádku,
  // proto je potřeba přidat "\n" ručně.
  // Nachází se v knihovně stdio.h (#include <stdio.h>).
  printf("Hello, World!\n");
  // Přijímá argumenty pro formátované vypisování:
  // %d - decimal
  // %f - float
  // %s - string/char array
  // %c - char
  // %p - pointer address
  // a další - https://cplusplus.com/reference/cstdio/printf/
  int d = 10;
  float f = 12.55;
  printf("%d, %f\n", d, f);

  // ==== pointery ====
  // Ukazatele: proměnné, které obsahují adresu buňky paměti,
  // kde leží nějaká hodnota.

  // Úplný základ: proměnná a ukazatel na ni
  int x = 10;  // obyčejná proměnná
  int *p = &x; // p = adresa, kde x leží

  printf("x = %d\n", x);
  printf("adresa x (&x) = %p\n", (void *)&x);
  printf("hodnota ukazatele p (kam ukazuje) = %p\n", (void *)p);
  printf("hodnota na adrese p (tam kam p ukazuje) (*p) = %d\n\n", *p);

  // Změna hodnoty přes ukazatel (dereference)
  *p = 25; // zapíšeme 25 na adresu, kam p ukazuje -> změní x
  printf("po *p = 25: x = %d, *p = %d\n\n", x, *p);

  // Pole a ukazatel (pole se chová jako adresa prvního prvku)
  int arr[] = {1, 2, 3}; // vytvoří automaticky pole o velikosti 3 (3 prvky)
                         // ekvivalent
                         // int arr[3] = {1, 2, 3};

  int *pa = arr; // stejné jako: int *pa = &arr[0];

  printf("arr[0] přes *pa: %d\n", *pa);           // 1
  printf("arr[1] přes *(pa+1): %d\n", *(pa + 1)); // 2
  printf("arr[2] přes *(pa+2): %d\n", *(pa + 2)); // 3

  // Změna prvku pole přes ukazatel
  *(pa + 1) = 20; // změní arr[1] z 2 na 20
  printf("po *(pa+1) = 20: arr[1] = %d\n", arr[1]);

  // Tipy k zapamatování:
  // - p ukazuje na ADRESU. *p je HODNOTA na adrese p.
  // - &x znamená "vezmi adresu x".
  // - (pa + 1) skočí na další int v poli (ne o 1 byte, ale o velikost int).

  // Zajímavost:
  // při přistupování k poli (arr je adresa prvního prvku)
  // se výraz arr[1] překládá jako *(arr + 1), proto
  printf("arr[1] = %d\n", arr[1]);
  // je stejné jako
  printf("1[arr] = %d\n", 1 [arr]); // -> *(1 + arr)

  // ===== malloc =====
  // malloc = "memory allocate" – požádá operační systém o kus paměti
  // používá se, když nevíme dopředu, kolik paměti budeme potřebovat
  // nachází se v knihovně stdlib.h (#include <stdlib.h>)

  // Příklad: chceme pole 5 čísel, ale nevíme velikost dopředu
  int n = 5;
  int *dynArr = malloc(n * sizeof(int)); // alokuje paměť pro n intů

  // Kontrolujeme, jestli se alokace povedla
  if (dynArr == NULL) {
    printf("Chyba: nepodařilo se alokovat paměť!\n"); // k tomu může dojít
                                                      // například kdybychom již
                                                      // všechnu paměť systému
                                                      // používali
    return 1;
  }

  // Použití dynamicky alokovaného pole
  for (int i = 0; i < n; i++) {
    dynArr[i] = (i + 1) * 10; 
  }

  printf("Dynamicky alokované pole:\n");
  for (int i = 0; i < n; i++) {
    printf("dynArr[%d] = %d\n", i, dynArr[i]);
  }

  // Až paměť nepotřebujeme, musíme ji uvolnit, říct operačnímu systému, že
  // ji již nepotřebujeme
  free(dynArr); // jinak by "zůstala viset" v paměti (memory leak)

  // Po free už na tu paměť nesmíme sahat
  dynArr = NULL; // obrana proti náhodnému použití

  return 0;
}
