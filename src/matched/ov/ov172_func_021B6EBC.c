/*
 * function: DRAW_SYSTEM_GetPlane
 * address:  0x021B6EBC
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to G2_GetBG2ScrPtr (ARM9).
 *
 * symbols:
 *   G2_GetBG2ScrPtr  0x0207E008  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void *G2_GetBG2ScrPtr(void);

void *DRAW_SYSTEM_GetPlane(void)
{
    return G2_GetBG2ScrPtr();
}
