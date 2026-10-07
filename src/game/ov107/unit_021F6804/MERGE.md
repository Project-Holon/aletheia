# unit_021F6804.c (ov107)

Translation unit 021F6804..021F6AA4, 6 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021F6804.c` is blocked by:

- ov107_func_021F6804.c..ov107_func_021F6A24.c: c99=CCERR: line 139: illegal implicit conversion from 'struct hdr *' to | line 139: 'struct  *' nolang=CCERR: line 139: illegal implicit conversion from 'struct hdr *' to | line 139: 'struct  *'
- ov107_func_021F6890.c..ov107_func_021F6A24.c: c99=CCERR: line 99: illegal implicit conversion from 'struct hdr *' to | line 99: 'struct  *' nolang=CCERR: line 99: illegal implicit conversion from 'struct hdr *' to | line 99: 'struct  *'
- ov107_func_021F6908.c..ov107_func_021F6A24.c: c99=CCERR: line 65: illegal implicit conversion from 'struct hdr *' to | line 65: 'struct  *' nolang=CCERR: line 65: illegal implicit conversion from 'struct hdr *' to | line 65: 'struct  *'

Members, in address order:

- `ov107_func_021F6890.c`
- `ov107_func_021F6908.c`
- `ov107_func_021F6A24.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021F6804.c` again.
