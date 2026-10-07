# script_command.c (ov132)

Translation unit 021F9E40..021FD4F8, 135 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`script_command.c` is blocked by:

- ov132_func_021F9E40.c..ov132_func_021FD470.c: global table declared two ways (src/matched/ov/ov132_func_021FA6CC.c); global d_021FDD00 declared two ways (src/matched/ov/ov132_func_021FB2B0.c); prototype of func_0207CA00 differs between members (s
- ov132_func_021F9E40.c..ov132_func_021FB5A4.c: global table declared two ways (src/matched/ov/ov132_func_021FA6CC.c); global d_021FDD00 declared two ways (src/matched/ov/ov132_func_021FB2B0.c); prototype of func_0207CA00 differs between members (s
- ov132_func_021F9E40.c..ov132_func_021FAAB8.c: global table declared two ways (src/matched/ov/ov132_func_021FA6CC.c)
- ov132_func_021FA0D4.c..ov132_func_021FAAB8.c: global table declared two ways (src/matched/ov/ov132_func_021FA6CC.c)
- ov132_func_021FB5EC.c..ov132_func_021FD470.c: prototype of func_02082D44 differs between members (src/matched/ov/ov132_func_021FD400.c); prototype of func_02082D44 differs between members (src/matched/ov/ov132_func_021FD470.c)
- ov132_func_021FB5EC.c..ov132_func_021FC53C.c: c99=DIFF nolang=DIFF
- ov132_func_021FB5EC.c..ov132_func_021FBE38.c: c99=DIFF nolang=DIFF
- ov132_func_021FB808.c..ov132_func_021FBE38.c: c99=DIFF nolang=DIFF
- ov132_func_021FC560.c..ov132_func_021FD470.c: prototype of func_02082D44 differs between members (src/matched/ov/ov132_func_021FD400.c); prototype of func_02082D44 differs between members (src/matched/ov/ov132_func_021FD470.c)
- ov132_func_021FCAA8.c..ov132_func_021FD470.c: prototype of func_02082D44 differs between members (src/matched/ov/ov132_func_021FD400.c); prototype of func_02082D44 differs between members (src/matched/ov/ov132_func_021FD470.c)
- ov132_func_021FD14C.c..ov132_func_021FD470.c: prototype of func_02082D44 differs between members (src/matched/ov/ov132_func_021FD400.c); prototype of func_02082D44 differs between members (src/matched/ov/ov132_func_021FD470.c)
- ov132_func_021FD14C.c..ov132_func_021FD328.c: c99=DIFF nolang=DIFF
- ov132_func_021FD14C.c..ov132_func_021FD22C.c: c99=DIFF nolang=DIFF

Members, in address order:

- `ov132_func_021FD14C.c`
- `ov132_func_021FD22C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names script_command.c` again.
