# unit_0217D3AC.c (ov009)

Translation unit 0217D3AC..0217EA7C, 18 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_0217D3AC.c` is blocked by:

- ov009_func_0217D3AC.c..ov009_func_0217E9EC.c: prototype of memcpy differs between members (src/matched/ov_sdk/ov009_func_0217E978.c)
- ov009_func_0217D3AC.c..ov009_func_0217D904.c: c99=CCERR: line 41: struct/union/enum/class tag 'gsLargeInt_s' redefined | line 46: struct/union/enum/class tag 'gsLargeInt_s' redefined | line 55: identifier 'memcpy(void *, const void *, unsigned lo
- ov009_func_0217D508.c..ov009_func_0217D904.c: c99=CCERR: line 39: struct/union/enum/class tag 'gsLargeInt_s' redefined | line 44: struct/union/enum/class tag 'gsLargeInt_s' redefined | line 52: identifier 'memcpy(void *, const void *, unsigned lo
- ov009_func_0217D750.c..ov009_func_0217D904.c: c99=CCERR: line 34: struct/union/enum/class tag 'gsLargeInt_s' redefined | line 39: struct/union/enum/class tag 'gsLargeInt_s' redefined | line 46: identifier 'memcpy(void *, const void *, unsigned lo
- ov009_func_0217D8E0.c..ov009_func_0217D904.c: c99=CCERR: line 34: struct/union/enum/class tag 'gsLargeInt_s' redefined | line 49: illegal implicit conversion from 'struct gsLargeInt_s *' to | line 49: 'struct  *' nolang=CCERR: line 34: struct/uni
- ov009_func_0217DCA4.c..ov009_func_0217E9EC.c: prototype of func_0217D640 differs between members (src/matched/ov_sdk/ov009_func_0217E504.c); prototype of memcpy differs between members (src/matched/ov_sdk/ov009_func_0217E978.c)
- ov009_func_0217DCA4.c..ov009_func_0217E504.c: prototype of func_0217D640 differs between members (src/matched/ov_sdk/ov009_func_0217E504.c)
- ov009_func_0217E078.c..ov009_func_0217E504.c: c99=CCERR: line 67: identifier 'memset(void *, int, unsigned long)' redeclared as 'void * (void *, int, unsigned int)' | line 68: identifier 'memcpy(void *, const void *, unsigned long)' redeclared as

Members, in address order:

- `ov009_func_0217D750.c`
- `ov009_func_0217D8E0.c`
- `ov009_func_0217D904.c`
- `ov009_func_0217E078.c`
- `ov009_func_0217E504.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_0217D3AC.c` again.
