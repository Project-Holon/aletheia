# unit_021E18EC.c (ov093)

Translation unit 021E18EC..021E1B4C, 14 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021E18EC.c` is blocked by:

- ov093_func_021E18EC.c..ov093_func_021E1AE4.c: c99=CCERR: line 111: illegal implicit conversion from 'int' to | line 111: 'void *' | line 115: illegal implicit conversion from 'int' to nolang=CCERR: line 111: illegal implicit conversion from 'int'
- ov093_func_021E18EC.c..func_021E199C.c: c99=DIFF nolang=DIFF
- ov093_func_021E18EC.c..func_021E1948.c: c99=DIFF nolang=DIFF
- func_021E1958.c..func_021E199C.c: c99=DIFF nolang=DIFF
- func_021E1958.c..func_021E197C.c: c99=DIFF nolang=DIFF
- func_021E19C0.c..ov093_func_021E1AE4.c: c99=CCERR: line 80: illegal implicit conversion from 'int' to | line 80: 'void *' | line 84: illegal implicit conversion from 'int' to nolang=CCERR: line 80: illegal implicit conversion from 'int' to 
- ov093_func_021E19F8.c..ov093_func_021E1AE4.c: c99=CCERR: line 69: illegal implicit conversion from 'struct Ent_021E19F8 *' to | line 69: 'struct Ent_021E1AE4 *' | line 80: illegal implicit conversion from 'struct Ent_021E1A2C *' to nolang=CCERR: 
- ov093_func_021E19F8.c..ov093_func_021E1A2C.c: prototype of func_021E1AE4 differs between members (src/matched/ov/ov093_func_021E1A2C.c)

Members, in address order:

- `ov093_func_021E18EC.c`
- `func_021E1958.c`
- `func_021E197C.c`
- `ov093_func_021E19F8.c`
- `ov093_func_021E1A2C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021E18EC.c` again.
