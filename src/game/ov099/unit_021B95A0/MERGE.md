# unit_021B95A0.c (ov099)

Translation unit 021B95A0..021BA594, 71 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021B95A0.c` is blocked by:

- ov099_func_021B95A0.c..ov099_func_021BA538.c: prototype of func_02082BCC differs between members (src/matched/ov/ov099_func_021B9670.c); prototype of func_020362DC differs between members (src/matched/ov/ov099_func_021B9788.c); prototype of func_
- ov099_func_021B95A0.c..func_021B9D5C.c: prototype of func_02082BCC differs between members (src/matched/ov/ov099_func_021B9670.c); prototype of func_020362DC differs between members (src/matched/ov/ov099_func_021B9788.c); prototype of func_
- ov099_func_021B95A0.c..ov099_func_021B99F4.c: prototype of func_02082BCC differs between members (src/matched/ov/ov099_func_021B9670.c); prototype of func_020362DC differs between members (src/matched/ov/ov099_func_021B9788.c); prototype of func_
- ov099_func_021B95A0.c..ov099_func_021B9800.c: prototype of func_02082BCC differs between members (src/matched/ov/ov099_func_021B9670.c); prototype of func_020362DC differs between members (src/matched/ov/ov099_func_021B9788.c)
- ov099_func_021B9A34.c..func_021B9D5C.c: c99=CCERR: line 225: illegal implicit conversion from 'char *' to | line 225: 'struct  *' | line 254: illegal implicit conversion from 'char *' to nolang=CCERR: line 225: illegal implicit conversion f
- ov099_func_021B9D6C.c..ov099_func_021BA538.c: prototype of func_0204B3DC differs between members (src/matched/ov/ov099_func_021B9F48.c); prototype of func_0204B528 differs between members (src/matched/ov/ov099_func_021B9F90.c); prototype of func_
- ov099_func_021B9D6C.c..ov099_func_021B9F90.c: prototype of func_0204B3DC differs between members (src/matched/ov/ov099_func_021B9F48.c); prototype of func_0204B528 differs between members (src/matched/ov/ov099_func_021B9F90.c); prototype of func_
- func_021B9E08.c..ov099_func_021B9F90.c: prototype of func_0204B3DC differs between members (src/matched/ov/ov099_func_021B9F48.c); prototype of func_0204B528 differs between members (src/matched/ov/ov099_func_021B9F90.c); prototype of func_
- ov099_func_021B9EB8.c..ov099_func_021B9F90.c: prototype of func_0204B3DC differs between members (src/matched/ov/ov099_func_021B9F48.c); prototype of func_0204B528 differs between members (src/matched/ov/ov099_func_021B9F90.c); prototype of func_
- ov099_func_021B9F48.c..ov099_func_021B9F90.c: prototype of func_0204B528 differs between members (src/matched/ov/ov099_func_021B9F90.c); prototype of func_0204B3DC differs between members (src/matched/ov/ov099_func_021B9F90.c)
- ov099_func_021B9FD0.c..ov099_func_021BA538.c: prototype of func_021C4864 differs between members (src/matched/ov/ov099_func_021BA04C.c); prototype of func_021C4864 differs between members (src/matched/ov/ov099_func_021BA0F8.c); prototype of func_
- ov099_func_021B9FD0.c..ov099_func_021BA228.c: prototype of func_021C4864 differs between members (src/matched/ov/ov099_func_021BA04C.c); prototype of func_021C4864 differs between members (src/matched/ov/ov099_func_021BA0F8.c)
- ov099_func_021B9FD0.c..ov099_func_021BA0F8.c: prototype of func_021C4864 differs between members (src/matched/ov/ov099_func_021BA04C.c); prototype of func_021C4864 differs between members (src/matched/ov/ov099_func_021BA0F8.c)
- ov099_func_021BA04C.c..ov099_func_021BA0F8.c: prototype of func_021C4864 differs between members (src/matched/ov/ov099_func_021BA0F8.c)
- func_021BA248.c..ov099_func_021BA538.c: prototype of func_021BA5B4 differs between members (src/matched/ov/ov099_func_021BA2A4.c); prototype of func_021C57D8 differs between members (src/matched/ov/ov099_func_021BA2A4.c); prototype of func_
- func_021BA248.c..ov099_func_021BA2D0.c: prototype of func_021BA5B4 differs between members (src/matched/ov/ov099_func_021BA2A4.c); prototype of func_021C57D8 differs between members (src/matched/ov/ov099_func_021BA2A4.c)

Members, in address order:

- `ov099_func_021B9F48.c`
- `ov099_func_021BA04C.c`
- `ov099_func_021BA0F8.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021B95A0.c` again.
