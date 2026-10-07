# unit_02179824.c (ov015)

Translation unit 02179824..02179C98, 17 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_02179824.c` is blocked by:

- ov015_func_02179824.c..ov015_func_02179B38.c: global d_0217AAC0 declared two ways (src/matched/ov/ov015_func_0217993C.c); global d_0217AAC0 declared two ways (src/matched/ov/ov015_func_021799B4.c); global d_0217AB40 declared two ways (src/matched
- ov015_func_02179824.c..ov015_func_0217998C.c: global d_0217AAC0 declared two ways (src/matched/ov/ov015_func_0217993C.c)
- ov015_func_02179824.c..ov015_func_021798A0.c: c99=DIFF nolang=DIFF
- ov015_func_0217984C.c..ov015_func_021798A0.c: c99=DIFF nolang=DIFF
- ov015_func_021798D4.c..ov015_func_0217998C.c: global d_0217AAC0 declared two ways (src/matched/ov/ov015_func_0217993C.c)
- ov015_func_02179998.c..ov015_func_02179B38.c: global d_0217AB40 declared two ways (src/matched/ov/ov015_func_02179A4C.c); global d_0217AAC0 declared two ways (src/matched/ov/ov015_func_02179AAC.c); global d_0217AB40 declared two ways (src/matched
- ov015_func_021799F0.c..ov015_func_02179B38.c: global d_0217AAC0 declared two ways (src/matched/ov/ov015_func_02179B38.c)
- ov015_func_021799F0.c..ov015_func_02179A4C.c: c99=DIFF nolang=DIFF
- ov015_func_02179AAC.c..ov015_func_02179B38.c: global d_0217AAC0 declared two ways (src/matched/ov/ov015_func_02179B38.c)

Members, in address order:

- `ov015_func_0217984C.c`
- `ov015_func_021798A0.c`
- `ov015_func_021799F0.c`
- `ov015_func_02179A4C.c`
- `ov015_func_02179AAC.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_02179824.c` again.
