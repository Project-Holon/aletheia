# wf2dmap_map.c (ov127)

Translation unit 021C4790..021C4CB4, 31 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`wf2dmap_map.c` is blocked by:

- ov127_func_021C4790.c..ov127_func_021C4C88.c: c99=CCERR: line 187: illegal implicit conversion from 'char *' to | line 187: 'unsigned char *' | line 305: illegal implicit conversion from 'struct pair_021C4AC4' to nolang=CCERR: line 187: illegal i
- ov127_func_021C4954.c..ov127_func_021C4C88.c: c99=CCERR: line 197: illegal implicit conversion from 'struct pair_021C4AC4' to | line 197: 'struct pair_021C4ADC' | line 198: illegal implicit conversion from 'struct pair_021C4AD0' to nolang=CCERR: 
- ov127_func_021C4A98.c..ov127_func_021C4C88.c: c99=CCERR: line 83: illegal implicit conversion from 'struct pair_021C4AC4' to | line 83: 'struct pair_021C4ADC' | line 84: illegal implicit conversion from 'struct pair_021C4AD0' to nolang=CCERR: lin
- ov127_func_021C4A98.c..ov127_func_021C4ADC.c: c99=CCERR: line 52: illegal implicit conversion from 'struct pair_021C4AC4' to | line 52: 'struct pair_021C4ADC' | line 53: illegal implicit conversion from 'struct pair_021C4AD0' to nolang=CCERR: lin
- ov127_func_021C4AD0.c..ov127_func_021C4ADC.c: c99=CCERR: line 41: illegal implicit conversion from 'struct pair_021C4AD0' to | line 41: 'struct pair_021C4ADC' nolang=CCERR: line 41: illegal implicit conversion from 'struct pair_021C4AD0' to | lin

Members, in address order:

- `ov127_func_021C4AD0.c`
- `ov127_func_021C4ADC.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names wf2dmap_map.c` again.
