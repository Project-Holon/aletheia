# unit_021D93D8.c (ov093)

Translation unit 021D93D8..021D9ADC, 28 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021D93D8.c` is blocked by:

- func_021D93D8.c..ov093_func_021D9A68.c: c99=CCERR: line 263: illegal implicit conversion from 'int' to | line 263: 'void *' nolang=CCERR: line 263: illegal implicit conversion from 'int' to | line 263: 'void *'
- func_021D93D8.c..ov093_func_021D96DC.c: c99=CCERR: line 218: illegal implicit conversion from 'int' to | line 218: 'void *' nolang=CCERR: line 218: illegal implicit conversion from 'int' to | line 218: 'void *'
- func_021D93D8.c..func_021D9544.c: c99=DIFF nolang=DIFF
- func_021D93D8.c..func_021D9460.c: c99=DIFF nolang=DIFF
- func_021D9484.c..func_021D9544.c: c99=DIFF nolang=DIFF
- func_021D9484.c..func_021D94C4.c: c99=DIFF nolang=DIFF
- func_021D9504.c..func_021D9544.c: c99=DIFF nolang=DIFF
- ov093_func_021D9558.c..ov093_func_021D96DC.c: c99=CCERR: line 143: illegal implicit conversion from 'int' to | line 143: 'void *' nolang=CCERR: line 143: illegal implicit conversion from 'int' to | line 143: 'void *'
- ov093_func_021D9558.c..ov093_func_021D95CC.c: c99=DIFF nolang=DIFF
- func_021D9598.c..ov093_func_021D95CC.c: c99=DIFF nolang=DIFF
- ov093_func_021D9648.c..ov093_func_021D96DC.c: c99=CCERR: line 76: illegal implicit conversion from 'int' to | line 76: 'void *' nolang=CCERR: line 76: illegal implicit conversion from 'int' to | line 76: 'void *'
- func_021D96FC.c..ov093_func_021D9A68.c: c99=DIFF nolang=DIFF
- func_021D96FC.c..ov093_func_021D9978.c: c99=DIFF nolang=DIFF
- func_021D96FC.c..func_021D97EC.c: c99=DIFF nolang=DIFF
- ov093_func_021D99A4.c..ov093_func_021D9A68.c: c99=DIFF nolang=DIFF
- ov093_func_021D99F8.c..ov093_func_021D9A68.c: c99=DIFF nolang=DIFF
- func_021D9A44.c..ov093_func_021D9A68.c: c99=DIFF nolang=DIFF

Members, in address order:

- `func_021D93D8.c`
- `func_021D9484.c`
- `func_021D94C4.c`
- `func_021D9504.c`
- `func_021D9544.c`
- `ov093_func_021D9558.c`
- `func_021D9598.c`
- `ov093_func_021D95CC.c`
- `func_021D96FC.c`
- `func_021D9A44.c`
- `ov093_func_021D9A68.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021D93D8.c` again.
