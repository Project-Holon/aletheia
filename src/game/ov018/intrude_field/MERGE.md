# intrude_field.c (ov018)

Translation unit 0217AE20..0217C758, 45 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`intrude_field.c` is blocked by:

- ov018_func_0217AE20.c..ov018_func_0217C688.c: prototype of func_020124E4 differs between members (src/matched/ov/ov018_func_0217B600.c); prototype of func_021A3074 differs between members (src/matched/ov/ov018_func_0217B600.c); prototype of func_
- ov018_func_0217AE20.c..ov018_func_0217BCDC.c: prototype of func_020124E4 differs between members (src/matched/ov/ov018_func_0217B600.c); prototype of func_021A3074 differs between members (src/matched/ov/ov018_func_0217B600.c); prototype of func_
- ov018_func_0217AE20.c..ov018_func_0217B810.c: prototype of func_020124E4 differs between members (src/matched/ov/ov018_func_0217B600.c); prototype of func_021A3074 differs between members (src/matched/ov/ov018_func_0217B600.c)
- ov018_func_0217B214.c..ov018_func_0217B810.c: prototype of func_020124E4 differs between members (src/matched/ov/ov018_func_0217B600.c); prototype of func_021A3074 differs between members (src/matched/ov/ov018_func_0217B600.c)
- ov018_func_0217B5DC.c..ov018_func_0217B810.c: prototype of func_021A3074 differs between members (src/matched/ov/ov018_func_0217B600.c)
- ov018_func_0217BDE0.c..ov018_func_0217C688.c: c99=CCERR: line 464: illegal implicit conversion from 'struct  *' to | line 464: 'short *' | line 746: illegal implicit conversion from 'struct  *' to nolang=CCERR: line 464: illegal implicit conversi
- ov018_func_0217BDE0.c..ov018_func_0217C0A8.c: c99=CCERR: line 193: illegal implicit conversion from 'struct  *' to | line 193: 'short *' nolang=CCERR: line 193: illegal implicit conversion from 'struct  *' to | line 193: 'short *'
- ov018_func_0217BDE0.c..ov018_func_0217BF28.c: c99=CCERR: line 123: illegal implicit conversion from 'struct  *' to | line 123: 'short *' nolang=CCERR: line 123: illegal implicit conversion from 'struct  *' to | line 123: 'short *'
- ov018_func_0217C11C.c..ov018_func_0217C688.c: c99=CCERR: line 458: illegal implicit conversion from 'struct  *' to | line 458: 'const struct  *' | line 528: illegal implicit conversion from 'struct  *' to nolang=CCERR: line 458: illegal implicit 
- ov018_func_0217C2A0.c..ov018_func_0217C688.c: c99=CCERR: line 384: illegal implicit conversion from 'struct  *' to | line 384: 'struct  *' | line 388: illegal implicit conversion from 'struct  *' to nolang=CCERR: line 384: illegal implicit conver
- ov018_func_0217C4D0.c..ov018_func_0217C688.c: c99=CCERR: line 199: illegal implicit conversion from 'struct  *' to | line 199: 'struct  *' | line 203: illegal implicit conversion from 'struct  *' to nolang=CCERR: line 199: illegal implicit conver

Members, in address order:

- `ov018_func_0217B5DC.c`
- `ov018_func_0217C4D0.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names intrude_field.c` again.
