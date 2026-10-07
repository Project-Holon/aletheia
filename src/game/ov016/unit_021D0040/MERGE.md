# unit_021D0040.c (ov016)

Translation unit 021D0040..021D0B44, 18 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021D0040.c` is blocked by:

- ov016_func_021D0040.c..ov016_func_021D0AFC.c: type typedef MEMSTEP differs between members (src/matched/ov_sdk/ov016_func_021D013C.c); prototype of DWCi_CEINlSetExCell differs between members (src/matched/ov_sdk/ov016_func_021D013C.c); type typed
- ov016_func_021D0040.c..ov016_func_021D05BC.c: type typedef MEMSTEP differs between members (src/matched/ov_sdk/ov016_func_021D013C.c); prototype of DWCi_CEINlSetExCell differs between members (src/matched/ov_sdk/ov016_func_021D013C.c); type typed
- ov016_func_021D0040.c..ov016_func_021D02FC.c: c99=CCERR: line 72: ')' expected | line 73: ')' expected | line 74: declaration syntax error nolang=CCERR: line 56: undefined identifier '_Bool' | line 67: undefined identifier 'bool' | line 72: ')' e
- ov016_func_021D0040.c..ov016_func_021D013C.c: c99=CCERR: line 74: ')' expected | line 75: ')' expected | line 76: declaration syntax error nolang=CCERR: line 58: undefined identifier '_Bool' | line 69: undefined identifier 'bool' | line 74: ')' e
- ov016_func_021D021C.c..ov016_func_021D02FC.c: c99=CCERR: line 74: ')' expected | line 75: ')' expected | line 76: declaration syntax error nolang=CCERR: line 58: undefined identifier '_Bool' | line 69: undefined identifier 'bool' | line 74: ')' e
- ov016_func_021D03DC.c..ov016_func_021D05BC.c: type typedef MEMSTEP differs between members (src/matched/ov_sdk/ov016_func_021D04BC.c); prototype of DWCi_CEINlSetExCell differs between members (src/matched/ov_sdk/ov016_func_021D04BC.c); type typed
- ov016_func_021D03DC.c..ov016_func_021D04BC.c: type typedef MEMSTEP differs between members (src/matched/ov_sdk/ov016_func_021D04BC.c); prototype of DWCi_CEINlSetExCell differs between members (src/matched/ov_sdk/ov016_func_021D04BC.c)
- ov016_func_021D0558.c..ov016_func_021D05BC.c: c99=CCERR: line 73: ')' expected | line 74: ')' expected | line 75: declaration syntax error nolang=CCERR: line 57: undefined identifier '_Bool' | line 68: undefined identifier 'bool' | line 73: ')' e
- ov016_func_021D0580.c..ov016_func_021D05BC.c: c99=CCERR: line 74: ')' expected | line 75: ')' expected | line 76: declaration syntax error nolang=CCERR: line 58: undefined identifier '_Bool' | line 69: undefined identifier 'bool' | line 74: ')' e
- func_021D0684.c..ov016_func_021D0AFC.c: type typedef MEMSTEP differs between members (src/matched/ov_sdk/ov016_func_021D0734.c); prototype of DWCi_CEINlSetExCell differs between members (src/matched/ov_sdk/ov016_func_021D0734.c); type typed
- func_021D0684.c..ov016_func_021D0808.c: type typedef MEMSTEP differs between members (src/matched/ov_sdk/ov016_func_021D0734.c); prototype of DWCi_CEINlSetExCell differs between members (src/matched/ov_sdk/ov016_func_021D0734.c); type typed
- ov016_func_021D0734.c..ov016_func_021D0808.c: c99=CCERR: line 74: ')' expected | line 75: ')' expected | line 76: declaration syntax error nolang=CCERR: line 58: undefined identifier '_Bool' | line 69: undefined identifier 'bool' | line 74: ')' e
- ov016_func_021D08DC.c..ov016_func_021D0AFC.c: global step_bss declared two ways (src/matched/ov_sdk/ov016_func_021D0AB0.c); global step_bss declared two ways (src/matched/ov_sdk/ov016_func_021D0AFC.c)
- ov016_func_021D08DC.c..ov016_func_021D09B0.c: c99=CCERR: line 74: ')' expected | line 75: ')' expected | line 76: declaration syntax error nolang=CCERR: line 58: undefined identifier '_Bool' | line 69: undefined identifier 'bool' | line 74: ')' e
- ov016_func_021D0A84.c..ov016_func_021D0AFC.c: global step_bss declared two ways (src/matched/ov_sdk/ov016_func_021D0AB0.c); global step_bss declared two ways (src/matched/ov_sdk/ov016_func_021D0AFC.c)
- ov016_func_021D0AB0.c..ov016_func_021D0AFC.c: c99=CCERR: line 76: ')' expected | line 77: ')' expected | line 78: declaration syntax error nolang=CCERR: line 60: undefined identifier '_Bool' | line 71: undefined identifier 'bool' | line 76: ')' e

Members, in address order:

- `ov016_func_021D0040.c`
- `ov016_func_021D013C.c`
- `ov016_func_021D021C.c`
- `ov016_func_021D02FC.c`
- `ov016_func_021D03DC.c`
- `ov016_func_021D04BC.c`
- `ov016_func_021D0558.c`
- `ov016_func_021D0580.c`
- `ov016_func_021D05BC.c`
- `ov016_func_021D0734.c`
- `ov016_func_021D0808.c`
- `ov016_func_021D08DC.c`
- `ov016_func_021D09B0.c`
- `ov016_func_021D0A84.c`
- `ov016_func_021D0AB0.c`
- `ov016_func_021D0AFC.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021D0040.c` again.
