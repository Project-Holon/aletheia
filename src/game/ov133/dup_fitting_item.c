/*
 * file:     dup_fitting_item.c
 * unit:     yes
 * function: DUP_FITTING_ITEM_NoOp, DUP_FITTING_ITEM_CreateList, DUP_FITTING_ITEM_DeleteList, DUP_FITTING_ITEM_InsertElem, DUP_FITTING_ITEM_InsertElemTail, DUP_FITTING_ITEM_RemoveElem, DUP_FITTING_ITEM_ListGetHead, DUP_FITTING_ITEM_ListGetCount, DUP_FITTING_ITEM_ListIsFull, DUP_FITTING_ITEM_CreateElem, DUP_FITTING_ITEM_DeleteElem, DUP_FITTING_ITEM_FreeElemImage, DUP_FITTING_ITEM_ElemGetNext, DUP_FITTING_ITEM_ElemGetData, DUP_FITTING_ITEM_ElemSetSprite, DUP_FITTING_ITEM_ElemGetSprite, DUP_FITTING_ITEM_ElemGetRenderElem, DUP_FITTING_ITEM_ElemSetPos, DUP_FITTING_ITEM_ElemGetPos, DUP_FITTING_ITEM_ElemSetBasePos, DUP_FITTING_ITEM_ElemGetBasePos, DUP_FITTING_ITEM_ElemSetF2C, DUP_FITTING_ITEM_ElemGetF2C, DUP_FITTING_ITEM_ElemSetF18, DUP_FITTING_ITEM_ElemGetF18, DUP_FITTING_ITEM_ElemSetF1C, DUP_FITTING_ITEM_ElemGetF1C, DUP_FITTING_ITEM_ElemSetF20, DUP_FITTING_ITEM_ElemGetF20, DUP_FITTING_ITEM_ElemHitTest, DUP_FITTING_ITEM_ElemHitDistance
 * address:  0x021BA0C8
 * region:   ov133
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from dup_fitting_item.c by tools/splitfile.py.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   MUSICAL_MCSS_FreeElemImage 0x021F4D74 thumb ov112
 *   MUSICAL_MCSS_AddImageNoVram 0x021F4C1C thumb ov112
 *   d_020A8148    0x020A8148 data
 *   MUSICAL_MCSS_FreeElem 0x021F4D40 thumb ov112
 *   FX_SinCosTable_ 0x020A1B38 data
 *   MUSICAL_MCSS_GetElemOffset 0x021F4F04 thumb ov112
 *   d_021BA610 0x021BA610 data a4
 *   MUSICAL_MCSS_GetElemFlag 0x021F4EFC thumb ov112
 *   MUSICAL_MCSS_GetElemField 0x021F4EE0 thumb ov112
 */
#include "dup_fitting_types.h"
#include "dup_fitting_types.h"

extern void *func_02030734(u32, u32, int, const char *, u16);

extern u32 func_020307B0(void *p);

extern void MUSICAL_MCSS_FreeElemImage(u8 *, u8 *, int, u16);

extern u8 *MUSICAL_MCSS_AddImageNoVram(u8 *, int, u32, Vec *);

extern void MUSICAL_MCSS_FreeElem(u8 *p, u8 *e);

extern void MUSICAL_MCSS_GetElemOffset(u8 *,DupFittingPair *);

extern unsigned int DUP_FITTING_ITEM_ElemHitDistance(u8 *, int, int);

extern int MUSICAL_MCSS_GetElemFlag(int, Flags *);

extern void MUSICAL_MCSS_GetElemField(int, u16 *, u16 *);

void DUP_FITTING_ITEM_NoOp(u8 *p, u8 n);

u8 *DUP_FITTING_ITEM_CreateList(u16 heap, int n);

void DUP_FITTING_ITEM_DeleteList(void *p);

void DUP_FITTING_ITEM_InsertElem(u8*p,u8*q);

void DUP_FITTING_ITEM_InsertElemTail(u8*p,u8*q);

void DUP_FITTING_ITEM_RemoveElem(u8*p,u8*q);

void *DUP_FITTING_ITEM_ListGetHead(char *p);

