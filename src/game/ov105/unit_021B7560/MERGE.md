# unit_021B7560.c (ov105)

Translation unit 021B7560..021B8860, 49 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021B7560.c` is blocked by:

- ov105_func_021B7560.c..ov105_func_021B8840.c: prototype of func_02082BCC differs between members (src/matched/ov/ov105_func_021B7C20.c); prototype of func_02082BCC differs between members (src/matched/ov/ov105_func_021B7C6C.c); prototype of func_
- ov105_func_021B7560.c..ov105_func_021B7CB0.c: prototype of func_02082BCC differs between members (src/matched/ov/ov105_func_021B7C20.c); prototype of func_02082BCC differs between members (src/matched/ov/ov105_func_021B7C6C.c)
- ov105_func_021B7D20.c..ov105_func_021B8840.c: prototype of func_02082BCC differs between members (src/matched/ov/ov105_func_021B7D90.c); prototype of func_02043B5C differs between members (src/matched/ov/ov105_func_021B7E48.c); prototype of func_
- ov105_func_021B80E8.c..ov105_func_021B8840.c: prototype of func_02061CA4 differs between members (src/matched/ov/ov105_func_021B8734.c)
- ov105_func_021B80E8.c..ov105_func_021B8440.c: c99=CCERR: line 109: illegal implicit conversion from 'struct  *' to | line 109: 'struct  *' | line 109: illegal implicit conversion from 'struct  *' to nolang=CCERR: line 109: illegal implicit conver
- ov105_func_021B80E8.c..ov105_func_021B83E0.c: c99=CCERR: line 99: illegal implicit conversion from 'struct  *' to | line 99: 'struct  *' | line 99: illegal implicit conversion from 'struct  *' to nolang=CCERR: line 99: illegal implicit conversion

Members, in address order:

- `ov105_func_021B80E8.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021B7560.c` again.
