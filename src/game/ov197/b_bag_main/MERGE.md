# b_bag_main.c (ov197)

Translation unit 0220B31C..0220D9DC, 88 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`b_bag_main.c` is blocked by:

- ov197_func_0220B31C.c..ov197_func_0220D9A8.c: prototype of func_02045EC0 differs between members (src/matched/ov/ov197_func_0220B3EC.c); prototype of func_0201EFA4 differs between members (src/matched/ov/ov197_func_0220B3EC.c); prototype of func_
- ov197_func_0220B31C.c..ov197_func_0220C6D0.c: prototype of func_02045EC0 differs between members (src/matched/ov/ov197_func_0220B3EC.c); prototype of func_0201EFA4 differs between members (src/matched/ov/ov197_func_0220B3EC.c); prototype of func_
- ov197_func_0220BD14.c..ov197_func_0220C6D0.c: prototype of func_02020E60 differs between members (src/matched/ov/ov197_func_0220C180.c); prototype of func_02020E60 differs between members (src/matched/ov/ov197_func_0220C220.c)
- ov197_func_0220C3B4.c..ov197_func_0220C6D0.c: prototype of func_0220C180 differs between members (src/matched/ov/ov197_func_0220C574.c); prototype of func_0220C180 differs between members (src/matched/ov/ov197_func_0220C618.c)
- ov197_func_0220C538.c..ov197_func_0220C6D0.c: prototype of func_0220C180 differs between members (src/matched/ov/ov197_func_0220C574.c); prototype of func_0220C180 differs between members (src/matched/ov/ov197_func_0220C618.c)
- ov197_func_0220C538.c..ov197_func_0220C618.c: prototype of func_0220C180 differs between members (src/matched/ov/ov197_func_0220C574.c); prototype of func_0220C180 differs between members (src/matched/ov/ov197_func_0220C618.c)

Members, in address order:

- `ov197_func_0220C538.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names b_bag_main.c` again.
