# unit_06898BFC.c (ov095)

Translation unit 06898BFC..06898CE0, 4 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_06898BFC.c` is blocked by:

- ov095_func_06898BFC.c..ov095_func_06898C10.c: global g_0689E7E0 declared two ways (src/matched/ov/ov095_func_06898C10.c)
- no verified entry for 06898CC0, 06898CD0

Members, in address order:

- `ov095_func_06898BFC.c`
- `ov095_func_06898C10.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_06898BFC.c` again.
