# field_wfbc_data_local.c (ov020)

Translation unit 02185EB0..02187D94, 106 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`field_wfbc_data_local.c` is blocked by:

- ov020_func_02185EB0.c..ov020_func_02187D74.c: prototype of func_0201284C differs between members (src/matched/ov/ov020_func_02185F18.c); prototype of func_02161E78 differs between members (src/matched/ov/ov020_func_021862A8.c); prototype of func_
- ov020_func_02185EB0.c..ov020_func_02186A2C.c: prototype of func_0201284C differs between members (src/matched/ov/ov020_func_02185F18.c); prototype of func_02161E78 differs between members (src/matched/ov/ov020_func_021862A8.c); prototype of func_
- ov020_func_02185EB0.c..ov020_func_02186770.c: prototype of func_0201284C differs between members (src/matched/ov/ov020_func_02185F18.c); prototype of func_02161E78 differs between members (src/matched/ov/ov020_func_021862A8.c); prototype of func_
- ov020_func_02185EB0.c..ov020_func_021861BC.c: prototype of func_0201284C differs between members (src/matched/ov/ov020_func_02185F18.c)
- ov020_func_02185EB0.c..ov020_func_0218604C.c: prototype of func_0201284C differs between members (src/matched/ov/ov020_func_02185F18.c)
- ov020_func_02185EB0.c..ov020_func_02185F48.c: prototype of func_0201284C differs between members (src/matched/ov/ov020_func_02185F18.c)
- ov020_func_021861F4.c..ov020_func_02186770.c: prototype of func_02161ECC differs between members (src/matched/ov/ov020_func_021864DC.c); prototype of func_02161ECC differs between members (src/matched/ov/ov020_func_02186538.c); prototype of func_
- ov020_func_021861F4.c..ov020_func_021864DC.c: prototype of func_02161ECC differs between members (src/matched/ov/ov020_func_021864DC.c)
- ov020_func_021862A8.c..ov020_func_021864DC.c: prototype of func_02161ECC differs between members (src/matched/ov/ov020_func_021864DC.c)
- ov020_func_02186470.c..ov020_func_021864DC.c: prototype of func_02161ECC differs between members (src/matched/ov/ov020_func_021864DC.c)
- ov020_func_0218677C.c..ov020_func_02186A2C.c: global d_02187EB4 declared two ways (src/matched/ov/ov020_func_021868B8.c)
- ov020_func_02186A58.c..ov020_func_02187D74.c: prototype of func_02161ECC differs between members (src/matched/ov/ov020_func_02186B60.c); prototype of func_021912F8 differs between members (src/matched/ov/ov020_func_021875B8.c)
- ov020_func_02186A58.c..ov020_func_0218768C.c: prototype of func_02161ECC differs between members (src/matched/ov/ov020_func_02186B60.c); prototype of func_021912F8 differs between members (src/matched/ov/ov020_func_021875B8.c)
- ov020_func_02186A58.c..ov020_func_02186D48.c: prototype of func_02161ECC differs between members (src/matched/ov/ov020_func_02186B60.c)
- ov020_func_02186A58.c..ov020_func_02186B84.c: prototype of func_02161ECC differs between members (src/matched/ov/ov020_func_02186B60.c)
- ov020_func_02186E94.c..ov020_func_0218768C.c: prototype of func_021912F8 differs between members (src/matched/ov/ov020_func_021875B8.c)
- ov020_func_0218741C.c..ov020_func_0218768C.c: prototype of func_021912F8 differs between members (src/matched/ov/ov020_func_021875B8.c)

Members, in address order:

- `ov020_func_02185EB0.c`
- `ov020_func_021862A8.c`
- `ov020_func_02186470.c`
- `ov020_func_021864DC.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names field_wfbc_data_local.c` again.
