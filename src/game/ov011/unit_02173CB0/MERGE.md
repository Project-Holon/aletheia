# unit_02173CB0.c (ov011)

Translation unit 02173CB0..021743B4, 25 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_02173CB0.c` is blocked by:

- ov011_func_02173CB0.c..ov011_func_02174374.c: prototype of func_02082D44 differs between members (src/matched/ov/ov011_func_02173EEC.c); prototype of func_0203D3F8 differs between members (src/matched/ov/ov011_func_021740AC.c); prototype of func_
- ov011_func_02173CB0.c..ov011_func_02173F74.c: prototype of func_02082D44 differs between members (src/matched/ov/ov011_func_02173EEC.c)
- ov011_func_02173E2C.c..ov011_func_02173F74.c: c99=DIFF nolang=DIFF
- ov011_func_02173E2C.c..ov011_func_02173EB8.c: c99=DIFF nolang=DIFF
- ov011_func_02173F9C.c..ov011_func_02174374.c: prototype of func_0203D3F8 differs between members (src/matched/ov/ov011_func_021741E8.c); prototype of func_0203D3F8 differs between members (src/matched/ov/ov011_func_02174258.c); prototype of func_
- ov011_func_02173F9C.c..ov011_func_021740AC.c: c99=DIFF nolang=DIFF
- ov011_func_0217403C.c..ov011_func_021740AC.c: c99=DIFF nolang=DIFF
- ov011_func_0217405C.c..ov011_func_021740AC.c: c99=DIFF nolang=DIFF
- ov011_func_0217410C.c..ov011_func_02174374.c: prototype of func_02082D44 differs between members (src/matched/ov/ov011_func_02174320.c)
- ov011_func_0217410C.c..ov011_func_02174258.c: c99=DIFF nolang=DIFF
- ov011_func_021741E8.c..ov011_func_02174258.c: c99=DIFF nolang=DIFF
- ov011_func_021742A8.c..ov011_func_02174374.c: c99=DIFF nolang=DIFF
- ov011_func_021742A8.c..ov011_func_021742EC.c: c99=DIFF nolang=DIFF

Members, in address order:

- `ov011_func_02173E2C.c`
- `ov011_func_0217403C.c`
- `ov011_func_0217405C.c`
- `ov011_func_021740AC.c`
- `ov011_func_0217410C.c`
- `ov011_func_021741E8.c`
- `ov011_func_02174258.c`
- `ov011_func_021742A8.c`
- `ov011_func_021742EC.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_02173CB0.c` again.
