# unit_021BD8D8.c (ov016)

Translation unit 021BD8D8..021BF390, 30 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021BD8D8.c` is blocked by:

- ov016_func_021BD8D8.c..ov016_func_021BF2B0.c: type typedef MEMKB differs between members (src/matched/ov_sdk/ov016_func_021BDC24.c); global keyboard_data declared two ways (src/matched/ov_sdk/ov016_func_021BDC24.c); global DWCi_R_SCR declared two
- ov016_func_021BD8D8.c..ov016_func_021BE384.c: type typedef MEMKB differs between members (src/matched/ov_sdk/ov016_func_021BDC24.c); global keyboard_data declared two ways (src/matched/ov_sdk/ov016_func_021BDC24.c); global DWCi_R_SCR declared two
- ov016_func_021BD8D8.c..ov016_func_021BDCAC.c: type typedef MEMKB differs between members (src/matched/ov_sdk/ov016_func_021BDC24.c); global keyboard_data declared two ways (src/matched/ov_sdk/ov016_func_021BDC24.c); prototype of DWCi_CEINlSetExCe
- ov016_func_021BD8D8.c..func_021BDC54.c: type typedef MEMKB differs between members (src/matched/ov_sdk/ov016_func_021BDC24.c); global keyboard_data declared two ways (src/matched/ov_sdk/ov016_func_021BDC24.c); prototype of DWCi_CEINlSetExCe
- ov016_func_021BDD24.c..ov016_func_021BE384.c: global DWCi_R_SCR declared two ways (src/matched/ov_sdk/ov016_func_021BDD9C.c); prototype of DWCi_Coord2Rect differs between members (src/matched/ov_sdk/ov016_func_021BDD9C.c); prototype of DWCi_TPlCh
- func_021BDF08.c..ov016_func_021BE384.c: prototype of DWCi_Coord2Rect differs between members (src/matched/ov_sdk/ov016_func_021BE0D8.c); prototype of DWCi_TPlCheck differs between members (src/matched/ov_sdk/ov016_func_021BE0D8.c); prototyp
- ov016_func_021BE0D8.c..ov016_func_021BE384.c: global keyboard_data declared two ways (src/matched/ov_sdk/ov016_func_021BE384.c); global DWCi_R_SCR declared two ways (src/matched/ov_sdk/ov016_func_021BE384.c); prototype of DWCi_Coord2Rect differs 
- ov016_func_021BE3B4.c..ov016_func_021BF2B0.c: type typedef MEMKB differs between members (src/matched/ov_sdk/ov016_func_021BE3E4.c); global DWCi_R_SCR declared two ways (src/matched/ov_sdk/ov016_func_021BE3E4.c); prototype of DWCi_CEINlSetExCell 
- ov016_func_021BE3B4.c..ov016_func_021BEB58.c: type typedef MEMKB differs between members (src/matched/ov_sdk/ov016_func_021BE3E4.c); global DWCi_R_SCR declared two ways (src/matched/ov_sdk/ov016_func_021BE3E4.c); prototype of DWCi_CEINlSetExCell 
- ov016_func_021BE3B4.c..ov016_func_021BE5CC.c: global DWCi_R_SCR declared two ways (src/matched/ov_sdk/ov016_func_021BE3E4.c); prototype of DWCi_Coord2Rect differs between members (src/matched/ov_sdk/ov016_func_021BE3E4.c); prototype of DWCi_TPlCh
- ov016_func_021BE3E4.c..ov016_func_021BE5CC.c: global DWCi_R_SCR declared two ways (src/matched/ov_sdk/ov016_func_021BE5CC.c); prototype of DWCi_Coord2Rect differs between members (src/matched/ov_sdk/ov016_func_021BE5CC.c); prototype of DWCi_TPlCh
- ov016_func_021BE618.c..ov016_func_021BEB58.c: type typedef MEMKB differs between members (src/matched/ov_sdk/ov016_func_021BE844.c); global keyboard_data declared two ways (src/matched/ov_sdk/ov016_func_021BE844.c); prototype of DWCi_CEINlSetExCe
- ov016_func_021BE618.c..ov016_func_021BE844.c: type typedef MEMKB differs between members (src/matched/ov_sdk/ov016_func_021BE844.c); global keyboard_data declared two ways (src/matched/ov_sdk/ov016_func_021BE844.c); prototype of DWCi_CEINlSetExCe

Members, in address order:

- `ov016_func_021BD8D8.c`
- `ov016_func_021BE0D8.c`
- `ov016_func_021BE384.c`
- `ov016_func_021BE3B4.c`
- `ov016_func_021BE3E4.c`
- `ov016_func_021BE5CC.c`
- `ov016_func_021BE618.c`
- `ov016_func_021BE844.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021BD8D8.c` again.
