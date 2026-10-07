# field_nogrid_mapper.c (ov021)

Translation unit 021B8848..021BB578, 101 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`field_nogrid_mapper.c` is blocked by:

- ov021_func_021B8848.c..ov021_func_021BB528.c: prototype of VEC_Normalize differs between members (src/matched/ov/ov021_func_021B9A50.c); prototype of func_0207CEE4 differs between members (src/matched/ov/ov021_func_021B9B7C.c); prototype of func_
- ov021_func_021B8848.c..ov021_func_021BA4FC.c: prototype of func_021B8308 differs between members (src/matched/ov/ov021_func_021B9C28.c); prototype of func_021B8308 differs between members (src/matched/ov/ov021_func_021B9D60.c); type typedef Rec d
- ov021_func_021B8848.c..func_021B9510.c: c99=CCERR: line 286: illegal implicit conversion from 'void *' to | line 286: 'unsigned int' | line 298: illegal implicit conversion from 'void *' to nolang=CCERR: line 286: illegal implicit conversio
- ov021_func_021B8848.c..ov021_func_021B9238.c: c99=CCERR: line 560: illegal implicit conversion from 'unsigned char *' to | line 560: 'struct  *' | line 604: illegal implicit conversion from 'struct  *' to nolang=CCERR: line 560: illegal implicit 
- func_021B9530.c..ov021_func_021BA4FC.c: prototype of func_021B8308 differs between members (src/matched/ov/ov021_func_021B9C28.c); prototype of func_021B8308 differs between members (src/matched/ov/ov021_func_021B9D60.c); prototype of func_
- func_021B9530.c..ov021_func_021B9A50.c: c99=CCERR: line 186: illegal implicit conversion from 'unsigned int *' to | line 186: 'struct  *' | line 191: illegal implicit conversion from 'unsigned int *' to nolang=CCERR: line 186: illegal impli
- func_021B9530.c..func_021B9768.c: c99=CCERR: line 121: illegal implicit conversion from 'unsigned int *' to | line 121: 'struct  *' | line 126: illegal implicit conversion from 'unsigned int *' to nolang=CCERR: line 121: illegal impli
- ov021_func_021B976C.c..ov021_func_021B9A50.c: c99=CCERR: line 109: function call 'func_021B976C(void *, struct  *, unsigned char[])' does not match | line 109: 'func_021B976C(void *, struct  *)' | line 113: function call 'func_021B976C(void *, st
- ov021_func_021B976C.c..ov021_func_021B97D0.c: c99=CCERR: line 70: function call 'func_021B976C(void *, struct  *, unsigned char[])' does not match | line 70: 'func_021B976C(void *, struct  *)' | line 74: function call 'func_021B976C(void *, struc
- ov021_func_021B97FC.c..ov021_func_021B9A50.c: c99=CCERR: line 125: object 'FX_Mul(int, int)' redefined nolang=CCERR: line 125: object 'FX_Mul(int, int)' redefined
- ov021_func_021B9828.c..ov021_func_021B9A50.c: c99=CCERR: line 100: object 'FX_Mul(int, int)' redefined nolang=CCERR: line 100: object 'FX_Mul(int, int)' redefined
- ov021_func_021B9B24.c..ov021_func_021BA4FC.c: prototype of func_021B8308 differs between members (src/matched/ov/ov021_func_021B9C28.c); prototype of func_021B8308 differs between members (src/matched/ov/ov021_func_021B9D60.c); prototype of func_
- ov021_func_021B9B24.c..ov021_func_021B9FC8.c: prototype of func_021B8308 differs between members (src/matched/ov/ov021_func_021B9C28.c); prototype of func_021B8308 differs between members (src/matched/ov/ov021_func_021B9D60.c); prototype of func_
- ov021_func_021B9B24.c..ov021_func_021B9C28.c: prototype of func_021B8308 differs between members (src/matched/ov/ov021_func_021B9C28.c)
- ov021_func_021B9B7C.c..ov021_func_021B9C28.c: prototype of func_021B8308 differs between members (src/matched/ov/ov021_func_021B9C28.c)
- ov021_func_021B9D60.c..ov021_func_021B9FC8.c: prototype of func_0207C768 differs between members (src/matched/ov/ov021_func_021B9FC8.c); prototype of func_0207CA00 differs between members (src/matched/ov/ov021_func_021B9FC8.c)
- ov021_func_021B9E84.c..ov021_func_021B9FC8.c: prototype of func_0207C768 differs between members (src/matched/ov/ov021_func_021B9FC8.c)
- ov021_func_021BA25C.c..ov021_func_021BA4FC.c: prototype of func_0218EC90 differs between members (src/matched/ov/ov021_func_021BA494.c); prototype of func_021B8314 differs between members (src/matched/ov/ov021_func_021BA4C4.c); prototype of func_
- ov021_func_021BA348.c..ov021_func_021BA4FC.c: prototype of func_0218EC90 differs between members (src/matched/ov/ov021_func_021BA4C4.c); prototype of func_0218EC90 differs between members (src/matched/ov/ov021_func_021BA4FC.c)
- ov021_func_021BA550.c..ov021_func_021BB528.c: prototype of func_021B830C differs between members (src/matched/ov/ov021_func_021BA7B0.c); prototype of func_0218EC90 differs between members (src/matched/ov/ov021_func_021BA7E0.c); prototype of func_
- ov021_func_021BA550.c..func_021BB1B8.c: prototype of func_021B830C differs between members (src/matched/ov/ov021_func_021BA7B0.c); prototype of func_0218EC90 differs between members (src/matched/ov/ov021_func_021BA7E0.c); prototype of func_
- ov021_func_021BA550.c..ov021_func_021BAC04.c: prototype of func_021B830C differs between members (src/matched/ov/ov021_func_021BA7B0.c); prototype of func_0218EC90 differs between members (src/matched/ov/ov021_func_021BA7E0.c); prototype of func_
- ov021_func_021BA550.c..ov021_func_021BA9B4.c: prototype of func_021B830C differs between members (src/matched/ov/ov021_func_021BA7B0.c); prototype of func_0218EC90 differs between members (src/matched/ov/ov021_func_021BA7E0.c); prototype of func_
- ov021_func_021BA550.c..ov021_func_021BA7B0.c: prototype of func_021B830C differs between members (src/matched/ov/ov021_func_021BA7B0.c); prototype of func_021BA7E0 differs between members (src/matched/ov/ov021_func_021BA7B0.c)
- ov021_func_021BA6E8.c..ov021_func_021BA7B0.c: prototype of func_021B830C differs between members (src/matched/ov/ov021_func_021BA7B0.c); prototype of func_021BA7E0 differs between members (src/matched/ov/ov021_func_021BA7B0.c)
- ov021_func_021BA7E0.c..ov021_func_021BA9B4.c: prototype of func_021B830C differs between members (src/matched/ov/ov021_func_021BA9B4.c)
- ov021_func_021BA8E0.c..ov021_func_021BA9B4.c: prototype of func_021B830C differs between members (src/matched/ov/ov021_func_021BA9B4.c)
- ov021_func_021BAA30.c..ov021_func_021BAC04.c: prototype of func_021B830C differs between members (src/matched/ov/ov021_func_021BAA9C.c); prototype of func_021B830C differs between members (src/matched/ov/ov021_func_021BAB30.c); prototype of func_
- ov021_func_021BAA30.c..ov021_func_021BAB30.c: prototype of func_021B830C differs between members (src/matched/ov/ov021_func_021BAA9C.c); prototype of func_021B830C differs between members (src/matched/ov/ov021_func_021BAB30.c)
- ov021_func_021BAC74.c..func_021BB1B8.c: prototype of func_021B836C differs between members (src/matched/ov/ov021_func_021BB014.c); prototype of func_0218EC90 differs between members (src/matched/ov/ov021_func_021BB014.c)
- ov021_func_021BAC74.c..func_021BB0A4.c: prototype of func_021B836C differs between members (src/matched/ov/ov021_func_021BB014.c); prototype of func_0218EC90 differs between members (src/matched/ov/ov021_func_021BB014.c)
- ov021_func_021BAC74.c..ov021_func_021BAE7C.c: c99=CCERR: line 114: declaration syntax error nolang=CCERR: line 114: declaration syntax error
- ov021_func_021BACA8.c..ov021_func_021BAE7C.c: c99=CCERR: line 88: declaration syntax error nolang=CCERR: line 88: declaration syntax error
- func_021BB1C4.c..ov021_func_021BB528.c: prototype of func_021B79F0 differs between members (src/matched/ov/ov021_func_021BB388.c)
- func_021BB3A0.c..ov021_func_021BB528.c: c99=CCERR: line 192: illegal implicit conversion from 'unsigned char *' to | line 192: 'struct  *' nolang=CCERR: line 192: illegal implicit conversion from 'unsigned char *' to | line 192: 'struct  *'
- ov021_func_021BB3E8.c..ov021_func_021BB528.c: c99=CCERR: line 137: illegal implicit conversion from 'unsigned char *' to | line 137: 'struct  *' nolang=CCERR: line 137: illegal implicit conversion from 'unsigned char *' to | line 137: 'struct  *'
- func_021BB4A8.c..ov021_func_021BB528.c: c99=CCERR: line 73: illegal implicit conversion from 'unsigned char *' to | line 73: 'struct  *' nolang=CCERR: line 73: illegal implicit conversion from 'unsigned char *' to | line 73: 'struct  *'

Members, in address order:

- `ov021_func_021B976C.c`
- `ov021_func_021B97FC.c`
- `ov021_func_021B9828.c`
- `ov021_func_021B9A50.c`
- `ov021_func_021B9B24.c`
- `ov021_func_021B9B7C.c`
- `ov021_func_021B9C28.c`
- `ov021_func_021B9D60.c`
- `ov021_func_021B9E84.c`
- `ov021_func_021B9FC8.c`
- `ov021_func_021BA550.c`
- `ov021_func_021BA6E8.c`
- `ov021_func_021BA7B0.c`
- `ov021_func_021BA7E0.c`
- `ov021_func_021BA8E0.c`
- `ov021_func_021BA9B4.c`
- `ov021_func_021BAA30.c`
- `ov021_func_021BAC74.c`
- `ov021_func_021BACA8.c`
- `ov021_func_021BAE7C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names field_nogrid_mapper.c` again.
