# shinka_demo.c (ov195)

Translation unit 02203FA0..022058F8, 45 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`shinka_demo.c` is blocked by:

- ov195_func_02203FA0.c..ov195_func_02205854.c: prototype of func_0204E720 differs between members (src/matched/ov/ov195_func_022040E0.c); global d_02208F40 declared two ways (src/matched/ov/ov195_func_022040E0.c); prototype of func_02205A34 differ
- ov195_func_02203FA0.c..ov195_func_02204FF8.c: prototype of func_0204E720 differs between members (src/matched/ov/ov195_func_022040E0.c); global d_02208F40 declared two ways (src/matched/ov/ov195_func_022040E0.c); prototype of func_02205A34 differ
- ov195_func_02203FA0.c..ov195_func_02204ED0.c: prototype of func_0204E720 differs between members (src/matched/ov/ov195_func_022040E0.c); global d_02208F40 declared two ways (src/matched/ov/ov195_func_022040E0.c); prototype of func_02205A34 differ
- ov195_func_02203FA0.c..ov195_func_02204D5C.c: prototype of func_0204E720 differs between members (src/matched/ov/ov195_func_022040E0.c); global d_02208F40 declared two ways (src/matched/ov/ov195_func_022040E0.c); prototype of func_02205A34 differ
- ov195_func_022040E0.c..ov195_func_02204D5C.c: prototype of func_02205A34 differs between members (src/matched/ov/ov195_func_02204C24.c)
- ov195_func_02205010.c..ov195_func_02205854.c: prototype of func_02043B5C differs between members (src/matched/ov/ov195_func_0220549C.c)
- ov195_func_02205384.c..ov195_func_02205854.c: prototype of func_02043B5C differs between members (src/matched/ov/ov195_func_022054E8.c)
- ov195_func_02205384.c..ov195_func_02205530.c: prototype of func_02043B5C differs between members (src/matched/ov/ov195_func_022054E8.c)
- ov195_func_0220549C.c..ov195_func_02205530.c: prototype of func_02043B5C differs between members (src/matched/ov/ov195_func_022054E8.c)

Members, in address order:

- `ov195_func_022040E0.c`
- `ov195_func_0220549C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names shinka_demo.c` again.
