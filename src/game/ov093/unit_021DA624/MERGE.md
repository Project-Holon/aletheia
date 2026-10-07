# unit_021DA624.c (ov093)

Translation unit 021DA624..021DB0E4, 35 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021DA624.c` is blocked by:

- ov093_func_021DA624.c..ov093_func_021DB00C.c: c99=DIFF nolang=DIFF
- ov093_func_021DA624.c..ov093_func_021DAAEC.c: c99=DIFF nolang=DIFF
- ov093_func_021DA624.c..ov093_func_021DA844.c: c99=DIFF nolang=DIFF
- ov093_func_021DA7DC.c..ov093_func_021DA844.c: c99=DIFF nolang=DIFF
- func_021DA820.c..ov093_func_021DA844.c: c99=DIFF nolang=DIFF
- ov093_func_021DA868.c..ov093_func_021DAAEC.c: c99=DIFF nolang=DIFF
- ov093_func_021DA868.c..ov093_func_021DA96C.c: c99=DIFF nolang=DIFF
- ov093_func_021DA868.c..ov093_func_021DA8A8.c: c99=DIFF nolang=DIFF
- ov093_func_021DAB24.c..ov093_func_021DB00C.c: c99=DIFF nolang=DIFF
- ov093_func_021DAB24.c..ov093_func_021DAD58.c: c99=DIFF nolang=DIFF
- ov093_func_021DAB24.c..ov093_func_021DABF4.c: c99=DIFF nolang=DIFF
- ov093_func_021DAB78.c..ov093_func_021DABF4.c: c99=DIFF nolang=DIFF
- ov093_func_021DAC1C.c..ov093_func_021DAD58.c: c99=DIFF nolang=DIFF
- func_021DAC90.c..ov093_func_021DAD58.c: c99=DIFF nolang=DIFF
- ov093_func_021DAD84.c..ov093_func_021DB00C.c: c99=DIFF nolang=DIFF
- func_021DAEAC.c..ov093_func_021DB00C.c: c99=DIFF nolang=DIFF
- func_021DAEAC.c..ov093_func_021DAEE4.c: c99=DIFF nolang=DIFF
- ov093_func_021DAF1C.c..ov093_func_021DB00C.c: c99=DIFF nolang=DIFF
- ov093_func_021DAF58.c..ov093_func_021DB00C.c: c99=DIFF nolang=DIFF

Members, in address order:

- `func_021DA820.c`
- `ov093_func_021DA844.c`
- `ov093_func_021DA868.c`
- `ov093_func_021DA8A8.c`
- `ov093_func_021DAB78.c`
- `ov093_func_021DABF4.c`
- `func_021DAC90.c`
- `func_021DAEAC.c`
- `ov093_func_021DAEE4.c`
- `ov093_func_021DAF1C.c`
- `ov093_func_021DAF58.c`
- `ov093_func_021DB00C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021DA624.c` again.
