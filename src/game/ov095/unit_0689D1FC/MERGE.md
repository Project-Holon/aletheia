# unit_0689D1FC.c (ov095)

Translation unit 0689D1FC..0689D2F8, 7 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_0689D1FC.c` is blocked by:

- ov095_func_0689D1FC.c..ov095_func_0689D258.c: c99=CCERR: line 59: illegal implicit conversion from 'unsigned char *' to | line 59: 'struct  *' nolang=CCERR: line 59: illegal implicit conversion from 'unsigned char *' to | line 59: 'struct  *'
- no verified entry for 0689D248, 0689D2B8, 0689D2C8, 0689D2D8, 0689D2E8

Members, in address order:

- `ov095_func_0689D1FC.c`
- `ov095_func_0689D258.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_0689D1FC.c` again.
