# ctvt_draw.c (ov172)

Translation unit 021BA174..021BE468, 104 functions, confidence likely (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`ctvt_draw.c` is blocked by:

- ov172_func_021BA174.c..ov172_func_021BE43C.c: prototype of func_0203D34C differs between members (src/matched/ov/ov172_func_021BA8C4.c); prototype of func_020409B4 differs between members (src/matched/ov/ov172_func_021BA8C4.c); prototype of func_
- ov172_func_021BA174.c..ov172_func_021BDC70.c: prototype of func_0203D34C differs between members (src/matched/ov/ov172_func_021BA8C4.c); prototype of func_020409B4 differs between members (src/matched/ov/ov172_func_021BA8C4.c); prototype of func_
- ov172_func_021BBA6C.c..ov172_func_021BDC70.c: prototype of func_02030734 differs between members (src/matched/ov/ov172_func_021BBA94.c); prototype of func_020409B4 differs between members (src/matched/ov/ov172_func_021BBE5C.c); prototype of func_
- ov172_func_021BD0C4.c..ov172_func_021BDC70.c: prototype of func_021BE034 differs between members (src/matched/ov/ov172_func_021BD134.c); prototype of func_021BE03C differs between members (src/matched/ov/ov172_func_021BD134.c); prototype of func_
- ov172_func_021BD5D8.c..ov172_func_021BDC70.c: prototype of func_02040588 differs between members (src/matched/ov/ov172_func_021BD820.c); prototype of func_02049238 differs between members (src/matched/ov/ov172_func_021BDB5C.c)
- ov172_func_021BD5D8.c..ov172_func_021BD820.c: prototype of func_02040588 differs between members (src/matched/ov/ov172_func_021BD820.c)
- ov172_func_021BD844.c..ov172_func_021BDC70.c: prototype of func_02049238 differs between members (src/matched/ov/ov172_func_021BDB5C.c)
- ov172_func_021BD844.c..ov172_func_021BDB5C.c: prototype of func_02049238 differs between members (src/matched/ov/ov172_func_021BDB5C.c)
- ov172_func_021BDCB8.c..ov172_func_021BE43C.c: prototype of func_021B8BA4 differs between members (src/matched/ov/ov172_func_021BE210.c); prototype of func_021B8B8C differs between members (src/matched/ov/ov172_func_021BE210.c); prototype of func_

Members, in address order:

- `ov172_func_021BD5D8.c`
- `ov172_func_021BD844.c`
- `ov172_func_021BDB5C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names ctvt_draw.c` again.
