# unit_02703CDC.c (twl)

Translation unit 02703CDC..027040B4, 5 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_02703CDC.c` is blocked by:

- func_02703CDC.c..func_02704088.c: settings differ: src/matched/twl_sdk/func_02704088.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c', 'isa': 
- func_02703F04.c..func_02704088.c: settings differ: src/matched/twl_sdk/func_02704088.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c', 'isa': 
- func_02703F7C.c..func_02704088.c: settings differ: src/matched/twl_sdk/func_02704088.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c', 'isa': 

Members, in address order:

- `func_02703F04.c`
- `func_02703F7C.c`
- `func_02704088.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_02703CDC.c` again.
