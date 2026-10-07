# unit_021C7A74.c (ov114)

Translation unit 021C7A74..021C7BA0, 2 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021C7A74.c` is blocked by:

- ov114_func_021C7A74.c..ov114_func_021C7B48.c: settings differ: src/matched/ov_sdk/ov114_func_021C7B48.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.2', 'flags': '-O4,p', 'lang': 'c99', 'i

Members, in address order:

- `ov114_func_021C7A74.c`
- `ov114_func_021C7B48.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021C7A74.c` again.
