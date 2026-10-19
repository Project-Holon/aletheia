/*
 * function: WORLDTRADE_SUBLCD_StartAnimTaskB
 * address: 0x021FF9E0
 * packet: pkt_ov135_021FF9E0
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02030DA8 0x02030DA8 arm
 *   TCBL_IsDeletePending 0x02030EE8 arm
 *   WORLDTRADE_SUBLCD_AnimTaskB 0x021FFA3C thumb ov135
 *   WORLDTRADE_SUBLCD_SetActorAnim 0x021FF914 thumb ov135
 *   str_02203E44 0x02203E44 data a1
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */
#include "../include/Obj04530.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { int state; int y; u8 *p; } Anim;
extern const char str_02203E44[];
typedef unsigned short u16;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_02030DA8(void *, void (*)(void *, Anim *), void *, int);
struct S02030EE8;
extern u32 TCBL_IsDeletePending(struct S02030EE8 *p);
extern void WORLDTRADE_SUBLCD_AnimTaskB(void *, Anim *);
extern void WORLDTRADE_SUBLCD_SetActorAnim(u32 *p, u32 v);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
void WORLDTRADE_SUBLCD_StartAnimTaskB(u8 *p)
{
    Anim *a;
    ((struct Obj04530 *)p)->fF98 = func_02030734(0x48, 12, 0, str_02203E44, 0x150);
    ((struct Obj04530 *)p)->fE14 = func_02030DA8(((struct Obj04530 *)p)->fF94, WORLDTRADE_SUBLCD_AnimTaskB, ((struct Obj04530 *)p)->fF98, 5);
    a = (Anim *)TCBL_IsDeletePending(((struct Obj04530 *)p)->fE14);
    a->state = 0;
    a->y = 0x8A;
    a->p = p;
    WORLDTRADE_SUBLCD_SetActorAnim((u32 *)a, 5);
    GFL_USE_PlaySeDefaultVolume(0x55D);
}
