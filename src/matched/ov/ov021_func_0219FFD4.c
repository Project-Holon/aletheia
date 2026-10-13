/*
 * function: FLDMMDL_DRAW_GetDirIndex
 * address:  0x0219FFD4
 * packet:   pkt_ov021_0219FFD4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 *
 * symbols:
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysGetAreaId  0x0216D538  thumb  ov010
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_CheckStatusBit  0x0216D55C  thumb  ov010
 *   FLDMMDL_RAIL_MOVE_GetDirByAngle  0x0219D738  thumb  ov021
 *   FLDMMDL_MOVE_GetRelativeDirCode  0x021642D4  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern void *FLDMMDL_GetMmdlSys(void *a0);
extern u32 FLDMMDL_SysGetAreaId(u8 *p);
extern u16 FLDMMDL_GetDirDisp(void *p);
extern int FLDMMDL_CheckStatusBit(int a0, int a1);
extern u32 FLDMMDL_RAIL_MOVE_GetDirByAngle(u32 a, int b);
extern u8 FLDMMDL_MOVE_GetRelativeDirCode(int i, int v);

void FLDMMDL_DRAW_GetDirIndex(u32 a)
{
    u32 x = FLDMMDL_SysGetAreaId(FLDMMDL_GetMmdlSys((void *)a));
    u32 y = FLDMMDL_GetDirDisp((void *)a);
    if (FLDMMDL_CheckStatusBit(a, 0x2000))
        FLDMMDL_RAIL_MOVE_GetDirByAngle(a, x);
    else
        FLDMMDL_MOVE_GetRelativeDirCode(y, x);
}
