# unit_021D5EA8.c (ov093)

Translation unit 021D5EA8..021D66B0, 34 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021D5EA8.c` is blocked by:

- ov093_func_021D5EA8.c..ov093_func_021D65C8.c: prototype of func_021E8AFC differs between members (src/matched/ov/ov093_func_021D6130.c); prototype of func_021E8918 differs between members (src/matched/ov/ov093_func_021D6130.c); prototype of func_
- ov093_func_021D5EA8.c..ov093_func_021D61F0.c: prototype of func_021E8AFC differs between members (src/matched/ov/ov093_func_021D6130.c); prototype of func_021E8918 differs between members (src/matched/ov/ov093_func_021D6130.c); prototype of func_
- ov093_func_021D5FC0.c..ov093_func_021D61F0.c: prototype of func_021E8AFC differs between members (src/matched/ov/ov093_func_021D6130.c); prototype of func_021E8918 differs between members (src/matched/ov/ov093_func_021D6130.c); prototype of func_
- ov093_func_021D6064.c..ov093_func_021D61F0.c: prototype of func_021E8AFC differs between members (src/matched/ov/ov093_func_021D6130.c); prototype of func_021E8918 differs between members (src/matched/ov/ov093_func_021D6130.c); prototype of func_
- ov093_func_021D6064.c..ov093_func_021D6130.c: prototype of func_021E8AFC differs between members (src/matched/ov/ov093_func_021D6130.c); prototype of func_021E8918 differs between members (src/matched/ov/ov093_func_021D6130.c)
- ov093_func_021D61A8.c..ov093_func_021D61F0.c: prototype of func_021E8918 differs between members (src/matched/ov/ov093_func_021D61F0.c)
- ov093_func_021D621C.c..ov093_func_021D65C8.c: prototype of func_021E8918 differs between members (src/matched/ov/ov093_func_021D6238.c); prototype of func_021E8918 differs between members (src/matched/ov/ov093_func_021D6264.c); type struct Unk021
- ov093_func_021D621C.c..func_021D631C.c: c99=CCERR: line 45: struct/union/enum/class tag 'Slot' redefined | line 50: struct/union/enum/class tag 'Slot' redefined | line 116: 's' is not a member of class 'struct Slot' nolang=CCERR: line 45: s
- ov093_func_021D62C4.c..func_021D631C.c: c99=CCERR: line 31: struct/union/enum/class tag 'Slot' redefined | line 36: struct/union/enum/class tag 'Slot' redefined | line 51: 's' is not a member of class 'struct Slot' nolang=CCERR: line 31: st
- ov093_func_021D62C4.c..ov093_func_021D62D8.c: c99=CCERR: line 31: struct/union/enum/class tag 'Slot' redefined | line 36: struct/union/enum/class tag 'Slot' redefined | line 49: 's' is not a member of class 'struct Slot' nolang=CCERR: line 31: st
- no verified entry for 021D66A0

Members, in address order:

- `ov093_func_021D6064.c`
- `ov093_func_021D6130.c`
- `ov093_func_021D61A8.c`
- `ov093_func_021D61F0.c`
- `ov093_func_021D62C4.c`
- `ov093_func_021D62D8.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021D5EA8.c` again.
