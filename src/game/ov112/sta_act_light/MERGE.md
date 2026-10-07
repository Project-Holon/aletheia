# sta_act_light.c (ov112)

Translation unit 021F6BC0..021F8154, 52 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`sta_act_light.c` is blocked by:

- ov112_func_021F6BC0.c..ov112_func_021F8140.c: prototype of func_020307B0 differs between members (src/matched/ov/ov112_func_021F6F4C.c); prototype of func_020307B0 differs between members (src/matched/ov/ov112_func_021F7120.c); global table decla
- ov112_func_021F6BC0.c..ov112_func_021F7204.c: prototype of func_020307B0 differs between members (src/matched/ov/ov112_func_021F6F4C.c); prototype of func_020307B0 differs between members (src/matched/ov/ov112_func_021F7120.c)
- ov112_func_021F6F1C.c..ov112_func_021F7204.c: c99=CCERR: line 153: illegal implicit conversion from 'unsigned char *' to | line 153: 'struct  *' nolang=CCERR: line 153: illegal implicit conversion from 'unsigned char *' to | line 153: 'struct  *'
- ov112_func_021F6F1C.c..ov112_func_021F6FB0.c: prototype of func_021F7048 differs between members (src/matched/ov/ov112_func_021F6FB0.c)
- ov112_func_021F732C.c..ov112_func_021F8140.c: prototype of func_021F4EB4 differs between members (src/matched/ov/ov112_func_021F760C.c); prototype of func_021F5450 differs between members (src/matched/ov/ov112_func_021F7AEC.c); prototype of func_
- ov112_func_021F732C.c..ov112_func_021F7D30.c: prototype of func_021F4EB4 differs between members (src/matched/ov/ov112_func_021F760C.c); prototype of func_021F5450 differs between members (src/matched/ov/ov112_func_021F7AEC.c); prototype of func_
- ov112_func_021F77EC.c..ov112_func_021F7D30.c: prototype of func_021F5450 differs between members (src/matched/ov/ov112_func_021F7BA8.c); prototype of func_0207C9D0 differs between members (src/matched/ov/ov112_func_021F7BA8.c); prototype of func_
- ov112_func_021F7AEC.c..ov112_func_021F7D30.c: prototype of func_021F5450 differs between members (src/matched/ov/ov112_func_021F7BA8.c); prototype of func_0207C9D0 differs between members (src/matched/ov/ov112_func_021F7BA8.c); prototype of func_
- ov112_func_021F7AEC.c..ov112_func_021F7BA8.c: prototype of func_021F5450 differs between members (src/matched/ov/ov112_func_021F7BA8.c); prototype of func_0207C9D0 differs between members (src/matched/ov/ov112_func_021F7BA8.c)
- ov112_func_021F7C90.c..ov112_func_021F7D30.c: prototype of func_021F4E8C differs between members (src/matched/ov/ov112_func_021F7D30.c)
- ov112_func_021F7E2C.c..ov112_func_021F8140.c: prototype of func_021F4E8C differs between members (src/matched/ov/ov112_func_021F7ECC.c); prototype of func_021F4EB4 differs between members (src/matched/ov/ov112_func_021F7ECC.c); prototype of func_
- ov112_func_021F7E2C.c..ov112_func_021F8068.c: prototype of func_021F4E8C differs between members (src/matched/ov/ov112_func_021F7ECC.c); prototype of func_021F4EB4 differs between members (src/matched/ov/ov112_func_021F7ECC.c); prototype of func_
- ov112_func_021F7E2C.c..ov112_func_021F7FAC.c: prototype of func_021F4E8C differs between members (src/matched/ov/ov112_func_021F7ECC.c); prototype of func_021F4EB4 differs between members (src/matched/ov/ov112_func_021F7ECC.c); prototype of func_

Members, in address order:

- `ov112_func_021F7AEC.c`
- `ov112_func_021F7BA8.c`
- `ov112_func_021F7C90.c`
- `ov112_func_021F7D30.c`
- `ov112_func_021F7E2C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names sta_act_light.c` again.
