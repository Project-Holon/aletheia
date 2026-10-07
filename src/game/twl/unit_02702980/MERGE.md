# unit_02702980.c (twl)

Translation unit 02702980..02702A78, 3 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_02702980.c` is blocked by:

- func_02702980.c..func_02702A40.c: settings differ: src/matched/twl_sdk/func_02702998.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 
- func_02702998.c..func_02702A40.c: settings differ: src/matched/twl_sdk/func_02702A40.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c', 'isa': 

Members, in address order:

- `func_02702980.c`
- `func_02702998.c`
- `func_02702A40.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_02702980.c` again.
