/*
 * function: FLDMMDL_RAIL_MOVE_MapAttrGrassProc0
 * address:  0x0219DA80
 * packet:   pkt_ov021_0219DA80
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MAP_ATTR_GetFlags  0x021AB0F8  thumb  ov021
 *   FLDMMDL_RAIL_MOVE_GetFldEffCtrl  0x0219DC08  thumb  ov021
 *   FLDEFF_GRASS_Start  0x021AC760  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern u16 MAP_ATTR_GetFlags(u32 attr);
extern int FLDMMDL_RAIL_MOVE_GetFldEffCtrl(u32 a);
extern void FLDEFF_GRASS_Start(u32 a, u32 b, u32 c, int d);

void FLDMMDL_RAIL_MOVE_MapAttrGrassProc0(u32 a, u32 b, u32 a2, u32 a3)
{
    if (MAP_ATTR_GetFlags(b) & 0x20)
        FLDEFF_GRASS_Start(FLDMMDL_RAIL_MOVE_GetFldEffCtrl(a), a, 0, 0);
}
