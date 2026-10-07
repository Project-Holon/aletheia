# zukan_toroku_graphic.c (ov207)

Translation unit 0220AF40..0220B55C, 21 functions, confidence likely (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`zukan_toroku_graphic.c` is blocked by:

- ov207_func_0220AF40.c..ov207_func_0220B550.c: prototype of func_020056A0 differs between members (src/matched/ov/ov207_func_0220B318.c); prototype of func_02082BCC differs between members (src/matched/ov/ov207_func_0220B4A8.c); global d_0220BB18 
- ov207_func_0220AF40.c..ov207_func_0220B420.c: prototype of func_020056A0 differs between members (src/matched/ov/ov207_func_0220B318.c)
- ov207_func_0220B424.c..ov207_func_0220B550.c: prototype of func_02082BCC differs between members (src/matched/ov/ov207_func_0220B4A8.c); global d_0220BB18 declared two ways (src/matched/ov/ov207_func_0220B4A8.c); prototype of func_02082BCC differ
- ov207_func_0220B424.c..ov207_func_0220B4A8.c: prototype of func_02082BCC differs between members (src/matched/ov/ov207_func_0220B4A8.c); global d_0220BB18 declared two ways (src/matched/ov/ov207_func_0220B4A8.c)
- ov207_func_0220B434.c..ov207_func_0220B4A8.c: prototype of func_02082BCC differs between members (src/matched/ov/ov207_func_0220B4A8.c); global d_0220BB18 declared two ways (src/matched/ov/ov207_func_0220B4A8.c)
- ov207_func_0220B448.c..ov207_func_0220B4A8.c: prototype of func_02082BCC differs between members (src/matched/ov/ov207_func_0220B4A8.c); global d_0220BB18 declared two ways (src/matched/ov/ov207_func_0220B4A8.c)

Members, in address order:

- `ov207_func_0220B434.c`
- `ov207_func_0220B448.c`
- `ov207_func_0220B4A8.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names zukan_toroku_graphic.c` again.
