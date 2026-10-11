# unit_021F4560.c (ov107)

Merged as far as the verifier and the compile allow. Remaining parts:

- `unit_021F4560_p01.c`: func_021F4560 .. func_021F4E9C (6 functions), MATCH
- `unit_021F4560_p02.c`: MBi_ChildCallback, MBi_GetBeaconPeriodDispersion (2 functions), MATCH
- `unit_021F4560_p03.c`: MB_Init .. MBi_CheckWmErrcode (19 functions, includes the tail stub func_021F5ED8), EXACT

MATCH (not EXACT) in p01 to p03 is the `.data` section-relative literal: the compiler
addresses the static words at 0x021F6E58 as `.data` + offset, and a section-relative
relocation in an overlay cannot be given an independent witness.

Blockers:

- p01|p02: the original MBi_ChildCallback reaches mbi_reject_ggid (+0x10) and
  mbi_reject_ggid_mask (+0x14) through the `.data` anchor, so both words must be
  defined (with initialisers) before ChildCallback. The image layout is mp, cam,
  table_no, frame, power, game, ggid, mask. `game` is a function static of MB_Init
  and only compiles like the original (value kept in a register across the copy loop)
  as a function static, which puts it last in the layout. A file-scope `game` gives
  the right layout but a different MB_Init. The whole TU therefore differs only in
  ChildCallback. p02 defines its own block (MB_WM_OWN_STATICS in mb_wm.h) with a
  stand-in `mbi_game` so the offsets are right.
- p03|p04: closed. The 12 bytes at 0x021F5ED8 (`ldr ip, [pc]; bx ip; .word 0x021F5EA0`) are a compiler tail call, `int func_021F5ED8(void) { return MBi_CallReset(); }`, and p04 shares p03's statics block (MB_WM_OWN_STATICS before the include).

Shared rule: the part files must stay separate where a data label only has witnesses in the other part.
