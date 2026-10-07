# unit_021DFCE8.c (ov093)

Translation unit 021DFCE8..021E0284, 43 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021DFCE8.c` is blocked by:

- ov093_func_021DFCE8.c..ov093_func_021E01D4.c: c99=CCERR: line 232: illegal implicit conversion from 'int' to | line 232: 'void *' | line 240: illegal implicit conversion from 'int' to nolang=CCERR: line 232: illegal implicit conversion from 'int'
- ov093_func_021DFCE8.c..func_021E000C.c: c99=DIFF nolang=DIFF
- ov093_func_021DFCE8.c..func_021DFF20.c: c99=DIFF nolang=DIFF
- ov093_func_021DFCE8.c..ov093_func_021DFDEC.c: c99=DIFF nolang=DIFF
- ov093_func_021DFCE8.c..ov093_func_021DFD20.c: c99=DIFF nolang=DIFF
- ov093_func_021DFD68.c..ov093_func_021DFDEC.c: c99=DIFF nolang=DIFF
- ov093_func_021DFE28.c..func_021DFF20.c: c99=DIFF nolang=DIFF
- func_021DFEF4.c..func_021DFF20.c: c99=DIFF nolang=DIFF
- func_021DFF04.c..func_021DFF20.c: c99=DIFF nolang=DIFF
- func_021DFF30.c..func_021E000C.c: c99=DIFF nolang=DIFF
- func_021DFF30.c..func_021DFF88.c: c99=DIFF nolang=DIFF
- func_021DFF30.c..func_021DFF4C.c: c99=DIFF nolang=DIFF
- func_021DFF5C.c..func_021DFF88.c: c99=DIFF nolang=DIFF
- func_021DFFA4.c..func_021E000C.c: c99=DIFF nolang=DIFF
- func_021DFFA4.c..func_021DFFD0.c: c99=DIFF nolang=DIFF
- func_021DFFB4.c..func_021DFFD0.c: c99=DIFF nolang=DIFF
- func_021DFFE0.c..func_021E000C.c: c99=DIFF nolang=DIFF
- func_021E0028.c..ov093_func_021E01D4.c: c99=CCERR: line 82: illegal implicit conversion from 'int' to | line 82: 'void *' | line 90: illegal implicit conversion from 'int' to nolang=CCERR: line 82: illegal implicit conversion from 'int' to 
- func_021E0028.c..func_021E00E8.c: c99=DIFF nolang=DIFF
- func_021E0028.c..func_021E0080.c: c99=DIFF nolang=DIFF
- func_021E0054.c..func_021E0080.c: c99=DIFF nolang=DIFF
- func_021E0064.c..func_021E0080.c: c99=DIFF nolang=DIFF
- ov093_func_021E0090.c..func_021E00E8.c: c99=DIFF nolang=DIFF
- ov093_func_021E0090.c..func_021E00AC.c: c99=DIFF nolang=DIFF
- func_021E00BC.c..func_021E00E8.c: c99=DIFF nolang=DIFF
- func_021E0104.c..ov093_func_021E01D4.c: c99=CCERR: line 72: illegal implicit conversion from 'int' to | line 72: 'void *' | line 80: illegal implicit conversion from 'int' to nolang=CCERR: line 72: illegal implicit conversion from 'int' to 
- func_021E0104.c..func_021E015C.c: c99=DIFF nolang=DIFF
- func_021E0130.c..func_021E015C.c: c99=DIFF nolang=DIFF
- func_021E0140.c..func_021E015C.c: c99=DIFF nolang=DIFF
- func_021E016C.c..ov093_func_021E01D4.c: c99=CCERR: line 63: illegal implicit conversion from 'int' to | line 63: 'void *' | line 71: illegal implicit conversion from 'int' to nolang=CCERR: line 63: illegal implicit conversion from 'int' to 
- func_021E016C.c..func_021E0198.c: c99=DIFF nolang=DIFF
- func_021E01B4.c..ov093_func_021E01D4.c: c99=CCERR: line 60: illegal implicit conversion from 'int' to | line 60: 'void *' nolang=CCERR: line 60: illegal implicit conversion from 'int' to | line 60: 'void *'
- no verified entry for 021E0274

Members, in address order:

- `ov093_func_021DFCE8.c`
- `ov093_func_021DFD20.c`
- `ov093_func_021DFD68.c`
- `func_021DFEF4.c`
- `func_021DFF04.c`
- `func_021DFF20.c`
- `func_021DFF30.c`
- `func_021DFF4C.c`
- `func_021DFF5C.c`
- `func_021DFFA4.c`
- `func_021DFFB4.c`
- `func_021DFFD0.c`
- `func_021DFFE0.c`
- `func_021E0054.c`
- `func_021E0064.c`
- `func_021E0080.c`
- `ov093_func_021E0090.c`
- `func_021E00AC.c`
- `func_021E00BC.c`
- `func_021E0130.c`
- `func_021E0140.c`
- `func_021E015C.c`
- `func_021E016C.c`
- `func_021E01B4.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021DFCE8.c` again.
