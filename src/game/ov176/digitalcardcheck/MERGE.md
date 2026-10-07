# digitalcardcheck.c (ov176)

Translation unit 0217CFE8..0217DEA4, 32 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`digitalcardcheck.c` is blocked by:

- ov176_func_0217CFE8.c..ov176_func_0217DE60.c: prototype of func_02082D44 differs between members (src/matched/ov/ov176_func_0217D2BC.c); prototype of func_02082D44 differs between members (src/matched/ov/ov176_func_0217D2F0.c); prototype of func_
- ov176_func_0217D2BC.c..ov176_func_0217DE60.c: prototype of func_02082D44 differs between members (src/matched/ov/ov176_func_0217D2F0.c); prototype of func_02082BCC differs between members (src/matched/ov/ov176_func_0217DC28.c); prototype of func_
- ov176_func_0217D2BC.c..ov176_func_0217D458.c: prototype of func_02082D44 differs between members (src/matched/ov/ov176_func_0217D2F0.c)
- ov176_func_0217D2BC.c..ov176_func_0217D398.c: prototype of func_02082D44 differs between members (src/matched/ov/ov176_func_0217D2F0.c)
- ov176_func_0217D2BC.c..ov176_func_0217D2F0.c: prototype of func_02082D44 differs between members (src/matched/ov/ov176_func_0217D2F0.c)

Members, in address order:

- `ov176_func_0217D2BC.c`
- `ov176_func_0217D2F0.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names digitalcardcheck.c` again.
