/*
 * function: ZUKAN_LIST_DrawHeaderNational
 * address: 0x021BD704
 * packet: pkt_ov209_021BD704
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ZUKAN_LIST_ClearWindow 0x021BD4F4 thumb ov209
 *   ZUKAN_LIST_PrintTouchbarLabel 0x021BD440 thumb ov209
 *   ZUKAN_LIST_PrintTouchbarLabelClone 0x021BD488 thumb ov209
 *   ZUKAN_LIST_MakeWindowScreens 0x021BD4DC thumb ov209
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 */
#include "../include/Obj00123.h"
#include "../include/Obj25566.h"
struct WordSet;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void ZUKAN_LIST_ClearWindow(u8 *p, u32 idx);
extern void ZUKAN_LIST_PrintTouchbarLabel(char *, unsigned, unsigned, unsigned, unsigned, unsigned short, unsigned);
extern void ZUKAN_LIST_PrintTouchbarLabelClone(char *, unsigned, unsigned, unsigned, unsigned, unsigned short, unsigned);
extern void ZUKAN_LIST_MakeWindowScreens(void **p);
extern void WORDSET_SetSlotNumber(struct WordSet *, unsigned, unsigned, unsigned, unsigned, unsigned);
void ZUKAN_LIST_DrawHeaderNational(char *p)
{
    ZUKAN_LIST_ClearWindow((u8 *)p, 2);
    ZUKAN_LIST_PrintTouchbarLabel(p, 2, 4, 88, 4, 0x31a0, 1);
    WORDSET_SetSlotNumber(*(struct WordSet * *)&((struct Obj00123 *)p)->f40, 0, ((struct Obj25566 *)(*(char * *)&((struct Obj00123 *)p)->f0))->fA, 3, 0, 1);
    ZUKAN_LIST_PrintTouchbarLabelClone(p, 2, 5, 120, 4, 0x31a0, 1);
    ZUKAN_LIST_MakeWindowScreens((void **)(p + 48));
}
