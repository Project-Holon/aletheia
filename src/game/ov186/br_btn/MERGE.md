# br_btn.c (ov186)

Translation unit 021F9CB8..021FC3BC, 84 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`br_btn.c` is blocked by:

- ov186_func_021F9CB8.c..ov186_func_021FC394.c: prototype of func_02034714 differs between members (src/matched/ov/ov186_func_021FA020.c); global d_02200D18 declared two ways (src/matched/ov/ov186_func_021FA020.c); prototype of func_02082BCC differ
- ov186_func_021F9CB8.c..ov186_func_021FB0E8.c: prototype of func_02034714 differs between members (src/matched/ov/ov186_func_021FA020.c); global d_02200D18 declared two ways (src/matched/ov/ov186_func_021FA020.c); prototype of func_02082BCC differ
- ov186_func_021F9CB8.c..ov186_func_021FAA34.c: prototype of func_02034714 differs between members (src/matched/ov/ov186_func_021FA020.c); global d_02200D18 declared two ways (src/matched/ov/ov186_func_021FA020.c); prototype of func_02082BCC differ
- ov186_func_021F9CB8.c..ov186_func_021FA1DC.c: prototype of func_02034714 differs between members (src/matched/ov/ov186_func_021FA020.c); global d_02200D18 declared two ways (src/matched/ov/ov186_func_021FA020.c); prototype of func_02082BCC differ
- ov186_func_021FA01C.c..ov186_func_021FA1DC.c: prototype of func_021FAFA0 differs between members (src/matched/ov/ov186_func_021FA0FC.c); prototype of func_02034714 differs between members (src/matched/ov/ov186_func_021FA1DC.c); global d_02200D18 
- ov186_func_021FAA74.c..ov186_func_021FB0E8.c: prototype of memset differs between members (src/matched/ov/ov186_func_021FADB8.c)
- ov186_func_021FB1EC.c..ov186_func_021FC394.c: prototype of func_02082BCC differs between members (src/matched/ov/ov186_func_021FB5E4.c); global d_022007F0 declared two ways (src/matched/ov/ov186_func_021FB644.c); global d_022007F0 declared two wa
- ov186_func_021FB1EC.c..ov186_func_021FB7B0.c: prototype of func_02082BCC differs between members (src/matched/ov/ov186_func_021FB5E4.c); global d_022007F0 declared two ways (src/matched/ov/ov186_func_021FB644.c); global d_022007F0 declared two wa
- ov186_func_021FB1EC.c..ov186_func_021FB578.c: c99=CCERR: line 79: struct/union/enum/class tag 'PtS' redefined | line 187: illegal implicit conversion from 'int' to | line 187: 'void *' nolang=CCERR: line 79: struct/union/enum/class tag 'PtS' rede
- ov186_func_021FB1EC.c..ov186_func_021FB494.c: c99=CCERR: line 165: illegal implicit conversion from 'int' to | line 165: 'void *' nolang=CCERR: line 165: illegal implicit conversion from 'int' to | line 165: 'void *'
- ov186_func_021FB378.c..ov186_func_021FB494.c: c99=CCERR: line 85: illegal implicit conversion from 'int' to | line 85: 'void *' nolang=CCERR: line 85: illegal implicit conversion from 'int' to | line 85: 'void *'
- ov186_func_021FB4B4.c..ov186_func_021FB578.c: c99=CCERR: line 40: struct/union/enum/class tag 'PtS' redefined nolang=CCERR: line 40: struct/union/enum/class tag 'PtS' redefined
- ov186_func_021FB594.c..ov186_func_021FB7B0.c: global d_022007F0 declared two ways (src/matched/ov/ov186_func_021FB644.c); global d_022007F0 declared two ways (src/matched/ov/ov186_func_021FB760.c)
- ov186_func_021FB63C.c..ov186_func_021FB7B0.c: global d_022007F0 declared two ways (src/matched/ov/ov186_func_021FB704.c); global d_022007F0 declared two ways (src/matched/ov/ov186_func_021FB760.c)
- ov186_func_021FB63C.c..ov186_func_021FB704.c: global d_022007F0 declared two ways (src/matched/ov/ov186_func_021FB704.c)
- ov186_func_021FB644.c..ov186_func_021FB704.c: global d_022007F0 declared two ways (src/matched/ov/ov186_func_021FB704.c)

Members, in address order:

- `ov186_func_021FB378.c`
- `ov186_func_021FB63C.c`
- `ov186_func_021FB644.c`
- `ov186_func_021FB704.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names br_btn.c` again.
