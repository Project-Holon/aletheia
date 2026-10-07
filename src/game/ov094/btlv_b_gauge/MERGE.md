# btlv_b_gauge.c (ov094)

Translation unit 022079C0..02209224, 47 functions, confidence likely (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`btlv_b_gauge.c` is blocked by:

- ov094_func_022079C0.c..ov094_func_02209214.c: prototype of func_02082A60 differs between members (src/matched/ov/ov094_func_02208420.c); prototype of func_0201C7A4 differs between members (src/matched/ov/ov094_func_02208550.c); type typedef Vec2 
- ov094_func_022079C0.c..ov094_func_02208550.c: prototype of func_0220868C differs between members (src/matched/ov/ov094_func_022082FC.c); prototype of func_02082A60 differs between members (src/matched/ov/ov094_func_02208420.c); prototype of func_
- ov094_func_022079C0.c..ov094_func_02207DA0.c: c99=CCERR: line 312: illegal implicit conversion from 'struct O_02207CC4 *' to | line 312: 'struct O_02207D04 *' nolang=CCERR: line 312: illegal implicit conversion from 'struct O_02207CC4 *' to | lin
- ov094_func_02207C94.c..ov094_func_02207DA0.c: type typedef O differs between members (src/matched/ov/ov094_func_02207D04.c)
- ov094_func_02207C94.c..ov094_func_02207D04.c: type typedef O differs between members (src/matched/ov/ov094_func_02207D04.c)
- ov094_func_02207CC4.c..ov094_func_02207D04.c: type typedef O differs between members (src/matched/ov/ov094_func_02207D04.c)
- ov094_func_02207E1C.c..ov094_func_02208550.c: prototype of func_02082A60 differs between members (src/matched/ov/ov094_func_02208420.c)
- ov094_func_02207E1C.c..ov094_func_02208034.c: type typedef O differs between members (src/matched/ov/ov094_func_02207EF0.c)
- ov094_func_02208650.c..ov094_func_02209214.c: prototype of func_022079C0 differs between members (src/matched/ov/ov094_func_02208870.c); type typedef Vec2 differs between members (src/matched/ov/ov094_func_022090B4.c)
- ov094_func_02208650.c..ov094_func_0220893C.c: prototype of func_022079C0 differs between members (src/matched/ov/ov094_func_02208870.c)
- ov094_func_02208958.c..ov094_func_02209214.c: type typedef Vec2 differs between members (src/matched/ov/ov094_func_022090B4.c)
- ov094_func_02208D38.c..ov094_func_02209214.c: c99=CCERR: line 226: illegal implicit conversion from 'void (void *, struct  *)' to | line 226: 'void (*)(void *, void *)' nolang=CCERR: line 226: illegal implicit conversion from 'void (void *, struc

Members, in address order:

- `ov094_func_02207C94.c`
- `ov094_func_02207CC4.c`
- `ov094_func_02207D04.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names btlv_b_gauge.c` again.
