/*
 * file:     dup_fitting_item.c
 * unit:     yes
 * function: DUP_FITTING_ITEM_NoOp, DUP_FITTING_ITEM_CreateList, DUP_FITTING_ITEM_DeleteList, DUP_FITTING_ITEM_InsertElem, DUP_FITTING_ITEM_InsertElemTail, DUP_FITTING_ITEM_RemoveElem, DUP_FITTING_ITEM_ListGetHead, DUP_FITTING_ITEM_ListGetCount, DUP_FITTING_ITEM_ListIsFull, DUP_FITTING_ITEM_CreateElem, DUP_FITTING_ITEM_DeleteElem, DUP_FITTING_ITEM_FreeElemImage, DUP_FITTING_ITEM_ElemGetNext, DUP_FITTING_ITEM_ElemGetData, DUP_FITTING_ITEM_ElemSetSprite, DUP_FITTING_ITEM_ElemGetSprite, DUP_FITTING_ITEM_ElemGetRenderElem, DUP_FITTING_ITEM_ElemSetPos, DUP_FITTING_ITEM_ElemGetPos, DUP_FITTING_ITEM_ElemSetBasePos, DUP_FITTING_ITEM_ElemGetBasePos, DUP_FITTING_ITEM_ElemSetStartScale, DUP_FITTING_ITEM_ElemGetStartScale, DUP_FITTING_ITEM_ElemSetScale, DUP_FITTING_ITEM_ElemGetScale, DUP_FITTING_ITEM_ElemSetAnimFrames, DUP_FITTING_ITEM_ElemGetAnimFrames, DUP_FITTING_ITEM_ElemSetFrameIndex, DUP_FITTING_ITEM_ElemGetFrameIndex, DUP_FITTING_ITEM_ElemHitTest, DUP_FITTING_ITEM_ElemHitDistance
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
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   MUSICAL_MCSS_FreeElemImage 0x021F4D74 thumb ov112
 *   MUSICAL_MCSS_AddImageNoVram 0x021F4C1C thumb ov112
 *   d_020A8148    0x020A8148 data
 *   MUSICAL_MCSS_FreeElem 0x021F4D40 thumb ov112
 *   FX_SinCosTable_ 0x020A1B38 data
 *   MUSICAL_MCSS_GetElemOffset 0x021F4F04 thumb ov112
 *   d_021BA610 0x021BA610 data a4
 *   MUSICAL_MCSS_GetElemFlag 0x021F4EFC thumb ov112
 *   MUSICAL_MCSS_GetElemField 0x021F4EE0 thumb ov112
 *   _fdiv                        0x0209CE10  arm
 *   _ffix                        0x0209C494  arm
 *   _fflt                        0x0209BDBC  arm
 */
#include "dup_fitting_types.h"
#include "../arm9/gfl_heap_wrap.h"


#include "../ov112/mus_item_draw.h"
struct McssActorPool;
struct McssActorElem;


struct McssOffset;


extern unsigned int DUP_FITTING_ITEM_ElemHitDistance(u8 *, int, int);



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

void DUP_FITTING_ITEM_ElemSetStartScale(u8 *p, u32 value);

u32 DUP_FITTING_ITEM_ElemGetStartScale(u8 *p);

void DUP_FITTING_ITEM_ElemSetScale(u8 *p, u32 value);

int DUP_FITTING_ITEM_ElemGetScale(char *p);

void DUP_FITTING_ITEM_ElemSetAnimFrames(char *p, u32 v);

u16 DUP_FITTING_ITEM_ElemGetAnimFrames(char *p);

void DUP_FITTING_ITEM_ElemSetFrameIndex(char *p, int v);

u32 DUP_FITTING_ITEM_ElemGetFrameIndex(char *p);

int DUP_FITTING_ITEM_ElemHitTest(u8 *p, int x, int y);

extern const short FX_SinCosTable_[];

extern const char d_021BA610[];

extern u32 (*d_020A8148)(u32, u32, u32);

void DUP_FITTING_ITEM_NoOp(u8 *p, u8 n){}

u8 *DUP_FITTING_ITEM_CreateList(u16 heap, int max){u8 *list;list=GFL_HEAP_Alloc(heap,16,0,d_021BA610,76);((struct DupFittingItemList *)list)->heapId=heap;((struct DupFittingItemList *)list)->count=0;((struct DupFittingItemList *)list)->max=max;((struct DupFittingItemList *)list)->head=0;((struct DupFittingItemList *)list)->tail=0;return list;}

void DUP_FITTING_ITEM_DeleteList(void *list){GFL_HEAP_Free(list);}

