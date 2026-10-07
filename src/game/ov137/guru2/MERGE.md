# guru2.c (ov137)

Translation unit 021DC860..021DD1E0, 36 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`guru2.c` is blocked by:

- ov137_func_021DC860.c..ov137_func_021DD1D0.c: global d_021BED00 declared two ways (src/matched/ov/ov137_func_021DCAB4.c); prototype of func_02030734 differs between members (src/matched/ov/ov137_func_021DCB04.c); prototype of func_02082D44 differ
- ov137_func_021DC860.c..ov137_func_021DCB94.c: global d_021BED00 declared two ways (src/matched/ov/ov137_func_021DCAB4.c); prototype of func_02030734 differs between members (src/matched/ov/ov137_func_021DCB04.c)
- ov137_func_021DC9F4.c..ov137_func_021DCB94.c: prototype of func_02030734 differs between members (src/matched/ov/ov137_func_021DCB04.c)
- ov137_func_021DCBC4.c..ov137_func_021DD1D0.c: c99=ERROR SystemExit('ISA conflict for func_021DCAFC at 021DCAFC: the source declares arm, the image says thumb (the func_021DCAFC label in ov137).  Fix the symbols: block (address from name); refusin
- ov137_func_021DCBC4.c..ov137_func_021DCE10.c: c99=ERROR SystemExit('ISA conflict for func_021DCAFC at 021DCAFC: the source declares arm, the image says thumb (the func_021DCAFC label in ov137).  Fix the symbols: block (address from name); refusin
- ov137_func_021DCBC4.c..ov137_func_021DCC24.c: c99=ERROR SystemExit('ISA conflict for func_021DCAFC at 021DCAFC: the source declares arm, the image says thumb (the func_021DCAFC label in ov137).  Fix the symbols: block (address from name); refusin
- ov137_func_021DCBFC.c..ov137_func_021DCC24.c: c99=ERROR SystemExit('ISA conflict for func_021DCAFC at 021DCAFC: the source declares arm, the image says thumb (the func_021DCAFC label in ov137).  Fix the symbols: block (address from name); refusin
- ov137_func_021DCCF0.c..ov137_func_021DCE10.c: c99=ERROR SystemExit('ISA conflict for func_021DE17C at 021DE17C: the source declares arm, the image says thumb (the func_021DE17C label in ov137).  Fix the symbols: block (address from name); refusin
- ov137_func_021DCCF0.c..ov137_func_021DCD14.c: c99=ERROR SystemExit('ISA conflict for func_021DE17C at 021DE17C: the source declares arm, the image says thumb (the func_021DE17C label in ov137).  Fix the symbols: block (address from name); refusin
- ov137_func_021DCD8C.c..ov137_func_021DCE10.c: c99=ERROR SystemExit('ISA conflict for func_021E1694 at 021E1694: the source declares arm, the image says thumb (the func_021E1694 label in ov137).  Fix the symbols: block (address from name); refusin
- ov137_func_021DCE00.c..ov137_func_021DCE10.c: c99=ERROR SystemExit('ISA conflict for func_021DD1D0 at 021DD1D0: the source declares arm, the image says thumb (the func_021DD1D0 label in ov137).  Fix the symbols: block (address from name); refusin
- ov137_func_021DCF50.c..ov137_func_021DD1D0.c: c99=ERROR SystemExit('ISA conflict for func_021841A0 at 021841A0: the source declares arm, the image says thumb (the func_021841A0 label in ov022).  Fix the symbols: block (address from name); refusin
- ov137_func_021DCF50.c..ov137_func_021DCF80.c: c99=ERROR SystemExit('ISA conflict for func_021841A0 at 021841A0: the source declares arm, the image says thumb (the func_021841A0 label in ov022).  Fix the symbols: block (address from name); refusin
- ov137_func_021DCF7C.c..ov137_func_021DCF80.c: c99=ERROR SystemExit('ISA conflict for func_021DCF50 at 021DCF50: the source declares arm, the image says thumb (the func_021DCF50 label in ov137).  Fix the symbols: block (address from name); refusin
- ov137_func_021DD0B8.c..ov137_func_021DD1D0.c: c99=ERROR SystemExit('ISA conflict for func_021DD570 at 021DD570: the source declares arm, the image says thumb (the func_021DD570 label in ov137).  Fix the symbols: block (address from name); refusin
- ov137_func_021DD0B8.c..ov137_func_021DD14C.c: c99=ERROR SystemExit('ISA conflict for func_021DD570 at 021DD570: the source declares arm, the image says thumb (the func_021DD570 label in ov137).  Fix the symbols: block (address from name); refusin

Members, in address order:

- `ov137_func_021DCBFC.c`
- `ov137_func_021DCC24.c`
- `ov137_func_021DCCF0.c`
- `ov137_func_021DCD14.c`
- `ov137_func_021DCD8C.c`
- `ov137_func_021DCE00.c`
- `ov137_func_021DCE10.c`
- `ov137_func_021DCF7C.c`
- `ov137_func_021DCF80.c`
- `ov137_func_021DD0B8.c`
- `ov137_func_021DD14C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names guru2.c` again.
