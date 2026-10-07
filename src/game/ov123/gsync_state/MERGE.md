# gsync_state.c (ov123)

Translation unit 021D4240..021DA5D0, 250 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`gsync_state.c` is blocked by:

- ov123_func_021D4240.c..ov123_func_021DA54C.c: prototype of func_02082D44 differs between members (src/matched/ov/ov123_func_021D4D40.c); prototype of func_0201C7A4 differs between members (src/matched/ov/ov123_func_021D4EF0.c); prototype of func_
- ov123_func_021D4240.c..ov123_func_021D7204.c: prototype of func_02082D44 differs between members (src/matched/ov/ov123_func_021D4D40.c); prototype of func_0201C7A4 differs between members (src/matched/ov/ov123_func_021D4EF0.c); prototype of func_
- ov123_func_021D4240.c..ov123_func_021D5BA8.c: prototype of func_02082D44 differs between members (src/matched/ov/ov123_func_021D4D40.c); prototype of func_0201C7A4 differs between members (src/matched/ov/ov123_func_021D4EF0.c); prototype of func_
- ov123_func_021D4240.c..ov123_func_021D4EF0.c: prototype of func_02082D44 differs between members (src/matched/ov/ov123_func_021D4D40.c); prototype of func_0201C7A4 differs between members (src/matched/ov/ov123_func_021D4EF0.c)
- ov123_func_021D4FAC.c..ov123_func_021D5BA8.c: prototype of func_02045CAC differs between members (src/matched/ov/ov123_func_021D5950.c)
- ov123_func_021D57B8.c..ov123_func_021D5BA8.c: prototype of func_02045CAC differs between members (src/matched/ov/ov123_func_021D5950.c)
- ov123_func_021D57B8.c..ov123_func_021D59E4.c: prototype of func_02045CAC differs between members (src/matched/ov/ov123_func_021D5950.c)
- ov123_func_021D5890.c..ov123_func_021D59E4.c: prototype of func_02045CAC differs between members (src/matched/ov/ov123_func_021D5950.c)
- ov123_func_021D5890.c..ov123_func_021D5950.c: prototype of func_02045CAC differs between members (src/matched/ov/ov123_func_021D5950.c)
- ov123_func_021D5BD4.c..ov123_func_021D7204.c: prototype of func_0207E3D0 differs between members (src/matched/ov/ov123_func_021D6548.c); prototype of func_0204B5AC differs between members (src/matched/ov/ov123_func_021D67B4.c); prototype of func_
- ov123_func_021D5BD4.c..ov123_func_021D6548.c: prototype of func_0207E3D0 differs between members (src/matched/ov/ov123_func_021D6548.c)
- ov123_func_021D60F8.c..ov123_func_021D6548.c: prototype of func_0207E3D0 differs between members (src/matched/ov/ov123_func_021D6548.c)
- ov123_func_021D65F4.c..ov123_func_021D7204.c: prototype of func_0204B5AC differs between members (src/matched/ov/ov123_func_021D67B4.c); prototype of func_0204B5AC differs between members (src/matched/ov/ov123_func_021D6830.c); prototype of func_
- ov123_func_021D65F4.c..ov123_func_021D6CD8.c: prototype of func_0204B5AC differs between members (src/matched/ov/ov123_func_021D67B4.c); prototype of func_0204B5AC differs between members (src/matched/ov/ov123_func_021D6830.c); prototype of func_
- ov123_func_021D7224.c..ov123_func_021DA54C.c: prototype of func_02082D44 differs between members (src/matched/ov/ov123_func_021D75D0.c); prototype of func_02082D44 differs between members (src/matched/ov/ov123_func_021D76F0.c); prototype of func_
- ov123_func_021D7224.c..ov123_func_021D8A7C.c: prototype of func_02082D44 differs between members (src/matched/ov/ov123_func_021D75D0.c); prototype of func_02082D44 differs between members (src/matched/ov/ov123_func_021D76F0.c); prototype of func_
- ov123_func_021D7224.c..ov123_func_021D7E58.c: prototype of func_02082D44 differs between members (src/matched/ov/ov123_func_021D75D0.c); prototype of func_02082D44 differs between members (src/matched/ov/ov123_func_021D76F0.c); prototype of func_
- ov123_func_021D7858.c..ov123_func_021D7E58.c: prototype of func_021D5D8C differs between members (src/matched/ov/ov123_func_021D79A4.c)
- ov123_func_021D7858.c..ov123_func_021D7B68.c: prototype of func_021D5D8C differs between members (src/matched/ov/ov123_func_021D79A4.c)

Members, in address order:

- `ov123_func_021D5890.c`
- `ov123_func_021D5950.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names gsync_state.c` again.
