/*
 * function: DUP_FITTING_ReleaseElem
 * address: 0x021B8254
 * packet: pkt_ov133_021B8254
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DUP_FITTING_ITEM_ElemGetRenderElem 0x021BA218 thumb ov133
 *   DUP_FITTING_ITEM_RemoveElem 0x021BA148 thumb ov133
 *   DUP_FITTING_ITEM_InsertElemTail 0x021BA124 thumb ov133
 *   DUP_FITTING_ITEM_ListGetHead 0x021BA184 thumb ov133
 *   DUP_FITTING_ITEM_ElemGetNext 0x021BA208 thumb ov133
 *   MUSICAL_MCSS_SetElemRotZ 0x021F4EB4 thumb ov112
 *   MUSICAL_MCSS_SetElemScale 0x021F4EA4 thumb ov112
 *   MUSICAL_MCSS_SetElemPos 0x021F4E8C thumb ov112
 */
#include "../include/Obj00004.h"
typedef unsigned char u8;
typedef struct { int x,y,z; } Vec;
extern unsigned int DUP_FITTING_ITEM_ElemGetRenderElem(u8 *p);
typedef signed short   s16;
typedef unsigned int   u32;
extern void DUP_FITTING_ITEM_RemoveElem(u8 *p, u8 *q);
extern void DUP_FITTING_ITEM_InsertElemTail(u8 *p, u8 *q);
extern void *DUP_FITTING_ITEM_ListGetHead(char *p);
extern u32 DUP_FITTING_ITEM_ElemGetNext(u8 *p);
extern void MUSICAL_MCSS_SetElemRotZ(u32 unused, u32 p, s16 a, s16 b);
extern void MUSICAL_MCSS_SetElemScale(u32 unused, u32 p, u32 q);
extern void MUSICAL_MCSS_SetElemPos(int, int, Vec *);
void DUP_FITTING_ReleaseElem(u8 *p)
{
    Vec v;
    u8 *e, *s;
    int z = 0xa000;
    s = (u8 *)DUP_FITTING_ITEM_ElemGetRenderElem(*(u8 * *)&((struct Obj00004 *)p)->f38);
    DUP_FITTING_ITEM_RemoveElem(((struct Obj00004 *)p)->f1820, *(u8 * *)&((struct Obj00004 *)p)->f38);
    DUP_FITTING_ITEM_InsertElemTail(((struct Obj00004 *)p)->f1820, *(u8 * *)&((struct Obj00004 *)p)->f38);
    MUSICAL_MCSS_SetElemRotZ(*(int *)&((struct Obj00004 *)p)->f1884, (int)s, 4096, 4096);
    e = DUP_FITTING_ITEM_ListGetHead(((struct Obj00004 *)p)->f1820);
    while (e) {
        s = (u8 *)DUP_FITTING_ITEM_ElemGetRenderElem(e);
        MUSICAL_MCSS_SetElemScale(*(int *)(p + 0x1884), (int)s, (u32)(&v));
        v.z = z;
        MUSICAL_MCSS_SetElemPos(*(int *)(p + 0x1884), (int)s, &v);
        z -= 1024;
        e = (u8 *)DUP_FITTING_ITEM_ElemGetNext(e);
    }
}
