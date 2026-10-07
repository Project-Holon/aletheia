# demo3d_cmdsys.c (ov203)

Translation unit 021BEE1C..021BF9D0, 32 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`demo3d_cmdsys.c` is blocked by:

- ov203_func_021BEE1C.c..ov203_func_021BF9B8.c: prototype of func_02082BCC differs between members (src/matched/ov/ov203_func_021BEFC4.c); prototype of func_020311B8 differs between members (src/matched/ov/ov203_func_021BF2DC.c); prototype of func_
- ov203_func_021BEE1C.c..ov203_func_021BF404.c: prototype of func_02082BCC differs between members (src/matched/ov/ov203_func_021BEFC4.c); prototype of func_020311B8 differs between members (src/matched/ov/ov203_func_021BF2DC.c)
- ov203_func_021BF168.c..ov203_func_021BF404.c: prototype of func_020311B8 differs between members (src/matched/ov/ov203_func_021BF2DC.c)
- ov203_func_021BF470.c..ov203_func_021BF9B8.c: prototype of func_021BE990 differs between members (src/matched/ov/ov203_func_021BF964.c)
- ov203_func_021BF7AC.c..ov203_func_021BF9B8.c: prototype of func_021BE990 differs between members (src/matched/ov/ov203_func_021BF964.c)
- ov203_func_021BF7AC.c..ov203_func_021BF858.c: prototype of func_021BF9B8 differs between members (src/matched/ov/ov203_func_021BF858.c)
- ov203_func_021BF810.c..ov203_func_021BF858.c: prototype of func_021BF9B8 differs between members (src/matched/ov/ov203_func_021BF858.c)

Members, in address order:

- `ov203_func_021BF810.c`
- `ov203_func_021BF858.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names demo3d_cmdsys.c` again.
