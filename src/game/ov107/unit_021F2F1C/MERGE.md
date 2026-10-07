# unit_021F2F1C.c (ov107)

Translation unit 021F2F1C..021F3C80, 10 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021F2F1C.c` is blocked by:

- ov107_func_021F2F1C.c..ov107_func_021F3BB8.c: prototype of MI_CpuCopy8 differs between members (src/matched/ov_sdk/ov107_func_021F3544.c); prototype of MI_CpuCopy8 differs between members (src/matched/ov_sdk/ov107_func_021F37BC.c); type typedef M
- ov107_func_021F2F1C.c..ov107_func_021F37BC.c: prototype of MI_CpuCopy8 differs between members (src/matched/ov_sdk/ov107_func_021F3544.c); prototype of MI_CpuCopy8 differs between members (src/matched/ov_sdk/ov107_func_021F37BC.c)
- ov107_func_021F34CC.c..ov107_func_021F37BC.c: prototype of MI_CpuCopy8 differs between members (src/matched/ov_sdk/ov107_func_021F37BC.c)
- ov107_func_021F3544.c..ov107_func_021F37BC.c: prototype of MI_CpuCopy8 differs between members (src/matched/ov_sdk/ov107_func_021F37BC.c)
- ov107_func_021F3830.c..ov107_func_021F3BB8.c: type typedef MB_BlockInfoTable differs between members (src/matched/ov_sdk/ov107_func_021F3A58.c); type typedef MbSegmentInfo differs between members (src/matched/ov_sdk/ov107_func_021F3A58.c); type t

Members, in address order:

- `ov107_func_021F34CC.c`
- `ov107_func_021F3544.c`
- `ov107_func_021F37BC.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021F2F1C.c` again.
