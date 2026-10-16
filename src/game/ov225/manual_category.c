/*
 * file:     manual_category.c
 * unit:     yes
 * function: MANUAL_CATEGORY_CreateList, MANUAL_CATEGORY_DeleteList, MANUAL_CATEGORY_TaskNoop, MANUAL_CATEGORY_CreateDetailList, MANUAL_CATEGORY_DeleteDetailList, MANUAL_CATEGORY_DetailTaskNoop, MANUAL_CATEGORY_CreateOption, MANUAL_CATEGORY_DeleteOption, MANUAL_CATEGORY_UpdateOption, MANUAL_CATEGORY_OptionTaskNoop, MANUAL_CATEGORY_LoadOptionAssets, MANUAL_CATEGORY_SetOptionBgMode, MANUAL_CATEGORY_OptionNoop, MANUAL_CATEGORY_CreateOptionSlots, MANUAL_CATEGORY_DeleteOptionSlots, MANUAL_CATEGORY_UpdateOptionSlots, MANUAL_CATEGORY_DrawOption
 * address:  0x021BB6E0
 * region:   ov225
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Builds a graphics record: releases the p+0x24 handle, sizes the p+0x18
 * resource through BMP_WIN_GetBmp, resolves a slot word, and submits a
 * seven-argument call before marking p+0x30 and repointing the slot.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020056A0 0x020056A0 thumb
 *   MANUAL_COMMON_GetGroupCount 0x021B9C50 thumb ov225
 *   MANUAL_COMMON_GetGroupValue1 0x021B9C34 thumb ov225
 *   MANUAL_COMMON_GetGroupValue2 0x021B9C40 thumb ov225
 *   MANUAL_COMMON_GetEntryValue1 0x021B9BD4 thumb ov225
 *   MANUAL_COMMON_CheckUnlocked 0x021B9C58 thumb ov225
 *   MANUAL_COMMON_GetGroupValue0 0x021B9C28 thumb ov225
 *   MANUAL_COMMON_CreateListWork 0x021BA65C thumb ov225
 *   gManualCategoryListAllocFile 0x021BC048 data a4
 *   func_02030EAC 0x02030EAC arm
 *   MANUAL_COMMON_DeleteListWork 0x021BA740 thumb ov225
 *   func_020307B0 0x020307B0 arm
 *   MANUAL_COMMON_UpdateListWork 0x021BA760 thumb ov225
 *   MANUAL_COMMON_GetEntryCount 0x021B9C20 thumb ov225
 *   MANUAL_COMMON_GetEntryValue2 0x021B9BE0 thumb ov225
 *   MANUAL_COMMON_GetSaveValue 0x021B9C98 thumb ov225
 *   MANUAL_COMMON_GetEntryValue0 0x021B9BC8 thumb ov225
 *   gManualCategoryDetailAllocFile 0x021BC05C data a1
 *   gManualCategoryOptionAllocFile 0x021BC06C data a1
 *   MANUAL_COMMON_SetTouchbarState 0x021BA068 thumb ov225
 *   MANUAL_COMMON_SetTouchbarSelection 0x021BA0F0 thumb ov225
 *   MANUAL_COMMON_GetDefaultId 0x021B9CDC thumb ov225
 *   MANUAL_COMMON_SetScreenId 0x021B9E80 thumb ov225
 *   TCB_DeleteTask 0x02030EAC arm
 *   MANUAL_COMMON_UpdateTouchbar 0x021B9FBC thumb ov225
 *   MANUAL_COMMON_GetTouchbarPressed 0x021BA158 thumb ov225
 *   MANUAL_COMMON_GetTouchbarSelected 0x021BA154 thumb ov225
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandleExt 0x020499D4 arm
 *   BG_SYS_SetFlagField06 0x02041B6C arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   func_02045EC0 0x02045EC0 arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   gManualCategorySlotRecords 0x021BBFA8 data a1
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
struct Node;
struct Descriptor;
struct CharBuf;
struct MsgBank;
struct U16Vec;
struct PrintSys;
struct Cfg;
typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned char u8;

typedef short s16;

/* The manual data object built by MANUAL_COMMON_CreateData (was State_021B9B3C / Obj views). */
struct ManualData {
    void *owner;        /* 0x00 save/state object */
    u16 heap;           /* 0x04 */
    u16 pad06;
    void *screen;       /* 0x08 */
    void *font;         /* 0x0C */
    void *printQue[3];  /* 0x10 */
    void *bank[2];      /* 0x1C */
    void *arc[2];       /* 0x24 */
    void *assets;       /* 0x2C */
    u16 id;             /* 0x30 */
    u16 pad32;
    void *group;        /* 0x34 */
};

