/*
 * function: FLDMMDL_ResetMoveStart
 * address: 0x0216E190
 * packet: pkt_ov010_0216E190
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   FLDMMDL_SetMoveBit 0x0216D568 thumb ov010
 *   FLDMMDL_ResetDrawStatusBits 0x0216E174 thumb ov010
 */

typedef unsigned int   u32;
extern void *FLDMMDL_SetMoveBit(void *p, u32 v);
extern void FLDMMDL_ResetDrawStatusBits(void *);
void FLDMMDL_ResetMoveStart(void *a) { FLDMMDL_SetMoveBit(a, 0x20); FLDMMDL_ResetDrawStatusBits(a); }
