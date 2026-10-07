# unit_0216C858.c (ov009)

Translation unit 0216C858..0216F008, 23 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_0216C858.c` is blocked by:

- ov009_func_0216C858.c..ov009_func_0216EC84.c: prototype of DWCi_GetMatchCnt differs between members (src/matched/ov_sdk/ov009_func_0216C890.c); global g_021AAA40 declared two ways (src/matched/ov_sdk/ov009_func_0216CA04.c); prototype of func_0216
- ov009_func_0216C858.c..ov009_func_0216D27C.c: prototype of DWCi_GetMatchCnt differs between members (src/matched/ov_sdk/ov009_func_0216C890.c); global g_021AAA40 declared two ways (src/matched/ov_sdk/ov009_func_0216CA04.c); prototype of func_0216
- ov009_func_0216C858.c..ov009_func_0216CB30.c: prototype of DWCi_GetMatchCnt differs between members (src/matched/ov_sdk/ov009_func_0216C890.c); global g_021AAA40 declared two ways (src/matched/ov_sdk/ov009_func_0216CA04.c)
- ov009_func_0216C858.c..ov009_func_0216C890.c: prototype of DWCi_GetMatchCnt differs between members (src/matched/ov_sdk/ov009_func_0216C890.c)
- ov009_func_0216C8DC.c..ov009_func_0216CB30.c: global g_021AAA40 declared two ways (src/matched/ov_sdk/ov009_func_0216CA04.c)
- ov009_func_0216CB90.c..ov009_func_0216D27C.c: prototype of func_0216F5FC differs between members (src/matched/ov_sdk/ov009_func_0216D138.c); prototype of func_0219EC74 differs between members (src/matched/ov_sdk/ov009_func_0216D138.c); prototype 
- ov009_func_0216CF1C.c..ov009_func_0216D27C.c: prototype of func_0216F5FC differs between members (src/matched/ov_sdk/ov009_func_0216D138.c); prototype of func_0219EC74 differs between members (src/matched/ov_sdk/ov009_func_0216D138.c); prototype 
- ov009_func_0216D138.c..ov009_func_0216D27C.c: prototype of func_02175F3C differs between members (src/matched/ov_sdk/ov009_func_0216D27C.c); prototype of func_0216F5FC differs between members (src/matched/ov_sdk/ov009_func_0216D27C.c); prototype 
- ov009_func_0216D540.c..ov009_func_0216EC84.c: prototype of DWCi_GetMatchCnt differs between members (src/matched/ov_sdk/ov009_func_0216D57C.c); prototype of qr2_think differs between members (src/matched/ov_sdk/ov009_func_0216D57C.c); prototype o
- ov009_func_0216D540.c..ov009_func_0216E834.c: prototype of DWCi_GetMatchCnt differs between members (src/matched/ov_sdk/ov009_func_0216D57C.c); prototype of qr2_think differs between members (src/matched/ov_sdk/ov009_func_0216D57C.c); prototype o
- ov009_func_0216D540.c..ov009_func_0216E4C0.c: prototype of DWCi_GetMatchCnt differs between members (src/matched/ov_sdk/ov009_func_0216D57C.c); prototype of qr2_think differs between members (src/matched/ov_sdk/ov009_func_0216D57C.c)
- ov009_func_0216E5B0.c..ov009_func_0216E834.c: prototype of DWCi_GetMatchCnt differs between members (src/matched/ov_sdk/ov009_func_0216E808.c); prototype of DWCi_GetMatchCnt differs between members (src/matched/ov_sdk/ov009_func_0216E834.c)
- ov009_func_0216E808.c..ov009_func_0216E834.c: prototype of DWCi_GetMatchCnt differs between members (src/matched/ov_sdk/ov009_func_0216E834.c)
- ov009_func_0216EAB8.c..ov009_func_0216EC84.c: prototype of DWCi_GetMatchCnt differs between members (src/matched/ov_sdk/ov009_func_0216EC84.c)
- ov009_func_0216EAB8.c..ov009_func_0216EB68.c: c99=CCERR: line 26: the file '../arm9_sdk/libc/string.h' cannot be opened nolang=CCERR: line 26: the file '../arm9_sdk/libc/string.h' cannot be opened
- ov009_func_0216EC18.c..ov009_func_0216EC84.c: prototype of DWCi_GetMatchCnt differs between members (src/matched/ov_sdk/ov009_func_0216EC84.c)
- ov009_func_0216EC4C.c..ov009_func_0216EC84.c: c99=CCERR: line 32: the file '../arm9_sdk/libc/string.h' cannot be opened nolang=CCERR: line 32: the file '../arm9_sdk/libc/string.h' cannot be opened

Members, in address order:

- `ov009_func_0216C858.c`
- `ov009_func_0216C890.c`
- `ov009_func_0216C8DC.c`
- `ov009_func_0216CF1C.c`
- `ov009_func_0216D138.c`
- `ov009_func_0216D27C.c`
- `ov009_func_0216D540.c`
- `ov009_func_0216E5B0.c`
- `ov009_func_0216E808.c`
- `ov009_func_0216E834.c`
- `ov009_func_0216EAB8.c`
- `ov009_func_0216EC18.c`
- `ov009_func_0216EC4C.c`
- `ov009_func_0216EC84.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_0216C858.c` again.
