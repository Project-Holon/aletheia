/*
 * function: FLDMMDL_MOVE_StopAcmdWalkCodes
 * address: 0x021641C8
 * packet: pkt_ov010_021641C8
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: halfword-wrapped +0xFFCD preserves the literal-pool bias;
 * spelling -51 produced a 26-byte DIFF instead of the 32-byte body.
 * symbols:
 *   FLDMMDL_GetMoveCode 0x0216D5A0 thumb ov010
 *   FLDMMDL_CallMoveProc 0x0216D708 thumb ov010
 */

typedef unsigned short u16;
extern u16 FLDMMDL_GetMoveCode(void *);
extern void FLDMMDL_CallMoveProc(void *);
void FLDMMDL_MOVE_StopAcmdWalkCodes(void *a) { if ((u16)(FLDMMDL_GetMoveCode(a)+0xFFCD) <= 3) FLDMMDL_CallMoveProc(a); }
