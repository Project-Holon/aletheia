/*
 * file:     manual_title.c
 * unit:     yes
 * function: MANUAL_CATEGORY_CreateDetailList, MANUAL_CATEGORY_DeleteDetailList, MANUAL_CATEGORY_IsDetailFinished, MANUAL_CATEGORY_DetailTaskNoop
 * address:  0x021BB854
 * region:   ov225
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from manual_category.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   MANUAL_COMMON_GetGroupValue1 0x021B9C34 thumb ov225
 *   MANUAL_COMMON_GetGroupValue2 0x021B9C40 thumb ov225
 *   MANUAL_COMMON_GetEntryValue1 0x021B9BD4 thumb ov225
 *   MANUAL_COMMON_CheckUnlocked 0x021B9C58 thumb ov225
 *   MANUAL_COMMON_CreateListWork 0x021BA65C thumb ov225
 *   TCB_DeleteTask 0x02030EAC arm
 *   MANUAL_COMMON_DeleteListWork 0x021BA740 thumb ov225
 *   GFL_HEAP_Free 0x020307B0 arm
 *   MANUAL_COMMON_UpdateListWork 0x021BA760 thumb ov225
 *   MANUAL_COMMON_GetEntryCount 0x021B9C20 thumb ov225
 *   MANUAL_COMMON_GetEntryValue2 0x021B9BE0 thumb ov225
 *   MANUAL_COMMON_GetSaveValue 0x021B9C98 thumb ov225
 *   MANUAL_COMMON_GetEntryValue0 0x021B9BC8 thumb ov225
 *   gManualCategoryDetailAllocFile 0x021BC05C data a1
 */
#include "manual_category_shared_types.h"

/* ManualWork + 0x30: the detail owner region. */
struct ManualDetailOwner {
    u32 state;          /* 0x00 */
    u16 id;             /* 0x04 */
    u16 count;          /* 0x06 */
    u16 selected;       /* 0x08 */
    u16 pad0A;
    u32 subFlag;        /* 0x0C */
    u16 entryId;        /* 0x10 */
    u16 pad12;
};

typedef enum { FLAG_FALSE, FLAG_TRUE } Flag;

#include "../arm9/gfl_heap_wrap.h"

#include "../arm9/gfl_use.h"

#include "manual_data.h"




#include "manual_list.h"
struct TcbTask;

#include "../arm9/tcb_list.h"








struct ManualMenuList *MANUAL_CATEGORY_CreateDetailList(struct ManualDetailOwner *p, struct ManualData *data);

void MANUAL_CATEGORY_DeleteDetailList(char *p);

int MANUAL_CATEGORY_IsDetailFinished(char *p);

void MANUAL_CATEGORY_DetailTaskNoop(void);

extern const char gManualCategoryDetailAllocFile[];

