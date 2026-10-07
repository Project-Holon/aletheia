# unit_021DDCA4.c (ov093)

Translation unit 021DDCA4..021DE0DC, 18 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021DDCA4.c` is blocked by:

- func_021DDCA4.c..ov093_func_021DE0C0.c: c99=CCERR: line 94: illegal implicit conversion from 'int' to | line 94: 'unsigned char *' | line 101: illegal implicit conversion from 'int' to nolang=CCERR: line 94: illegal implicit conversion from
- func_021DDCA4.c..ov093_func_021DDE74.c: c99=CCERR: line 73: illegal implicit conversion from 'int' to | line 73: 'unsigned char *' | line 80: illegal implicit conversion from 'int' to nolang=CCERR: line 73: illegal implicit conversion from 
- func_021DDCA4.c..ov093_func_021DDD38.c: c99=CCERR: line 62: illegal implicit conversion from 'int' to | line 62: 'unsigned char *' | line 69: illegal implicit conversion from 'int' to nolang=CCERR: line 62: illegal implicit conversion from 
- func_021DDCA4.c..func_021DDCC4.c: c99=DIFF nolang=DIFF
- ov093_func_021DDEA4.c..ov093_func_021DE0C0.c: c99=DIFF nolang=DIFF
- ov093_func_021DDEA4.c..ov093_func_021DDF98.c: c99=DIFF nolang=DIFF
- ov093_func_021DDEA4.c..ov093_func_021DDEFC.c: c99=DIFF nolang=DIFF
- ov093_func_021DDF38.c..ov093_func_021DDF98.c: c99=DIFF nolang=DIFF

Members, in address order:

- `func_021DDCA4.c`
- `func_021DDCC4.c`
- `ov093_func_021DDEA4.c`
- `ov093_func_021DDEFC.c`
- `ov093_func_021DDF38.c`
- `ov093_func_021DDF98.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021DDCA4.c` again.
