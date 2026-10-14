/*
 * function: WORLDTRADE_SUBLCD_StartAnimTaskA
 * address: 0x021FF8B0
 * packet: pkt_ov135_021FF8B0
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORLDTRADE_SUBLCD_CreateActors 0x021FF6A4 thumb ov135
 *   func_02030734 0x02030734 arm
 *   func_02030DA8 0x02030DA8 arm
 *   TCBL_GetTaskUserData 0x02030EE8 arm
 *   WORLDTRADE_SUBLCD_AnimTaskA 0x021FF92C thumb ov135
 *   WORLDTRADE_SUBLCD_SetActorAnim 0x021FF914 thumb ov135
 *   str_02203E44 0x02203E44 data a1
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */
#include "../include/Obj05419.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int state; int y; u8 *p; } Anim;
extern const char str_02203E44[];
extern void WORLDTRADE_SUBLCD_CreateActors(u8 *);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_02030DA8(void *, void (*)(void *, Anim *), void *, int);
struct S02030EE8;
extern u32 TCBL_GetTaskUserData(struct S02030EE8 *p);
extern void WORLDTRADE_SUBLCD_AnimTaskA(void *, Anim *);
extern void WORLDTRADE_SUBLCD_SetActorAnim(u32 *p, u32 v);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
void WORLDTRADE_SUBLCD_StartAnimTaskA(u8 *p)
{
    Anim *a;
    WORLDTRADE_SUBLCD_CreateActors(p);
    ((struct Obj05419 *)p)->fF98 = func_02030734(0x48, 12, 0, str_02203E44, 0xD4);
    ((struct Obj05419 *)p)->fE14 = func_02030DA8(((struct Obj05419 *)p)->fF94, WORLDTRADE_SUBLCD_AnimTaskA, ((struct Obj05419 *)p)->fF98, 5);
    a = (Anim *)TCBL_GetTaskUserData(((struct Obj05419 *)p)->fE14);
    a->state = 0;
    a->y = -40;
    a->p = p;
    ((struct Obj05419 *)p)->fE18 = 0;
    WORLDTRADE_SUBLCD_SetActorAnim((u32 *)a, 0);
    GFL_USE_PlaySeDefaultVolume(0x790);
}
