# mb_comm_sys.c (ov107)

Round 4 (lane r4_ov08): 13 parts reduced to 10. d_021F6EA0 is now one struct Counter
{ u8 f0; u8 f1; u16 f2; u32 f4; int f8; } in every part (the G_Counter.h view and the byte and
int array views are gone); old p01..p03 and p05..p06 are merged. Every file verifies EXACT.

Parts, in address order:

- p01: 021EE740 .. 021EEF28 (old p01 to p03)
- p02: 021EF080 .. 021EF0F4
- p03: 021EF444 .. 021EFC1C (old p05, p06)
- p04..p10: old p07..p13 (021EFCA8 .. 021F13BC)

Blockers still open:

- p01 | p02 and p02 | p03 (old p03|p04, p04|p05): DIFF when merged. func_02040588 has two prototypes
  (u32/unsigned char versus unsigned char/unsigned char), func_02049658 returns u32 in the old p05
  and void in p04, func_020413B0 takes u32 first in p05 and u8 in p04. p05 passes u32 bg: try making
  the callers' locals u8.
- Masks views: d_021F6EAC is a struct Masks with three different local layouts (Masks_021F08E4,
  Masks_021F0B04, Masks_021F0D34) and an int array in p12 (d_021F6EAC[0], [1]). Build one struct.
- d_021F6E1C is u8[] in one part and const char[] in another; d_021F6AF8 has no declaration.
- Old p12 | p13 gives DIFF when merged.

Shared rule: the part files must stay separate where a data label only has witnesses in the other part.
