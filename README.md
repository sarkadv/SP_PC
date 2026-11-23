# Identifikace spamu naivním bayesovským klasifikátorem

Konzolová aplikace v ANSI C, která rozhoduje, zda je textový soubor spam (nevyžádaná zpráva), nebo ham
(neškodná zpráva). Program se nejdříve naučí rozpoznávat spam na trénovacích souborech a poté klasifikuje
testovací soubory pomocí naivního bayesovského klasifikátoru. Semestrální práce z předmětu KIV/PC.

Zadání je v souboru `zadani.pdf`.

## Jak to funguje

1. **Fáze učení.** Slova ze spamových a hamových trénovacích souborů se načtou do dvou hash tabulek, které se
   poté spojí do jednoho slovníku. Pro každé slovo ve slovníku se vypočítá pravděpodobnost jeho výskytu ve spamu
   a v hamu:
   `(četnost slova + 1) / (celkový počet slov ve třídě + velikost slovníku)`.
2. **Fáze klasifikace.** Z testovacího souboru se vyberou slova, která jsou ve slovníku. Sečtou se dekadické
   logaritmy jejich pravděpodobností pro spam a pro ham (logaritmy místo násobení, protože pravděpodobnosti
   jsou velmi malé). Větší součet určí výslednou třídu.

Slovník je uložen v hash tabulce, kde se kolize řeší spojovým seznamem.

## Překlad

```
make
```

Vytvoří se spustitelný soubor `spamid.exe`.

## Použití

```
spamid.exe <spam> <spam-cnt> <ham> <ham-cnt> <test> <test-cnt> <out-file>
```

Parametry `<spam>`, `<ham>` a `<test>` jsou vzory jmen souborů, `<spam-cnt>`, `<ham-cnt>` a `<test-cnt>` jejich
počty. Soubory se načítají z podadresáře `data` vedle spustitelného souboru a jmenují se `<vzor><číslo>.txt`,
číslováno od 1. Například:

```
spamid.exe spam 10 ham 20 test 50 result.txt
```

načte soubory `data/spam1.txt` … `data/spam10.txt`, `data/ham1.txt` … `data/ham20.txt` a `data/test1.txt` …
`data/test50.txt`.

Každý vstupní soubor obsahuje jeden řádek slov oddělených mezerou (pouze písmena anglické abecedy v ASCII).

Výstupní soubor obsahuje na každém řádku jméno testovaného souboru, tabulátor a klasifikaci: `S` (spam) nebo
`H` (ham). Soubory, které se nepodařilo klasifikovat, jsou označeny `x`.

```
test1.txt	H
test2.txt	H
test3.txt	S
```

Zadání vyžadovalo přesnost klasifikace alespoň 90 %.
