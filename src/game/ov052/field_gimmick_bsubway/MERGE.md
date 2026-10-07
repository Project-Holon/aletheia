# field_gimmick_bsubway.c (ov052)

Translation unit 021F36C0..021F3998, 9 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`field_gimmick_bsubway.c` is blocked by:

- ov052_func_021F36C0.c..ov052_func_021F38F0.c: prototype of func_0200B3A4 differs between members (src/matched/ov/ov052_func_021F37C0.c); prototype of func_0200B3A4 differs between members (src/matched/ov/ov052_func_021F380C.c)
- ov052_func_021F36C0.c..ov052_func_021F37C0.c: prototype of func_0200B3A4 differs between members (src/matched/ov/ov052_func_021F37C0.c)
- ov052_func_021F3770.c..ov052_func_021F37C0.c: prototype of func_0200B3A4 differs between members (src/matched/ov/ov052_func_021F37C0.c)
- ov052_func_021F380C.c..ov052_func_021F38F0.c: prototype of func_0200B3A4 differs between members (src/matched/ov/ov052_func_021F388C.c)

Members, in address order:

- `ov052_func_021F3770.c`
- `ov052_func_021F37C0.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names field_gimmick_bsubway.c` again.
