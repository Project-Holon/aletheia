/*
 * function: BOX2_SEQ_StateSwapMenuC
 * address: 0x021E7904
 * packet: pkt_ov170_021E7904
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_SEQ_SetCursorDraw 0x021ED55C thumb ov170
 *   BOX2_UI_OpenListPack 0x021EF57C thumb ov170
 *   BOX2_SEQ_SetSeqThird 0x021E8FC0 thumb ov170
 *   BOX2_MAIN_IsWindowMoving 0x021E0190 thumb ov170
 *   BOX2_MAIN_GetPartyValueAt 0x021DD25C thumb ov170
 *   BOX2_SEQ_PrintMenuRow 0x021EBD1C thumb ov170
 *   BOX2_SEQ_ReturnAfterClear 0x021E8F50 thumb ov170
 *   BOX2_MAIN_GetBoxValue 0x021DD908 thumb ov170
 *   BOX2_SEQ_SetSlotActors 0x021ECB20 thumb ov170
 *   BOX2_SEQ_SetSlotActorMode 0x021ECB60 thumb ov170
 *   BOX2_SEQ_PrintBoxMonName 0x021EBD50 thumb ov170
 *   BOX2_SEQ_OpenYesNo 0x021E8FE8 thumb ov170
 */
#include "../include/Obj00000.h"
struct WinMgr;
extern void BOX2_SEQ_SetCursorDraw(char **p, int flag);
extern void BOX2_UI_OpenListPack(struct WinMgr *mgr);
extern int BOX2_SEQ_SetSeqThird(char *p, int a, int b);
extern int BOX2_MAIN_IsWindowMoving(char *p);
extern unsigned BOX2_MAIN_GetPartyValueAt(void ***p, unsigned short a, int box, unsigned id, unsigned v);
extern void BOX2_SEQ_PrintMenuRow(char *p, int row, int b);
extern int BOX2_SEQ_ReturnAfterClear(char *p, int v);
typedef unsigned int   u32;
extern int BOX2_MAIN_GetBoxValue(char *p, u32 a);
extern void BOX2_SEQ_SetSlotActors(char *p, int f, int c);
extern void BOX2_SEQ_SetSlotActorMode(char *w, int i, int f);
extern void BOX2_SEQ_PrintBoxMonName(unsigned char *p);
extern int BOX2_SEQ_OpenYesNo(unsigned char *p, int sel);
#define WORK(p) (*(char **)((p) + 0x2C))
#define STEP(p) (*(int *)(WORK(p) + 0xA194))
int BOX2_SEQ_StateSwapMenuC(unsigned char *p)
{
    switch (STEP(p)) {
    case 0:
        BOX2_SEQ_SetCursorDraw((char **)p, 0);
        BOX2_UI_OpenListPack(*(struct WinMgr **)(WORK(p) + 0x74));
        STEP(p)++;
        return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_MAIN_IsWindowMoving, 0x4D);
    case 1:
        if (BOX2_MAIN_GetPartyValueAt((void ***)p, p[0x16], p[0x14], 0x4C, 0) != 0) {
            BOX2_SEQ_PrintMenuRow((char *)p, 4, 0x18);
            ((struct Obj00000 *)p)->f28 = 0xE;
            return BOX2_SEQ_ReturnAfterClear((char *)p, 6);
        }
        if (BOX2_MAIN_GetBoxValue((char *)p, p[0x16]) == 0) {
            BOX2_SEQ_PrintMenuRow((char *)p, 6, 0x1B);
            ((struct Obj00000 *)p)->f28 = 0xE;
            return BOX2_SEQ_ReturnAfterClear((char *)p, 6);
        }
        BOX2_SEQ_SetSlotActors((char *)p, 1, 1);
        BOX2_SEQ_SetSlotActorMode(WORK(p), p[0x16], 0);
        BOX2_SEQ_PrintBoxMonName(p);
        STEP(p) = 0;
        return BOX2_SEQ_OpenYesNo(p, 5);
    }
    return 0x4D;
}
