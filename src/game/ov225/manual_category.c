/*
 * file:     manual_category.c
 * unit:     yes
 * function: MANUAL_CATEGORY_CreateList, MANUAL_CATEGORY_DeleteList, MANUAL_CATEGORY_IsListFinished, MANUAL_CATEGORY_TaskNoop
 * address:  0x021BB6E0
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
 *   MANUAL_COMMON_GetGroupCount 0x021B9C50 thumb ov225
 *   MANUAL_COMMON_GetGroupValue1 0x021B9C34 thumb ov225
 *   MANUAL_COMMON_GetGroupValue2 0x021B9C40 thumb ov225
 *   MANUAL_COMMON_GetEntryValue1 0x021B9BD4 thumb ov225
 *   MANUAL_COMMON_CheckUnlocked 0x021B9C58 thumb ov225
 *   MANUAL_COMMON_GetGroupValue0 0x021B9C28 thumb ov225
 *   MANUAL_COMMON_CreateListWork 0x021BA65C thumb ov225
 *   gManualCategoryListAllocFile 0x021BC048 data a4
 *   TCB_DeleteTask 0x02030EAC arm
 *   MANUAL_COMMON_DeleteListWork 0x021BA740 thumb ov225
 *   GFL_HEAP_Free 0x020307B0 arm
 *   MANUAL_COMMON_UpdateListWork 0x021BA760 thumb ov225
 */
#include "manual_category_shared_types.h"

/* ManualWork + 0x20: the list owner region. */
struct ManualListOwner {
    u16 originX;        /* 0x00 */
    u16 originY;        /* 0x02 */
    u32 hasDetail;      /* 0x04 */
    u16 detailEntry;    /* 0x08 */
    u16 pad0A;
};

extern void *GFL_HEAP_Alloc(unsigned,unsigned,int,const char *,u16);

extern void *GFL_USE_AddMainTask(unsigned,unsigned,unsigned);

extern u16 MANUAL_COMMON_GetGroupCount(const char *p);

extern u16 MANUAL_COMMON_GetGroupValue1(char *,int);

extern u16 MANUAL_COMMON_GetGroupValue2(char *,int,int);

extern u16 MANUAL_COMMON_GetEntryValue1(char *,int);

extern int MANUAL_COMMON_CheckUnlocked(void *,int,void *);

extern u16 MANUAL_COMMON_GetGroupValue0(char *,int);

extern void *MANUAL_COMMON_CreateListWork(char *owner, struct ManualData *data);

extern void TCB_DeleteTask(struct Node *);

extern void MANUAL_COMMON_DeleteListWork(char *);

extern u32 GFL_HEAP_Free(void *p);

extern int MANUAL_COMMON_UpdateListWork(char *p);

char *MANUAL_CATEGORY_CreateList(char *p,char *data);

void MANUAL_CATEGORY_DeleteList(char *p);

int MANUAL_CATEGORY_IsListFinished(char *p);

void MANUAL_CATEGORY_TaskNoop(void);

extern const char gManualCategoryListAllocFile[];

