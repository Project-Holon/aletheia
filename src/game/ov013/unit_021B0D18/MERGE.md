# unit_021B0D18.c (ov013)

Translation unit 021B0D18..021B1488, 8 functions, confidence likely (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021B0D18.c` is blocked by:

- ov013_func_021B0D18.c..ov013_func_021B1404.c: global d_021B3C84 declared two ways (src/matched/ov/ov013_func_021B0F38.c); prototype of func_021B2FE4 differs between members (src/matched/ov/ov013_func_021B111C.c); global d_021B3C84 declared two wa
- ov013_func_021B0D18.c..ov013_func_021B11E8.c: global d_021B3C84 declared two ways (src/matched/ov/ov013_func_021B0F38.c); prototype of func_021B2FE4 differs between members (src/matched/ov/ov013_func_021B111C.c); global d_021B3C84 declared two wa
- ov013_func_021B12FC.c..ov013_func_021B1404.c: prototype of func_021B2FE4 differs between members (src/matched/ov/ov013_func_021B1398.c); global g_021B4B98 declared two ways (src/matched/ov/ov013_func_021B1398.c); global g_021B4B98 declared two wa
- ov013_func_021B1398.c..ov013_func_021B1404.c: global g_021B4B98 declared two ways (src/matched/ov/ov013_func_021B1404.c)

Members, in address order:

- `ov013_func_021B1398.c`
- `ov013_func_021B1404.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021B0D18.c` again.
