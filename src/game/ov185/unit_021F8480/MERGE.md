# unit_021F8480.c (ov185)

Translation unit 021F8480..021F9048, 26 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021F8480.c` is blocked by:

- ov185_func_021F8480.c..ov185_func_021F9008.c: prototype of func_021FD73C differs between members (src/matched/ov/ov185_func_021F86A4.c); prototype of func_021FD860 differs between members (src/matched/ov/ov185_func_021F8790.c); prototype of func_
- ov185_func_021F8480.c..ov185_func_021F8B5C.c: prototype of func_021FD73C differs between members (src/matched/ov/ov185_func_021F86A4.c); prototype of func_021FD860 differs between members (src/matched/ov/ov185_func_021F8790.c); prototype of func_
- ov185_func_021F8480.c..ov185_func_021F86A4.c: prototype of func_021FD73C differs between members (src/matched/ov/ov185_func_021F86A4.c)
- ov185_func_021F8604.c..ov185_func_021F86A4.c: prototype of func_021FD73C differs between members (src/matched/ov/ov185_func_021F86A4.c)
- ov185_func_021F86E4.c..ov185_func_021F8B5C.c: prototype of func_021FD860 differs between members (src/matched/ov/ov185_func_021F8790.c); prototype of func_021FD860 differs between members (src/matched/ov/ov185_func_021F8AA8.c)
- ov185_func_021F86E4.c..ov185_func_021F88B0.c: prototype of func_021FD860 differs between members (src/matched/ov/ov185_func_021F8790.c)
- ov185_func_021F8C30.c..ov185_func_021F9008.c: prototype of func_021FEEC0 differs between members (src/matched/ov/ov185_func_021F8D5C.c); prototype of func_021FBDA4 differs between members (src/matched/ov/ov185_func_021F8E60.c)
- ov185_func_021F8C30.c..ov185_func_021F8E90.c: prototype of func_021FEEC0 differs between members (src/matched/ov/ov185_func_021F8D5C.c); prototype of func_021FBDA4 differs between members (src/matched/ov/ov185_func_021F8E60.c)
- ov185_func_021F8C30.c..ov185_func_021F8D5C.c: prototype of func_021FEEC0 differs between members (src/matched/ov/ov185_func_021F8D5C.c)
- ov185_func_021F8D18.c..ov185_func_021F8D5C.c: prototype of func_021FEEC0 differs between members (src/matched/ov/ov185_func_021F8D5C.c)

Members, in address order:

- `ov185_func_021F8604.c`
- `ov185_func_021F86E4.c`
- `ov185_func_021F8C30.c`
- `ov185_func_021F8D18.c`
- `ov185_func_021F8D5C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021F8480.c` again.
