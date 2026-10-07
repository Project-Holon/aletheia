# unit_02198850.c (ov009)

Translation unit 02198850..02198E74, 5 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_02198850.c` is blocked by:

- ov009_func_02198850.c..ov009_func_02198A0C.c: prototype of func_0217D254 differs between members (src/matched/ov_sdk/ov009_func_02198A0C.c)
- ov009_func_02198958.c..ov009_func_02198A0C.c: prototype of func_0217D254 differs between members (src/matched/ov_sdk/ov009_func_02198A0C.c)
- ov009_func_0219898C.c..ov009_func_02198A0C.c: prototype of func_0217D254 differs between members (src/matched/ov_sdk/ov009_func_02198A0C.c)

Members, in address order:

- `ov009_func_02198958.c`
- `ov009_func_0219898C.c`
- `ov009_func_02198A0C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_02198850.c` again.
