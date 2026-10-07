# unit_021B23E0.c (ov013)

Translation unit 021B23E0..021B2F98, 21 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021B23E0.c` is blocked by:

- ov013_func_021B23E0.c..ov013_func_021B2ED8.c: global d_021B60D8 declared two ways (src/matched/ov/ov013_func_021B2488.c); global d_021B60D8 declared two ways (src/matched/ov/ov013_func_021B24FC.c); global d_021B4BD0 declared two ways (src/matched
- ov013_func_021B23E0.c..ov013_func_021B275C.c: global d_021B60D8 declared two ways (src/matched/ov/ov013_func_021B2488.c); global d_021B60D8 declared two ways (src/matched/ov/ov013_func_021B24FC.c); global d_021B4BD0 declared two ways (src/matched
- ov013_func_021B23E0.c..ov013_func_021B25B0.c: global d_021B60D8 declared two ways (src/matched/ov/ov013_func_021B2488.c); global d_021B60D8 declared two ways (src/matched/ov/ov013_func_021B24FC.c)
- ov013_func_021B23E0.c..ov013_func_021B2488.c: c99=CCERR: line 49: struct/union/enum/class tag 'Ctx' redefined | line 53: identifier 'Ctx' redeclared | line 53: was declared as: 'struct Ctx' nolang=CCERR: line 49: struct/union/enum/class tag 'Ctx'
- ov013_func_021B25FC.c..ov013_func_021B275C.c: global d_021B4BD0 declared two ways (src/matched/ov/ov013_func_021B2620.c); global d_021B60D8 declared two ways (src/matched/ov/ov013_func_021B2724.c)
- ov013_func_021B25FC.c..ov013_func_021B2620.c: global d_021B4BD0 declared two ways (src/matched/ov/ov013_func_021B2620.c)
- ov013_func_021B279C.c..ov013_func_021B2ED8.c: global d_021B60D8 declared two ways (src/matched/ov/ov013_func_021B2894.c); global d_021B60D8 declared two ways (src/matched/ov/ov013_func_021B29A4.c); global d_021B60D8 declared two ways (src/matched
- ov013_func_021B279C.c..ov013_func_021B29A4.c: global d_021B60D8 declared two ways (src/matched/ov/ov013_func_021B2894.c); global d_021B60D8 declared two ways (src/matched/ov/ov013_func_021B29A4.c)
- ov013_func_021B2894.c..ov013_func_021B29A4.c: global d_021B60D8 declared two ways (src/matched/ov/ov013_func_021B29A4.c)
- ov013_func_021B2A20.c..ov013_func_021B2ED8.c: global d_021B4C0C declared two ways (src/matched/ov/ov013_func_021B2BE0.c)
- ov013_func_021B2A20.c..ov013_func_021B2BE0.c: c99=CCERR: line 63: struct/union/enum/class tag 'Pool' redefined | line 159: 'freeList' is not a member of class 'struct Pool' | line 160: 'freeList' is not a member of class 'struct Pool' nolang=CCER
- ov013_func_021B2AA0.c..ov013_func_021B2BE0.c: c99=CCERR: line 49: struct/union/enum/class tag 'Pool' redefined | line 126: 'freeList' is not a member of class 'struct Pool' | line 127: 'freeList' is not a member of class 'struct Pool' nolang=CCER

Members, in address order:

- `ov013_func_021B23E0.c`
- `ov013_func_021B2488.c`
- `ov013_func_021B25FC.c`
- `ov013_func_021B2620.c`
- `ov013_func_021B2894.c`
- `ov013_func_021B2A20.c`
- `ov013_func_021B2AA0.c`
- `ov013_func_021B2BE0.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021B23E0.c` again.
