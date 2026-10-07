# scrcmd_proc_fld.c (ov021)

Translation unit 021B3158..021B5700, 87 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`scrcmd_proc_fld.c` is blocked by:

- ov021_func_021B3158.c..ov021_func_021B568C.c: prototype of func_0201F81C differs between members (src/matched/ov/ov021_func_021B39C4.c); prototype of func_0201C7D0 differs between members (src/matched/ov/ov021_func_021B40D4.c); prototype of func_
- ov021_func_021B3158.c..ov021_func_021B4918.c: prototype of func_0201F81C differs between members (src/matched/ov/ov021_func_021B39C4.c); prototype of func_0201C7D0 differs between members (src/matched/ov/ov021_func_021B40D4.c); prototype of func_
- ov021_func_021B3158.c..ov021_func_021B3CFC.c: prototype of func_0201F81C differs between members (src/matched/ov/ov021_func_021B39C4.c)
- ov021_func_021B3158.c..ov021_func_021B3834.c: c99=CCERR: line 361: illegal implicit conversion from 'char *' to | line 361: 'unsigned char *' nolang=CCERR: line 361: illegal implicit conversion from 'char *' to | line 361: 'unsigned char *'
- ov021_func_021B3158.c..ov021_func_021B3370.c: c99=CCERR: line 264: illegal implicit conversion from 'char *' to | line 264: 'unsigned char *' nolang=CCERR: line 264: illegal implicit conversion from 'char *' to | line 264: 'unsigned char *'
- ov021_func_021B331C.c..ov021_func_021B3370.c: c99=CCERR: line 79: illegal implicit conversion from 'char *' to | line 79: 'unsigned char *' nolang=CCERR: line 79: illegal implicit conversion from 'char *' to | line 79: 'unsigned char *'
- ov021_func_021B3350.c..ov021_func_021B3370.c: c99=CCERR: line 63: illegal implicit conversion from 'char *' to | line 63: 'unsigned char *' nolang=CCERR: line 63: illegal implicit conversion from 'char *' to | line 63: 'unsigned char *'
- ov021_func_021B3D60.c..ov021_func_021B4918.c: prototype of func_0201C7D0 differs between members (src/matched/ov/ov021_func_021B40D4.c); prototype of func_0201C7D0 differs between members (src/matched/ov/ov021_func_021B41AC.c); prototype of func_
- ov021_func_021B44CC.c..ov021_func_021B4918.c: prototype of func_0201F73C differs between members (src/matched/ov/func_021B4878.c); prototype of func_0201CD10 differs between members (src/matched/ov/ov021_func_021B4894.c)
- func_021B4710.c..ov021_func_021B4918.c: prototype of func_0201F73C differs between members (src/matched/ov/func_021B4878.c); prototype of func_0201CD10 differs between members (src/matched/ov/ov021_func_021B4894.c)

Members, in address order:

- `ov021_func_021B331C.c`
- `ov021_func_021B3350.c`
- `ov021_func_021B3370.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names scrcmd_proc_fld.c` again.
