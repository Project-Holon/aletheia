# unit_02166880.c (ov009)

Translation unit 02166880..02167E88, 21 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_02166880.c` is blocked by:

- ov009_func_02166880.c..ov009_func_02167E20.c: prototype of WCMi_GetSystemWork differs between members (src/matched/ov_sdk/ov009_func_02166E5C.c); prototype of WCMi_GetSystemWork differs between members (src/matched/ov_sdk/ov009_func_02166F24.c); 
- ov009_func_02166880.c..ov009_func_02166EB0.c: prototype of WCMi_GetSystemWork differs between members (src/matched/ov_sdk/ov009_func_02166E5C.c)
- ov009_func_02166C44.c..ov009_func_02166EB0.c: c99=CCERR: line 59: struct/union/enum/class tag 'WCMWork' redefined | line 200: 'flag' is not a member of class 'struct WCMWork' | line 202: 'flag' is not a member of class 'struct WCMWork' nolang=CCE
- ov009_func_02166F24.c..ov009_func_02167E20.c: prototype of WCMi_GetCpsifWork differs between members (src/matched/ov_sdk/ov009_func_02167E20.c)
- ov009_func_02166F24.c..ov009_func_021676E4.c: c99=CCERR: line 84: struct/union/enum/class tag 'WCMWork' redefined | line 102: identifier 'WCMWork' redeclared | line 102: was declared as: 'struct WCMWork' nolang=CCERR: line 84: struct/union/enum/c
- ov009_func_02166F24.c..ov009_func_021671C0.c: c99=CCERR: line 80: struct/union/enum/class tag 'WCMWork' redefined | line 98: identifier 'WCMWork' redeclared | line 98: was declared as: 'struct WCMWork' nolang=CCERR: line 80: struct/union/enum/cla
- ov009_func_02167448.c..ov009_func_021676E4.c: c99=CCERR: line 65: struct/union/enum/class tag 'WCMWork' redefined | line 70: identifier 'WCMWork' redeclared | line 70: was declared as: 'struct WCMWork' nolang=CCERR: line 65: struct/union/enum/cla
- ov009_func_021674BC.c..ov009_func_021676E4.c: c99=CCERR: line 65: struct/union/enum/class tag 'WCMWork' redefined | line 70: identifier 'WCMWork' redeclared | line 70: was declared as: 'struct WCMWork' nolang=CCERR: line 65: struct/union/enum/cla

Members, in address order:

- `ov009_func_02166F24.c`
- `ov009_func_021671C0.c`
- `ov009_func_02167448.c`
- `ov009_func_021674BC.c`
- `ov009_func_021676E4.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_02166880.c` again.
