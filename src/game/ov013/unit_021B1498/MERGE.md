# unit_021B1498.c (ov013)

Translation unit 021B1498..021B23C8, 29 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021B1498.c` is blocked by:

- ov013_func_021B1498.c..ov013_func_021B22B4.c: global d_021B4B98 declared two ways (src/matched/ov/ov013_func_021B14F8.c); global d_021B4BA0 declared two ways (src/matched/ov/ov013_func_021B14F8.c); global d_021B4BB8 declared two ways (src/matched
- ov013_func_021B1498.c..ov013_func_021B19AC.c: global d_021B4B98 declared two ways (src/matched/ov/ov013_func_021B14F8.c); global d_021B4BA0 declared two ways (src/matched/ov/ov013_func_021B14F8.c); global d_021B4BB8 declared two ways (src/matched
- ov013_func_021B16E4.c..ov013_func_021B19AC.c: global d_021B4BB8 declared two ways (src/matched/ov/ov013_func_021B1720.c); prototype of func_021B2FE4 differs between members (src/matched/ov/ov013_func_021B1790.c); global d_021B4BAC declared two wa
- ov013_func_021B16E4.c..ov013_func_021B1790.c: global d_021B4BB8 declared two ways (src/matched/ov/ov013_func_021B1720.c); global d_021B4BB8 declared two ways (src/matched/ov/ov013_func_021B1790.c)
- ov013_func_021B1810.c..ov013_func_021B19AC.c: global d_021B4BAC declared two ways (src/matched/ov/ov013_func_021B190C.c); prototype of func_02087988 differs between members (src/matched/ov/ov013_func_021B190C.c); prototype of func_0208799C differ
- ov013_func_021B19BC.c..ov013_func_021B22B4.c: prototype of func_021B2848 differs between members (src/matched/ov/ov013_func_021B20D4.c); global d_021B60D8 declared two ways (src/matched/ov/ov013_func_021B2254.c); global g_021B4BE0 declared two wa
- ov013_func_021B1F54.c..ov013_func_021B22B4.c: prototype of func_021B2848 differs between members (src/matched/ov/ov013_func_021B20D4.c); global d_021B60D8 declared two ways (src/matched/ov/ov013_func_021B2254.c); global g_021B4BE0 declared two wa
- ov013_func_021B2180.c..ov013_func_021B22B4.c: global d_021B60D8 declared two ways (src/matched/ov/ov013_func_021B2254.c)
- ov013_func_021B2180.c..ov013_func_021B21A4.c: c99=CCERR: line 26: struct/union/enum/class tag 'Sess' redefined | line 67: 'id' is not a member of class 'struct Sess' | line 78: 'cb' is not a member of class 'struct Sess' nolang=CCERR: line 26: st

Members, in address order:

- `ov013_func_021B16E4.c`
- `ov013_func_021B2180.c`
- `ov013_func_021B21A4.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021B1498.c` again.
