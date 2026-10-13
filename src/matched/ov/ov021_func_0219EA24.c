/*
 * function: FLDMMDL_RAIL_GetRandomDirOfKind
 * address:  0x0219EA24
 * packet:   pkt_ov021_0219EA24
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_RAIL_GetDirListOfKind  0x0219EA40  thumb  ov021
 *   FLDMMDL_RAIL_GetTableLength  0x0219E9F8  thumb  ov021
 *   func_020056EC  0x020056EC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern int FLDMMDL_RAIL_GetDirListOfKind(int key);
extern int FLDMMDL_RAIL_GetTableLength(u32 *arr, u32 v);
extern u32 func_020056EC(u32 v);

u32 FLDMMDL_RAIL_GetRandomDirOfKind(u32 a, u32 b)
{
    u32 *t = (u32 *)FLDMMDL_RAIL_GetDirListOfKind(a);
    return t[func_020056EC(FLDMMDL_RAIL_GetTableLength(t, b))];
}