void DUP_FITTING_ITEM_InsertElem(u8*list,u8*elem){if(((struct DupFittingItemList *)list)->count<((struct DupFittingItemList *)list)->max){if(!*(u8* *)&((struct DupFittingItemList *)list)->head)*(u8* *)&((struct DupFittingItemList *)list)->head=elem;else *(u8* *)&((struct DupFittingItemElem *)(*(u8* *)&((struct DupFittingItemList *)list)->tail))->next=elem;*(u8* *)&((struct DupFittingItemList *)list)->tail=elem;*(u8* *)&((struct DupFittingItemElem *)elem)->next=0;(((struct DupFittingItemList *)list)->count)++;}}

void DUP_FITTING_ITEM_InsertElemTail(u8*list,u8*elem){if(((struct DupFittingItemList *)list)->count<((struct DupFittingItemList *)list)->max){if(!*(u8* *)&((struct DupFittingItemList *)list)->head){*(u8* *)&((struct DupFittingItemList *)list)->head=elem;*(u8* *)&((struct DupFittingItemList *)list)->tail=elem;*(u8* *)&((struct DupFittingItemElem *)elem)->next=0;}else{*(u8* *)&((struct DupFittingItemElem *)elem)->next=*(u8* *)&((struct DupFittingItemList *)list)->head;*(u8* *)&((struct DupFittingItemList *)list)->head=elem;}(((struct DupFittingItemList *)list)->count)++;}}

void DUP_FITTING_ITEM_RemoveElem(u8*list,u8*elem){u8 *prev;u8 *cur;prev=0;cur=*(u8* *)&((struct DupFittingItemList *)list)->head;while(cur!=elem && cur){prev=cur;cur=*(u8* *)&((struct DupFittingItemElem *)cur)->next;}if(cur){if(prev)*(u8* *)&((struct DupFittingItemElem *)prev)->next=*(u8* *)&((struct DupFittingItemElem *)cur)->next;else *(u8* *)&((struct DupFittingItemList *)list)->head=*(u8* *)&((struct DupFittingItemElem *)cur)->next;if(*(u8* *)&((struct DupFittingItemList *)list)->tail==elem)*(u8* *)&((struct DupFittingItemList *)list)->tail=prev;*(u8* *)&((struct DupFittingItemElem *)cur)->next=0;(((struct DupFittingItemList *)list)->count)--;}}

void *DUP_FITTING_ITEM_ListGetHead(char *list){return *(void* *)&((struct DupFittingItemList *)list)->head;}

unsigned short DUP_FITTING_ITEM_ListGetCount(char *list){return ((struct DupFittingItemList *)list)->count;}

int DUP_FITTING_ITEM_ListIsFull(char *list)
{
    return ((struct DupFittingItemList *)list)->count == ((struct DupFittingItemList *)list)->max;
}

u8 *DUP_FITTING_ITEM_CreateElem(u16 heap, struct Object*pool, u8*data, int*pos){u8*elem;elem=GFL_HEAP_Alloc(heap,52,0,d_021BA610,204);*(u32 *)&((struct DupFittingItemElem *)elem)->next=0;*(u8* *)&((struct DupFittingItemElem *)elem)->data=data;*(u8 **)&((struct DupFittingItemElem *)elem)->renderElem=(unsigned char *)MUSICAL_MCSS_AddImageNoVram((struct McssActorPool *)pool,((struct DupFittingItemData *)data)->id,((struct DupFittingItemData *)data)->imageId,(int *)pos);((struct DupFittingItemElem *)elem)->animFrames=0;((struct DupFittingItemElem *)elem)->frameIndex=10;return elem;}

void DUP_FITTING_ITEM_DeleteElem(u8*elem,u8*pool){MUSICAL_MCSS_FreeElem(pool,*(u8* *)&((struct DupFittingItemElem *)elem)->renderElem);GFL_HEAP_Free(elem);}

void DUP_FITTING_ITEM_FreeElemImage(u8*elem,u8*pool,u8*data){*(u8* *)&((struct DupFittingItemElem *)elem)->data=data;MUSICAL_MCSS_FreeElemImage(pool,*(u8* *)&((struct DupFittingItemElem *)elem)->renderElem,((struct DupFittingItemData *)data)->id,((struct DupFittingItemData *)data)->imageId);}

u32 DUP_FITTING_ITEM_ElemGetNext(u8 *elem)
{
    return (u32)((struct DupFittingItemElem *)elem)->next;
}

u32 DUP_FITTING_ITEM_ElemGetData(u8 *elem)
{
    return (u32)((struct DupFittingItemElem *)elem)->data;
}

void DUP_FITTING_ITEM_ElemSetSprite(u8 *elem, u32 value)
{
    ((struct DupFittingItemElem *)elem)->sprite=value;
}

u32 DUP_FITTING_ITEM_ElemGetSprite(u8 *elem)
{
    return ((struct DupFittingItemElem *)elem)->sprite;
}

u32 DUP_FITTING_ITEM_ElemGetRenderElem(u8 *elem)
{
    return (u32)((struct DupFittingItemElem *)elem)->renderElem;
}

