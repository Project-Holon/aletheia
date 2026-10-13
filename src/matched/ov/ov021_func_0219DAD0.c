/*
 * function: FLDMMDL_RAIL_MOVE_MapAttrFootMarkProc1
 * address:  0x0219DAD0
 * packet:   pkt_ov021_0219DAD0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MAP_ATTR_GetFlags  0x021AB0F8  thumb  ov021
 *   FLDMMDL_RAIL_MOVE_GetFldEffCtrl  0x0219DC08  thumb  ov021
 *   FLDEFF_FOOTMARK_SetMMdl  0x021BBDD4  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern u16 MAP_ATTR_GetFlags(u32 attr);
extern int FLDMMDL_RAIL_MOVE_GetFldEffCtrl(u32 a);
extern void FLDEFF_FOOTMARK_SetMMdl(int a, int b, int c);

void FLDMMDL_RAIL_MOVE_MapAttrFootMarkProc1(u32 a, u32 x, u32 b, u8 *p)
{
    u32 h;
    int f;
    if (b != 0xFFFFFFFF && (MAP_ATTR_GetFlags(b) & 8)) {
        h = FLDMMDL_RAIL_MOVE_GetFldEffCtrl(a);
        f = 0;
        if (p[5] == 2)
            f = 1;
        FLDEFF_FOOTMARK_SetMMdl(a, h, f);
    }
}
