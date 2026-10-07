# unit_021D4240.c (ov122)

Translation unit 021D4240..021D55FC, 34 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021D4240.c` is blocked by:

- ov122_func_021D4240.c..ov122_func_021D5514.c: prototype of func_020452E8 differs between members (src/matched/ov/ov122_func_021D4590.c); prototype of func_020452E8 differs between members (src/matched/ov/ov122_func_021D45BC.c); prototype of func_
- ov122_func_021D4240.c..ov122_func_021D4B74.c: prototype of func_020452E8 differs between members (src/matched/ov/ov122_func_021D4590.c); prototype of func_020452E8 differs between members (src/matched/ov/ov122_func_021D45BC.c)
- ov122_func_021D4BF4.c..ov122_func_021D5514.c: prototype of func_02045CAC differs between members (src/matched/ov/ov122_func_021D5004.c); prototype of func_02045808 differs between members (src/matched/ov/ov122_func_021D5110.c); prototype of func_
- ov122_func_021D4BF4.c..ov122_func_021D50B4.c: prototype of func_02045CAC differs between members (src/matched/ov/ov122_func_021D5004.c)
- ov122_func_021D4BF4.c..ov122_func_021D4D98.c: c99=CCERR: line 183: illegal implicit conversion from 'char *' to | line 183: 'struct  *' | line 184: illegal implicit conversion from 'char *' to nolang=CCERR: line 183: illegal implicit conversion f
- ov122_func_021D4CD8.c..ov122_func_021D4D98.c: c99=CCERR: line 115: illegal implicit conversion from 'char *' to | line 115: 'struct  *' | line 116: illegal implicit conversion from 'char *' to nolang=CCERR: line 115: illegal implicit conversion f

Members, in address order:

- `ov122_func_021D4CD8.c`
- `ov122_func_021D4D98.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021D4240.c` again.
