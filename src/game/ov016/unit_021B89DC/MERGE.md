# unit_021B89DC.c (ov016)

Translation unit 021B89DC..021B9038, 9 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021B89DC.c` is blocked by:

- ov016_func_021B89DC.c..ov016_func_021B8F80.c: prototype of WCM_SearchAsync differs between members (src/matched/ov_sdk/ov016_func_021B8C94.c); prototype of WCM_SearchAsync differs between members (src/matched/ov_sdk/ov016_func_021B8D40.c); protot
- ov016_func_021B89DC.c..ov016_func_021B8D40.c: prototype of WCM_SearchAsync differs between members (src/matched/ov_sdk/ov016_func_021B8C94.c); prototype of WCM_SearchAsync differs between members (src/matched/ov_sdk/ov016_func_021B8D40.c)
- ov016_func_021B89DC.c..ov016_func_021B8C94.c: prototype of WCM_SearchAsync differs between members (src/matched/ov_sdk/ov016_func_021B8C94.c)

Members, in address order:

- `ov016_func_021B89DC.c`
- `ov016_func_021B8C94.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021B89DC.c` again.
