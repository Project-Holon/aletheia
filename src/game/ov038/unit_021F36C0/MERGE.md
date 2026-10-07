# unit_021F36C0.c (ov038)

Translation unit 021F36C0..021F44C0, 14 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021F36C0.c` is blocked by:

- ov038_func_021F36C0.c..ov038_func_021F42BC.c: prototype of func_021897BC differs between members (src/matched/ov/ov038_func_021F3A88.c); prototype of func_02188C80 differs between members (src/matched/ov/ov038_func_021F3A88.c); prototype of func_
- ov038_func_021F36C0.c..ov038_func_021F3DFC.c: prototype of func_021897BC differs between members (src/matched/ov/ov038_func_021F3A88.c); prototype of func_02188C80 differs between members (src/matched/ov/ov038_func_021F3A88.c); prototype of func_
- ov038_func_021F3A08.c..ov038_func_021F3DFC.c: prototype of func_021897BC differs between members (src/matched/ov/ov038_func_021F3B3C.c); prototype of func_02188CB4 differs between members (src/matched/ov/ov038_func_021F3B3C.c); prototype of func_
- ov038_func_021F3F40.c..ov038_func_021F42BC.c: prototype of func_021897BC differs between members (src/matched/ov/ov038_func_021F407C.c); prototype of func_021BE480 differs between members (src/matched/ov/ov038_func_021F407C.c); prototype of func_
- ov038_func_021F3F40.c..ov038_func_021F4184.c: prototype of func_021897BC differs between members (src/matched/ov/ov038_func_021F407C.c); prototype of func_021BE480 differs between members (src/matched/ov/ov038_func_021F407C.c)
- ov038_func_021F41B0.c..ov038_func_021F42BC.c: prototype of func_021897BC differs between members (src/matched/ov/ov038_func_021F42BC.c)
- ov038_func_021F4200.c..ov038_func_021F42BC.c: prototype of func_021897BC differs between members (src/matched/ov/ov038_func_021F42BC.c)

Members, in address order:

- `ov038_func_021F3F40.c`
- `ov038_func_021F4200.c`
- `ov038_func_021F42BC.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021F36C0.c` again.
