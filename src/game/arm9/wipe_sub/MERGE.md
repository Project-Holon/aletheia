# wipe_sub (arm9)

Translation unit 02021728..02025318, 9 parts, all byte-exact (compiler 1.1p1, thumb, c99).
Round 3 lane r3_a908: 28 files (21 parts + 7 folder members) -> 13 parts. The folder members were absorbed by the greedy pass.

What was changed to get there:
- func_02021F64 takes `u16 color` (bitfield read through a cast), func_02022004 takes narrow
  (`struct Chan02021FD8 *`, u8, u16) parameters, so func_02021FD8 needs no narrowing at the call.
- One canonical `struct G` (object g_021467A4) and `struct Sub` (0x30 bytes, its two screens)
  are used in p01, p02 and p05; g_021468A4 is `struct G021468A4`.

Round 4 (lane r4_a907): 13 parts -> 9. Old p10..p13 are now one part (p09): p11+p12 merged as they were,
func_02025154/func_020251D8/func_020251FC/func_020252A8 appended with gInfoWin as the one InfoWin pointer
(gSysState was the same object; the Sys struct is gone), func_02024DCC and func_020251D8 rewritten from
machine-style stand-ins into typed C (EXACT), func_02045B38 has one prototype (u16 heap; callers
func_02024838, func_02024498, func_020245AC take u16 parameters now), struct T / T_020244F8 became one
struct Rec4, s32 typedef clones removed, func_02024918 copies from its third argument (MI_CpuCopy8 src,
dest order fixed).

Boundaries left (what blocks each):
- p01|p02 (func_0202208C calls func_02022430): the definition takes `u16 j`, the caller passes the
  value of func_020225F4 as a pointer. `void *` fails to compile, `u32 obj` and `u32 j` both give DIFF.
  The seventh argument is a mode 0/1 flag stored in Sub.f10 (u32).
- p02|p03: func_02022490 still holds a stand-in `char *q` declaration and `struct Obj11272` casts
  where the Slots struct (p03/p04 view) belongs; merging stops with a syntax error.
- p03|p04, p04|p05: func_020225D4 and func_020224DC are machine-style stand-ins (`int a0..a3`)
  that call neighbours through implicit int; the callees take `struct Slots *` / `struct Node *`.
- p05 (func_020225F0..func_02022DCC): still has a dozen clone structs (Obj_02022804 ..
  Obj_020228E0 are all `struct Sub`; Obj_0 is `struct G`; Task_020229A4 / Task_02022A44 /
  Task_020238B4 describe one task object). Needs the struct pass from p05 to p08.
- p05|p06, p06|p07, p07|p08: calls between members do not type-check because of those clones
  (Struct_02023CFC, Interp, Task) and a void-versus-value return of one callee.
- p08|p09: with MI_CpuCopy8 (src, dest) and func_02045B38 unified the merged build compiles but gives
  DIFF (3 bytes in the first function area; same function layout). Not located yet: run
  scratchpad/ol027/mm27.py on the merged pair. func_02045B38's first two parameters are int in p08
  and u32 in p09, MI_CpuCopy8's order differs (p09 fixed in round 4).