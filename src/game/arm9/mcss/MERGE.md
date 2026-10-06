# mcss (arm9)

Translation unit 02014910..02019A50, confidence weak (tools/tuboundary.py).

Merged so far: 14 parts `mcss_p01.c`..`mcss_p14.c` (address order), all verified.
Three members stay separate here: `func_020155A0.c`, `func_020180FC.c`, `sub_02019388.c`.

Boundaries that do not merge (checked one by one):

- p01|p02, p03|p04, p04|p05 (shared-literal / code differences): merging gives c99=DIFF.
- p02|func_020155A0: after fixing the doubled G3_Translate/G3_Scale and the struct views of
  McssSys/McssWork, the merge still gives DIFF (func_020155A0 compiles with other registers).
- p05|p06: the same object (size 0x2C, func_0201691C and func_020163C4) has two different
  local struct views (Obj_0201691C); needs the struct pass.
- p07|p08: DIFF.
- p08|p09 (func_020173F0): the caller in p09 passes the last argument as u32 (no narrowing),
  the definition takes u16; needs one prototype (struct pass / prototype pass).
- p09|p10: Sav_0201747C vs Sav_02017CC8 views and func_02017D30 / func_02017D70 prototypes.
- p10|p11, p11|p12 (func_02019C54, void * result vs u32 result with u16 argument): DIFF
  when the prototype is unified.
- p12|func_020180FC, func_020180FC|p13, p13|p14: declaration syntax errors from the
  members' own macros; func_02018E34 and func_02019388 use two Mon struct views.

- `func_02014CEC.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.

- `func_02015D80.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.

- `func_020160C0.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.

- `sub_020173C8.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.

- `func_020189D0.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.
