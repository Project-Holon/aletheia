/*
 * function: BOX2_SEQ_StateUseItem
 * address: 0x021E9010
 * packet: pkt_ov170_021E9010
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_MAIN_GetPartyValueAt 0x021DD25C thumb ov170
 *   func_02007E50 0x02007E50 thumb
 *   BOX2_MAIN_GetMonAt 0x021DD2D0 thumb ov170
 *   BOX2_SEQ_PrintWordsetB 0x021EBB34 thumb ov170
 *   BOX2_MAIN_SetBoxValueAt 0x021DD2B4 thumb ov170
 *   BOX2_MAIN_CanPlaceInBox 0x021DD718 thumb ov170
 *   BOX2_MAIN_RecalcPartyParam 0x021DD8A8 thumb ov170
 *   BOX2_SEQ_ShowSlotIcon 0x021EC48C thumb ov170
 *   BOX2_MAIN_SetBoxForm 0x021DEFF8 thumb ov170
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BOX2_SEQ_PrintMessageD 0x021EBB58 thumb ov170
 *   func_020355C4 0x020355C4 arm
 *   CURSOR_MOVE_SetState 0x020260F4 thumb
 *   BOX2_SEQ_SetCursorDraw 0x021ED55C thumb ov170
 *   BOX2_SEQ_ReturnAfterClear 0x021E8F50 thumb ov170
 */
#include "../include/Obj00000.h"
#include "../include/Obj23942.h"
extern unsigned BOX2_MAIN_GetPartyValueAt(void ***p, unsigned short a, int box, unsigned id, unsigned v);
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Struct_02025CD0;
extern u32 func_02007E50(u8 *base, u16 id, u16 qty, u16 d);
extern int BOX2_MAIN_GetMonAt(void ***p, int a, unsigned b);
extern void BOX2_SEQ_PrintWordsetB(char *p, int a, int b);
extern void BOX2_MAIN_SetBoxValueAt(int a, int b, int c, int d, int e);
extern int BOX2_MAIN_CanPlaceInBox(void **pp, void *mon);
extern void BOX2_MAIN_RecalcPartyParam(void **pp, u32 idx);
extern void BOX2_SEQ_ShowSlotIcon(unsigned char *p, int box, int pos, int win);
extern void BOX2_MAIN_SetBoxForm(char *p, unsigned b);
extern void GFL_USE_PlaySeDefaultVolume(unsigned se);
extern void BOX2_SEQ_PrintMessageD(char *p, int b);
extern u8 func_020355C4(void);
extern void CURSOR_MOVE_SetState(struct Struct_02025CD0 *obj, u32 state);
extern void BOX2_SEQ_SetCursorDraw(char **p, int flag);
extern int BOX2_SEQ_ReturnAfterClear(char *p, int v);
#define WORK(p) (*(char **)((p) + 0x2C))
int BOX2_SEQ_StateUseItem(unsigned char *p)
{
    unsigned item;
    void *mon;
    item = BOX2_MAIN_GetPartyValueAt((void ***)p, p[0x16], p[0x14], 6, 0);
    if (func_02007E50(((struct Obj23942 *)(*(char * *)&((struct Obj00000 *)p)->f0))->fC, item, 1, 0x4C) == 1) {
        mon = (void *)BOX2_MAIN_GetMonAt((void ***)p, p[0x14], p[0x16]);
        BOX2_SEQ_PrintWordsetB((char *)p, item, 0x18);
        BOX2_MAIN_SetBoxValueAt((int)p, p[0x16], p[0x14], 6, 0);
        if (BOX2_MAIN_CanPlaceInBox((void **)p, mon) == 1) {
            BOX2_MAIN_RecalcPartyParam((void **)p, p[0x16]);
            BOX2_SEQ_ShowSlotIcon(p, p[0x14], p[0x16], *(unsigned char *)(WORK(p) + p[0x16] + 0x3DD2));
        }
        BOX2_MAIN_SetBoxForm((char *)p, p[0x16]);
    } else {
        GFL_USE_PlaySeDefaultVolume(0x557);
        BOX2_SEQ_PrintMessageD((char *)p, 0x18);
    }
    if (func_020355C4() == 1) {
        CURSOR_MOVE_SetState(*(void **)(WORK(p) + 0x70), 0);
    } else {
        CURSOR_MOVE_SetState(*(void **)(WORK(p) + 0x70), 1);
        BOX2_SEQ_SetCursorDraw((char **)p, 0);
    }
    ((struct Obj00000 *)p)->f28 = 0xE;
    return BOX2_SEQ_ReturnAfterClear((char *)p, 6);
}
