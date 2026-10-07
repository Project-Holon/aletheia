# btlv_scd.c (ov095)

Translation unit 06899AF0..06899BE0, 6 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`btlv_scd.c` is blocked by:

- ov095_func_06899AF0.c..ov095_func_06899BC8.c: settings differ: src/matched/ov/ov095_func_06899BA0.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa
- ov095_func_06899BA0.c..ov095_func_06899BC8.c: c99=DIFF nolang=DIFF
- no verified entry for 06899BA8, 06899BB8, 06899BD0

Members, in address order:

- `ov095_func_06899AF0.c`
- `ov095_func_06899BA0.c`
- `ov095_func_06899BC8.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names btlv_scd.c` again.
