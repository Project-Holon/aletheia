/*
 * function: B_PLIST_MAIN_EndSwap
 * address:  0x02211378
 * packet:   pkt_02211378
 * region:   ov198
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   B_PLIST_DRAW_PrintHeader10 0x0220C688 thumb
 *   B_PLIST_DRAW_ShowSubWindow 0x0220E27C thumb
 */
#include "../include/Obj25281.h"

typedef unsigned int   u32;
extern void BMP_MENUWORK_DrawWindowBorder(void *desc, u32 kind);
extern void B_PLIST_DRAW_PrintHeader10(char *p);
typedef unsigned char  u8;
extern void B_PLIST_DRAW_ShowSubWindow(u8 *p);

int B_PLIST_MAIN_EndSwap(char *p)
{
    BMP_MENUWORK_DrawWindowBorder(((struct Obj25281 *)p)->f1F68, 0);
    B_PLIST_DRAW_PrintHeader10(p);
    B_PLIST_DRAW_ShowSubWindow((u8 *)p);
    return 8;
}
