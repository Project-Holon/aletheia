# unit_021C771C.c (ov016)

Translation unit 021C771C..021C7768, 2 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021C771C.c` is blocked by:

- ov016_func_021C771C.c..ov016_func_021C7738.c: prototype of DWCi_ChangeScene differs between members (src/matched/ov_sdk/ov016_func_021C7738.c)

Members, in address order:

- `ov016_func_021C771C.c`
- `ov016_func_021C7738.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021C771C.c` again.