unsigned short DUP_FITTING_ITEM_ListGetCount(char *p);

int DUP_FITTING_ITEM_ListIsFull(char *p);

u8 *DUP_FITTING_ITEM_CreateElem(u16 heap, struct Object*q, u8*r, int*v);

void DUP_FITTING_ITEM_DeleteElem(u8*p,u8*q);

void DUP_FITTING_ITEM_FreeElemImage(u8*p,u8*q,u8*r);

u32 DUP_FITTING_ITEM_ElemGetNext(u8 *p);

u32 DUP_FITTING_ITEM_ElemGetData(u8 *p);

void DUP_FITTING_ITEM_ElemSetSprite(u8 *p, u32 value);

u32 DUP_FITTING_ITEM_ElemGetSprite(u8 *p);

u32 DUP_FITTING_ITEM_ElemGetRenderElem(u8 *p);

void DUP_FITTING_ITEM_ElemSetPos(u8 *p, const u8 *src);

u8 * DUP_FITTING_ITEM_ElemGetPos(u8 *p);

void DUP_FITTING_ITEM_ElemSetBasePos(u8 *p, const u8 *src);

u8 * DUP_FITTING_ITEM_ElemGetBasePos(u8 *p);

void DUP_FITTING_ITEM_ElemSetF2C(u8 *p, u32 value);

u32 DUP_FITTING_ITEM_ElemGetF2C(u8 *p);

void DUP_FITTING_ITEM_ElemSetF18(u8 *p, u32 value);

int DUP_FITTING_ITEM_ElemGetF18(char *p);

void DUP_FITTING_ITEM_ElemSetF1C(char *p, u32 v);

u16 DUP_FITTING_ITEM_ElemGetF1C(char *p);

void DUP_FITTING_ITEM_ElemSetF20(char *p, int v);

u32 DUP_FITTING_ITEM_ElemGetF20(char *p);

int DUP_FITTING_ITEM_ElemHitTest(u8 *p, int x, int y);

extern const short FX_SinCosTable_[];

extern const char d_021BA610[];

extern u32 (*d_020A8148)(u32, u32, u32);

void DUP_FITTING_ITEM_NoOp(u8 *p, u8 n){}

u8 *DUP_FITTING_ITEM_CreateList(u16 heap, int n){u8 *p;p=func_02030734(heap,16,0,d_021BA610,76);((struct DupFittingItemList *)p)->heapId=heap;((struct DupFittingItemList *)p)->count=0;((struct DupFittingItemList *)p)->max=n;((struct DupFittingItemList *)p)->head=0;((struct DupFittingItemList *)p)->tail=0;return p;}

void DUP_FITTING_ITEM_DeleteList(void *p){func_020307B0(p);}

void DUP_FITTING_ITEM_InsertElem(u8*p,u8*q){if(((struct DupFittingItemList *)p)->count<((struct DupFittingItemList *)p)->max){if(!*(u8* *)&((struct DupFittingItemList *)p)->head)*(u8* *)&((struct DupFittingItemList *)p)->head=q;else *(u8* *)&((struct DupFittingItemElem *)(*(u8* *)&((struct DupFittingItemList *)p)->tail))->next=q;*(u8* *)&((struct DupFittingItemList *)p)->tail=q;*(u8* *)&((struct DupFittingItemElem *)q)->next=0;(((struct DupFittingItemList *)p)->count)++;}}

void DUP_FITTING_ITEM_InsertElemTail(u8*p,u8*q){if(((struct DupFittingItemList *)p)->count<((struct DupFittingItemList *)p)->max){if(!*(u8* *)&((struct DupFittingItemList *)p)->head){*(u8* *)&((struct DupFittingItemList *)p)->head=q;*(u8* *)&((struct DupFittingItemList *)p)->tail=q;*(u8* *)&((struct DupFittingItemElem *)q)->next=0;}else{*(u8* *)&((struct DupFittingItemElem *)q)->next=*(u8* *)&((struct DupFittingItemList *)p)->head;*(u8* *)&((struct DupFittingItemList *)p)->head=q;}(((struct DupFittingItemList *)p)->count)++;}}

