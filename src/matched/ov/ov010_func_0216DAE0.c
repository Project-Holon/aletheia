/*
 * function: FLDMMDL_SetStatusBitFellowHit
 * address: 0x0216DAE0
 * packet: pkt_ov010_0216DAE0
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   FLDMMDL_SetStatusBit 0x0216D548 thumb ov010
 *   FLDMMDL_ClearStatusBit 0x0216D550 thumb ov010
 */

extern unsigned int *FLDMMDL_SetStatusBit(unsigned int *p, unsigned int v);
typedef unsigned int   u32;
extern u32 *FLDMMDL_ClearStatusBit(u32 *p, u32 v);
void FLDMMDL_SetStatusBitFellowHit(unsigned int *p, unsigned int v)
{
    if (v == 1) FLDMMDL_ClearStatusBit(p, 128);
    else FLDMMDL_SetStatusBit(p, 128);
}
