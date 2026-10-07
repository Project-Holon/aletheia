# unit_021C1D30.c (ov114)

Translation unit 021C1D30..021C2270, 5 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021C1D30.c` is blocked by:

- ov114_func_021C1D30.c..ov114_func_021C20A4.c: c99=CCERR: line 227: illegal implicit conversion from 'struct GHIConnection_021C1DEC *' to | line 227: 'struct GHIConnection_021C1D30 *' | line 348: illegal implicit conversion from 'struct GHIConnect
- ov114_func_021C1D30.c..ov114_func_021C1DEC.c: c99=CCERR: line 157: illegal implicit conversion from 'struct GHIConnection_021C1DEC *' to | line 157: 'struct GHIConnection_021C1D30 *' nolang=CCERR: line 157: illegal implicit conversion from 'struc

Members, in address order:

- `ov114_func_021C1D30.c`
- `ov114_func_021C1DEC.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021C1D30.c` again.
