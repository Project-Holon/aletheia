/*
 * function: ITEMMENU_StartSideButtonPress
 * address:  0x021B8C1C
 * packet:   pkt_ov070_021B8C1C
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   CLACT_SetActorAnimFrame  0x0204B8C4  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   ITEMMENU_SetTask  0x021B6100  thumb  ov070
 *   ITEMMENU_TaskWaitSideButtonPress  0x021B8CB4  thumb  ov070
 */
#include "../include/Obj00002.h"

typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
typedef unsigned short u16;
struct Obj;
extern void CLACT_SetActorAnimFrame(struct Obj *p, u32 value);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *obj, unsigned int v);
extern void ITEMMENU_SetTask(char *p, int k);
extern void ITEMMENU_TaskWaitSideButtonPress(char *p);

void ITEMMENU_StartSideButtonPress(int p, int a, int b)
{
    int x;
    if (a == 4) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        x = 9;
    } else if (a == 3) {
        GFL_USE_PlaySeDefaultVolume(0x556);
        x = 8;
    } else if (a == 1) {
        GFL_USE_PlaySeDefaultVolume(0x7D9);
        x = 0xD;
    } else if (a == 0) {
        GFL_USE_PlaySeDefaultVolume(0x7D9);
        x = 0xC;
    }
    ((struct Obj00002 *)p)->f864 = a;
    CLACT_SetActorAnimFrame((struct Obj *)(*(int *)((char *)p + ((struct Obj00002 *)p)->f864 * 4 + 0x710)), 0);
    CLACT_SetActorAnimSeq((struct Obj *)(*(int *)((char *)p + ((struct Obj00002 *)p)->f864 * 4 + 0x710)), (unsigned short)x);
    CLACT_SetActorAutoAnim((struct Obj *)*(int *)((char *)p + ((struct Obj00002 *)p)->f864 * 4 + 0x710), 1);
    *(int *)&((struct Obj00002 *)p)->f868 = b;
    ITEMMENU_SetTask((char *)p, (int)ITEMMENU_TaskWaitSideButtonPress);
}
