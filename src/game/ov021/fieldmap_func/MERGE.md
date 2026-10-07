# fieldmap_func.c (ov021)

Translation unit 021BB578..021BBDD4, 27 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`fieldmap_func.c` is blocked by:

- ov021_func_021BB578.c..ov021_func_021BBD84.c: prototype of func_021AC1CC differs between members (src/matched/ov/ov021_func_021BB648.c)
- ov021_func_021BB578.c..func_021BB954.c: prototype of func_021AC1CC differs between members (src/matched/ov/ov021_func_021BB648.c)
- ov021_func_021BB578.c..ov021_func_021BB68C.c: prototype of func_021AC1CC differs between members (src/matched/ov/ov021_func_021BB648.c)
- ov021_func_021BB60C.c..ov021_func_021BB68C.c: prototype of func_021AC1CC differs between members (src/matched/ov/ov021_func_021BB648.c)
- func_021BB960.c..ov021_func_021BBD84.c: c99=CCERR: line 304: illegal implicit conversion from 'struct Ring_021BBA70 *' to | line 304: 'struct Ring_021BBC58 *' | line 307: illegal implicit conversion from 'struct Ring_021BBA70 *' to nolang=C
- func_021BB960.c..ov021_func_021BBBD8.c: c99=CCERR: line 237: illegal implicit conversion from 'struct Ring_021BBA70 *' to | line 237: 'struct Ring_021BBBD8 *' nolang=CCERR: line 237: illegal implicit conversion from 'struct Ring_021BBA70 *'
- ov021_func_021BBA1C.c..ov021_func_021BBBD8.c: c99=CCERR: line 172: illegal implicit conversion from 'struct Ring_021BBA70 *' to | line 172: 'struct Ring_021BBBD8 *' nolang=CCERR: line 172: illegal implicit conversion from 'struct Ring_021BBA70 *'
- ov021_func_021BBA70.c..ov021_func_021BBBD8.c: c99=CCERR: line 130: illegal implicit conversion from 'struct Ring_021BBA70 *' to | line 130: 'struct Ring_021BBBD8 *' nolang=CCERR: line 130: illegal implicit conversion from 'struct Ring_021BBA70 *'
- ov021_func_021BBC2C.c..ov021_func_021BBD84.c: c99=CCERR: line 122: illegal implicit conversion from 'struct Ring *' to | line 122: 'struct  *' | line 147: illegal implicit conversion from 'unsigned char *' to nolang=CCERR: line 122: illegal impli
- ov021_func_021BBC2C.c..ov021_func_021BBCBC.c: c99=CCERR: line 92: illegal implicit conversion from 'struct Ring *' to | line 92: 'struct  *' nolang=CCERR: line 92: illegal implicit conversion from 'struct Ring *' to | line 92: 'struct  *'
- func_021BBCF8.c..ov021_func_021BBD84.c: c99=CCERR: line 61: illegal implicit conversion from 'unsigned char *' to | line 61: 'struct  *' nolang=CCERR: line 61: illegal implicit conversion from 'unsigned char *' to | line 61: 'struct  *'

Members, in address order:

- `ov021_func_021BB60C.c`
- `ov021_func_021BBA70.c`
- `ov021_func_021BBBD8.c`
- `ov021_func_021BBC2C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names fieldmap_func.c` again.
