# unit_021EE740.c (ov026)

Translation unit 021EE740..021EFBA4, 43 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021EE740.c` is blocked by:

- ov026_func_021EE740.c..ov026_func_021EF9D8.c: prototype of func_021A2564 differs between members (src/matched/ov/ov026_func_021EE888.c); type typedef Pt differs between members (src/matched/ov/ov026_func_021EEA18.c); type typedef Pt differs betwe
- ov026_func_021EE740.c..ov026_func_021EEFA8.c: prototype of func_021A2564 differs between members (src/matched/ov/ov026_func_021EE888.c)
- ov026_func_021EE740.c..ov026_func_021EEAEC.c: prototype of func_021A2564 differs between members (src/matched/ov/ov026_func_021EE888.c)
- ov026_func_021EE740.c..ov026_func_021EE8B8.c: prototype of func_021A2564 differs between members (src/matched/ov/ov026_func_021EE888.c)
- ov026_func_021EF078.c..ov026_func_021EF9D8.c: prototype of func_02082BCC differs between members (src/matched/ov/ov026_func_021EF9CC.c)
- ov026_func_021EF4D0.c..ov026_func_021EF9D8.c: prototype of func_02082BCC differs between members (src/matched/ov/ov026_func_021EF9CC.c)
- ov026_func_021EF920.c..ov026_func_021EF9D8.c: prototype of func_02082BCC differs between members (src/matched/ov/ov026_func_021EF9CC.c)
- ov026_func_021EF9B0.c..ov026_func_021EF9D8.c: prototype of func_02082BCC differs between members (src/matched/ov/ov026_func_021EF9CC.c)

Members, in address order:

- `ov026_func_021EF9B0.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021EE740.c` again.
