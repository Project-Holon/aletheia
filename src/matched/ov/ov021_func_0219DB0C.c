/*
 * function: FLDMMDL_RAIL_MOVE_MapAttrShadowProc12
 * address:  0x0219DB0C
 * packet:   pkt_ov021_0219DB0C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysIsDrawEnable  0x0216D98C  thumb  ov010
 *   FLDMMDL_CheckMoveBit  0x0216D57C  thumb  ov010
 *   FLDMMDL_RAIL_MOVE_GetFldEffCtrl  0x0219DC08  thumb  ov021
 *   FLDEFF_SHADOW_Start  0x021AC2C0  thumb  ov021
 *   FLDMMDL_SetMoveBit  0x0216D568  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern void *FLDMMDL_GetMmdlSys(void *a0);
extern int FLDMMDL_SysIsDrawEnable(int a0);
extern u32 FLDMMDL_CheckMoveBit(void *p, u32 v);
extern int FLDMMDL_RAIL_MOVE_GetFldEffCtrl(u32 a);
extern void FLDEFF_SHADOW_Start(u32, u32);
extern void *FLDMMDL_SetMoveBit(void *p, u32 v);

void FLDMMDL_RAIL_MOVE_MapAttrShadowProc12(u32 a, u32 a1, u32 a2, u32 a3)
{
    if (FLDMMDL_SysIsDrawEnable((int)FLDMMDL_GetMmdlSys((void *)a)) != 0) {
        if (FLDMMDL_CheckMoveBit((void *)a, 0x4000) == 0) {
            FLDEFF_SHADOW_Start(a, FLDMMDL_RAIL_MOVE_GetFldEffCtrl(a));
            FLDMMDL_SetMoveBit((void *)a, 0x4000);
        }
    }
}
