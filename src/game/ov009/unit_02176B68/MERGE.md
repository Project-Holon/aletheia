# unit_02176B68.c (ov009)

Translation unit 02176B68..02176C00, 3 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_02176B68.c` is blocked by:

- ov009_func_02176B68.c..ov009_func_02176BE4.c: global g_021AB178 declared two ways (src/matched/ov_sdk/ov009_func_02176B80.c)
- ov009_func_02176B80.c..ov009_func_02176BE4.c: global g_021AB178 declared two ways (src/matched/ov_sdk/ov009_func_02176BE4.c)

Members, in address order:

- `ov009_func_02176B68.c`
- `ov009_func_02176B80.c`
- `ov009_func_02176BE4.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_02176B68.c` again.
