# fld_faceup.c (ov082)

Translation unit 021F5260..021F58C0, 16 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`fld_faceup.c` is blocked by:

- ov082_func_021F5260.c..ov082_func_021F5840.c: prototype of func_02189A60 differs between members (src/matched/ov/ov082_func_021F5338.c); prototype of func_02189A60 differs between members (src/matched/ov/ov082_func_021F5550.c); prototype of func_
- ov082_func_021F5260.c..ov082_func_021F5648.c: prototype of func_02189A60 differs between members (src/matched/ov/ov082_func_021F5338.c); prototype of func_02189A60 differs between members (src/matched/ov/ov082_func_021F5550.c); prototype of func_
- ov082_func_021F5578.c..ov082_func_021F5648.c: prototype of func_02189A60 differs between members (src/matched/ov/ov082_func_021F558C.c); prototype of func_02189A60 differs between members (src/matched/ov/ov082_func_021F55A0.c); prototype of func_
- ov082_func_021F55A0.c..ov082_func_021F5648.c: prototype of func_02189A60 differs between members (src/matched/ov/ov082_func_021F5648.c)
- ov082_func_021F56C0.c..ov082_func_021F5840.c: c99=CCERR: line 118: illegal implicit conversion from 'char[]' to | line 118: 'struct  *' | line 125: illegal implicit conversion from 'char[]' to nolang=CCERR: line 118: illegal implicit conversion f
- ov082_func_021F5708.c..ov082_func_021F5840.c: c99=CCERR: line 90: illegal implicit conversion from 'char[]' to | line 90: 'struct  *' | line 97: illegal implicit conversion from 'char[]' to nolang=CCERR: line 90: illegal implicit conversion from 

Members, in address order:

- `ov082_func_021F55A0.c`
- `ov082_func_021F5648.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names fld_faceup.c` again.