/* ManualWork + 0x20: the list owner region. */
struct ManualListOwner {
    u16 originX;        /* 0x00 */
    u16 originY;        /* 0x02 */
    u32 hasDetail;      /* 0x04 */
    u16 detailEntry;    /* 0x08 */
    u16 pad0A;
};

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

/* One 8-byte selection table row. */
struct ManualListEntry { u16 item; u16 count; u32 flag; };

/* The selection list built by MANUAL_CATEGORY_CreateList and MANUAL_CATEGORY_CreateDetailList. */
struct ManualMenuList {
    void *owner;            /* 0x00 list or detail owner region */
    void *data;             /* 0x04 */
    u32 ready;              /* 0x08 */
    u16 entryCount;         /* 0x0C */
    u16 pad0E;
    struct ManualListEntry *entries;  /* 0x10 */
    u16 savedA;             /* 0x14 restored to the owner on delete */
    u16 savedB;             /* 0x16 */
    u32 mode;               /* 0x18 */
    void *widget;           /* 0x1C */
    void *task;             /* 0x20 */
};

/* The option/detail work built by MANUAL_CATEGORY_CreateOption. */
struct ManualOptionWork {
    void *owner;            /* 0x00 ManualWork + 0x48 */
    void *data;             /* 0x04 */
    u8 cursor;              /* 0x08 */
    u8 pad09[3];
    u32 dirty;              /* 0x0C */
    void *bg[3];            /* 0x10 */
    struct PrintSys *que[3];/* 0x1C */
    u32 flag[3];            /* 0x28 */
    void *task;             /* 0x34 */
    u32 state;              /* 0x38 */
    signed char timer;      /* 0x3C */
    u8 pad3D[3];
};

/* ManualWork + 0x48: the option owner region. */
struct ManualOptionOwner {
    u8 entryCount;          /* 0x00 */
    u8 pad01;
    u16 selectedId;         /* 0x02 */
    struct { u16 item; u16 count; } entries[9];  /* 0x04 */
    u32 closeFlag;          /* 0x28 */
};

typedef enum { FLAG_FALSE, FLAG_TRUE } Flag;

typedef struct { u8 v[9]; } ManualSlotRecord;

extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern void *func_020056A0(unsigned,unsigned,unsigned);
extern u16 MANUAL_COMMON_GetGroupCount(const char *p);
extern u16 MANUAL_COMMON_GetGroupValue1(char *,int);
extern u16 MANUAL_COMMON_GetGroupValue2(char *,int,int);
extern u16 MANUAL_COMMON_GetEntryValue1(char *,int);
extern int MANUAL_COMMON_CheckUnlocked(void *,int,void *);
extern u16 MANUAL_COMMON_GetGroupValue0(char *,int);
extern void *MANUAL_COMMON_CreateListWork(char *owner, struct ManualData *data);
extern void func_02030EAC(struct Node *);
extern void MANUAL_COMMON_DeleteListWork(char *);
extern u32 func_020307B0(void *p);
extern int MANUAL_COMMON_UpdateListWork(char *p);
extern u16 MANUAL_COMMON_GetEntryCount(const char *p);
extern u16 MANUAL_COMMON_GetEntryValue2(char *, int);
extern int MANUAL_COMMON_GetSaveValue(void *, int, int);
extern u16 MANUAL_COMMON_GetEntryValue0(char *, int);
extern void MANUAL_COMMON_SetTouchbarState(char *, unsigned);
extern void MANUAL_COMMON_SetTouchbarSelection(char *, unsigned, unsigned);
extern int MANUAL_COMMON_GetDefaultId(void *);
extern void MANUAL_COMMON_SetScreenId(char *,u32);
extern void TCB_DeleteTask(struct Node *);
extern void MANUAL_COMMON_UpdateTouchbar(char *);
extern unsigned MANUAL_COMMON_GetTouchbarPressed(char *p);
extern unsigned MANUAL_COMMON_GetTouchbarSelected(char *p);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u32 ARC_UTIL_UploadBgPaletteAddFromHandleExt(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void BG_SYS_SetFlagField06(u32);
extern u32 BMP_WIN_Create(u32 layer,u32 a,u32 b,u32 tiles,u8 c,u8 d,u8 slot);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *p,u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *p);
extern void *func_02045EC0(struct MsgBank *p,u32 index);
extern void PRINTSYS_PrintQueColor(void *p,u32 a,u32 b,u32 c,u32 d,u32 e,u16 f);
extern void STRBUF_Delete(struct U16Vec *p);
extern void PRINTSYS_QUE_Clear(struct PrintSys *);
extern void BMP_WIN_ClearScreen(struct Descriptor *);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p,void *value);
extern void BMP_WIN_MakeScreen(struct Cfg *p);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(u32 channel);
char *MANUAL_CATEGORY_CreateList(char *p,char *data);
void MANUAL_CATEGORY_DeleteList(char *p);
int MANUAL_CATEGORY_IsListFinished(char *p);
void MANUAL_CATEGORY_TaskNoop(void);
struct ManualMenuList *MANUAL_CATEGORY_CreateDetailList(struct ManualDetailOwner *p, struct ManualData *data);
void MANUAL_CATEGORY_DeleteDetailList(char *p);
int MANUAL_CATEGORY_IsDetailFinished(char *p);
void MANUAL_CATEGORY_DetailTaskNoop(void);
char *MANUAL_CATEGORY_CreateOption(char *p, char *data);
void MANUAL_CATEGORY_DeleteOption(char *p);
int MANUAL_CATEGORY_UpdateOption(char *p);
void MANUAL_CATEGORY_OptionTaskNoop(void *p);
void MANUAL_CATEGORY_LoadOptionAssets(char *p);
void MANUAL_CATEGORY_SetOptionBgMode(char *a0);
void MANUAL_CATEGORY_OptionNoop(char *a0);
void MANUAL_CATEGORY_CreateOptionSlots(u8 *p);
void MANUAL_CATEGORY_DeleteOptionSlots(char *p);
void MANUAL_CATEGORY_UpdateOptionSlots(u8 *p);
void MANUAL_CATEGORY_DrawOption(char *p);
extern const char gManualCategoryListAllocFile[];
extern const char gManualCategoryDetailAllocFile[];
extern const char gManualCategoryOptionAllocFile[];
extern const ManualSlotRecord gManualCategorySlotRecords[];


char *MANUAL_CATEGORY_CreateList(char *p,char *data)
{
    char *q;
    u16 groups,items;
    u16 i,j,valid;
    q=func_02030734(((struct ManualData *)data)->heap,0x24,1,gManualCategoryListAllocFile,0x5c);
    *(char * *)&((struct ManualMenuList *)q)->owner=p;
    ((struct ManualListOwner *)p)->hasDetail=0;
    ((struct ManualListOwner *)(*(char * *)&((struct ManualMenuList *)q)->owner))->detailEntry=0;
    *(char * *)&((struct ManualMenuList *)q)->data=data;
    ((struct ManualMenuList *)q)->ready=0;
    groups=MANUAL_COMMON_GetGroupCount(*(char * *)&((struct ManualData *)data)->assets);
    ((struct ManualMenuList *)q)->entryCount=0;
    *(char * *)&((struct ManualMenuList *)q)->entries=func_02030734(((struct ManualData *)(*(char * *)&((struct ManualMenuList *)q)->data))->heap,groups*8,1,gManualCategoryListAllocFile,0x71);
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
    ((struct ManualMenuList *)q)->task=func_020056A0((unsigned)MANUAL_CATEGORY_TaskNoop,(unsigned)q,1);
    return q;
}


/*
 * extent: 94-byte unit; two zero alignment bytes at 021BB852 are outside the unit.
 * followers: parent cleared 021BB844 tail stub and 021BB850 empty Thumb leaf.
 */
