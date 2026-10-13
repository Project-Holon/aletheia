/*
 * function: UNION_EFF_UpdateAnimGroup
 * address: 0x0217FACC
 * packet: pkt_ov019_0217FACC
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FLDMMDL_CheckStatusBitUse 0x0216DA30 thumb ov010
 *   UNION_EFF_UpdateAnimObj 0x0217FA78 thumb ov019
 *   UNION_EFF_DeleteAnimObj 0x0217FA54 thumb ov019
 */

typedef unsigned int u32;
extern int FLDMMDL_CheckStatusBitUse(int a0, int a1);
extern void UNION_EFF_UpdateAnimObj(u32 *p);
extern void UNION_EFF_DeleteAnimObj(u32 *p);
void UNION_EFF_UpdateAnimGroup(u32 *p, int a1)
{
    if (p[3] != 0) {
        if (FLDMMDL_CheckStatusBitUse(p[0], a1) == 1) UNION_EFF_UpdateAnimObj(p);
        else UNION_EFF_DeleteAnimObj(p);
    }
}
