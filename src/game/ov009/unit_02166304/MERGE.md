# unit_02166304.c (ov009)

Translation unit 02166304..02166378, 2 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_02166304.c` is blocked by:

- ov009_func_02166304.c..ov009_func_02166358.c: global g_021AA7DC declared two ways (src/matched/ov_sdk/ov009_func_02166358.c)

Members, in address order:

- `ov009_func_02166304.c`
- `ov009_func_02166358.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_02166304.c` again.
