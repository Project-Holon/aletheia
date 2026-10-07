# unit_021B824C.c (ov016)

Translation unit 021B824C..021B82C4, 3 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021B824C.c` is blocked by:

- ov016_func_021B824C.c..func_021B82B4.c: settings differ: src/matched/ov_sdk/ov016_func_021B8260.c has {'compiler': '../2.0/sp1p2', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang'
- ov016_func_021B8260.c..func_021B82B4.c: settings differ: src/matched/ov_sdk/func_021B82B4.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '../2.0/sp1p2', 'flags': '-O4,p', 'lang': 'c99

Members, in address order:

- `ov016_func_021B824C.c`
- `ov016_func_021B8260.c`
- `func_021B82B4.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021B824C.c` again.
