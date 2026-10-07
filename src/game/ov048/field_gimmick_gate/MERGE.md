# field_gimmick_gate.c (ov048)

Translation unit 021F36C0..021F3D24, 27 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`field_gimmick_gate.c` is blocked by:

- ov048_func_021F36C0.c..ov048_func_021F3CB0.c: prototype of func_020142E8 differs between members (src/matched/ov/ov048_func_021F3C2C.c)
- ov048_func_021F36C0.c..ov048_func_021F3908.c: c99=CCERR: line 189: illegal implicit conversion from 'unsigned char *' to | line 189: 'char *' nolang=CCERR: line 189: illegal implicit conversion from 'unsigned char *' to | line 189: 'char *'
- ov048_func_021F37FC.c..ov048_func_021F3908.c: prototype of func_021F37A4 differs between members (src/matched/ov/ov048_func_021F3830.c)
- ov048_func_021F37FC.c..ov048_func_021F3830.c: prototype of func_021F37A4 differs between members (src/matched/ov/ov048_func_021F3830.c)
- ov048_func_021F392C.c..ov048_func_021F3CB0.c: prototype of func_020142E8 differs between members (src/matched/ov/ov048_func_021F3C2C.c)
- ov048_func_021F3AB4.c..ov048_func_021F3CB0.c: prototype of func_020142E8 differs between members (src/matched/ov/ov048_func_021F3C2C.c)
- ov048_func_021F3BC0.c..ov048_func_021F3CB0.c: prototype of func_020142E8 differs between members (src/matched/ov/ov048_func_021F3CB0.c)
- ov048_func_021F3C2C.c..ov048_func_021F3CB0.c: prototype of func_020142E8 differs between members (src/matched/ov/ov048_func_021F3CB0.c)

Members, in address order:

- `ov048_func_021F37FC.c`
- `ov048_func_021F3C2C.c`
- `ov048_func_021F3CB0.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names field_gimmick_gate.c` again.
