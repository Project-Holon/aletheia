# unit_02703088.c (twl)

Translation unit 02703088..027032E0, 3 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_02703088.c` is blocked by:

- func_02703088.c..func_02703250.c: settings differ: src/matched/twl_sdk/func_02703208.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c', 'isa': 
- func_02703208.c..func_02703250.c: settings differ: src/matched/twl_sdk/func_02703250.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 

Members, in address order:

- `func_02703088.c`
- `func_02703208.c`
- `func_02703250.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_02703088.c` again.
