# unit_021F36C0.c (ov039)

Translation unit 021F36C0..021F4A18, 25 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021F36C0.c` is blocked by:

- ov039_func_021F36C0.c..ov039_func_021F4928.c: prototype of func_021897BC differs between members (src/matched/ov/ov039_func_021F3CD8.c); prototype of func_02188C80 differs between members (src/matched/ov/ov039_func_021F3CD8.c); prototype of func_
- ov039_func_021F36C0.c..ov039_func_021F3E24.c: prototype of func_021897BC differs between members (src/matched/ov/ov039_func_021F3CD8.c); prototype of func_02188C80 differs between members (src/matched/ov/ov039_func_021F3CD8.c); prototype of func_
- ov039_func_021F36C0.c..ov039_func_021F3D74.c: prototype of func_021897BC differs between members (src/matched/ov/ov039_func_021F3CD8.c); prototype of func_02188C80 differs between members (src/matched/ov/ov039_func_021F3CD8.c); prototype of func_
- ov039_func_021F36C0.c..ov039_func_021F3A34.c: c99=DIFF nolang=DIFF
- ov039_func_021F36F0.c..ov039_func_021F3A34.c: c99=DIFF nolang=DIFF
- ov039_func_021F3CD8.c..ov039_func_021F3D74.c: prototype of func_021897BC differs between members (src/matched/ov/ov039_func_021F3D1C.c)
- ov039_func_021F3E70.c..ov039_func_021F4928.c: prototype of func_021897BC differs between members (src/matched/ov/ov039_func_021F404C.c); prototype of func_02188C80 differs between members (src/matched/ov/ov039_func_021F4134.c); prototype of func_
- ov039_func_021F3E70.c..ov039_func_021F41A8.c: prototype of func_021897BC differs between members (src/matched/ov/ov039_func_021F404C.c); prototype of func_02188C80 differs between members (src/matched/ov/ov039_func_021F4134.c); prototype of func_
- ov039_func_021F3E70.c..ov039_func_021F4134.c: prototype of func_021897BC differs between members (src/matched/ov/ov039_func_021F404C.c); prototype of func_02188C80 differs between members (src/matched/ov/ov039_func_021F4134.c)
- ov039_func_021F404C.c..ov039_func_021F4134.c: prototype of func_02188C80 differs between members (src/matched/ov/ov039_func_021F4134.c)
- ov039_func_021F4610.c..ov039_func_021F4928.c: prototype of func_021897BC differs between members (src/matched/ov/ov039_func_021F4740.c); prototype of func_02188C80 differs between members (src/matched/ov/ov039_func_021F4740.c)
- ov039_func_021F4610.c..ov039_func_021F47D8.c: prototype of func_021897BC differs between members (src/matched/ov/ov039_func_021F4740.c); prototype of func_02188C80 differs between members (src/matched/ov/ov039_func_021F4740.c)

Members, in address order:

- `ov039_func_021F36C0.c`
- `ov039_func_021F36F0.c`
- `ov039_func_021F3A34.c`
- `ov039_func_021F3CD8.c`
- `ov039_func_021F3E70.c`
- `ov039_func_021F404C.c`
- `ov039_func_021F4134.c`
- `ov039_func_021F4610.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021F36C0.c` again.
