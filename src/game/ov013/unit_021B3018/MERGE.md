# unit_021B3018.c (ov013)

Translation unit 021B3018..021B3924, 14 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021B3018.c` is blocked by:

- ov013_func_021B3018.c..ov013_func_021B38B0.c: global d_021B3C50 declared two ways (src/matched/ov/ov013_func_021B3064.c); global d_021B3C50 declared two ways (src/matched/ov/ov013_func_021B3250.c); global d_021B4C48 declared two ways (src/matched
- ov013_func_021B3018.c..ov013_func_021B33E0.c: global d_021B3C50 declared two ways (src/matched/ov/ov013_func_021B3064.c); global d_021B3C50 declared two ways (src/matched/ov/ov013_func_021B3250.c); global d_021B4C48 declared two ways (src/matched
- ov013_func_021B3018.c..ov013_func_021B3250.c: global d_021B3C50 declared two ways (src/matched/ov/ov013_func_021B3064.c); global d_021B3C50 declared two ways (src/matched/ov/ov013_func_021B3250.c)
- ov013_func_021B3064.c..ov013_func_021B3250.c: global d_021B3C50 declared two ways (src/matched/ov/ov013_func_021B3250.c)
- ov013_func_021B33F8.c..ov013_func_021B38B0.c: global d_021B60CC declared two ways (src/matched/ov/ov013_func_021B38B0.c)
- ov013_func_021B370C.c..ov013_func_021B38B0.c: global d_021B60CC declared two ways (src/matched/ov/ov013_func_021B38B0.c)
- ov013_func_021B386C.c..ov013_func_021B38B0.c: global d_021B60CC declared two ways (src/matched/ov/ov013_func_021B38B0.c)
- no verified entry for 021B3084

Members, in address order:

- `ov013_func_021B3018.c`
- `ov013_func_021B3064.c`
- `ov013_func_021B3250.c`
- `ov013_func_021B386C.c`
- `ov013_func_021B38B0.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021B3018.c` again.
