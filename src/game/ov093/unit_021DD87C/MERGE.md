# unit_021DD87C.c (ov093)

Translation unit 021DD87C..021DDAC4, 10 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021DD87C.c` is blocked by:

- func_021DD87C.c..ov093_func_021DDA6C.c: c99=CCERR: line 84: illegal implicit conversion from 'int' to | line 84: 'void *' | line 91: illegal implicit conversion from 'int' to nolang=CCERR: line 84: illegal implicit conversion from 'int' to 
- func_021DD87C.c..func_021DD8EC.c: c99=DIFF nolang=DIFF
- func_021DD87C.c..func_021DD898.c: c99=DIFF nolang=DIFF
- func_021DD8B4.c..func_021DD8EC.c: c99=DIFF nolang=DIFF
- func_021DD8D0.c..func_021DD8EC.c: c99=DIFF nolang=DIFF
- func_021DD908.c..ov093_func_021DDA6C.c: c99=DIFF nolang=DIFF
- func_021DD908.c..ov093_func_021DD98C.c: c99=DIFF nolang=DIFF
- ov093_func_021DD9E8.c..ov093_func_021DDA6C.c: c99=DIFF nolang=DIFF

Members, in address order:

- `func_021DD87C.c`
- `func_021DD898.c`
- `func_021DD8B4.c`
- `func_021DD8D0.c`
- `func_021DD8EC.c`
- `func_021DD908.c`
- `ov093_func_021DD98C.c`
- `ov093_func_021DD9E8.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021DD87C.c` again.
