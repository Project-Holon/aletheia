/*
 * function: DUP_FITTING_ResetSlots
 * address: 0x021B94C0
 * packet: pkt_ov133_021B94C0
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DUP_FITTING_ITEM_ListGetHead 0x021BA184 thumb ov133
 *   DUP_FITTING_ITEM_ElemGetFrameIndex 0x021BA258 thumb ov133
 *   DUP_FITTING_ITEM_ElemGetRenderElem 0x021BA218 thumb ov133
 *   DUP_FITTING_ITEM_ElemGetNext 0x021BA208 thumb ov133
 *   MUSICAL_MCSS_GetRenderElem 0x021F5450 thumb ov112
 *   MUSICAL_MCSS_SetElemField 0x021F4ED4 thumb ov112
 */
#include "../include/Obj00004.h"
#include "../include/Obj23319.h"
#include "../include/Obj23320.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void *DUP_FITTING_ITEM_ListGetHead(char *p);
extern unsigned int DUP_FITTING_ITEM_ElemGetFrameIndex(char *p);
typedef unsigned int   u32;
extern u32 DUP_FITTING_ITEM_ElemGetRenderElem(u8 *p);
extern u32 DUP_FITTING_ITEM_ElemGetNext(u8 *p);
extern u8 *MUSICAL_MCSS_GetRenderElem(u8 *, int);
extern void MUSICAL_MCSS_SetElemField(u32 unused, u32 p, u16 v);
void DUP_FITTING_ResetSlots(u8 *p)
{
    u8 i;
    u8 *e, *q;
    u16 index;
    for (i = 0; i < 9; i++)
        *(u16 *)(*(u8 * *)&((struct Obj23319 *)(*(u8 * *)&((struct Obj00004 *)p)->f4))->f4 + 0x16 + i * 6) = 0;
    e = DUP_FITTING_ITEM_ListGetHead(((struct Obj00004 *)p)->f1824);
    while (e) {
        index = DUP_FITTING_ITEM_ElemGetFrameIndex((char *)e);
        q = MUSICAL_MCSS_GetRenderElem(*(u8 * *)&((struct Obj00004 *)p)->f1880, index);
        MUSICAL_MCSS_SetElemField((u32)(((struct Obj00004 *)p)->f1884), DUP_FITTING_ITEM_ElemGetRenderElem(e), ((struct Obj23320 *)q)->f36);
        e = (u8 *)DUP_FITTING_ITEM_ElemGetNext(e);
    }
}
