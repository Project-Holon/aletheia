# box2_ui.c (ov170)

Translation unit 021ED824..021EF770, 126 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`box2_ui.c` is blocked by:

- ov170_func_021ED824.c..func_021EF75C.c: prototype of func_02025774 differs between members (src/matched/ov/func_021EE224.c); global d_021F02F0 declared two ways (src/matched/ov/ov170_func_021EE364.c)
- ov170_func_021ED824.c..func_021EEC1C.c: prototype of func_02025774 differs between members (src/matched/ov/func_021EE224.c); global d_021F02F0 declared two ways (src/matched/ov/ov170_func_021EE364.c)
- ov170_func_021ED824.c..func_021EE3CC.c: prototype of func_02025774 differs between members (src/matched/ov/func_021EE224.c); global d_021F02F0 declared two ways (src/matched/ov/ov170_func_021EE364.c)
- ov170_func_021EDD38.c..func_021EE3CC.c: prototype of func_02025774 differs between members (src/matched/ov/func_021EE224.c); global d_021F02F0 declared two ways (src/matched/ov/ov170_func_021EE364.c)
- ov170_func_021EE3E4.c..func_021EEC1C.c: c99=DIFF nolang=DIFF
- ov170_func_021EE3E4.c..func_021EE7C4.c: c99=DIFF nolang=DIFF
- ov170_func_021EE3E4.c..func_021EE520.c: c99=DIFF nolang=DIFF
- ov170_func_021EE3E4.c..func_021EE43C.c: c99=DIFF nolang=DIFF
- func_021EE418.c..func_021EE43C.c: c99=DIFF nolang=DIFF
- func_021EE454.c..func_021EE520.c: c99=DIFF nolang=DIFF
- func_021EE454.c..ov170_func_021EE474.c: c99=DIFF nolang=DIFF

Members, in address order:

- `func_021EE418.c`
- `func_021EE43C.c`
- `func_021EE454.c`
- `ov170_func_021EE474.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names box2_ui.c` again.
