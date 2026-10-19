/*
 * file:     btlv_finger_cursor.c
 * unit:     yes
 * function: BTLV_FINGER_CURSOR_Create, BTLV_FINGER_CURSOR_Delete, BTLV_FINGER_CURSOR_Start, BTLV_FINGER_CURSOR_DeleteActor, BTLV_FINGER_CURSOR_IsActive, BTLV_FINGER_CURSOR_AnimCallback, BTLV_FINGER_CURSOR_TaskHideAfterDelay
 * address:  0x02209A7C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from btlv_effvm.c, btlv_b_gauge.c, btlv_bg.c, btlv_finger_cursor.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Free  0x020307B0  arm
 *   TCB_DeleteTask 0x02030EAC arm
 *   TCB_AddTask  0x02030DA8  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_GetPaletteVramAddress 0x0204AEF4 arm
 *   CLACT_CreateAffineActor 0x0204B324 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   BTLV_FINGER_CURSOR_Delete  0x02209B30  thumb  ov094
 *   CLACT_CreateUnit 0x0204B100 arm
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   BTLV_FINGER_CURSOR_Create  0x02209A7C  thumb  ov094
 *   BTLV_FINGER_CURSOR_Start  0x02209B60  thumb  ov094
 *   BTLV_FINGER_CURSOR_IsActive  0x02209C2C  thumb  ov094
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   BTLV_EFFECT_GetOwner 0x021F86D4 thumb ov094
 *   d_0220AEFC     0x0220AEFC  data  ov094
 *   gBtlvFingerCursorActorInit     0x0220AC10  data   ov094  a4
 *   CLACT_SetActorAnimFrame  0x0204B8C4  arm
 *   CLACT_ApplyActorAnimCommand  0x0204BA00  arm
 */
#include "btlv_effvm_types.h"
#include "btlv_clact_shared_types.h"

extern u32 GFL_HEAP_Free(void *p);
struct TcbTask;

extern void TCB_DeleteTask(struct TcbTask *task);

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern struct Unit *CLACT_CreateUnit(int count, u8 flag, u32 heapId);

extern void *ARC_TOOL_CreateHandle(u32 archiveID, u16 heapID);

extern s32 CLACT_RegisterCharacter(void *archive, u32 fileIdx, u32 compressed, u32 vramMode, u16 heapId);

extern s32 CLACT_RegisterCellAnim(void *archive, u32 cellFileIdx, u32 animFileIdx, u32 heapId);

extern int CLACT_GetPaletteVramAddress(u32 paletteId, u32 alternate);

extern void CLACT_ReleaseCharacter(u32 charId);

extern void CLACT_ReleasePalette(u32 paletteId);

extern void CLACT_ReleaseCellAnim(u32 cellId);

extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *slots, u32 bank, u32 offset, u32 size);

extern s32 CLACT_RegisterPaletteEx(void *archive, u32 fileIdx, u32 vramMode, u32 vramOffset, u16 a, u16 b, u16 heapId);

extern void *BTLV_EFFECT_GetOwner(void);

struct ClactAnimCommand;

/* Pointing-hand cursor shown over a battle menu entry (0x30 bytes). */
typedef struct BtlvFingerCursor {
    struct Unit *clactUnit;         /* 0x00 */
    struct Actor *actor;       /* 0x04, null while hidden or deleted */
    void *task;                     /* 0x08, delayed-hide task */
    s32 charResId;                  /* 0x0c */
    s32 palResId;                   /* 0x10 */
    s32 cellResId;                  /* 0x14 */
    u32 state;             /* 0x18, animation step 0..3 */
    u32 startDelay;                 /* 0x1c, frames before the press animation */
    u32 loopCount;                  /* 0x20, press animation loops */
    u32 hideTimer;                  /* 0x24, frames until auto-hide */
    u32 isActive;          /* 0x28 */
    u16 heapId;                     /* 0x2c */
} BtlvFingerCursor;

/* Animation command, same layout as struct Cmd in arm9/clact.c. */
typedef struct ClactAnimCommand {
    u16 kind;           /* 0 start callback, 1 press loop, 2 release */
    u16 param;          /* loop count of kind 1 */
    void *userData;
    void *callback;
} ClactAnimCommand;

