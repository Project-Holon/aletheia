/*
 * function: GSYNC_MENU_DeleteMessageWindow
 * address:  0x021D4E64
 * packet:   pkt_021D4E64
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GSYNC_MENU_HideMessage  0x021D4E34  thumb
 *   BMP_WIN_Delete  0x020452E8  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04495.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Descriptor;
extern void GSYNC_MENU_HideMessage(u8 *p);
extern u32 BMP_WIN_Delete(struct Descriptor *d);

void GSYNC_MENU_DeleteMessageWindow(u8 *p)
{
    GSYNC_MENU_HideMessage(p);
    BMP_WIN_Delete(((struct Obj04495 *)p)->f224);
    *(u32 *)&((struct Obj04495 *)p)->f224 = 0;
}
