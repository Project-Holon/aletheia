# fldeff_namipoke.c (ov021)

Translation unit 021AC810..021ADC6C, 44 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`fldeff_namipoke.c` is blocked by:

- ov021_func_021AC810.c..ov021_func_021ADC04.c: prototype of func_021AC1CC differs between members (src/matched/ov/ov021_func_021ACDC4.c); prototype of func_0216D8E0 differs between members (src/matched/ov/ov021_func_021ACFF8.c); prototype of func_
- ov021_func_021AC810.c..ov021_func_021AD410.c: prototype of func_021AC1CC differs between members (src/matched/ov/ov021_func_021ACDC4.c); prototype of func_0216D8E0 differs between members (src/matched/ov/ov021_func_021ACFF8.c); prototype of func_
- ov021_func_021AC810.c..ov021_func_021ACBC8.c: c99=DIFF nolang=DIFF
- ov021_func_021AC810.c..ov021_func_021ACA38.c: c99=DIFF nolang=DIFF
- ov021_func_021AC900.c..ov021_func_021ACA38.c: c99=DIFF nolang=DIFF
- ov021_func_021ACBE4.c..ov021_func_021AD410.c: type typedef V3 differs between members (src/matched/ov/ov021_func_021ACDC4.c); prototype of func_021AC1CC differs between members (src/matched/ov/ov021_func_021ACDC4.c); type typedef V3 differs betwe
- ov021_func_021ACBE4.c..ov021_func_021ACDC4.c: prototype of func_021AC1CC differs between members (src/matched/ov/ov021_func_021ACDC4.c)
- ov021_func_021ACC3C.c..ov021_func_021ACDC4.c: prototype of func_021AC1CC differs between members (src/matched/ov/ov021_func_021ACDC4.c)
- ov021_func_021ACCB0.c..ov021_func_021ACDC4.c: c99=CCERR: line 172: illegal implicit conversion from 'struct B_021ACDC4 *' to | line 172: 'struct B_021ACCB0 *' | line 266: illegal implicit conversion from 'struct B_021ACDC4 *' to nolang=CCERR: lin
- ov021_func_021ACFD8.c..ov021_func_021AD410.c: type typedef V3 differs between members (src/matched/ov/ov021_func_021AD274.c)
- ov021_func_021AD530.c..ov021_func_021ADC04.c: type typedef Obj differs between members (src/matched/ov/ov021_func_021AD6B8.c); prototype of func_021AC1B8 differs between members (src/matched/ov/ov021_func_021AD738.c); prototype of func_021ABFA8 d
- ov021_func_021AD530.c..ov021_func_021AD7E4.c: type typedef Obj differs between members (src/matched/ov/ov021_func_021AD6B8.c); prototype of func_021AC1B8 differs between members (src/matched/ov/ov021_func_021AD738.c)
- func_021AD6A4.c..ov021_func_021AD7E4.c: prototype of func_021AC1B8 differs between members (src/matched/ov/ov021_func_021AD738.c)
- func_021AD6A4.c..ov021_func_021AD738.c: prototype of func_021AC1B8 differs between members (src/matched/ov/ov021_func_021AD738.c)
- ov021_func_021AD6B8.c..ov021_func_021AD738.c: prototype of func_021AC1B8 differs between members (src/matched/ov/ov021_func_021AD738.c)
- ov021_func_021AD82C.c..ov021_func_021ADC04.c: c99=DIFF nolang=DIFF
- ov021_func_021ADAAC.c..ov021_func_021ADC04.c: c99=DIFF nolang=DIFF
- ov021_func_021ADB6C.c..ov021_func_021ADC04.c: c99=DIFF nolang=DIFF

Members, in address order:

- `ov021_func_021AC900.c`
- `ov021_func_021ACC3C.c`
- `ov021_func_021ACCB0.c`
- `ov021_func_021ACDC4.c`
- `func_021AD6A4.c`
- `ov021_func_021AD6B8.c`
- `ov021_func_021AD738.c`
- `ov021_func_021ADB6C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names fldeff_namipoke.c` again.
