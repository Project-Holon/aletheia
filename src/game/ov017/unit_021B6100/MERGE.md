# unit_021B6100.c (ov017)

Translation unit 021B6100..021B641C, 4 functions, confidence likely (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021B6100.c` is blocked by:

- ov017_func_021B6100.c..ov017_func_021B6368.c: prototype of func_0207E24C differs between members (src/matched/ov/ov017_func_021B6368.c)
- ov017_func_021B6298.c..ov017_func_021B6368.c: prototype of func_0207E24C differs between members (src/matched/ov/ov017_func_021B6368.c)

Members, in address order:

- `ov017_func_021B6298.c`
- `ov017_func_021B6368.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021B6100.c` again.
