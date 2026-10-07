# unit_06899DD8.c (ov095)

Translation unit 06899DD8..0689A45C, 24 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_06899DD8.c` is blocked by:

- ov095_func_06899DD8.c..ov095_func_0689A3E4.c: settings differ: src/matched/ov/ov095_func_06899E0C.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': '', 'isa': 
- ov095_func_06899DD8.c..ov095_func_06899E68.c: settings differ: src/matched/ov/ov095_func_06899E0C.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': '', 'isa': 
- ov095_func_06899DD8.c..ov095_func_06899E24.c: settings differ: src/matched/ov/ov095_func_06899E0C.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': '', 'isa': 
- ov095_func_06899E0C.c..ov095_func_06899E24.c: c99=DIFF nolang=DIFF
- ov095_func_06899ED0.c..ov095_func_0689A3E4.c: settings differ: src/matched/ov/ov095_func_0689A3E4.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa
- ov095_func_06899FD4.c..ov095_func_0689A3E4.c: settings differ: src/matched/ov/ov095_func_0689A3E4.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa
- ov095_func_0689A030.c..ov095_func_0689A3E4.c: settings differ: src/matched/ov/ov095_func_0689A3E4.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa
- no verified entry for 06899DFC, 06899E14, 06899FA4, 06899FB4, 06899FC4, 0689A3EC, 0689A3FC, 0689A40C

Members, in address order:

- `ov095_func_06899DD8.c`
- `ov095_func_06899E0C.c`
- `ov095_func_06899E24.c`
- `ov095_func_06899FD4.c`
- `ov095_func_0689A030.c`
- `ov095_func_0689A3E4.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_06899DD8.c` again.
