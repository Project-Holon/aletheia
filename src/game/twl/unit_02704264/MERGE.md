# unit_02704264.c (twl)

Translation unit 02704264..02704328, 1 functions, confidence likely (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_02704264.c` is blocked by:

- the merged file does not compile or match: 

Members, in address order:

- `func_02704264.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_02704264.c` again.

- `FATFSi_IsInitialized.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.
