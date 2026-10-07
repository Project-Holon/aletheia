# unit_021F36C0.c (ov056)

Translation unit 021F36C0..021F3E94, 26 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021F36C0.c` is blocked by:

- ov056_func_021F36C0.c..ov056_func_021F3E54.c: prototype of func_0218ECD4 differs between members (src/matched/ov/ov056_func_021F3A14.c); prototype of func_02048AE8 differs between members (src/matched/ov/ov056_func_021F3AB0.c); prototype of func_
- ov056_func_021F36C0.c..ov056_func_021F3A78.c: prototype of func_0218ECD4 differs between members (src/matched/ov/ov056_func_021F3A14.c)
- ov056_func_021F3890.c..ov056_func_021F3A78.c: prototype of func_0218ECD4 differs between members (src/matched/ov/ov056_func_021F3A14.c)
- ov056_func_021F3918.c..ov056_func_021F3A78.c: prototype of func_0218ECD4 differs between members (src/matched/ov/ov056_func_021F3A14.c)
- ov056_func_021F3AB0.c..ov056_func_021F3E54.c: global d_021F426C declared two ways (src/matched/ov/ov056_func_021F3B10.c)
- ov056_func_021F3AB0.c..ov056_func_021F3CC4.c: global d_021F426C declared two ways (src/matched/ov/ov056_func_021F3B10.c)
- ov056_func_021F3AB0.c..ov056_func_021F3BF0.c: global d_021F426C declared two ways (src/matched/ov/ov056_func_021F3B10.c)
- ov056_func_021F3D2C.c..ov056_func_021F3E54.c: c99=DIFF nolang=DIFF
- ov056_func_021F3D2C.c..ov056_func_021F3D9C.c: c99=DIFF nolang=DIFF

Members, in address order:

- `ov056_func_021F3AB0.c`
- `ov056_func_021F3D2C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021F36C0.c` again.
