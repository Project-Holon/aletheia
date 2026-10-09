# weather_task (ov021)

Translation unit 021A1AAC..021A7360, 452 functions. After the lane 025 greedy
pass (scratchpad/ol020/go20.py with the harmonizer) the TU was 34 parts. In round 4 (r4_ov11) the old p21 DIFF was fixed (an unused static helper clr4 was emitted as a 12-byte function) and old p20+p21+p22 merged, so it is now 32 parts, weather_task_p01.c .. p32.c, all EXACT.

Each boundary between parts still fails to merge. Open kinds:
- Local struct views of one object differ between neighbours (identifier 'Obj'
  redeclared, Obj_021A244C in a parameter list, unsigned char * versus struct *
  for the same global). Needs one canonical struct per object, offsets checked
  against every view.
- Prototypes of shared functions differ (func_0216D5F8, func_0216D410,
  func_0216D83C/854/86C, func_02163E34/58, func_0216D89C, func_021A1BDC,
  func_021A1C34, func_0218EC2C, func_021A63F0 argument count, func_021A6D9C).
  Use the definition's prototype and cast the call arguments.
- void versus value return mismatches (func_0216D5F8 u16 versus u32, others).
- Boundaries that give c99=DIFF after merging (literal pool or inlining changes), checked in round 4:
  after the new p20 (func_021A5C3C|func_021A5CA4) and p21|p22 (old p23|p24); the old p21 DIFF was a stale
  unused static helper and is fixed. The other old DIFF spots (func_021A607C, func_021A666C, the last parts)
  were not re-tested in round 4.

Round 3 check (r3_ov06): no boundary of this TU has uncovered code before it (no bx lr or tail-call stub words), so every remaining boundary is a struct or prototype conflict, not a hidden function.
