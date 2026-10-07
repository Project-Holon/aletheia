# unit_021E3420.c (ov093)

Translation unit 021E3420..021E37C0, 11 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021E3420.c` is blocked by:

- func_021E3420.c..ov093_func_021E36F4.c: c99=CCERR: line 158: illegal implicit conversion from 'int' to | line 158: 'struct Node *' | line 209: illegal implicit conversion from 'int' to nolang=CCERR: line 158: illegal implicit conversion fro
- func_021E3420.c..func_021E357C.c: c99=DIFF nolang=DIFF
- func_021E3420.c..ov093_func_021E34B4.c: c99=DIFF nolang=DIFF
- ov093_func_021E35A0.c..ov093_func_021E36F4.c: c99=CCERR: line 119: illegal implicit conversion from 'int' to | line 119: 'struct Node *' nolang=CCERR: line 119: illegal implicit conversion from 'int' to | line 119: 'struct Node *'
- func_021E36A4.c..ov093_func_021E36F4.c: c99=DIFF nolang=DIFF

Members, in address order:

- `func_021E3420.c`
- `ov093_func_021E34B4.c`
- `func_021E36A4.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021E3420.c` again.
