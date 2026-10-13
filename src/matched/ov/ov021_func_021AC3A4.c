/*
 * function: FLDEFF_SHADOW_Update
 * address:  0x021AC3A4
 * packet:   pkt_ov021_021AC3A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_CheckCheckInfo  0x0216E1C4  thumb  ov010
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysIsDrawEnable  0x0216D98C  thumb  ov010
 *   FLDMMDL_CheckStatusBitVanish  0x0216DAB4  thumb  ov010
 *   FLDMMDL_CheckMoveBit  0x0216D57C  thumb  ov010
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int FLDMMDL_CheckCheckInfo(int a0, int a1);
extern void *FLDMMDL_GetMmdlSys(void *a0);
extern int FLDMMDL_SysIsDrawEnable(int a0);
extern int FLDMMDL_CheckStatusBitVanish(void *a0);
extern u32 FLDMMDL_CheckMoveBit(void *p, u32 v);
extern void FIELD_EFFECT_DeleteObject(u32 a);

void FLDEFF_SHADOW_Update(u32 a, u32 *b)
{
    if (FLDMMDL_CheckCheckInfo(b[2], (int)(b + 3)) == 0) {
        FIELD_EFFECT_DeleteObject(a);
        return;
    }
    if (FLDMMDL_SysIsDrawEnable((int)FLDMMDL_GetMmdlSys((void *)b[2])) == 0) {
        FIELD_EFFECT_DeleteObject(a);
        return;
    }
    if (FLDMMDL_CheckStatusBitVanish((void *)b[2]) == 1 || FLDMMDL_CheckMoveBit((void *)b[2], 0x8000) != 0)
        b[0] = 1;
    else
        b[0] = 0;
}
