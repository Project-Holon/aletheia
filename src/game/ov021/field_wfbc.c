/*
 * file:     field_wfbc.c
 * unit:     yes
 * function: func_021938AC, func_021938D4, func_021938F4, func_021938FC, func_02193904, func_0219390C, func_0219391C, func_02193920, func_02193924, func_021939C0, func_02193ABC, func_02193AFC, func_02193B04, func_02193B20, func_02193B40, func_02193B68, func_02193BC4, func_02193BE4, func_02193C00, func_02193C04, func_02193C08, func_02193C80, func_02193CBC, func_02193D08, func_02193D30, func_02193E54, func_02193EB4, func_02193EE8, func_02193EFC, func_02193F34, func_02193F6C, func_02193F80, func_02193FBC, func_02193FD4, func_02193FE8, func_02194014, func_02194038, func_02194044, func_02194078, func_02194084, func_02194128
 * address:  0x021938AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Lane CL120 cut the tail off at 0x02194284 (field_comm_actor.c), 0x02194670 (talkmsgwin.c) and 0x02196030 (ircbattlemenu.c).
 * Split from field_wfbc.c at 0x021938AC (__FILE__ anchor boundary, certain cut).
 *
 * symbols:
 *   func_02030734  0x02030734  arm  arm9
 *   sFieldWfbcFileName     0x021DDA60  data   ov021  a1
 *   func_0216D974  0x0216D974  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 *   func_021C939C  0x021C939C  thumb  ov021
 *   func_021C93E4  0x021C93E4  thumb  ov021
 *   func_021C9450  0x021C9450  thumb  ov021
 *   func_021C93D0  0x021C93D0  thumb  ov021
 *   func_020493D4  0x020493D4  arm
 *   func_02049250  0x02049250  arm
 *   func_0216245C  0x0216245C  thumb  ov010
 *   sConnectListMemberIds     0x021D3F60  data  a4
 *   func_0204A380  0x0204A380  arm
 *   func_0218E17C  0x0218E17C  thumb  ov021
 *   func_02186748  0x02186748  thumb  ov020
 *   func_0200846C  0x0200846C  thumb
 *   func_020084A0  0x020084A0  thumb
 *   func_020084D4  0x020084D4  thumb
 *   func_0200852C  0x0200852C  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_02186764  0x02186764  thumb
 *   func_02186770  0x02186770  thumb
 *   func_021867C4  0x021867C4  thumb  ov020
 *   func_020490F4  0x020490F4  arm
 *   func_02186830  0x02186830  thumb
 *   func_02049238  0x02049238  arm  arm9
 *   func_02186804  0x02186804  thumb  ov020
 *   func_0218683C  0x0218683C  thumb  ov020
 *   func_02082BCC  0x02082BCC  arm
 *   func_0218625C  0x0218625C  thumb  ov020
 *   func_02161ECC  0x02161ECC  thumb  ov010
 *   func_02186818  0x02186818  thumb  ov020
 *   func_02186844  0x02186844  thumb  ov020
 *   func_0218682C  0x0218682C  thumb  ov020
 *   func_0204932C  0x0204932C  arm
 *   sBlockTableMemberIds     0x021D3F58  data  a4
 *   func_0218609C  0x0218609C  thumb  ov020
 *   func_021860B8  0x021860B8  thumb  ov020
 *   func_021867B0  0x021867B0  thumb  ov020
 *   func_02082D44  0x02082D44  arm  arm9
 *   func_02186278  0x02186278  thumb  ov020
 */
struct ArcHandle;
struct EventDataSystem;
struct MmdlSys;
struct MyStatus;
struct WordSet;
struct WfbcNpcData;
struct LandDataPatch;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned long long u64;

