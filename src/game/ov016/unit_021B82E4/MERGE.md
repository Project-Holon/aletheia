# unit_021B82E4.c (ov016)

Translation unit 021B82E4..021B83E8, 6 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021B82E4.c` is blocked by:

- ov016_func_021B82E4.c..ov016_func_021B8378.c: settings differ: src/matched/ov_sdk/func_021B8364.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '../2.0/sp1p2', 'flags': '-O4,p', 'lang': 'c99
- ov016_func_021B834C.c..ov016_func_021B8378.c: settings differ: src/matched/ov_sdk/func_021B8364.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '../2.0/sp1p2', 'flags': '-O4,p', 'lang': 'c99
- func_021B8364.c..ov016_func_021B8378.c: settings differ: src/matched/ov_sdk/ov016_func_021B8378.c has {'compiler': '../2.0/sp1p2', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang'

Members, in address order:

- `ov016_func_021B834C.c`
- `func_021B8364.c`
- `ov016_func_021B8378.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021B82E4.c` again.
