# unit_0217576C (ov009)

Merged as far as the greedy pass allows: 7 part files remain (unit_0217576C_pNN.c, address order),
each byte-exact. Adjacent parts do not merge because of:

- the same global or struct seen through different local views (DWC structs such as
  LoginCnt, DWCstMatchControl, DWCstNodeInfo, DWCstGameMatchKeyData, DWCstDwcCnt, DwcState):
  offsets conflict (scalar vs pointer, void ** vs void *, nested struct vs u32) or a field
  type the unifier cannot size;
- globals declared two ways (for example g_021AA874, g_021AA8A0) whose uses need casts that
  change the bytes;
- prototypes that differ between members (void * vs typed parameters).

Offset-compatible views were already unified by scratchpad tool un3.py. A later struct
pass has to settle the conflicting offsets.
