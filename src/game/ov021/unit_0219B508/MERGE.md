# unit_0219B508.c (ov021)

Translation unit 0219B508..0219C4AC, 56 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_0219B508.c` is blocked by:

- ov021_func_0219B508.c..ov021_func_0219C338.c: prototype of func_0216DAE0 differs between members (src/matched/ov/ov021_func_0219B8E8.c); prototype of func_0216DA50 differs between members (src/matched/ov/ov021_func_0219B924.c); prototype of func_
- ov021_func_0219B508.c..ov021_func_0219BDC4.c: prototype of func_0216DAE0 differs between members (src/matched/ov/ov021_func_0219B8E8.c); prototype of func_0216DA50 differs between members (src/matched/ov/ov021_func_0219B924.c); prototype of func_
- ov021_func_0219B508.c..ov021_func_0219B9D8.c: prototype of func_0216DAE0 differs between members (src/matched/ov/ov021_func_0219B8E8.c); prototype of func_0216DA50 differs between members (src/matched/ov/ov021_func_0219B924.c)
- func_0219B8BC.c..ov021_func_0219B9D8.c: prototype of func_0216DAE0 differs between members (src/matched/ov/ov021_func_0219B8E8.c); prototype of func_0216DA50 differs between members (src/matched/ov/ov021_func_0219B924.c)
- func_0219B8BC.c..ov021_func_0219B924.c: prototype of func_0216DAE0 differs between members (src/matched/ov/ov021_func_0219B8E8.c); prototype of func_0216DA50 differs between members (src/matched/ov/ov021_func_0219B924.c)
- ov021_func_0219B8E8.c..ov021_func_0219B924.c: c99=DIFF nolang=DIFF
- ov021_func_0219BA0C.c..ov021_func_0219BDC4.c: prototype of func_0216D69C differs between members (src/matched/ov/ov021_func_0219BB3C.c); prototype of func_0216DA50 differs between members (src/matched/ov/func_0219BB84.c); prototype of func_02197E
- ov021_func_0219BA0C.c..ov021_func_0219BB48.c: prototype of func_0216D69C differs between members (src/matched/ov/ov021_func_0219BB3C.c)
- ov021_func_0219BAE0.c..ov021_func_0219BB48.c: prototype of func_0216D69C differs between members (src/matched/ov/ov021_func_0219BB3C.c)
- ov021_func_0219BE3C.c..ov021_func_0219C338.c: prototype of func_0216D69C differs between members (src/matched/ov/ov021_func_0219BF3C.c); prototype of func_0216D69C differs between members (src/matched/ov/ov021_func_0219BF54.c); prototype of func_
- ov021_func_0219BE3C.c..ov021_func_0219C04C.c: prototype of func_0216D69C differs between members (src/matched/ov/ov021_func_0219BF3C.c); prototype of func_0216D69C differs between members (src/matched/ov/ov021_func_0219BF54.c); prototype of func_
- ov021_func_0219BE3C.c..ov021_func_0219BF3C.c: prototype of func_0216D69C differs between members (src/matched/ov/ov021_func_0219BF3C.c)
- func_0219BF48.c..ov021_func_0219C04C.c: prototype of func_0216D69C differs between members (src/matched/ov/ov021_func_0219BF54.c); prototype of func_0216DA50 differs between members (src/matched/ov/ov021_func_0219C04C.c); prototype of func_
- func_0219BF48.c..ov021_func_0219BF60.c: prototype of func_0216D69C differs between members (src/matched/ov/ov021_func_0219BF54.c)
- ov021_func_0219BFDC.c..ov021_func_0219C04C.c: prototype of func_0216DA50 differs between members (src/matched/ov/ov021_func_0219C04C.c); prototype of func_0216DA7C differs between members (src/matched/ov/ov021_func_0219C04C.c)
- func_0219C080.c..ov021_func_0219C338.c: prototype of func_0216DA50 differs between members (src/matched/ov/ov021_func_0219C13C.c)
- func_0219C080.c..func_0219C164.c: prototype of func_0216DA50 differs between members (src/matched/ov/ov021_func_0219C13C.c)
- ov021_func_0219C118.c..func_0219C164.c: prototype of func_0216DA50 differs between members (src/matched/ov/func_0219C164.c)

Members, in address order:

- `func_0219B8BC.c`
- `ov021_func_0219B8E8.c`
- `ov021_func_0219B924.c`
- `func_0219BF48.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_0219B508.c` again.
