# unit_01FF82A8.c (arm9_autoload0_ITCM)

Translation unit 01FF82A8..01FF87D4, 7 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_01FF82A8.c` is blocked by:

- func_01FF82A8.c..func_01FF8700.c: settings differ: src/matched/itcm_sdk/func_01FF836C.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa
- func_01FF82A8.c..func_01FF8414.c: settings differ: src/matched/itcm_sdk/func_01FF836C.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa

Members, in address order:

- `func_01FF82A8.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_01FF82A8.c` again.