void MANUAL_CATEGORY_DeleteList(char *p)
{
    func_02030EAC(*(struct Node * *)&((struct ManualMenuList *)p)->task);
    *(u16 *)*(char * *)&((struct ManualMenuList *)p)->owner = ((struct ManualMenuList *)p)->savedA;
    ((struct ManualListOwner *)(*(char * *)&((struct ManualMenuList *)p)->owner))->originY = ((struct ManualMenuList *)p)->savedB;
    if (((struct ManualMenuList *)p)->mode == 0) ((struct ManualListOwner *)(*(char * *)&((struct ManualMenuList *)p)->owner))->hasDetail = 0;
    else if (((struct ManualMenuList *)p)->mode == 1) {
        ((struct ManualListOwner *)(*(char * *)&((struct ManualMenuList *)p)->owner))->hasDetail = 1;
        ((struct ManualListOwner *)(*(char * *)&((struct ManualMenuList *)p)->owner))->detailEntry = *(u16 *)(*(char * *)&((struct ManualMenuList *)p)->entries + ((struct ManualListOwner *)(*(char * *)&((struct ManualMenuList *)p)->owner))->originY * 8);
    }
    MANUAL_COMMON_DeleteListWork(*(char * *)&((struct ManualMenuList *)p)->widget);
    func_020307B0(((struct ManualMenuList *)p)->entries);
    func_020307B0(p);
}


int MANUAL_CATEGORY_IsListFinished(char *p)
{
    return MANUAL_COMMON_UpdateListWork(*(char * *)&((struct ManualMenuList *)p)->widget);
}


void MANUAL_CATEGORY_TaskNoop(void)
{
}


