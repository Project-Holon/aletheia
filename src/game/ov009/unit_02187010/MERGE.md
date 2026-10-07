# unit_02187010.c (ov009)

Translation unit 02187010..0218934C, 12 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_02187010.c` is blocked by:

- ov009_func_02187010.c..ov009_func_02189300.c: prototype of gpiProfileListAdd differs between members (src/matched/ov_sdk/ov009_func_02187D60.c); prototype of func_0218FD9C differs between members (src/matched/ov_sdk/ov009_func_02188BA0.c); protot
- ov009_func_02187010.c..ov009_func_021889A0.c: prototype of gpiProfileListAdd differs between members (src/matched/ov_sdk/ov009_func_02187D60.c)
- ov009_func_02187010.c..ov009_func_02187D60.c: prototype of gpiProfileListAdd differs between members (src/matched/ov_sdk/ov009_func_02187D60.c)
- ov009_func_021870B8.c..ov009_func_02187D60.c: prototype of gpiProfileListAdd differs between members (src/matched/ov_sdk/ov009_func_02187D60.c)
- ov009_func_02188B0C.c..ov009_func_02189300.c: prototype of func_0218FD9C differs between members (src/matched/ov_sdk/ov009_func_021890E0.c); prototype of func_0218FD9C differs between members (src/matched/ov_sdk/ov009_func_02189300.c)
- ov009_func_021890A4.c..ov009_func_02189300.c: prototype of func_0218FD9C differs between members (src/matched/ov_sdk/ov009_func_02189300.c)
- ov009_func_021890E0.c..ov009_func_02189300.c: prototype of func_0218FD9C differs between members (src/matched/ov_sdk/ov009_func_02189300.c)

Members, in address order:

- `ov009_func_02187010.c`
- `ov009_func_021870B8.c`
- `ov009_func_02187D60.c`
- `ov009_func_021890A4.c`
- `ov009_func_021890E0.c`
- `ov009_func_02189300.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_02187010.c` again.
