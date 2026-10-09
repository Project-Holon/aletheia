# wifibattlematch_view (ov177): 3 parts left (round 5 lane s11 merged old p01 and p02)

Parts: p01 (func_021E5440..func_021E65xx: old p01+p02), p02 (func_021E65FC..func_021E888C), p03 (func_021E88B0..).
All parts verify EXACT.

Done in round 5: p01|p02 closed by giving func_0204B404 one prototype (void *, const Pt_021E5D68 *, u16) and casting the
Vec2 call in the old p01 to Pt_021E5D68 (same short x, y layout).

Open boundaries:
- p01|p02 (now): Work_021E5D68 (old p02) lacks fields of the 0x238 Work in p02 (fields count, wins[30], slots[30], objs[22]...);
  func_021E6718 and func_021E72FC are called with the other Work view. One canonical Work by offset is still needed.
  Prototypes that differ: func_0204B404, func_020457B0, func_0201C724, func_0204AF28, func_0204A6C8, func_0201EC64.
- p02|p03 (0x021E88B0): merged build compiles after casts, but func_021E888C (caller in p02) is 4 to 8 bytes too long.
  p02 declares func_021E88B0(S *, int, u8, int, int, int) (only the third argument is narrowed in the original), while the
  definition in p03 takes (const Desc *, u8, u8, u8, u8, u16) and its body casts x, y and width to u8 explicitly. Next: try
  (const Desc *, u8 x, u8 y, int width, int height, int heap) with the body casts kept, and make v in func_021E888C u8.

Round 6 (lane s_mid2), p02|p03 findings:
- S_021E888C in p02 is the same object as Desc in p03 (f1c is Desc.count at 0x1c): use Desc in func_021E888C and the merge compiles
  after `(const char *)d_021E8DD4` at the func_02030734 call.
- Making func_021E888C take `u16 a` (wide caller lever) removes the heap narrowing at the call to func_021E88B0 (definition keeps u16 heap).
- Left: the original caller passes height (v, an int) with no narrowing while the callee reads height as a byte from the stack
  (`add r0,sp,#0x68; ldrb`). With u8 height the caller adds lsls/lsrs; with int height the callee loses the ldrb. The two views cannot
  both be built from one prototype: probably a real boundary or an implicit call (mwcc rejects the implicit form here).
