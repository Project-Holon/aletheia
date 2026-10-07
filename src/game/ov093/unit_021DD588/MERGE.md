# unit_021DD588.c (ov093)

Translation unit 021DD588..021DD87C, 15 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021DD588.c` is blocked by:

- func_021DD588.c..ov093_func_021DD7B8.c: c99=CCERR: line 121: illegal implicit conversion from 'int' to | line 121: 'unsigned char *' | line 132: illegal implicit conversion from 'int' to nolang=CCERR: line 121: illegal implicit conversion f
- func_021DD588.c..ov093_func_021DD68C.c: c99=CCERR: line 94: illegal implicit conversion from 'int' to | line 94: 'unsigned char *' | line 105: illegal implicit conversion from 'int' to nolang=CCERR: line 94: illegal implicit conversion from
- func_021DD588.c..ov093_func_021DD624.c: c99=CCERR: line 84: illegal implicit conversion from 'int' to | line 84: 'unsigned char *' nolang=CCERR: line 84: illegal implicit conversion from 'int' to | line 84: 'unsigned char *'
- func_021DD614.c..ov093_func_021DD624.c: c99=CCERR: line 39: illegal implicit conversion from 'int' to | line 39: 'unsigned char *' nolang=CCERR: line 39: illegal implicit conversion from 'int' to | line 39: 'unsigned char *'
- func_021DD648.c..ov093_func_021DD68C.c: c99=CCERR: line 44: illegal implicit conversion from 'int' to | line 44: 'unsigned char *' | line 55: illegal implicit conversion from 'int' to nolang=CCERR: line 44: illegal implicit conversion from 
- func_021DD648.c..ov093_func_021DD658.c: c99=CCERR: line 39: illegal implicit conversion from 'int' to | line 39: 'unsigned char *' nolang=CCERR: line 39: illegal implicit conversion from 'int' to | line 39: 'unsigned char *'
- func_021DD67C.c..ov093_func_021DD68C.c: c99=CCERR: line 39: illegal implicit conversion from 'int' to | line 39: 'unsigned char *' nolang=CCERR: line 39: illegal implicit conversion from 'int' to | line 39: 'unsigned char *'
- func_021DD6B0.c..ov093_func_021DD7B8.c: c99=CCERR: line 80: illegal implicit conversion from 'int' to | line 80: 'unsigned char *' | line 91: illegal implicit conversion from 'int' to nolang=CCERR: line 80: illegal implicit conversion from 
- func_021DD6B0.c..ov093_func_021DD6F4.c: c99=CCERR: line 41: illegal implicit conversion from 'int' to | line 41: 'unsigned char *' | line 52: illegal implicit conversion from 'int' to nolang=CCERR: line 41: illegal implicit conversion from 
- func_021DD6B0.c..ov093_func_021DD6C0.c: c99=CCERR: line 39: illegal implicit conversion from 'int' to | line 39: 'unsigned char *' nolang=CCERR: line 39: illegal implicit conversion from 'int' to | line 39: 'unsigned char *'
- func_021DD6E4.c..ov093_func_021DD6F4.c: c99=CCERR: line 36: illegal implicit conversion from 'int' to | line 36: 'unsigned char *' nolang=CCERR: line 36: illegal implicit conversion from 'int' to | line 36: 'unsigned char *'

Members, in address order:

- `func_021DD588.c`
- `func_021DD614.c`
- `ov093_func_021DD624.c`
- `func_021DD648.c`
- `ov093_func_021DD658.c`
- `func_021DD67C.c`
- `ov093_func_021DD68C.c`
- `func_021DD6B0.c`
- `ov093_func_021DD6C0.c`
- `func_021DD6E4.c`
- `ov093_func_021DD6F4.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021DD588.c` again.
