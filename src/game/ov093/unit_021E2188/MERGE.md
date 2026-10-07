# unit_021E2188.c (ov093)

Translation unit 021E2188..021E281C, 17 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021E2188.c` is blocked by:

- ov093_func_021E2188.c..ov093_func_021E27B0.c: prototype of func_021E896C differs between members (src/matched/ov/ov093_func_021E237C.c); prototype of func_021E896C differs between members (src/matched/ov/ov093_func_021E25FC.c)
- ov093_func_021E2188.c..ov093_func_021E2574.c: prototype of func_021E896C differs between members (src/matched/ov/ov093_func_021E237C.c)
- ov093_func_021E2188.c..ov093_func_021E231C.c: c99=DIFF nolang=DIFF
- ov093_func_021E2188.c..ov093_func_021E21F4.c: c99=DIFF nolang=DIFF
- ov093_func_021E25DC.c..ov093_func_021E27B0.c: c99=DIFF nolang=DIFF
- ov093_func_021E25DC.c..ov093_func_021E269C.c: c99=DIFF nolang=DIFF
- ov093_func_021E25DC.c..ov093_func_021E25FC.c: c99=DIFF nolang=DIFF
- ov093_func_021E26C8.c..ov093_func_021E27B0.c: c99=DIFF nolang=DIFF
- ov093_func_021E2768.c..ov093_func_021E27B0.c: c99=DIFF nolang=DIFF
- func_021E278C.c..ov093_func_021E27B0.c: c99=DIFF nolang=DIFF

Members, in address order:

- `ov093_func_021E2188.c`
- `ov093_func_021E21F4.c`
- `ov093_func_021E25DC.c`
- `ov093_func_021E25FC.c`
- `ov093_func_021E2768.c`
- `func_021E278C.c`
- `ov093_func_021E27B0.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021E2188.c` again.
