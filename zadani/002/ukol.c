int main() {
  /*
  1: printf a formátování
  Zadání:
  - Použijte proměnné name a hourlySalary.
  - Vypište větu ve tvaru: "Tomáš vydělává 192.60 Kč za hodinu." (2 desetinná
  místa).
  */
  char name[] = "Jonáš";
  float hourlySalary = 192.6f;

  /*
  2: Načítání vstupu pomocí scanf
  Zadání:
  - Načtěte od uživatele věk (int) a výšku v metrech (float).
  - Výsledek vypište a formátujte, zkombinujte a jménem z předchozí části.
  */

  /*
  3: Ukazatele – základní práce s adresou
  Zadání:
  - Použijte proměnnou x.
  - Vytvořte ukazatel px na proměnnou x a vypište x, adresu x, hodnotu ukazatele a hodnotu na
  adrese.
  - Změňte hodnotu přes ukazatel (na 25) a znovu vypište.
  */
  int x = 10;

  /*
  4: Pole a ukazatele
  Zadání:
  - Použijte pole arr.
  - Vypište prvky dvěma různými způsoby ([] a *).
  - Změňte prostřední prvek přes ukazatel na 20 a ověřte výpisem.
  */
  int arr[] = {1, 2, 3, 8, 13, 6, 6};

  /*
  5: Dynamická paměť – malloc/free + náhodná čísla
  Zadání:
  - Načtěte od uživatele kladné n (velikost pole intů).
  - Dynamicky alokujte pole, zkontrolujte úspěch alokace.
  - Naplňte náhodnými čísly v rozsahu 0–2893, vypište.
  - Uvolněte paměť.
  */

  /*
  6: Funkce pracující s polem
  Zadání (implementujte dané funkce):
  - int sum(int *a, int n) – součet prvků.
  - int max(int *a, int n) – maximum.
  - void printArr(int *a, int n) – pěkný výpis pole.

  Definujte si vlastní pole a fce otestujte.
  */

  /*
  7: Řetězce
  Zadání:
  - Načtěte od uživatele dva řetězce bez mezer do dvou char polí.
  - Porovnejte je a vypište, zda jsou stejná, nebo které je abecedně dřív.
  - Ošetřete rozumně maximální délku vstupu.
  */

  return 0;
}
