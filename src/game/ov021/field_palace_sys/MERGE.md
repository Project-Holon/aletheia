# field_palace_sys.c (ov021)

Translation unit 021D1164..021D3554, 94 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`field_palace_sys.c` is blocked by:

- ov021_func_021D1164.c..ov021_func_021D3478.c: prototype of func_02049238 differs between members (src/matched/ov/ov021_func_021D1F78.c); prototype of func_0201F7A8 differs between members (src/matched/ov/func_021D25E8.c); prototype of func_020492
- ov021_func_021D1164.c..ov021_func_021D2358.c: prototype of func_02049238 differs between members (src/matched/ov/ov021_func_021D1F78.c)
- ov021_func_021D1164.c..ov021_func_021D1A04.c: c99=CCERR: line 787: illegal implicit conversion from 'unsigned int[3]' to | line 787: 'struct V3 *' nolang=CCERR: line 787: illegal implicit conversion from 'unsigned int[3]' to | line 787: 'struct V
- ov021_func_021D1488.c..ov021_func_021D1A04.c: c99=CCERR: line 517: illegal implicit conversion from 'unsigned int[3]' to | line 517: 'struct V3 *' nolang=CCERR: line 517: illegal implicit conversion from 'unsigned int[3]' to | line 517: 'struct V
- func_021D1884.c..ov021_func_021D1A04.c: c99=DIFF nolang=DIFF
- ov021_func_021D18F4.c..ov021_func_021D1A04.c: c99=DIFF nolang=DIFF
- ov021_func_021D1A54.c..ov021_func_021D2358.c: c99=CCERR: line 645: illegal implicit conversion from 'struct  *' to | line 645: 'unsigned int' nolang=CCERR: line 645: illegal implicit conversion from 'struct  *' to | line 645: 'unsigned int'
- ov021_func_021D2418.c..ov021_func_021D3478.c: prototype of func_020124E8 differs between members (src/matched/ov/ov021_func_021D2D50.c); prototype of func_02049238 differs between members (src/matched/ov/ov021_func_021D3478.c)
- ov021_func_021D2418.c..ov021_func_021D2F44.c: prototype of func_020124E8 differs between members (src/matched/ov/ov021_func_021D2D50.c)
- ov021_func_021D297C.c..ov021_func_021D2F44.c: prototype of func_020124E8 differs between members (src/matched/ov/ov021_func_021D2D50.c)
- ov021_func_021D2CE8.c..ov021_func_021D2F44.c: prototype of func_020124E8 differs between members (src/matched/ov/ov021_func_021D2D7C.c)
- ov021_func_021D2F6C.c..ov021_func_021D3478.c: c99=DIFF nolang=DIFF
- ov021_func_021D2F6C.c..ov021_func_021D325C.c: c99=DIFF nolang=DIFF
- ov021_func_021D3164.c..ov021_func_021D325C.c: c99=DIFF nolang=DIFF
- ov021_func_021D31AC.c..ov021_func_021D325C.c: c99=DIFF nolang=DIFF
- ov021_func_021D3244.c..ov021_func_021D325C.c: c99=DIFF nolang=DIFF
- ov021_func_021D3270.c..ov021_func_021D3478.c: c99=DIFF nolang=DIFF
- ov021_func_021D3270.c..ov021_func_021D331C.c: c99=DIFF nolang=DIFF

Members, in address order:

- `ov021_func_021D18F4.c`
- `ov021_func_021D31AC.c`
- `ov021_func_021D3244.c`
- `ov021_func_021D325C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names field_palace_sys.c` again.
