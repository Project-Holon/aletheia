/*
 * function: BOX2_MAIN_StateMachineHideHandScroll
 * address: 0x021E0E50
 * packet: pkt_ov170_021E0E50
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_SEQ_GetActorDrawEnable 0x021EC01C thumb ov170
 *   BOX2_SEQ_SetActorAffineMode 0x021ED108 thumb ov170
 *   BOX2_SEQ_SetActorAnimSeq 0x021EBFA8 thumb ov170
 *   BOX2_SEQ_SetActorDrawEnable 0x021EC000 thumb ov170
 *   BOX2_MAIN_SceneApplyScroll 0x021E066C thumb ov170
 *   BOX2_MAIN_IsWindowMoving 0x021E0190 thumb ov170
 */
#include "../include/Obj08235.h"
typedef unsigned int   u32;
extern u32 BOX2_SEQ_GetActorDrawEnable(char *p, int i);
extern void BOX2_SEQ_SetActorAffineMode(char *w, int on);
extern void BOX2_SEQ_SetActorAnimSeq(char *w, int i, int v);
extern void BOX2_SEQ_SetActorDrawEnable(char *w, int i, int v);
extern int BOX2_MAIN_SceneApplyScroll(char *p);
extern int BOX2_MAIN_IsWindowMoving(char *p);
#define WORK(p) (*(char **)((p) + 0x2C))
int BOX2_MAIN_StateMachineHideHandScroll(char *p)
{
    char *s;
    int a;
    int b;
    s = WORK(p) + 0x58;
    switch (((struct Obj08235 *)s)->fC) {
    case 0:
        if (BOX2_SEQ_GetActorDrawEnable(WORK(p), 10) == 1) {
            BOX2_SEQ_SetActorAffineMode(WORK(p), 1);
            BOX2_SEQ_SetActorAnimSeq(WORK(p), 10, 2);
        }
        (((struct Obj08235 *)s)->fC)++;
    case 1:
        a = BOX2_MAIN_SceneApplyScroll(p);
        b = BOX2_MAIN_IsWindowMoving(p);
        if (a == 0 && b == 0)
            (((struct Obj08235 *)s)->fC)++;
        break;
    case 2:
        if (BOX2_SEQ_GetActorDrawEnable(WORK(p), 10) == 1) {
            BOX2_SEQ_SetActorAffineMode(WORK(p), 0);
            BOX2_SEQ_SetActorDrawEnable(WORK(p), 10, 0);
        }
        ((struct Obj08235 *)s)->fC = 0;
        return 0;
    }
    return 1;
}
