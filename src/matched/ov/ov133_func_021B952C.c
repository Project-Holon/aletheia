/*
 * function: DUP_FITTING_HandlePickTouch
 * address: 0x021B952C
 * packet: pkt_ov133_021B952C
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   DUP_FITTING_ITEM_ListGetHead 0x021BA184 thumb ov133
 *   DUP_FITTING_ITEM_ElemHitDistance 0x021BA324 thumb ov133
 *   DUP_FITTING_ITEM_ElemGetNext 0x021BA208 thumb ov133
 *   DUP_FITTING_DragRotate 0x021B95AC thumb ov133
 */
#include "../include/Obj00004.h"
typedef unsigned char u8;
extern int TOUCHPANEL_GetTrg(void);
extern unsigned int TOUCHPANEL_GetPointCont(unsigned int *outA, unsigned int *outB);
extern void *DUP_FITTING_ITEM_ListGetHead(char *p);
extern unsigned int DUP_FITTING_ITEM_ElemHitDistance(u8 *, int, int);
typedef unsigned int   u32;
extern u32 DUP_FITTING_ITEM_ElemGetNext(u8 *p);
extern void DUP_FITTING_DragRotate(u8 *);
void DUP_FITTING_HandlePickTouch(u8 *p)
{
    u8 *e, *best;
    unsigned int distance, n;
    *(int *)&((struct Obj00004 *)p)->f24 = ((struct Obj00004 *)p)->f1C;
    *(int *)&((struct Obj00004 *)p)->f28 = *(int *)&((struct Obj00004 *)p)->f20;
    ((struct Obj00004 *)p)->f14 = TOUCHPANEL_GetTrg();
    ((struct Obj00004 *)p)->f18 = TOUCHPANEL_GetPointCont((unsigned int *)(p + 0x1c), (unsigned int *)(p + 0x20));
    if (((struct Obj00004 *)p)->f14 == 1) {
        best = 0;
        distance = 256;
        e = DUP_FITTING_ITEM_ListGetHead(((struct Obj00004 *)p)->f1824);
        while (e) {
            n = DUP_FITTING_ITEM_ElemHitDistance(e, ((struct Obj00004 *)p)->f1C, *(int *)&((struct Obj00004 *)p)->f20);
            if (distance > n) { best = e; distance = n; }
            e = (u8 *)DUP_FITTING_ITEM_ElemGetNext(e);
        }
        if (best) *(u8 * *)&((struct Obj00004 *)p)->f38 = best;
    }
    if (((struct Obj00004 *)p)->f18 == 1 && *(u8 * *)&((struct Obj00004 *)p)->f38) DUP_FITTING_DragRotate(p);
    if (((struct Obj00004 *)p)->f18 == 0) {
        ((struct Obj00004 *)p)->f30 = 0;
        *(u8 * *)&((struct Obj00004 *)p)->f38 = 0;
    }
}
