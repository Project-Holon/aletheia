/*
 * file:     union_app.c
 * unit:     yes
 * function: func_02183B60, func_02183BE0, func_02183BE8, func_02183C3C, func_02183CC0, func_02183D34, func_02183D4C, func_02183D94, func_02183DAC, func_02183DDC, func_02183E48, func_02183EE0, func_02183F6C, func_02183F7C, func_02183F84, func_02183F88, func_02183F98, func_02183FA8, func_02183FB8, func_0218401C, func_0218402C, func_02184060, func_021840A4, func_021840A8, func_021840AC, func_021840C8, func_021840FC, func_02184114, func_02184134, func_02184148, func_0218416C, func_02184174, func_0218417C, func_02184180, func_021841A0
 * address:  0x02183B60
 * region:   ov022
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_0203D378  0x0203D378  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02087C6C  0x02087C6C  arm
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1A4  0x0203D1A4  arm
 *   d_021841C0     0x021841C0  data  a1
 *   func_020307B0  0x020307B0  arm
 *   func_02080D24  0x02080D24  arm
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02172D38  0x02172D38  thumb  ov012
 *   func_02172D68  0x02172D68  thumb  ov012
 *   func_0203D1C0  0x0203D1C0  arm
 *   INTRUDE_CMD_RecvResultRecord  0x0217410C  thumb  ov011
 *   UNION_COMMAND_SendAppSetting 0x02173F20 thumb ov012
 *   UNION_COMMAND_SendAppQuitAccept 0x02173E68 thumb ov012
 *   UNION_COMMAND_SendAppData 0x02174010 thumb ov012
 *   func_02173614  0x02173614  thumb  ov012
 *   func_02082D44  0x02082D44  arm
 *   func_02008550  0x02008550  thumb
 *   func_02008554  0x02008554  thumb
 *   func_0217357C  0x0217357C  thumb  ov012
 *   func_0203D1E8  0x0203D1E8  arm
 *   func_0203CD98 0x0203CD98 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef signed int s32;

typedef struct { s32 x, y, z; } VecFx32;
#include "../ov012/union_comm_types.h"
#include "union_app_types.h"

struct Entry;
struct Link;
struct Sub0200852CObj;

extern void *func_02030734(u32 heap, u32 size, int clear, const char *file, unsigned short line);
extern u32 func_0203D378(void);
extern void func_02082BCC(void *p, int v, int n);
extern void func_02087C6C(void *p);
extern struct Entry *func_020399A8(void);
extern u32 func_0203D1A4(struct Link *p);
extern u32 func_020307B0(void *p);
extern u32 func_02080D24(u32 a);
extern u32 func_0200FB24(void);
extern void func_02172D38(UnionRoomWork *work);
extern int func_02172D68(UnionRoomWork *work);
extern u32 func_0203D1C0(u32 index);
extern int INTRUDE_CMD_RecvResultRecord(int a, int b);
extern u32 UNION_COMMAND_SendAppSetting(void *p, u32 a);
extern u32 UNION_COMMAND_SendAppQuitAccept(u32 a);
extern u32 UNION_COMMAND_SendAppData(u32 a, void *p);
extern void func_02173614(UnionConnectInfo *connect, const u8 *mac);
extern void func_02082D44(const void *src, void *dst, u32 len);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern int func_0217357C(UnionConnectInfo *connect, const u8 *mac, u32 a2, u32 a3);
extern void func_0203D1E8(u32 unused, void *arg);
extern int func_0203CD98(void);
UnionAppWork *func_02183B60(UnionRoomWork *work, int heapId, int maxMembers, UnionAppStatusCopy *myStatus);
void func_02183BE0(UnionAppWork *app);
int func_02183BE8(UnionAppWork *app, int netId);
void func_02183C3C(UnionAppWork *app, UnionRoomWork *work);
void func_02183CC0(UnionAppWork *app);
void func_02183D34(UnionAppWork *app);
void func_02183D4C(UnionAppWork *app);
void func_02183D94(UnionAppWork *app);
void func_02183DAC(UnionAppWork *app);
void func_02183DDC(UnionAppWork *app);
void func_02183E48(UnionAppWork *app, UnionRoomWork *work);
void func_02183EE0(UnionAppWork *app, UnionRoomWork *work);
void func_02183F6C(UnionAppWork *app, u8 netId);
void func_02183F7C(UnionAppWork *app);
u8 func_02183F84(UnionAppWork *app);
void func_02183F88(UnionAppWork *app, u8 netId);
void func_02183F98(UnionAppWork *app, const void *setting);
void func_02183FA8(UnionAppWork *app, u8 netId);
void func_02183FB8(UnionAppWork *app, UnionRoomWork *work, u32 netId, const UnionAppEntry *src);
int func_0218401C(UnionAppWork *app);
int func_0218402C(UnionAppWork *app);
void func_02184060(UnionAppWork *app, int netId);
void func_021840A4(UnionAppWork *app, int netId);
unsigned int func_021840A8(unsigned int entry);
void func_021840AC(UnionAppWork *app);
int func_021840C8(UnionAppWork *app);
void func_021840FC(UnionAppWork *app, UnionAppMemberCallback joinCallback, UnionAppMemberCallback leaveCallback, void *callbackArg);
int func_02184114(UnionAppWork *app);
void func_02184134(UnionAppWork *app);
void func_02184148(UnionAppWork *app, int maxCount);
void func_0218416C(UnionAppWork *app);
void func_02184174(UnionAppWork *app);
u32 func_0218417C(UnionAppWork *app);
UnionAppEntry *func_02184180(UnionAppWork *app, int netId);
unsigned char func_021841A0(UnionAppWork *app);
extern u8 d_021841C0[];

UnionAppWork *func_02183B60(UnionRoomWork *work, int heapId, int maxMembers, UnionAppStatusCopy *myStatus)
{
    UnionAppWork *app;
    UnionAppEntry entry;

    app = func_02030734(heapId, UNION_APP_WORK_SIZE, 1, (const char *)d_021841C0, 0x4d);
    if (func_0203D378() == 1) {
        app->joinedBits = 3;
    }
    app->maxMembers = maxMembers;
    app->quitRequester = UNION_APP_NO_MEMBER;
    app->quitAcceptTarget = UNION_APP_NO_MEMBER;
    func_02082BCC(&entry, 0, sizeof(UnionAppEntry));
    entry.status = *myStatus;
    func_02087C6C(entry.mac);
    func_02183FB8(app, work, func_0203D1A4((struct Link *)((u32)func_020399A8())), &entry);
    func_02184114(app);
    func_0218416C(app);
    return app;
}

/*
 * Unlabelled tail-call thunk (ldr r3 / bx r3 / pool) in ov022; blocker of
 * ov012 UNION_MAIN_StepGroupActivity.
 */
