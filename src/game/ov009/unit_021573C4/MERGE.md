# unit_021573C4 (ov009): 37 parts left (was 26 parts + 32 folder members), all EXACT

Remaining boundaries (greedy pass, both function orders):
- The CPS network state is viewed through many local structs for the same globals:
  `NetVars`, `net_vars`, `CPSVars`, `CPSGlobal`, `thread_info`, `_CPSSoc` (redefined with
  different fields in 0215B09C, 0215BAC0, 02159A80, p14, p17), `_OSThread` redefined.
  Failures read "'x' is not a member of class" or "tag redefined". Needs one `_CPSSoc`,
  one network-state struct and one `_OSThread` (union of fields, offsets checked).
- Prototype clash func_02157D8C (unsigned long) returning `unsigned char (*)[6]` in one
  member and another type in the other (part p04 boundary).
- 0215832C: c99=DIFF on merge; p26: undefined identifier `orr` (an asm helper name).

Round 3 (r3_ov01): p01, p11, p34, p37 now verify MATCH (status fixed); all parts contiguous.
