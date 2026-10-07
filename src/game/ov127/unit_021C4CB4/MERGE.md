# unit_021C4CB4.c (ov127)

Translation unit 021C4CB4..021C5550, 27 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021C4CB4.c` is blocked by:

- ov127_func_021C4CB4.c..ov127_func_021C54EC.c: prototype of func_021C4B7C differs between members (src/matched/ov/ov127_func_021C4D34.c); prototype of func_021C4B90 differs between members (src/matched/ov/ov127_func_021C4D34.c); prototype of func_
- ov127_func_021C4CB4.c..ov127_func_021C51C8.c: prototype of func_021C4B90 differs between members (src/matched/ov/ov127_func_021C51C8.c); prototype of func_021C4B7C differs between members (src/matched/ov/ov127_func_021C51C8.c)
- ov127_func_021C4F10.c..ov127_func_021C51C8.c: prototype of func_021C4B90 differs between members (src/matched/ov/ov127_func_021C51C8.c); prototype of func_021C4B7C differs between members (src/matched/ov/ov127_func_021C51C8.c)
- ov127_func_021C509C.c..ov127_func_021C51C8.c: prototype of func_021C4B90 differs between members (src/matched/ov/ov127_func_021C51C8.c); prototype of func_021C4B7C differs between members (src/matched/ov/ov127_func_021C51C8.c)
- ov127_func_021C5164.c..ov127_func_021C51C8.c: prototype of func_021C4B90 differs between members (src/matched/ov/ov127_func_021C51C8.c); prototype of func_021C4B7C differs between members (src/matched/ov/ov127_func_021C51C8.c)
- ov127_func_021C5238.c..ov127_func_021C54EC.c: prototype of func_021C4AC4 differs between members (src/matched/ov/ov127_func_021C5278.c); prototype of func_021C4B90 differs between members (src/matched/ov/ov127_func_021C5278.c); prototype of func_
- ov127_func_021C5238.c..ov127_func_021C539C.c: prototype of func_021C4AC4 differs between members (src/matched/ov/ov127_func_021C5334.c)

Members, in address order:

- `ov127_func_021C5164.c`
- `ov127_func_021C51C8.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021C4CB4.c` again.
