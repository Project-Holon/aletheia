/*
 * function: FLDMMDL_RAIL_GetRandomTableEntry
 * address:  0x0219EA10
 * packet:   pkt_0219EA10
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FLDMMDL_RAIL_GetTableLength  0x0219E9F8  thumb  ov021
 *   func_020056EC  0x020056EC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020056EC(u32);
extern int FLDMMDL_RAIL_GetTableLength(u32 *arr, u32 v);

int FLDMMDL_RAIL_GetRandomTableEntry(u32 *a, int b)
{
return *(u32 *)((u8 *)(a) + ((func_020056EC(FLDMMDL_RAIL_GetTableLength((u32 *)a, b)) << 2)));
}

