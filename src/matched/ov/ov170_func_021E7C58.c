/*
 * function: BOX2_SEQ_StateSwapFinishB
 * address: 0x021E7C58
 * packet: pkt_ov170_021E7C58
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_MAIN_ResetBoxView 0x021DF040 thumb ov170
 *   BOX2_UI_MoveCursor 0x021EE364 thumb ov170
 *   BOX2_UI_ShowWindowA 0x021EF670 thumb ov170
 *   BOX2_SEQ_SetSlotActors 0x021ECB20 thumb ov170
 *   BOX2_SEQ_StateWaitPrint 0x021E22B8 thumb ov170
 */
#include "../include/Obj00000.h"
#include "../include/Obj23913.h"
extern void BOX2_MAIN_ResetBoxView(char *p);
extern void BOX2_UI_MoveCursor(char **p, int idx, int v);
extern void BOX2_UI_ShowWindowA(char *w);
extern void BOX2_SEQ_SetSlotActors(char *p, int f, int c);
extern int BOX2_SEQ_StateWaitPrint(int p);
#define WORK(p) (*(char **)((p) + 0x2C))
#define STEP(p) (*(int *)(WORK(p) + 0xA194))
int BOX2_SEQ_StateSwapFinishB(unsigned char *p)
{
    BOX2_MAIN_ResetBoxView((char *)p);
    switch (((struct Obj23913 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f24) {
    case 1:
        BOX2_UI_MoveCursor((char **)p, 2, 0x1E);
        *(int *)(WORK(p) + 0xA168) = 0x1E;
        *(int *)(WORK(p) + 0xA198) = 0x2C;
        break;
    case 2:
        BOX2_UI_ShowWindowA(WORK(p));
        BOX2_UI_MoveCursor((char **)p, 3, 0x1E);
        *(int *)(WORK(p) + 0xA168) = 0x1E;
        *(int *)(WORK(p) + 0xA198) = 0x11;
        break;
    case 3:
        BOX2_SEQ_SetSlotActors((char *)p, 0x81, 1);
        BOX2_UI_ShowWindowA(WORK(p));
        BOX2_UI_MoveCursor((char **)p, 7, 0x1E);
        *(int *)(WORK(p) + 0xA168) = 0x1E;
        *(int *)(WORK(p) + 0xA198) = 0x39;
        break;
    case 4:
        BOX2_UI_ShowWindowA(WORK(p));
        BOX2_UI_MoveCursor((char **)p, 0xD, 0x1E);
        *(int *)(WORK(p) + 0xA168) = 0x1E;
        *(int *)(WORK(p) + 0xA198) = 0x23;
        break;
    case 0:
        break;
    }
    return BOX2_SEQ_StateWaitPrint((int)p);
}
