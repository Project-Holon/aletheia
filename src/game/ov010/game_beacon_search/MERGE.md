# game_beacon_search.c (ov010)

Translation unit 02164B38..02165FC0, 139 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`game_beacon_search.c` is blocked by:

- ov010_func_02164B38.c..ov010_func_02165FB4.c: prototype of func_02082BCC differs between members (src/matched/ov/ov010_func_02164EB4.c); prototype of func_0202744C differs between members (src/matched/ov/func_0216544C.c); prototype of func_020274
- ov010_func_02164B38.c..func_0216566C.c: prototype of func_02082BCC differs between members (src/matched/ov/ov010_func_02164EB4.c); prototype of func_0202744C differs between members (src/matched/ov/func_0216544C.c); prototype of func_020274
- ov010_func_02164B38.c..func_0216527C.c: prototype of func_02082BCC differs between members (src/matched/ov/ov010_func_02164EB4.c)
- ov010_func_02164B38.c..func_02165094.c: prototype of func_02082BCC differs between members (src/matched/ov/ov010_func_02164EB4.c)
- ov010_func_02164E04.c..func_02165094.c: c99=CCERR: line 159: illegal implicit conversion from 'struct Ent *' to | line 159: 'struct Hdr_02164F9C *' | line 173: illegal implicit conversion from 'struct Hdr_02164E8C *' to nolang=CCERR: line 1
- ov010_func_02164E04.c..ov010_func_02164F9C.c: c99=CCERR: line 112: illegal implicit conversion from 'struct Ent *' to | line 112: 'struct Hdr_02164F9C *' | line 126: illegal implicit conversion from 'struct Hdr_02164E8C *' to nolang=CCERR: line 1
- ov010_func_02164EB4.c..ov010_func_02164F9C.c: c99=DIFF nolang=DIFF
- ov010_func_02164FC4.c..func_02165094.c: c99=CCERR: line 114: illegal implicit conversion from 'int' to | line 114: 'void *' nolang=CCERR: line 114: illegal implicit conversion from 'int' to | line 114: 'void *'
- func_0216505C.c..func_02165094.c: c99=CCERR: line 59: illegal implicit conversion from 'int' to | line 59: 'void *' nolang=CCERR: line 59: illegal implicit conversion from 'int' to | line 59: 'void *'
- func_0216528C.c..func_0216566C.c: prototype of func_0202744C differs between members (src/matched/ov/func_0216544C.c); prototype of func_0202744C differs between members (src/matched/ov/func_02165490.c); prototype of func_0202744C dif
- func_0216528C.c..func_02165468.c: prototype of func_0202744C differs between members (src/matched/ov/func_0216544C.c)
- ov010_func_02165374.c..func_02165468.c: prototype of func_0202744C differs between members (src/matched/ov/func_0216544C.c)
- func_021653F4.c..func_02165468.c: prototype of func_0202744C differs between members (src/matched/ov/func_0216544C.c)
- func_02165690.c..ov010_func_02165FB4.c: prototype of func_0202744C differs between members (src/matched/ov/func_02165794.c); prototype of func_0202744C differs between members (src/matched/ov/func_0216586C.c); type struct Queue differs betw
- func_02165690.c..func_02165C60.c: prototype of func_0202744C differs between members (src/matched/ov/func_02165794.c); prototype of func_0202744C differs between members (src/matched/ov/func_0216586C.c); type struct Queue differs betw
- func_02165690.c..func_0216586C.c: prototype of func_0202744C differs between members (src/matched/ov/func_02165794.c); prototype of func_0202744C differs between members (src/matched/ov/func_0216586C.c)
- func_02165690.c..func_0216573C.c: c99=CCERR: line 72: illegal implicit conversion from 'char *' to | line 72: 'unsigned char *' nolang=CCERR: line 72: illegal implicit conversion from 'char *' to | line 72: 'unsigned char *'
- func_02165760.c..func_0216586C.c: prototype of func_0202744C differs between members (src/matched/ov/func_02165794.c); prototype of func_0202744C differs between members (src/matched/ov/func_0216586C.c)
- func_02165760.c..ov010_func_021657B0.c: prototype of func_0202744C differs between members (src/matched/ov/func_02165794.c)
- func_021657D8.c..func_0216586C.c: prototype of func_0202744C differs between members (src/matched/ov/func_0216586C.c)
- ov010_func_02165814.c..func_0216586C.c: prototype of func_0202744C differs between members (src/matched/ov/func_0216586C.c)
- ov010_func_02165888.c..func_02165C60.c: type struct Queue differs between members (src/matched/ov/ov010_func_02165960.c); type struct Queue differs between members (src/matched/ov/ov010_func_02165A10.c); type struct Queue differs between me
- func_02165C78.c..ov010_func_02165FB4.c: prototype of func_0204581C differs between members (src/matched/ov/func_02165D6C.c); prototype of func_0204581C differs between members (src/matched/ov/func_02165D8C.c)
- func_02165C78.c..func_02165D8C.c: prototype of func_0204581C differs between members (src/matched/ov/func_02165D6C.c); prototype of func_0204581C differs between members (src/matched/ov/func_02165D8C.c)
- ov010_func_02165D10.c..func_02165D8C.c: prototype of func_0204581C differs between members (src/matched/ov/func_02165D6C.c); prototype of func_0204581C differs between members (src/matched/ov/func_02165D8C.c)
- ov010_func_02165D40.c..func_02165D8C.c: prototype of func_0204581C differs between members (src/matched/ov/func_02165D6C.c); prototype of func_0204581C differs between members (src/matched/ov/func_02165D8C.c)
- func_02165D50.c..func_02165D8C.c: prototype of func_0204581C differs between members (src/matched/ov/func_02165D6C.c); prototype of func_0204581C differs between members (src/matched/ov/func_02165D8C.c)

Members, in address order:

- `ov010_func_02164EB4.c`
- `ov010_func_02164F9C.c`
- `func_0216505C.c`
- `ov010_func_02165814.c`
- `func_02165D50.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names game_beacon_search.c` again.