void DUP_FITTING_ITEM_RemoveElem(u8*p,u8*q){u8 *prev;u8 *cur;prev=0;cur=*(u8* *)&((struct DupFittingItemList *)p)->head;while(cur!=q && cur){prev=cur;cur=*(u8* *)&((struct DupFittingItemElem *)cur)->next;}if(cur){if(prev)*(u8* *)&((struct DupFittingItemElem *)prev)->next=*(u8* *)&((struct DupFittingItemElem *)cur)->next;else *(u8* *)&((struct DupFittingItemList *)p)->head=*(u8* *)&((struct DupFittingItemElem *)cur)->next;if(*(u8* *)&((struct DupFittingItemList *)p)->tail==q)*(u8* *)&((struct DupFittingItemList *)p)->tail=prev;*(u8* *)&((struct DupFittingItemElem *)cur)->next=0;(((struct DupFittingItemList *)p)->count)--;}}

void *DUP_FITTING_ITEM_ListGetHead(char *p){return *(void* *)&((struct DupFittingItemList *)p)->head;}

unsigned short DUP_FITTING_ITEM_ListGetCount(char *p){return ((struct DupFittingItemList *)p)->count;}

int DUP_FITTING_ITEM_ListIsFull(char *p)
{
    return ((struct DupFittingItemList *)p)->count == ((struct DupFittingItemList *)p)->max;
}

u8 *DUP_FITTING_ITEM_CreateElem(u16 heap, struct Object*q, u8*r, int*v){u8*p;p=func_02030734(heap,52,0,d_021BA610,204);*(u32 *)&((struct DupFittingItemElem *)p)->next=0;*(u8* *)&((struct DupFittingItemElem *)p)->data=r;*(u8 **)&((struct DupFittingItemElem *)p)->renderElem=MUSICAL_MCSS_AddImageNoVram((u8 *)q,((struct DupFittingItemData *)r)->id,((struct DupFittingItemData *)r)->f4,(Vec *)v);((struct DupFittingItemElem *)p)->f1C=0;((struct DupFittingItemElem *)p)->f20=10;return p;}

void DUP_FITTING_ITEM_DeleteElem(u8*p,u8*q){MUSICAL_MCSS_FreeElem(q,*(u8* *)&((struct DupFittingItemElem *)p)->renderElem);func_020307B0(p);}

void DUP_FITTING_ITEM_FreeElemImage(u8*p,u8*q,u8*r){*(u8* *)&((struct DupFittingItemElem *)p)->data=r;MUSICAL_MCSS_FreeElemImage(q,*(u8* *)&((struct DupFittingItemElem *)p)->renderElem,((struct DupFittingItemData *)r)->id,((struct DupFittingItemData *)r)->f4);}

u32 DUP_FITTING_ITEM_ElemGetNext(u8 *p)
{
    return (u32)((struct DupFittingItemElem *)p)->next;
}

u32 DUP_FITTING_ITEM_ElemGetData(u8 *p)
{
    return (u32)((struct DupFittingItemElem *)p)->data;
}

void DUP_FITTING_ITEM_ElemSetSprite(u8 *p, u32 value)
{
    ((struct DupFittingItemElem *)p)->sprite=value;
}

u32 DUP_FITTING_ITEM_ElemGetSprite(u8 *p)
{
    return ((struct DupFittingItemElem *)p)->sprite;
}

u32 DUP_FITTING_ITEM_ElemGetRenderElem(u8 *p)
{
    return (u32)((struct DupFittingItemElem *)p)->renderElem;
}

void DUP_FITTING_ITEM_ElemSetPos(u8 *p, const u8 *src)
{
    *(DupFittingPairU32 *)(p+16)=*(const DupFittingPairU32 *)src;
}

u8 * DUP_FITTING_ITEM_ElemGetPos(u8 *p)
{
    return p+16;
}

void DUP_FITTING_ITEM_ElemSetBasePos(u8 *p, const u8 *src)
{
    *(DupFittingPairU32 *)(p+36)=*(const DupFittingPairU32 *)src;
}

