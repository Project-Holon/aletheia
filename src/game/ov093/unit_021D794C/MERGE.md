# unit_021D794C.c (ov093)

Translation unit 021D794C..021D7E44, 26 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021D794C.c` is blocked by:

- ov093_func_021D794C.c..ov093_func_021D7E10.c: c99=CCERR: line 319: illegal implicit conversion from 'union Slot_021D7D18' to | line 319: 'struct ' nolang=CCERR: line 319: illegal implicit conversion from 'union Slot_021D7D18' to | line 319: 'stru
- ov093_func_021D7B60.c..ov093_func_021D7E10.c: c99=CCERR: line 204: illegal implicit conversion from 'union Slot_021D7D18' to | line 204: 'struct ' nolang=CCERR: line 204: illegal implicit conversion from 'union Slot_021D7D18' to | line 204: 'stru
- ov093_func_021D7C70.c..ov093_func_021D7E10.c: c99=CCERR: line 139: illegal implicit conversion from 'union Slot_021D7D18' to | line 139: 'struct ' nolang=CCERR: line 139: illegal implicit conversion from 'union Slot_021D7D18' to | line 139: 'stru
- no verified entry for 021D7E34

Members, in address order:


To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021D794C.c` again.
