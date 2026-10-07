# unit_021743B4.c (ov011)

Translation unit 021743B4..02175C40, 91 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021743B4.c` is blocked by:

- ov011_func_021743B4.c..ov011_func_02175BE4.c: prototype of func_02082D44 differs between members (src/matched/ov/ov011_func_02174E3C.c); prototype of func_02082D44 differs between members (src/matched/ov/ov011_func_02174EAC.c); prototype of func_
- ov011_func_021743B4.c..ov011_func_02175368.c: prototype of func_02082D44 differs between members (src/matched/ov/ov011_func_02174E3C.c); prototype of func_02082D44 differs between members (src/matched/ov/ov011_func_02174EAC.c); prototype of func_
- ov011_func_021743B4.c..ov011_func_02174954.c: c99=DIFF nolang=DIFF
- ov011_func_02174630.c..ov011_func_02174954.c: c99=DIFF nolang=DIFF
- ov011_func_02174630.c..ov011_func_02174734.c: c99=DIFF nolang=DIFF
- ov011_func_021747A8.c..ov011_func_02174954.c: c99=DIFF nolang=DIFF
- ov011_func_021747A8.c..ov011_func_02174854.c: c99=DIFF nolang=DIFF
- ov011_func_021747F4.c..ov011_func_02174854.c: c99=DIFF nolang=DIFF
- ov011_func_02174978.c..ov011_func_02175368.c: prototype of func_02082D44 differs between members (src/matched/ov/ov011_func_02174EAC.c); prototype of func_02082D44 differs between members (src/matched/ov/ov011_func_02174F54.c)
- ov011_func_02174EAC.c..ov011_func_02175368.c: prototype of func_02082D44 differs between members (src/matched/ov/ov011_func_02174F54.c)
- ov011_func_02174EAC.c..ov011_func_02175144.c: prototype of func_02082D44 differs between members (src/matched/ov/ov011_func_02174F54.c)
- ov011_func_02174EAC.c..ov011_func_02174F54.c: prototype of func_02082D44 differs between members (src/matched/ov/ov011_func_02174F54.c)

Members, in address order:

- `ov011_func_021747A8.c`
- `ov011_func_021747F4.c`
- `ov011_func_02174854.c`
- `ov011_func_02174EAC.c`
- `ov011_func_02174F54.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021743B4.c` again.
