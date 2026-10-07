# unit_0270379C.c (twl)

Translation unit 0270379C..02703960, 3 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_0270379C.c` is blocked by:

- func_0270379C.c..func_027038BC.c: settings differ: src/matched/twl_sdk/func_02703854.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c', 'isa': 
- func_02703854.c..func_027038BC.c: settings differ: src/matched/twl_sdk/func_027038BC.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 

Members, in address order:

- `func_0270379C.c`
- `func_02703854.c`
- `func_027038BC.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_0270379C.c` again.
