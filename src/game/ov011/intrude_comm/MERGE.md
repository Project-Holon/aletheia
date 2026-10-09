# intrude_comm.c

Round 3 (r3_ov04): the hidden function func_0217358C (4 bytes, u8 *f(u8 *p) { return p + 12; }) now sits in p02, so the old p02|p03 boundary is gone. 2 parts left.

- p01|p02: func_02012B64 is declared (struct BigObj *, u8) in p01 and (void *sv, u32 a) in p02. With the real prototype the u16 argument from func_02039338 gets a truncation. Dropping the declaration (implicit call) still gives a DIFF: func_02172D70 grows by 8 bytes (code 28 bytes longer, literal pool 20 shorter), so more than that one prototype is involved. Not solved.
