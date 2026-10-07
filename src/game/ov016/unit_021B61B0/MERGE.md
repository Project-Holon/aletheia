# unit_021B61B0.c (ov016)

Translation unit 021B61B0..021B6D74, 7 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021B61B0.c` is blocked by:

- func_021B61B0.c..ov016_func_021B6D1C.c: settings differ: src/matched/ov_sdk/ov016_func_021B61D0.c has {'compiler': '../2.0/sp1p2', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang'
- func_021B61B0.c..ov016_func_021B61D0.c: settings differ: src/matched/ov_sdk/ov016_func_021B61D0.c has {'compiler': '../2.0/sp1p2', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang'
- func_021B61C0.c..ov016_func_021B61D0.c: settings differ: src/matched/ov_sdk/ov016_func_021B61D0.c has {'compiler': '../2.0/sp1p2', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang'
- ov016_func_021B62C0.c..ov016_func_021B6D1C.c: global aoss_bss declared two ways (src/matched/ov_sdk/ov016_func_021B6CF0.c); global aoss_bss declared two ways (src/matched/ov_sdk/ov016_func_021B6D1C.c)
- ov016_func_021B6CF0.c..ov016_func_021B6D1C.c: global aoss_bss declared two ways (src/matched/ov_sdk/ov016_func_021B6D1C.c)

Members, in address order:

- `func_021B61B0.c`
- `func_021B61C0.c`
- `ov016_func_021B61D0.c`
- `ov016_func_021B6CF0.c`
- `ov016_func_021B6D1C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021B61B0.c` again.
