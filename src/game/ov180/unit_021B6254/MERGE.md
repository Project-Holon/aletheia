# unit_021B6254.c (ov180)

Translation unit 021B6254..021B7750, 67 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021B6254.c` is blocked by:

- ov180_func_021B6254.c..ov180_func_021B761C.c: prototype of func_02017D30 differs between members (src/matched/ov/ov180_func_021B654C.c); prototype of func_02017E1C differs between members (src/matched/ov/ov180_func_021B654C.c); prototype of func_
- ov180_func_021B6254.c..ov180_func_021B69E8.c: prototype of func_02017D30 differs between members (src/matched/ov/ov180_func_021B654C.c); prototype of func_02017E1C differs between members (src/matched/ov/ov180_func_021B654C.c); prototype of func_
- ov180_func_021B6254.c..ov180_func_021B6704.c: prototype of func_02017D30 differs between members (src/matched/ov/ov180_func_021B654C.c); prototype of func_02017E1C differs between members (src/matched/ov/ov180_func_021B654C.c); prototype of func_
- ov180_func_021B6254.c..ov180_func_021B64D0.c: c99=CCERR: line 86: identifier 'func_020434DC(unsigned long, unsigned long)' redeclared as 'void (unsigned int, unsigned int)' | line 85: identifier 'func_020434DC(unsigned long, unsigned long)' was o
- ov180_func_021B6254.c..ov180_func_021B63E8.c: c99=CCERR: line 57: identifier 'func_020434DC(unsigned long, unsigned long)' redeclared as 'void (unsigned int, unsigned int)' | line 56: identifier 'func_020434DC(unsigned long, unsigned long)' was o
- ov180_func_021B6254.c..ov180_func_021B6340.c: c99=CCERR: line 47: identifier 'func_020434DC(unsigned long, unsigned long)' redeclared as 'void (unsigned int, unsigned int)' | line 46: identifier 'func_020434DC(unsigned long, unsigned long)' was o

Members, in address order:

- `ov180_func_021B6254.c`
- `ov180_func_021B6340.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021B6254.c` again.
