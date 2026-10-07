# nhttp_rap.c (ov114)

Translation unit 021B95A0..021B9B64, 29 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`nhttp_rap.c` is blocked by:

- ov114_func_021B95A0.c..ov114_func_021B9B58.c: settings differ: src/matched/ov/ov114_func_021B9B4C.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa
- ov114_func_021B95A0.c..ov114_func_021B98D8.c: prototype of func_02082BCC differs between members (src/matched/ov/ov114_func_021B98A0.c)
- ov114_func_021B9790.c..ov114_func_021B98D8.c: c99=CCERR: line 117: illegal implicit conversion from 'unsigned char *' to | line 117: 'struct  *' nolang=CCERR: line 117: illegal implicit conversion from 'unsigned char *' to | line 117: 'struct  *'
- ov114_func_021B9790.c..ov114_func_021B9800.c: c99=ERROR SystemExit('ISA conflict for func_021B9774 at 021B9774: the source declares arm, the image says thumb (the func_021B9774 label in ov114).  Fix the symbols: block (address from name); refusin
- ov114_func_021B9838.c..ov114_func_021B98D8.c: c99=CCERR: line 74: illegal implicit conversion from 'unsigned char *' to | line 74: 'struct  *' nolang=CCERR: line 74: illegal implicit conversion from 'unsigned char *' to | line 74: 'struct  *'
- ov114_func_021B98F8.c..ov114_func_021B9B58.c: settings differ: src/matched/ov/ov114_func_021B9B4C.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa
- ov114_func_021B9A64.c..ov114_func_021B9B58.c: settings differ: src/matched/ov/ov114_func_021B9B4C.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa
- ov114_func_021B9AA8.c..ov114_func_021B9B58.c: settings differ: src/matched/ov/ov114_func_021B9B4C.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa

Members, in address order:

- `ov114_func_021B9790.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names nhttp_rap.c` again.