extern void ARC_TOOL_DeleteHandle(void *archive);
struct TcbSystem;

extern struct TcbTask *TCB_AddTask(struct TcbSystem *sys, void (*fn)(void *, void *), void *work, u32 priority);

extern void BTLV_FINGER_CURSOR_TaskHideAfterDelay(void *task, void *work);

extern u32 CLACT_DeleteUnit(struct Unit *bank);

extern struct Actor *CLACT_CreateAffineActor(struct Unit *unit, u32 charIdx, u32 palIdx, u32 cellIdx, const BtlvClactActorInit *init, u16 space, u16 heapId);

extern void CLACT_SetActorAnimSeq(struct Actor *actor, u16 seq);

extern void CLACT_SetActorAnimFrame(struct Actor *actor, u32 frame);

extern void CLACT_SetActorAutoAnim(struct Actor *actor, u32 enable);

extern void CLACT_SetActorDrawEnable(struct Actor *actor, u32 enable);

extern void CLACT_ApplyActorAnimCommand(struct Actor *actor, const struct ClactAnimCommand *cmd);

extern void CLACT_DeleteActor(struct Actor *actor);

BtlvFingerCursor *BTLV_FINGER_CURSOR_Create(void *palAnmSlots, u32 palSlot, u16 heapId);

void BTLV_FINGER_CURSOR_Delete(BtlvFingerCursor *cursor);

int BTLV_FINGER_CURSOR_Start(BtlvFingerCursor *cursor, u16 x, u16 y, u32 startDelay, u32 loopCount, u32 hideTimer);

void BTLV_FINGER_CURSOR_DeleteActor(BtlvFingerCursor *cursor);

int BTLV_FINGER_CURSOR_IsActive(BtlvFingerCursor *cursor);

void BTLV_FINGER_CURSOR_AnimCallback(BtlvFingerCursor *cursor);

extern char d_0220AEFC[];

extern const BtlvClactActorInit gBtlvFingerCursorActorInit;

BtlvFingerCursor *BTLV_FINGER_CURSOR_Create(void *palAnmSlots, u32 palSlot, u16 heapId)
{
    BtlvFingerCursor *cursor;
    void *archive;

    cursor = GFL_HEAP_Alloc(heapId, 0x30, 1, d_0220AEFC, 0x52);
    archive = ARC_TOOL_CreateHandle(0xb, (u16)((heapId & 0x7fff) | 0x8000));
    cursor->heapId = heapId;
    cursor->charResId = CLACT_RegisterCharacter(archive, 0xd9, 0, 1, heapId);
    cursor->cellResId = CLACT_RegisterCellAnim(archive, 0xdb, 0xdc, heapId);
    cursor->palResId = CLACT_RegisterPaletteEx(archive, 0xda, 1, (u16)(palSlot << 5), 0, 1, heapId);
    PALANM_CopyHwPaletteToSlot(palAnmSlots, 3, (u16)(CLACT_GetPaletteVramAddress(cursor->palResId, 1) >> 1), 0x20);
    cursor->clactUnit = CLACT_CreateUnit(1, 0, heapId);
    ARC_TOOL_DeleteHandle(archive);
    cursor->task = TCB_AddTask(BTLV_EFFECT_GetOwner(), BTLV_FINGER_CURSOR_TaskHideAfterDelay, cursor, 0);
    return cursor;
}

void BTLV_FINGER_CURSOR_Delete(BtlvFingerCursor *cursor)
{
    TCB_DeleteTask(cursor->task);
    BTLV_FINGER_CURSOR_DeleteActor(cursor);
    CLACT_ReleaseCharacter(cursor->charResId);
    CLACT_ReleaseCellAnim(cursor->cellResId);
    CLACT_ReleasePalette(cursor->palResId);
    CLACT_DeleteUnit(cursor->clactUnit);
    GFL_HEAP_Free(cursor);
}

/*
 * The hideTimer store is written out in both arms (the cross-jumped-tail idiom):
 * then-arm `str` is cross-jumped onto the else-arm copy, giving beq/b/movs.
 */
