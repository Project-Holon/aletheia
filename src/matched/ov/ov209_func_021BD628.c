/*
 * function: ZUKAN_LIST_DrawHeaderCounts
 * address: 0x021BD628
 * packet: pkt_ov209_021BD628
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ZUKAN_SAVE_GetViewMode 0x0200CA70 thumb
 *   ZUKAN_SAVE_CountSeenNational 0x0200D0CC thumb
 *   ZUKAN_SAVE_CountCaughtNational 0x0200CF28 thumb
 *   ZUKAN_SAVE_CountSeenRegional 0x0200D0F8 thumb
 *   ZUKAN_SAVE_CountCaughtRegional 0x0200CF54 thumb
 *   ZUKAN_LIST_ClearWindow 0x021BD4F4 thumb ov209
 *   ZUKAN_LIST_PrintTouchbarLabel 0x021BD440 thumb ov209
 *   ZUKAN_LIST_PrintTouchbarLabelClone 0x021BD488 thumb ov209
 *   ZUKAN_LIST_MakeWindowScreens 0x021BD4DC thumb ov209
 *   func_0201EFA4 0x0201EFA4 thumb
 */
#include "../include/Obj00123.h"
#include "../include/Obj25561.h"
#include "../include/Obj25562.h"
#include "../include/Obj25563.h"
#include "../include/Obj25564.h"
#include "../include/Obj25565.h"
typedef unsigned short u16;
typedef struct WordSet WordSet;
typedef unsigned int   u32;
struct Blk37;
extern u32 ZUKAN_SAVE_GetViewMode(struct Blk37 *p);
extern u16 ZUKAN_SAVE_CountSeenNational(struct Blk37 *p);
extern u16 ZUKAN_SAVE_CountCaughtNational(struct Blk37 *p);
extern u16 ZUKAN_SAVE_CountSeenRegional(struct Blk37 *p, u32 heap);
extern u16 ZUKAN_SAVE_CountCaughtRegional(struct Blk37 *p, u32 heap);
typedef unsigned char  u8;
extern void ZUKAN_LIST_ClearWindow(u8 *p, u32 idx);
extern void ZUKAN_LIST_PrintTouchbarLabel(char *, unsigned, unsigned, unsigned, unsigned, u16, unsigned);
extern void ZUKAN_LIST_PrintTouchbarLabelClone(char *, unsigned, unsigned, unsigned, unsigned, u16, unsigned);
extern void ZUKAN_LIST_MakeWindowScreens(void **p);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
void ZUKAN_LIST_DrawHeaderCounts(char *p)
{
    unsigned a, b;
    if (ZUKAN_SAVE_GetViewMode(((struct Obj25561 *)(*(char * *)&((struct Obj00123 *)p)->f0))->f4) == 1) {
        a = ZUKAN_SAVE_CountSeenNational(((struct Obj25562 *)(*(char * *)&((struct Obj00123 *)p)->f0))->f4);
        b = ZUKAN_SAVE_CountCaughtNational(((struct Obj25563 *)(*(char * *)&((struct Obj00123 *)p)->f0))->f4);
    } else {
        a = ZUKAN_SAVE_CountSeenRegional(((struct Obj25564 *)(*(char * *)&((struct Obj00123 *)p)->f0))->f4, 0x806b);
        b = ZUKAN_SAVE_CountCaughtRegional(((struct Obj25565 *)(*(char * *)&((struct Obj00123 *)p)->f0))->f4, 0x806b);
    }
    ZUKAN_LIST_ClearWindow((u8 *)p, 1);
    ZUKAN_LIST_ClearWindow((u8 *)p, 2);
    ZUKAN_LIST_PrintTouchbarLabel(p, 1, 2, 0x48, 4, 0x31a0, 1);
    func_0201EFA4(*(WordSet * *)&((struct Obj00123 *)p)->f40, 0, a, 3, 0, 1);
    ZUKAN_LIST_PrintTouchbarLabelClone(p, 1, 5, 0x68, 4, 0x31a0, 1);
    ZUKAN_LIST_PrintTouchbarLabel(p, 2, 3, 0x58, 4, 0x31a0, 1);
    func_0201EFA4(*(WordSet * *)&((struct Obj00123 *)p)->f40, 0, b, 3, 0, 1);
    ZUKAN_LIST_PrintTouchbarLabelClone(p, 2, 5, 0x78, 4, 0x31a0, 1);
    ZUKAN_LIST_MakeWindowScreens((void **)(p + 0x28));
    ZUKAN_LIST_MakeWindowScreens((void **)(p + 0x30));
}
