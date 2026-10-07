# unit_021D9118.c (ov093)

Translation unit 021D9118..021D93D8, 15 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021D9118.c` is blocked by:

- ov093_func_021D9118.c..ov093_func_021D93A8.c: c99=CCERR: line 146: illegal implicit conversion from 'int' to | line 146: 'void *' | line 160: illegal implicit conversion from 'int' to nolang=CCERR: line 146: illegal implicit conversion from 'int'
- ov093_func_021D9118.c..func_021D9240.c: c99=DIFF nolang=DIFF
- ov093_func_021D9118.c..ov093_func_021D919C.c: c99=DIFF nolang=DIFF
- ov093_func_021D9154.c..ov093_func_021D919C.c: c99=DIFF nolang=DIFF
- func_021D91E4.c..func_021D9240.c: c99=DIFF nolang=DIFF
- func_021D91E4.c..func_021D9214.c: c99=DIFF nolang=DIFF
- func_021D9224.c..func_021D9240.c: c99=DIFF nolang=DIFF
- func_021D9250.c..ov093_func_021D93A8.c: c99=CCERR: line 69: illegal implicit conversion from 'int' to | line 69: 'void *' | line 83: illegal implicit conversion from 'int' to nolang=CCERR: line 69: illegal implicit conversion from 'int' to 
- func_021D9250.c..ov093_func_021D928C.c: c99=DIFF nolang=DIFF
- func_021D9250.c..func_021D926C.c: c99=DIFF nolang=DIFF

Members, in address order:

- `ov093_func_021D9118.c`
- `ov093_func_021D9154.c`
- `ov093_func_021D919C.c`
- `func_021D91E4.c`
- `func_021D9214.c`
- `func_021D9224.c`
- `func_021D9240.c`
- `func_021D9250.c`
- `func_021D926C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021D9118.c` again.
