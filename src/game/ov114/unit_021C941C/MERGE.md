# unit_021C941C.c (ov114)

Translation unit 021C941C..021C9858, 7 functions, confidence likely (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021C941C.c` is blocked by:

- ov114_func_021C941C.c..ov114_func_021C97E0.c: global d_021D4098 declared two ways (src/matched/ov/ov114_func_021C9530.c); global d_021D4084 declared two ways (src/matched/ov/ov114_func_021C9530.c); global d_021D4084 declared two ways (src/matched
- ov114_func_021C941C.c..ov114_func_021C9530.c: global d_021D4098 declared two ways (src/matched/ov/ov114_func_021C9530.c); global d_021D4084 declared two ways (src/matched/ov/ov114_func_021C9530.c)
- ov114_func_021C94A0.c..ov114_func_021C9530.c: global d_021D4098 declared two ways (src/matched/ov/ov114_func_021C9530.c); global d_021D4084 declared two ways (src/matched/ov/ov114_func_021C9530.c)
- ov114_func_021C9634.c..ov114_func_021C97E0.c: c99=CCERR: line 52: identifier 'd_021D4084' redeclared as 'struct ' | line 51: identifier 'd_021D4084' was originally declared as 'unsigned int[]' | line 82: not a struct/union/class nolang=CCERR: lin

Members, in address order:

- `ov114_func_021C941C.c`
- `ov114_func_021C94A0.c`
- `ov114_func_021C9530.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021C941C.c` again.
