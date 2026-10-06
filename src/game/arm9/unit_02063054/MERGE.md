# unit_02063054.c (arm9)

Translation unit 02063054..02063078, 1 functions, confidence likely (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_02063054.c` is blocked by:

- the merged file does not compile or match: 

Members, in address order:

- `sub_02063054.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_02063054.c` again.

- `sub_02063068.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.