void func_02183BE0(UnionAppWork *app)
{
    func_020307B0(app);
}

/*
 * Addresses are Black-image addresses.
 */
int func_02183BE8(UnionAppWork *app, int netId)
{
    u32 memberCount;
    u32 limitedCount;

    if (app->phase == UNION_APP_PHASE_CLOSED) {
        return 0;
    }
    memberCount = func_02080D24(app->joinedBits);
    if (app->phase == UNION_APP_PHASE_LIMITED) {
        limitedCount = app->limitedCount;
        if (limitedCount + 1 > app->limitedMax) {
            return 0;
        }
    }
    if (memberCount + 1 <= app->maxMembers) {
        app->pendingBits = app->pendingBits | (u8)(1 << netId);
        if (app->phase == UNION_APP_PHASE_LIMITED) {
            app->limitedCount = app->limitedCount + 1;
        }
        return 1;
    }
    return 0;
}

void func_02183C3C(UnionAppWork *app, UnionRoomWork *work)
{
    if (func_0200FB24() != 0) {
        return;
    }
    if (app->resetDone == 1) {
        return;
    }
    if (app->resetRequest == 1) {
        func_02172D38(work);
        app->resetRequest = 0;
        app->resetRunning = 1;
        return;
    }
    if (app->resetRunning == 1) {
        if (func_02172D68(work) == 0) {
            app->resetRunning = 0;
            app->resetDone = 1;
        }
        return;
    }
    if (func_0203D378() == 1) {
        func_02183EE0(app, work);
        func_02183D34(app);
        func_02183CC0(app);
        func_02183D4C(app);
        func_02183D94(app);
    }
    func_02183DAC(app);
    func_02183DDC(app);
    func_02183E48(app, work);
}

