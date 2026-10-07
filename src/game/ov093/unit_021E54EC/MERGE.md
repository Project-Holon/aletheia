# unit_021E54EC.c (ov093)

Translation unit 021E54EC..021E55C4, 3 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021E54EC.c` is blocked by:

- ov093_func_021E54EC.c..ov093_func_021E556C.c: c99=CCERR: line 64: illegal implicit conversion from 'int' to | line 64: 'void *' | line 73: illegal implicit conversion from 'int' to nolang=CCERR: line 64: illegal implicit conversion from 'int' to 
- ov093_func_021E552C.c..ov093_func_021E556C.c: c99=CCERR: line 56: illegal implicit conversion from 'int' to | line 56: 'void *' nolang=CCERR: line 56: illegal implicit conversion from 'int' to | line 56: 'void *'

Members, in address order:

- `ov093_func_021E54EC.c`
- `ov093_func_021E552C.c`
- `ov093_func_021E556C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021E54EC.c` again.
