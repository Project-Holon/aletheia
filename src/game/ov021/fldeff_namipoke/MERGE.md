# fldeff_namipoke: 4 parts, all EXACT (round 3: 10 -> 4)

Hidden functions added (empty `bx lr` leaves): func_021AC9D4, func_021ACCAC, func_021ADBAC.
They closed the old p01/p02, p02/p03 and p09/p10 boundaries.

Remaining boundaries:
- p01/p02 (0x021ACDC4): local struct names B, Inner, Node, V3, P are used for different
  views of the objects in p01 and p02 (merge gives `'fc' is not a member of class struct
  B_021AC810`). Needs one canonical struct per object, offsets checked against every view.
- p02/p03 (0x021AD6B8): S16, Obj, Vec views differ (`S16_021ACDC4` against `S16_021AD6B8`,
  `struct Node *` passed where another struct is expected). Same fix.
- p03/p04 (0x021AD7A0): merged file is DIFF with no uncovered code between them (the
  previous function ends in a literal pool word). Check literal pool or string sharing.
