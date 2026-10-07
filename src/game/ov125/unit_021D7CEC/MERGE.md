# unit_021D7CEC.c (ov125)

Translation unit 021D7CEC..021D8C5C, 40 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021D7CEC.c` is blocked by:

- ov125_func_021D7CEC.c..ov125_func_021D8C14.c: global d_021DA258 declared two ways (src/matched/ov/ov125_func_021D7F60.c); global d_021D9E40 declared two ways (src/matched/ov/ov125_func_021D7FA0.c); global d_021D9E40 declared two ways (src/matched
- ov125_func_021D7CEC.c..ov125_func_021D85E8.c: global d_021DA258 declared two ways (src/matched/ov/ov125_func_021D7F60.c); global d_021D9E40 declared two ways (src/matched/ov/ov125_func_021D7FA0.c); global d_021D9E40 declared two ways (src/matched
- ov125_func_021D7CEC.c..ov125_func_021D7FA0.c: global d_021DA258 declared two ways (src/matched/ov/ov125_func_021D7F60.c); global d_021D9E40 declared two ways (src/matched/ov/ov125_func_021D7FA0.c)
- ov125_func_021D7CEC.c..ov125_func_021D7D30.c: c99=DIFF nolang=DIFF
- ov125_func_021D7D20.c..ov125_func_021D7D30.c: c99=DIFF nolang=DIFF
- ov125_func_021D7D88.c..ov125_func_021D7FA0.c: global d_021DA258 declared two ways (src/matched/ov/ov125_func_021D7F60.c); global d_021D9E40 declared two ways (src/matched/ov/ov125_func_021D7FA0.c)
- ov125_func_021D7E80.c..ov125_func_021D7FA0.c: global d_021DA258 declared two ways (src/matched/ov/ov125_func_021D7F60.c); global d_021D9E40 declared two ways (src/matched/ov/ov125_func_021D7FA0.c)
- ov125_func_021D7F60.c..ov125_func_021D7FA0.c: global d_021D9E40 declared two ways (src/matched/ov/ov125_func_021D7FA0.c)
- ov125_func_021D80E0.c..ov125_func_021D85E8.c: global d_021D9E40 declared two ways (src/matched/ov/ov125_func_021D8444.c)
- ov125_func_021D80E0.c..ov125_func_021D8588.c: global d_021D9E40 declared two ways (src/matched/ov/ov125_func_021D8444.c)
- ov125_func_021D858C.c..ov125_func_021D85E8.c: c99=DIFF nolang=DIFF
- ov125_func_021D85B4.c..ov125_func_021D85E8.c: c99=DIFF nolang=DIFF
- ov125_func_021D85C0.c..ov125_func_021D85E8.c: c99=DIFF nolang=DIFF
- ov125_func_021D85F4.c..ov125_func_021D8C14.c: global d_021DAAAC declared two ways (src/matched/ov/ov125_func_021D8BC0.c); global d_021DAA88 declared two ways (src/matched/ov/ov125_func_021D8C14.c)
- ov125_func_021D88BC.c..ov125_func_021D8C14.c: global d_021DAAAC declared two ways (src/matched/ov/ov125_func_021D8BC0.c); global d_021DAA88 declared two ways (src/matched/ov/ov125_func_021D8C14.c)
- ov125_func_021D8B44.c..ov125_func_021D8C14.c: global d_021DAAAC declared two ways (src/matched/ov/ov125_func_021D8BC0.c); global d_021DAA88 declared two ways (src/matched/ov/ov125_func_021D8C14.c)
- ov125_func_021D8BE4.c..ov125_func_021D8C14.c: global d_021DAA88 declared two ways (src/matched/ov/ov125_func_021D8C14.c)
- ov125_func_021D8BF8.c..ov125_func_021D8C14.c: global d_021DAA88 declared two ways (src/matched/ov/ov125_func_021D8C14.c)
- no verified entry for 021D7D24, 021D85DC

Members, in address order:

- `ov125_func_021D7D20.c`
- `ov125_func_021D7D30.c`
- `ov125_func_021D7E80.c`
- `ov125_func_021D7F60.c`
- `ov125_func_021D7FA0.c`
- `ov125_func_021D85B4.c`
- `ov125_func_021D85C0.c`
- `ov125_func_021D85E8.c`
- `ov125_func_021D8BE4.c`
- `ov125_func_021D8BF8.c`
- `ov125_func_021D8C14.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021D7CEC.c` again.
