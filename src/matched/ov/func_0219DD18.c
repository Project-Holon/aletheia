/*
 * function: FLDMMDL_RAIL_MOVE_AcWalkEnd
 * address:  0x0219DD18
 * packet:   pkt_0219DD18
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
 *   FLDMMDL_SetDrawStatus  0x0216D674  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void FLDMMDL_SetDrawStatus(void *p, u16 v);

int FLDMMDL_RAIL_MOVE_AcWalkEnd(u32 a, u32 b, u32 c, u32 d)
{
FLDMMDL_SetDrawStatus((void *)a, 0);
return 0;
}

