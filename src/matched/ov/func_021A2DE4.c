/*
 * function: FIELDMAP_CTRL_GRID_Destroy
 * address:  0x021A2DE4
 * packet:   pkt_021A2DE4
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
 *   FIELDMAP_GetCtrlWork  0x02188CA4  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020307B0(void *p);
extern u32 FIELDMAP_GetCtrlWork(u8 *p);

int FIELDMAP_CTRL_GRID_Destroy(u32 a, u32 b, u32 c, u32 d)
{
return func_020307B0((void *)FIELDMAP_GetCtrlWork((u8 *)a));
}

