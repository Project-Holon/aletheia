/*
 * function: FLDMMDL_RAIL_MOVE_GetFldEffCtrl
 * address:  0x0219DC08
 * packet:   pkt_0219DC08
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysGetFieldMap  0x0216D534  thumb  ov010
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FLDMMDL_SysGetFieldMap(void *p);
extern void *FLDMMDL_GetMmdlSys(void *a0);
extern u32 FIELDMAP_GetEffect(u8 *p);

int FLDMMDL_RAIL_MOVE_GetFldEffCtrl(u32 a)
{
return FIELDMAP_GetEffect((u8 *)FLDMMDL_SysGetFieldMap((void *)FLDMMDL_GetMmdlSys((void *)a)));
}

