# intrude_comm.c (ov011)

Translation unit 02172BC0..02173658, 12 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`intrude_comm.c` is blocked by:

- ov011_func_02172BC0.c..ov011_func_021735FC.c: prototype of func_02012B64 differs between members (src/matched/ov/ov011_func_02172D70.c)
- ov011_func_02172BC0.c..ov011_func_02173368.c: prototype of func_02012B64 differs between members (src/matched/ov/ov011_func_02172D70.c)
- ov011_func_02172BC0.c..ov011_func_02172D70.c: prototype of func_02012B64 differs between members (src/matched/ov/ov011_func_02172D70.c)
- ov011_func_02173464.c..ov011_func_021735FC.c: c99=DIFF nolang=DIFF
- ov011_func_02173580.c..ov011_func_021735FC.c: c99=DIFF nolang=DIFF

Members, in address order:

- `ov011_func_02172BC0.c`
- `ov011_func_02173580.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names intrude_comm.c` again.
