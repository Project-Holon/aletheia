# unit_021EAC54.c (ov093)

Translation unit 021EAC54..021EAEA8, 18 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021EAC54.c` is blocked by:

- func_021EAC54.c..ov093_func_021EAE74.c: c99=CCERR: line 190: illegal implicit conversion from 'unsigned int' to | line 190: 'void *' nolang=CCERR: line 190: illegal implicit conversion from 'unsigned int' to | line 190: 'void *'
- func_021EAC54.c..ov093_func_021EADE4.c: c99=DIFF nolang=DIFF
- func_021EAC54.c..ov093_func_021EADA4.c: c99=DIFF nolang=DIFF
- ov093_func_021EAC80.c..ov093_func_021EADA4.c: c99=DIFF nolang=DIFF
- ov093_func_021EADF4.c..ov093_func_021EAE74.c: c99=CCERR: line 69: illegal implicit conversion from 'unsigned int' to | line 69: 'void *' nolang=CCERR: line 69: illegal implicit conversion from 'unsigned int' to | line 69: 'void *'
- ov093_func_021EADF4.c..ov093_func_021EAE24.c: c99=CCERR: line 59: illegal implicit conversion from 'unsigned int' to | line 59: 'void *' nolang=CCERR: line 59: illegal implicit conversion from 'unsigned int' to | line 59: 'void *'
- func_021EAE14.c..ov093_func_021EAE24.c: c99=CCERR: line 42: illegal implicit conversion from 'unsigned int' to | line 42: 'void *' nolang=CCERR: line 42: illegal implicit conversion from 'unsigned int' to | line 42: 'void *'
- no verified entry for 021EAE98

Members, in address order:

- `ov093_func_021EAC80.c`
- `ov093_func_021EADA4.c`
- `func_021EAE14.c`
- `ov093_func_021EAE24.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021EAC54.c` again.