void DUP_FITTING_ITEM_ElemSetPos(u8 *elem, const u8 *src)
{
    *(DupFittingPairU32 *)(elem+16)=*(const DupFittingPairU32 *)src;
}

u8 * DUP_FITTING_ITEM_ElemGetPos(u8 *elem)
{
    return elem+16;
}

void DUP_FITTING_ITEM_ElemSetBasePos(u8 *elem, const u8 *src)
{
    *(DupFittingPairU32 *)(elem+36)=*(const DupFittingPairU32 *)src;
}

u8 * DUP_FITTING_ITEM_ElemGetBasePos(u8 *elem)
{
    return elem+36;
}

void DUP_FITTING_ITEM_ElemSetStartScale(u8 *elem, u32 value)
{
    ((struct DupFittingItemElem *)elem)->startScale=value;
}

u32 DUP_FITTING_ITEM_ElemGetStartScale(u8 *elem)
{
    return ((struct DupFittingItemElem *)elem)->startScale;
}

void DUP_FITTING_ITEM_ElemSetScale(u8 *elem, u32 value)
{
    ((struct DupFittingItemElem *)elem)->scale=value;
}

int DUP_FITTING_ITEM_ElemGetScale(char *elem) { return ((struct DupFittingItemElem *)elem)->scale; }

void DUP_FITTING_ITEM_ElemSetAnimFrames(char *elem, u32 value) { ((struct DupFittingItemElem *)elem)->animFrames=value; }

u16 DUP_FITTING_ITEM_ElemGetAnimFrames(char *elem) { return ((struct DupFittingItemElem *)elem)->animFrames; }

void DUP_FITTING_ITEM_ElemSetFrameIndex(char *elem, int value) { ((struct DupFittingItemElem *)elem)->frameIndex=value; }

u32 DUP_FITTING_ITEM_ElemGetFrameIndex(char *elem) { return ((struct DupFittingItemElem *)elem)->frameIndex; }

int DUP_FITTING_ITEM_ElemHitTest(u8 *elem, int x, int y)
{
    short s;
    int pos[2];
    u16 angle;
    short c;
    int dx, dy;
    short rx, ry;
    MUSICAL_MCSS_GetElemOffset((u8 *)((struct DupFittingItemElem *)elem)->renderElem, (struct McssOffset *)pos);
    if (MUSICAL_MCSS_GetElemFlag(0, ((struct DupFittingItemElem *)elem)->renderElem) == 1) {
        MUSICAL_MCSS_GetElemField(0, ((struct DupFittingItemElem *)elem)->renderElem, &angle);
        s = ((const short *)FX_SinCosTable_)[(angle >> 4) * 2];
        c = ((const short *)FX_SinCosTable_)[(angle >> 4) * 2 + 1];
        dx = (int)((float)(pos[0] * c - pos[1] * s) / 4096.0f);
        dy = (int)((float)(pos[0] * s + pos[1] * c) / 4096.0f);
        rx = ((struct DupFittingItemElem *)elem)->posX - dx - x;
        ry = ((struct DupFittingItemElem *)elem)->posY - dy - y;
    } else {
        rx = ((struct DupFittingItemElem *)elem)->posX - x;
        ry = ((struct DupFittingItemElem *)elem)->posY - y;
    }
    if (rx < 16 && rx > -16 && ry < 16 && ry > -16) return 1;
    return 0;
}

unsigned int DUP_FITTING_ITEM_ElemHitDistance(u8 *elem, int x, int y)
{
    short s;
    int pos[2];
    u16 angle;
    short c;
    int dx, dy;
    short rx, ry;
    MUSICAL_MCSS_GetElemOffset((u8 *)((struct DupFittingItemElem *)elem)->renderElem, (struct McssOffset *)pos);
    if (MUSICAL_MCSS_GetElemFlag(0, ((struct DupFittingItemElem *)elem)->renderElem) == 1) {
        MUSICAL_MCSS_GetElemField(0, ((struct DupFittingItemElem *)elem)->renderElem, &angle);
        s = ((const short *)FX_SinCosTable_)[(angle >> 4) * 2];
        c = ((const short *)FX_SinCosTable_)[(angle >> 4) * 2 + 1];
        dx = (int)((float)(pos[0] * c - pos[1] * s) / 4096.0f);
        dy = (int)((float)(pos[0] * s + pos[1] * c) / 4096.0f);
        rx = ((struct DupFittingItemElem *)elem)->posX - dx - x;
        ry = ((struct DupFittingItemElem *)elem)->posY - dy - y;
    } else {
        rx = ((struct DupFittingItemElem *)elem)->posX - x;
        ry = ((struct DupFittingItemElem *)elem)->posY - y;
    }
    return rx * rx + ry * ry;
}
