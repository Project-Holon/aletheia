# pmsiv_menu.c (ov110)

Translation unit 021BBE8C..021BEB78, 118 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`pmsiv_menu.c` is blocked by:

- ov110_func_021BBE8C.c..ov110_func_021BEB60.c: prototype of func_021BAC78 differs between members (src/matched/ov/ov110_func_021BC1B8.c); type typedef Pair differs between members (src/matched/ov/ov110_func_021BC23C.c); prototype of func_0204B3DC 
- ov110_func_021BBE8C.c..ov110_func_021BCF38.c: prototype of func_021BAC78 differs between members (src/matched/ov/ov110_func_021BC1B8.c); type typedef Pair differs between members (src/matched/ov/ov110_func_021BC23C.c); prototype of func_0204B3DC 
- ov110_func_021BBE8C.c..ov110_func_021BC72C.c: prototype of func_021BAC78 differs between members (src/matched/ov/ov110_func_021BC1B8.c); type typedef Pair differs between members (src/matched/ov/ov110_func_021BC23C.c); prototype of func_0204B3DC 
- ov110_func_021BBE8C.c..ov110_func_021BC490.c: prototype of func_021BAC78 differs between members (src/matched/ov/ov110_func_021BC1B8.c); type typedef Pair differs between members (src/matched/ov/ov110_func_021BC23C.c); prototype of func_0204B3DC 
- ov110_func_021BC1B8.c..ov110_func_021BC490.c: prototype of func_021BF6F0 differs between members (src/matched/ov/ov110_func_021BC340.c); prototype of func_021BC5BC differs between members (src/matched/ov/ov110_func_021BC340.c); prototype of func_
- ov110_func_021BC564.c..ov110_func_021BC72C.c: prototype of func_0204B404 differs between members (src/matched/ov/ov110_func_021BC72C.c)
- ov110_func_021BC78C.c..ov110_func_021BCF38.c: c99=CCERR: line 379: illegal implicit conversion from 'unsigned char *' to | line 379: 'struct  *' | line 419: illegal implicit conversion from 'struct Object_021BCB50 *' to nolang=CCERR: line 379: il
- ov110_func_021BC78C.c..ov110_func_021BCC58.c: c99=CCERR: line 315: illegal implicit conversion from 'unsigned char *' to | line 315: 'struct  *' | line 355: illegal implicit conversion from 'struct Object_021BCB50 *' to nolang=CCERR: line 315: il
- ov110_func_021BC93C.c..ov110_func_021BCC58.c: c99=CCERR: line 190: illegal implicit conversion from 'unsigned char *' to | line 190: 'struct  *' | line 230: illegal implicit conversion from 'struct Object_021BCB50 *' to nolang=CCERR: line 190: il
- ov110_func_021BCA84.c..ov110_func_021BCC58.c: c99=CCERR: line 118: illegal implicit conversion from 'struct Object_021BCB50 *' to | line 118: 'struct  *' | line 145: illegal implicit conversion from 'unsigned char *' to nolang=CCERR: line 118: il
- ov110_func_021BCB50.c..ov110_func_021BCC58.c: prototype of func_021BCAD8 differs between members (src/matched/ov/ov110_func_021BCC58.c)
- ov110_func_021BCF70.c..ov110_func_021BEB60.c: prototype of func_0204A6C8 differs between members (src/matched/ov/ov110_func_021BD194.c); prototype of func_0204AF28 differs between members (src/matched/ov/ov110_func_021BD194.c); prototype of func_
- ov110_func_021BD764.c..ov110_func_021BEB60.c: prototype of func_021BEDEC differs between members (src/matched/ov/ov110_func_021BD868.c); prototype of func_021BAE24 differs between members (src/matched/ov/ov110_func_021BD894.c); prototype of func_
- ov110_func_021BD764.c..ov110_func_021BDEAC.c: prototype of func_021BEDEC differs between members (src/matched/ov/ov110_func_021BD868.c); prototype of func_021BAE24 differs between members (src/matched/ov/ov110_func_021BD894.c); prototype of func_
- ov110_func_021BD764.c..ov110_func_021BDA84.c: prototype of func_021BEDEC differs between members (src/matched/ov/ov110_func_021BD868.c); prototype of func_021BAE24 differs between members (src/matched/ov/ov110_func_021BD894.c); prototype of func_

Members, in address order:

- `ov110_func_021BCB50.c`
- `ov110_func_021BCC58.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names pmsiv_menu.c` again.
