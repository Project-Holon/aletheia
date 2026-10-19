/*
 * function: DUP_FITTING_ReturnElem
 * address: 0x021B82E8
 * packet: pkt_ov133_021B82E8
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: Named halfword call-result local fixes comparison load order.
 * symbols:
 *   DUP_FITTING_ITEM_ElemGetRenderElem 0x021BA218 thumb ov133
 *   DUP_FITTING_ITEM_ElemGetData 0x021BA20C thumb ov133
 *   DUP_FITTING_ITEM_RemoveElem 0x021BA148 thumb ov133
 *   DUP_FITTING_ITEM_InsertElemTail 0x021BA124 thumb ov133
 *   DUP_FITTING_ITEM_ElemSetBasePos 0x021BA22C thumb ov133
 *   MUSICAL_MCSS_SetElemPos 0x021F4E8C thumb ov112
 *   MUSICAL_MCSS_SetElemRotZ 0x021F4EB4 thumb ov112
 *   DUP_FITTING_ITEM_ElemSetScale 0x021BA244 thumb ov133
 *   DUP_FITTING_ITEM_ListGetHead 0x021BA184 thumb ov133
 *   DUP_FITTING_ITEM_ElemGetNext 0x021BA208 thumb ov133
 *   DUP_FITTING_ITEM_ElemGetPos 0x021BA228 thumb ov133
 *   DUP_FITTING_ITEM_ElemSetPos 0x021BA21C thumb ov133
 *   DUP_FITTING_ITEM_ElemGetScale 0x021BA248 thumb ov133
 *   DUP_FITTING_ITEM_ElemSetStartScale 0x021BA23C thumb ov133
 *   DUP_FITTING_ITEM_ElemSetAnimFrames 0x021BA24C thumb ov133
 *   DUP_FITTING_FreeHeldElem 0x021B7A18 thumb ov133
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   d_021BA588 0x021BA588 data a4
 *   d_021BA568 0x021BA568 data a4
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 */
#include "../include/Obj00004.h"
#include "../include/Obj14149.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { int x, y, z; } Vec;
typedef struct { int x, y; } Pair;
extern const Vec d_021BA588;
extern const Pair d_021BA568;
extern unsigned int DUP_FITTING_ITEM_ElemGetRenderElem(u8 *p);
extern unsigned int DUP_FITTING_ITEM_ElemGetData(u8 *p);
typedef signed short   s16;
typedef unsigned int   u32;
extern void DUP_FITTING_ITEM_RemoveElem(u8 *p, u8 *q);
extern void DUP_FITTING_ITEM_InsertElemTail(u8 *p, u8 *q);
extern void DUP_FITTING_ITEM_ElemSetBasePos(u8 *p, const u8 *src);
extern void MUSICAL_MCSS_SetElemPos(int, int, Vec *);
extern void MUSICAL_MCSS_SetElemRotZ(u32 unused, u32 p, s16 a, s16 b);
extern void DUP_FITTING_ITEM_ElemSetScale(u8 *p, u32 value);
extern void *DUP_FITTING_ITEM_ListGetHead(char *p);
extern u32 DUP_FITTING_ITEM_ElemGetNext(u8 *p);
extern u8 *DUP_FITTING_ITEM_ElemGetPos(u8 *p);
extern void DUP_FITTING_ITEM_ElemSetPos(u8 *p, const u8 *src);
extern int DUP_FITTING_ITEM_ElemGetScale(char *p);
extern void DUP_FITTING_ITEM_ElemSetStartScale(u8 *p, u32 value);
extern void DUP_FITTING_ITEM_ElemSetAnimFrames(char *p, u32 v);
extern void DUP_FITTING_FreeHeldElem(u8 *);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
void DUP_FITTING_ReturnElem(u8 *p, int unused)
{
    Vec v;
    Pair pos;
    Pair fallback;
    u8 *sprite, *data, *entry, *found;
    u16 key;
    DUP_FITTING_ITEM_ElemGetRenderElem(*(u8 * *)&((struct Obj00004 *)p)->f38);
    sprite = (u8 *)DUP_FITTING_ITEM_ElemGetRenderElem(*(u8 * *)&((struct Obj00004 *)p)->f38);
    data = (u8 *)DUP_FITTING_ITEM_ElemGetData(*(u8 * *)&((struct Obj00004 *)p)->f38);
    DUP_FITTING_ITEM_RemoveElem(((struct Obj00004 *)p)->f1820, *(u8 * *)&((struct Obj00004 *)p)->f38);
    DUP_FITTING_ITEM_InsertElemTail(((struct Obj00004 *)p)->f1828, *(u8 * *)&((struct Obj00004 *)p)->f38);
    v = d_021BA588;
    pos.x = ((struct Obj00004 *)p)->f1C;
    pos.y = *(int *)&((struct Obj00004 *)p)->f20;
    if (((struct Obj00004 *)p)->f44 > 0) v.x = (int)(0.5f + (float)(((struct Obj00004 *)p)->f44 << 12));
    else v.x = (int)((float)(((struct Obj00004 *)p)->f44 << 12) - 0.5f);
    if (((struct Obj00004 *)p)->f48 > 0) v.y = (int)(0.5f + (float)(((struct Obj00004 *)p)->f48 << 12));
    else v.y = (int)((float)(((struct Obj00004 *)p)->f48 << 12) - 0.5f);
    DUP_FITTING_ITEM_ElemSetBasePos(*(u8 * *)&((struct Obj00004 *)p)->f38, (const u8 *)(&pos));
    MUSICAL_MCSS_SetElemPos(*(int *)&((struct Obj00004 *)p)->f1884, (int)sprite, &v);
    MUSICAL_MCSS_SetElemRotZ(*(int *)&((struct Obj00004 *)p)->f1884, (int)sprite, 4096, 4096);
    DUP_FITTING_ITEM_ElemSetScale(*(u8 * *)&((struct Obj00004 *)p)->f38, 4096);
    found = 0;
    entry = DUP_FITTING_ITEM_ListGetHead(((struct Obj00004 *)p)->f181C);
    while (entry && !found) {
        key = *(u16 *)DUP_FITTING_ITEM_ElemGetData(entry);
        if (key == ((struct Obj14149 *)data)->f0) found = entry;
        entry = (u8 *)DUP_FITTING_ITEM_ElemGetNext(entry);
    }
    if (found) {
        DUP_FITTING_ITEM_ElemSetPos(*(u8 * *)&((struct Obj00004 *)p)->f38, (const u8 *)DUP_FITTING_ITEM_ElemGetPos(found));
        DUP_FITTING_ITEM_ElemSetStartScale(*(u8 * *)&((struct Obj00004 *)p)->f38, DUP_FITTING_ITEM_ElemGetScale((char *)found));
    } else {
        fallback = d_021BA568;
        DUP_FITTING_ITEM_ElemSetPos(*(u8 * *)&((struct Obj00004 *)p)->f38, (const u8 *)(&fallback));
        DUP_FITTING_ITEM_ElemSetStartScale(*(u8 * *)&((struct Obj00004 *)p)->f38, 0);
    }
    DUP_FITTING_ITEM_ElemSetAnimFrames((char *)(*(u8 * *)&((struct Obj00004 *)p)->f38), 10);
    ((struct Obj14149 *)data)->fC = 0;
    DUP_FITTING_FreeHeldElem(p);
    GFL_USE_PlaySeDefaultVolume(1574);
}
