# unit_027040B4.c (twl)

Translation unit 027040B4..02704258, 5 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_027040B4.c` is blocked by:

- func_027040B4.c..func_02704230.c: settings differ: src/matched/twl_sdk/func_027041E8.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 
- func_0270410C.c..func_02704230.c: settings differ: src/matched/twl_sdk/func_027041E8.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 

Members, in address order:

- `func_0270410C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_027040B4.c` again.
