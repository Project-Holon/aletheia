# unit_021BF988.c (ov016)

Translation unit 021BF988..021C07A8, 15 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021BF988.c` is blocked by:

- ov016_func_021BF988.c..ov016_func_021C06E8.c: type typedef MEMKB10 differs between members (src/matched/ov_sdk/ov016_func_021BFB38.c); prototype of DWCi_CEINlSetExCell differs between members (src/matched/ov_sdk/ov016_func_021BFB38.c); prototype 
- ov016_func_021BF988.c..ov016_func_021C0328.c: type typedef MEMKB10 differs between members (src/matched/ov_sdk/ov016_func_021BFB38.c); prototype of DWCi_CEINlSetExCell differs between members (src/matched/ov_sdk/ov016_func_021BFB38.c); prototype 
- func_021BFED0.c..ov016_func_021C0328.c: type typedef MEMKB10 differs between members (src/matched/ov_sdk/ov016_func_021C00A8.c); prototype of DWCi_CEINlSetExCell differs between members (src/matched/ov_sdk/ov016_func_021C00A8.c); prototype 
- ov016_func_021C00A8.c..ov016_func_021C0328.c: type typedef MEMKB10 differs between members (src/matched/ov_sdk/ov016_func_021C0328.c); prototype of DWCi_CEINlSetExCell differs between members (src/matched/ov_sdk/ov016_func_021C0328.c); prototype 

Members, in address order:

- `ov016_func_021C00A8.c`
- `ov016_func_021C0328.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021BF988.c` again.
