/*
 * function: GSYNC_MESSAGE_ClearWindow
 * address:  0x021D5A60
 * packet:   pkt_021D5A60
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BMP_MENUWORK_DrawWindowBorder  0x0201F7A8  thumb
 *   BMP_WIN_ClearScreen  0x020456F8  arm
 *   func_02041B6C  0x02041B6C  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj13973.h"

typedef unsigned int u32;

struct Descriptor;
extern void BMP_MENUWORK_DrawWindowBorder(void *desc, u32 kind);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern void func_02041B6C(u32 bit);

void GSYNC_MESSAGE_ClearWindow(char *p)
{
    BMP_MENUWORK_DrawWindowBorder(((struct Obj13973 *)p)->f48, 2);
    BMP_WIN_ClearScreen(((struct Obj13973 *)p)->f48);
    func_02041B6C(6);
}
