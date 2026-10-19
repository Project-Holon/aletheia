/*
 * function: BOX2_MAIN_StateMachineShowHandScroll
 * address: 0x021E0A40
 * packet: pkt_ov170_021E0A40
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_SEQ_SetActorAffineMode 0x021ED108 thumb ov170
 *   BOX2_SEQ_SetActorAnimSeq 0x021EBFA8 thumb ov170
 *   BOX2_SEQ_SetActorDrawEnable 0x021EC000 thumb ov170
 *   BOX2_MAIN_SceneApplyScroll 0x021E066C thumb ov170
 *   BOX2_UI_UpdateListPacks 0x021EF5C4 thumb ov170
 *   BOX2_SEQ_ShowHandSlots 0x021ED2F4 thumb ov170
 */
#include "../include/Obj10651.h"
struct WinMgr;
extern void BOX2_SEQ_SetActorAffineMode(char *w, int on);
extern void BOX2_SEQ_SetActorAnimSeq(char *w, int i, int v);
extern void BOX2_SEQ_SetActorDrawEnable(char *w, int i, int v);
extern int BOX2_MAIN_SceneApplyScroll(char *p);
extern int BOX2_UI_UpdateListPacks(struct WinMgr *mgr);
extern void BOX2_SEQ_ShowHandSlots(char *w);
#define WORK(p) (*(char **)((p) + 0x2C))
int BOX2_MAIN_StateMachineShowHandScroll(char *p)
{
    char *s;
    int a;
    int b;
    s = WORK(p) + 0x58;
    switch (((struct Obj10651 *)s)->fC) {
    case 0:
        if (*(unsigned short *)(WORK(p) + 0xA16C)) {
            BOX2_SEQ_SetActorAffineMode(WORK(p), 1);
            BOX2_SEQ_SetActorAnimSeq(WORK(p), 10, 1);
            BOX2_SEQ_SetActorDrawEnable(WORK(p), 10, 1);
        }
        (((struct Obj10651 *)s)->fC)++;
    case 1:
        a = BOX2_MAIN_SceneApplyScroll(p);
        b = BOX2_UI_UpdateListPacks(*(struct WinMgr **)(WORK(p) + 0x74));
        if (a == 0 && b == 0) {
            if (*(unsigned short *)(WORK(p) + 0xA16C)) {
                BOX2_SEQ_SetActorAffineMode(WORK(p), 0);
                BOX2_SEQ_ShowHandSlots(WORK(p));
            }
            ((struct Obj10651 *)s)->fC = 0;
            return 0;
        }
        break;
    }
    return 1;
}
