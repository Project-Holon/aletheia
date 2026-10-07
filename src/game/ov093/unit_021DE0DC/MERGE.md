# unit_021DE0DC.c (ov093)

Translation unit 021DE0DC..021DE180, 4 functions, confidence likely (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021DE0DC.c` is blocked by:

- func_021DE0DC.c..ov093_func_021DE108.c: c99=CCERR: line 47: illegal implicit conversion from 'int' to | line 47: 'void *' | line 51: illegal implicit conversion from 'int' to nolang=CCERR: line 47: illegal implicit conversion from 'int' to 
- func_021DE0F8.c..ov093_func_021DE108.c: c99=CCERR: line 46: illegal implicit conversion from 'int' to | line 46: 'void *' nolang=CCERR: line 46: illegal implicit conversion from 'int' to | line 46: 'void *'
- no verified entry for 021DE170

Members, in address order:

- `func_021DE0DC.c`
- `func_021DE0F8.c`
- `ov093_func_021DE108.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021DE0DC.c` again.
