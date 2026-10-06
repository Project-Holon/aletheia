# wipe_sub (arm9)

Translation unit 02021728..02025318, 193 functions, confidence weak (tools/tuboundary.py).
All 21 parts below are byte-exact (compiler 1.1p1, thumb, c99). Neighbouring parts do not merge:

- `arm9\wipe_sub_p01.c`: func_02021728..func_02021F64 (22 functions)
- `arm9\wipe_sub_p02.c`: func_02021FD8..func_02021FD8 (1 functions)
- `arm9\wipe_sub_p03.c`: func_02022004..func_0202208C (3 functions)
- `arm9\wipe_sub_p04.c`: func_02022174..func_020222CC (9 functions)
- `arm9\wipe_sub_p05.c`: func_020222EC..func_02022490 (10 functions)
- `arm9\wipe_sub_p06.c`: func_020224DC..func_020225B4 (4 functions)
- `arm9\wipe_sub_p07.c`: func_020225D4..func_020225D4 (1 functions)
- `arm9\wipe_sub_p08.c`: func_020225F0..func_02022758 (11 functions)
- `arm9\wipe_sub_p09.c`: func_02022790..func_02022DCC (22 functions)
- `arm9\wipe_sub_p10.c`: func_02022E20..func_020234C0 (10 functions)
- `arm9\wipe_sub_p11.c`: func_0202350C..func_020237B8 (7 functions)
- `arm9\wipe_sub_p12.c`: func_0202384C..func_0202390C (3 functions)
- `arm9\wipe_sub_p13.c`: func_02023964..func_02023E9C (19 functions)
- `arm9\wipe_sub_p14.c`: func_02023EF4..func_02024044 (6 functions)
- `arm9\wipe_sub_p15.c`: func_0202411C..func_020241E0 (14 functions)
- `arm9\wipe_sub_p16.c`: func_02024224..func_0202441C (10 functions)
- `arm9\wipe_sub_p17.c`: func_02024464..func_020244D4 (3 functions)
- `arm9\wipe_sub_p18.c`: func_020244F8..func_020247A8 (17 functions)
- `arm9\wipe_sub_p19.c`: func_020247F0..func_02024ABC (15 functions)
- `arm9\wipe_sub_p20.c`: func_02024DCC..func_02024DFC (2 functions)
- `arm9\wipe_sub_p21.c`: func_02025154..func_020252A8 (4 functions)

Why each boundary stays (checked by merging the two neighbours):

- p01|p02: func_02021F64 takes `struct Rgb555 color` by value in p01 and `u16 color` in p02's call; making the call pass a struct changes the bytes (DIFF).
- p02|p03: p03 calls func_02021FD8 with six `u32`; the definition in p02 takes `struct Chan02021FD8 *, ..., u8, u16`; typing the call narrows the arguments and changes the bytes (DIFF).
- p03|p04, p04|p05, p05|p06: global g_021467A4 / g_021468A4 viewed through different local structs (G, Sub, ...) with different field names at one offset. Needs the struct pass.
- p06|p07, p07|p08: p07 and p08 start with a machine-style stand-in (`int f(int a0, ...)`) that calls neighbours through implicit `int`; the callees take `struct Slots *` / `struct Node *`.
- p08|p09, p09|p10, p10|p11, p11|p12, p12|p13: the same objects (Task, Obj, Wipe, Interp) are described by a different local struct in each member (`Task_020229A4`, `Task_02022A44`, ...), so calls between members do not type-check. Needs one struct per object (struct pass).
- p13|p14 (func_02023E9C), p14|p15, p15|p16, p16|p17, p17|p18, p19|p20: the merged file compiles but gives DIFF, or the callee prototypes differ in arity/meaning (func_02045B38, func_02023E9C).
- p20|p21, p21|p22: implicit `int` call into a `void *` parameter; gInfoWin viewed through two InfoWin structs.

p18 and p19 were merged (sub_02024508 call order needed a prototype that
tools/restructure.py dropped because split_items() mis-parses a function whose
last parameter is `struct X *`; see below).

Tool note: in tools/restructure.py split_items(), the test
`re.search(r'(struct|union|enum)[^(]*$', head)` treats any function whose
parameter list ends in a `struct` type as a struct definition, so such a
function is fused with the next item and its prototype is lost. Use
`[^()]*$` there.

- `func_020240FC.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.

- `func_02024104.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.

- `func_02024108.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.

- `func_0202421C.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.

- `func_02024450.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.

- `sub_020244F0.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.
