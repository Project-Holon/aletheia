# unit_021BC240.c (ov209)

Translation unit 021BC240..021BC388, 11 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021BC240.c` is blocked by:

- ov209_func_021BC240.c..ov209_func_021BC380.c: global d_021BE7D4 declared two ways (src/matched/ov/ov209_func_021BC380.c)
- ov209_func_021BC2BC.c..ov209_func_021BC380.c: global d_021BE7D4 declared two ways (src/matched/ov/ov209_func_021BC380.c)
- ov209_func_021BC308.c..ov209_func_021BC380.c: global d_021BE7D4 declared two ways (src/matched/ov/ov209_func_021BC380.c)
- ov209_func_021BC370.c..ov209_func_021BC380.c: global d_021BE7D4 declared two ways (src/matched/ov/ov209_func_021BC380.c)

Members, in address order:

- `ov209_func_021BC308.c`
- `ov209_func_021BC370.c`
- `ov209_func_021BC380.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021BC240.c` again.
