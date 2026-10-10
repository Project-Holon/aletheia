# fld_trade (ov021): 3 parts (was 5)

Round 7: old p01|p02 merged. Round 10 (w10b): old p03|p04 merged (p04 struct views S_021CE934 / S_021CE984 now used by
the callers in p03 via casts); p01|p02 prototypes reconciled except one (below).

Remaining boundaries:
- p01|p02 (0x021CD050): fixed this round: func_021CD1AC (now void, takes Work_021CCBE0 *, rewritten as typed C),
  func_021CD004 / func_021CD038 / func_021CCE48 (void), func_02049238 (void *), func_020124E8 (Obj_021CC390 *).
  Left: func_02030734. Functions in p01 (func_021CBFB0 ...) need the call to narrow the heap argument (prototype
  u16 heap; the explicit (u16) cast and a u16 parameter both change scheduling), while func_021CD48C in p02 loads
  heap from the stack with ldr and passes it unnarrowed (u16 parameter gives ldrh twice; u32 prototype adds nothing
  to p01 that stays EXACT). Tested both ways. Possibly a real source boundary.
- p02|p03 (0x021CE3E8): many struct-view conflicts (Work_021CD6D0 against the other work views, func_021CE73C,
  func_02082D44, func_020399A8 prototypes). Needs one canonical struct for the trade work object.
