# br_proc_sys.c (ov186)

Translation unit 021F90C0..021F9CB8, 28 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`br_proc_sys.c` is blocked by:

- ov186_func_021F90C0.c..ov186_func_021F9CA4.c: prototype of func_02012A30 differs between members (src/matched/ov/ov186_func_021F9244.c); prototype of func_021FC4DC differs between members (src/matched/ov/ov186_func_021F9390.c); prototype of func_
- ov186_func_021F90C0.c..ov186_func_021F97EC.c: prototype of func_02082BCC differs between members (src/matched/ov/ov186_func_021F96AC.c)
- ov186_func_021F90C0.c..ov186_func_021F962C.c: c99=DIFF nolang=DIFF
- ov186_func_021F9390.c..ov186_func_021F962C.c: c99=DIFF nolang=DIFF
- ov186_func_021F94E4.c..ov186_func_021F962C.c: c99=DIFF nolang=DIFF
- ov186_func_021F966C.c..ov186_func_021F97EC.c: c99=ERROR SystemExit('ISA conflict for func_021F98F8 at 021F98F8: the source declares arm, the image says thumb (the func_021F98F8 label in ov186).  Fix the symbols: block (address from name); refusin
- ov186_func_021F966C.c..ov186_func_021F972C.c: c99=DIFF nolang=DIFF
- ov186_func_021F96AC.c..ov186_func_021F972C.c: c99=ERROR SystemExit('ISA conflict for func_021FC4DC at 021FC4DC: the source declares arm, the image says thumb (the func_021FC4DC label in ov186).  Fix the symbols: block (address from name); refusin
- ov186_func_021F9810.c..ov186_func_021F9CA4.c: prototype of func_0200B570 differs between members (src/matched/ov/ov186_func_021F98F8.c); prototype of func_02034714 differs between members (src/matched/ov/ov186_func_021F9A80.c); prototype of func_
- ov186_func_021F9810.c..ov186_func_021F9B98.c: prototype of func_0200B570 differs between members (src/matched/ov/ov186_func_021F98F8.c); prototype of func_02034714 differs between members (src/matched/ov/ov186_func_021F9A80.c); prototype of func_
- ov186_func_021F9810.c..ov186_func_021F98F8.c: c99=DIFF nolang=DIFF
- ov186_func_021F9868.c..ov186_func_021F98F8.c: c99=DIFF nolang=DIFF
- ov186_func_021F99CC.c..ov186_func_021F9B98.c: prototype of func_02030734 differs between members (src/matched/ov/ov186_func_021F9A80.c); prototype of func_02082BCC differs between members (src/matched/ov/ov186_func_021F9A80.c); prototype of func_
- ov186_func_021F9B9C.c..ov186_func_021F9CA4.c: prototype of func_02082BCC differs between members (src/matched/ov/ov186_func_021F9CA4.c)
- ov186_func_021F9C50.c..ov186_func_021F9CA4.c: prototype of func_02082BCC differs between members (src/matched/ov/ov186_func_021F9CA4.c)
- ov186_func_021F9C50.c..ov186_func_021F9C6C.c: c99=CCERR: line 43: illegal implicit conversion from 'struct  *' to | line 43: 'struct  *' nolang=CCERR: line 43: illegal implicit conversion from 'struct  *' to | line 43: 'struct  *'

Members, in address order:

- `ov186_func_021F94E4.c`
- `ov186_func_021F962C.c`
- `ov186_func_021F966C.c`
- `ov186_func_021F96AC.c`
- `ov186_func_021F972C.c`
- `ov186_func_021F9810.c`
- `ov186_func_021F9868.c`
- `ov186_func_021F98F8.c`
- `ov186_func_021F9C50.c`
- `ov186_func_021F9C6C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names br_proc_sys.c` again.
