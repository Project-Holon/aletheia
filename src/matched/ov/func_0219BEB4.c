/*
 * function: FLDEFF_HIDE_Create
 * address:  0x0219BEB4
 * packet:   pkt_0219BEB4
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
 *   FLDEFF_HIDE_Start  0x021D046C  thumb  ov021
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
extern u32 FLDEFF_HIDE_Start(u32, u32, u32);

int FLDEFF_HIDE_Create(u32 a, u32 b)
{
return FLDEFF_HIDE_Start(FIELDMAP_GetEffect((u8 *)FLDMMDL_SysGetFieldMap(FLDMMDL_GetMmdlSys((void *)a))), a, b);
}

