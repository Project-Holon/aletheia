# unit_021C6A10.c (ov016)

Translation unit 021C6A10..021C7088, 11 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021C6A10.c` is blocked by:

- ov016_func_021C6A10.c..ov016_func_021C7044.c: prototype of DWCi_ChangeScene differs between members (src/matched/ov_sdk/ov016_func_021C6A2C.c); prototype of DWCi_ChangeScene differs between members (src/matched/ov_sdk/ov016_func_021C6A5C.c); prot
- ov016_func_021C6A10.c..ov016_func_021C6C30.c: prototype of DWCi_ChangeScene differs between members (src/matched/ov_sdk/ov016_func_021C6A2C.c); prototype of DWCi_ChangeScene differs between members (src/matched/ov_sdk/ov016_func_021C6A5C.c); prot
- ov016_func_021C6A10.c..ov016_func_021C6A2C.c: prototype of DWCi_ChangeScene differs between members (src/matched/ov_sdk/ov016_func_021C6A2C.c)

Members, in address order:

- `ov016_func_021C6A10.c`
- `ov016_func_021C6A2C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021C6A10.c` again.
