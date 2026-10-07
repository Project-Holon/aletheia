# unit_021F0680.c (ov031)

Translation unit 021F0680..021F0FE0, 18 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021F0680.c` is blocked by:

- ov031_func_021F0680.c..ov031_func_021F0F68.c: prototype of func_02082D44 differs between members (src/matched/ov/ov031_func_021F0A04.c); prototype of func_021BBC2C differs between members (src/matched/ov/ov031_func_021F0A04.c); prototype of func_
- ov031_func_021F0680.c..ov031_func_021F0CEC.c: prototype of func_02082D44 differs between members (src/matched/ov/ov031_func_021F0A04.c); prototype of func_021BBC2C differs between members (src/matched/ov/ov031_func_021F0A04.c); prototype of func_
- ov031_func_021F0680.c..ov031_func_021F0A04.c: prototype of func_02082D44 differs between members (src/matched/ov/ov031_func_021F0A04.c); prototype of func_021BBC2C differs between members (src/matched/ov/ov031_func_021F0A04.c)
- ov031_func_021F0680.c..ov031_func_021F07AC.c: c99=CCERR: line 170: illegal implicit conversion from 'struct Obj_021F0680 *' to | line 170: 'struct Obj_021F07AC *' nolang=CCERR: line 170: illegal implicit conversion from 'struct Obj_021F0680 *' to
- ov031_func_021F09A0.c..ov031_func_021F0A04.c: prototype of func_021BBC2C differs between members (src/matched/ov/ov031_func_021F0A04.c); prototype of func_021F07AC differs between members (src/matched/ov/ov031_func_021F0A04.c)
- ov031_func_021F0AA0.c..ov031_func_021F0CEC.c: prototype of func_021F0D40 differs between members (src/matched/ov/ov031_func_021F0CEC.c)
- ov031_func_021F0C34.c..ov031_func_021F0CEC.c: prototype of func_021F0D40 differs between members (src/matched/ov/ov031_func_021F0CEC.c)
- ov031_func_021F0C60.c..ov031_func_021F0CEC.c: prototype of func_021F0D40 differs between members (src/matched/ov/ov031_func_021F0CEC.c)
- ov031_func_021F0D40.c..ov031_func_021F0F68.c: c99=CCERR: line 165: illegal implicit conversion from 'struct  *' to | line 165: 'struct B_021F0ED8 *' | line 169: illegal implicit conversion from 'struct  *' to nolang=CCERR: line 165: illegal impli
- ov031_func_021F0E64.c..ov031_func_021F0F68.c: c99=CCERR: line 96: illegal implicit conversion from 'struct A_021F0ED8 *' to | line 96: 'struct  *' nolang=CCERR: line 96: illegal implicit conversion from 'struct A_021F0ED8 *' to | line 96: 'struct
- ov031_func_021F0E64.c..ov031_func_021F0ED8.c: c99=CCERR: line 75: illegal implicit conversion from 'struct A_021F0ED8 *' to | line 75: 'struct  *' nolang=CCERR: line 75: illegal implicit conversion from 'struct A_021F0ED8 *' to | line 75: 'struct

Members, in address order:

- `ov031_func_021F0680.c`
- `ov031_func_021F07AC.c`
- `ov031_func_021F09A0.c`
- `ov031_func_021F0A04.c`
- `ov031_func_021F0C34.c`
- `ov031_func_021F0C60.c`
- `ov031_func_021F0CEC.c`
- `ov031_func_021F0E64.c`
- `ov031_func_021F0ED8.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021F0680.c` again.
