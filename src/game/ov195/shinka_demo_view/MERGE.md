# shinka_demo_view.c (ov195)

Translation unit 022058F8..02208C30, 105 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`shinka_demo_view.c` is blocked by:

- ov195_func_022058F8.c..ov195_func_02208C28.c: global d_02208D1C declared two ways (src/matched/ov/ov195_func_02205A84.c); global d_02208D1C declared two ways (src/matched/ov/ov195_func_02205B24.c); type typedef VecFx32 differs between members (sr
- ov195_func_022058F8.c..ov195_func_02206768.c: global d_02208D1C declared two ways (src/matched/ov/ov195_func_02205A84.c); global d_02208D1C declared two ways (src/matched/ov/ov195_func_02205B24.c); type typedef VecFx32 differs between members (sr
- ov195_func_022058F8.c..ov195_func_0220602C.c: global d_02208D1C declared two ways (src/matched/ov/ov195_func_02205A84.c); global d_02208D1C declared two ways (src/matched/ov/ov195_func_02205B24.c)
- ov195_func_022058F8.c..ov195_func_02205B64.c: global d_02208D1C declared two ways (src/matched/ov/ov195_func_02205A84.c); global d_02208D1C declared two ways (src/matched/ov/ov195_func_02205B24.c)
- ov195_func_02205A34.c..ov195_func_02205B64.c: global d_02208D1C declared two ways (src/matched/ov/ov195_func_02205A84.c); global d_02208D1C declared two ways (src/matched/ov/ov195_func_02205B24.c)
- ov195_func_02205A34.c..ov195_func_02205AAC.c: global d_02208D1C declared two ways (src/matched/ov/ov195_func_02205A84.c)
- ov195_func_02206044.c..ov195_func_02206768.c: type typedef VecFx32 differs between members (src/matched/ov/ov195_func_02206274.c); type typedef VecFx32 differs between members (src/matched/ov/ov195_func_022063E0.c); type typedef VecFx32 differs b
- ov195_func_02206108.c..ov195_func_02206768.c: c99=CCERR: line 330: illegal implicit conversion from 'struct Owner_02206108 *' to | line 330: 'struct Owner_02206274 *' nolang=CCERR: line 330: illegal implicit conversion from 'struct Owner_02206108
- ov195_func_02206108.c..ov195_func_022063E0.c: c99=CCERR: line 208: illegal implicit conversion from 'struct Owner_02206108 *' to | line 208: 'struct Owner_02206274 *' nolang=CCERR: line 208: illegal implicit conversion from 'struct Owner_02206108
- ov195_func_022067B0.c..ov195_func_02208C28.c: type typedef fx16 differs between members (src/matched/ov/ov195_func_022076A0.c); type typedef Row differs between members (src/matched/ov/ov195_func_022076A0.c); type typedef Owner differs between me
- ov195_func_022067B0.c..ov195_func_022086BC.c: type typedef fx16 differs between members (src/matched/ov/ov195_func_022076A0.c); type typedef Row differs between members (src/matched/ov/ov195_func_022076A0.c); type typedef Owner differs between me
- ov195_func_022067B0.c..ov195_func_0220826C.c: type typedef fx16 differs between members (src/matched/ov/ov195_func_022076A0.c); type typedef Row differs between members (src/matched/ov/ov195_func_022076A0.c); type typedef Owner differs between me
- ov195_func_02206A5C.c..ov195_func_0220826C.c: type typedef fx16 differs between members (src/matched/ov/ov195_func_022076A0.c); type typedef Row differs between members (src/matched/ov/ov195_func_022076A0.c); type typedef Fade differs between mem
- ov195_func_02206A5C.c..ov195_func_02207510.c: c99=CCERR: line 163: illegal implicit conversion from 'struct Grid_02206A5C *' to | line 163: 'struct Grid_02206E2C *' nolang=CCERR: line 163: illegal implicit conversion from 'struct Grid_02206A5C *'
- ov195_func_0220827C.c..ov195_func_022086BC.c: c99=CCERR: line 181: illegal implicit conversion from 'struct Fade_0220827C *' to | line 181: 'struct Fade_022082DC *' | line 269: illegal implicit conversion from 'struct Fade_02208430 *' to nolang=C
- ov195_func_0220827C.c..ov195_func_02208410.c: c99=CCERR: line 111: illegal implicit conversion from 'struct Fade_0220827C *' to | line 111: 'struct Fade_022082DC *' nolang=CCERR: line 111: illegal implicit conversion from 'struct Fade_0220827C *'
- ov195_func_0220827C.c..ov195_func_022083CC.c: c99=CCERR: line 91: illegal implicit conversion from 'struct Fade_0220827C *' to | line 91: 'struct Fade_022082DC *' nolang=CCERR: line 91: illegal implicit conversion from 'struct Fade_0220827C *' to
- ov195_func_022086C8.c..ov195_func_02208C28.c: c99=CCERR: line 323: illegal implicit conversion from 'struct Anim_0220871C *' to | line 323: 'struct Anim_02208AB0 *' | line 344: illegal implicit conversion from 'struct Anim_0220878C *' to nolang=C

Members, in address order:

- `ov195_func_02205A34.c`
- `ov195_func_02206A5C.c`
- `ov195_func_0220827C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names shinka_demo_view.c` again.
