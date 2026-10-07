# unit_0218E3B0.c (ov009)

Translation unit 0218E3B0..0218F880, 21 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_0218E3B0.c` is blocked by:

- ov009_func_0218E3B0.c..ov009_func_0218F7B8.c: prototype of func_02094B20 differs between members (src/matched/ov_sdk/ov009_func_0218E6DC.c); prototype of func_02189A7C differs between members (src/matched/ov_sdk/ov009_func_0218E6DC.c); prototype 
- ov009_func_0218E3B0.c..ov009_func_0218F0B8.c: prototype of func_02094B20 differs between members (src/matched/ov_sdk/ov009_func_0218E6DC.c); prototype of func_02189A7C differs between members (src/matched/ov_sdk/ov009_func_0218E91C.c); prototype 
- ov009_func_0218E3B0.c..ov009_func_0218ED58.c: prototype of func_02094B20 differs between members (src/matched/ov_sdk/ov009_func_0218E6DC.c); prototype of func_02189A7C differs between members (src/matched/ov_sdk/ov009_func_0218E91C.c); prototype 
- ov009_func_0218E3B0.c..ov009_func_0218E6DC.c: prototype of func_02094B20 differs between members (src/matched/ov_sdk/ov009_func_0218E6DC.c)
- ov009_func_0218E91C.c..ov009_func_0218ED58.c: prototype of func_02189A7C differs between members (src/matched/ov_sdk/ov009_func_0218E9E8.c); prototype of func_02189DFC differs between members (src/matched/ov_sdk/ov009_func_0218ED58.c)
- ov009_func_0218E9E8.c..ov009_func_0218ED58.c: prototype of func_02189DFC differs between members (src/matched/ov_sdk/ov009_func_0218ED58.c)
- ov009_func_0218F0E8.c..ov009_func_0218F7B8.c: prototype of func_0218F0E8 differs between members (src/matched/ov_sdk/ov009_func_0218F7B8.c); prototype of func_0215FA9C differs between members (src/matched/ov_sdk/ov009_func_0218F7B8.c)
- ov009_func_0218F350.c..ov009_func_0218F7B8.c: prototype of func_0218F0E8 differs between members (src/matched/ov_sdk/ov009_func_0218F7B8.c); prototype of func_0215FA9C differs between members (src/matched/ov_sdk/ov009_func_0218F7B8.c)
- ov009_func_0218F5F4.c..ov009_func_0218F7B8.c: prototype of func_0218F0E8 differs between members (src/matched/ov_sdk/ov009_func_0218F7B8.c); prototype of func_0215FA9C differs between members (src/matched/ov_sdk/ov009_func_0218F7B8.c)
- ov009_func_0218F65C.c..ov009_func_0218F7B8.c: prototype of func_0218F0E8 differs between members (src/matched/ov_sdk/ov009_func_0218F7B8.c)

Members, in address order:

- `ov009_func_0218E3B0.c`
- `ov009_func_0218E6DC.c`
- `ov009_func_0218E91C.c`
- `ov009_func_0218E9E8.c`
- `ov009_func_0218ED58.c`
- `ov009_func_0218F5F4.c`
- `ov009_func_0218F65C.c`
- `ov009_func_0218F7B8.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_0218E3B0.c` again.
