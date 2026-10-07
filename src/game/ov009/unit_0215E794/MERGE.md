# unit_0215E794.c (ov009)

Translation unit 0215E794..0215EBF0, 7 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_0215E794.c` is blocked by:

- ov009_func_0215E794.c..ov009_func_0215EBB4.c: prototype of func_0215F3D0 differs between members (src/matched/ov_sdk/ov009_func_0215E84C.c)
- ov009_func_0215E980.c..ov009_func_0215EBB4.c: c99=CCERR: line 154: identifier 'IsStream(struct Socket_0215E980 *)' redeclared as 'int (struct  *)' | line 120: identifier 'IsStream(struct Socket_0215E980 *)' was originally declared as 'int (struct
- ov009_func_0215E980.c..ov009_func_0215EA1C.c: c99=CCERR: line 130: identifier 'IsStream(struct Socket_0215E980 *)' redeclared as 'int (struct  *)' | line 96: identifier 'IsStream(struct Socket_0215E980 *)' was originally declared as 'int (struct 

Members, in address order:

- `ov009_func_0215E980.c`
- `ov009_func_0215EA1C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_0215E794.c` again.
