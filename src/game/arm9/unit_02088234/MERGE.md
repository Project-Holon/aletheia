# unit_02088234.c (arm9)

Translation unit 02088234..020882C0, 1 functions, confidence likely (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_02088234.c` is blocked by:

- the merged file does not compile or match: 

Members, in address order:

- `OS_Terminate.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_02088234.c` again.
