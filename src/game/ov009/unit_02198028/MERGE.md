# unit_02198028.c (ov009)

Translation unit 02198028..02198620, 8 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_02198028.c` is blocked by:

- ov009_func_02198028.c..ov009_func_021985E4.c: prototype of func_02197D5C differs between members (src/matched/ov_sdk/ov009_func_02198328.c)
- ov009_func_02198028.c..ov009_func_02198328.c: prototype of func_02197D5C differs between members (src/matched/ov_sdk/ov009_func_02198328.c)
- ov009_func_02198028.c..ov009_func_02198038.c: c99=CCERR: line 121: illegal use of type 'void' nolang=CCERR: line 121: illegal use of type 'void'

Members, in address order:

- `ov009_func_02198028.c`
- `ov009_func_02198038.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_02198028.c` again.
