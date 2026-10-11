# zukan_detail_graphic (ov208): 2 parts (was 7)

Round 17 (L14): p02..p08 merged into p02 (all EXACT). Levers: func_0204B878 is (struct Obj *, u16) and
the callers' anim locals are u16 (no narrowing needed); func_021C06A0 / func_021C0CC0 take (void *, X *, void *)
like the other handlers, func_021C0CC0 returns the tail-called result; func_0204B294 takes u32 owner;
func_0200CC40 takes (void *, u32 id, ...).
One boundary left, p01|p02: ov208_func_021BD574 reads its 15th (stack) argument with ldrh (u16 heap) but
its caller ov208_func_021BD444 (p01) stores the word-sized heap with no narrowing. With the u16 prototype the
caller adds lsls/lsrs; without a prototype (implicit call) the u8 arguments are promoted and the caller
layout changes (198 bytes DIFF); a u32 definition changes the callee (ldr instead of ldrh).
