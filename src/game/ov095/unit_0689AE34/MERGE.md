# unit_0689AE34.c (ov095)

Translation unit 0689AE34..0689B008, 9 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_0689AE34.c` is blocked by:

- ov095_func_0689AE34.c..ov095_func_0689AF90.c: settings differ: src/matched/ov/ov095_func_0689AF90.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': '', 'isa': 
- no verified entry for 0689AF98, 0689AFA8, 0689AFB8, 0689AFC8, 0689AFD8, 0689AFE8, 0689AFF8

Members, in address order:

- `ov095_func_0689AE34.c`
- `ov095_func_0689AF90.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_0689AE34.c` again.
