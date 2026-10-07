# unit_021889E4.c (ov230)

Translation unit 021889E4..02188E3C, 4 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021889E4.c` is blocked by:

- ov230_func_021889E4.c..ov230_func_02188A48.c: settings differ: src/matched/ov/ov230_func_02188A48.c has {'compiler': '../2.0/sp2', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99',
- ov230_func_02188A0C.c..ov230_func_02188A48.c: settings differ: src/matched/ov/ov230_func_02188A48.c has {'compiler': '../2.0/sp2', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99',
- no verified entry for 02188CB0

Members, in address order:

- `ov230_func_021889E4.c`
- `ov230_func_02188A0C.c`
- `ov230_func_02188A48.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021889E4.c` again.
