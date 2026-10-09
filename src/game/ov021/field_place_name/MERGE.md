# field_place_name (ov021)

Nine parts remain, every one EXACT (was 10). Round 5 (r5s08): struct Head had two views
(p01: pad[4], void *h4, u16 tab[]; p02: int h0, int h4). It is now one typedef struct Head
{ int h0; int h4; u16 tab[1]; } in both, with a (void *) cast at the func_02050340 call; the old p01 and p02 merged.

Open boundaries (greedy merge result, numbers are the new part numbers):
- p01|p02 (021BC704): c99=DIFF with no mismatching rows in the diff window (code before the boundary
  ends in `pop {r4, pc}`; no uncovered code). Needs a look at the size table of the merged build.
- p02|p03: func_021BD184 is (void *) in one part and four u32 parameters in another;
  an `h42` member is missing in one view of an object.
- p03|p04: u32 passed where an anonymous struct pointer is expected (func_021BD1EC area).
- p04|p05 .. p07|p08: anonymous struct views (f00, f0, f4 members missing in one view), u32 * against u32.
- p08|p09: func_021BDD9C takes (struct *, void *) in one part and (struct *) in the other;
  func_021BE148 is (u32) against (u32, int).
Each needs one canonical struct per object, offsets checked against every view.
