# unit_021C2A3C.c (ov016)

Translation unit 021C2A3C..021C2C94, 2 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021C2A3C.c` is blocked by:

- func_021C2A3C.c..ov016_func_021C2B00.c: global g_021DE5A8 declared two ways (src/matched/ov_sdk/ov016_func_021C2B00.c)

Members, in address order:

- `func_021C2A3C.c`
- `ov016_func_021C2B00.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021C2A3C.c` again.
