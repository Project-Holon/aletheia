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

Round 18 (lane L16), merge of all three parts studied:

- Static data order in mwcc (measured): file-scope statics are emitted in groups. A group is the statics defined
  between two function bodies. Inside a group the emission order is the reverse of the definition order, except that the
  last one defined stays last (defs frame, table_no, cam, mp, power give mp, cam, table_no, frame, power). A function
  static is emitted at its function. So the image order mp, cam, table_no, frame, power, game, ggid, mask is reached with
  defs `frame, table_no, cam, mp, power` at the top, then `game, ggid, mask` (in that order) just before
  MBi_ChildCallback. With that, every function from ParentCallback on is EXACT except MB_Init (9 bytes) and the
  `.data` anchor is shared (one pool word) in ParentCallback and ChildCallback.
- A static that is only declared early (`static u32 x;`) and initialised after MB_Init is not in `.data` at its first
  use, so its uses load a separate pool word. Definitions with initialisers must come before the first use.
- Last blocker, measured with `mwccdbg alias`: `game` must be a function static of MB_Init. A file-scope static is in
  the unknown-memory alias set G, so `str game` and `strh [c]` get a dependence and the scheduler keeps `str` before
  `add i` (9 bytes, the pair swaps). A function static is not in G, which is what the image shows. But a function static
  is emitted at MB_Init, after the file-scope `ggid`/`mask` that ChildCallback needs defined (and in `.data`) earlier.
  Both constraints cannot hold with the group rule above. Needs a way to have `game` flushed before ChildCallback while
  staying a function static of MB_Init, or ggid/mask known to ChildCallback without being defined before it.
