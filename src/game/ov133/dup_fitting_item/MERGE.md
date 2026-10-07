# dup_fitting_item.c (ov133)

Translation unit 021B6100..021BA324, 87 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`dup_fitting_item.c` is blocked by:

- ov133_func_021B6100.c..ov133_func_021BA25C.c: prototype of func_02040588 differs between members (src/matched/ov/ov133_func_021B6E4C.c); prototype of func_021F4EB4 differs between members (src/matched/ov/ov133_func_021B7368.c); prototype of func_
- ov133_func_021B6100.c..ov133_func_021B987C.c: prototype of func_02040588 differs between members (src/matched/ov/ov133_func_021B6E4C.c); prototype of func_021F4EB4 differs between members (src/matched/ov/ov133_func_021B7368.c); prototype of func_
- ov133_func_021B6100.c..ov133_func_021B8254.c: prototype of func_02040588 differs between members (src/matched/ov/ov133_func_021B6E4C.c); prototype of func_021F4EB4 differs between members (src/matched/ov/ov133_func_021B7368.c); prototype of func_
- ov133_func_021B6100.c..ov133_func_021B7368.c: prototype of func_02040588 differs between members (src/matched/ov/ov133_func_021B6E4C.c); prototype of func_021F4EB4 differs between members (src/matched/ov/ov133_func_021B7368.c)
- ov133_func_021B7458.c..ov133_func_021B8254.c: prototype of func_021F4E8C differs between members (src/matched/ov/ov133_func_021B7F54.c); prototype of func_021F4EB4 differs between members (src/matched/ov/ov133_func_021B7F54.c); prototype of func_
- ov133_func_021B7A70.c..ov133_func_021B8254.c: prototype of func_021B765C differs between members (src/matched/ov/ov133_func_021B7CFC.c); prototype of func_021F4EC4 differs between members (src/matched/ov/ov133_func_021B8140.c); prototype of func_
- ov133_func_021B7F54.c..ov133_func_021B8254.c: prototype of func_021F4EC4 differs between members (src/matched/ov/ov133_func_021B8140.c); prototype of func_021F4EB4 differs between members (src/matched/ov/ov133_func_021B8140.c); prototype of func_
- ov133_func_021B82E8.c..ov133_func_021B987C.c: prototype of func_021F4E8C differs between members (src/matched/ov/ov133_func_021B8444.c); prototype of func_021F4EB4 differs between members (src/matched/ov/ov133_func_021B8444.c); prototype of func_
- ov133_func_021B82E8.c..ov133_func_021B8FF4.c: prototype of func_021F4E8C differs between members (src/matched/ov/ov133_func_021B8444.c); prototype of func_021F4E8C differs between members (src/matched/ov/ov133_func_021B8680.c); prototype of func_
- ov133_func_021B82E8.c..ov133_func_021B8A30.c: prototype of func_021F4E8C differs between members (src/matched/ov/ov133_func_021B8444.c); prototype of func_021F4E8C differs between members (src/matched/ov/ov133_func_021B8680.c)
- ov133_func_021B82E8.c..ov133_func_021B8444.c: prototype of func_021F4E8C differs between members (src/matched/ov/ov133_func_021B8444.c)
- ov133_func_021B9028.c..ov133_func_021B987C.c: prototype of func_021F5450 differs between members (src/matched/ov/ov133_func_021B96D8.c)
- ov133_func_021B952C.c..ov133_func_021B987C.c: prototype of func_021F5450 differs between members (src/matched/ov/ov133_func_021B96D8.c)
- ov133_func_021B952C.c..ov133_func_021B96D8.c: prototype of func_021F5450 differs between members (src/matched/ov/ov133_func_021B96D8.c)
- ov133_func_021B95AC.c..ov133_func_021B96D8.c: prototype of func_021F5450 differs between members (src/matched/ov/ov133_func_021B96D8.c)

Members, in address order:

- `ov133_func_021B7F54.c`
- `ov133_func_021B82E8.c`
- `ov133_func_021B8444.c`
- `ov133_func_021B952C.c`
- `ov133_func_021B95AC.c`
- `ov133_func_021B96D8.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names dup_fitting_item.c` again.
