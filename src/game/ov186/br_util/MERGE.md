# br_util.c (ov186)

Translation unit 021FC6A4..021FEEF4, 84 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`br_util.c` is blocked by:

- ov186_func_021FC6A4.c..ov186_func_021FEEC0.c: prototype of func_02034714 differs between members (src/matched/ov/ov186_func_021FCDAC.c); global d_02200D68 declared two ways (src/matched/ov/ov186_func_021FCDAC.c); prototype of func_02034714 differ
- ov186_func_021FC6A4.c..ov186_func_021FD938.c: prototype of func_02034714 differs between members (src/matched/ov/ov186_func_021FCDAC.c); global d_02200D68 declared two ways (src/matched/ov/ov186_func_021FCDAC.c); prototype of func_02034714 differ
- ov186_func_021FC6A4.c..ov186_func_021FD0B8.c: prototype of func_02034714 differs between members (src/matched/ov/ov186_func_021FCDAC.c); global d_02200D68 declared two ways (src/matched/ov/ov186_func_021FCDAC.c); prototype of func_02034714 differ
- ov186_func_021FC6A4.c..ov186_func_021FCD0C.c: c99=CCERR: line 136: identifier 'func_02082BCC(void *, int, int)' redeclared as 'void (void *, int, unsigned int)' | line 115: identifier 'func_02082BCC(void *, int, int)' was originally declared as '
- ov186_func_021FC868.c..ov186_func_021FCD0C.c: c99=CCERR: line 119: identifier 'func_021FD860(char *, unsigned int, const struct  *)' redeclared as 'void (int, int, void *)' | line 108: identifier 'func_021FD860(char *, unsigned int, const struct 
- ov186_func_021FC8C8.c..ov186_func_021FCD0C.c: c99=CCERR: line 109: identifier 'func_021FD860(char *, unsigned int, const struct  *)' redeclared as 'void (int, int, void *)' | line 98: identifier 'func_021FD860(char *, unsigned int, const struct  
- ov186_func_021FCDA0.c..ov186_func_021FD0B8.c: prototype of func_021FD860 differs between members (src/matched/ov/ov186_func_021FD0B8.c)
- ov186_func_021FCE60.c..ov186_func_021FD0B8.c: prototype of func_021FD860 differs between members (src/matched/ov/ov186_func_021FD0B8.c)
- ov186_func_021FCF90.c..ov186_func_021FD0B8.c: prototype of func_021FD860 differs between members (src/matched/ov/ov186_func_021FD0B8.c)
- ov186_func_021FCFE0.c..ov186_func_021FD0B8.c: prototype of func_021FD860 differs between members (src/matched/ov/ov186_func_021FD0B8.c)
- ov186_func_021FD110.c..ov186_func_021FD938.c: prototype of func_02082BCC differs between members (src/matched/ov/ov186_func_021FD6D8.c); prototype of func_0204B294 differs between members (src/matched/ov/ov186_func_021FD760.c)
- ov186_func_021FD940.c..ov186_func_021FEEC0.c: prototype of func_0204B404 differs between members (src/matched/ov/ov186_func_021FDA7C.c); prototype of func_0204B404 differs between members (src/matched/ov/ov186_func_021FDBF4.c); prototype of func_
- ov186_func_021FD940.c..ov186_func_021FE784.c: prototype of func_0204B404 differs between members (src/matched/ov/ov186_func_021FDA7C.c); prototype of func_0204B404 differs between members (src/matched/ov/ov186_func_021FDBF4.c); prototype of func_
- ov186_func_021FD940.c..ov186_func_021FE2BC.c: prototype of func_0204B404 differs between members (src/matched/ov/ov186_func_021FDA7C.c); prototype of func_021FE4D8 differs between members (src/matched/ov/ov186_func_021FDBF4.c); prototype of func_
- ov186_func_021FD940.c..ov186_func_021FDBF4.c: prototype of func_0204B404 differs between members (src/matched/ov/ov186_func_021FDBF4.c)
- ov186_func_021FD9A0.c..ov186_func_021FDBF4.c: prototype of func_0204B404 differs between members (src/matched/ov/ov186_func_021FDBF4.c)
- ov186_func_021FDA7C.c..ov186_func_021FDBF4.c: prototype of func_0204B404 differs between members (src/matched/ov/ov186_func_021FDBF4.c)
- ov186_func_021FDE88.c..ov186_func_021FE2BC.c: prototype of func_021FE3B4 differs between members (src/matched/ov/ov186_func_021FDF40.c); prototype of func_0204B404 differs between members (src/matched/ov/ov186_func_021FDF40.c); prototype of func_
- ov186_func_021FDFF4.c..ov186_func_021FE2BC.c: prototype of func_0204B404 differs between members (src/matched/ov/ov186_func_021FE1C4.c)

Members, in address order:

- `ov186_func_021FC8C8.c`
- `ov186_func_021FCF90.c`
- `ov186_func_021FCFE0.c`
- `ov186_func_021FD0B8.c`
- `ov186_func_021FD9A0.c`
- `ov186_func_021FDA7C.c`
- `ov186_func_021FDBF4.c`
- `ov186_func_021FDFF4.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names br_util.c` again.
