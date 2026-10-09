# unit_021573C4 (ov009): 34 parts left (was 37), all verify

Round 5 (r5s03): the greedy pass merged p16+p17+p18 (old numbering) and p36+p37. Parts renumbered.
Remaining boundaries (greedy pass, both function orders):
- The CPS network state is viewed through many local structs for the same globals:
  NetVars, net_vars, CPSVars, CPSGlobal, thread_info, _CPSSoc (redefined with different
  fields in 0215B09C, 0215BAC0, 02159A80 and others), _OSThread redefined.
  Needs one _CPSSoc (reuse the canonical CPSSoc/SOCLSocket blocks of unit_0215D6C8.c and
  unit_0215E024.c), one network-state struct and one _OSThread (union of fields, offsets checked).
  A converter like scratchpad r5s03/conv.py (dwc_rap) can do the raw-offset rewrites.
- Prototype clash func_02157D8C (unsigned long) returning unsigned char (*)[6] in one member
  and another type in the other (old p10 boundary).
- 0215832C: c99=DIFF on merge; old p26: undefined identifier orr (an asm helper name).
- p34 (0x0215C508) verifies MATCH, header status set to MATCH.
