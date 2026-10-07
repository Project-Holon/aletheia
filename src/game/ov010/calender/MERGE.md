# calender.c (ov010)

Translation unit 021644F4..02164B38, 33 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`calender.c` is blocked by:

- ov010_func_021644F4.c..ov010_func_02164A2C.c: prototype of func_02188CB4 differs between members (src/matched/ov/ov010_func_021645E0.c); global d_02171534 declared two ways (src/matched/ov/ov010_func_02164728.c); global d_02171534 declared two wa
- ov010_func_021644F4.c..ov010_func_02164778.c: prototype of func_02188CB4 differs between members (src/matched/ov/ov010_func_021645E0.c); global d_02171534 declared two ways (src/matched/ov/ov010_func_02164728.c); global d_02171534 declared two wa
- ov010_func_021644F4.c..ov010_func_02164654.c: prototype of func_02188CB4 differs between members (src/matched/ov/ov010_func_021645E0.c)
- ov010_func_02164678.c..ov010_func_02164778.c: global d_02171534 declared two ways (src/matched/ov/ov010_func_02164728.c); global d_02171534 declared two ways (src/matched/ov/ov010_func_0216476C.c)
- ov010_func_02164708.c..ov010_func_02164778.c: global d_02171534 declared two ways (src/matched/ov/ov010_func_02164728.c); global d_02171534 declared two ways (src/matched/ov/ov010_func_0216476C.c)
- ov010_func_02164708.c..ov010_func_02164728.c: global d_02171534 declared two ways (src/matched/ov/ov010_func_02164728.c)

Members, in address order:

- `ov010_func_02164708.c`
- `ov010_func_02164728.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names calender.c` again.
