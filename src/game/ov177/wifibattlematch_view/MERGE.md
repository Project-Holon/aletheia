# wifibattlematch_view (ov177): 4 parts left (was 10; round 4 lane r4_ov09)

Parts: p01 (func_021E5440..), p02 (func_021E5D68..), p03 (func_021E65FC..func_021E888C), p04 (func_021E88B0..).
All parts verify EXACT.

Round 4: old p05..p10 merged. Keys: func_021E7CF0 takes (void *, unsigned, unsigned) with no u16 narrowing
(the original compare has no zero-extension); one Work struct for the 0x9c object at 0x21E7xxx (owner, win[8],
ent[7], main, obj[5], menu, count, base, objBase, mode); one Work for the 0x238 object at 0x21E65FC (count,
wins[30], slots[30], objs[22], chr, cell, pal, pal2, chr2, cell2, objCount, baseX, bg, palette, palSlot, layer);
func_0204AC18 and func_0204A6C8 take u16 trailing args (callers func_021E72FC and func_021E7B68 take u16 heap);
func_0204B294 last parameter is unsigned; func_0201C724 first parameter is void *.

Open boundaries:
- p03|p04 (0x021E88B0): merged build compiles after casts, but func_021E888C (caller in p03) is 4 to 8 bytes
  too long. p03 declares func_021E88B0(S *, int, u8, int, int, int) (only the third argument is narrowed in the
  original), while the definition in p04 takes (const Desc *, u8, u8, u8, u8, u16) and its body casts x, y and
  width to u8 explicitly. No parameter split found that is EXACT in both. Next: try (const Desc *, u8 x, u8 y, int
  width, int height, int heap) with the body casts kept, and make v in func_021E888C u8.
- p01|p02: const struct view of a record at p01 end versus the Work in p02.
- p02|p03: Work_021E5D68 (p02) lacks fields of the later views; one canonical struct by offset is still needed.
