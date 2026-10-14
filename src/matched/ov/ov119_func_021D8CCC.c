/*
 * function: POKETRADE_PROC_BeginDrag
 * address:  0x021D8CCC
 * packet:   pkt_021D8B54
 * region:   ov119
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_GetActorSurfacePos  0x0204B454  arm
 *   TOUCHPANEL_GetPointCont  0x02035CB8  arm
 *   POKETRADE_2D_SetIconObjMode  0x021E4AB8  thumb  ov119
 *   POKETRADE_2D_CreateFloatingIconActor  0x021E64DC  thumb  ov119
 */
#include "../include/Obj00001.h"

typedef signed short s16;

struct Actor;
struct PtS;
typedef unsigned short u16;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
typedef unsigned int   u32;
extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);
extern void POKETRADE_2D_SetIconObjMode(int a0, int a1, int a2);
extern void POKETRADE_2D_CreateFloatingIconActor(int p, int i, int j, int x, int y, void *q);

void POKETRADE_PROC_BeginDrag(void *p, int x, int y, int z, int a4)
{
    int o1, o2;

    ((struct Obj00001 *)p)->fF60 = x;
    CLACT_GetActorSurfacePos((struct Actor *)x, (struct PtS *)((char *)p + 0xf64), 1);
    POKETRADE_2D_SetIconObjMode((int)p, ((struct Obj00001 *)p)->fF60, 1);
    if (TOUCHPANEL_GetPointCont((u32 *)(&o1), (u32 *)(&o2)) == 0)
        return;
    ((struct Obj00001 *)p)->fF68 = (s16)((struct Obj00001 *)p)->fF64 - o1;
    ((struct Obj00001 *)p)->fF6A = (s16)((struct Obj00001 *)p)->fF66 - o2;
    POKETRADE_2D_CreateFloatingIconActor((int)p, y, z,
                  o1 + (s16)((struct Obj00001 *)p)->fF68,
                  o2 + (s16)((struct Obj00001 *)p)->fF6A,
                  (void *)a4);
    ((struct Obj00001 *)p)->fF60 = ((struct Obj00001 *)p)->fF20;
}
