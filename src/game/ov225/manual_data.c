/*
 * file:     manual_data.c
 * unit:     yes
 * function: MANUAL_COMMON_CreateMenuTable, MANUAL_COMMON_DeleteMenuTable, MANUAL_COMMON_GetEntryValue0, MANUAL_COMMON_GetEntryValue1, MANUAL_COMMON_GetEntryValue2, MANUAL_COMMON_GetEntryValue3, MANUAL_COMMON_GetEntryPair0, MANUAL_COMMON_GetEntryPair1, MANUAL_COMMON_GetEntryCount, MANUAL_COMMON_GetGroupValue0, MANUAL_COMMON_GetGroupValue1, MANUAL_COMMON_GetGroupValue2, MANUAL_COMMON_GetGroupCount, MANUAL_COMMON_CheckUnlocked, MANUAL_COMMON_GetSaveValue, MANUAL_COMMON_SetSaveValue, MANUAL_COMMON_IsValidKey, MANUAL_COMMON_GetDefaultId, MANUAL_COMMON_GetGroupEntry, MANUAL_COMMON_GetGroupOffset, MANUAL_COMMON_GetEntry, MANUAL_COMMON_GetEntryOffset
 * address:  0x021B9B3C
 * region:   ov225
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from manual_common.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   ARC_UTIL_LoadHandleMemberWithSize 0x0204A39C arm
 *   gManualCommonTableAllocFile 0x021BBFF4 data ov225 a1
 *   GFL_HEAP_Free 0x020307B0 arm
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   BLOCK20_SAVEDATA_GetBlock 0x02009210 thumb
 *   CGEAR_SAVE_GetObtained 0x020090E0 thumb
 *   GAME_DATA_GetEventWork 0x0201296C thumb
 *   ZONEDATA_CheckEventFlag 0x020142E8 thumb
 *   MISC_SAVEDATA_GetBlock44  0x0200ED48  thumb
 *   MISC_SAVEDATA_TestBitmapBit  0x0200EDEC  thumb
 *   MISC_SAVEDATA_SetBitmapBit 0x0200EE14 thumb
 */
#include "manual_data_shared_types.h"

struct Big;

struct Sub02009210Obj;

struct Sub020090B0Obj;

struct BigObj;

struct ManualMenuTable;

/* Archive table object returned by MANUAL_COMMON_CreateMenuTable (0x10). */
struct ManualMenuTable {
    u32 base0;      /* 0x00 group table base */
    u32 offsets0;   /* 0x04 group offset array */
    u32 base1;      /* 0x08 entry table base */
    u32 offsets1;   /* 0x0C entry offset array */
};

extern void *GFL_HEAP_Alloc(u32, u32, int, const char *, u16);

extern void *ARC_UTIL_LoadHandleMemberWithSize(void *, int, int, u32, u32 *);

extern u32 GFL_HEAP_Free(void *p);

extern void *GAME_DATA_GetSaveControl(struct Big *);

extern struct Sub02009210Obj *BLOCK20_SAVEDATA_GetBlock(void *);

extern u8 CGEAR_SAVE_GetObtained(const struct Sub020090B0Obj *);

extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);

extern unsigned ZONEDATA_CheckEventFlag(void *,int);

extern void *MISC_SAVEDATA_GetBlock44(void *p);

extern int MISC_SAVEDATA_TestBitmapBit(char *obj, int i);

extern void MISC_SAVEDATA_SetBitmapBit(char *obj, int i);

void *MANUAL_COMMON_CreateMenuTable(void *narc, u32 heap);

void MANUAL_COMMON_DeleteMenuTable(char *p);

u16 MANUAL_COMMON_GetEntryValue0(char *p,int index);

u16 MANUAL_COMMON_GetEntryValue1(char *p,int index);

u16 MANUAL_COMMON_GetEntryValue2(char *p,int index);

u16 MANUAL_COMMON_GetEntryValue3(char *p,int index);

u16 MANUAL_COMMON_GetEntryPair0(char *p, int idx, int c);

u16 MANUAL_COMMON_GetEntryPair1(char *p, int idx, int c);

u16 MANUAL_COMMON_GetEntryCount(const char *p);

u16 MANUAL_COMMON_GetGroupValue0(char *p,int index);

u16 MANUAL_COMMON_GetGroupValue1(char *p,int index);

u16 MANUAL_COMMON_GetGroupValue2(char *p, int idx, int c);

u16 MANUAL_COMMON_GetGroupCount(const char *p);

int MANUAL_COMMON_CheckUnlocked(void *unused,int kind,void *save);

int MANUAL_COMMON_GetSaveValue(void *unused, int b, int c);

void MANUAL_COMMON_SetSaveValue(void *unused,int code,struct Big *save);

int MANUAL_COMMON_IsValidKey(unsigned unused,unsigned key);

int MANUAL_COMMON_GetDefaultId(void *a0);

int MANUAL_COMMON_GetGroupEntry(char *p, int idx);

unsigned short MANUAL_COMMON_GetGroupOffset(char *p,unsigned i);

int MANUAL_COMMON_GetEntry(char *p, int idx);

unsigned short MANUAL_COMMON_GetEntryOffset(char *p,unsigned i);

extern char gManualCommonTableAllocFile[];

