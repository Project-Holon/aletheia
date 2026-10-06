# unit_0207312C.c (arm9)

Translation unit 0207312C..020737C0, 16 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_0207312C.c` is blocked by:

- func_0207312C.c..func_02073760.c: settings differ: src/matched/arm9/func_020731E0.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '../2.0/sp2', 'flags': '-O4,p', 'lang': 'c99', 'is
- func_0207312C.c..func_020734AC.c: settings differ: src/matched/arm9/func_020731E0.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '../2.0/sp2', 'flags': '-O4,p', 'lang': 'c99', 'is
- func_0207312C.c..func_020733DC.c: settings differ: src/matched/arm9/func_020731E0.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '../2.0/sp2', 'flags': '-O4,p', 'lang': 'c99', 'is
- func_0207312C.c..func_020731E0.c: settings differ: src/matched/arm9/func_020731E0.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '../2.0/sp2', 'flags': '-O4,p', 'lang': 'c99', 'is
- func_02073344.c..func_020733DC.c: settings differ: src/matched/arm9/func_020733DC.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '../2.0/sp2', 'flags': '-O4,p', 'lang': 'c99', 'is
- func_020733E8.c..func_020734AC.c: settings differ: src/matched/arm9/func_02073484.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '../2.0/sp2', 'flags': '-O4,p', 'lang': 'c99', 'is
- func_02073484.c..func_020734AC.c: settings differ: src/matched/arm9/func_020734AC.c has {'compiler': '../2.0/sp2', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'is
- func_02073500.c..func_02073760.c: settings differ: src/matched/arm9/func_02073598.c has {'compiler': '../2.0/sp2', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'is
- func_02073500.c..func_020735EC.c: settings differ: src/matched/arm9/func_02073598.c has {'compiler': '../2.0/sp2', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'is
- func_02073598.c..func_020735EC.c: settings differ: src/matched/arm9/func_020735EC.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '../2.0/sp2', 'flags': '-O4,p', 'lang': 'c99', 'is
- func_02073624.c..func_02073760.c: settings differ: src/matched/arm9/func_02073710.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '../2.0/sp2', 'flags': '-O4,p', 'lang': 'c99', 'is
- func_02073624.c..func_0207368C.c: c99=CCERR: line 62: struct/union/enum/class tag 'Voice' redefined | line 81: 'f00' is not a member of class 'struct Voice' | line 82: 'f00' is not a member of class 'struct Voice' nolang=CCERR: line 6
- func_02073710.c..func_02073760.c: c99=CCERR: line 35: warning: identifier 'u8' redeclared | line 35: warning: identifier 'u16' redeclared | line 35: warning: identifier 'u32' redeclared nolang=CCERR: line 35: warning: identifier 'u8' 

Members, in address order:

- `func_0207312C.c`
- `func_020731E0.c`
- `func_02073344.c`
- `func_020733DC.c`
- `func_02073484.c`
- `func_020734AC.c`
- `func_02073598.c`
- `func_020735EC.c`
- `func_02073624.c`
- `func_0207368C.c`
- `func_02073710.c`
- `func_02073760.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_0207312C.c` again.

Lane note (merge lane arm9_lane10):

The members alternate between two compilers by address: 1.1p1 (func_020731E0,
func_020733DC, func_02073484, func_020735EC, func_02073710, func_02073760 and
unit_0207312C_p02) and ../2.0/sp2 (func_0207312C, func_02073344, func_020734AC,
func_02073598, func_02073624, func_0207368C and unit_0207312C_p01). One
translation unit has one compiler, so this range is several translation units
whose boundaries tools/tuboundary.py did not see (confidence weak). It cannot
become one file. Next step: split the range at the compiler changes into units
that each use one compiler, then merge each unit separately.
