# union_comm.c (ov012)

Translation unit 02172BC0..0217422C, 88 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`union_comm.c` is blocked by:

- ov012_func_02172BC0.c..ov012_func_0217416C.c: prototype of func_02082BCC differs between members (src/matched/ov/ov012_func_021734E0.c); prototype of func_02082BCC differs between members (src/matched/ov/ov012_func_02173524.c); prototype of func_
- ov012_func_02172BC0.c..ov012_func_02173928.c: prototype of func_02082BCC differs between members (src/matched/ov/ov012_func_021734E0.c); prototype of func_02082BCC differs between members (src/matched/ov/ov012_func_02173524.c); prototype of func_
- ov012_func_02172BC0.c..ov012_func_02173248.c: c99=CCERR: line 192: warning: types that are declared in parameter lists ('Work_0217303C') go out of scope at the end of the function declaration/definition, | line 192: warning: this is probably not 
- ov012_func_02172BC0.c..ov012_func_02172D50.c: c99=CCERR: line 112: illegal implicit conversion from 'struct  *' to | line 112: 'struct Work_02172C4C *' nolang=CCERR: line 112: illegal implicit conversion from 'struct  *' to | line 112: 'struct Wo
- ov012_func_02172BC0.c..ov012_func_02172C98.c: c99=CCERR: line 99: illegal implicit conversion from 'struct  *' to | line 99: 'struct Work_02172C4C *' nolang=CCERR: line 99: illegal implicit conversion from 'struct  *' to | line 99: 'struct Work_0
- ov012_func_02172D68.c..ov012_func_02173248.c: c99=CCERR: line 261: illegal implicit conversion from 'struct  *' to | line 261: 'struct  *' | line 263: illegal implicit conversion from 'struct  *' to nolang=CCERR: line 261: illegal implicit conver
- ov012_func_02172D68.c..ov012_func_02172EEC.c: c99=CCERR: line 170: illegal implicit conversion from 'struct  *' to | line 170: 'struct  *' nolang=CCERR: line 170: illegal implicit conversion from 'struct  *' to | line 170: 'struct  *'
- ov012_func_02172E48.c..ov012_func_02172EEC.c: c99=CCERR: line 94: illegal implicit conversion from 'struct  *' to | line 94: 'struct  *' nolang=CCERR: line 94: illegal implicit conversion from 'struct  *' to | line 94: 'struct  *'
- ov012_func_02172FF0.c..ov012_func_02173248.c: c99=CCERR: line 164: illegal implicit conversion from 'struct Entry_021730C8 *' to | line 164: 'struct Entry_021730F8 *' | line 188: illegal implicit conversion from 'struct Entry_021730F8 *' to nolan
- ov012_func_021730F8.c..ov012_func_02173248.c: c99=CCERR: line 90: illegal implicit conversion from 'struct Entry_021730F8 *' to | line 90: 'struct Entry_021731E0 *' nolang=CCERR: line 90: illegal implicit conversion from 'struct Entry_021730F8 *'
- ov012_func_0217325C.c..ov012_func_02173928.c: prototype of func_02082BCC differs between members (src/matched/ov/ov012_func_021734E0.c); prototype of func_02082BCC differs between members (src/matched/ov/ov012_func_02173524.c); prototype of func_
- ov012_func_0217325C.c..ov012_func_02173650.c: prototype of func_02082BCC differs between members (src/matched/ov/ov012_func_021734E0.c); prototype of func_02082BCC differs between members (src/matched/ov/ov012_func_02173524.c); prototype of func_
- ov012_func_0217325C.c..ov012_func_021734E0.c: prototype of func_02082BCC differs between members (src/matched/ov/ov012_func_021734E0.c)
- ov012_func_0217325C.c..ov012_func_02173408.c: c99=DIFF nolang=DIFF
- ov012_func_02173934.c..ov012_func_0217416C.c: global d_02175624 declared two ways (src/matched/ov/ov012_func_02173F54.c); global d_02175624 declared two ways (src/matched/ov/ov012_func_02173FE0.c); global d_02175624 declared two ways (src/matched
- ov012_func_02173CCC.c..ov012_func_0217416C.c: c99=DIFF nolang=DIFF
- ov012_func_02173CCC.c..ov012_func_02173EEC.c: c99=DIFF nolang=DIFF
- ov012_func_02173CCC.c..ov012_func_02173DE4.c: c99=DIFF nolang=DIFF

Members, in address order:

- `ov012_func_02172E48.c`
- `ov012_func_021730F8.c`
- `ov012_func_0217325C.c`
- `ov012_func_02173408.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names union_comm.c` again.
