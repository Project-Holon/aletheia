# unit_02165B80.c (ov009)

Translation unit 02165B80..02166304, 13 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_02165B80.c` is blocked by:

- ov009_func_02165B80.c..ov009_func_021661F0.c: prototype of WCMi_GetSystemWork differs between members (src/matched/ov_sdk/ov009_func_02165BD0.c); prototype of WCMi_GetSystemWork differs between members (src/matched/ov_sdk/ov009_func_02165C28.c); 
- ov009_func_02165B80.c..ov009_func_02165DCC.c: prototype of WCMi_GetSystemWork differs between members (src/matched/ov_sdk/ov009_func_02165BD0.c); prototype of WCMi_GetSystemWork differs between members (src/matched/ov_sdk/ov009_func_02165C28.c); 
- ov009_func_02165CAC.c..ov009_func_02165DCC.c: c99=CCERR: line 173: illegal implicit conversion from 'struct WCMApList_02165DCC *' to | line 173: 'struct WCMApList_02165D04 *' nolang=CCERR: line 173: illegal implicit conversion from 'struct WCMApL
- ov009_func_02165E98.c..ov009_func_021661F0.c: prototype of WCMi_GetSystemWork differs between members (src/matched/ov_sdk/ov009_func_02165EC8.c); prototype of WCMi_GetSystemWork differs between members (src/matched/ov_sdk/ov009_func_02165F34.c)
- ov009_func_02165E98.c..ov009_func_02165F34.c: type struct WCMApListHeader differs between members (src/matched/ov_sdk/ov009_func_02165EC8.c); type struct WCMApListHeader differs between members (src/matched/ov_sdk/ov009_func_02165F34.c)
- ov009_func_02165EC8.c..ov009_func_02165F34.c: type struct WCMApListHeader differs between members (src/matched/ov_sdk/ov009_func_02165F34.c)
- no verified entry for 02165CA0

Members, in address order:

- `ov009_func_02165CAC.c`
- `ov009_func_02165E98.c`
- `ov009_func_02165EC8.c`
- `ov009_func_02165F34.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_02165B80.c` again.
