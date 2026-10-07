# unit_027036A0.c (twl)

Translation unit 027036A0..0270379C, 2 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_027036A0.c` is blocked by:

- func_027036A0.c..func_02703764.c: settings differ: src/matched/twl_sdk/func_02703764.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c', 'isa': 

Members, in address order:

- `func_027036A0.c`
- `func_02703764.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_027036A0.c` again.
