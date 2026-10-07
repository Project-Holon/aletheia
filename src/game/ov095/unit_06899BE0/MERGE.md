# unit_06899BE0.c (ov095)

Translation unit 06899BE0..06899CDC, 9 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_06899BE0.c` is blocked by:

- ov095_func_06899BE0.c..ov095_func_06899CA4.c: settings differ: src/matched/ov/ov095_func_06899C9C.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa
- ov095_func_06899C9C.c..ov095_func_06899CA4.c: settings differ: src/matched/ov/ov095_func_06899CA4.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'i
- no verified entry for 06899C4C, 06899C5C, 06899C6C, 06899C7C, 06899C8C, 06899CCC

Members, in address order:

- `ov095_func_06899BE0.c`
- `ov095_func_06899C9C.c`
- `ov095_func_06899CA4.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_06899BE0.c` again.
