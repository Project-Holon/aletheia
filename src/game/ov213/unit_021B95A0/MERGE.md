# unit_021B95A0.c (ov213)

Translation unit 021B95A0..021BAB64, 62 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021B95A0.c` is blocked by:

- ov213_func_021B95A0.c..ov213_func_021BAABC.c: prototype of func_0204B92C differs between members (src/matched/ov/ov213_func_021BA68C.c)
- ov213_func_021B95A0.c..ov213_func_021BA30C.c: prototype of func_021BA408 differs between members (src/matched/ov/ov213_func_021B9A68.c); prototype of func_021BA38C differs between members (src/matched/ov/ov213_func_021B9A84.c)
- ov213_func_021B95A0.c..ov213_func_021B9D80.c: prototype of func_021BA408 differs between members (src/matched/ov/ov213_func_021B9A68.c); prototype of func_021BA38C differs between members (src/matched/ov/ov213_func_021B9A84.c)
- ov213_func_021B98A0.c..ov213_func_021B9D80.c: c99=ERROR SystemExit('ISA conflict for func_021BA81C at 021BA81C: the source declares arm, the image says thumb (the func_021BA81C label in ov213).  Fix the symbols: block (address from name); refusin
- ov213_func_021B9A84.c..ov213_func_021B9D80.c: prototype of func_021B98DC differs between members (src/matched/ov/ov213_func_021B9D4C.c)
- ov213_func_021B9A84.c..ov213_func_021B9B0C.c: c99=ERROR SystemExit('ISA conflict for func_021B61FC at 021B61FC: the source declares arm, the image says thumb (the func_021B61FC label in ov067).  Fix the symbols: block (address from name); refusin
- ov213_func_021B9E08.c..ov213_func_021BA30C.c: c99=ERROR SystemExit('ISA conflict for func_021BA71C at 021BA71C: the source declares arm, the image says thumb (the func_021BA71C label in ov213).  Fix the symbols: block (address from name); refusin
- ov213_func_021B9E08.c..ov213_func_021BA034.c: c99=ERROR SystemExit('ISA conflict for func_021BA71C at 021BA71C: the source declares arm, the image says thumb (the func_021BA71C label in ov213).  Fix the symbols: block (address from name); refusin
- ov213_func_021B9EB0.c..ov213_func_021BA034.c: c99=ERROR SystemExit('ISA conflict for func_021B9E50 at 021B9E50: the source declares arm, the image says thumb (the func_021B9E50 label in ov213).  Fix the symbols: block (address from name); refusin
- ov213_func_021B9EB0.c..ov213_func_021B9EE4.c: c99=ERROR SystemExit('ISA conflict for func_021B9E50 at 021B9E50: the source declares arm, the image says thumb (the func_021B9E50 label in ov213).  Fix the symbols: block (address from name); refusin
- ov213_func_021BA014.c..ov213_func_021BA034.c: c99=ERROR SystemExit('ISA conflict for func_021B98DC at 021B98DC: the source declares arm, the image says thumb (the func_021B98DC label in ov213).  Fix the symbols: block (address from name); refusin
- ov213_func_021BA330.c..ov213_func_021BAABC.c: prototype of func_0204B92C differs between members (src/matched/ov/ov213_func_021BA68C.c)
- ov213_func_021BA330.c..ov213_func_021BA750.c: prototype of func_0204B92C differs between members (src/matched/ov/ov213_func_021BA68C.c)
- ov213_func_021BA330.c..ov213_func_021BA514.c: c99=CCERR: line 58: illegal name overloading | line 60: illegal name overloading | line 62: illegal name overloading nolang=CCERR: line 58: illegal name overloading | line 60: illegal name overloading
- ov213_func_021BA330.c..ov213_func_021BA408.c: c99=CCERR: line 45: illegal name overloading nolang=CCERR: line 45: illegal name overloading
- ov213_func_021BA38C.c..ov213_func_021BA408.c: c99=CCERR: line 30: illegal name overloading nolang=CCERR: line 30: illegal name overloading

Members, in address order:

- `ov213_func_021B9A84.c`
- `ov213_func_021B9B0C.c`
- `ov213_func_021B9EB0.c`
- `ov213_func_021B9EE4.c`
- `ov213_func_021BA014.c`
- `ov213_func_021BA034.c`
- `ov213_func_021BA330.c`
- `ov213_func_021BA38C.c`
- `ov213_func_021BA408.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021B95A0.c` again.