void *MANUAL_COMMON_CreateMenuTable(void *narc, u32 heap)
{
    void **table = GFL_HEAP_Alloc(heap, 16, 1, gManualCommonTableAllocFile, 0x9c);
    u32 size;
    table[0] = ARC_UTIL_LoadHandleMemberWithSize(narc, 11, 0, heap, &size);
    table[1] = ARC_UTIL_LoadHandleMemberWithSize(narc, 12, 0, heap, &size);
    table[2] = ARC_UTIL_LoadHandleMemberWithSize(narc, 9, 0, heap, &size);
    table[3] = ARC_UTIL_LoadHandleMemberWithSize(narc, 10, 0, heap, &size);
    return table;
}

void MANUAL_COMMON_DeleteMenuTable(char *table) {GFL_HEAP_Free((void *)((struct ManualMenuTable *)table)->offsets1);GFL_HEAP_Free((void *)((struct ManualMenuTable *)table)->base1);GFL_HEAP_Free((void *)((struct ManualMenuTable *)table)->offsets0);GFL_HEAP_Free((void *)((struct ManualMenuTable *)table)->base0);GFL_HEAP_Free(table);}

u16 MANUAL_COMMON_GetEntryValue0(char *table,int index) {return *(u16 *)(MANUAL_COMMON_GetGroupEntry(table,index)+6);}

u16 MANUAL_COMMON_GetEntryValue1(char *table,int index) {return *(u16 *)(MANUAL_COMMON_GetGroupEntry(table,index)+8);}

u16 MANUAL_COMMON_GetEntryValue2(char *table,int index) {return *(u16 *)(MANUAL_COMMON_GetGroupEntry(table,index)+10);}

u16 MANUAL_COMMON_GetEntryValue3(char *table,int index) {return *(u16 *)(MANUAL_COMMON_GetGroupEntry(table,index)+12);}

/*
 * Addresses are Black-image addresses.
 */
u16 MANUAL_COMMON_GetEntryPair0(char *table, int idx, int pair)
{
    return ((u16 *)MANUAL_COMMON_GetGroupEntry(table, idx))[(pair << 1) + 7];
}

u16 MANUAL_COMMON_GetEntryPair1(char *table, int idx, int pair)
{
    return ((u16 *)MANUAL_COMMON_GetGroupEntry(table, idx))[(pair << 1) + 8];
}

u16 MANUAL_COMMON_GetEntryCount(const char *table) {return **(u16 * *)&((struct ManualMenuTable *)table)->offsets0;}

u16 MANUAL_COMMON_GetGroupValue0(char *table,int index) {return *(u16 *)(MANUAL_COMMON_GetEntry(table,index)+2);}

u16 MANUAL_COMMON_GetGroupValue1(char *table,int index) {return *(u16 *)(MANUAL_COMMON_GetEntry(table,index)+4);}

u16 MANUAL_COMMON_GetGroupValue2(char *table, int idx, int index2)
{
    return ((u16 *)MANUAL_COMMON_GetEntry(table, idx))[index2 + 3];
}

u16 MANUAL_COMMON_GetGroupCount(const char *table) {return **(u16 * *)&((struct ManualMenuTable *)table)->offsets1;}

int MANUAL_COMMON_CheckUnlocked(void *unused,int kind,void *save)
{
    int result=0;
    switch(kind) {
    case 0:result=1;break;
    case 1:
        if(CGEAR_SAVE_GetObtained((const struct Sub020090B0Obj *)BLOCK20_SAVEDATA_GetBlock(GAME_DATA_GetSaveControl((struct Big *)save)))!=0)result=1;
        break;
    case 2:
        if(ZONEDATA_CheckEventFlag((void *)GAME_DATA_GetEventWork(save),2400)!=0)result=1;
        break;
    }
    return result;
}

int MANUAL_COMMON_GetSaveValue(void *unused, int id, int save)
{
    return MISC_SAVEDATA_TestBitmapBit(MISC_SAVEDATA_GetBlock44(GAME_DATA_GetSaveControl((struct Big *)save)), id);
}

void MANUAL_COMMON_SetSaveValue(void *unused,int value,struct Big *save) {MISC_SAVEDATA_SetBitmapBit(MISC_SAVEDATA_GetBlock44(GAME_DATA_GetSaveControl(save)),value);}

int MANUAL_COMMON_IsValidKey(unsigned unused,unsigned key) {if(key!=65535)return 1;return 0;}

int MANUAL_COMMON_GetDefaultId(void *unused){return 0x48;}

int MANUAL_COMMON_GetGroupEntry(char *table, int idx)
{
    return MANUAL_COMMON_GetGroupOffset(table, idx) + ((struct ManualMenuTable *)table)->base0;
}

unsigned short MANUAL_COMMON_GetGroupOffset(char *table,unsigned index){return *(unsigned short *)(((struct ManualMenuTable *)table)->offsets0+index*2+2);}

int MANUAL_COMMON_GetEntry(char *table, int idx)
{
    return MANUAL_COMMON_GetEntryOffset(table, idx) + ((struct ManualMenuTable *)table)->base1;
}

unsigned short MANUAL_COMMON_GetEntryOffset(char *table,unsigned index){return *(unsigned short *)(((struct ManualMenuTable *)table)->offsets1+index*2+2);}
