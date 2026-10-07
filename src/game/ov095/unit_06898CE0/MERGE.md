# unit_06898CE0.c (ov095)

Translation unit 06898CE0..06898E1C, 8 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_06898CE0.c` is blocked by:

- ov095_func_06898CE0.c..ov095_func_06898DE0.c: global g_0689E7E0 declared two ways (src/matched/ov/ov095_func_06898D54.c)
- ov095_func_06898D10.c..ov095_func_06898DE0.c: global g_0689E7E0 declared two ways (src/matched/ov/ov095_func_06898D54.c)
- ov095_func_06898D54.c..ov095_func_06898DE0.c: c99=DIFF nolang=DIFF
- no verified entry for 06898D44, 06898DD0, 06898E0C

Members, in address order:

- `ov095_func_06898D10.c`
- `ov095_func_06898D54.c`
- `ov095_func_06898DE0.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_06898CE0.c` again.
