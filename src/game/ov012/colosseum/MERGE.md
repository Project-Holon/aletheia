# colosseum.c (ov012)

Translation unit 02174B58..02175358, 37 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`colosseum.c` is blocked by:

- ov012_func_02174B58.c..ov012_func_0217534C.c: c99=DIFF nolang=DIFF
- ov012_func_02174B58.c..ov012_func_02174E9C.c: c99=DIFF nolang=DIFF
- ov012_func_02174D10.c..ov012_func_02174E9C.c: c99=DIFF nolang=DIFF
- ov012_func_02174DC8.c..ov012_func_02174E9C.c: c99=DIFF nolang=DIFF
- ov012_func_02174E20.c..ov012_func_02174E9C.c: c99=DIFF nolang=DIFF
- ov012_func_02174ED8.c..ov012_func_0217534C.c: c99=DIFF nolang=DIFF
- ov012_func_02174ED8.c..ov012_func_021750D0.c: c99=DIFF nolang=DIFF
- ov012_func_02174ED8.c..ov012_func_0217505C.c: c99=DIFF nolang=DIFF
- ov012_func_02174ED8.c..ov012_func_02174F34.c: c99=DIFF nolang=DIFF

Members, in address order:

- `ov012_func_02174E20.c`
- `ov012_func_02174ED8.c`
- `ov012_func_02174F34.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names colosseum.c` again.
