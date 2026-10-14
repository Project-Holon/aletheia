/*
 * function: WORLDTRADE_SUBLCD_AnimTaskA
 * address: 0x021FF92C
 * packet: pkt_ov135_021FF92C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORLDTRADE_SUBLCD_SetActorAnim 0x021FF914 thumb ov135
 *   WORLDTRADE_SUBLCD_SetActorSurfacePos 0x021FFAEC thumb ov135
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   func_020307B0 0x020307B0 arm
 *   func_02030EAC 0x02030EAC arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */
#include "../include/Obj10589.h"
#include "../include/Obj23436.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int state; int y; u8 *p; } Anim;
extern void WORLDTRADE_SUBLCD_SetActorAnim(u32 *p, u32 v);
extern void WORLDTRADE_SUBLCD_SetActorSurfacePos(u32, int, int);
struct Actor;
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern u32 func_020307B0(void *p);
struct Node;
extern void func_02030EAC(struct Node *n);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
void WORLDTRADE_SUBLCD_AnimTaskA(void *task, Anim *a)
{
    u8 *p;
    p = a->p;
    switch (a->state) {
    case 0:
        if (a->y > 160) {
            a->y = 160;
            a->state = 1;
            WORLDTRADE_SUBLCD_SetActorAnim((u32 *)a, 1);
        }
        a->y += 2;
        WORLDTRADE_SUBLCD_SetActorSurfacePos(((struct Obj10589 *)p)->fD0C, 128, a->y);
        break;
    case 1:
        if (CLACT_IsActorAnimActive((struct Actor *)(((struct Obj10589 *)p)->fD0C)) == 0) {
            WORLDTRADE_SUBLCD_SetActorAnim((u32 *)a, 2);
            a->state = 2;
        }
        break;
    case 2:
        if (a->y <= 138) {
            a->y = 138;
            a->state = 3;
            WORLDTRADE_SUBLCD_SetActorAnim((u32 *)a, 3);
        } else {
            a->y--;
        }
        WORLDTRADE_SUBLCD_SetActorSurfacePos(((struct Obj10589 *)p)->fD0C, 128, a->y);
        break;
    case 3:
        GFL_USE_PlaySeDefaultVolume(0x55C);
        ((struct Obj23436 *)(a->p))->fE18 = 1;
        func_020307B0(a);
        func_02030EAC(task);
        break;
    }
}