#include "field_wfbc_types.h"

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void func_0216D974(struct MmdlSys *mmdlSys, int flag);
extern struct LandDataPatch *func_021C939C(u32 blockId, u32 heapId);
extern void func_021C93E4(struct LandDataPatch *patch, void *attrBuf, u32 srcX, u32 srcZ, u32 dstX, u32 dstZ, u32 sizeX, u32 sizeZ);
extern int func_021C9450(struct LandDataPatch *patch, int buildModelMan, int mapBlockIndex, int modelNum, int dstX, int dstZ);
extern void func_021C93D0(struct LandDataPatch *patch);
extern u32 func_020493D4(struct ArcHandle *arc, u32 member);
extern FieldWfbcConnectEntry *func_02049250(struct ArcHandle *arc, int member, u16 heapId);
extern void func_0216245C(struct EventDataSystem *eventData, u16 index);
extern void *func_0204A380(struct ArcHandle *arc, u32 member, u32 compressed, u32 heapId);
extern void func_0218E17C(u32 *camera, u32 value);
extern void func_02186748(WfbcPerson *person);
extern struct MyStatus *func_0200846C(int heapId);
extern void func_020084A0(struct MyStatus *myStatus);
extern u32 func_020084D4(struct MyStatus *myStatus, const u16 *name);
extern void func_0200852C(struct MyStatus *myStatus, u32 id);
extern void func_0201F02C(struct WordSet *wordSet, u32 bufIndex, struct MyStatus *myStatus);
extern void func_02186764(WfbcPerson *person);
extern int func_02186770(WfbcPerson *person);
extern struct WfbcNpcData *func_021867C4(int type, int heapId);
extern struct ArcHandle *func_020490F4(unsigned int arcId, unsigned int heapId);
extern u8 *func_02186830(struct WfbcNpcData *npcData, int cityType, int heapId);
extern void func_0218683C(u8 *posTable);
extern void func_02049238(struct ArcHandle *arc);
extern void func_02186804(struct WfbcNpcData *npcData);
extern u32 func_02082BCC(void *dst, int value, int size);
extern int func_0218625C(WfbcData *data);
extern int func_02161ECC(const WfbcPerson *person);
extern void func_02186818(struct WfbcNpcData *npcData, u32 npcId);
extern u8 *func_02186844(u8 *posTable, int index);
extern WfbcNpcRecord *func_0218682C(struct WfbcNpcData *npcData);
extern void func_0204932C(struct ArcHandle *arc, u32 member, void *dst);
extern void func_0218609C(WfbcData *data);
extern void func_021860B8(WfbcData *data);
extern int func_021867B0(const WfbcPerson *person);
extern void func_02082D44(const void *src, void *dst, int size);
extern int func_02186278(const WfbcData *data, int which);
FieldWfbc *func_021938AC(u32 heapId);
u32 func_021938D4(FieldWfbc *wfbc);
int func_021938F4(FieldWfbc *wfbc);
void func_021938FC(FieldWfbc *wfbc, WfbcData *saveData);
FieldWfbcPeople *func_0219390C(FieldWfbc *wfbc, u32 npcId);
u8 func_0219391C(FieldWfbc *wfbc);
u8 func_02193920(FieldWfbc *wfbc);
int func_02193924(FieldWfbc *wfbc, void *attrBuf, int buildModelMan, int mapBlockIndex, int modelNum, int cellX, int cellZ, u16 heapId);
void func_021939C0(FieldWfbc *wfbc, struct EventDataSystem *eventData, int skip, u32 heapId);
void func_02193ABC(FieldWfbc *wfbc, int camera, int heapId);
void func_02193AFC(FieldWfbc *wfbc, struct MmdlSys *mmdlSys);
void func_02193B04(FieldWfbc *wfbc, WfbcData *saveData, u32 isBackPeople, u32 heapId);
void func_02193B20(FieldWfbc *wfbc, u32 npcId);
void func_02193B40(FieldWfbc *wfbc, u32 npcId);
void func_02193B68(FieldWfbc *wfbc, struct WordSet *wordSet, int npcId, int bufIndex, u16 heapId);
void func_02193BC4(FieldWfbc *wfbc, u32 npcId);
int func_02193BE4(FieldWfbc *wfbc, u32 npcId);
WfbcNpcRecord *func_02193C00(FieldWfbcPeople *people);
WfbcPerson *func_02193C04(FieldWfbcPeople *people);
void func_02193C08(FieldWfbc *wfbc, int heapId);
void func_02193C80(FieldWfbc *wfbc);
void func_02193CBC(FieldWfbc *wfbc);
int func_02193D08(FieldWfbc *wfbc);
void func_02193D30(FieldWfbc *wfbc, WfbcData *saveData, int isBackPeople);
void func_02193E54(FieldWfbc *wfbc, WfbcData *saveData);
void func_02193EB4(FieldWfbc *wfbc);
void func_02193EE8(FieldWfbc *wfbc);
FieldWfbcPeople *func_02193EFC(FieldWfbc *wfbc, u32 npcId);
FieldWfbcPeople *func_02193F34(FieldWfbc *wfbc, u32 npcId);
void func_02193F6C(FieldWfbcPeople *people);
void func_02193F80(FieldWfbcPeople *people, const WfbcPerson *person, u8 *gridPos, const WfbcNpcRecord *npcRecord);
void func_02193FBC(FieldWfbcPeople *people, const WfbcPerson *src);
void func_02193FD4(FieldWfbcPeople *people, WfbcPerson *dst);
void func_02193FE8(FieldWfbcBlock (*blocks)[8]);
void func_02194014(FieldWfbcBlock (*blocks)[8], int x, int z, FieldWfbcBlockPos pos, u16 blockId);
FieldWfbcBlock func_02194038(FieldWfbcBlock (*blocks)[8], int x, int z);
int func_02194044(FieldWfbcBlock (*blocks)[8], u16 type, u16 blockId);
void func_02194078(FieldWfbcBlockRand *blockRand);
void func_02194084(FieldWfbcBlockRand *blockRand, WfbcData *data, struct WfbcNpcData *npcData);
void func_02194128(FieldWfbcBlockRand *blockRand, FieldWfbcBlockTable *table, FieldWfbcBlock (*blocks)[8]);
extern char sFieldWfbcFileName[];
extern int sConnectListMemberIds[];
extern int sBlockTableMemberIds[];

