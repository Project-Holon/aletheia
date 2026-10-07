# unit_021B9038.c (ov016)

Translation unit 021B9038..021B93AC, 2 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021B9038.c` is blocked by:

- ov016_func_021B9038.c..ov016_func_021B9344.c: prototype of WCM_SearchAsync differs between members (src/matched/ov_sdk/ov016_func_021B9344.c)

Members, in address order:

- `ov016_func_021B9038.c`
- `ov016_func_021B9344.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021B9038.c` again.
