# unit_0215E024.c (ov009)

Translation unit 0215E024..0215E6B8, 8 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_0215E024.c` is blocked by:

- ov009_func_0215E024.c..ov009_func_0215E620.c: type struct SOCLiCommandWrite differs between members (src/matched/ov_sdk/ov009_func_0215E138.c); type struct SOCLiCommandWrite differs between members (src/matched/ov_sdk/ov009_func_0215E450.c); prot
- ov009_func_0215E024.c..ov009_func_0215E2C0.c: type struct SOCLSocket differs between members (src/matched/ov_sdk/ov009_func_0215E138.c)
- ov009_func_0215E024.c..ov009_func_0215E138.c: type struct SOCLSocket differs between members (src/matched/ov_sdk/ov009_func_0215E138.c)
- ov009_func_0215E2E4.c..ov009_func_0215E620.c: type struct SOCLiSocketSendCommandPipe differs between members (src/matched/ov_sdk/ov009_func_0215E450.c); prototype of func_02082EA4 differs between members (src/matched/ov_sdk/ov009_func_0215E620.c)
- ov009_func_0215E2E4.c..ov009_func_0215E450.c: type struct SOCLiSocketSendCommandPipe differs between members (src/matched/ov_sdk/ov009_func_0215E450.c)

Members, in address order:

- `ov009_func_0215E024.c`
- `ov009_func_0215E138.c`
- `ov009_func_0215E2E4.c`
- `ov009_func_0215E450.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_0215E024.c` again.
