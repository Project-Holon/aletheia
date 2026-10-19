/*
 * function: BOX2_MAIN_StateMachineHideHandWindow
 * address: 0x021E0ED4
 * packet: pkt_ov170_021E0ED4
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_SEQ_GetActorDrawEnable 0x021EC01C thumb ov170
 *   BOX2_SEQ_IsActorAnimActive 0x021EBFEC thumb ov170
 *   BOX2_SEQ_SetActorAffineMode 0x021ED108 thumb ov170
 *   BOX2_SEQ_SetActorAnimSeq 0x021EBFA8 thumb ov170
 *   BOX2_SEQ_SetActorDrawEnable 0x021EC000 thumb ov170
 *   BOX2_MAIN_IsWindowMoving 0x021E0190 thumb ov170
 */
#include "../include/Obj08236.h"
typedef unsigned int   u32;
extern u32 BOX2_SEQ_GetActorDrawEnable(char *p, int i);
extern u32 BOX2_SEQ_IsActorAnimActive(char *p, int i);
extern void BOX2_SEQ_SetActorAffineMode(char *, int);
extern void BOX2_SEQ_SetActorAnimSeq(char *, int, int);
extern void BOX2_SEQ_SetActorDrawEnable(char *, int, int);
extern int BOX2_MAIN_IsWindowMoving(char *p);
#define W(p) (*(char **)((p) + 0x2C))
int BOX2_MAIN_StateMachineHideHandWindow(unsigned char *p)
{
    char *b = W(p) + 0x58;
    switch (((struct Obj08236 *)b)->fC) {
    case 0:
        if (BOX2_SEQ_GetActorDrawEnable(W(p), 10) == 1) {
            BOX2_SEQ_SetActorAffineMode(W(p), 1);
            BOX2_SEQ_SetActorAnimSeq(W(p), 10, 2);
        }
        (((struct Obj08236 *)b)->fC)++;
        /* fall through */
    case 1:
        if (!BOX2_MAIN_IsWindowMoving((char *)p))
            (((struct Obj08236 *)b)->fC)++;
        break;
    case 2:
        if (BOX2_SEQ_GetActorDrawEnable(W(p), 10) == 1) {
            BOX2_SEQ_SetActorAffineMode(W(p), 0);
            BOX2_SEQ_SetActorDrawEnable(W(p), 10, 0);
        }
        ((struct Obj08236 *)b)->fC = 0;
        return 0;
    }
    return 1;
}
