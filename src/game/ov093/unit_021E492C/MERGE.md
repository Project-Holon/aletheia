# unit_021E492C.c (ov093)

Translation unit 021E492C..021E4BB0, 6 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021E492C.c` is blocked by:

- func_021E492C.c..ov093_func_021E4B00.c: c99=CCERR: line 80: illegal implicit conversion from 'int' to | line 80: 'unsigned char *' | line 84: illegal implicit conversion from 'int' to nolang=CCERR: line 80: illegal implicit conversion from 
- func_021E492C.c..ov093_func_021E4958.c: c99=CCERR: line 53: illegal implicit conversion from 'int' to | line 53: 'unsigned char *' | line 57: illegal implicit conversion from 'int' to nolang=CCERR: line 53: illegal implicit conversion from 
- func_021E4948.c..ov093_func_021E4958.c: c99=CCERR: line 52: illegal implicit conversion from 'int' to | line 52: 'unsigned char *' nolang=CCERR: line 52: illegal implicit conversion from 'int' to | line 52: 'unsigned char *'
- ov093_func_021E4A08.c..ov093_func_021E4B00.c: c99=DIFF nolang=DIFF
- ov093_func_021E4A70.c..ov093_func_021E4B00.c: c99=DIFF nolang=DIFF

Members, in address order:

- `func_021E492C.c`
- `func_021E4948.c`
- `ov093_func_021E4958.c`
- `ov093_func_021E4A08.c`
- `ov093_func_021E4A70.c`
- `ov093_func_021E4B00.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021E492C.c` again.
