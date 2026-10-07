# unit_02186664.c (ov009)

Translation unit 02186664..02187010, 6 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_02186664.c` is blocked by:

- ov009_func_02186664.c..ov009_func_02186E9C.c: prototype of gpiFindOperationByID differs between members (src/matched/ov_sdk/ov009_func_02186E9C.c)
- ov009_func_021867E8.c..ov009_func_02186E9C.c: prototype of gpiFindOperationByID differs between members (src/matched/ov_sdk/ov009_func_02186E9C.c)
- ov009_func_02186A0C.c..ov009_func_02186E9C.c: prototype of gpiFindOperationByID differs between members (src/matched/ov_sdk/ov009_func_02186E9C.c)

Members, in address order:

- `ov009_func_021867E8.c`
- `ov009_func_02186A0C.c`
- `ov009_func_02186E9C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_02186664.c` again.
