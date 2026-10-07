# btlv_core.c (ov093)

Translation unit 021E869C..021E9034, 45 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`btlv_core.c` is blocked by:

- ov093_func_021E869C.c..ov093_func_021E8F20.c: c99=CCERR: line 673: illegal implicit conversion from 'void *' to | line 673: 'unsigned short' nolang=CCERR: line 673: illegal implicit conversion from 'void *' to | line 673: 'unsigned short'
- ov093_func_021E8A98.c..ov093_func_021E8F20.c: c99=CCERR: line 325: illegal implicit conversion from 'void *' to | line 325: 'unsigned short' nolang=CCERR: line 325: illegal implicit conversion from 'void *' to | line 325: 'unsigned short'
- ov093_func_021E8A98.c..func_021E8CFC.c: c99=DIFF nolang=DIFF
- ov093_func_021E8BD0.c..func_021E8CFC.c: c99=DIFF nolang=DIFF
- ov093_func_021E8BD0.c..ov093_func_021E8C9C.c: c99=DIFF nolang=DIFF
- ov093_func_021E8D04.c..ov093_func_021E8F20.c: c99=CCERR: line 202: illegal implicit conversion from 'void *' to | line 202: 'unsigned short' nolang=CCERR: line 202: illegal implicit conversion from 'void *' to | line 202: 'unsigned short'
- ov093_func_021E8DC4.c..ov093_func_021E8F20.c: c99=CCERR: line 152: illegal implicit conversion from 'void *' to | line 152: 'unsigned short' nolang=CCERR: line 152: illegal implicit conversion from 'void *' to | line 152: 'unsigned short'
- ov093_func_021E8DC4.c..func_021E8E28.c: prototype of func_021E8E38 differs between members (src/matched/ov/func_021E8E28.c)
- no verified entry for 021E9024

Members, in address order:

- `ov093_func_021E8BD0.c`
- `ov093_func_021E8DC4.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names btlv_core.c` again.