int BTLV_FINGER_CURSOR_Start(BtlvFingerCursor *cursor, u16 x, u16 y, u32 startDelay, u32 loopCount, u32 hideTimer)
{
    BtlvClactActorInit setup = gBtlvFingerCursorActorInit;
    ClactAnimCommand command;

    if (cursor->isActive != 0)
        return 0;
    if (cursor->actor != 0) {
        BTLV_FINGER_CURSOR_DeleteActor(cursor);
        cursor->actor = 0;
    }
    setup.x = x;
    setup.y = y;
    cursor->actor = CLACT_CreateAffineActor(cursor->clactUnit, cursor->charResId, cursor->palResId, cursor->cellResId, &setup, 1, cursor->heapId);
    CLACT_SetActorAnimSeq(cursor->actor, 0);
    CLACT_SetActorAnimFrame(cursor->actor, 0);
    CLACT_SetActorAutoAnim(cursor->actor, 1);
    CLACT_SetActorDrawEnable(cursor->actor, 1);
    if (startDelay != 0)
        cursor->startDelay = startDelay;
    else
        cursor->startDelay = 1;
    if (hideTimer != 0)
        cursor->hideTimer = hideTimer;
    else
        cursor->hideTimer = 1;
    cursor->state = 0;
    cursor->loopCount = loopCount;
    cursor->isActive = 0;
    command.userData = cursor;
    command.kind = 0;
    command.param = 0;
    command.callback = (void *)BTLV_FINGER_CURSOR_AnimCallback;
    CLACT_ApplyActorAnimCommand(cursor->actor, &command);
    return 1;
}

void BTLV_FINGER_CURSOR_DeleteActor(BtlvFingerCursor *cursor)
{
    if (cursor->actor != 0) {
        CLACT_DeleteActor(cursor->actor);
        cursor->actor = 0;
    }
}

/* Returns the isActive flag at +0x28.  A bare leaf getter with no prologue. */
int BTLV_FINGER_CURSOR_IsActive(BtlvFingerCursor *cursor)
{
    return cursor->isActive;
}

/*
 * state and isActive are accessed through a volatile view (live): the
 * original reloads state after each isActive store and keeps the store order.
 * The other fields stay plain, so the volatile view is local to this function.
 */
void BTLV_FINGER_CURSOR_AnimCallback(BtlvFingerCursor *cursor)
{
    volatile BtlvFingerCursor *live = cursor;
    ClactAnimCommand pressCommand;
    ClactAnimCommand releaseCommand;

    switch (live->state) {
    case 0:
        if (--cursor->startDelay == 0) {
            CLACT_SetActorAnimSeq(cursor->actor, 1);
            live->state++;
            pressCommand.userData = cursor;
            pressCommand.kind = 1;
            pressCommand.param = cursor->loopCount;
            pressCommand.callback = (void *)BTLV_FINGER_CURSOR_AnimCallback;
            CLACT_ApplyActorAnimCommand(cursor->actor, &pressCommand);
            return;
        }
        break;
    case 1:
        live->isActive = 1;
        live->state++;
        releaseCommand.userData = cursor;
        releaseCommand.kind = 2;
        releaseCommand.param = 0;
        releaseCommand.callback = (void *)BTLV_FINGER_CURSOR_AnimCallback;
        CLACT_ApplyActorAnimCommand(cursor->actor, &releaseCommand);
        return;
    case 2:
        CLACT_SetActorDrawEnable(cursor->actor, 0);
        live->isActive = 0;
        live->state++;
        break;
    case 3:
        break;
    }
}

/* Task callback: hides the cursor when the hide timer runs out. */
void BTLV_FINGER_CURSOR_TaskHideAfterDelay(void *task, void *work)
{
    BtlvFingerCursor *cursor = work;

    if (cursor->actor == 0)
        return;
    if (cursor->isActive == 0)
        return;
    if (--cursor->hideTimer != 0)
        return;
    CLACT_SetActorDrawEnable(cursor->actor, 0);
    cursor->isActive = 0;
}
