# ghttpEncryption.c (ov114)

Translation unit 021C109C..021C1D30, 17 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`ghttpEncryption.c` is blocked by:

- ov114_func_021C109C.c..ov114_func_021C1C98.c: prototype of func_0217D254 differs between members (src/matched/ov_sdk/ov114_func_021C1230.c); prototype of func_0217D254 differs between members (src/matched/ov_sdk/ov114_func_021C137C.c); prototype 
- ov114_func_021C109C.c..ov114_func_021C1668.c: prototype of func_0217D254 differs between members (src/matched/ov_sdk/ov114_func_021C1230.c); prototype of func_0217D254 differs between members (src/matched/ov_sdk/ov114_func_021C137C.c); prototype 
- ov114_func_021C109C.c..ov114_func_021C1230.c: prototype of func_0217D254 differs between members (src/matched/ov_sdk/ov114_func_021C1230.c)
- ov114_func_021C1804.c..ov114_func_021C1C98.c: prototype of func_0217D254 differs between members (src/matched/ov_sdk/ov114_func_021C1C98.c)
- no verified entry for 021C1210

Members, in address order:


To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names ghttpEncryption.c` again.
