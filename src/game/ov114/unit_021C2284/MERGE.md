# unit_021C2284.c (ov114)

Translation unit 021C2284..021C2344, 8 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021C2284.c` is blocked by:

- ov114_func_021C2284.c..ov114_func_021C2324.c: prototype of ghiRequestToConnection differs between members (src/matched/ov_sdk/ov114_func_021C22A4.c); prototype of func_021C0DA4 differs between members (src/matched/ov_sdk/ov114_func_021C22EC.c)
- ov114_func_021C2284.c..ov114_func_021C22D4.c: prototype of ghiRequestToConnection differs between members (src/matched/ov_sdk/ov114_func_021C22A4.c)
- ov114_func_021C22EC.c..ov114_func_021C2324.c: c99=DIFF nolang=DIFF
- no verified entry for 021C2304, 021C2338

Members, in address order:

- `ov114_func_021C2284.c`
- `ov114_func_021C22EC.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021C2284.c` again.
