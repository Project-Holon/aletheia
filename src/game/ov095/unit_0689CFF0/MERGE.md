# unit_0689CFF0.c (ov095)

Translation unit 0689CFF0..0689D0FC, 3 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_0689CFF0.c` is blocked by:

- ov095_func_0689CFF0.c..ov095_func_0689D01C.c: settings differ: src/matched/ov/ov095_func_0689D014.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': '', 'isa': 
- ov095_func_0689D014.c..ov095_func_0689D01C.c: settings differ: src/matched/ov/ov095_func_0689D01C.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': '', 'isa': 'thumb'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa'

Members, in address order:

- `ov095_func_0689CFF0.c`
- `ov095_func_0689D014.c`
- `ov095_func_0689D01C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_0689CFF0.c` again.
