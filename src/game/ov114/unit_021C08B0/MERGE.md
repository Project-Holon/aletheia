# unit_021C08B0.c (ov114)

Translation unit 021C08B0..021C109C, 10 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021C08B0.c` is blocked by:

- ov114_func_021C08B0.c..ov114_func_021C1020.c: type typedef GHIGlobals differs between members (src/matched/ov_sdk/ov114_func_021C0B4C.c); type typedef GHIGlobals differs between members (src/matched/ov_sdk/ov114_func_021C0C14.c); type typedef GHI
- ov114_func_021C08B0.c..ov114_func_021C0D40.c: type typedef GHIGlobals differs between members (src/matched/ov_sdk/ov114_func_021C0B4C.c); type typedef GHIGlobals differs between members (src/matched/ov_sdk/ov114_func_021C0C14.c); type typedef GHI
- ov114_func_021C0B4C.c..ov114_func_021C0D40.c: type typedef GHIGlobals differs between members (src/matched/ov_sdk/ov114_func_021C0C14.c); type typedef GHIGlobals differs between members (src/matched/ov_sdk/ov114_func_021C0D40.c)
- ov114_func_021C0C14.c..ov114_func_021C0D40.c: c99=CCERR: line 70: struct/union/enum/class tag 'GHIConnection' redefined | line 73: identifier 'GHIConnection' redeclared | line 73: was declared as: 'struct GHIConnection' nolang=CCERR: line 70: str
- ov114_func_021C0DA4.c..ov114_func_021C1020.c: type typedef GHIGlobals differs between members (src/matched/ov_sdk/ov114_func_021C0DF8.c); type typedef GHIGlobals differs between members (src/matched/ov_sdk/ov114_func_021C0FB0.c)

Members, in address order:

- `ov114_func_021C0B4C.c`
- `ov114_func_021C0C14.c`
- `ov114_func_021C0D40.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021C08B0.c` again.
