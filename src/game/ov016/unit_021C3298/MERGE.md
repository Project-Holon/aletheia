# unit_021C3298.c (ov016)

Translation unit 021C3298..021C33CC, 3 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021C3298.c` is blocked by:

- ov016_func_021C3298.c..ov016_func_021C3358.c: global g_021DE5B4 declared two ways (src/matched/ov_sdk/ov016_func_021C3358.c)
- func_021C32C0.c..ov016_func_021C3358.c: global g_021DE5B4 declared two ways (src/matched/ov_sdk/ov016_func_021C3358.c)

Members, in address order:

- `ov016_func_021C3298.c`
- `func_021C32C0.c`
- `ov016_func_021C3358.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021C3298.c` again.
