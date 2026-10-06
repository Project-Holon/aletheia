# unit_02072F34.c (arm9)

Translation unit 02072F34..020730B8, 12 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_02072F34.c` is blocked by:

- unit_02072F34.c..unit_02072F88.c: type struct Obj differs between members (src/matched/arm9/unit_02072F88.c)

Members, in address order:

- `unit_02072F34.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_02072F34.c` again.