FieldWfbc *func_021938AC(u32 heapId)
{
    FieldWfbc *wfbc = func_02030734(heapId, sizeof(FieldWfbc), 1, sFieldWfbcFileName, 0x12A);
    func_02193CBC(wfbc);
    return wfbc;
}

u32 func_021938D4(FieldWfbc *wfbc)
{
    func_02193C80(wfbc);
    if (wfbc->mmdlSys != 0) {
        func_0216D974(wfbc->mmdlSys, 1);
    }
    return func_020307B0(wfbc);
}

int func_021938F4(FieldWfbc *wfbc)
{
    return func_02193D08(wfbc);
}

void func_021938FC(FieldWfbc *wfbc, WfbcData *saveData)
{
    func_02193E54(wfbc, saveData);
}

void func_02193904(FieldWfbc *wfbc)
{
    func_02193EB4(wfbc);
}

FieldWfbcPeople *func_0219390C(FieldWfbc *wfbc, u32 npcId)
{
    if (npcId < 30) {
        return func_02193F34(wfbc, npcId);
    }
    return 0;
}

u8 func_0219391C(FieldWfbc *wfbc)
{
    return wfbc->cityType;
}

u8 func_02193920(FieldWfbc *wfbc)
{
    return wfbc->isBackPeople;
}

/*
 * The cell comes back from func_02194038 as a 4-byte struct in r0; the high
 * nibble is read before the low one.
 */
int func_02193924(FieldWfbc *wfbc, void *attrBuf, int buildModelMan, int mapBlockIndex, int modelNum, int cellX, int cellZ, u16 heapId)
{
    FieldWfbcBlock cell = func_02194038(wfbc->blocks, cellX, cellZ);
    struct LandDataPatch *patch;
    int dstX, dstZ;
    int offsetX, offsetZ;

    if (cell.pos.type != 0xFF) {
        dstX = (cellX * 8) & 0x1F;
        dstZ = (cellZ * 8) & 0x1F;
        patch = func_021C939C(cell.blockId, (u16)((heapId & 0x7FFF) | 0x8000));
        offsetZ = cell.pos.offsetZ;
        offsetX = cell.pos.offsetX;
        func_021C93E4(patch, attrBuf, offsetX * 8, offsetZ * 8, dstX, dstZ, 8, 8);
        if (offsetX == 0 && offsetZ == 0) {
            modelNum = func_021C9450(patch, buildModelMan, mapBlockIndex, modelNum, dstX, dstZ);
        }
        func_021C93D0(patch);
    }
    return modelNum;
}

