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
