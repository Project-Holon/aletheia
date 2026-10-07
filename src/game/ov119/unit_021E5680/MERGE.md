# unit_021E5680.c (ov119)

Translation unit 021E5680..021E6CB8, 40 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021E5680.c` is blocked by:

- ov119_func_021E5680.c..ov119_func_021E6B90.c: prototype of func_021B6208 differs between members (src/matched/ov/ov119_func_021E5F14.c); prototype of func_021B629C differs between members (src/matched/ov/ov119_func_021E5F14.c); prototype of func_
- ov119_func_021E5680.c..ov119_func_021E62D4.c: prototype of func_021B6208 differs between members (src/matched/ov/ov119_func_021E5F14.c); prototype of func_021B629C differs between members (src/matched/ov/ov119_func_021E5F14.c); prototype of func_
- ov119_func_021E5C64.c..ov119_func_021E62D4.c: prototype of func_021B6208 differs between members (src/matched/ov/ov119_func_021E5F14.c); prototype of func_021B629C differs between members (src/matched/ov/ov119_func_021E5F14.c); prototype of func_
- ov119_func_021E6008.c..ov119_func_021E62D4.c: prototype of func_021B6208 differs between members (src/matched/ov/ov119_func_021E60BC.c)
- ov119_func_021E6008.c..ov119_func_021E60BC.c: prototype of func_021B6208 differs between members (src/matched/ov/ov119_func_021E60BC.c)
- ov119_func_021E6308.c..ov119_func_021E6B90.c: prototype of func_02049238 differs between members (src/matched/ov/ov119_func_021E6B90.c)

Members, in address order:

- `ov119_func_021E6008.c`
- `ov119_func_021E60BC.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021E5680.c` again.