void func_021939C0(FieldWfbc *wfbc, struct EventDataSystem *eventData, int skip, u32 heapId)
{
    u32 entryNum;
    FieldWfbcConnectEntry *entries;
    u32 *placedConnects;
    u32 placedNum;
    u32 i;
    u32 j;
    FieldWfbcConnectEntry *cur;

    if (skip != 0)
        return;
    entryNum = func_020493D4(wfbc->arcHandle, sConnectListMemberIds[wfbc->cityType]);
    heapId = (heapId & 0x7FFF) | 0x8000;
    entries = func_02049250(wfbc->arcHandle, sConnectListMemberIds[wfbc->cityType], (u16)heapId);
    entryNum >>= 3;
    placedConnects = func_02030734((u16)heapId, entryNum * 4, 1, sFieldWfbcFileName, 0x208);
    placedNum = 0;
    for (i = 0; i < entryNum; i++) {
        cur = &entries[i];
        if (func_02194044(wfbc->blocks, entries[i].blockType, cur->blockId)) {
            placedConnects[placedNum] = cur->connectIndex;
            placedNum++;
        } else {
            for (j = 0; j < placedNum; j++) {
                if (placedConnects[j] == entries[i].connectIndex)
                    break;
            }
            if (j >= placedNum) {
                for (j = i + 1; j < entryNum; j++) {
                    if (cur->connectIndex == entries[j].connectIndex)
                        break;
                }
                if (j >= entryNum)
                    func_0216245C(eventData, (u16)cur->connectIndex);
            }
        }
    }
    func_020307B0(placedConnects);
    func_020307B0(entries);
}

void func_02193ABC(FieldWfbc *wfbc, int camera, int heapId)
{
    u16 *values;
    values = func_0204A380(wfbc->arcHandle, 0x24, 0, (u16)((heapId & 0x7fff) | 0x8000));
    func_0218E17C((u32 *)camera, values[func_021938F4(wfbc)]);
    func_020307B0(values);
}

void func_02193AFC(FieldWfbc *wfbc, struct MmdlSys *mmdlSys)
{
    wfbc->mmdlSys = mmdlSys;
}

void func_02193B04(FieldWfbc *wfbc, WfbcData *saveData, u32 isBackPeople, u32 heapId)
{
    func_02193C08(wfbc, heapId);
    func_02193D30(wfbc, saveData, isBackPeople);
}

void func_02193B20(FieldWfbc *wfbc, u32 npcId)
{
    func_02193EB4(wfbc);
    func_02193F6C(func_02193EFC(wfbc, npcId));
    func_02193EE8(wfbc);
}

void func_02193B40(FieldWfbc *wfbc, u32 npcId)
{
    FieldWfbcPeople *people;
    func_02193EB4(wfbc);
    people = func_02193EFC(wfbc, npcId);
    if (wfbc->isBackPeople == 0) {
        func_02186748(&people->person);
        func_02193EE8(wfbc);
    }
}

void func_02193B68(FieldWfbc *wfbc, struct WordSet *wordSet, int npcId, int bufIndex, u16 heapId)
{
    FieldWfbcPeople *people;
    struct MyStatus *myStatus;
    func_02193EB4(wfbc);
    people = func_02193F34(wfbc, npcId);
    myStatus = func_0200846C((u16)((heapId & 0x7fff) | 0x8000));
    func_020084A0(myStatus);
    func_020084D4(myStatus, people->person.parentName);
    func_0200852C(myStatus, people->person.parentId);
    func_0201F02C(wordSet, bufIndex, myStatus);
    func_020307B0(myStatus);
}

void func_02193BC4(FieldWfbc *wfbc, u32 npcId)
{
    func_02193EB4(wfbc);
    func_02186764(&func_02193EFC(wfbc, npcId)->person);
    func_02193EE8(wfbc);
}

