# unit_021C0244.c (ov114)

Translation unit 021C0244..021C0368, 3 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021C0244.c` is blocked by:

- ov114_func_021C0244.c..ov114_func_021C0318.c: c99=CCERR: line 54: struct/union/enum/class tag 'GHIConnection' redefined | line 65: identifier 'GHIConnection' redeclared | line 65: was declared as: 'struct GHIConnection' nolang=CCERR: line 54: str
- ov114_func_021C02C8.c..ov114_func_021C0318.c: c99=CCERR: line 32: struct/union/enum/class tag 'GHIConnection' redefined | line 43: identifier 'GHIConnection' redeclared | line 43: was declared as: 'struct GHIConnection' nolang=CCERR: line 32: str

Members, in address order:

- `ov114_func_021C0244.c`
- `ov114_func_021C02C8.c`
- `ov114_func_021C0318.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021C0244.c` again.
