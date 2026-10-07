# unit_02702080.c (twl)

Translation unit 02702080..02702434, 15 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_02702080.c` is blocked by:

- func_02702080.c..func_0270234C.c: settings differ: src/matched/twl_sdk/func_0270234C.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 
- func_027021E4.c..func_0270234C.c: settings differ: src/matched/twl_sdk/func_0270234C.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 
- func_0270229C.c..func_0270234C.c: settings differ: src/matched/twl_sdk/func_0270234C.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 
- func_027022F8.c..func_0270234C.c: settings differ: src/matched/twl_sdk/func_0270234C.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 

Members, in address order:

- `func_027022F8.c`
- `func_0270234C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_02702080.c` again.
