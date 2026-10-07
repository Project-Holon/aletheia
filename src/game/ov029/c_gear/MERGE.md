# c_gear.c (ov029)

Translation unit 021EFEC0..021F2BF0, 110 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`c_gear.c` is blocked by:

- ov029_func_021EFEC0.c..ov029_func_021F2BD4.c: prototype of func_0202173C differs between members (src/matched/ov/ov029_func_021F0EB0.c); prototype of func_0202173C differs between members (src/matched/ov/ov029_func_021F0F28.c); prototype of func_
- ov029_func_021EFEC0.c..ov029_func_021F1000.c: prototype of func_0202173C differs between members (src/matched/ov/ov029_func_021F0EB0.c); prototype of func_0202173C differs between members (src/matched/ov/ov029_func_021F0F28.c); prototype of func_
- ov029_func_021F0A38.c..ov029_func_021F1000.c: c99=CCERR: line 159: illegal implicit conversion from 'unsigned char *' to | line 159: 'struct  *' | line 183: illegal implicit conversion from 'struct S021F0B7C_021F0AA0 *' to nolang=CCERR: line 159:
- ov029_func_021F0A38.c..ov029_func_021F0CB8.c: c99=CCERR: line 102: illegal implicit conversion from 'unsigned char *' to | line 102: 'struct  *' | line 126: illegal implicit conversion from 'struct S021F0B7C_021F0AA0 *' to nolang=CCERR: line 102:
- ov029_func_021F0A38.c..ov029_func_021F0B00.c: prototype of func_021F0C00 differs between members (src/matched/ov/ov029_func_021F0B00.c)
- ov029_func_021F0AC8.c..ov029_func_021F0B00.c: prototype of func_021F0C00 differs between members (src/matched/ov/ov029_func_021F0B00.c)
- ov029_func_021F0AE0.c..ov029_func_021F0B00.c: prototype of func_021F0C00 differs between members (src/matched/ov/ov029_func_021F0B00.c)
- ov029_func_021F1010.c..ov029_func_021F2BD4.c: prototype of func_021F0B00 differs between members (src/matched/ov/ov029_func_021F11B4.c); prototype of func_02158614 differs between members (src/matched/ov/ov029_func_021F26E0.c)
- ov029_func_021F1F24.c..ov029_func_021F2BD4.c: prototype of func_02158614 differs between members (src/matched/ov/ov029_func_021F26E0.c)
- ov029_func_021F251C.c..ov029_func_021F2BD4.c: prototype of func_02158614 differs between members (src/matched/ov/ov029_func_021F26E0.c)
- ov029_func_021F251C.c..ov029_func_021F2994.c: prototype of func_02158614 differs between members (src/matched/ov/ov029_func_021F26E0.c)
- ov029_func_021F251C.c..ov029_func_021F279C.c: prototype of func_02158614 differs between members (src/matched/ov/ov029_func_021F26E0.c)
- ov029_func_021F27D8.c..ov029_func_021F2994.c: c99=DIFF nolang=DIFF

Members, in address order:

- `ov029_func_021F0AC8.c`
- `ov029_func_021F0AE0.c`
- `ov029_func_021F0B00.c`
- `ov029_func_021F251C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names c_gear.c` again.
