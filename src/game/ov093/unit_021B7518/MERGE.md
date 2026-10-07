# unit_021B7518.c (ov093)

Translation unit 021B7518..021B8834, 38 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021B7518.c` is blocked by:

- ov093_func_021B7518.c..ov093_func_021B87E8.c: prototype of func_021B6818 differs between members (src/matched/ov/ov093_func_021B7E18.c); prototype of func_021BAB10 differs between members (src/matched/ov/ov093_func_021B7E18.c); prototype of func_
- ov093_func_021B7518.c..ov093_func_021B85A8.c: prototype of func_021B6818 differs between members (src/matched/ov/ov093_func_021B7E18.c); prototype of func_021BAB10 differs between members (src/matched/ov/ov093_func_021B7E18.c); prototype of func_
- ov093_func_021B7518.c..ov093_func_021B81DC.c: prototype of func_021B6818 differs between members (src/matched/ov/ov093_func_021B7E18.c); prototype of func_021BAB10 differs between members (src/matched/ov/ov093_func_021B7E18.c); prototype of func_
- ov093_func_021B7BB0.c..ov093_func_021B81DC.c: prototype of func_021B6818 differs between members (src/matched/ov/ov093_func_021B7E18.c); prototype of func_021BAB10 differs between members (src/matched/ov/ov093_func_021B7E18.c); prototype of func_
- ov093_func_021B7E18.c..ov093_func_021B81DC.c: prototype of func_021B6818 differs between members (src/matched/ov/ov093_func_021B8070.c); prototype of func_021B6818 differs between members (src/matched/ov/ov093_func_021B81DC.c)
- ov093_func_021B85DC.c..ov093_func_021B87E8.c: c99=CCERR: line 173: illegal implicit conversion from 'char *' to | line 173: 'void ***' nolang=CCERR: line 173: illegal implicit conversion from 'char *' to | line 173: 'void ***'

Members, in address order:

- `ov093_func_021B7E18.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021B7518.c` again.

- `ov093_func_021B86CA.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.
