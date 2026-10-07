# subway_map_graphic.c (ov224)

Translation unit 021B95A0..021B9BE8, 19 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`subway_map_graphic.c` is blocked by:

- ov224_func_021B95A0.c..ov224_func_021B9B7C.c: global d_021B9C04 declared two ways (src/matched/ov/ov224_func_021B9718.c); prototype of func_020056A0 differs between members (src/matched/ov/ov224_func_021B9940.c); global table declared two ways (s
- ov224_func_021B95A0.c..ov224_func_021B9A44.c: global d_021B9C04 declared two ways (src/matched/ov/ov224_func_021B9718.c); prototype of func_020056A0 differs between members (src/matched/ov/ov224_func_021B9940.c)
- ov224_func_021B95A0.c..ov224_func_021B9824.c: global d_021B9C04 declared two ways (src/matched/ov/ov224_func_021B9718.c)
- ov224_func_021B95A0.c..ov224_func_021B9718.c: global d_021B9C04 declared two ways (src/matched/ov/ov224_func_021B9718.c)

Members, in address order:

- `ov224_func_021B95A0.c`
- `ov224_func_021B9718.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names subway_map_graphic.c` again.
