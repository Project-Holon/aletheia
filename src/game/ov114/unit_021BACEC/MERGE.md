# unit_021BACEC.c (ov114)

Translation unit 021BACEC..021BAEC8, 5 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021BACEC.c` is blocked by:

- ov114_func_021BACEC.c..ov114_func_021BAE90.c: c99=CCERR: line 154: illegal implicit conversion from 'struct _NHTTPListInfo_021BADE0 *' to | line 154: 'struct _NHTTPListInfo_021BAD94 *' nolang=CCERR: line 154: illegal implicit conversion from 'str
- ov114_func_021BAD94.c..ov114_func_021BAE90.c: type struct _NHTTPListInfo differs between members (src/matched/ov_sdk/ov114_func_021BADE0.c)

Members, in address order:

- `ov114_func_021BAD94.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021BACEC.c` again.
