# Úvod do C

Souhrný ukázkový program v C z hodiny.

## Jak spustit

1) Zkompilujte (Linux, GCC):

```sh
gcc main.c -o main
```

Nebo (Windows, MinGW):

```sh
gcc main.c -o main.exe
```

2) Spusťte binárku:

```sh
./main
```
Nebo (Windows):

```sh
main.exe
```

> Tip: `-o` specifikuje výstupní soubor.

## Úkoly k vyzkoušení

- Změňte hodnoty proměnných a sledujte, co se vypisuje.
- Přidejte do pole `arr` další prvek a vypište ho přes pointer `pa`.
- Změňte `n` u dynamického pole a zkuste vyplnit jinými hodnotami.
- Zkuste po `free` nastavit pointer na `NULL` a vyzkoušet si, že na paměť po `free` už nedosáhneme.

## Časté chyby a tipy

- Nikdy nečtěte ani nezapisujte na paměť po `free`.
- `arr[i]` je totéž co `*(arr + i)`, ale používejte spíše přehlednější `arr[i]`.

