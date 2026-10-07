# btl_rec_sel_graphic.c (ov214)

Translation unit 021BB178..021BB46C, 18 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`btl_rec_sel_graphic.c` is blocked by:

- ov214_func_021BB178.c..ov214_func_021BB458.c: global config declared two ways (src/matched/ov/ov214_func_021BB2C8.c); global records declared two ways (src/matched/ov/ov214_func_021BB328.c); prototype of func_02082BCC differs between members (src
- ov214_func_021BB178.c..ov214_func_021BB328.c: global config declared two ways (src/matched/ov/ov214_func_021BB2C8.c); global records declared two ways (src/matched/ov/ov214_func_021BB328.c)
- ov214_func_021BB29C.c..ov214_func_021BB328.c: global records declared two ways (src/matched/ov/ov214_func_021BB328.c)
- ov214_func_021BB2B4.c..ov214_func_021BB328.c: global records declared two ways (src/matched/ov/ov214_func_021BB328.c)
- ov214_func_021BB2C8.c..ov214_func_021BB328.c: global records declared two ways (src/matched/ov/ov214_func_021BB328.c)

Members, in address order:

- `ov214_func_021BB2B4.c`
- `ov214_func_021BB2C8.c`
- `ov214_func_021BB328.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names btl_rec_sel_graphic.c` again.
