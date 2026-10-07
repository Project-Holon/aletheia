# unit_021DFAA8.c (ov175)

Translation unit 021DFAA8..021DFCE8, 5 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021DFAA8.c` is blocked by:

- ov175_func_021DFAA8.c..ov175_func_021DFC8C.c: settings differ: src/matched/ov_sdk/ov175_func_021DFB18.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': '', 'isa': 'thumb'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', '
- ov175_func_021DFB18.c..ov175_func_021DFC8C.c: settings differ: src/matched/ov_sdk/ov175_func_021DFBB8.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': '', 'is

Members, in address order:

- `ov175_func_021DFB18.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021DFAA8.c` again.
