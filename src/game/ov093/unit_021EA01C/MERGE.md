# unit_021EA01C.c (ov093)

Translation unit 021EA01C..021EAA34, 74 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021EA01C.c` is blocked by:

- func_021EA01C.c..ov093_func_021EAA00.c: c99=CCERR: line 752: illegal implicit conversion from 'struct H *' to | line 752: 'struct H_021EA55C *' | line 764: illegal implicit conversion from 'struct H_021EA614 *' to nolang=CCERR: line 752: il
- no verified entry for 021EAA24

Members, in address order:


To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021EA01C.c` again.
