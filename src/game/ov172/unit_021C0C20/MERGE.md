# unit_021C0C20.c (ov172)

Translation unit 021C0C20..021C2CDC, 19 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021C0C20.c` is blocked by:

- ov172_func_021C0C20.c..ov172_func_021C2B74.c: global g_021CADE4 declared two ways (src/matched/ov_sdk/ov172_func_021C1248.c); prototype of _u32_div_f differs between members (src/matched/ov_sdk/ov172_func_021C1F04.c); prototype of MI_CpuCopy8 dif
- ov172_func_021C0C20.c..ov172_func_021C1710.c: global g_021CADE4 declared two ways (src/matched/ov_sdk/ov172_func_021C1248.c); type typedef huffman_structure differs between members (src/matched/ov_sdk/ov172_func_021C131C.c)
- ov172_func_021C0C20.c..ov172_func_021C104C.c: c99=DIFF nolang=DIFF
- ov172_func_021C0C20.c..ov172_func_021C0C3C.c: c99=DIFF nolang=DIFF
- ov172_func_021C1868.c..ov172_func_021C2B74.c: prototype of _u32_div_f differs between members (src/matched/ov_sdk/ov172_func_021C1F04.c); prototype of MI_CpuCopy8 differs between members (src/matched/ov_sdk/ov172_func_021C20B0.c)
- ov172_func_021C1F04.c..ov172_func_021C2B74.c: c99=DIFF nolang=DIFF

Members, in address order:

- `ov172_func_021C0C20.c`
- `ov172_func_021C0C3C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021C0C20.c` again.
