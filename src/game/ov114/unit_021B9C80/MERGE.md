# unit_021B9C80.c (ov114)

Translation unit 021B9C80..021BA014, 8 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021B9C80.c` is blocked by:

- ov114_func_021B9C80.c..ov114_func_021B9F94.c: prototype of func_0215F4DC differs between members (src/matched/ov_sdk/ov114_func_021B9ECC.c)
- ov114_func_021B9D8C.c..ov114_func_021B9F94.c: c99=CCERR: line 100: illegal implicit conversion from 'void *' to | line 100: 'int' | line 186: illegal implicit conversion from 'int' to nolang=CCERR: line 100: illegal implicit conversion from 'void
- ov114_func_021B9D8C.c..ov114_func_021B9E3C.c: c99=CCERR: line 81: illegal implicit conversion from 'void *' to | line 81: 'int' nolang=CCERR: line 81: illegal implicit conversion from 'void *' to | line 81: 'int'
- ov114_func_021B9ECC.c..ov114_func_021B9F94.c: c99=CCERR: line 84: illegal implicit conversion from 'int' to | line 84: 'char *' nolang=CCERR: line 84: illegal implicit conversion from 'int' to | line 84: 'char *'

Members, in address order:

- `ov114_func_021B9D8C.c`
- `ov114_func_021B9E3C.c`
- `ov114_func_021B9ECC.c`
- `ov114_func_021B9F94.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021B9C80.c` again.
