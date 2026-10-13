/*
 * function: FLDMMDL_RAIL_MOVE_MapAttrProcMoveStartJumpSecond
 * address:  0x0219D990
 * packet:   pkt_ov021_0219D990
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_RAIL_MOVE_UpdateCurrentAttr  0x0219D85C  thumb  ov021
 *   FLDMMDL_CheckDrawInitComp  0x0216DB24  thumb  ov010
 *   FLDMMDL_GetNowAttr  0x0216D7DC  thumb  ov010
 *   FLDMMDL_GetOldAttr  0x0216D7E4  thumb  ov010
 *   FLDMMDL_GetObjCodeParam  0x0216E3C4  thumb  ov010
 *   FLDMMDL_RAIL_MOVE_MapAttrShadowProc12  0x0219DB0C  thumb  ov021
 *   FLDMMDL_RAIL_MOVE_MapAttrReflectProc01  0x0219DB5C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
extern u32 FLDMMDL_RAIL_MOVE_UpdateCurrentAttr(u32);
extern int FLDMMDL_CheckDrawInitComp(int a0);
typedef unsigned char  u8;
extern u32 FLDMMDL_GetNowAttr(void *p);
extern u32 FLDMMDL_GetOldAttr(void *p);
extern void *FLDMMDL_GetObjCodeParam(void *p);
extern void FLDMMDL_RAIL_MOVE_MapAttrShadowProc12(u32, u32, u32, u32);
extern void FLDMMDL_RAIL_MOVE_MapAttrReflectProc01(void *a, u32 b, u32 c, u8 *d);

void FLDMMDL_RAIL_MOVE_MapAttrProcMoveStartJumpSecond(void *a)
{
    u32 b;
    u32 c;
    u32 d;
    if (FLDMMDL_RAIL_MOVE_UpdateCurrentAttr((u32)a) != 0 && FLDMMDL_CheckDrawInitComp((int)a) == 1) {
        b = FLDMMDL_GetNowAttr((void *)a);
        c = FLDMMDL_GetOldAttr((void *)a);
        d = (u32)FLDMMDL_GetObjCodeParam((void *)a);
        FLDMMDL_RAIL_MOVE_MapAttrShadowProc12((u32)a, b, c, d);
        FLDMMDL_RAIL_MOVE_MapAttrReflectProc01(a, b, c, (u8 *)d);
    }
}
