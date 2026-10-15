/*
 * function: DUP_FITTING_PickElem
 * address: 0x021B7F00
 * packet: pkt_ov133_021B7F00
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DUP_FITTING_ITEM_ListGetHead 0x021BA184 thumb ov133
 *   DUP_FITTING_ITEM_ElemHitTest 0x021BA25C thumb ov133
 *   DUP_FITTING_ITEM_ElemGetPos 0x021BA228 thumb ov133
 *   DUP_FITTING_ITEM_ElemGetNext 0x021BA208 thumb ov133
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */
#include "../include/Obj04522.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void *DUP_FITTING_ITEM_ListGetHead(char *p);
extern int DUP_FITTING_ITEM_ElemHitTest(u8 *, int, int);
extern u8 *DUP_FITTING_ITEM_ElemGetPos(u8 *p);
extern u32 DUP_FITTING_ITEM_ElemGetNext(u8 *p);
extern void GFL_USE_PlaySeDefaultVolume(u32);
int DUP_FITTING_PickElem(u8 *p, void *q, u32 a)
{
    u8 *e = DUP_FITTING_ITEM_ListGetHead(q);
    u32 *v;
    while (e) {
        if (DUP_FITTING_ITEM_ElemHitTest(e, ((struct Obj04522 *)p)->f1C, ((struct Obj04522 *)p)->f20) == 1) {
            v = (u32 *)DUP_FITTING_ITEM_ElemGetPos(e);
            ((struct Obj04522 *)p)->f3C = 2;
            *(u8 * *)&((struct Obj04522 *)p)->f38 = e;
            GFL_USE_PlaySeDefaultVolume(0x623);
            ((struct Obj04522 *)p)->f40 = a;
            ((struct Obj04522 *)p)->f44 = v[0];
            ((struct Obj04522 *)p)->f48 = v[1];
            return 1;
        }
        e = (u8 *)DUP_FITTING_ITEM_ElemGetNext(e);
    }
    return 0;
}
