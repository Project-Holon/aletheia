# br_codein (ov183): 4 parts left (was 6; round 16 lane L18 merged old p01..p03 into p01)

Open boundaries (current numbering):
- p01|p02 (func_021E0B.. onward, old p04|p05): merge needs `struct Record_021DB2E0` (int value) and
  `typedef Record_021DB2E0` (u32 value) unified, `void func_021DD0AC();` kept unprototyped, int to void * casts
  on func_021FC124/func_021FD860 first arguments, char * to struct * mismatches at func_021E1244/func_021E111C callers.
- later pairs: pointer/array view mismatches (char * vs struct *, int[2] vs struct *).
Findings: func_020457B0 takes (u32 capacity, u16 heapId): that closed the func_021E07A4 narrowing.
