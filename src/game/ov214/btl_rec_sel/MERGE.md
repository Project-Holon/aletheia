# btl_rec_sel.c (ov214)

Translation unit 021B95A0..021BB0D4, 49 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`btl_rec_sel.c` is blocked by:

- ov214_func_021B95A0.c..ov214_func_021BAF64.c: prototype of func_02041B6C differs between members (src/matched/ov/ov214_func_021BA0DC.c); prototype of func_020061E4 differs between members (src/matched/ov/ov214_func_021BA190.c); prototype of func_
- ov214_func_021B95A0.c..ov214_func_021BA3C4.c: prototype of func_02041B6C differs between members (src/matched/ov/ov214_func_021BA0DC.c); prototype of func_020061E4 differs between members (src/matched/ov/ov214_func_021BA190.c)
- ov214_func_021B95A0.c..ov214_func_021BA058.c: c99=ERROR SystemExit('ISA conflict for func_021BB178 at 021BB178: the source declares arm, the image says thumb (the func_021BB178 label in ov214).  Fix the symbols: block (address from name); refusin
- ov214_func_021B95A0.c..ov214_func_021B9EF0.c: c99=ERROR SystemExit('ISA conflict for func_021BB178 at 021BB178: the source declares arm, the image says thumb (the func_021BB178 label in ov214).  Fix the symbols: block (address from name); refusin
- ov214_func_021B95A0.c..ov214_func_021B9834.c: c99=ERROR SystemExit('ISA conflict for func_021BB178 at 021BB178: the source declares arm, the image says thumb (the func_021BB178 label in ov214).  Fix the symbols: block (address from name); refusin
- ov214_func_021B9798.c..ov214_func_021B9834.c: c99=ERROR SystemExit('ISA conflict for func_021BA108 at 021BA108: the source declares arm, the image says thumb (the func_021BA108 label in ov214).  Fix the symbols: block (address from name); refusin
- ov214_func_021BA43C.c..ov214_func_021BAF64.c: prototype of func_0201C724 differs between members (src/matched/ov/ov214_func_021BA794.c); global d_021BB498 declared two ways (src/matched/ov/ov214_func_021BAE10.c)
- ov214_func_021BA43C.c..ov214_func_021BABA4.c: prototype of func_0201C724 differs between members (src/matched/ov/ov214_func_021BA794.c)
- ov214_func_021BA43C.c..ov214_func_021BA6A0.c: prototype of func_021BA794 differs between members (src/matched/ov/ov214_func_021BA6A0.c)
- ov214_func_021BABF4.c..ov214_func_021BAF64.c: global d_021BB498 declared two ways (src/matched/ov/ov214_func_021BAE10.c)
- ov214_func_021BAD14.c..ov214_func_021BAF64.c: global d_021BB498 declared two ways (src/matched/ov/ov214_func_021BAE10.c)
- ov214_func_021BAD14.c..ov214_func_021BAE4C.c: global d_021BB498 declared two ways (src/matched/ov/ov214_func_021BAE10.c)

Members, in address order:

- `ov214_func_021B95A0.c`
- `ov214_func_021B9798.c`
- `ov214_func_021B9834.c`
- `ov214_func_021BAD14.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names btl_rec_sel.c` again.
