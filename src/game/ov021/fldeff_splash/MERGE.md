# fldeff_splash: 6 parts, all EXACT (round 3: 15 -> 6)

Hidden functions added (empty `bx lr` leaves): func_021C4974, func_021C4B24, func_021C4C50.

Remaining boundaries:
- p01/p02 (0x021C49C0) and p02/p03 (0x021C4C54): the generic local struct S is a different
  object in each part (`'p' is not a member of class struct S_021C49C0`). Needs one
  canonical struct built by offset from all views.
- p03/p04 (0x021C4D7C): merged file is DIFF, no uncovered code between them (pool word).
- p04/p05 (0x021C4E08): `'task' is not a member of class struct` (an unnamed struct view
  against a named one). Same canonical struct fix.
- p05/p06 (0x021C577C): func_021C577C has three signatures (void *, void *,int,int and
  others) in the old p12, p13, p14. Use the definition's prototype and cast the callers.
