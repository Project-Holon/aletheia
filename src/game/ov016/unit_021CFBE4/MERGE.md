# unit_021CFBE4.c (ov016)

Translation unit 021CFBE4..021CFEBC, 5 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021CFBE4.c` is blocked by:

- ov016_func_021CFBE4.c..func_021CFEA0.c: type typedef SETTINGINFO differs between members (src/matched/ov_sdk/ov016_func_021CFC20.c); type typedef SETTINGINFO differs between members (src/matched/ov_sdk/ov016_func_021CFCC8.c); type typedef S
- ov016_func_021CFCC8.c..func_021CFEA0.c: type typedef SETTINGINFO differs between members (src/matched/ov_sdk/ov016_func_021CFE18.c)

Members, in address order:

- `ov016_func_021CFCC8.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021CFBE4.c` again.
