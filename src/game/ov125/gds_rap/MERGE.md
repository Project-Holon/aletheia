# gds_rap.c (ov125)

Translation unit 021D6660..021D7CC0, 50 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`gds_rap.c` is blocked by:

- ov125_func_021D6660.c..ov125_func_021D7CAC.c: settings differ: src/matched/ov/ov125_func_021D770C.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': '', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 
- ov125_func_021D6660.c..ov125_func_021D73B8.c: global d_021D8D28 declared two ways (src/matched/ov/ov125_func_021D68EC.c); global d_021D8D28 declared two ways (src/matched/ov/ov125_func_021D6B40.c); prototype of func_02082D44 differs between membe
- ov125_func_021D73E0.c..ov125_func_021D7CAC.c: settings differ: src/matched/ov/ov125_func_021D770C.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': '', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 
- ov125_func_021D770C.c..ov125_func_021D7CAC.c: global d_021D9E40 declared two ways (src/matched/ov/ov125_func_021D7770.c)
- ov125_func_021D770C.c..ov125_func_021D7BCC.c: global d_021D9E40 declared two ways (src/matched/ov/ov125_func_021D7770.c)
- ov125_func_021D770C.c..ov125_func_021D7808.c: global d_021D9E40 declared two ways (src/matched/ov/ov125_func_021D7770.c)

Members, in address order:

- `ov125_func_021D770C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names gds_rap.c` again.
