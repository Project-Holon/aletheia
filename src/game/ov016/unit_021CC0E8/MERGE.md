# unit_021CC0E8.c (ov016)

Translation unit 021CC0E8..021CC998, 10 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021CC0E8.c` is blocked by:

- ov016_func_021CC0E8.c..ov016_func_021CC8C4.c: type typedef SCENESETSELECTAP_BSS differs between members (src/matched/ov_sdk/ov016_func_021CC244.c); type typedef SCENESETSELECTAP_BSS differs between members (src/matched/ov_sdk/ov016_func_021CC6AC.
- ov016_func_021CC0E8.c..ov016_func_021CC46C.c: c99=CCERR: line 108: struct/union/enum/class tag 'tagSETTINGINFO' redefined nolang=CCERR: line 70: undefined identifier '_Bool' | line 108: struct/union/enum/class tag 'tagSETTINGINFO' redefined | lin
- ov016_func_021CC244.c..ov016_func_021CC46C.c: c99=CCERR: line 85: struct/union/enum/class tag 'tagSETTINGINFO' redefined nolang=CCERR: line 54: undefined identifier '_Bool' | line 85: struct/union/enum/class tag 'tagSETTINGINFO' redefined | line 
- ov016_func_021CC4E8.c..ov016_func_021CC8C4.c: prototype of DWCi_CELLlGetObj differs between members (src/matched/ov_sdk/ov016_func_021CC740.c); prototype of DWCi_CEINlSet differs between members (src/matched/ov_sdk/ov016_func_021CC740.c)

Members, in address order:

- `ov016_func_021CC244.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021CC0E8.c` again.
