# pokelist.c (ov091)

Translation unit 021B6240..021B8DB4, 33 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`pokelist.c` is blocked by:

- ov091_func_021B6240.c..ov091_func_021B8AC4.c: prototype of func_020355D8 differs between members (src/matched/ov/ov091_func_021B6818.c); prototype of func_0207D63C differs between members (src/matched/ov/ov091_func_021B6F28.c); prototype of func_
- ov091_func_021B6240.c..ov091_func_021B709C.c: prototype of func_020355D8 differs between members (src/matched/ov/ov091_func_021B6818.c); prototype of func_0207D63C differs between members (src/matched/ov/ov091_func_021B6F28.c); prototype of func_
- ov091_func_021B6240.c..ov091_func_021B6D64.c: prototype of func_020355D8 differs between members (src/matched/ov/ov091_func_021B6818.c)
- ov091_func_021B6D90.c..ov091_func_021B709C.c: prototype of func_0207D63C differs between members (src/matched/ov/ov091_func_021B6F28.c); prototype of func_0207D63C differs between members (src/matched/ov/ov091_func_021B7040.c)
- ov091_func_021B6D90.c..ov091_func_021B6FEC.c: prototype of func_0207D63C differs between members (src/matched/ov/ov091_func_021B6F28.c)
- ov091_func_021B6D90.c..ov091_func_021B6F0C.c: c99=ERROR SystemExit('ISA conflict for func_021B9A84 at 021B9A84: the source declares arm, the image says thumb (the func_021B9A84 label in ov091).  Fix the symbols: block (address from name); refusin

Members, in address order:

- `ov091_func_021B6D90.c`
- `ov091_func_021B6F0C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names pokelist.c` again.
