# unit_021990A0.c (ov009)

Translation unit 021990A0..021992FC, 7 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021990A0.c` is blocked by:

- ov009_func_021990A0.c..ov009_func_021992A8.c: c99=CCERR: line 59: struct/union/enum/class tag '_NATNegotiator' redefined | line 63: struct/union/enum/class tag '_NATNegotiator' redefined nolang=CCERR: line 59: struct/union/enum/class tag '_NATNeg
- ov009_func_021990A0.c..ov009_func_02199138.c: c99=CCERR: line 48: struct/union/enum/class tag '_NATNegotiator' redefined nolang=CCERR: line 48: struct/union/enum/class tag '_NATNegotiator' redefined
- ov009_func_021990D4.c..ov009_func_02199138.c: c99=CCERR: line 27: struct/union/enum/class tag '_NATNegotiator' redefined nolang=CCERR: line 27: struct/union/enum/class tag '_NATNegotiator' redefined

Members, in address order:

- `ov009_func_021990A0.c`
- `ov009_func_021990D4.c`
- `ov009_func_02199138.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021990A0.c` again.
