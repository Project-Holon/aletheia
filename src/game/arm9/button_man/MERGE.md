# button_man.c (arm9)

Translation unit 02051788..020584E0, 87 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`button_man.c` is blocked by:

- func_02051788.c..unit_0205841C.c: settings differ: src/matched/arm9/func_020524C8.c has {'compiler': '../1.2/sp2', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'is
- func_02051788.c..func_020528D0.c: settings differ: src/matched/arm9/func_020524C8.c has {'compiler': '../1.2/sp2', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'is
- func_02051788.c..func_02051C6C.c: c99=DIFF nolang=DIFF
- func_02051788.c..func_02051A24.c: c99=DIFF nolang=DIFF
- func_02051788.c..func_020518A4.c: c99=DIFF nolang=DIFF
- func_02051788.c..func_02051838.c: c99=DIFF nolang=DIFF
- func_02051C88.c..func_020528D0.c: settings differ: src/matched/arm9/func_020524C8.c has {'compiler': '../1.2/sp2', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'is
- func_02052274.c..func_020528D0.c: settings differ: src/matched/arm9/func_020524C8.c has {'compiler': '../1.2/sp2', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'is
- func_02052274.c..func_020525A0.c: settings differ: src/matched/arm9/func_020524C8.c has {'compiler': '../1.2/sp2', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'is
- func_02052634.c..func_020528D0.c: prototype of func_020583CC differs between members (src/matched/arm9/func_02052770.c)
- func_02052634.c..func_02052770.c: prototype of func_020583CC differs between members (src/matched/arm9/func_02052770.c)
- func_020526A8.c..func_02052770.c: c99=DIFF nolang=DIFF
- func_020528A8.c..func_020528D0.c: c99=CCERR: line 65: identifier 'func_020528D0(unsigned int, void *)' redeclared | line 65: was declared as: 'void (unsigned int, void *)' | line 65: now declared as: 'int (struct Obj *, unsigned int (
- func_02052984.c..unit_0205841C.c: settings differ: src/matched/arm9/func_02053D2C.c has {'compiler': '1.1p1', 'flags': '-O4,p -proc arm7tdmi', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '../1.2/sp2', 'flags': '-O4,p', 'la
- func_02052984.c..func_02056460.c: settings differ: src/matched/arm9/func_02053D2C.c has {'compiler': '1.1p1', 'flags': '-O4,p -proc arm7tdmi', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '../1.2/sp2', 'flags': '-O4,p', 'la
- func_02052984.c..func_02053A60.c: type typedef Fn differs between members (src/matched/arm9/func_0205312C.c)
- func_02052984.c..func_02052F90.c: c99=DIFF nolang=DIFF
- func_02052984.c..func_02052A50.c: c99=DIFF nolang=DIFF
- func_02052FC8.c..func_02053A60.c: type typedef Fn differs between members (src/matched/arm9/func_0205312C.c)
- func_0205312C.c..func_02053A60.c: c99=CCERR: line 353: undefined identifier 'SPL_TEX_ANIM_MAX_FRAMES' | line 360: empty array must be last class/struct member | line 781: undefined identifier 'reg_G3_POLYGON_ATTR' nolang=CCERR: line 3
- func_02053218.c..func_02053A60.c: c99=CCERR: line 310: undefined identifier 'SPL_TEX_ANIM_MAX_FRAMES' | line 317: empty array must be last class/struct member | line 687: undefined identifier 'reg_G3_POLYGON_ATTR' nolang=CCERR: line 3
- func_02053D2C.c..func_02056460.c: settings differ: src/matched/arm9/func_02053D30.c has {'compiler': '../1.2/sp2', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p -proc arm7tdmi', 'la
- func_02053D2C.c..func_02054718.c: settings differ: src/matched/arm9/func_02053D30.c has {'compiler': '../1.2/sp2', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p -proc arm7tdmi', 'la
- func_02053D2C.c..func_02053D30.c: settings differ: src/matched/arm9/func_02053D30.c has {'compiler': '../1.2/sp2', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p -proc arm7tdmi', 'la
- func_02053E1C.c..func_02054718.c: type struct SubX differs between members (src/matched/arm9/func_0205429C.c); type struct Obj differs between members (src/matched/arm9/func_0205429C.c); type struct SubX differs between members (src/m
- func_0205429C.c..func_02054718.c: type struct SubX differs between members (src/matched/arm9/func_02054718.c); type struct Obj differs between members (src/matched/arm9/func_02054718.c)
- func_02054A68.c..func_02056460.c: type struct SubC differs between members (src/matched/arm9/func_02055B80.c); type struct Obj differs between members (src/matched/arm9/func_02055B80.c); type struct SubC differs between members (src/m
- func_02054A68.c..func_02055498.c: c99=CCERR: line 401: undefined identifier 'SPL_TEX_ANIM_MAX_FRAMES' | line 408: empty array must be last class/struct member | line 741: undefined identifier 'reg_G3_POLYGON_ATTR' nolang=CCERR: line 4
- func_02054DB8.c..func_02055498.c: c99=CCERR: line 299: undefined identifier 'SPL_TEX_ANIM_MAX_FRAMES' | line 306: empty array must be last class/struct member | line 548: undefined identifier 'reg_G3_POLYGON_ATTR' nolang=CCERR: line 2
- func_02055B80.c..func_02056460.c: c99=DIFF nolang=DIFF
- func_02055FD4.c..func_02056460.c: c99=DIFF nolang=DIFF
- func_0205650C.c..unit_0205841C.c: settings differ: src/matched/arm9/func_02058300.c has {'compiler': '1.1p1', 'flags': '-O4,p -proc arm7tdmi', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '../1.2/sp2', 'flags': '-O4,p', 'la
- func_0205650C.c..func_02057C9C.c: type typedef fx16 differs between members (src/matched/arm9/func_020565C8.c); type typedef fx16 differs between members (src/matched/arm9/func_020569A4.c); type struct VecFx32 differs between members 
- func_0205650C.c..func_020576D0.c: type typedef fx16 differs between members (src/matched/arm9/func_020565C8.c); type typedef fx16 differs between members (src/matched/arm9/func_020569A4.c); type struct VecFx32 differs between members 
- func_0205650C.c..func_020565C8.c: c99=CCERR: line 33: undefined identifier 'reg_G3_END_VTXS' | line 37: undefined identifier 'reg_G3_TEXCOORD' | line 42: undefined identifier 'reg_G3_VTX_10' nolang=CCERR: line 33: undefined identifier
- func_02056684.c..func_020576D0.c: type struct VecFx32 differs between members (src/matched/arm9/func_020576D0.c)
- func_020569A4.c..func_020576D0.c: c99=CCERR: line 294: undefined identifier 'SPL_TEX_ANIM_MAX_FRAMES' | line 301: empty array must be last class/struct member | line 528: undefined identifier 'FX32_SHIFT' nolang=CCERR: line 294: undef
- func_02057830.c..func_02057C9C.c: c99=DIFF nolang=DIFF
- func_02057830.c..func_02057B10.c: c99=DIFF nolang=DIFF
- func_02057AB8.c..func_02057B10.c: c99=DIFF nolang=DIFF
- func_02057B5C.c..func_02057C9C.c: c99=DIFF nolang=DIFF
- func_02057BC0.c..func_02057C9C.c: c99=DIFF nolang=DIFF
- func_02057E68.c..unit_0205841C.c: settings differ: src/matched/arm9/func_02058300.c has {'compiler': '1.1p1', 'flags': '-O4,p -proc arm7tdmi', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '../1.2/sp2', 'flags': '-O4,p', 'la
- func_02057E68.c..func_02058180.c: c99=DIFF nolang=DIFF
- func_02057E68.c..func_02057EF8.c: c99=DIFF nolang=DIFF
- func_02057F8C.c..func_02058180.c: c99=DIFF nolang=DIFF
- func_020580A8.c..func_02058180.c: c99=DIFF nolang=DIFF
- func_02058204.c..unit_0205841C.c: settings differ: src/matched/arm9/func_02058300.c has {'compiler': '1.1p1', 'flags': '-O4,p -proc arm7tdmi', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '../1.2/sp2', 'flags': '-O4,p', 'la
- func_02058204.c..func_02058300.c: settings differ: src/matched/arm9/func_02058300.c has {'compiler': '1.1p1', 'flags': '-O4,p -proc arm7tdmi', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '../1.2/sp2', 'flags': '-O4,p', 'la
- func_020582CC.c..func_02058300.c: settings differ: src/matched/arm9/func_02058300.c has {'compiler': '1.1p1', 'flags': '-O4,p -proc arm7tdmi', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '../1.2/sp2', 'flags': '-O4,p', 'la
- func_02058380.c..unit_0205841C.c: settings differ: src/matched/arm9/func_020583CC.c has {'compiler': '../1.2/sp2', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'is
- func_020583CC.c..unit_0205841C.c: settings differ: src/matched/arm9/unit_0205841C.c has {'compiler': '1.1p1', 'flags': '-O4,p -proc arm7tdmi', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '../1.2/sp2', 'flags': '-O4,p', 'la

Members, in address order:

- `func_02051788.c`
- `func_02051838.c`
- `func_02052634.c`
- `func_020526A8.c`
- `func_02052770.c`
- `func_020528A8.c`
- `func_02052984.c`
- `func_02052A50.c`
- `func_0205312C.c`
- `func_02053218.c`
- `func_02053A60.c`
- `func_02053D2C.c`
- `func_02053D30.c`
- `func_02053E1C.c`
- `func_0205429C.c`
- `func_02054718.c`
- `func_02054A68.c`
- `func_02054DB8.c`
- `func_02055498.c`
- `func_02055B80.c`
- `func_02055FD4.c`
- `func_02056460.c`
- `func_0205650C.c`
- `func_020565C8.c`
- `func_02056684.c`
- `func_020569A4.c`
- `func_020576D0.c`
- `func_02057830.c`
- `func_02057AB8.c`
- `func_02057B10.c`
- `func_02057B5C.c`
- `func_02057BC0.c`
- `func_02057C9C.c`
- `func_02057E68.c`
- `func_02057EF8.c`
- `func_02057F8C.c`
- `func_020580A8.c`
- `func_02058180.c`
- `func_02058204.c`
- `func_020582CC.c`
- `func_02058300.c`
- `func_02058380.c`
- `func_020583CC.c`
- `unit_0205841C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names button_man.c` again.

- `func_02051790.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.

- `func_020517A4.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.

- `func_020517B4.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.

- `func_020517D0.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.

- `func_020517D8.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.

- `func_020517E0.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.

- `func_020517E8.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.

- `func_020517F0.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.

- `func_02051800.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.

- `func_02051808.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.

- `func_02051818.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.

- `func_02051820.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.

- `func_02051830.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.