int func_02193BE4(FieldWfbc *wfbc, u32 npcId)
{
    func_02193EB4(wfbc);
    return func_02186770(&func_02193F34(wfbc, npcId)->person);
}

WfbcNpcRecord *func_02193C00(FieldWfbcPeople *people)
{
    return &people->npcRecord;
}

WfbcPerson *func_02193C04(FieldWfbcPeople *people)
{
    return &people->person;
}

void func_02193C08(FieldWfbc *wfbc, int heapId)
{
    int i;
    if (wfbc->npcData == 0) {
        i = 0;
        wfbc->npcData = func_021867C4(0, heapId);
        wfbc->people = func_02030734(heapId, 10 * sizeof(FieldWfbcPeople), 1, sFieldWfbcFileName, 0x39e);
        for (i = 0; i < 10; i++) {
            func_02193F6C(&wfbc->people[i]);
        }
        wfbc->arcHandle = func_020490F4(0x9a, heapId);
        wfbc->blockTable = func_02030734(heapId, sizeof(FieldWfbcBlockTable), 1, sFieldWfbcFileName, 0x3ab);
        wfbc->mmdlPosTable = func_02186830(wfbc->npcData, wfbc->cityType, heapId);
    }
}

void func_02193C80(FieldWfbc *wfbc)
{
    if (wfbc->npcData != 0) {
        func_0218683C(wfbc->mmdlPosTable);
        func_020307B0(wfbc->blockTable);
        func_02049238(wfbc->arcHandle);
        func_02186804(wfbc->npcData);
        func_020307B0(wfbc->people);
        wfbc->npcData = 0;
        wfbc->people = 0;
        wfbc->arcHandle = 0;
        wfbc->blockTable = 0;
        wfbc->mmdlPosTable = 0;
    }
}

void func_02193CBC(FieldWfbc *wfbc)
{
    int i;
    FieldWfbcPeople *people = wfbc->people;
    wfbc->cityType = 0;
    wfbc->isBackPeople = 0;
    wfbc->saveData = 0;
    if (people != 0) {
        for (i = 0; i < 10; i++)
            func_02193F6C(&wfbc->people[i]);
    }
    if (wfbc->blockTable != 0)
        func_02082BCC(wfbc->blockTable, 0, sizeof(FieldWfbcBlockTable));
    func_02193FE8(wfbc->blocks);
    func_02194078(&wfbc->blockRand);
}

int func_02193D08(FieldWfbc *wfbc)
{
    int count = 0;
    int i;
    FieldWfbcPeople *people = wfbc->people;
    if (people != 0) {
        for (i = 0; i < 10; i++) {
            if (people[i].isActive != 0)
                count++;
        }
    }
    return count;
}

/*
 * The back-list branch calls func_0218682C once more before the call whose
 * result it passes; the call is kept (the original code makes it).
 */
void func_02193D30(FieldWfbc *wfbc, WfbcData *saveData, int isBackPeople)
{
    int i;
    u8 *gridPos;
    func_0218625C(saveData);
    func_02193CBC(wfbc);
    wfbc->cityType = saveData->cityType;
    wfbc->isBackPeople = isBackPeople;
    for (i = 0; i < 10; i++) {
        if (isBackPeople == 0) {
            if (func_02161ECC(&saveData->people[i])) {
                func_02186818(wfbc->npcData, saveData->people[i].npcId);
                func_02193F80(&wfbc->people[i], &saveData->people[i],
                              func_02186844(wfbc->mmdlPosTable, i),
                              func_0218682C(wfbc->npcData));
            }
        } else {
            if (func_02161ECC(&saveData->backPeople[i])) {
                func_02186818(wfbc->npcData, saveData->backPeople[i].npcId);
                gridPos = func_02186844(wfbc->mmdlPosTable, i);
                func_0218682C(wfbc->npcData);
                func_02193F80(&wfbc->people[i], &saveData->backPeople[i],
                              gridPos, func_0218682C(wfbc->npcData));
            }
        }
    }
    func_02194084(&wfbc->blockRand, saveData, wfbc->npcData);
    if (isBackPeople == 0)
        wfbc->saveData = saveData;
    else
        wfbc->saveData = 0;
    func_020493D4(wfbc->arcHandle, sBlockTableMemberIds[wfbc->cityType]);
    func_0204932C(wfbc->arcHandle, sBlockTableMemberIds[wfbc->cityType], wfbc->blockTable);
    func_02194128(&wfbc->blockRand, wfbc->blockTable, wfbc->blocks);
}

