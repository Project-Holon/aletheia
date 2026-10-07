# unit_021C6180.c (ov128)

Translation unit 021C6180..021C8DA0, 96 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021C6180.c` is blocked by:

- ov128_func_021C6180.c..ov128_func_021C8C04.c: prototype of func_020355D8 differs between members (src/matched/ov/ov128_func_021C734C.c); prototype of func_020355D8 differs between members (src/matched/ov/ov128_func_021C7460.c); prototype of func_
- ov128_func_021C6180.c..ov128_func_021C734C.c: prototype of func_020355D8 differs between members (src/matched/ov/ov128_func_021C734C.c)
- ov128_func_021C6180.c..ov128_func_021C6980.c: c99=CCERR: line 322: identifier 'd_021CA5CC' redeclared as 'unsigned char[]' | line 318: identifier 'd_021CA5CC' was originally declared as 'char[]' nolang=CCERR: line 322: identifier 'd_021CA5CC' red
- ov128_func_021C6520.c..ov128_func_021C6980.c: c99=CCERR: line 216: identifier 'd_021CA5CC' redeclared as 'unsigned char[]' | line 212: identifier 'd_021CA5CC' was originally declared as 'char[]' nolang=CCERR: line 216: identifier 'd_021CA5CC' red
- ov128_func_021C7460.c..ov128_func_021C8C04.c: prototype of func_0201CCE4 differs between members (src/matched/ov/ov128_func_021C867C.c); prototype of func_02041300 differs between members (src/matched/ov/ov128_func_021C89C4.c); global d_021CA6C8 
- ov128_func_021C7460.c..ov128_func_021C83DC.c: prototype of func_021C87A0 differs between members (src/matched/ov/ov128_func_021C8388.c); prototype of func_021C87A0 differs between members (src/matched/ov/ov128_func_021C83B0.c); prototype of func_
- ov128_func_021C7460.c..ov128_func_021C7D48.c: c99=DIFF nolang=DIFF
- ov128_func_021C7694.c..ov128_func_021C7D48.c: c99=DIFF nolang=DIFF
- ov128_func_021C8470.c..ov128_func_021C8C04.c: global d_021CA6C8 declared two ways (src/matched/ov/ov128_func_021C8A80.c); global d_021CA6C8 declared two ways (src/matched/ov/ov128_func_021C8B90.c)
- ov128_func_021C8850.c..ov128_func_021C8C04.c: global d_021CA6C8 declared two ways (src/matched/ov/ov128_func_021C8B90.c)
- ov128_func_021C899C.c..ov128_func_021C8C04.c: global d_021CA6C8 declared two ways (src/matched/ov/ov128_func_021C8B90.c)
- ov128_func_021C8A80.c..ov128_func_021C8C04.c: global d_021CA6C8 declared two ways (src/matched/ov/ov128_func_021C8B90.c)

Members, in address order:

- `ov128_func_021C8A80.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021C6180.c` again.
