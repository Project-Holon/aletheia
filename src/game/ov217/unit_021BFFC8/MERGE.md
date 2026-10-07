# unit_021BFFC8.c (ov217)

Translation unit 021BFFC8..021C05B0, 26 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021BFFC8.c` is blocked by:

- ov217_func_021BFFC8.c..ov217_func_021C04FC.c: global d_021C37A4 declared two ways (src/matched/ov/ov217_func_021C04FC.c)
- ov217_func_021C0250.c..ov217_func_021C04FC.c: global d_021C37A4 declared two ways (src/matched/ov/ov217_func_021C04FC.c)
- ov217_func_021C03D0.c..ov217_func_021C04FC.c: global d_021C37A4 declared two ways (src/matched/ov/ov217_func_021C04FC.c)
- ov217_func_021C0494.c..ov217_func_021C04FC.c: global d_021C37A4 declared two ways (src/matched/ov/ov217_func_021C04FC.c)
- ov217_func_021C04CC.c..ov217_func_021C04FC.c: global d_021C37A4 declared two ways (src/matched/ov/ov217_func_021C04FC.c)

Members, in address order:

- `ov217_func_021C04CC.c`
- `ov217_func_021C04FC.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021BFFC8.c` again.
