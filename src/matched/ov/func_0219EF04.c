/*
 * function: FLDMMDL_RAIL_ShuttleDeleteBody
 * address:  0x0219EF04
 * packet:   pkt_0219EF04
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
 *   FLDMMDL_GetMoveProcWork  0x0216D69C  thumb  ov010
 *   FLDMMDL_RAIL_ReleaseRailWork  0x0219EA94  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *FLDMMDL_GetMoveProcWork(void *p);
extern u32 FLDMMDL_RAIL_ReleaseRailWork(u32 a, u32 *b);

int FLDMMDL_RAIL_ShuttleDeleteBody(u32 *a)
{
return FLDMMDL_RAIL_ReleaseRailWork((u32)FLDMMDL_GetMoveProcWork((void *)a), a);
}

