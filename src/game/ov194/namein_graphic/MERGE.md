# namein_graphic: blockers (lane 051)

23 files reduced to 4 parts (p01 021F1440, p02 021F1D58, p03 021F2F8C, p04 021F3B18). Three
boundaries stay. All three have the same shape: a callee has narrow parameters (or a narrow
return type) in its definition, and the caller passes wide values with no narrowing code. A
prototype-style declaration makes the caller narrow (lsls/lsrs), a K&R definition makes the
callee narrow on entry; the image has neither. Possibly these are separate original TUs.

- p01 | p02: func_021F1E28(u8 *, int, u16 b, u16 c, int, u8 *, int) is called from func_021F1440
  with word values for b and c. Caller-side narrowing adds 4 bytes to func_021F1440.
- p02 | p03: func_021F26F0(char *, char *, void *, void *, u16 heap) is called from func_021F3008
  with a full-word heap argument (the same value is forwarded to word parameters elsewhere).
- p03 | p04: func_021F32FC is defined as returning void * (word load) and read in p04 as
  `u16 value = func_021F32FC(p + 0xfc)`; a u16 return type in the definition changes the
  callee, a cast at the call changes the caller.

Round 18 (L15) tried, all reverted:
- p01|p02: c as int, void *, u32, u8 *, u16 *, char *; b as u8 with the caller cast dropped. With any wide c the callee spills a before b (str r1 then str r2); target stores b first. Only u16 c matches, and it needs a narrowing caller.
- p02|p03: u16 heap in func_021F3008 (and in the p01 call): the callee then loads heap with ldrh and changes register assignment (364 bytes DIFF); the target loads the word (ldr r4,[sp,#0x40]) and passes it on, while func_021F26F0 reads it with ldrh.
- p03|p04: func_021F32FC returning u32/int and the caller's value as u32/int (merge compiles after Pair * and const u8 * unification, only func_021F47B4 differs: owner/value swap r6/r7); u16 return in the definition narrows in the callee (+6 bytes).

F08b (2026-10-12): the scratch merge compiles and is DIFF in two places only (a 4-byte excess in func_021F3FBC was
the `u32 r` argument of func_0201C724 in p04: a u16 local `r` passes unnarrowed and fixes it; `u32 heap` with
`*(u16 *)&heap` in func_021F26F0 holds).
- boundary 1 (func_021F1E28): only a narrow c (u16 or u8) gives the target's store order (str r2 before str r1);
  a u32 c with any other parameter types, a (u16) local, or an address pun does not. A narrow c needs a narrowing
  caller (+4 bytes in func_021F1440). A prior K&R/implicit declaration is rejected by mwcc (redeclared).
- boundary 3 (func_021F47B4): after the u32 return fix only a register swap is left: the target has owner r6 and
  value r7, the compiler gives value r6 and owner r7. mwccdbg regalloc: owner and value both have spill cost 2
  and owner has the lower cost/degree ratio (0.111 against 0.125), so it is pushed first and coloured last.
  Declaration order, value-first call order, a local copy of owner and u16/int value do not change it.

F10 (2026-10-12): p03 and p04 merged (4 -> 3 parts, all EXACT). Boundary 3 closed without a pun: func_021F21BC takes
`u32 b` (it only forwards b to func_021F23FC, which takes int), so the caller's wide `value` needs no narrowing;
func_021F32FC returns u32 and `value` is u32. func_020490F4 takes `u16 heap` in the merged part (as p04 had it).
Boundary 1 (p01 | p02, func_021F1E28) stays. Mechanism (mwccdbg sched/alias): the entry stores of a, b, c order by
deadline; a narrow param is in the scheduler's unknown-memory set G, so with b and c narrow the store of b gets an
edge to the store and load of c, height 26 against 25, and b is stored first (target: b, a, c). With c wide c is an
exact object, no edge, order a, b, c. Only a narrow c makes c part of G (wide c as pointer, struct, address taken,
f narrow all tried: no or a larger change). A narrow c needs a narrowing caller (target caller loads c with ldr and
passes it unnarrowed) and mwcc rejects differing prototypes in one TU, so the original caller and callee are in
different TUs (header and definition disagree on c). Boundary 2 (p02 | p03) holds only with a `u32 heap` plus
`*(u16 *)&heap` pun, which is also a sign of a TU boundary; it is left split.
