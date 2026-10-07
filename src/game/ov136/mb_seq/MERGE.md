# mb_seq.c (ov136)

Translation unit 021C6984..021C7738, 50 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`mb_seq.c` is blocked by:

- ov136_func_021C6984.c..ov136_func_021C770C.c: c99=DIFF nolang=DIFF
- ov136_func_021C6984.c..ov136_func_021C7178.c: c99=DIFF nolang=DIFF
- ov136_func_021C6984.c..ov136_func_021C6E98.c: c99=DIFF nolang=DIFF
- ov136_func_021C6BD8.c..ov136_func_021C6E98.c: c99=DIFF nolang=DIFF
- ov136_func_021C71A8.c..ov136_func_021C770C.c: c99=ERROR SystemExit('ISA conflict for func_021C5BE0 at 021C5BE0: the source declares arm, the image says thumb (the func_021C5BE0 label in ov136).  Fix the symbols: block (address from name); refusin
- ov136_func_021C74BC.c..ov136_func_021C770C.c: c99=ERROR SystemExit('ISA conflict for func_021C73C8 at 021C73C8: the source declares arm, the image says thumb (the func_021C73C8 label in ov136).  Fix the symbols: block (address from name); refusin
- ov136_func_021C74BC.c..ov136_func_021C758C.c: c99=ERROR SystemExit('ISA conflict for func_021C73C8 at 021C73C8: the source declares arm, the image says thumb (the func_021C73C8 label in ov136).  Fix the symbols: block (address from name); refusin
- ov136_func_021C7504.c..ov136_func_021C758C.c: c99=ERROR SystemExit('ISA conflict for func_021C73C8 at 021C73C8: the source declares arm, the image says thumb (the func_021C73C8 label in ov136).  Fix the symbols: block (address from name); refusin
- ov136_func_021C7540.c..ov136_func_021C758C.c: c99=ERROR SystemExit('ISA conflict for func_021C73C8 at 021C73C8: the source declares arm, the image says thumb (the func_021C73C8 label in ov136).  Fix the symbols: block (address from name); refusin
- ov136_func_021C7600.c..ov136_func_021C770C.c: c99=DIFF nolang=DIFF
- ov136_func_021C7658.c..ov136_func_021C770C.c: c99=DIFF nolang=DIFF
- ov136_func_021C7658.c..ov136_func_021C76A8.c: c99=ERROR SystemExit('ISA conflict for func_021C76D0 at 021C76D0: the source declares arm, the image says thumb (the func_021C76D0 label in ov136).  Fix the symbols: block (address from name); refusin

Members, in address order:

- `ov136_func_021C7504.c`
- `ov136_func_021C7540.c`
- `ov136_func_021C758C.c`
- `ov136_func_021C7658.c`
- `ov136_func_021C76A8.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names mb_seq.c` again.
