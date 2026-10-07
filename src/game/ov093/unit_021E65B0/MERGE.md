# unit_021E65B0.c (ov093)

Translation unit 021E65B0..021E6994, 13 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021E65B0.c` is blocked by:

- ov093_func_021E65B0.c..ov093_func_021E695C.c: c99=CCERR: line 167: illegal implicit conversion from 'int' to | line 167: 'struct Node *' nolang=CCERR: line 167: illegal implicit conversion from 'int' to | line 167: 'struct Node *'
- ov093_func_021E65B0.c..ov093_func_021E66CC.c: c99=DIFF nolang=DIFF
- ov093_func_021E666C.c..ov093_func_021E66CC.c: c99=DIFF nolang=DIFF
- func_021E66A8.c..ov093_func_021E66CC.c: c99=DIFF nolang=DIFF
- func_021E6710.c..ov093_func_021E695C.c: c99=CCERR: line 75: illegal implicit conversion from 'int' to | line 75: 'struct Node *' nolang=CCERR: line 75: illegal implicit conversion from 'int' to | line 75: 'struct Node *'
- func_021E6710.c..ov093_func_021E6800.c: c99=CCERR: line 62: illegal implicit conversion from 'int' to | line 62: 'struct Node *' nolang=CCERR: line 62: illegal implicit conversion from 'int' to | line 62: 'struct Node *'
- ov093_func_021E6728.c..ov093_func_021E6800.c: c99=DIFF nolang=DIFF
- ov093_func_021E6840.c..ov093_func_021E695C.c: c99=DIFF nolang=DIFF
- ov093_func_021E6924.c..ov093_func_021E695C.c: c99=DIFF nolang=DIFF
- no verified entry for 021E67E4, 021E6908

Members, in address order:

- `ov093_func_021E666C.c`
- `func_021E66A8.c`
- `ov093_func_021E66CC.c`
- `func_021E6710.c`
- `ov093_func_021E6728.c`
- `ov093_func_021E6800.c`
- `ov093_func_021E6840.c`
- `ov093_func_021E6924.c`
- `ov093_func_021E695C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021E65B0.c` again.
