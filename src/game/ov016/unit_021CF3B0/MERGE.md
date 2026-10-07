# unit_021CF3B0.c (ov016)

Translation unit 021CF3B0..021CFBD4, 23 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021CF3B0.c` is blocked by:

- ov016_func_021CF3B0.c..ov016_func_021CFABC.c: prototype of ascii2hex differs between members (src/matched/ov_sdk/ov016_func_021CF46C.c); prototype of ascii2hex differs between members (src/matched/ov_sdk/ov016_func_021CF80C.c); prototype of ascii
- ov016_func_021CF3B0.c..ov016_func_021CF644.c: prototype of ascii2hex differs between members (src/matched/ov_sdk/ov016_func_021CF46C.c)
- ov016_func_021CF440.c..ov016_func_021CF644.c: prototype of ascii2hex differs between members (src/matched/ov_sdk/ov016_func_021CF46C.c)
- ov016_func_021CF440.c..ov016_func_021CF5EC.c: prototype of ascii2hex differs between members (src/matched/ov_sdk/ov016_func_021CF46C.c)

Members, in address order:

- `ov016_func_021CF440.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021CF3B0.c` again.