void func_02193E54(FieldWfbc *wfbc, WfbcData *saveData)
{
    int i;
    saveData->isValid = 1;
    saveData->cityType = wfbc->cityType;
    if (wfbc->isBackPeople == 0) {
        func_0218609C(saveData);
        for (i = 0; i < 10; i++)
            func_02193FD4(&wfbc->people[i], &saveData->people[i]);
    } else {
        func_021860B8(saveData);
        for (i = 0; i < 10; i++)
            func_02193FD4(&wfbc->people[i], &saveData->backPeople[i]);
    }
}

void func_02193EB4(FieldWfbc *wfbc)
{
    int i;
    if (wfbc->isBackPeople == 0 && wfbc->saveData != 0) {
        for (i = 0; i < 10; i++)
            func_02193FBC(&wfbc->people[i], &wfbc->saveData->people[i]);
    }
}

void func_02193EE8(FieldWfbc *wfbc)
{
    if (wfbc->isBackPeople == 0 && wfbc->saveData != 0)
        func_021938FC(wfbc, wfbc->saveData);
}

FieldWfbcPeople *func_02193EFC(FieldWfbc *wfbc, u32 npcId)
{
    int i;
    if (wfbc->people != 0) {
        for (i = 0; i < 10; i++) {
            if (wfbc->people[i].isActive != 0 && npcId == func_021867B0(&wfbc->people[i].person))
                return &wfbc->people[i];
        }
    }
    return 0;
}

/* Same code as func_02193EFC; the callers use both. */
FieldWfbcPeople *func_02193F34(FieldWfbc *wfbc, u32 npcId)
{
    int i;
    if (wfbc->people != 0) {
        for (i = 0; i < 10; i++) {
            if (wfbc->people[i].isActive != 0 && npcId == func_021867B0(&wfbc->people[i].person))
                return &wfbc->people[i];
        }
    }
    return 0;
}

void func_02193F6C(FieldWfbcPeople *people)
{
    func_02082BCC(people, 0, sizeof(FieldWfbcPeople));
    people->isActive = 0;
}

void func_02193F80(FieldWfbcPeople *people, const WfbcPerson *person, u8 *gridPos, const WfbcNpcRecord *npcRecord)
{
    func_02161ECC(person);
    people->isActive = 1;
    func_02082D44(person, &people->person, sizeof(WfbcPerson));
    func_02082D44(npcRecord, &people->npcRecord, sizeof(WfbcNpcRecord));
    people->gridX = gridPos[0];
    people->gridZ = gridPos[1];
}

void func_02193FBC(FieldWfbcPeople *people, const WfbcPerson *src)
{
    if (people->isActive == 1) {
        func_02082D44(src, &people->person, sizeof(WfbcPerson));
    }
}

void func_02193FD4(FieldWfbcPeople *people, WfbcPerson *dst)
{
    if (people->isActive == 1) {
        func_02082D44(&people->person, dst, sizeof(WfbcPerson));
    }
}

void func_02193FE8(FieldWfbcBlock (*blocks)[8])
{
    int z;
    int x;
    for (z = 0; z < 8; z++) {
        for (x = 0; x < 8; x++) {
            blocks[z][x].pos.type = 0xFF;
            blocks[z][x].blockId = 0xFFFF;
        }
    }
}

/*
 * The cell holds the position as one member; the struct copy
 * blocks[z][x].pos = pos emits the two byte stores, the first one addressed
 * [x*4, row].
 */
void func_02194014(FieldWfbcBlock (*blocks)[8], int x, int z, FieldWfbcBlockPos pos, u16 blockId)
{
    blocks[z][x].pos = pos;
    blocks[z][x].blockId = blockId;
}

FieldWfbcBlock func_02194038(FieldWfbcBlock (*blocks)[8], int x, int z)
{
    return blocks[z][x];
}

