# zukan.c (ov212)

Translation unit 021C8E80..021C9918, 27 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`zukan.c` is blocked by:

- ov212_func_021C8E80.c..ov212_func_021C98A8.c: prototype of alloc differs between members (src/matched/ov/ov212_func_021C976C.c)
- ov212_func_021C8E80.c..ov212_func_021C9244.c: c99=DIFF nolang=DIFF
- ov212_func_021C8E80.c..ov212_func_021C8FA8.c: c99=DIFF nolang=DIFF
- ov212_func_021C8F7C.c..ov212_func_021C8FA8.c: c99=DIFF nolang=DIFF
- ov212_func_021C8F90.c..ov212_func_021C8FA8.c: c99=DIFF nolang=DIFF

Members, in address order:

- `ov212_func_021C8F7C.c`
- `ov212_func_021C8F90.c`
- `ov212_func_021C8FA8.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names zukan.c` again.
