# unit_021EE740.c (ov025)

Translation unit 021EE740..021EF634, 36 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021EE740.c` is blocked by:

- ov025_func_021EE740.c..ov025_func_021EF5D0.c: prototype of func_021A2564 differs between members (src/matched/ov/ov025_func_021EE888.c); prototype of func_021A2564 differs between members (src/matched/ov/ov025_func_021EE8B0.c); global d_021EF770 
- ov025_func_021EE740.c..ov025_func_021EEE04.c: prototype of func_021A2564 differs between members (src/matched/ov/ov025_func_021EE888.c); prototype of func_021A2564 differs between members (src/matched/ov/ov025_func_021EE8B0.c); global d_021EF770 
- ov025_func_021EE740.c..ov025_func_021EEA34.c: prototype of func_021A2564 differs between members (src/matched/ov/ov025_func_021EE888.c); prototype of func_021A2564 differs between members (src/matched/ov/ov025_func_021EE8B0.c)
- ov025_func_021EE740.c..ov025_func_021EE888.c: prototype of func_021A2564 differs between members (src/matched/ov/ov025_func_021EE888.c)
- ov025_func_021EE8B0.c..ov025_func_021EEA34.c: prototype of func_021A2564 differs between members (src/matched/ov/ov025_func_021EE8EC.c)
- ov025_func_021EE8B0.c..ov025_func_021EE8EC.c: prototype of func_021A2564 differs between members (src/matched/ov/ov025_func_021EE8EC.c)
- ov025_func_021EEB0C.c..ov025_func_021EEE04.c: global d_021EF770 declared two ways (src/matched/ov/ov025_func_021EEE04.c)
- ov025_func_021EEB0C.c..ov025_func_021EEC64.c: prototype of func_021EEE04 differs between members (src/matched/ov/ov025_func_021EEC64.c)
- ov025_func_021EEBE4.c..ov025_func_021EEC64.c: prototype of func_021EEE04 differs between members (src/matched/ov/ov025_func_021EEC64.c)
- ov025_func_021EEEE0.c..ov025_func_021EF5D0.c: prototype of func_021A2564 differs between members (src/matched/ov/ov025_func_021EF0D0.c); prototype of func_021A2564 differs between members (src/matched/ov/ov025_func_021EF4E4.c)
- ov025_func_021EEEE0.c..ov025_func_021EF1C4.c: prototype of func_021A2564 differs between members (src/matched/ov/ov025_func_021EF0D0.c)
- ov025_func_021EF0D0.c..ov025_func_021EF1C4.c: prototype of func_021A2564 differs between members (src/matched/ov/ov025_func_021EF12C.c)
- ov025_func_021EF2D4.c..ov025_func_021EF5D0.c: prototype of func_021A2564 differs between members (src/matched/ov/ov025_func_021EF4E4.c)
- ov025_func_021EF4E4.c..ov025_func_021EF5D0.c: prototype of func_021A2564 differs between members (src/matched/ov/ov025_func_021EF538.c)

Members, in address order:

- `ov025_func_021EE8B0.c`
- `ov025_func_021EE8EC.c`
- `ov025_func_021EEBE4.c`
- `ov025_func_021EEC64.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021EE740.c` again.
