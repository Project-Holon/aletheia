# unit_027026DC.c (twl)

Translation unit 027026DC..027028E8, 5 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_027026DC.c` is blocked by:

- func_027026DC.c..func_027028E4.c: settings differ: src/matched/twl_sdk/func_02702740.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 
- func_02702740.c..func_027028E4.c: settings differ: src/matched/twl_sdk/func_027028B0.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c', 'isa': 

Members, in address order:

- `func_02702740.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_027026DC.c` again.
