# unit_0218DD88.c (ov009)

Translation unit 0218DD88..0218E3B0, 7 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_0218DD88.c` is blocked by:

- ov009_func_0218DD88.c..ov009_func_0218E318.c: c99=CCERR: line 97: struct/union/enum/class tag 'GPICallback' redefined | line 102: struct/union/enum/class tag 'GPIOperation_s' redefined | line 363: 'handler' is not a member of class 'struct GPICal
- ov009_func_0218DD88.c..ov009_func_0218E1CC.c: c99=CCERR: line 88: struct/union/enum/class tag 'GPICallback' redefined | line 93: struct/union/enum/class tag 'GPIOperation_s' redefined | line 307: 'handler' is not a member of class 'struct GPICall
- ov009_func_0218E240.c..ov009_func_0218E318.c: type struct GPIConnection differs between members (src/matched/ov_sdk/ov009_func_0218E290.c)

Members, in address order:

- `ov009_func_0218DD88.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_0218DD88.c` again.
