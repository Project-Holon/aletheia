# app_taskmenu (arm9)

Translation unit 020263B0..02028844, 193 functions, confidence weak (tools/tuboundary.py).

Eight parts are left (`app_taskmenu_p01.c` .. `app_taskmenu_p08.c`, address order). The
unit started as 56 files. What was unified: `g_02146940`/`g_GameBeacon` now share one
`struct BeaconSys` (own record `Inner`, `BeaconSlot slot[30]`, mask at 0xBA4), one
`struct Req`, one `struct TaskMenu`/`TaskMenuTmpl`, one `struct Ctx`, one `struct Cfg`/`Src`,
`func_02027B30` returns `u32` everywhere, `func_02166C7C` is unprototyped (two call shapes).

Boundaries still blocked (each part verifies on its own):

- p01|p02: c99=DIFF. The merged range loses the outside witness of `d_0209FCF8` and
  `d_0209FCEC` (data referenced only inside the range), and 934 bytes differ.
- p02|p03: c99=DIFF. Merged code is 4 bytes longer before `func_02027D44`; every later call
  displacement moves (1567 bytes differ).
- p03|p04: `func_02028084(struct Cfg *, struct Src *, u16 a2, u16 a3, u8, u8, u32, u32, u16)`
  has narrow parameters; the callers in p03 (`func_0202800C`, `func_0202804C`) pass full
  `u32` values and the bytes match only without the typed prototype (an unprototyped
  declaration is not accepted once the definition is in the same file).
- p04|p05: c99=DIFF (196 bytes): `func_02028164` is reached by a different pool/branch
  shape inside one file.
- p05|p06: `func_0202822E` is the `bx lr` at +2 of `func_0202822C` (a second entry inside
  the previous function), so it cannot be a separate function of a merged file.
- p06|p07 and p07|p08: c99=DIFF. `g_0209FD10` has no witness outside the merged range.

`struct Obj` is still defined differently in several parts (the task menu object in p03,
the cfg object `CfgObj` in p04); `d_02146940` (p01) and `g_GameBeacon` stay separate symbols
for the same address because their pool words do not fold.

- `func_020275DC.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.

- `func_020275E0.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.

- `func_02027A20.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.

- `func_0202815C.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.
