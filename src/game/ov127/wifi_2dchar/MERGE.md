# wifi_2dchar.c (ov127)

Translation unit 021C3EE0..021C471C, 44 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`wifi_2dchar.c` is blocked by:

- ov127_func_021C3EE0.c..ov127_func_021C4680.c: prototype of func_0204B528 differs between members (src/matched/ov/ov127_func_021C428C.c)
- ov127_func_021C3EE0.c..ov127_func_021C42A8.c: prototype of func_0204B528 differs between members (src/matched/ov/ov127_func_021C428C.c)
- ov127_func_021C42C4.c..ov127_func_021C4680.c: c99=CCERR: line 123: illegal implicit conversion from 'char *' to | line 123: 'struct  *' nolang=CCERR: line 123: illegal implicit conversion from 'char *' to | line 123: 'struct  *'
- ov127_func_021C42C4.c..ov127_func_021C4464.c: c99=CCERR: line 77: illegal implicit conversion from 'char *' to | line 77: 'struct  *' nolang=CCERR: line 77: illegal implicit conversion from 'char *' to | line 77: 'struct  *'
- ov127_func_021C435C.c..ov127_func_021C4464.c: c99=CCERR: line 48: illegal implicit conversion from 'char *' to | line 48: 'struct  *' nolang=CCERR: line 48: illegal implicit conversion from 'char *' to | line 48: 'struct  *'
- ov127_func_021C435C.c..ov127_func_021C43E4.c: c99=CCERR: line 41: illegal implicit conversion from 'char *' to | line 41: 'struct  *' nolang=CCERR: line 41: illegal implicit conversion from 'char *' to | line 41: 'struct  *'

Members, in address order:

- `ov127_func_021C435C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names wifi_2dchar.c` again.