void func_02183CC0(UnionAppWork *app)
{
    int netId;
    u32 bit;
    u32 stillConnected;
    u8 stillConnectedBits;

    stillConnected = app->joinedBits;
    if (app->quitRequester == UNION_APP_NO_MEMBER) {
        for (netId = 0; netId < UNION_APP_MEMBER_MAX; netId++) {
            bit = 1 << netId;
            if (app->joinedBits & bit) {
                if (func_0203D1C0((u8)netId) == 0) {
                    stillConnected ^= bit;
                }
            }
        }
        if (stillConnected != app->joinedBits) {
            stillConnectedBits = stillConnected;
            for (netId = 0; netId < UNION_APP_MEMBER_MAX; netId++) {
                bit = 1 << netId;
                if (app->joinedBits & bit) {
                    if (!(stillConnected & bit)) {
                        if (INTRUDE_CMD_RecvResultRecord(stillConnectedBits, netId & 0xff) == 1) {
                            func_021840A4(app, (u8)netId);
                            app->joinedBits = app->joinedBits ^ (u8)bit;
                        }
                    }
                }
            }
        }
    }
}

void func_02183D34(UnionAppWork *app)
{
    if (app->settingSendBits != 0 && UNION_COMMAND_SendAppSetting(app, app->settingSendBits) == 1) app->settingSendBits = 0;
}

void func_02183D4C(UnionAppWork *app)
{
    int netId;
    u8 bits;

    if (app->quitRequester != UNION_APP_NO_MEMBER) {
        if (func_0203D1C0(app->quitRequester) != 0) {
            return;
        }
        app->quitRequester = UNION_APP_NO_MEMBER;
        app->quitAcceptTarget = UNION_APP_NO_MEMBER;
    }
    bits = app->quitRequestBits;
    if (bits != 0) {
        for (netId = 0; netId < UNION_APP_MEMBER_MAX; netId++) {
            if (bits & (1 << netId)) {
                app->quitRequester = netId;
                app->quitAcceptTarget = netId;
                app->quitRequestBits = app->quitRequestBits ^ (u8)(1 << netId);
                return;
            }
        }
    }
}

/*
 * Callee's filed definition says void; original caller reads r0 at
 * 02183DA2, and ov012 callee leaves func_0203D3F8 result live.
 */
void func_02183D94(UnionAppWork *app)
{
    if (app->quitAcceptTarget != 255 && UNION_COMMAND_SendAppQuitAccept(app->quitAcceptTarget) == 1) app->quitAcceptTarget = 255;
}

void func_02183DAC(UnionAppWork *app)
{
    u32 myNetId;
    if (app->dataSendBits != 0) {
        myNetId = func_0203D1A4((struct Link *)func_020399A8());
        if (UNION_COMMAND_SendAppData(app->dataSendBits, &app->entry[myNetId]) == 1) app->dataSendBits = 0;
    }
}

void func_02183DDC(UnionAppWork *app)
{
    int netId;
    u32 bit;
    UnionAppEntry *entries;
    UnionAppMemberCallback callback;

    if (app->confirmBits != 0) {
        netId = 0;
        entries = app->entry;
        for (; netId < UNION_APP_MEMBER_MAX; netId++) {
            bit = 1 << netId;
            if (app->confirmBits & bit) {
                if ((app->entryReceivedBits & bit) && (app->pendingBits & bit)) {
                    app->pendingBits ^= (u8)bit;
                    app->joinedBits |= (u8)bit;
                    callback = app->joinCallback;
                    if (callback != 0) {
                        callback((u8)netId, entries + netId, app->callbackArg);
                    }
                    app->quitRequester = 0xff;
                }
                app->confirmBits = app->confirmBits ^ (u8)bit;
            }
        }
    }
}

