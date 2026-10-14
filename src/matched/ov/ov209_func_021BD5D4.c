/*
 * function: ZUKAN_LIST_DrawHeaderRegional
 * address: 0x021BD5D4
 * packet: pkt_ov209_021BD5D4
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ZUKAN_LIST_ClearWindow 0x021BD4F4 thumb ov209
 *   ZUKAN_SAVE_GetViewMode 0x0200CA70 thumb
 *   ZUKAN_LIST_PrintTouchbarLabel 0x021BD440 thumb ov209
 *   ZUKAN_LIST_MakeWindowScreens 0x021BD4DC thumb ov209
 */
#include "../include/Obj00123.h"
#include "../include/Obj25560.h"
typedef unsigned char  u8;
extern void ZUKAN_LIST_ClearWindow(u8 *p, unsigned int idx);
typedef unsigned int   u32;
struct Blk37;
extern u32 ZUKAN_SAVE_GetViewMode(struct Blk37 *p);
extern void ZUKAN_LIST_PrintTouchbarLabel(char *, unsigned, unsigned, unsigned, unsigned, unsigned short, unsigned);
extern void ZUKAN_LIST_MakeWindowScreens(void **p);
void ZUKAN_LIST_DrawHeaderRegional(char *p)
{
    ZUKAN_LIST_ClearWindow((u8 *)p, 0);
    if (ZUKAN_SAVE_GetViewMode(((struct Obj25560 *)(*(char * *)&((struct Obj00123 *)p)->f0))->f4) == 1)
        ZUKAN_LIST_PrintTouchbarLabel(p, 0, 1, 0, 4, 0x39e0, 0);
    else
        ZUKAN_LIST_PrintTouchbarLabel(p, 0, 0, 0, 4, 0x39e0, 0);
    ZUKAN_LIST_MakeWindowScreens((void **)(p + 32));
}
