# unit_021F5260.c (ov083)

Translation unit 021F5260..021F55D4, 10 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021F5260.c` is blocked by:

- ov083_func_021F5260.c..ov083_func_021F556C.c: c99=CCERR: line 210: illegal implicit conversion from 'void *' to | line 210: 'int' nolang=CCERR: line 210: illegal implicit conversion from 'void *' to | line 210: 'int'
- ov083_func_021F5260.c..ov083_func_021F5390.c: c99=CCERR: line 151: illegal implicit conversion from 'void *' to | line 151: 'int' nolang=CCERR: line 151: illegal implicit conversion from 'void *' to | line 151: 'int'
- ov083_func_021F5340.c..ov083_func_021F5390.c: c99=CCERR: line 81: illegal implicit conversion from 'void *' to | line 81: 'int' nolang=CCERR: line 81: illegal implicit conversion from 'void *' to | line 81: 'int'
- ov083_func_021F5368.c..ov083_func_021F5390.c: c99=CCERR: line 74: illegal implicit conversion from 'void *' to | line 74: 'int' nolang=CCERR: line 74: illegal implicit conversion from 'void *' to | line 74: 'int'

Members, in address order:

- `ov083_func_021F5340.c`
- `ov083_func_021F5368.c`
- `ov083_func_021F5390.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021F5260.c` again.
