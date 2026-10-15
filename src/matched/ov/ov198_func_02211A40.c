/*
 * function: B_PLIST_MAIN_ShowCursor
 * address:  0x02211A40
 * packet:   pkt_02211A40
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   B_PLIST_MAIN_LayoutCursorActors   0x02211A24  thumb  ov198
 *   B_PLIST_MAIN_SetActorsVisible   0x02211A10  thumb  ov198
 */

typedef unsigned char u8;

extern void B_PLIST_MAIN_LayoutCursorActors(u8 *, unsigned);
typedef unsigned int   u32;
extern u32 B_PLIST_MAIN_SetActorsVisible(u8 *p, u32 v);

void B_PLIST_MAIN_ShowCursor(u8 *p, unsigned idx)
{
    B_PLIST_MAIN_LayoutCursorActors(p, idx);
    B_PLIST_MAIN_SetActorsVisible(p, 1);
}
