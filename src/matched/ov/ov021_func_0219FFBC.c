/*
 * function: FLDMMDL_DRAW_AddHeightOffset
 * address:  0x0219FFBC
 * packet:   pkt_ov021_0219FFBC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysGetFieldMap  0x0216D534  thumb  ov010
 *   FIELDMAP_GetCameraPitchScale  0x02189A78  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern void *FLDMMDL_GetMmdlSys(void *a0);
extern u32 FLDMMDL_SysGetFieldMap(void *p);
extern u32 FIELDMAP_GetCameraPitchScale(u8 *p);

void FLDMMDL_DRAW_AddHeightOffset(u32 a, u32 *p)
{
    p[1] += FIELDMAP_GetCameraPitchScale((u8 *)FLDMMDL_SysGetFieldMap(FLDMMDL_GetMmdlSys((void *)a)));
}
