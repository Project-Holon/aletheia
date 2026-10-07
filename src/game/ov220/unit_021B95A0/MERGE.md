# unit_021B95A0.c (ov220)

Translation unit 021B95A0..021BA0D8, 13 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021B95A0.c` is blocked by:

- ov220_func_021B95A0.c..ov220_func_021BA068.c: prototype of func_0204AF28 differs between members (src/matched/ov/ov220_func_021B9B64.c); prototype of func_02082BCC differs between members (src/matched/ov/ov220_func_021B9B64.c); prototype of func_
- ov220_func_021B95A0.c..ov220_func_021B99DC.c: c99=ERROR SystemExit('ISA conflict for func_021BA0D8 at 021BA0D8: the source declares arm, the image says thumb (the func_021BA0D8 label in ov220).  Fix the symbols: block (address from name); refusin
- ov220_func_021B95A0.c..ov220_func_021B97F4.c: c99=ERROR SystemExit('ISA conflict for func_021BA0D8 at 021BA0D8: the source declares arm, the image says thumb (the func_021BA0D8 label in ov220).  Fix the symbols: block (address from name); refusin
- ov220_func_021B9770.c..ov220_func_021B97F4.c: c99=ERROR SystemExit('ISA conflict for func_021BA01C at 021BA01C: the source declares arm, the image says thumb (the func_021BA01C label in ov220).  Fix the symbols: block (address from name); refusin
- ov220_func_021B9960.c..ov220_func_021B99DC.c: c99=ERROR SystemExit('ISA conflict for func_021BA1E0 at 021BA1E0: the source declares arm, the image says thumb (the func_021BA1E0 label in ov220).  Fix the symbols: block (address from name); refusin
- ov220_func_021B99D8.c..ov220_func_021B99DC.c: c99=ERROR SystemExit('ISA conflict for func_021BA1E0 at 021BA1E0: the source declares arm, the image says thumb (the func_021BA1E0 label in ov220).  Fix the symbols: block (address from name); refusin
- ov220_func_021B9B20.c..ov220_func_021BA068.c: prototype of func_0204ADA4 differs between members (src/matched/ov/ov220_func_021B9C70.c); global d_021BA3A8 declared two ways (src/matched/ov/ov220_func_021BA068.c)
- ov220_func_021B9B20.c..ov220_func_021B9C70.c: prototype of func_0204ADA4 differs between members (src/matched/ov/ov220_func_021B9C70.c)
- ov220_func_021B9B64.c..ov220_func_021B9C70.c: c99=ERROR SystemExit('ISA conflict for func_021BA1E0 at 021BA1E0: the source declares arm, the image says thumb (the func_021BA1E0 label in ov220).  Fix the symbols: block (address from name); refusin
- ov220_func_021B9CBC.c..ov220_func_021BA068.c: global d_021BA3A8 declared two ways (src/matched/ov/ov220_func_021BA068.c)

Members, in address order:

- `ov220_func_021B95A0.c`
- `ov220_func_021B9770.c`
- `ov220_func_021B97F4.c`
- `ov220_func_021B9960.c`
- `ov220_func_021B99D8.c`
- `ov220_func_021B99DC.c`
- `ov220_func_021B9B20.c`
- `ov220_func_021B9B64.c`
- `ov220_func_021B9C70.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021B95A0.c` again.