struct ManualMenuList *MANUAL_CATEGORY_CreateDetailList(struct ManualDetailOwner *p, struct ManualData *data)
{
    struct ManualMenuList *q;
    u32 t, t0;
    int g;
    u16 ca, cb;
    int ra, rb;
    q = func_02030734(data->heap, 0x24, 1, gManualCategoryDetailAllocFile, 0x61);
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
        q->entries = func_02030734(((struct ManualData *)q->data)->heap, ca * 8, 1, gManualCategoryDetailAllocFile, 0x79);
        {
            u16 i;
        for (i = 0; i < ca; i++) {
            u16 id;
            int id2;
            id = MANUAL_COMMON_GetGroupValue2(((struct ManualData *)q->data)->assets, g, i);
            id2 = MANUAL_COMMON_GetEntryValue1(((struct ManualData *)q->data)->assets, id);
            if (MANUAL_COMMON_CheckUnlocked(((struct ManualData *)q->data)->assets, id2, ((struct ManualData *)q->data)->owner)) {
                t = MANUAL_COMMON_GetEntryValue2(((struct ManualData *)q->data)->assets, id);
                ra = MANUAL_COMMON_GetSaveValue(((struct ManualData *)q->data)->assets, t, (int)((struct ManualData *)q->data)->owner);
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
        q->entries = func_02030734(((struct ManualData *)q->data)->heap, cb * 8, 1, gManualCategoryDetailAllocFile, 0xB2);
        {
            u16 i;
        for (i = 0; i < cb; i++) {
            int id;
            id = MANUAL_COMMON_GetEntryValue1(((struct ManualData *)q->data)->assets, i);
            if (MANUAL_COMMON_CheckUnlocked(((struct ManualData *)q->data)->assets, id, ((struct ManualData *)q->data)->owner)) {
                t = MANUAL_COMMON_GetEntryValue2(((struct ManualData *)q->data)->assets, i);
                rb = MANUAL_COMMON_GetSaveValue(((struct ManualData *)q->data)->assets, t, (int)((struct ManualData *)q->data)->owner);
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
    q->task = func_020056A0((unsigned)MANUAL_CATEGORY_DetailTaskNoop, (unsigned)q, 1);
    return q;
}


/*
 * extent: 94-byte unit; two zero alignment bytes at 021BBA72 are outside the unit.
 * followers: parent cleared 021BBA64 tail stub and 021BBA70 empty Thumb leaf.
 */
void MANUAL_CATEGORY_DeleteDetailList(char *p)
{
    func_02030EAC(*(struct Node * *)&((struct ManualMenuList *)p)->task);
    ((struct ManualDetailOwner *)(*(char * *)&((struct ManualMenuList *)p)->owner))->count = ((struct ManualMenuList *)p)->savedA;
    ((struct ManualDetailOwner *)(*(char * *)&((struct ManualMenuList *)p)->owner))->selected = ((struct ManualMenuList *)p)->savedB;
    if (((struct ManualMenuList *)p)->mode == 0) ((struct ManualDetailOwner *)(*(char * *)&((struct ManualMenuList *)p)->owner))->subFlag = 0;
    else if (((struct ManualMenuList *)p)->mode == 1) {
        ((struct ManualDetailOwner *)(*(char * *)&((struct ManualMenuList *)p)->owner))->subFlag = 1;
        ((struct ManualDetailOwner *)(*(char * *)&((struct ManualMenuList *)p)->owner))->entryId = *(u16 *)(*(char * *)&((struct ManualMenuList *)p)->entries + ((struct ManualDetailOwner *)(*(char * *)&((struct ManualMenuList *)p)->owner))->selected * 8);
    }
    MANUAL_COMMON_DeleteListWork(*(char * *)&((struct ManualMenuList *)p)->widget);
    func_020307B0(((struct ManualMenuList *)p)->entries);
    func_020307B0(p);
}


int MANUAL_CATEGORY_IsDetailFinished(char *p)
{
    return MANUAL_COMMON_UpdateListWork(*(char * *)&((struct ManualMenuList *)p)->widget);
}


void MANUAL_CATEGORY_DetailTaskNoop(void)
{
}


/*
 * arity: BBC44 retains original visible r0 context although its fixed tail ignores it.
 */
char *MANUAL_CATEGORY_CreateOption(char *p, char *data)
{
    char *q;
    q = func_02030734(((struct ManualData *)data)->heap, 64, 1, gManualCategoryOptionAllocFile, 156);
    *(char * *)&((struct ManualOptionWork *)q)->owner = p;
    ((struct ManualOptionOwner *)p)->closeFlag = 0;
    *(char * *)&((struct ManualOptionWork *)q)->data = data;
    q[8] = 0;
    ((struct ManualOptionWork *)q)->dirty = 0;
    MANUAL_CATEGORY_LoadOptionAssets(q);
    MANUAL_CATEGORY_SetOptionBgMode(q);
    MANUAL_CATEGORY_CreateOptionSlots((u8 *)q);
    ((struct ManualOptionWork *)q)->task = func_020056A0((unsigned)MANUAL_CATEGORY_OptionTaskNoop, (unsigned)q, 1);
    ((struct ManualOptionWork *)q)->state = 0;
    q[0x3c] = -1;
    MANUAL_COMMON_SetTouchbarState(*(char * *)&((struct ManualData *)(*(char * *)&((struct ManualOptionWork *)q)->data))->group, 3);
    MANUAL_COMMON_SetTouchbarSelection(*(char * *)&((struct ManualData *)(*(char * *)&((struct ManualOptionWork *)q)->data))->group, *(u8 *)*(char * *)&((struct ManualOptionWork *)q)->owner, ((struct ManualOptionWork *)q)->cursor);
    MANUAL_CATEGORY_DrawOption(q);
    return q;
}


void MANUAL_CATEGORY_DeleteOption(char *p) { MANUAL_COMMON_SetScreenId(*(char * *)&((struct ManualOptionWork *)p)->data,MANUAL_COMMON_GetDefaultId(((struct ManualData *)(*(char * *)&((struct ManualOptionWork *)p)->data))->assets)); TCB_DeleteTask(*(struct Node * *)&((struct ManualOptionWork *)p)->task); func_020307B0(p); }


int MANUAL_CATEGORY_UpdateOption(char *p)
{
    int result = 0;
    int timer = ((struct ManualOptionWork *)p)->timer;
    int choice;
    if (timer == 0) result = 1;
    else if (timer > 0) {
        if (timer == 1) {
            MANUAL_CATEGORY_DeleteOptionSlots(p);
            MANUAL_CATEGORY_OptionNoop(p);
        }
        ((struct ManualOptionWork *)p)->timer -= 1;
    }
    if (((struct ManualOptionWork *)p)->state != 1) MANUAL_CATEGORY_UpdateOptionSlots((u8 *)p);
    if (((struct ManualOptionWork *)p)->state == 0 || ((struct ManualOptionWork *)p)->state == 2) {
        MANUAL_COMMON_UpdateTouchbar(*(char * *)&((struct ManualData *)(*(char * *)&((struct ManualOptionWork *)p)->data))->group);
        if (((struct ManualOptionWork *)p)->state == 0) {
            choice = MANUAL_COMMON_GetTouchbarPressed(*(char * *)&((struct ManualData *)(*(char * *)&((struct ManualOptionWork *)p)->data))->group);
            if (choice == -1) goto done;
            ((struct ManualOptionWork *)p)->state = 2;
            if (choice == 4) {
                if (((struct ManualOptionWork *)p)->cursor != 0) {
                    ((struct ManualOptionWork *)p)->cursor -= 1;
                    ((struct ManualOptionWork *)p)->dirty = 1;
                }
            } else if (choice == 5) {
                if (((struct ManualOptionWork *)p)->cursor < *(u8 *)*(char * *)&((struct ManualOptionWork *)p)->owner - 1) {
                    ((struct ManualOptionWork *)p)->cursor += 1;
                    ((struct ManualOptionWork *)p)->dirty = 1;
                }
            }
            if (((struct ManualOptionWork *)p)->dirty) MANUAL_CATEGORY_DrawOption(p);
        } else {
            choice = MANUAL_COMMON_GetTouchbarSelected(*(char * *)&((struct ManualData *)(*(char * *)&((struct ManualOptionWork *)p)->data))->group);
            if (choice == -1) goto done;
            switch (choice) {
            case 1:
                ((struct ManualOptionOwner *)(*(char * *)&((struct ManualOptionWork *)p)->owner))->closeFlag = 0;
                ((struct ManualOptionWork *)p)->state = 1;
                ((struct ManualOptionWork *)p)->timer = 1;
                break;
            case 4: case 5:
                ((struct ManualOptionWork *)p)->state = 0;
                if (((struct ManualOptionWork *)p)->dirty) {
                    MANUAL_COMMON_SetTouchbarSelection(*(char * *)&((struct ManualData *)(*(char * *)&((struct ManualOptionWork *)p)->data))->group, *(u8 *)*(char * *)&((struct ManualOptionWork *)p)->owner, ((struct ManualOptionWork *)p)->cursor);
                    ((struct ManualOptionWork *)p)->dirty = 0;
                }
                break;
            }
        }
    }
done:
    return result;
}


/*
 * leaf: sole unresolved BA74 callback; parent clearance. Thumb bx lr, then two zero alignment bytes.
 */
void MANUAL_CATEGORY_OptionTaskNoop(void *p)
{
}


void MANUAL_CATEGORY_LoadOptionAssets(char *p)
{
    func_02049B68((void *)(((struct ManualData *)(*(char * *)&((struct ManualOptionWork *)p)->data))->arc[0]), 0, 4, 0, 64, ((struct ManualData *)(*(char * *)&((struct ManualOptionWork *)p)->data))->heap);
    func_02049658((void *)(((struct ManualData *)(*(char * *)&((struct ManualOptionWork *)p)->data))->arc[0]), 2, 4, 0, 0, 0, ((struct ManualData *)(*(char * *)&((struct ManualOptionWork *)p)->data))->heap);
    ARC_UTIL_UploadBgPaletteAddFromHandleExt((void *)(((struct ManualData *)(*(char * *)&((struct ManualOptionWork *)p)->data))->arc[0]), 6, 4, 0, 0, 0, 0, ((struct ManualData *)(*(char * *)&((struct ManualOptionWork *)p)->data))->heap);
}


void MANUAL_CATEGORY_SetOptionBgMode(char *a0) { BG_SYS_SetFlagField06(4); }


void MANUAL_CATEGORY_OptionNoop(char *a0) {}


void MANUAL_CATEGORY_CreateOptionSlots(u8 *p)
{
    u8 index;
    u8 *slot;
    const ManualSlotRecord *record;
    u8 *owner;
    struct U16Vec *string;
    for(index=0;index<3;index++) {
        record=&gManualCategorySlotRecords[index];
        slot=p+index*4;
        *(u32 *)&((struct ManualOptionWork *)slot)->bg=BMP_WIN_Create(record->v[0],record->v[1],record->v[2],record->v[3],record->v[4],record->v[5],record->v[6]);
        BMP_Clear((struct CharBuf *)BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct ManualOptionWork *)slot)->bg),0);
        BMP_WIN_TransferChars(*(struct Descriptor * *)&((struct ManualOptionWork *)slot)->bg);
        ((struct ManualOptionWork *)slot)->flag[0]=0;
    }
    owner=*(u8 * *)&((struct ManualOptionWork *)p)->data;
    ((struct ManualOptionWork *)p)->que[0]=((struct ManualData *)owner)->printQue[0];
    *(u32 *)&((struct ManualOptionWork *)p)->que[1]=(u32)((struct ManualData *)owner)->printQue[0];
    ((struct ManualOptionWork *)p)->que[2]=((struct ManualData *)owner)->printQue[1];
    string=(struct U16Vec *)func_02045EC0(*(struct MsgBank * *)&((struct ManualData *)owner)->bank[1],((struct ManualOptionOwner *)(*(u8 * *)&((struct ManualOptionWork *)p)->owner))->selectedId);
    PRINTSYS_PrintQueColor(((struct ManualOptionWork *)p)->que[1],(u32)BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct ManualOptionWork *)p)->bg[1]),0,1,(u32)string,(u32)((struct ManualData *)(*(u8 * *)&((struct ManualOptionWork *)p)->data))->font,0x3C40);
    STRBUF_Delete(string);
    ((struct ManualOptionWork *)p)->flag[1]=1;
    MANUAL_CATEGORY_UpdateOptionSlots(p);
}


