# unit_021B6D8C.c (ov016)

Translation unit 021B6D8C..021B8240, 46 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021B6D8C.c` is blocked by:

- ov016_func_021B6D8C.c..func_021B8230.c: settings differ: src/matched/ov_sdk/func_021B796C.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '../2.0/sp1p2', 'flags': '-O4,p', 'lang': 'c99
- ov016_func_021B6D8C.c..ov016_func_021B7B14.c: settings differ: src/matched/ov_sdk/func_021B796C.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '../2.0/sp1p2', 'flags': '-O4,p', 'lang': 'c99
- ov016_func_021B74B0.c..ov016_func_021B7B14.c: settings differ: src/matched/ov_sdk/func_021B796C.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '../2.0/sp1p2', 'flags': '-O4,p', 'lang': 'c99
- ov016_func_021B782C.c..ov016_func_021B7B14.c: settings differ: src/matched/ov_sdk/func_021B796C.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '../2.0/sp1p2', 'flags': '-O4,p', 'lang': 'c99
- ov016_func_021B782C.c..func_021B796C.c: settings differ: src/matched/ov_sdk/func_021B796C.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '../2.0/sp1p2', 'flags': '-O4,p', 'lang': 'c99
- ov016_func_021B785C.c..func_021B796C.c: settings differ: src/matched/ov_sdk/func_021B796C.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '../2.0/sp1p2', 'flags': '-O4,p', 'lang': 'c99
- ov016_func_021B7BF0.c..func_021B8230.c: settings differ: src/matched/ov_sdk/func_021B816C.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '../2.0/sp1p2', 'flags': '-O4,p', 'lang': 'c99
- ov016_func_021B7FF8.c..func_021B8230.c: settings differ: src/matched/ov_sdk/func_021B816C.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '../2.0/sp1p2', 'flags': '-O4,p', 'lang': 'c99
- func_021B816C.c..func_021B8230.c: settings differ: src/matched/ov_sdk/ov016_func_021B8194.c has {'compiler': '../2.0/sp1p2', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang'
- func_021B816C.c..ov016_func_021B8194.c: settings differ: src/matched/ov_sdk/ov016_func_021B8194.c has {'compiler': '../2.0/sp1p2', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang'
- func_021B8184.c..ov016_func_021B8194.c: settings differ: src/matched/ov_sdk/ov016_func_021B8194.c has {'compiler': '../2.0/sp1p2', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang'
- ov016_func_021B81EC.c..func_021B8230.c: settings differ: src/matched/ov_sdk/func_021B8230.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '../2.0/sp1p2', 'flags': '-O4,p', 'lang': 'c99
- ov016_func_021B8210.c..func_021B8230.c: settings differ: src/matched/ov_sdk/func_021B8230.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '../2.0/sp1p2', 'flags': '-O4,p', 'lang': 'c99

Members, in address order:

- `ov016_func_021B782C.c`
- `ov016_func_021B785C.c`
- `func_021B796C.c`
- `func_021B816C.c`
- `func_021B8184.c`
- `ov016_func_021B8194.c`
- `ov016_func_021B81EC.c`
- `ov016_func_021B8210.c`
- `func_021B8230.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021B6D8C.c` again.
