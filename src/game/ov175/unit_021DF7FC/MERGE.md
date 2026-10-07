# unit_021DF7FC.c (ov175)

Translation unit 021DF7FC..021DF9D8, 6 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021DF7FC.c` is blocked by:

- ov175_func_021DF7FC.c..ov175_func_021DF968.c: settings differ: src/matched/ov_sdk/ov175_func_021DF884.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': '', 'is
- ov175_func_021DF7FC.c..ov175_func_021DF8D4.c: settings differ: src/matched/ov_sdk/ov175_func_021DF884.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': '', 'is

Members, in address order:

- `ov175_func_021DF7FC.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021DF7FC.c` again.
