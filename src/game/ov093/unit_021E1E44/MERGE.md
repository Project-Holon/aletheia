# unit_021E1E44.c (ov093)

Translation unit 021E1E44..021E203C, 8 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021E1E44.c` is blocked by:

- ov093_func_021E1E44.c..ov093_func_021E2004.c: prototype of func_021D76BC differs between members (src/matched/ov/ov093_func_021E2004.c)
- ov093_func_021E1E44.c..ov093_func_021E1F44.c: c99=DIFF nolang=DIFF
- ov093_func_021E1E44.c..ov093_func_021E1EB8.c: c99=DIFF nolang=DIFF
- ov093_func_021E1F70.c..ov093_func_021E2004.c: prototype of func_021D76BC differs between members (src/matched/ov/ov093_func_021E2004.c)
- ov093_func_021E1F70.c..ov093_func_021E1F9C.c: c99=DIFF nolang=DIFF
- ov093_func_021E1FCC.c..ov093_func_021E2004.c: prototype of func_021D76BC differs between members (src/matched/ov/ov093_func_021E2004.c)

Members, in address order:

- `ov093_func_021E1E44.c`
- `ov093_func_021E1EB8.c`
- `ov093_func_021E1F70.c`
- `ov093_func_021E1F9C.c`
- `ov093_func_021E1FCC.c`
- `ov093_func_021E2004.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021E1E44.c` again.