void func_02183E48(UnionAppWork *app, UnionRoomWork *work)
{
    int netId;
    u32 bit;
    UnionAppMemberCallback callback;

    for (netId = 0; netId < UNION_APP_MEMBER_MAX; netId++) {
        bit = 1 << netId;
        if (app->entryReceivedBits & bit) {
            if (func_0203D1C0((u8)netId) == 0) {
                if (func_0203D378() == 1 || (app->joinedBits & bit)) {
                    callback = app->leaveCallback;
                    if (callback != 0) {
                        callback(netId & 0xff, &app->entry[netId], app->callbackArg);
                    }
                    app->joinedBits &= (u8)(bit ^ 0xff);
                    app->entryReceivedBits &= (u8)(bit ^ 0xff);
                }
                func_02173614(&work->mySituation.connect, app->entry[netId].mac);
            }
        }
    }
}

void func_02183EE0(UnionAppWork *app, UnionRoomWork *work)
{
    u8 netId;
    u32 bit;

    for (netId = 0; netId < UNION_APP_MEMBER_MAX; netId++) {
        bit = 1 << netId;
        if (app->pendingBits & bit) {
            if (func_0203D1C0(netId) == 0) {
                app->pendingBits ^= (u8)bit;
                if (app->entryReceivedBits & bit) {
                    app->entryReceivedBits &= (u8)(bit ^ 0xff);
                    func_02173614(&work->mySituation.connect, app->entry[netId].mac);
                }
                if (app->phase == UNION_APP_PHASE_LIMITED && app->limitedCount != 0) {
                    app->limitedCount--;
                }
            }
        }
    }
}

void func_02183F6C(UnionAppWork *app, u8 netId)
{
    app->quitRequestBits |= (u8)(1 << netId);
}

/*
 * leaf:     Sole game blocker of assigned ov012 caller; root claim granted.
 */
void func_02183F7C(UnionAppWork *app)
{
    app->quitAccepted = 1;
}

/*
 * Unlabelled leaf (a .word run in asm/overlays/ov022.s); blocker of ov012
 * UNION_MAIN_StepGroupActivity.
 */
u8 func_02183F84(UnionAppWork *app)
{
    return app->quitAccepted;
}

void func_02183F88(UnionAppWork *app, u8 netId)
{
    app->settingSendBits |= (u8)(1 << netId);
}

void func_02183F98(UnionAppWork *app, const void *setting)
{
    func_02082D44(setting, app, 4);
}

/*
 * Unlabelled bit-set leaf; follower 02183FB8 is separate labelled code.
 */
void func_02183FA8(UnionAppWork *app, u8 netId)
{
    app->dataSendBits = app->dataSendBits | (u8)(1 << netId);
}

void func_02183FB8(UnionAppWork *app, UnionRoomWork *work, u32 netId, const UnionAppEntry *src)
{
    UnionMySituation *situation = &work->mySituation;
    app->entry[netId] = *src;
    app->entryReceivedBits |= (u8)(1 << netId);
    if (netId != func_0203D1A4((struct Link *)func_020399A8())) {
        u32 trainerView = func_02008554((const struct Sub0200852CObj *)src);
        u32 sex = func_02008550((const struct Sub0200852CObj *)src);
        func_0217357C(&situation->connect, src->mac, trainerView, (u8)sex);
    }
}

int func_0218401C(UnionAppWork *app)
{
    if (app->joinedBits != 0)
        return 1;
    return 0;
}

int func_0218402C(UnionAppWork *app)
{
    int netId;
    u32 bit;
    for (netId = 0; netId < UNION_APP_MEMBER_MAX; netId++) {
        bit = 1 << netId;
        if ((app->joinedBits & bit) && func_0203D1C0((u8)netId) == 1 && !(app->entryReceivedBits & bit)) return 0;
    }
    return 1;
}