struct ManualMenuList *MANUAL_CATEGORY_CreateDetailList(struct ManualDetailOwner *p, struct ManualData *data)
{
    struct ManualMenuList *q;
    u32 t, t0;
    int g;
    u16 ca, cb;
    int ra, rb;
    q = GFL_HEAP_Alloc(data->heap, 0x24, 1, gManualCategoryDetailAllocFile, 0x61);
    q->owner = p;
    *(u32 *)((char *)p + 0xC) = 0;
    *(u16 *)((char *)q->owner + 0x10) = 0;
    q->data = data;
    t0 = ((struct ManualDetailOwner *)q->owner)->state;
    if (t0 == 0) {
        q->ready = 1;
        g = ((struct ManualDetailOwner *)q->owner)->id;
        ca = MANUAL_COMMON_GetGroupValue1(((struct ManualData *)q->data)->assets, g);
        q->entryCount = 0;
        q->entries = GFL_HEAP_Alloc(((struct ManualData *)q->data)->heap, ca * 8, 1, gManualCategoryDetailAllocFile, 0x79);
        {
            u16 i;
        for (i = 0; i < ca; i++) {
            u16 id;
            int id2;
            id = MANUAL_COMMON_GetGroupValue2(((struct ManualData *)q->data)->assets, g, i);
            id2 = MANUAL_COMMON_GetEntryValue1(((struct ManualData *)q->data)->assets, id);
            if (MANUAL_COMMON_CheckUnlocked(((struct ManualData *)q->data)->assets, id2, ((struct ManualData *)q->data)->owner)) {
                t = MANUAL_COMMON_GetEntryValue2(((struct ManualData *)q->data)->assets, id);
                ra = MANUAL_COMMON_GetSaveValue((void *)(((struct ManualData *)q->data)->assets), t, ((struct ManualData *)q->data)->owner);
                *(u16 *)((char *)q->entries + q->entryCount * 8) = id;
                *(u16 *)((char *)q->entries + q->entryCount * 8 + 2) = MANUAL_COMMON_GetEntryValue0(((struct ManualData *)q->data)->assets, id);
                *(u32 *)((char *)q->entries + q->entryCount * 8 + 4) = (ra != 0) ? FLAG_FALSE : FLAG_TRUE;
                q->entryCount += 1;
            }
        }
        }
        q->savedA = *(u16 *)((char *)q->owner + 6);
        q->savedB = *(u16 *)((char *)q->owner + 8);
    } else {
        q->ready = 1;
        cb = MANUAL_COMMON_GetEntryCount(((struct ManualData *)q->data)->assets);
        q->entryCount = 0;
        q->entries = GFL_HEAP_Alloc(((struct ManualData *)q->data)->heap, cb * 8, 1, gManualCategoryDetailAllocFile, 0xB2);
        {
            u16 i;
        for (i = 0; i < cb; i++) {
            int id;
            id = MANUAL_COMMON_GetEntryValue1(((struct ManualData *)q->data)->assets, i);
            if (MANUAL_COMMON_CheckUnlocked(((struct ManualData *)q->data)->assets, id, ((struct ManualData *)q->data)->owner)) {
                t = MANUAL_COMMON_GetEntryValue2(((struct ManualData *)q->data)->assets, i);
                rb = MANUAL_COMMON_GetSaveValue((void *)(((struct ManualData *)q->data)->assets), t, ((struct ManualData *)q->data)->owner);
                *(u16 *)((char *)q->entries + q->entryCount * 8) = i;
                *(u16 *)((char *)q->entries + q->entryCount * 8 + 2) = MANUAL_COMMON_GetEntryValue0(((struct ManualData *)q->data)->assets, i);
                {
                    u32 fl = 0;
                    if (rb == 0)
                        fl = 1;
                    *(u32 *)((char *)q->entries + q->entryCount * 8 + 4) = fl;
                }
                q->entryCount += 1;
            }
        }
        }
        q->savedA = *(u16 *)((char *)q->owner + 6);
        q->savedB = *(u16 *)((char *)q->owner + 8);
    }
    q->widget = MANUAL_COMMON_CreateListWork((char *)q + 8, data);
    q->task = GFL_USE_AddMainTask((void (*)(struct TcbTask *, void *))((uptr)MANUAL_CATEGORY_DetailTaskNoop), (void *)((uptr)q), 1);
    return q;
}

/*
 * extent: 94-byte unit; two zero alignment bytes at 021BBA72 are outside the unit.
 * followers: parent cleared 021BBA64 tail stub and 021BBA70 empty Thumb leaf.
 */
void MANUAL_CATEGORY_DeleteDetailList(char *p)
{
    TCB_DeleteTask((struct TcbTask *)(*(struct Node * *)&((struct ManualMenuList *)p)->task));
    ((struct ManualDetailOwner *)(*(char * *)&((struct ManualMenuList *)p)->owner))->count = ((struct ManualMenuList *)p)->savedA;
    ((struct ManualDetailOwner *)(*(char * *)&((struct ManualMenuList *)p)->owner))->selected = ((struct ManualMenuList *)p)->savedB;
    if (((struct ManualMenuList *)p)->mode == 0) ((struct ManualDetailOwner *)(*(char * *)&((struct ManualMenuList *)p)->owner))->subFlag = 0;
    else if (((struct ManualMenuList *)p)->mode == 1) {
        ((struct ManualDetailOwner *)(*(char * *)&((struct ManualMenuList *)p)->owner))->subFlag = 1;
        ((struct ManualDetailOwner *)(*(char * *)&((struct ManualMenuList *)p)->owner))->entryId = *(u16 *)(*(char * *)&((struct ManualMenuList *)p)->entries + ((struct ManualDetailOwner *)(*(char * *)&((struct ManualMenuList *)p)->owner))->selected * 8);
    }
    MANUAL_COMMON_DeleteListWork(*(char * *)&((struct ManualMenuList *)p)->widget);
    GFL_HEAP_Free(((struct ManualMenuList *)p)->entries);
    GFL_HEAP_Free(p);
}

int MANUAL_CATEGORY_IsDetailFinished(char *p)
{
    return MANUAL_COMMON_UpdateListWork(*(char * *)&((struct ManualMenuList *)p)->widget);
}

void MANUAL_CATEGORY_DetailTaskNoop(void)
{
}
