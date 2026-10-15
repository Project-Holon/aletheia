/*
 * function: DUP_FITTING_FreeHeldElem
 * address: 0x021B7A18
 * packet: pkt_ov133_021B7A18
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DUP_FITTING_ITEM_ListGetHead 0x021BA184 thumb ov133
 *   DUP_FITTING_ITEM_ElemGetData 0x021BA20C thumb ov133
 *   DUP_FITTING_ITEM_ElemGetRenderElem 0x021BA218 thumb ov133
 *   DUP_FITTING_ITEM_ElemGetNext 0x021BA208 thumb ov133
 *   MUSICAL_MCSS_FreeElemImage 0x021F4D74 thumb ov112
 */
#include "../include/Obj00004.h"
#include "../include/Obj06496.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void *DUP_FITTING_ITEM_ListGetHead(char *p);
typedef unsigned int   u32;
extern u32 DUP_FITTING_ITEM_ElemGetData(u8 *p);
extern u32 DUP_FITTING_ITEM_ElemGetRenderElem(u8 *p);
extern u32 DUP_FITTING_ITEM_ElemGetNext(u8 *p);
extern void MUSICAL_MCSS_FreeElemImage(u8 *, u8 *, int, u16);
void DUP_FITTING_FreeHeldElem(u8 *p)
{
    u8 *e = DUP_FITTING_ITEM_ListGetHead(((struct Obj00004 *)p)->f181C);
    u8 *q;
    u8 *s;
    while (e) {
        q = (u8 *)DUP_FITTING_ITEM_ElemGetData(e);
        s = (u8 *)DUP_FITTING_ITEM_ElemGetRenderElem(e);
        if (((struct Obj06496 *)q)->fC == 1)
            MUSICAL_MCSS_FreeElemImage(*(u8 **)(p + 0x1884), s, ((struct Obj06496 *)q)->f0, ((struct Obj06496 *)q)->f8);
        else
            MUSICAL_MCSS_FreeElemImage(*(u8 * *)&((struct Obj00004 *)p)->f1884, s, ((struct Obj06496 *)q)->f0, ((struct Obj06496 *)q)->f4);
        e = (u8 *)DUP_FITTING_ITEM_ElemGetNext(e);
    }
}
