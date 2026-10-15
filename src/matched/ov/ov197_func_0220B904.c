/*
 * function: B_BAG_MAIN_PrintItemMsg
 * address:  0x0220B904
 * packet:   pkt_0220B904
 * region:   ov197
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   B_BAG_MAIN_StartItemMsg 0x0220B928 thumb
 */
#include "../include/Obj14543.h"

extern void BMP_MENUWORK_DrawWindow(void *, int, int, int);
typedef unsigned char  u8;
struct CharBuf;
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void B_BAG_MAIN_StartItemMsg(char *p);

void B_BAG_MAIN_PrintItemMsg(char *p)
{
    BMP_MENUWORK_DrawWindow(((struct Obj14543 *)p)->f24, 2, 1, 0xb);
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj14543 *)p)->f24), 0xf);
    B_BAG_MAIN_StartItemMsg(p);
}
