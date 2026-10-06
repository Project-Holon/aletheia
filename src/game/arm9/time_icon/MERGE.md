# time_icon.c (arm9)

Translation unit 0202E4EC..0202FAB0, 78 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`time_icon.c` is blocked by:

- func_0202E4EC.c..func_0202F9F8.c: prototype of func_02082D44 differs between members (src/matched/arm9/func_0202E9AC.c); prototype of func_0200974C differs between members (src/matched/arm9/func_0202ED60.c); prototype of _u32_div_f di
- func_0202E4EC.c..func_0202ED00.c: prototype of func_02082D44 differs between members (src/matched/arm9/func_0202E9AC.c)
- func_0202E4EC.c..func_0202E8D8.c: c99=DIFF nolang=DIFF
- func_0202E7DC.c..func_0202E8D8.c: c99=DIFF nolang=DIFF
- func_0202E7DC.c..func_0202E818.c: c99=DIFF nolang=DIFF
- func_0202E7E4.c..func_0202E818.c: c99=DIFF nolang=DIFF
- func_0202E930.c..func_0202ED00.c: c99=CCERR: line 417: identifier 'func_0202EC44(struct Slot_0202EB9C *, unsigned int)' redeclared as 'unsigned int (struct Slot_0202EC44 *, unsigned int)' | line 197: identifier 'func_0202EC44(struct S
- func_0202EB44.c..func_0202ED00.c: c99=CCERR: line 198: identifier 'func_0202EC44(struct Slot_0202EB9C *, unsigned int)' redeclared as 'unsigned int (struct Slot_0202EC44 *, unsigned int)' | line 107: identifier 'func_0202EC44(struct S
- func_0202ED60.c..func_0202F9F8.c: prototype of _u32_div_f differs between members (src/matched/arm9/func_0202EE0C.c); global g_020A7814 declared two ways (src/matched/arm9/func_0202EF60.c); prototype of func_02030DA8 differs between m
- func_0202ED60.c..func_0202F2F4.c: prototype of _u32_div_f differs between members (src/matched/arm9/func_0202EE0C.c); global g_020A7814 declared two ways (src/matched/arm9/func_0202EF60.c); prototype of func_02030DA8 differs between m
- func_0202ED60.c..func_0202EF98.c: prototype of _u32_div_f differs between members (src/matched/arm9/func_0202EE0C.c); global g_020A7814 declared two ways (src/matched/arm9/func_0202EF60.c); prototype of func_02030DA8 differs between m
- func_0202EE30.c..func_0202EF98.c: global g_020A7814 declared two ways (src/matched/arm9/func_0202EF60.c); prototype of func_02030DA8 differs between members (src/matched/arm9/func_0202EF98.c)
- func_0202F038.c..func_0202F2F4.c: c99=DIFF nolang=DIFF
- func_0202F038.c..sub_0202F170.c: c99=DIFF nolang=DIFF
- func_0202F038.c..func_0202F0B0.c: c99=DIFF nolang=DIFF
- sub_0202F114.c..sub_0202F170.c: c99=DIFF nolang=DIFF
- sub_0202F138.c..sub_0202F170.c: c99=DIFF nolang=DIFF
- func_0202F30C.c..func_0202F9F8.c: prototype of func_0207E24C differs between members (src/matched/arm9/func_0202F940.c)
- func_0202F30C.c..func_0202F630.c: c99=CCERR: line 92: illegal implicit conversion from 'int' to | line 92: 'void *' | line 94: illegal implicit conversion from 'int' to nolang=CCERR: line 92: illegal implicit conversion from 'int' to 
- func_0202F30C.c..func_0202F41C.c: c99=CCERR: line 78: illegal implicit conversion from 'int' to | line 78: 'void *' nolang=CCERR: line 78: illegal implicit conversion from 'int' to | line 78: 'void *'
- func_0202F464.c..func_0202F630.c: c99=CCERR: line 38: illegal implicit conversion from 'int' to | line 38: 'void *' | line 46: function call 'func_020185F0()' does not match nolang=CCERR: line 38: illegal implicit conversion from 'int
- func_0202F464.c..func_0202F47C.c: c99=CCERR: line 24: illegal implicit conversion from 'int' to | line 24: 'void *' nolang=CCERR: line 24: illegal implicit conversion from 'int' to | line 24: 'void *'
- func_0202F488.c..func_0202F630.c: c99=CCERR: line 34: function call 'func_020185F0()' does not match | line 34: 'func_020185F0(unsigned int)' nolang=CCERR: line 34: function call 'func_020185F0()' does not match | line 34: 'func_02018
- func_0202F640.c..func_0202F9F8.c: prototype of func_0207E24C differs between members (src/matched/arm9/func_0202F940.c)
- func_0202F640.c..func_0202F788.c: c99=DIFF nolang=DIFF
- func_0202F640.c..func_0202F738.c: c99=DIFF nolang=DIFF
- func_0202F7C4.c..func_0202F9F8.c: prototype of func_0207E24C differs between members (src/matched/arm9/func_0202F940.c)

Status after the merge-lane pass (same-settings runs merged greedily; the blocker list above may include entries already resolved):

Parts: time_icon_p01.c, time_icon_p02.c, time_icon_p03.c, time_icon_p04.c, time_icon_p05.c, time_icon_p06.c, time_icon_p07.c, time_icon_p08.c, time_icon_p09.c, time_icon_p10.c, time_icon_p11.c

Members still separate:

- `func_0202F464.c`

- `func_0202E80C.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.

- `sub_0202F144.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.

- `func_0202F688.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.

- `func_0202F6D8.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.

- `func_0202F72C.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.
