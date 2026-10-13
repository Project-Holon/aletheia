/*
 * function: FIELD_SUBSCREEN_UpdateMenu
 * address:  0x021A1288
 * packet:   pkt_ov021_021A1288
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_MENU_Update  0x021A85B4  thumb  ov021
 *   INFOWIN_Update  0x02024ABC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

struct Obj;
extern u32 FIELD_MENU_Update(struct Obj *p);
extern void INFOWIN_Update(u32);

void FIELD_SUBSCREEN_UpdateMenu(u32 *p)
{
    INFOWIN_Update(FIELD_MENU_Update((struct Obj *)p[8]));
}
