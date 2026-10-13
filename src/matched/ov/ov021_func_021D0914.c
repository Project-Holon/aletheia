/*
 * function: FLDEFF_BUBBLE_GetFacingVector
 * address:  0x021D0914
 * packet:   pkt_ov021_021D0914
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_CheckStatusBit  0x0216D55C  thumb  ov010
 *   FLDMMDL_MOVE_GetDirAddGridX  0x021641E8  thumb  ov010
 *   FLDMMDL_MOVE_GetDirAddGridZ  0x021641F8  thumb  ov010
 *   FLDMMDL_RAIL_GetDrawOffsetByDir  0x0219E784  thumb  ov021
 *   VEC_Fx16Normalize  0x0207CDB8  arm
 */

typedef short s16;

typedef unsigned short u16;
extern u16 FLDMMDL_GetDirDisp(void *p);
extern int FLDMMDL_CheckStatusBit(int a, int b);
extern int FLDMMDL_MOVE_GetDirAddGridX(int a);
extern int FLDMMDL_MOVE_GetDirAddGridZ(int a);
typedef unsigned int   u32;
extern void FLDMMDL_RAIL_GetDrawOffsetByDir(u32 o, u32 idx, s16 *v);
extern void VEC_Fx16Normalize(s16 *a, s16 *b);

int FLDEFF_BUBBLE_GetFacingVector(int a, s16 *v)
{
    int r;

    r = FLDMMDL_GetDirDisp((void *)a);
    if (FLDMMDL_CheckStatusBit(a, 0x1000 * 2) == 0) {
        v[1] = 0;
        v[0] = FLDMMDL_MOVE_GetDirAddGridX(r);
        v[2] = FLDMMDL_MOVE_GetDirAddGridZ(r);
        v[0] = v[0] << 16;
        v[2] = v[2] << 16;
    } else {
        FLDMMDL_RAIL_GetDrawOffsetByDir(a, r, v);
        v[1] = 0;
    }
    VEC_Fx16Normalize(v, v);
    return r;
}
