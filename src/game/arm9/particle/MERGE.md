# particle (arm9)

Round 12 (lane w12d): 6 parts -> 4, all dsi/1.1p1 ARM, all byte-exact.
Old p02, p03 and p04 are `particle_p02.c`. What closed them: one `struct BbActSys` (slot
array at +0xC, AreaMan at +0x14) and `struct BbActSlot` replace the clones and the
S8 view; func_02050088 takes a `struct BbActSlot *`; func_0203422C returns int (the
caller func_02050304 returns its result); func_02050304 and func_02050330 are typed C
over the same struct.

Left:
- p01 | p02: p02 starts with func_02050084, the second half of the 8-byte function
  func_02050080 whose first half is in p01 (needs asm to merge). Not mergeable.
- p02 | p03 (02050C04.. in the old p05): struct tags Owner, Entry and Cmd are defined with
  different fields in the two views (inventory: p02 Owner {+0x18 Entry *, +0x1C u16},
  Entry {+0 u32, +0x74 callback}; p03 Owner {+8 callback}, Entry {u16, u16, u32}); and
  func_0204F720 is declared with two prototypes (void (void *, u32, u32 *) against
  int (u32, u32, void *)). Needs one canonical Entry and Owner by offset.
- p03 | p04: p04 uses a global as a struct that p03 declares as a scalar (g_02146A88).
