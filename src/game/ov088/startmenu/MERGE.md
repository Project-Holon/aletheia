# ov088 startmenu: merge status

Files: startmenu_p01.c (021B95A0..021BBB84, includes func_021BBA64), startmenu_p02.c (021BBB84 and later).
Six parts were reduced to two (struct Ent unified to f0/f2, extra unused parameters added to
func_021B99E0/9BD4/9DD0/9F68, one print_line helper, one prototype for func_02041300).

## Boundary p01 | p02 (open)

Cause: func_02041300 first parameter.
- func_021BBA64 (p01) reads its stack argument as a word (`u32 layer = *(u32 *)&bg;`) and passes it
  unmasked: it needs a `u32` first parameter.
- func_021BBB84 (p02) passes a `u8 bg` argument and the original reloads it from the stack for each use
  (`ldrb`): it needs a `u8` first parameter. With `u32` the compiler keeps bg in r4 (31 bytes differ).
Both views cannot be one prototype without changing bytes. The original probably declared the callee
differently at the two sites (block-scope or implicit declaration), which is not plausible to reproduce.
Reason kept split: c99=DIFF.

## Parked (2026-10-09)
p01 and p02 merge EXACT if func_021BBB84's `u8 bg` parameter is declared
`volatile u8 bg` (the original reloads the stack argument at every use) together
with the u32 prototype of func_02041300. Not applied: a volatile parameter has no
plausible reason in the original source. Review later.
