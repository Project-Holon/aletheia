# unit_021F36C0.c (ov046)

Translation unit 021F36C0..021F40D8, 20 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021F36C0.c` is blocked by:

- ov046_func_021F36C0.c..ov046_func_021F4078.c: prototype of func_021BE700 differs between members (src/matched/ov/ov046_func_021F3838.c); prototype of func_021BE674 differs between members (src/matched/ov/ov046_func_021F38D4.c); prototype of func_
- ov046_func_021F36C0.c..ov046_func_021F3BC8.c: prototype of func_021BE700 differs between members (src/matched/ov/ov046_func_021F3838.c); prototype of func_021BE674 differs between members (src/matched/ov/ov046_func_021F38D4.c)
- ov046_func_021F36C0.c..ov046_func_021F3A28.c: prototype of func_021BE700 differs between members (src/matched/ov/ov046_func_021F3838.c); prototype of func_021BE674 differs between members (src/matched/ov/ov046_func_021F38D4.c)
- ov046_func_021F36C0.c..ov046_func_021F3838.c: prototype of func_021BE700 differs between members (src/matched/ov/ov046_func_021F3838.c)
- ov046_func_021F3BE8.c..ov046_func_021F4078.c: prototype of func_021897BC differs between members (src/matched/ov/ov046_func_021F3DE8.c)
- ov046_func_021F3BE8.c..ov046_func_021F3DE8.c: prototype of func_021897BC differs between members (src/matched/ov/ov046_func_021F3DE8.c)
- ov046_func_021F3C8C.c..ov046_func_021F3DE8.c: prototype of func_021897BC differs between members (src/matched/ov/ov046_func_021F3DE8.c)
- ov046_func_021F3D40.c..ov046_func_021F3DE8.c: prototype of func_021897BC differs between members (src/matched/ov/ov046_func_021F3DE8.c)

Members, in address order:

- `ov046_func_021F36C0.c`
- `ov046_func_021F3838.c`
- `ov046_func_021F3C8C.c`
- `ov046_func_021F3D40.c`
- `ov046_func_021F3DE8.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021F36C0.c` again.