u8 * DUP_FITTING_ITEM_ElemGetBasePos(u8 *p)
{
    return p+36;
}

void DUP_FITTING_ITEM_ElemSetF2C(u8 *p, u32 value)
{
    ((struct DupFittingItemElem *)p)->f2C=value;
}

u32 DUP_FITTING_ITEM_ElemGetF2C(u8 *p)
{
    return ((struct DupFittingItemElem *)p)->f2C;
}

void DUP_FITTING_ITEM_ElemSetF18(u8 *p, u32 value)
{
    ((struct DupFittingItemElem *)p)->f18=value;
}

int DUP_FITTING_ITEM_ElemGetF18(char *p) { return ((struct DupFittingItemElem *)p)->f18; }

void DUP_FITTING_ITEM_ElemSetF1C(char *p, u32 v) { ((struct DupFittingItemElem *)p)->f1C=v; }

u16 DUP_FITTING_ITEM_ElemGetF1C(char *p) { return ((struct DupFittingItemElem *)p)->f1C; }

void DUP_FITTING_ITEM_ElemSetF20(char *p, int v) { ((struct DupFittingItemElem *)p)->f20=v; }

u32 DUP_FITTING_ITEM_ElemGetF20(char *p) { return ((struct DupFittingItemElem *)p)->f20; }

int DUP_FITTING_ITEM_ElemHitTest(u8 *p, int x, int y)
{
    short s;
    int pos[2];
    u16 angle;
    short c;
    int dx, dy;
    short rx, ry;
    MUSICAL_MCSS_GetElemOffset((u8 *)((struct DupFittingItemElem *)p)->renderElem, (DupFittingPair *)pos);
    if (MUSICAL_MCSS_GetElemFlag(0, ((struct DupFittingItemElem *)p)->renderElem) == 1) {
        MUSICAL_MCSS_GetElemField(0, ((struct DupFittingItemElem *)p)->renderElem, &angle);
        s = ((const short *)FX_SinCosTable_)[(angle >> 4) * 2];
        c = ((const short *)FX_SinCosTable_)[(angle >> 4) * 2 + 1];
        dx = (int)((float)(pos[0] * c - pos[1] * s) / 4096.0f);
        dy = (int)((float)(pos[0] * s + pos[1] * c) / 4096.0f);
        rx = ((struct DupFittingItemElem *)p)->posX - dx - x;
        ry = ((struct DupFittingItemElem *)p)->posY - dy - y;
    } else {
        rx = ((struct DupFittingItemElem *)p)->posX - x;
        ry = ((struct DupFittingItemElem *)p)->posY - y;
    }
    if (rx < 16 && rx > -16 && ry < 16 && ry > -16) return 1;
    return 0;
}

unsigned int DUP_FITTING_ITEM_ElemHitDistance(u8 *p, int x, int y)
{
    short s;
    int pos[2];
    u16 angle;
    short c;
    int dx, dy;
    short rx, ry;
    MUSICAL_MCSS_GetElemOffset((u8 *)((struct DupFittingItemElem *)p)->renderElem, (DupFittingPair *)pos);
    if (MUSICAL_MCSS_GetElemFlag(0, ((struct DupFittingItemElem *)p)->renderElem) == 1) {
        MUSICAL_MCSS_GetElemField(0, ((struct DupFittingItemElem *)p)->renderElem, &angle);
        s = ((const short *)FX_SinCosTable_)[(angle >> 4) * 2];
        c = ((const short *)FX_SinCosTable_)[(angle >> 4) * 2 + 1];
        dx = (int)((float)(pos[0] * c - pos[1] * s) / 4096.0f);
        dy = (int)((float)(pos[0] * s + pos[1] * c) / 4096.0f);
        rx = ((struct DupFittingItemElem *)p)->posX - dx - x;
        ry = ((struct DupFittingItemElem *)p)->posY - dy - y;
    } else {
        rx = ((struct DupFittingItemElem *)p)->posX - x;
        ry = ((struct DupFittingItemElem *)p)->posY - y;
    }
    return rx * rx + ry * ry;
}
