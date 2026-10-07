# unit_021D81F8.c (ov093)

Translation unit 021D81F8..021D832C, 7 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021D81F8.c` is blocked by:

- ov093_func_021D81F8.c..ov093_func_021D82FC.c: c99=CCERR: line 29: struct/union/enum/class tag 'B' redefined | line 60: 'val' is not a member of class 'struct B' | line 60: 'val' is not a member of class 'struct B' nolang=CCERR: line 29: struct/un
- ov093_func_021D81F8.c..ov093_func_021D8244.c: c99=CCERR: line 28: struct/union/enum/class tag 'B' redefined | line 40: 'val' is not a member of class 'struct B' | line 40: 'val' is not a member of class 'struct B' nolang=CCERR: line 28: struct/un

Members, in address order:

- `ov093_func_021D81F8.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021D81F8.c` again.
