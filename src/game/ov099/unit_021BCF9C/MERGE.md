# unit_021BCF9C.c (ov099)

Translation unit 021BCF9C..021BD8D8, 32 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021BCF9C.c` is blocked by:

- func_021BCF9C.c..ov099_func_021BD888.c: prototype of func_020362DC differs between members (src/matched/ov/ov099_func_021BD0BC.c); prototype of func_021BA928 differs between members (src/matched/ov/ov099_func_021BD15C.c); prototype of func_
- func_021BCF9C.c..ov099_func_021BD558.c: prototype of func_020362DC differs between members (src/matched/ov/ov099_func_021BD0BC.c); prototype of func_021BA928 differs between members (src/matched/ov/ov099_func_021BD15C.c); prototype of func_
- func_021BCF9C.c..ov099_func_021BD1A4.c: prototype of func_020362DC differs between members (src/matched/ov/ov099_func_021BD0BC.c); prototype of func_021BA928 differs between members (src/matched/ov/ov099_func_021BD15C.c); prototype of func_
- ov099_func_021BD0BC.c..ov099_func_021BD1A4.c: prototype of func_021BA928 differs between members (src/matched/ov/ov099_func_021BD15C.c); prototype of func_0203D378 differs between members (src/matched/ov/ov099_func_021BD1A4.c)
- ov099_func_021BD318.c..ov099_func_021BD558.c: prototype of func_021BA928 differs between members (src/matched/ov/func_021BD41C.c); prototype of func_021BA928 differs between members (src/matched/ov/ov099_func_021BD4A8.c); prototype of func_021BA9
- ov099_func_021BD318.c..func_021BD41C.c: prototype of func_021BA928 differs between members (src/matched/ov/func_021BD41C.c)
- ov099_func_021BD584.c..ov099_func_021BD888.c: prototype of func_021BA928 differs between members (src/matched/ov/func_021BD5D8.c); prototype of func_02039CB4 differs between members (src/matched/ov/ov099_func_021BD678.c); prototype of func_02039C
- ov099_func_021BD584.c..ov099_func_021BD71C.c: prototype of func_021BA928 differs between members (src/matched/ov/func_021BD5D8.c); prototype of func_02039CB4 differs between members (src/matched/ov/ov099_func_021BD678.c); prototype of func_02039C
- ov099_func_021BD584.c..ov099_func_021BD63C.c: prototype of func_021BA928 differs between members (src/matched/ov/func_021BD5D8.c)
- ov099_func_021BD584.c..func_021BD5D8.c: prototype of func_021BA928 differs between members (src/matched/ov/func_021BD5D8.c)
- func_021BD744.c..ov099_func_021BD888.c: c99=DIFF nolang=DIFF
- func_021BD744.c..ov099_func_021BD7E0.c: c99=DIFF nolang=DIFF
- func_021BD7A0.c..ov099_func_021BD7E0.c: c99=DIFF nolang=DIFF

Members, in address order:

- `ov099_func_021BD584.c`
- `func_021BD5D8.c`
- `func_021BD7A0.c`
- `ov099_func_021BD7E0.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021BCF9C.c` again.
