# btl_rec.c (ov093)

Translation unit 021EE104..021EFA94, 104 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`btl_rec.c` is blocked by:

- ov093_func_021EE104.c..ov093_func_021EF9F4.c: prototype of func_02082BCC differs between members (src/matched/ov/ov093_func_021EE8B4.c); prototype of func_02082D44 differs between members (src/matched/ov/ov093_func_021EE8F4.c); prototype of func_
- ov093_func_021EE104.c..ov093_func_021EECD8.c: prototype of func_02082BCC differs between members (src/matched/ov/ov093_func_021EE8B4.c); prototype of func_02082D44 differs between members (src/matched/ov/ov093_func_021EE8F4.c); prototype of func_
- ov093_func_021EE104.c..ov093_func_021EE8B4.c: prototype of func_02082BCC differs between members (src/matched/ov/ov093_func_021EE8B4.c)
- ov093_func_021EE104.c..ov093_func_021EE4B4.c: c99=CCERR: line 149: identifier 'func_021EE25C()' redeclared as 'void ()' | line 147: identifier 'func_021EE25C()' was originally declared as 'int ()' | line 236: identifier 'func_021EE25C()' redeclar
- func_021EE25C.c..ov093_func_021EE4B4.c: c99=DIFF nolang=DIFF
- func_021EE25C.c..ov093_func_021EE318.c: c99=DIFF nolang=DIFF
- ov093_func_021EE8D8.c..ov093_func_021EECD8.c: global d_021F6388 declared two ways (src/matched/ov/ov093_func_021EEA58.c); global d_021F6398 declared two ways (src/matched/ov/ov093_func_021EECD8.c)
- func_021EEAFC.c..ov093_func_021EECD8.c: global d_021F6398 declared two ways (src/matched/ov/ov093_func_021EECD8.c)
- ov093_func_021EEBA4.c..ov093_func_021EECD8.c: global d_021F6398 declared two ways (src/matched/ov/ov093_func_021EECD8.c)
- ov093_func_021EEC20.c..ov093_func_021EECD8.c: global d_021F6398 declared two ways (src/matched/ov/ov093_func_021EECD8.c)
- ov093_func_021EEC78.c..ov093_func_021EECD8.c: global d_021F6398 declared two ways (src/matched/ov/ov093_func_021EECD8.c)
- ov093_func_021EED00.c..ov093_func_021EF9F4.c: global d_021F6398 declared two ways (src/matched/ov/ov093_func_021EED24.c); global d_021F6398 declared two ways (src/matched/ov/ov093_func_021EED48.c); global d_021F6398 declared two ways (src/matched
- ov093_func_021EED00.c..ov093_func_021EF6E8.c: global d_021F6398 declared two ways (src/matched/ov/ov093_func_021EED24.c); global d_021F6398 declared two ways (src/matched/ov/ov093_func_021EED48.c); global d_021F6398 declared two ways (src/matched
- ov093_func_021EED00.c..ov093_func_021EEFE0.c: global d_021F6398 declared two ways (src/matched/ov/ov093_func_021EED24.c); global d_021F6398 declared two ways (src/matched/ov/ov093_func_021EED48.c); global d_021F6398 declared two ways (src/matched
- ov093_func_021EED00.c..ov093_func_021EEE24.c: global d_021F6398 declared two ways (src/matched/ov/ov093_func_021EED24.c); global d_021F6398 declared two ways (src/matched/ov/ov093_func_021EED48.c); global d_021F6398 declared two ways (src/matched
- ov093_func_021EED6C.c..ov093_func_021EEE24.c: global d_021F6398 declared two ways (src/matched/ov/ov093_func_021EED90.c); global d_021F6398 declared two ways (src/matched/ov/ov093_func_021EEE24.c)
- ov093_func_021EEE80.c..ov093_func_021EEFE0.c: global d_021F6398 declared two ways (src/matched/ov/ov093_func_021EEEC8.c)
- ov093_func_021EEE80.c..ov093_func_021EEEF4.c: global d_021F6398 declared two ways (src/matched/ov/ov093_func_021EEEC8.c)
- ov093_func_021EF1CC.c..ov093_func_021EF6E8.c: global d_021F6398 declared two ways (src/matched/ov/ov093_func_021EF204.c); global d_021F6398 declared two ways (src/matched/ov/ov093_func_021EF280.c); global d_021F63D8 declared two ways (src/matched
- ov093_func_021EF1CC.c..ov093_func_021EF508.c: global d_021F6398 declared two ways (src/matched/ov/ov093_func_021EF204.c); global d_021F6398 declared two ways (src/matched/ov/ov093_func_021EF280.c); global d_021F63D8 declared two ways (src/matched
- ov093_func_021EF1CC.c..ov093_func_021EF280.c: global d_021F6398 declared two ways (src/matched/ov/ov093_func_021EF204.c); global d_021F6398 declared two ways (src/matched/ov/ov093_func_021EF280.c); global d_021F63D8 declared two ways (src/matched
- ov093_func_021EF204.c..ov093_func_021EF280.c: global d_021F6398 declared two ways (src/matched/ov/ov093_func_021EF280.c); global d_021F63D8 declared two ways (src/matched/ov/ov093_func_021EF280.c)
- ov093_func_021EF3A4.c..ov093_func_021EF508.c: global d_021F6398 declared two ways (src/matched/ov/ov093_func_021EF508.c)
- ov093_func_021EF460.c..ov093_func_021EF508.c: global d_021F6398 declared two ways (src/matched/ov/ov093_func_021EF508.c)
- ov093_func_021EF594.c..ov093_func_021EF6E8.c: global d_021F6398 declared two ways (src/matched/ov/ov093_func_021EF5E8.c); global d_021F6398 declared two ways (src/matched/ov/ov093_func_021EF664.c); global d_021F6398 declared two ways (src/matched
- ov093_func_021EF594.c..ov093_func_021EF664.c: global d_021F6398 declared two ways (src/matched/ov/ov093_func_021EF5E8.c); global d_021F6398 declared two ways (src/matched/ov/ov093_func_021EF664.c)
- ov093_func_021EF5E8.c..ov093_func_021EF664.c: global d_021F6398 declared two ways (src/matched/ov/ov093_func_021EF664.c)
- ov093_func_021EF694.c..ov093_func_021EF6E8.c: global d_021F6398 declared two ways (src/matched/ov/ov093_func_021EF6B0.c)
- ov093_func_021EF6F0.c..ov093_func_021EF9F4.c: global d_021F6398 declared two ways (src/matched/ov/ov093_func_021EF71C.c); global d_021F6398 declared two ways (src/matched/ov/ov093_func_021EF7AC.c)
- ov093_func_021EF6F0.c..ov093_func_021EF8F8.c: global d_021F6398 declared two ways (src/matched/ov/ov093_func_021EF71C.c); global d_021F6398 declared two ways (src/matched/ov/ov093_func_021EF7AC.c)
- ov093_func_021EF894.c..ov093_func_021EF8F8.c: c99=CCERR: line 82: object 'DWC_StartUtilityEx(int, int)' redefined nolang=CCERR: line 82: object 'DWC_StartUtilityEx(int, int)' redefined
- ov093_func_021EF90C.c..ov093_func_021EF9F4.c: c99=CCERR: line 133: illegal implicit conversion from 'struct  *' to | line 133: 'struct  *' nolang=CCERR: line 133: illegal implicit conversion from 'struct  *' to | line 133: 'struct  *'
- no verified entry for 021EFA84

Members, in address order:

- `func_021EE25C.c`
- `ov093_func_021EEC78.c`
- `ov093_func_021EECD8.c`
- `ov093_func_021EED6C.c`
- `ov093_func_021EEE80.c`
- `ov093_func_021EF1CC.c`
- `ov093_func_021EF204.c`
- `ov093_func_021EF280.c`
- `ov093_func_021EF3A4.c`
- `ov093_func_021EF460.c`
- `ov093_func_021EF508.c`
- `ov093_func_021EF594.c`
- `ov093_func_021EF5E8.c`
- `ov093_func_021EF664.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names btl_rec.c` again.
