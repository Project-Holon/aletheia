# field_ground_anime.c (ov021)

Translation unit 021A7360..021A7CE8, 36 functions, confidence likely (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`field_ground_anime.c` is blocked by:

- ov021_func_021A7360.c..ov021_func_021A7B88.c: prototype of func_020307B0 differs between members (src/matched/ov/ov021_func_021A7484.c); global d_021DDF7C declared two ways (src/matched/ov/ov021_func_021A7508.c); prototype of func_020307B0 differ
- ov021_func_021A7360.c..ov021_func_021A7654.c: prototype of func_020307B0 differs between members (src/matched/ov/ov021_func_021A7484.c); global d_021DDF7C declared two ways (src/matched/ov/ov021_func_021A7508.c); prototype of func_020307B0 differ
- ov021_func_021A7360.c..ov021_func_021A74C0.c: prototype of func_020307B0 differs between members (src/matched/ov/ov021_func_021A7484.c)
- ov021_func_021A7678.c..ov021_func_021A7B88.c: prototype of func_02047250 differs between members (src/matched/ov/ov021_func_021A797C.c); prototype of func_02047250 differs between members (src/matched/ov/ov021_func_021A79E4.c)
- ov021_func_021A7678.c..func_021A7A34.c: prototype of func_02047250 differs between members (src/matched/ov/ov021_func_021A797C.c); prototype of func_02047250 differs between members (src/matched/ov/ov021_func_021A79E4.c)
- ov021_func_021A78EC.c..func_021A7A34.c: prototype of func_02047250 differs between members (src/matched/ov/ov021_func_021A797C.c); prototype of func_02047250 differs between members (src/matched/ov/ov021_func_021A79E4.c)
- ov021_func_021A78EC.c..ov021_func_021A797C.c: prototype of func_02047250 differs between members (src/matched/ov/ov021_func_021A797C.c)
- ov021_func_021A7A40.c..ov021_func_021A7B88.c: c99=CCERR: line 256: illegal implicit conversion from 'struct Work_021A7B20 *' to | line 256: 'struct Work_021A7B88 *' nolang=CCERR: line 256: illegal implicit conversion from 'struct Work_021A7B20 *'
- ov021_func_021A7AB0.c..ov021_func_021A7B88.c: c99=CCERR: line 180: illegal implicit conversion from 'struct Work_021A7B20 *' to | line 180: 'struct Work_021A7B88 *' nolang=CCERR: line 180: illegal implicit conversion from 'struct Work_021A7B20 *'
- func_021A7B10.c..ov021_func_021A7B88.c: c99=CCERR: line 125: illegal implicit conversion from 'struct Work_021A7B20 *' to | line 125: 'struct Work_021A7B88 *' nolang=CCERR: line 125: illegal implicit conversion from 'struct Work_021A7B20 *'
- ov021_func_021A7B20.c..ov021_func_021A7B88.c: c99=CCERR: line 108: illegal implicit conversion from 'struct Work_021A7B20 *' to | line 108: 'struct Work_021A7B88 *' nolang=CCERR: line 108: illegal implicit conversion from 'struct Work_021A7B20 *'

Members, in address order:

- `ov021_func_021A78EC.c`
- `ov021_func_021A797C.c`
- `func_021A7B10.c`
- `ov021_func_021A7B20.c`
- `ov021_func_021A7B88.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names field_ground_anime.c` again.
