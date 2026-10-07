# save_control_intr.c (ov088)

Translation unit 021BC2FC..021BD3B8, 54 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`save_control_intr.c` is blocked by:

- ov088_func_021BC2FC.c..ov088_func_021BD3A0.c: prototype of func_0200854C differs between members (src/matched/ov/ov088_func_021BC568.c); prototype of func_02040588 differs between members (src/matched/ov/ov088_func_021BC9E8.c); global d_021BDA20 
- ov088_func_021BC2FC.c..ov088_func_021BCE3C.c: prototype of func_0200854C differs between members (src/matched/ov/ov088_func_021BC568.c); prototype of func_02040588 differs between members (src/matched/ov/ov088_func_021BC9E8.c)
- ov088_func_021BC2FC.c..ov088_func_021BC870.c: prototype of func_0200854C differs between members (src/matched/ov/ov088_func_021BC568.c)
- ov088_func_021BCE70.c..ov088_func_021BD3A0.c: global d_021BDA20 declared two ways (src/matched/ov/ov088_func_021BCE80.c); prototype of func_02007214 differs between members (src/matched/ov/ov088_func_021BD2F4.c); prototype of func_0200721C differ
- ov088_func_021BD118.c..ov088_func_021BD3A0.c: prototype of func_02007214 differs between members (src/matched/ov/ov088_func_021BD2F4.c); prototype of func_0200721C differs between members (src/matched/ov/ov088_func_021BD2F4.c)
- ov088_func_021BD2B0.c..ov088_func_021BD3A0.c: prototype of func_02007214 differs between members (src/matched/ov/ov088_func_021BD2F4.c); prototype of func_0200721C differs between members (src/matched/ov/ov088_func_021BD2F4.c)
- ov088_func_021BD2B0.c..ov088_func_021BD368.c: prototype of func_02007214 differs between members (src/matched/ov/ov088_func_021BD2F4.c); prototype of func_0200721C differs between members (src/matched/ov/ov088_func_021BD2F4.c)

Members, in address order:

- `ov088_func_021BD2B0.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names save_control_intr.c` again.