int func_02194044(FieldWfbcBlock (*blocks)[8], u16 type, u16 blockId)
{
    int z;
    int x;
    for (z = 0; z < 8; z++) {
        for (x = 0; x < 8; x++) {
            if (type == blocks[z][x].pos.type && blockId == blocks[z][x].blockId) {
                return 1;
            }
        }
    }
    return 0;
}

void func_02194078(FieldWfbcBlockRand *blockRand)
{
    func_02082BCC(blockRand, 0, sizeof(FieldWfbcBlockRand));
}

/*
 * WfbcNpcRecord+0x2E (pad2E in the ov020 header) is summed into the random
 * range here; it is read raw until the header owner names it.
 */
void func_02194084(FieldWfbcBlockRand *blockRand, WfbcData *data, struct WfbcNpcData *npcData)
{
    int recordSum;
    int npcIdSum;
    int i;
    recordSum = 0;
    npcIdSum = 0;
    for (i = 0; i < 10; i++) {
        if (func_02161ECC(&data->people[i]) != 0) {
            func_02186818(npcData, data->people[i].npcId);
            recordSum += *(u16 *)((u8 *)func_0218682C(npcData) + 0x2E);
            npcIdSum += data->people[i].npcId;
        }
    }
    blockRand->peopleNum = func_02186278(data, 0);
    blockRand->rand.x = data->playerId;
    blockRand->rand.mul = 0x5D588B656C078965ULL;
    blockRand->rand.add = 0x269EC3;
    if (blockRand->peopleNum == 0) {
        blockRand->randRange = 1;
    } else {
        blockRand->randRange = recordSum + 2;
    }
    blockRand->npcIdSum = npcIdSum;
    blockRand->seed = data->playerId;
}

static inline void MATH_InitRand32(MATHRandContext32 *context, u64 seed)
{
    context->x = seed;
    context->mul = 0x5d588b656c078965ULL;
    context->add = 0x269ec3ULL;
}

static inline u32 MATH_Rand32(MATHRandContext32 *context, u32 max)
{
    context->x = context->mul * context->x + context->add;
    if (max) {
        return (u32)(((context->x >> 32) * max) >> 32);
    } else {
        return (u32)(context->x >> 32);
    }
}

/*
 * Seeds a NitroSDK MATHRandContext32 at the head of blockRand
 * (MATH_InitRand32 inline) and fills the 8x8 block grid through
 * func_02194014. Spill-slot order (u64 max temp at the top, then row, z,
 * type, variant) needs the explicit locals in this declaration order; the
 * index `index += variant * 8` must be folded into index before the call or
 * the tail's loads schedule differently.
 */
void func_02194128(FieldWfbcBlockRand *blockRand, FieldWfbcBlockTable *table, FieldWfbcBlock (*blocks)[8])
{
    FieldWfbcBlockPos pos;
    u32 range;
    FieldWfbcBlockPos *row;
    int z;
    u8 type;
    u8 variant;
    int x;
    int index;
    int originX;
    int originZ;
    MATH_InitRand32(&blockRand->rand, blockRand->seed);
    for (z = 0; z < 8; z++) {
        row = table->layout[z];
        for (x = 0; x < 8; x++) {
            pos = row[x];
            type = pos.type;
            if (type == 0xFF) {
                continue;
            }
            if (pos.offsetX != 0 || pos.offsetZ != 0) {
                func_02194014(blocks, x, z, pos, blocks[z - pos.offsetZ][x - pos.offsetX].blockId);
            } else {
                originX = x - pos.offsetX;
                originZ = z - pos.offsetZ;
                variant = (u8)((u8)((u8)blockRand->npcIdSum + (u8)(originX + originZ)) / (u32)((originX + 3) + (originZ + 1))) % 2;
                index = (blockRand->peopleNum * 8) / 10;
                range = blockRand->randRange;
                index += MATH_Rand32(&blockRand->rand, range);
                if (index >= 8) {
                    index = 7;
                }
                index += variant * 8;
                func_02194014(blocks, x, z, pos, table->blockIds[type][index]);
            }
        }
    }
}
