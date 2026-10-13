/*
 * file:     unit_02154CA0.c
 * unit:     yes
 * function: func_02154CA0, func_02154CC8, func_02154CF8, func_021550A0, func_021550B0
 * address:  0x02154CA0
 * region:   ov008
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02031324  0x02031324  arm
 *   func_0200FB24  0x0200FB24  thumb
 *   func_0200FB38  0x0200FB38  thumb
 *   func_0203133C  0x0203133C  arm
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   func_02031330  0x02031330  arm
 *   func_02031348  0x02031348  arm
 *   func_0203A5E4  0x0203A5E4  arm
 *   func_0203A574  0x0203A574  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_02034AC4  0x02034AC4  arm
 *   func_0200B424  0x0200B424  thumb
 *   func_0200B400  0x0200B400  thumb
 *   func_020399A8  0x020399A8  arm
 *   func_0203D594  0x0203D594  arm
 *   func_0203D5A0  0x0203D5A0  arm
 *   func_0200BA58  0x0200BA58  thumb
 *   func_0200BA68  0x0200BA68  thumb
 *   func_0200BA38  0x0200BA38  thumb
 *   func_021EEE78  0x021EEE78  thumb  ov188
 *   ov093_id       0x0000005D  data   a1
 *   ov097_id       0x00000061  data   a1
 *   ov213_id       0x000000D5  data   a1
 *   ov214_id       0x000000D6  data   a1
 *   d_021BB0B0     0x021BB0B0  data   ov213  a4
 *   d_021F75EC     0x021F75EC  data   ov097  a4
 *   d_021F03C4     0x021F03C4  data   ov093  a4
 *   d_021EFDAC     0x021EFDAC  data   ov093  a4
 *   d_021BB474     0x021BB474  data   ov214  a4
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_021550DC  0x021550DC  thumb  ov008
 */
#include "../../matched/include/Obj18644.h"
#include "../../matched/include/Obj18645.h"

struct Obj0203159C;
struct S020315D4;
struct S020314B8;
struct Entry;
struct Desc;
struct Obj;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef struct {
    int trainerId;
    char pad4[0xA - 4];
    u8 name[6];
} BattlePlayerSlot;

typedef struct {
    BattlePlayerSlot slot[4];
    int formatId;
    int modeId;
} BattleSlotTable;

typedef struct {
    char pad0[0x21];
    u8 playerIndex;
    u8 isMulti;
    char pad23[0x8C - 0x23];
    int battleType;
    char pad90[0x91 - 0x90];
    u8 recordVersion;
    char pad92[0x94 - 0x92];
    int hasRecord;
    char pad98[0xC8 - 0x98];
    u8 names[4][6];
} BattleInfo;

typedef struct {
    int gameSystem;
    BattleInfo *info;
    BattleSlotTable *slots;
    int flag;
    int extraFlag;
    int pad14;
    int resultGameSystem;
    int recordSupported;
    int isCommBattle;
    int saveEnabled;
    int resultFlag;
    int resultExtraFlag;
} BattleRecordWork;

typedef struct {
    int procsys;
    int playerIdFirst;
    int playerIdSecond;
    int swapped;
    int overlayLoaded;
    int cmdTableAdded;
    int recordWorkAllocated;
} BattleRecordCtx;

typedef signed int     s32;

