# wipe_sub (arm9)

Round 6 (lane sa9): old p02+p03 merged by the greedy pass (EXACT), 9 parts -> 8. Part numbers below are the new ones (old p04..p09 are now p03..p08).

Boundaries left (what blocks each):
- p01|p02 (func_0202208C calls func_02022430): the definition takes `u16 j`, the caller passes the
  value of func_020225F4 as a pointer. `void *` fails to compile, `u32 obj` and `u32 j` both give DIFF.
  The seventh argument is a mode 0/1 flag stored in Sub.f10 (u32).
- p02|p03: func_02022490 still holds a stand-in `char *q` declaration and `struct Obj11272` casts
  where the Slots struct (p03/p04 view) belongs; merging stops with a syntax error.
- p02|p03, p03|p04: func_020225D4 and func_020224DC are machine-style stand-ins (`int a0..a3`)
  that call neighbours through implicit int; the callees take `struct Slots *` / `struct Node *`.
- p05 (func_020225F0..func_02022DCC): still has a dozen clone structs (Obj_02022804 ..
  Obj_020228E0 are all `struct Sub`; Obj_0 is `struct G`; Task_020229A4 / Task_02022A44 /
  Task_020238B4 describe one task object). Needs the struct pass from p05 to p08.
- p05|p06, p06|p07, p07|p08: calls between members do not type-check because of those clones
  (Struct_02023CFC, Interp, Task) and a void-versus-value return of one callee.
- (w10d) old p07|p08 is merged and EXACT (the 3 byte DIFF is gone with the current merge tool). Part numbers: 8 parts -> 7.
- (old note, resolved) p08|p09: with MI_CpuCopy8 (src, dest) and func_02045B38 unified the merged build compiles but gives
  DIFF (3 bytes in the first function area; same function layout). Not located yet: run
  scratchpad/ol027/mm27.py on the merged pair. func_02045B38's first two parameters are int in p08
  and u32 in p09, MI_CpuCopy8's order differs (p09 fixed in round 4).
Note: old p02|p03 (p02 stand-in char *q) merged on its own in round 6; the remaining boundaries above are as before with the shifted numbers (old p05 is p04 and so on). p07|p08 (old p08|p09) is DIFF by only 3 bytes in the merged file, not located (the diff tool shows no mismatching row).
