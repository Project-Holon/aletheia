# field_effect.c (ov021)

Translation unit 021A87A8..021AC810, 253 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`field_effect.c` is blocked by:

- ov021_func_021A87A8.c..ov021_func_021AC760.c: prototype of func_0204B3DC differs between members (src/matched/ov/ov021_func_021A8874.c); prototype of func_02040618 differs between members (src/matched/ov/ov021_func_021A8DD8.c); prototype of func_
- ov021_func_021A87A8.c..func_021AB27C.c: prototype of func_0204B3DC differs between members (src/matched/ov/ov021_func_021A8874.c); type typedef P differs between members (src/matched/ov/ov021_func_021A8DD8.c); prototype of func_02040618 dif
- ov021_func_021A87A8.c..ov021_func_021AA6E0.c: prototype of func_0204B3DC differs between members (src/matched/ov/ov021_func_021A8874.c); type typedef P differs between members (src/matched/ov/ov021_func_021A8DD8.c); prototype of func_0204B3DC dif
- ov021_func_021A87A8.c..ov021_func_021A9810.c: prototype of func_0204B3DC differs between members (src/matched/ov/ov021_func_021A8874.c); type typedef P differs between members (src/matched/ov/ov021_func_021A8DD8.c); prototype of func_0204B3DC dif
- ov021_func_021A87A8.c..ov021_func_021A8FFC.c: prototype of func_0204B3DC differs between members (src/matched/ov/ov021_func_021A8874.c); type typedef P differs between members (src/matched/ov/ov021_func_021A8DD8.c); prototype of func_0204B3DC dif
- ov021_func_021A87A8.c..ov021_func_021A8BB8.c: prototype of func_0204B3DC differs between members (src/matched/ov/ov021_func_021A8874.c)
- ov021_func_021A8D40.c..ov021_func_021A8FFC.c: prototype of func_021A90A4 differs between members (src/matched/ov/ov021_func_021A8FFC.c)
- func_021A8E78.c..ov021_func_021A8FFC.c: prototype of func_021A90A4 differs between members (src/matched/ov/ov021_func_021A8FFC.c)
- ov021_func_021A8EEC.c..ov021_func_021A8FFC.c: prototype of func_021A90A4 differs between members (src/matched/ov/ov021_func_021A8FFC.c)
- ov021_func_021A9080.c..ov021_func_021A9810.c: prototype of func_021A996C differs between members (src/matched/ov/ov021_func_021A957C.c)
- ov021_func_021A9080.c..ov021_func_021A9350.c: c99=CCERR: line 339: illegal implicit conversion from 'struct W *' to | line 339: 'struct  *' nolang=CCERR: line 339: illegal implicit conversion from 'struct W *' to | line 339: 'struct  *'
- ov021_func_021A9080.c..ov021_func_021A9154.c: c99=CCERR: line 218: illegal implicit conversion from 'struct W *' to | line 218: 'struct  *' nolang=CCERR: line 218: illegal implicit conversion from 'struct W *' to | line 218: 'struct  *'
- ov021_func_021A94B0.c..ov021_func_021A9810.c: prototype of func_021A996C differs between members (src/matched/ov/ov021_func_021A957C.c)
- ov021_func_021A9828.c..ov021_func_021AA6E0.c: prototype of func_021A9350 differs between members (src/matched/ov/ov021_func_021AA0A0.c); prototype of func_0216E7C8 differs between members (src/matched/ov/ov021_func_021AA0A0.c); prototype of func_
- ov021_func_021A9828.c..ov021_func_021A9EC4.c: c99=CCERR: line 285: illegal implicit conversion from 'const struct Entry8_021A99A8 *' to | line 285: 'const struct Entry8_021A99E4 *' | line 309: illegal implicit conversion from 'struct Unit_021A9A5
- ov021_func_021A9828.c..ov021_func_021A9BE8.c: c99=CCERR: line 238: illegal implicit conversion from 'const struct Entry8_021A99A8 *' to | line 238: 'const struct Entry8_021A99E4 *' | line 262: illegal implicit conversion from 'struct Unit_021A9A5
- ov021_func_021A9828.c..ov021_func_021A99E4.c: c99=CCERR: line 209: illegal implicit conversion from 'const struct Entry8_021A99A8 *' to | line 209: 'const struct Entry8_021A99E4 *' nolang=CCERR: line 209: illegal implicit conversion from 'const s
- ov021_func_021A99A8.c..ov021_func_021A99E4.c: c99=CCERR: line 81: illegal implicit conversion from 'const struct Entry8_021A99A8 *' to | line 81: 'const struct Entry8_021A99E4 *' nolang=CCERR: line 81: illegal implicit conversion from 'const stru
- ov021_func_021A9ED8.c..ov021_func_021AA6E0.c: prototype of func_021A9350 differs between members (src/matched/ov/ov021_func_021AA0A0.c); prototype of func_0216E7C8 differs between members (src/matched/ov/ov021_func_021AA0A0.c); prototype of func_
- ov021_func_021A9ED8.c..ov021_func_021AA35C.c: prototype of func_021A9350 differs between members (src/matched/ov/ov021_func_021AA0A0.c); prototype of func_021AA490 differs between members (src/matched/ov/ov021_func_021AA0A0.c); prototype of func_
- ov021_func_021AA180.c..ov021_func_021AA35C.c: prototype of func_021A9350 differs between members (src/matched/ov/ov021_func_021AA248.c); prototype of func_021AA490 differs between members (src/matched/ov/ov021_func_021AA248.c)
- ov021_func_021AA180.c..ov021_func_021AA248.c: prototype of func_021A9350 differs between members (src/matched/ov/ov021_func_021AA248.c); prototype of func_021AA490 differs between members (src/matched/ov/ov021_func_021AA248.c)
- ov021_func_021AA6F8.c..func_021AB27C.c: type struct Pos differs between members (src/matched/ov/ov021_func_021AA728.c); prototype of func_02012A38 differs between members (src/matched/ov/ov021_func_021AA900.c); prototype of func_02012A38 di
- ov021_func_021AA6F8.c..ov021_func_021AB018.c: prototype of func_02012A38 differs between members (src/matched/ov/ov021_func_021AAABC.c); prototype of func_02012A38 differs between members (src/matched/ov/ov021_func_021AAB54.c); prototype of func_
- ov021_func_021AA6F8.c..ov021_func_021AAABC.c: prototype of func_021AAFA0 differs between members (src/matched/ov/ov021_func_021AA944.c); prototype of func_02012A38 differs between members (src/matched/ov/ov021_func_021AAABC.c)
- ov021_func_021AA7DC.c..ov021_func_021AAABC.c: prototype of func_021AAFA0 differs between members (src/matched/ov/ov021_func_021AA944.c); prototype of func_02012A38 differs between members (src/matched/ov/ov021_func_021AAABC.c)
- ov021_func_021AA900.c..ov021_func_021AAABC.c: prototype of func_02012A38 differs between members (src/matched/ov/ov021_func_021AAABC.c)
- ov021_func_021AAA4C.c..ov021_func_021AAABC.c: prototype of func_02012A38 differs between members (src/matched/ov/ov021_func_021AAABC.c)
- ov021_func_021AAAF0.c..ov021_func_021AB018.c: prototype of func_02012A38 differs between members (src/matched/ov/ov021_func_021AAB54.c); type struct Area differs between members (src/matched/ov/ov021_func_021AACD4.c); prototype of func_02082BCC d
- ov021_func_021AAAF0.c..ov021_func_021AABF4.c: prototype of func_02012A38 differs between members (src/matched/ov/ov021_func_021AAB54.c)
- ov021_func_021AAAF0.c..ov021_func_021AAB54.c: prototype of func_02012A38 differs between members (src/matched/ov/ov021_func_021AAB54.c)
- ov021_func_021AACD4.c..ov021_func_021AB018.c: type typedef T differs between members (src/matched/ov/ov021_func_021AAFA0.c)
- ov021_func_021AACD4.c..ov021_func_021AAF54.c: c99=CCERR: line 250: illegal implicit conversion from 'struct  *' to | line 250: 'struct Self_021AAEC0 *' | line 302: illegal implicit conversion from 'struct Self_021AAF54 *' to nolang=CCERR: line 25
- ov021_func_021AAEC0.c..ov021_func_021AAF54.c: c99=CCERR: line 111: illegal implicit conversion from 'struct Self_021AAF54 *' to | line 111: 'struct Self_021AAEC0 *' nolang=CCERR: line 111: illegal implicit conversion from 'struct Self_021AAF54 *'
- ov021_func_021AAFA0.c..ov021_func_021AB018.c: c99=CCERR: line 83: illegal implicit conversion from 'struct D_021AAFA0 *' to | line 83: 'struct  *' nolang=CCERR: line 83: illegal implicit conversion from 'struct D_021AAFA0 *' to | line 83: 'struct
- func_021AB29C.c..ov021_func_021AC760.c: prototype of func_02030734 differs between members (src/matched/ov/ov021_func_021AB7E4.c); prototype of func_020307B0 differs between members (src/matched/ov/ov021_func_021AB81C.c); prototype of func_
- func_021AB29C.c..func_021ABBF0.c: prototype of func_02030734 differs between members (src/matched/ov/ov021_func_021AB7E4.c); prototype of func_020307B0 differs between members (src/matched/ov/ov021_func_021AB81C.c); prototype of func_
- func_021AB29C.c..sub_021AB4EC.c: c99=DIFF nolang=DIFF
- func_021AB29C.c..func_021AB37C.c: c99=DIFF nolang=DIFF
- func_021AB29C.c..func_021AB310.c: c99=DIFF nolang=DIFF
- func_021AB2E8.c..func_021AB310.c: c99=DIFF nolang=DIFF
- func_021AB390.c..sub_021AB4EC.c: c99=DIFF nolang=DIFF
- func_021AB390.c..sub_021AB410.c: c99=DIFF nolang=DIFF
- sub_021AB3EC.c..sub_021AB410.c: c99=DIFF nolang=DIFF
- unit_021AB404.c..sub_021AB410.c: c99=DIFF nolang=DIFF
- sub_021AB41C.c..sub_021AB4EC.c: c99=DIFF nolang=DIFF
- sub_021AB44C.c..sub_021AB4EC.c: c99=DIFF nolang=DIFF
- sub_021AB4F8.c..func_021ABBF0.c: prototype of func_02030734 differs between members (src/matched/ov/ov021_func_021AB7E4.c); prototype of func_020307B0 differs between members (src/matched/ov/ov021_func_021AB81C.c); prototype of func_
- sub_021AB4F8.c..ov021_func_021AB7C0.c: c99=CCERR: line 233: illegal implicit conversion from 'unsigned char *' to | line 233: 'struct  *' | line 240: illegal implicit conversion from 'struct  *' to nolang=CCERR: line 233: illegal implicit 
- sub_021AB4F8.c..ov021_func_021AB650.c: c99=CCERR: line 171: illegal implicit conversion from 'unsigned char *' to | line 171: 'struct  *' | line 178: illegal implicit conversion from 'struct  *' to nolang=CCERR: line 171: illegal implicit 
- ov021_func_021AB5F4.c..ov021_func_021AB650.c: c99=CCERR: line 75: illegal implicit conversion from 'unsigned char *' to | line 75: 'struct  *' | line 82: illegal implicit conversion from 'struct  *' to nolang=CCERR: line 75: illegal implicit conv
- ov021_func_021AB660.c..ov021_func_021AB7C0.c: type typedef S differs between members (src/matched/ov/ov021_func_021AB7C0.c)
- ov021_func_021AB7E4.c..func_021ABBF0.c: prototype of func_0207CA00 differs between members (src/matched/ov/ov021_func_021AB908.c); prototype of func_0207CCA4 differs between members (src/matched/ov/ov021_func_021AB908.c); prototype of func_
- ov021_func_021AB7E4.c..ov021_func_021AB890.c: c99=CCERR: line 99: illegal implicit conversion from 'struct  *' to | line 99: 'struct  *' nolang=CCERR: line 99: illegal implicit conversion from 'struct  *' to | line 99: 'struct  *'
- ov021_func_021AB7E4.c..ov021_func_021AB868.c: c99=CCERR: line 77: illegal implicit conversion from 'struct  *' to | line 77: 'struct  *' nolang=CCERR: line 77: illegal implicit conversion from 'struct  *' to | line 77: 'struct  *'
- ov021_func_021AB908.c..func_021ABBF0.c: prototype of func_0218EC90 differs between members (src/matched/ov/ov021_func_021AB9FC.c); prototype of func_0218ECF4 differs between members (src/matched/ov/ov021_func_021AB9FC.c)
- ov021_func_021AB908.c..ov021_func_021ABABC.c: prototype of func_0218EC90 differs between members (src/matched/ov/ov021_func_021AB9FC.c); prototype of func_0218ECF4 differs between members (src/matched/ov/ov021_func_021AB9FC.c)
- ov021_func_021AB908.c..ov021_func_021AB9FC.c: prototype of func_0218EC90 differs between members (src/matched/ov/ov021_func_021AB9FC.c); prototype of func_0218ECF4 differs between members (src/matched/ov/ov021_func_021AB9FC.c)
- func_021ABC14.c..ov021_func_021AC760.c: prototype of func_021ABBA0 differs between members (src/matched/ov/ov021_func_021ABD08.c); type typedef f4 differs between members (src/matched/ov/ov021_func_021ABE64.c); type typedef f4 differs betwe
- func_021ABC14.c..ov021_func_021AC140.c: prototype of func_021ABBA0 differs between members (src/matched/ov/ov021_func_021ABD08.c); type typedef f4 differs between members (src/matched/ov/ov021_func_021ABE64.c); type typedef f4 differs betwe
- func_021ABC14.c..func_021ABE8C.c: prototype of func_021ABBA0 differs between members (src/matched/ov/ov021_func_021ABD08.c); type struct T differs between members (src/matched/ov/ov021_func_021ABE64.c); prototype of func_021ABF2C diff
- func_021ABC14.c..func_021ABE0C.c: prototype of func_021ABBA0 differs between members (src/matched/ov/ov021_func_021ABD08.c)
- func_021ABC14.c..ov021_func_021ABD08.c: prototype of func_021ABBA0 differs between members (src/matched/ov/ov021_func_021ABD08.c)
- ov021_func_021ABC5C.c..ov021_func_021ABD08.c: prototype of func_021ABBA0 differs between members (src/matched/ov/ov021_func_021ABD08.c)
- func_021ABE14.c..func_021ABE8C.c: type struct T differs between members (src/matched/ov/ov021_func_021ABE64.c); prototype of func_021ABF2C differs between members (src/matched/ov/ov021_func_021ABE64.c); prototype of func_021ABF2C diff
- func_021ABE2C.c..func_021ABE8C.c: type struct T differs between members (src/matched/ov/ov021_func_021ABE64.c); prototype of func_021ABF2C differs between members (src/matched/ov/ov021_func_021ABE64.c); prototype of func_021ABF2C diff
- func_021ABEA0.c..ov021_func_021AC140.c: type typedef f4 differs between members (src/matched/ov/ov021_func_021ABF2C.c); type typedef f4 differs between members (src/matched/ov/ov021_func_021ABF48.c); type typedef ObjCb differs between membe
- func_021ABEA0.c..ov021_func_021ABFC0.c: type typedef f4 differs between members (src/matched/ov/ov021_func_021ABF2C.c); type typedef f4 differs between members (src/matched/ov/ov021_func_021ABF48.c)
- func_021ABEA0.c..ov021_func_021ABF2C.c: type struct T differs between members (src/matched/ov/ov021_func_021ABF2C.c)
- ov021_func_021ABEE8.c..ov021_func_021ABF2C.c: c99=CCERR: line 47: identifier 'T' redeclared | line 47: was declared as: 'struct ' | line 47: now declared as: 'struct T' nolang=CCERR: line 47: identifier 'T' redeclared | line 47: was declared as: 
- ov021_func_021ABFDC.c..ov021_func_021AC140.c: type typedef ObjCb differs between members (src/matched/ov/ov021_func_021AC0A0.c); type typedef ObjCb differs between members (src/matched/ov/ov021_func_021AC140.c)
- ov021_func_021AC074.c..ov021_func_021AC140.c: type typedef ObjCb differs between members (src/matched/ov/ov021_func_021AC0A0.c); type typedef ObjCb differs between members (src/matched/ov/ov021_func_021AC140.c)
- ov021_func_021AC154.c..ov021_func_021AC760.c: type typedef Vec3 differs between members (src/matched/ov/ov021_func_021AC528.c); prototype of func_021ABFA8 differs between members (src/matched/ov/ov021_func_021AC528.c); type typedef Vec3 differs b
- ov021_func_021AC154.c..ov021_func_021AC2F0.c: c99=CCERR: line 307: illegal implicit conversion from 'unsigned int' to | line 307: 'struct Obj *' | line 312: illegal implicit conversion from 'unsigned int' to nolang=CCERR: line 307: illegal implic
- ov021_func_021AC384.c..ov021_func_021AC760.c: type typedef Vec3 differs between members (src/matched/ov/ov021_func_021AC528.c); type typedef Vec3 differs between members (src/matched/ov/ov021_func_021AC578.c); prototype of func_021ABFA8 differs b
- ov021_func_021AC578.c..ov021_func_021AC760.c: prototype of func_021ABFA8 differs between members (src/matched/ov/ov021_func_021AC760.c)
- ov021_func_021AC578.c..ov021_func_021AC68C.c: c99=DIFF nolang=DIFF
- ov021_func_021AC66C.c..ov021_func_021AC68C.c: c99=DIFF nolang=DIFF

Members, in address order:

- `ov021_func_021A8EEC.c`
- `ov021_func_021A8FFC.c`
- `ov021_func_021A99A8.c`
- `ov021_func_021A99E4.c`
- `ov021_func_021AA180.c`
- `ov021_func_021AA248.c`
- `ov021_func_021AAA4C.c`
- `ov021_func_021AAABC.c`
- `ov021_func_021AAEC0.c`
- `ov021_func_021AAF54.c`
- `unit_021AB404.c`
- `sub_021AB410.c`
- `ov021_func_021AB908.c`
- `ov021_func_021AB9FC.c`
- `ov021_func_021ABC5C.c`
- `ov021_func_021ABD08.c`
- `ov021_func_021ABEE8.c`
- `ov021_func_021ABF2C.c`
- `ov021_func_021AC66C.c`
- `ov021_func_021AC68C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names field_effect.c` again.

- `func_021A8E14.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.