extern void  func_0203064C(unsigned int a, unsigned int b, unsigned int c);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void *func_02031324(int a0);
extern u32 func_0200FB24(void);
extern void func_0200FB38(void);
extern void func_0203133C(struct S020314B8 *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(u32 heap);
extern unsigned int func_02031330(void *p);
extern void func_02031348(int h, u32 id, void *a, void *b);
extern void func_0203A5E4(u32 key);
extern void func_0203A574(u32 a, u32 b, u32 c, u32 d);
extern void func_02034A5C(s32 handle);
extern int func_02034AC4(s32 handle);
extern void func_0200B424(void);
extern void func_0200B400(u32 heap);
extern struct Entry *func_020399A8(void);
extern void func_0203D594(int a, int b);
extern int  func_0203D5A0(int a, int b);
extern void func_0200BA58(void);
extern void func_0200BA68(void);
extern u32 func_0200BA38(u32 v);
extern void func_021EEE78(void *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern int func_021550DC(int unused, int *stage, int *work);
int func_02154CA0(void *procsysOwner);
int func_02154CC8(void *procWork, int unused, char *taskWork, int *procsys);
u32 func_02154CF8(void *event, int *stage, BattleRecordWork *work, BattleRecordCtx *ctx);
void *func_021550A0(void *gameSystem, const int *args);
void *func_021550B0(void *gameSystem, int info, int slots, int flag);
extern char ov093_id[];
extern char ov097_id[];
extern char ov213_id[];
extern char ov214_id[];
extern char d_021BB0B0[];
extern char d_021F75EC[];
extern char d_021F03C4[];
extern char d_021EFDAC[];
extern char d_021BB474[];


int func_02154CA0(void *procsysOwner)
{
    u8 *procWork;

    func_0203064C(1, 0x76, 0x4000);
    procWork = func_0203159C(procsysOwner, 0x1c, 0x76);
    ((struct Obj18644 *)procWork)->f0 = (unsigned int)func_02031324(0x76);
    return 1;
}


int func_02154CC8(void *procWork, int unused, char *taskWork, int *procsys)
{
    if (((struct Obj18645 *)taskWork)->f14 == 1) {
        if (func_0200FB24() != 0)
            func_0200FB38();
    }
    func_0203133C((struct S020314B8 *)*procsys);
    func_020315D4(procWork);
    func_020306F0(0x76);
    return 1;
}


/*
 * 2026-10-05 wave P16 lane E10: stage 15 truth value is built after the call
 * (versionOk = f(recordVersion); nameRow = 1; if (versionOk == 0) nameRow = 0; zero arm for hasRecord == 0 shares the
 * same zero). Closes the 121-byte DIFF; the mid-function pool island follows.
 * BA38 returns u32.
 *
 * 18-stage task on *stage.  func_02031348's second/third arguments are an
 * overlay id and an address in that overlay (0xD5/ov213, 0x61/ov097,
 * 0xD6/ov214; the -1 one points into ov093, which stage 6 loads by id 0x5D
 * and stage 12 unloads).
 */
u32 func_02154CF8(void *event, int *stage, BattleRecordWork *work, BattleRecordCtx *ctx)
{
    int procsysBusy = func_02031330((void *)ctx->procsys);
    int lastPlayer, firstTeamBase, secondTeamBase, i, j, playerIndexBit, nameRow;
    u32 versionOk;

    if (procsysBusy != 1 && func_0200FB24() != 0 && *stage >= 0 && *stage < 13) {
        if (ctx->cmdTableAdded == 1)
            func_0203A5E4(0x100);
        if (ctx->overlayLoaded == 1)
            func_02034A5C((u32)ov093_id);
        if (ctx->recordWorkAllocated == 1)
            func_0200B424();
        return 1;
    }

    switch (*stage) {
    case 0:
        if (work->info->isMulti == 0)
            work->slots->modeId = 1;
        else
            work->slots->modeId = 3;
        func_02031348(ctx->procsys, (u32)ov213_id, d_021BB0B0, work->slots);
        *stage = 1;
        break;
    case 1:
        if (procsysBusy == 1)
            break;
        if (work->info->isMulti == 0)
            *stage = 6;
        else
            *stage = 2;
        break;
    case 2:
        func_0203D594((int)func_020399A8(), 0xC9);
        *stage = 3;
        break;
    case 3:
        if (func_0203D5A0((int)func_020399A8(), 0xC9) == 0)
            break;
        *stage = 4;
        break;
    case 4:
        if (work->info->playerIndex <= 1) {
            ctx->swapped = 0;
            ctx->playerIdFirst = work->slots->slot[0].trainerId;
            ctx->playerIdSecond = work->slots->slot[1].trainerId;
        } else {
            ctx->swapped = 1;
            ctx->playerIdFirst = work->slots->slot[1].trainerId;
            ctx->playerIdSecond = work->slots->slot[0].trainerId;
        }
        func_02031348(ctx->procsys, (u32)ov097_id, d_021F75EC, &ctx->playerIdFirst);
        *stage = 5;
        break;
    case 5:
        if (procsysBusy == 1)
            break;
        *stage = 6;
        break;
    case 6:
        ctx->overlayLoaded = 1;
        func_02034AC4((u32)ov093_id);
        ctx->cmdTableAdded = 1;
        func_0203A574(0x100, (u32)d_021F03C4, 9, 0);
        func_0203D594((int)func_020399A8(), 0xC8);
        *stage = 7;
        break;
    case 7:
        if (func_0203D5A0((int)func_020399A8(), 0xC8) == 0)
            break;
        *stage = 8;
        break;
    case 8:
        ctx->recordWorkAllocated = 1;
        func_0200B400(0x76);
        func_02031348(ctx->procsys, -1, d_021EFDAC, work->info);
        *stage = 9;
        break;
    case 9:
        if (procsysBusy == 1)
            break;
        *stage = 10;
        break;
    case 10:
        *stage = 11;
        break;
    case 11:
        func_0203D594((int)func_020399A8(), 0xCA);
        *stage = 12;
        break;
    case 12:
        if (func_0203D5A0((int)func_020399A8(), 0xCA) == 0)
            break;
        func_0203A5E4(0x100);
        ctx->cmdTableAdded = 0;
        func_02034A5C((u32)ov093_id);
        ctx->overlayLoaded = 0;
        func_0200BA58();
        func_021EEE78(work->info);
        func_0200BA68();
        *stage = 13;
        break;
    case 13:
        if (work->info->isMulti == 0)
            work->slots->modeId = 2;
        else
            work->slots->modeId = 4;
        switch (work->info->battleType) {
        case 1:
        case 4:
            work->slots->formatId = 0;
            break;
        case 0:
        case 3:
            work->slots->formatId = 1;
            break;
        case 2:
            work->slots->formatId = 2;
            break;
        case 6:
            break;
        default:
            work->slots->formatId = 2;
            break;
        }
        if (work->info->isMulti == 0) {
            lastPlayer = 1;
            firstTeamBase = 0;
            secondTeamBase = 1;
        } else {
            lastPlayer = 3;
            firstTeamBase = 0;
            secondTeamBase = 2;
        }
        playerIndexBit = work->info->playerIndex;
        for (i = 0; i <= lastPlayer; i++) {
            if ((i & 1) == (playerIndexBit & 1)) {
                if (playerIndexBit & 1)
                    nameRow = (i & 2) + 1;
                else
                    nameRow = i & 2;
                for (j = 0; j < 6; j++)
                    work->slots->slot[firstTeamBase + (i >> 1)].name[j] = work->info->names[nameRow][j];
            } else {
                if (playerIndexBit & 1)
                    nameRow = i & 2;
                else
                    nameRow = (i & 2) + 1;
                for (j = 0; j < 6; j++)
                    work->slots->slot[secondTeamBase + (i >> 1)].name[j] = work->info->names[nameRow][j];
            }
        }
        if (work->info->battleType == 6) {
            *stage = 16;
            break;
        }
        func_02031348(ctx->procsys, (u32)ov213_id, d_021BB0B0, work->slots);
        *stage = 14;
        break;
    case 14:
        if (procsysBusy == 1)
            break;
        *stage = 15;
        break;
    case 15:
        if (work->info->hasRecord == 0) nameRow = 0; else { versionOk = func_0200BA38(work->info->recordVersion); nameRow = 1; if (versionOk == 0) nameRow = 0; }
        work->recordSupported = nameRow;
        work->resultGameSystem = work->gameSystem;
        work->isCommBattle = 1;
        work->saveEnabled = 1;
        work->resultFlag = work->flag;
        work->resultExtraFlag = work->extraFlag;
        func_02031348(ctx->procsys, (u32)ov214_id, d_021BB474, &work->resultGameSystem);
        *stage = 16;
        break;
    case 16:
        if (procsysBusy == 1)
            break;
        func_0200B424();
        ctx->recordWorkAllocated = 0;
        *stage = 17;
        break;
    case 17:
        return 1;
    }
    return 0;
}

void *func_021550A0(void *gameSystem, const int *args)
{
    return func_021550B0(gameSystem, args[0], args[1], args[2]);
}


void *func_021550B0(void *gameSystem, int info, int slots, int flag)
{
    void *event = func_020122C0(gameSystem, 0, (void *)((int)func_021550DC), 0x40);
    u32 *work = func_020124E8(event);

    work[0] = (u32)gameSystem;
    work[1] = info;
    work[2] = slots;
    work[3] = flag;
    return event;
}
