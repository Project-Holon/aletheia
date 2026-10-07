# unit_021E2FA8.c (ov183)

Translation unit 021E2FA8..021E3228, 6 functions, confidence likely (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021E2FA8.c` is blocked by:

- ov183_func_021E2FA8.c..ov183_func_021E31E8.c: prototype of func_021FD860 differs between members (src/matched/ov/ov183_func_021E2FE8.c)
- ov183_func_021E2FA8.c..ov183_func_021E300C.c: prototype of func_021FD860 differs between members (src/matched/ov/ov183_func_021E2FE8.c)

Members, in address order:

- `ov183_func_021E2FA8.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021E2FA8.c` again.
