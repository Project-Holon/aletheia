# fld_exp_obj.c (ov021)

Translation unit 021BE258..021BEE74, 49 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`fld_exp_obj.c` is blocked by:

- ov021_func_021BE258.c..ov021_func_021BEE24.c: type typedef Grp differs between members (src/matched/ov/ov021_func_021BE580.c); type typedef P differs between members (src/matched/ov/ov021_func_021BE580.c); prototype of func_02048A00 differs betwe
- ov021_func_021BE258.c..ov021_func_021BE89C.c: type typedef P differs between members (src/matched/ov/ov021_func_021BE580.c); prototype of func_02048A00 differs between members (src/matched/ov/ov021_func_021BE580.c); type typedef P differs between
- ov021_func_021BE258.c..ov021_func_021BE580.c: type typedef P differs between members (src/matched/ov/ov021_func_021BE580.c); prototype of func_02048A00 differs between members (src/matched/ov/ov021_func_021BE580.c)
- func_021BE480.c..ov021_func_021BE580.c: prototype of func_02048A00 differs between members (src/matched/ov/ov021_func_021BE580.c)
- ov021_func_021BE4C4.c..ov021_func_021BE580.c: prototype of func_02048A00 differs between members (src/matched/ov/ov021_func_021BE580.c)
- ov021_func_021BE4F8.c..ov021_func_021BE580.c: prototype of func_02048A00 differs between members (src/matched/ov/ov021_func_021BE580.c)
- ov021_func_021BE630.c..ov021_func_021BE89C.c: prototype of func_021BE4C4 differs between members (src/matched/ov/ov021_func_021BE700.c); prototype of func_021BE4C4 differs between members (src/matched/ov/ov021_func_021BE760.c)
- ov021_func_021BE6CC.c..ov021_func_021BE89C.c: prototype of func_021BE4C4 differs between members (src/matched/ov/ov021_func_021BE700.c); prototype of func_021BE4C4 differs between members (src/matched/ov/ov021_func_021BE760.c)
- ov021_func_021BE6CC.c..ov021_func_021BE700.c: prototype of func_021BE4C4 differs between members (src/matched/ov/ov021_func_021BE700.c)
- ov021_func_021BE6E8.c..ov021_func_021BE700.c: prototype of func_021BE4C4 differs between members (src/matched/ov/ov021_func_021BE700.c)
- ov021_func_021BE8B8.c..ov021_func_021BEE24.c: c99=CCERR: line 230: illegal implicit conversion from 'int' to | line 230: 'void *' nolang=CCERR: line 230: illegal implicit conversion from 'int' to | line 230: 'void *'

Members, in address order:

- `ov021_func_021BE4C4.c`
- `ov021_func_021BE4F8.c`
- `ov021_func_021BE580.c`
- `ov021_func_021BE6CC.c`
- `ov021_func_021BE6E8.c`
- `ov021_func_021BE700.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names fld_exp_obj.c` again.
