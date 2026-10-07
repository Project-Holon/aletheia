# unit_021B7560.c (ov103)

Translation unit 021B7560..021B9214, 78 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021B7560.c` is blocked by:

- ov103_func_021B7560.c..ov103_func_021B91B4.c: prototype of func_02082BCC differs between members (src/matched/ov/ov103_func_021B787C.c); prototype of func_02082BCC differs between members (src/matched/ov/ov103_func_021B7B3C.c); prototype of func_
- ov103_func_021B7560.c..ov103_func_021B800C.c: prototype of func_02082BCC differs between members (src/matched/ov/ov103_func_021B787C.c); prototype of func_02082BCC differs between members (src/matched/ov/ov103_func_021B7B3C.c); prototype of func_
- ov103_func_021B7560.c..ov103_func_021B7C5C.c: prototype of func_02082BCC differs between members (src/matched/ov/ov103_func_021B787C.c); prototype of func_02082BCC differs between members (src/matched/ov/ov103_func_021B7B3C.c); prototype of func_
- ov103_func_021B7560.c..ov103_func_021B7954.c: prototype of func_02082BCC differs between members (src/matched/ov/ov103_func_021B787C.c)
- ov103_func_021B7560.c..ov103_func_021B787C.c: prototype of func_02082BCC differs between members (src/matched/ov/ov103_func_021B787C.c)
- ov103_func_021B7560.c..ov103_func_021B7748.c: c99=ERROR SystemExit('ISA conflict for func_021B8AF4 at 021B8AF4: the source declares arm, the image says thumb (the func_021B8AF4 label in ov103).  Fix the symbols: block (address from name); refusin
- ov103_func_021B795C.c..ov103_func_021B7C5C.c: prototype of func_02082BCC differs between members (src/matched/ov/ov103_func_021B7C08.c)
- ov103_func_021B795C.c..ov103_func_021B7B34.c: c99=CCERR: line 84: identifier 'd_021B927C' redeclared as 'const int[]' | line 82: identifier 'd_021B927C' was originally declared as 'unsigned int[]' nolang=CCERR: line 84: identifier 'd_021B927C' re
- ov103_func_021B8074.c..ov103_func_021B91B4.c: prototype of func_02082BCC differs between members (src/matched/ov/ov103_func_021B80E4.c); prototype of func_02045808 differs between members (src/matched/ov/ov103_func_021B824C.c); global d_021B926C 
- ov103_func_021B8074.c..ov103_func_021B8B38.c: prototype of func_02082BCC differs between members (src/matched/ov/ov103_func_021B80E4.c); prototype of func_02045808 differs between members (src/matched/ov/ov103_func_021B824C.c); global d_021B926C 
- ov103_func_021B8074.c..ov103_func_021B8338.c: prototype of func_02082BCC differs between members (src/matched/ov/ov103_func_021B80E4.c); prototype of func_02045808 differs between members (src/matched/ov/ov103_func_021B824C.c)
- ov103_func_021B8348.c..ov103_func_021B8B38.c: global d_021B926C declared two ways (src/matched/ov/ov103_func_021B8728.c)
- ov103_func_021B8348.c..ov103_func_021B8728.c: prototype of func_021B8A44 differs between members (src/matched/ov/ov103_func_021B856C.c); prototype of func_021B8A44 differs between members (src/matched/ov/ov103_func_021B8728.c); global d_021B926C 
- ov103_func_021B8364.c..ov103_func_021B8728.c: prototype of func_021B8A44 differs between members (src/matched/ov/ov103_func_021B856C.c); prototype of func_021B8A44 differs between members (src/matched/ov/ov103_func_021B8728.c); global d_021B926C 
- ov103_func_021B856C.c..ov103_func_021B8728.c: global d_021B926C declared two ways (src/matched/ov/ov103_func_021B8728.c)
- ov103_func_021B8828.c..ov103_func_021B8B38.c: c99=CCERR: line 122: illegal implicit conversion from 'struct  *' to | line 122: 'const struct  *' nolang=CCERR: line 122: illegal implicit conversion from 'struct  *' to | line 122: 'const struct  *'
- ov103_func_021B8BC0.c..ov103_func_021B91B4.c: c99=CCERR: line 191: illegal implicit conversion from 'struct  *' to | line 191: 'struct  *' nolang=CCERR: line 191: illegal implicit conversion from 'struct  *' to | line 191: 'struct  *'

Members, in address order:

- `ov103_func_021B7560.c`
- `ov103_func_021B7748.c`
- `ov103_func_021B8364.c`
- `ov103_func_021B856C.c`
- `ov103_func_021B8728.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021B7560.c` again.
