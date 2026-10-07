# ui_scene.c (ov067)

Translation unit 021B6100..021B940C, 110 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`ui_scene.c` is blocked by:

- ov067_func_021B6100.c..ov067_func_021B93D4.c: prototype of func_02030734 differs between members (src/matched/ov/ov067_func_021B62E0.c); prototype of func_02082BCC differs between members (src/matched/ov/ov067_func_021B62E0.c); prototype of func_
- ov067_func_021B6100.c..ov067_func_021B6DC0.c: prototype of func_02030734 differs between members (src/matched/ov/ov067_func_021B62E0.c); prototype of func_02082BCC differs between members (src/matched/ov/ov067_func_021B62E0.c); prototype of func_
- ov067_func_021B65C8.c..ov067_func_021B6DC0.c: prototype of func_02082BCC differs between members (src/matched/ov/ov067_func_021B66FC.c); prototype of func_02082BCC differs between members (src/matched/ov/ov067_func_021B67F8.c); prototype of func_
- ov067_func_021B65C8.c..ov067_func_021B69F8.c: c99=CCERR: line 140: identifier 'S' redeclared | line 140: was declared as: 'struct ' | line 140: now declared as: 'struct S' nolang=CCERR: line 140: identifier 'S' redeclared | line 140: was declared
- ov067_func_021B65C8.c..ov067_func_021B6738.c: c99=CCERR: line 132: illegal implicit conversion from 'void *' to | line 132: 'unsigned int' nolang=CCERR: line 132: illegal implicit conversion from 'void *' to | line 132: 'unsigned int'
- ov067_func_021B67F8.c..ov067_func_021B69F8.c: c99=CCERR: line 105: struct/union/enum/class tag 'S' redefined | line 264: 'f8' is not a member of class 'struct S' | line 266: 'f8' is not a member of class 'struct S' nolang=CCERR: line 105: struct/
- ov067_func_021B6A10.c..ov067_func_021B6DC0.c: prototype of func_020061E4 differs between members (src/matched/ov/ov067_func_021B6A44.c); prototype of func_0201D304 differs between members (src/matched/ov/ov067_func_021B6C4C.c); prototype of func_
- ov067_func_021B709C.c..ov067_func_021B93D4.c: prototype of func_0204B404 differs between members (src/matched/ov/ov067_func_021B7378.c); prototype of func_020355D8 differs between members (src/matched/ov/ov067_func_021B7CF8.c)
- ov067_func_021B709C.c..ov067_func_021B8A44.c: prototype of func_0204B404 differs between members (src/matched/ov/ov067_func_021B7378.c); prototype of func_021B9344 differs between members (src/matched/ov/ov067_func_021B7AB0.c); prototype of func_
- ov067_func_021B709C.c..ov067_func_021B7A64.c: prototype of func_0204B404 differs between members (src/matched/ov/ov067_func_021B7378.c)
- ov067_func_021B709C.c..ov067_func_021B76C8.c: prototype of func_0204B404 differs between members (src/matched/ov/ov067_func_021B7378.c)
- ov067_func_021B7AB0.c..ov067_func_021B8A44.c: prototype of func_020355D8 differs between members (src/matched/ov/ov067_func_021B7E70.c); prototype of func_021B92F0 differs between members (src/matched/ov/ov067_func_021B806C.c); prototype of func_
- ov067_func_021B7AB0.c..ov067_func_021B806C.c: prototype of func_020355D8 differs between members (src/matched/ov/ov067_func_021B7E70.c); prototype of func_021B92F0 differs between members (src/matched/ov/ov067_func_021B806C.c)
- ov067_func_021B7CF8.c..ov067_func_021B806C.c: prototype of func_020355D8 differs between members (src/matched/ov/ov067_func_021B7E70.c)
- ov067_func_021B7E70.c..ov067_func_021B806C.c: c99=CCERR: line 59: struct/union/enum/class tag 'S' redefined | line 194: 'f34' is not a member of class 'struct S' | line 203: 'f20' is not a member of class 'struct S' nolang=CCERR: line 59: struct/
- ov067_func_021B8A88.c..ov067_func_021B93D4.c: prototype of func_021B8434 differs between members (src/matched/ov/ov067_func_021B8EA0.c)
- ov067_func_021B8A88.c..ov067_func_021B9190.c: prototype of func_021B8434 differs between members (src/matched/ov/ov067_func_021B8EA0.c)
- ov067_func_021B8DF0.c..ov067_func_021B9190.c: prototype of func_021B8434 differs between members (src/matched/ov/ov067_func_021B8EA0.c)
- ov067_func_021B8DF0.c..ov067_func_021B8FA0.c: prototype of func_021B8434 differs between members (src/matched/ov/ov067_func_021B8EA0.c)
- ov067_func_021B91BC.c..ov067_func_021B93D4.c: prototype of func_021B8FE4 differs between members (src/matched/ov/ov067_func_021B9228.c); prototype of func_021B90B8 differs between members (src/matched/ov/ov067_func_021B9228.c); prototype of func_
- ov067_func_021B91BC.c..ov067_func_021B9344.c: prototype of func_021B8FE4 differs between members (src/matched/ov/ov067_func_021B9228.c); prototype of func_021B90B8 differs between members (src/matched/ov/ov067_func_021B9228.c); prototype of func_
- ov067_func_021B91BC.c..ov067_func_021B9228.c: prototype of func_021B8FE4 differs between members (src/matched/ov/ov067_func_021B9228.c); prototype of func_021B90B8 differs between members (src/matched/ov/ov067_func_021B9228.c); prototype of func_
- ov067_func_021B91D0.c..ov067_func_021B9228.c: prototype of func_021B8FE4 differs between members (src/matched/ov/ov067_func_021B9228.c); prototype of func_021B90B8 differs between members (src/matched/ov/ov067_func_021B9228.c); prototype of func_

Members, in address order:

- `ov067_func_021B7CF8.c`
- `ov067_func_021B7E70.c`
- `ov067_func_021B806C.c`
- `ov067_func_021B8DF0.c`
- `ov067_func_021B91BC.c`
- `ov067_func_021B91D0.c`
- `ov067_func_021B9228.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names ui_scene.c` again.
