#include "malloc.h"
#include "stdio.h"
#include "string.h"

void FormatAndPrint(char *string) {
  printf("Hezky zformatovany string %s", string);
  return;
}

struct nasStruct {
  int cislo;
  char *string;
  // void nastavCislo(int cil) {
  //  this.cislo = cil;
  // }
};

void Format(int *string) {
  *string = 5;
  return;
}

void Format2(int string) {
  string = 2;
  return;
}

void nastavCisloStruct(struct nasStruct nasstruct, int cil) {
  if (nasstruct.cislo == 5) {
    printf("Cislo je 5\n");
    nasstruct.cislo = cil;
  }
}
int main() {
  int *cislo = malloc(sizeof(int));
  *cislo = 8;

  struct nasStruct str = {5, (char *)cislo};

  nastavCisloStruct(str, 6);
  printf("A teď je %d\n", str.cislo);
  printf("%d\n", *cislo);
  Format(cislo);
  printf("%d\n", *cislo);
  Format2(*cislo);
  printf("%d\n", *cislo);

  char *od_uzivatele = malloc(1000);
  int err = scanf("%s %d\n", od_uzivatele, cislo);

  printf("%s\n", od_uzivatele);

  free(od_uzivatele);

  free(cislo);
  return 0;
}
