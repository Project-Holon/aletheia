# br_codein (ov183): 7 parts left (was 11; round 2 lane r2_11)

Merged this round: old p01..p05 into p01 (func_021DD0AC is declared `void func_021DD0AC();`
before its callers because callers pass 2 args and the definition takes 1; func_021FD860
unified to (void *, unsigned, const void *) with pointer casts at call sites; the redefined
local tags Position, Record, Triple were renamed by the merge tool). The merged file p01 is
EXACT. In the merged text the hoisted prototype of func_021DD0AC must be turned into `()`
by hand each time two parts are merged.

Open boundaries (current numbering):
- p01|p02 (old p05|p06 plus the merged head): DIFF, 17 bytes in a data row near
  func_021DF3DC (pure data/section tail, not analysed).
- p02|p03, p03|p04, p04|p05, p05|p06, p06|p07: compile errors from pointer/array views not
  yet run through the cast pass: char * vs struct State_021DF620 *, int[2] vs struct *,
  void * vs int, struct * vs int *.