void MANUAL_CATEGORY_DeleteOptionSlots(char *p) { u8 i; for(i=0;i<3;i++) { ((struct ManualOptionWork *)p)->flag[i]=0; PRINTSYS_QUE_Clear(((struct ManualOptionWork *)p)->que[i]); BMP_WIN_ClearScreen((struct Descriptor *)((struct ManualOptionWork *)p)->bg[i]); BMP_WIN_Delete((struct Descriptor *)((struct ManualOptionWork *)p)->bg[i]); } BG_SYS_SetFlagField06(5); }


void MANUAL_CATEGORY_UpdateOptionSlots(u8 *p)
{
    u8 index;
    u8 *slot;
    struct Descriptor *descriptor;
    for(index=0;index<3;index++) {
        slot=p+index*4;
        if(((struct ManualOptionWork *)slot)->flag[0]!=0) {
            if(PRINTSYS_QUE_IsExistTarget(*(struct PrintSys * *)&((struct ManualOptionWork *)slot)->que[0],BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct ManualOptionWork *)slot)->bg))==0) {
                descriptor=*(struct Descriptor * *)&((struct ManualOptionWork *)slot)->bg;
                BMP_WIN_TransferChars(descriptor);
                BMP_WIN_MakeScreen((struct Cfg *)descriptor);
                func_02041B6C(BMP_WIN_GetBgLayer(descriptor));
                ((struct ManualOptionWork *)slot)->flag[0]=0;
            }
        }
    }
}


