# unit_0217AE20.c (ov019)

Translation unit 0217AE20..0217BD9C, 45 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_0217AE20.c` is blocked by:

- ov019_func_0217AE20.c..ov019_func_0217BCDC.c: prototype of memcmp differs between members (src/matched/ov/ov019_func_0217B264.c); prototype of MI_CpuFill8 differs between members (src/matched/ov/ov019_func_0217B264.c); prototype of func_0216D410 
- ov019_func_0217AE20.c..ov019_func_0217B66C.c: prototype of memcmp differs between members (src/matched/ov/ov019_func_0217B264.c); prototype of MI_CpuFill8 differs between members (src/matched/ov/ov019_func_0217B264.c)
- ov019_func_0217B054.c..ov019_func_0217B66C.c: prototype of memcmp differs between members (src/matched/ov/ov019_func_0217B264.c); prototype of MI_CpuFill8 differs between members (src/matched/ov/ov019_func_0217B264.c)
- ov019_func_0217B054.c..ov019_func_0217B264.c: prototype of memcmp differs between members (src/matched/ov/ov019_func_0217B264.c); prototype of MI_CpuFill8 differs between members (src/matched/ov/ov019_func_0217B264.c)
- ov019_func_0217B158.c..ov019_func_0217B264.c: prototype of memcmp differs between members (src/matched/ov/ov019_func_0217B264.c)
- ov019_func_0217B6B4.c..ov019_func_0217BCDC.c: prototype of func_02173524 differs between members (src/matched/ov/ov019_func_0217BCDC.c)
- ov019_func_0217B9CC.c..ov019_func_0217BCDC.c: prototype of func_02173524 differs between members (src/matched/ov/ov019_func_0217BCDC.c)
- ov019_func_0217BAF0.c..ov019_func_0217BCDC.c: prototype of func_02173524 differs between members (src/matched/ov/ov019_func_0217BCDC.c)
- ov019_func_0217BB3C.c..ov019_func_0217BCDC.c: prototype of func_02173524 differs between members (src/matched/ov/ov019_func_0217BCDC.c)

Members, in address order:

- `ov019_func_0217B158.c`
- `ov019_func_0217BB3C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_0217AE20.c` again.
