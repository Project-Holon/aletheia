# unit_02704364.c (twl)

Translation unit 02704364..02704D64, 13 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_02704364.c` is blocked by:

- func_02704364.c..func_02704D48.c: prototype of func_0208799C differs between members (src/matched/twl_sdk/func_02704B74.c); prototype of func_0208799C differs between members (src/matched/twl_sdk/func_02704BE0.c); prototype of func_02
- func_02704940.c..func_02704D48.c: c=DIFF
- func_02704940.c..func_02704B74.c: c=DIFF
- func_027049B0.c..func_02704B74.c: c=DIFF

Members, in address order:

- `func_02704940.c`
- `func_027049B0.c`
- `func_02704B74.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_02704364.c` again.

- `func_02704B58.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.