void func_02184060(UnionAppWork *app, int netId)
{
    if (func_0203D378() == 1) {
        if ((app->entryReceivedBits & (1 << netId)) && (app->pendingBits & (1 << netId))) {
            app->confirmBits |= (u8)(1 << netId);
        }
    } else {
        app->pendingBits |= (u8)(1 << netId);
        app->confirmBits |= (u8)(1 << netId);
    }
}

void func_021840A4(UnionAppWork *app, int netId)
{
}

/*
 * Unlabelled size-return leaf. Extent follower 021840AC already filed separately.
 */
unsigned int func_021840A8(unsigned int entry)
{
    return 4;
}

void func_021840AC(UnionAppWork *app)
{
    app->joinedBits = app->joinedBits | (u8)(1 << func_0203D1A4((struct Link *)((u32)func_020399A8())));
}

/*
 * Unlabelled leaf (prints as a .word run in asm/overlays/ov022.s); the
 * sole blocker of ov012 UNION_COMM_BuildBeacon's MATCH. Of the five overlays whose
 * window holds 0x021840C8 only ov022 has a function start there.
 */
int func_021840C8(UnionAppWork *app)
{
    if (app == 0)
        return 0;
    switch (app->phase) {
    case UNION_APP_PHASE_OPEN:
        return 0;
    case UNION_APP_PHASE_CLOSED:
        return 1;
    case UNION_APP_PHASE_LIMITED:
        if (app->limitedCount >= app->limitedMax)
            return 1;
        return 0;
    }
    return 0;
}

/*
 * Unlabelled leaf (a .word run in asm/overlays/ov022.s): stores the two
 * callbacks and their argument at 0xf4/0xf8/0xfc (the fields
 * func_02183E48 reads). Blocker of ov023 func_02184674.
 */
void func_021840FC(UnionAppWork *app, UnionAppMemberCallback joinCallback, UnionAppMemberCallback leaveCallback, void *callbackArg)
{
    app->joinCallback = joinCallback;
    app->leaveCallback = leaveCallback;
    app->callbackArg = callbackArg;
}

int func_02184114(UnionAppWork *app)
{
    if (app->pendingBits == 0) {
        func_0203D1E8((u32)func_020399A8(), 0);
        app->phase = UNION_APP_PHASE_CLOSED;
        return 1;
    }
    return 0;
}

/*
 * Original r0 return from 020399A8 flows into unused parameter 0 of
 * 0203D1E8; its r1 argument is literal payload 1. No implicit arguments.
 */
void func_02184134(UnionAppWork *app)
{
    func_0203D1E8((u32)func_020399A8(), (void *)1);
    app->phase = UNION_APP_PHASE_OPEN;
}

void func_02184148(UnionAppWork *app, int maxCount)
{
    if (func_0203CD98()) {
        func_0203D1E8((int)func_020399A8(), (void *)1);
        app->phase = UNION_APP_PHASE_LIMITED;
        app->limitedMax = maxCount;
        app->limitedCount = 0;
    }
}

/*
 * Extent followers 0x02184174, 0x0218417C and 0x02184180 are matched separately.
 */
void func_0218416C(UnionAppWork *app)
{
    app->ready = 1;
}

/*
 * Unlabelled leaf (a .word run in asm/overlays/ov022.s): sets the word at
 * 0x20. Blocker of ov023 func_02184674.
 */
void func_02184174(UnionAppWork *app)
{
    app->resetRequest = 1;
}

/*
 * Unlabelled leaf (a .word run in asm/overlays/ov022.s): returns the word
 * at 0x28. Blocker of ov023 func_02184674.
 */
u32 func_0218417C(UnionAppWork *app)
{
    return app->resetDone;
}

/*
 * Unlabelled leaf; callers in ov023 (func_02186170, func_02185EA0).
 */
UnionAppEntry *func_02184180(UnionAppWork *app, int netId)
{
    int bit;

    bit = 1 << netId;
    if (!(app->entryReceivedBits & bit) || !(app->joinedBits & bit))
        return 0;
    return &app->entry[netId];
}

unsigned char func_021841A0(UnionAppWork *app)
{
    return app->joinedBits;
}
