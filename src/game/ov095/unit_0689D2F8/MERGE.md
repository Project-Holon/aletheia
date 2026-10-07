# unit_0689D2F8.c (ov095)

Translation unit 0689D2F8..0689D4F0, 13 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_0689D2F8.c` is blocked by:

- ov095_func_0689D2F8.c..ov095_func_0689D448.c: type typedef T differs between members (src/matched/ov/ov095_func_0689D338.c); type typedef T differs between members (src/matched/ov/ov095_func_0689D448.c)
- ov095_func_0689D338.c..ov095_func_0689D448.c: type typedef T differs between members (src/matched/ov/ov095_func_0689D448.c)
- no verified entry for 0689D408, 0689D418, 0689D428, 0689D438, 0689D4A0, 0689D4B0, 0689D4C0, 0689D4D0

Members, in address order:

- `ov095_func_0689D338.c`
- `ov095_func_0689D448.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_0689D2F8.c` again.
