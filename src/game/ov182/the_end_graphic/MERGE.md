# the_end_graphic.c (ov182)

Translation unit 021B95A0..021B9B8C, 21 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`the_end_graphic.c` is blocked by:

- ov182_func_021B95A0.c..ov182_func_021B9B20.c: prototype of func_020056A0 differs between members (src/matched/ov/ov182_func_021B98E4.c); global d_021B9C78 declared two ways (src/matched/ov/ov182_func_021B9A70.c); prototype of func_02082BCC differ
- ov182_func_021B95A0.c..ov182_func_021B998C.c: prototype of func_020056A0 differs between members (src/matched/ov/ov182_func_021B98E4.c)
- ov182_func_021B99E8.c..ov182_func_021B9B20.c: global d_021B9C78 declared two ways (src/matched/ov/ov182_func_021B9A70.c); prototype of func_02082BCC differs between members (src/matched/ov/ov182_func_021B9A70.c); prototype of func_02082BCC differ
- ov182_func_021B9AAC.c..ov182_func_021B9B20.c: prototype of func_02082BCC differs between members (src/matched/ov/ov182_func_021B9AF4.c)
- ov182_func_021B9AAC.c..ov182_func_021B9AF4.c: prototype of func_02082BCC differs between members (src/matched/ov/ov182_func_021B9AF4.c)
- ov182_func_021B9AB4.c..ov182_func_021B9AF4.c: prototype of func_02082BCC differs between members (src/matched/ov/ov182_func_021B9AF4.c)

Members, in address order:

- `ov182_func_021B9AAC.c`
- `ov182_func_021B9AB4.c`
- `ov182_func_021B9AF4.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names the_end_graphic.c` again.
