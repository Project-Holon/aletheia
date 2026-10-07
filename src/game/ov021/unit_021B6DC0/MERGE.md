# unit_021B6DC0.c (ov021)

Translation unit 021B6DC0..021B7364, 21 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021B6DC0.c` is blocked by:

- ov021_func_021B6DC0.c..ov021_func_021B72CC.c: global d_021D99D0 declared two ways (src/matched/ov/ov021_func_021B721C.c); global d_021D99D0 declared two ways (src/matched/ov/ov021_func_021B72CC.c)
- ov021_func_021B6F88.c..ov021_func_021B72CC.c: global d_021D99D0 declared two ways (src/matched/ov/ov021_func_021B721C.c); global d_021D99D0 declared two ways (src/matched/ov/ov021_func_021B72CC.c)
- ov021_func_021B6F88.c..func_021B7068.c: c99=DIFF nolang=DIFF
- ov021_func_021B6F88.c..ov021_func_021B6FF0.c: c99=DIFF nolang=DIFF
- func_021B7080.c..ov021_func_021B72CC.c: global d_021D99D0 declared two ways (src/matched/ov/ov021_func_021B721C.c); global d_021D99D0 declared two ways (src/matched/ov/ov021_func_021B72CC.c)
- func_021B7080.c..ov021_func_021B70D8.c: c99=DIFF nolang=DIFF
- ov021_func_021B709C.c..ov021_func_021B70D8.c: c99=DIFF nolang=DIFF
- ov021_func_021B716C.c..ov021_func_021B72CC.c: global d_021D99D0 declared two ways (src/matched/ov/ov021_func_021B721C.c); global d_021D99D0 declared two ways (src/matched/ov/ov021_func_021B72CC.c)

Members, in address order:

- `ov021_func_021B6F88.c`
- `ov021_func_021B6FF0.c`
- `func_021B7080.c`
- `ov021_func_021B709C.c`
- `ov021_func_021B70D8.c`
- `ov021_func_021B716C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021B6DC0.c` again.
