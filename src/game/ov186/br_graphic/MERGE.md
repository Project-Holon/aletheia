# br_graphic.c (ov186)

Translation unit 021FC3BC..021FC6A4, 15 functions, confidence likely (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`br_graphic.c` is blocked by:

- ov186_func_021FC3BC.c..ov186_func_021FC640.c: global d_0220099C declared two ways (src/matched/ov/ov186_func_021FC55C.c); prototype of func_02082BCC differs between members (src/matched/ov/ov186_func_021FC55C.c); prototype of func_02082BCC differ
- ov186_func_021FC594.c..ov186_func_021FC640.c: prototype of func_02082BCC differs between members (src/matched/ov/ov186_func_021FC5E0.c); global d_0220099C declared two ways (src/matched/ov/ov186_func_021FC640.c)
- ov186_func_021FC594.c..ov186_func_021FC5E0.c: prototype of func_02082BCC differs between members (src/matched/ov/ov186_func_021FC5E0.c)
- ov186_func_021FC5A0.c..ov186_func_021FC5E0.c: prototype of func_02082BCC differs between members (src/matched/ov/ov186_func_021FC5E0.c)
- ov186_func_021FC5FC.c..ov186_func_021FC640.c: global d_0220099C declared two ways (src/matched/ov/ov186_func_021FC640.c)
- ov186_func_021FC610.c..ov186_func_021FC640.c: global d_0220099C declared two ways (src/matched/ov/ov186_func_021FC640.c)

Members, in address order:

- `ov186_func_021FC5A0.c`
- `ov186_func_021FC5E0.c`
- `ov186_func_021FC610.c`
- `ov186_func_021FC640.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names br_graphic.c` again.