void MANUAL_CATEGORY_DrawOption(char *p)
{
    void *r;

    PRINTSYS_QUE_Clear(((struct ManualOptionWork *)p)->que[2]);
    BMP_Clear(BMP_WIN_GetBmp(((struct ManualOptionWork *)p)->bg[2]), 0);
    r = func_02045EC0(((struct ManualData *)(*(char * *)&((struct ManualOptionWork *)p)->data))->bank[1],
                      *(u16 *)(*(char * *)&((struct ManualOptionWork *)p)->owner + (((struct ManualOptionWork *)p)->cursor << 2) + 6));
    PRINTSYS_PrintQueColor(((struct ManualOptionWork *)p)->que[2], (u32)BMP_WIN_GetBmp(((struct ManualOptionWork *)p)->bg[2]),
                  4, 6, (u32)r, (u32)((struct ManualData *)(*(char * *)&((struct ManualOptionWork *)p)->data))->font, 0x440);
    STRBUF_Delete(r);
    ((struct ManualOptionWork *)p)->flag[2] = 1;
    MANUAL_CATEGORY_UpdateOptionSlots((u8 *)p);
    MANUAL_COMMON_SetScreenId(((struct ManualOptionWork *)p)->data,
                  *(u16 *)(*(char * *)&((struct ManualOptionWork *)p)->owner + (((struct ManualOptionWork *)p)->cursor << 2) + 4));
}
