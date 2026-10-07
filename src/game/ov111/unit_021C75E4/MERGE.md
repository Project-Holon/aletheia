# unit_021C75E4.c (ov111)

Translation unit 021C75E4..021C842C, 41 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021C75E4.c` is blocked by:

- ov111_func_021C75E4.c..ov111_func_021C8414.c: c99=CCERR: line 2055: illegal implicit conversion from 'struct  *' to | line 2055: 'struct  *' | line 2056: illegal implicit conversion from 'struct  *' to nolang=CCERR: line 2055: illegal implicit co
- ov111_func_021C7B20.c..ov111_func_021C8414.c: c99=CCERR: line 1090: illegal implicit conversion from 'struct  *' to | line 1090: 'struct  *' | line 1139: illegal implicit conversion from 'struct  *' to nolang=CCERR: line 1090: illegal implicit co
- ov111_func_021C7B20.c..ov111_func_021C80E8.c: c99=CCERR: line 606: illegal implicit conversion from 'struct  *' to | line 606: 'struct  *' | line 655: illegal implicit conversion from 'struct  *' to nolang=CCERR: line 606: illegal implicit conver
- ov111_func_021C7B20.c..ov111_func_021C7E48.c: c99=CCERR: line 405: illegal implicit conversion from 'struct  *' to | line 405: 'struct  *' | line 455: illegal implicit conversion from 'struct  *' to nolang=CCERR: line 405: illegal implicit conver
- ov111_func_021C7C94.c..ov111_func_021C7E48.c: c99=CCERR: line 265: illegal implicit conversion from 'struct  *' to | line 265: 'struct  *' | line 315: illegal implicit conversion from 'struct  *' to nolang=CCERR: line 265: illegal implicit conver
- ov111_func_021C7CD0.c..ov111_func_021C7E48.c: c99=CCERR: line 267: illegal implicit conversion from 'struct  *' to | line 267: 'struct  *' nolang=CCERR: line 267: illegal implicit conversion from 'struct  *' to | line 267: 'struct  *'
- ov111_func_021C7EF8.c..ov111_func_021C80E8.c: c99=CCERR: line 292: illegal implicit conversion from 'struct  *' to | line 292: 'struct  *' nolang=CCERR: line 292: illegal implicit conversion from 'struct  *' to | line 292: 'struct  *'
- ov111_func_021C810C.c..ov111_func_021C8414.c: c99=CCERR: line 520: illegal implicit conversion from 'struct  *' to | line 520: 'struct  *' | line 521: illegal implicit conversion from 'struct  *' to nolang=CCERR: line 520: illegal implicit conver
- ov111_func_021C810C.c..ov111_func_021C829C.c: c99=CCERR: line 301: illegal implicit conversion from 'struct  *' to | line 301: 'struct  *' nolang=CCERR: line 301: illegal implicit conversion from 'struct  *' to | line 301: 'struct  *'
- ov111_func_021C810C.c..ov111_func_021C81A4.c: c99=CCERR: line 152: illegal implicit conversion from 'struct  *' to | line 152: 'struct  *' nolang=CCERR: line 152: illegal implicit conversion from 'struct  *' to | line 152: 'struct  *'
- ov111_func_021C82C0.c..ov111_func_021C8414.c: c99=CCERR: line 300: illegal implicit conversion from 'struct  *' to | line 300: 'struct  *' | line 301: illegal implicit conversion from 'struct  *' to nolang=CCERR: line 300: illegal implicit conver
- ov111_func_021C82C0.c..ov111_func_021C8364.c: c99=CCERR: line 287: illegal implicit conversion from 'struct  *' to | line 287: 'struct  *' | line 288: illegal implicit conversion from 'struct  *' to nolang=CCERR: line 287: illegal implicit conver
- ov111_func_021C832C.c..ov111_func_021C8364.c: c99=CCERR: line 169: illegal implicit conversion from 'struct  *' to | line 169: 'struct  *' nolang=CCERR: line 169: illegal implicit conversion from 'struct  *' to | line 169: 'struct  *'

Members, in address order:

- `ov111_func_021C7C94.c`
- `ov111_func_021C7CD0.c`
- `ov111_func_021C7E48.c`
- `ov111_func_021C810C.c`
- `ov111_func_021C81A4.c`
- `ov111_func_021C82C0.c`
- `ov111_func_021C832C.c`
- `ov111_func_021C8364.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021C75E4.c` again.