char *MANUAL_CATEGORY_CreateList(char *p,char *data)
{
    char *q;
    u16 groups,items;
    u16 i,j,valid;
    q=GFL_HEAP_Alloc(((struct ManualData *)data)->heap,0x24,1,gManualCategoryListAllocFile,0x5c);
    *(char * *)&((struct ManualMenuList *)q)->owner=p;
    ((struct ManualListOwner *)p)->hasDetail=0;
    ((struct ManualListOwner *)(*(char * *)&((struct ManualMenuList *)q)->owner))->detailEntry=0;
    *(char * *)&((struct ManualMenuList *)q)->data=data;
    ((struct ManualMenuList *)q)->ready=0;
    groups=MANUAL_COMMON_GetGroupCount(*(char * *)&((struct ManualData *)data)->assets);
    ((struct ManualMenuList *)q)->entryCount=0;
    *(char * *)&((struct ManualMenuList *)q)->entries=GFL_HEAP_Alloc(((struct ManualData *)(*(char * *)&((struct ManualMenuList *)q)->data))->heap,groups*8,1,gManualCategoryListAllocFile,0x71);
    for(i=0;i<groups;i++) {
        valid=0;
        items=MANUAL_COMMON_GetGroupValue1(*(char * *)&((struct ManualData *)(*(char * *)&((struct ManualMenuList *)q)->data))->assets,i);
        for(j=0;j<items;j++) {
            int id;
            id=MANUAL_COMMON_GetGroupValue2(*(char * *)&((struct ManualData *)(*(char * *)&((struct ManualMenuList *)q)->data))->assets,i,j);
            id=MANUAL_COMMON_GetEntryValue1(*(char * *)&((struct ManualData *)(*(char * *)&((struct ManualMenuList *)q)->data))->assets,id);
            if(MANUAL_COMMON_CheckUnlocked(((struct ManualData *)(*(char * *)&((struct ManualMenuList *)q)->data))->assets,id,*(void **)*(char * *)&((struct ManualMenuList *)q)->data)) valid++;
        }
        if(valid) {
            *(u16 *)(*(char * *)&((struct ManualMenuList *)q)->entries+((struct ManualMenuList *)q)->entryCount*8)=i;
            *(u16 *)(*(char * *)&((struct ManualMenuList *)q)->entries+((struct ManualMenuList *)q)->entryCount*8+2)=MANUAL_COMMON_GetGroupValue0(*(char * *)&((struct ManualData *)(*(char * *)&((struct ManualMenuList *)q)->data))->assets,i);
            *(u32 *)(*(char * *)&((struct ManualMenuList *)q)->entries+((struct ManualMenuList *)q)->entryCount*8+4)=0;
            ((struct ManualMenuList *)q)->entryCount+=1;
        }
    }
    ((struct ManualMenuList *)q)->savedA=*(u16 *)*(char * *)&((struct ManualMenuList *)q)->owner;
    ((struct ManualMenuList *)q)->savedB=((struct ManualListOwner *)(*(char * *)&((struct ManualMenuList *)q)->owner))->originY;
    *(char * *)&((struct ManualMenuList *)q)->widget=MANUAL_COMMON_CreateListWork(q+8,(struct ManualData *)data);
    ((struct ManualMenuList *)q)->task=GFL_USE_AddMainTask((unsigned)MANUAL_CATEGORY_TaskNoop,(unsigned)q,1);
    return q;
}

/*
 * extent: 94-byte unit; two zero alignment bytes at 021BB852 are outside the unit.
 * followers: parent cleared 021BB844 tail stub and 021BB850 empty Thumb leaf.
 */
void MANUAL_CATEGORY_DeleteList(char *p)
{
    TCB_DeleteTask(*(struct Node * *)&((struct ManualMenuList *)p)->task);
    *(u16 *)*(char * *)&((struct ManualMenuList *)p)->owner = ((struct ManualMenuList *)p)->savedA;
    ((struct ManualListOwner *)(*(char * *)&((struct ManualMenuList *)p)->owner))->originY = ((struct ManualMenuList *)p)->savedB;
    if (((struct ManualMenuList *)p)->mode == 0) ((struct ManualListOwner *)(*(char * *)&((struct ManualMenuList *)p)->owner))->hasDetail = 0;
    else if (((struct ManualMenuList *)p)->mode == 1) {
        ((struct ManualListOwner *)(*(char * *)&((struct ManualMenuList *)p)->owner))->hasDetail = 1;
        ((struct ManualListOwner *)(*(char * *)&((struct ManualMenuList *)p)->owner))->detailEntry = *(u16 *)(*(char * *)&((struct ManualMenuList *)p)->entries + ((struct ManualListOwner *)(*(char * *)&((struct ManualMenuList *)p)->owner))->originY * 8);
    }
    MANUAL_COMMON_DeleteListWork(*(char * *)&((struct ManualMenuList *)p)->widget);
    GFL_HEAP_Free(((struct ManualMenuList *)p)->entries);
    GFL_HEAP_Free(p);
}

int MANUAL_CATEGORY_IsListFinished(char *p)
{
    return MANUAL_COMMON_UpdateListWork(*(char * *)&((struct ManualMenuList *)p)->widget);
}

void MANUAL_CATEGORY_TaskNoop(void)
{
}
