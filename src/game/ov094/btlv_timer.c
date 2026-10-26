/*
 * file:     btlv_timer.c
 * unit:     yes
 * function: BTLV_TIMER_Create, BTLV_TIMER_Delete, BTLV_TIMER_Start, BTLV_TIMER_DeleteActors, BTLV_TIMER_SetVisible, BTLV_TIMER_IsExpired, BTLV_TIMER_Redraw, BTLV_TIMER_TickTask
 * address:  0x02209224
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
 *   BTLV_TIMER_Create  0x02209224  thumb  ov094
 *   BTLV_TIMER_Delete 0x022092E8 thumb ov094
 *   TCB_DeleteTask 0x02030EAC arm
 *   TCB_AddTask  0x02030DA8  arm
 *   BTLV_TIMER_Start 0x02209318 thumb ov094
 *   BTLV_TIMER_SetVisible  0x022094BC  thumb  ov094
 *   BTLV_TIMER_IsExpired  0x02209500  thumb ov094
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_GetPaletteVramAddress 0x0204AEF4 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_SetUnitDrawEnable  0x0204B22C  arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   BTLV_EFFECT_GetPalanm 0x021F86E0 thumb ov094
 *   BTLV_EFFECT_GetOwner 0x021F86D4 thumb ov094
 *   sBtlvTimerSiteName     0x0220AEE0  data  ov094
 *   OS_GetTick 0x020870D0 arm
 *   sBtlvTimerRowY 0x0220ABC0 data a4
 *   sBtlvTimerColumnX 0x0220ABC8 data a4
 *   sBtlvTimerSpriteZ 0x0220ABE0 data a4
 *   sBtlvTimerWarningSeconds  0x0220ABB8  data  a4
 *   _ll_udiv                     0x0209C00C  arm
 */
#include "btlv_effvm_types.h"
#include "btlv_effect_shared_types.h"
#include "btlv_timer_shared_types.h"

#include "../arm9/gfl_heap_wrap.h"

#include "../arm9/arc_tool.h"

#include "btlv_effect.h"


struct PalAnimSlot;

/* Sprite position handed to CLACT_CreateActor. */

typedef struct { int v[2]; } SidePair;

typedef struct { int v[6]; } ColumnTable;

typedef struct { int v[2][6]; } SpriteZTable;


typedef enum { BTLV_TIMER_SIDE_PLAYER, BTLV_TIMER_SIDE_ENEMY } BtlvTimerSideId;

#include "../arm9/clact.h"





#include "../arm9/palanm.h"







struct ClactActor;


#include "../arm9/os_tick.h"
struct TcbSystem;
struct TcbTask;



#include "../arm9/tcb_list.h"




BtlvTimer *BTLV_TIMER_Create(u16 heapId);

void BTLV_TIMER_Delete(BtlvTimer *timer);

void BTLV_TIMER_Start(BtlvTimer *timer, int secondsPlayer, int secondsEnemy);

void BTLV_TIMER_DeleteActors(BtlvTimer *timer);

void BTLV_TIMER_SetVisible(BtlvTimer *timer, int side, int visible, int restart);

int BTLV_TIMER_IsExpired(BtlvTimer *timer, int side);

void BTLV_TIMER_Redraw(BtlvTimer *timer, int side);

void BTLV_TIMER_TickTask(struct TcbTask *tcb, void *timerArg);

extern char sBtlvTimerSiteName[];

extern const SidePair sBtlvTimerRowY;

extern const ColumnTable sBtlvTimerColumnX;

extern const SpriteZTable sBtlvTimerSpriteZ;

extern const SidePair sBtlvTimerWarningSeconds;

/*
 * Lever: the `lsls #15 / lsrs #16` argument is `(u16)(v >> 1)`; `& 0x7fff`
 * or `& 0x1ffff` forms pool the mask and shift the registers.
 */
BtlvTimer *BTLV_TIMER_Create(u16 heapId)
{
    BtlvTimer *timer;
    void *archive;
    void *palSlots;

    timer = GFL_HEAP_Alloc(heapId, sizeof(BtlvTimer), 1, sBtlvTimerSiteName, 0x81);
    timer->heapId = heapId;
    archive = ARC_TOOL_CreateHandle(0xb, (u16)((timer->heapId & 0x7fff) | 0x8000));
    timer->unit[0] = CLACT_CreateUnit(6, 0, timer->heapId);
    timer->unit[1] = CLACT_CreateUnit(6, 0, timer->heapId);
    timer->charResId = CLACT_RegisterCharacter(archive, 0x7a, 0, 0, timer->heapId);
    timer->cellResId = CLACT_RegisterCellAnim(archive, 0x7b, 0x7c, timer->heapId);
    timer->paletteResId = CLACT_RegisterPalette(archive, 0xa2, 0, 0xe0, timer->heapId);
    palSlots = (void *)BTLV_EFFECT_GetPalanm();
    PALANM_CopyHwPaletteToSlot(palSlots, 2, (u16)(CLACT_GetPaletteVramAddress(timer->paletteResId, 0) >> 1), 0x20);
    ARC_TOOL_DeleteHandle(archive);
    return timer;
}

void BTLV_TIMER_Delete(BtlvTimer *timer)
{
    BTLV_TIMER_DeleteActors(timer);
    CLACT_ReleaseCharacter(timer->charResId);
    CLACT_ReleaseCellAnim(timer->cellResId);
    CLACT_ReleasePalette(timer->paletteResId);
    CLACT_DeleteUnit(timer->unit[0]);
    CLACT_DeleteUnit(timer->unit[1]);
    GFL_HEAP_Free(timer);
}

/*
 * lever: y is a full int, narrowed by assignment to pos.y; s16 y sinks
 *   its home store and swaps it with the explicit handle-offset spill.
 *   Aggregate locals are declared columns, zValues, pos, rowYs in that order.
 */
void BTLV_TIMER_Start(BtlvTimer *timer, int secondsPlayer, int secondsEnemy)
{
    ColumnTable columns;
    SpriteZTable zValues;
    struct ActorInitParam pos = {0, 0, 0, 0};
    SidePair rowYs;
    int y;
    int side, slot;
    int *zRow;
    columns = sBtlvTimerColumnX;
    rowYs = sBtlvTimerRowY;
    zValues = sBtlvTimerSpriteZ;
    for (side = 0; side < 2; side++) {
        if ((side == 0 && secondsPlayer != 0) || (side == 1 && secondsEnemy != 0)) {
            y = rowYs.v[side];
            zRow = zValues.v[side];
            for (slot = 0; slot < 6; slot++) {
                pos.x = columns.v[slot];
                pos.y = y;
                pos.anim_seq = zRow[slot];
                timer->side[side].actor[slot] = CLACT_CreateActor(timer->unit[side], timer->charResId, timer->paletteResId, timer->cellResId, &pos, 0, timer->heapId);
                CLACT_SetActorAutoAnim((struct ClactActor *)timer->side[side].actor[slot], 1);
            }
        }
    }
    if (secondsPlayer > 5999) secondsPlayer = 5999;
    if (secondsEnemy > 5999) secondsEnemy = 5999;
    timer->limit[0] = secondsPlayer;
    timer->limit[1] = secondsEnemy;
    timer->startTick[1] = OS_GetTick();
    timer->startTick[0] = timer->startTick[1];
    BTLV_TIMER_SetVisible(timer, 0, 0, 0);
    BTLV_TIMER_SetVisible(timer, 1, 0, 0);
    timer->tickTask = (struct Task *)TCB_AddTask(BTLV_EFFECT_GetOwner(), BTLV_TIMER_TickTask, timer, 0);
}

void BTLV_TIMER_DeleteActors(BtlvTimer *timer)
{
    int side;
    int slot;

    for (side = 0; side < 2; side++) {
        for (slot = 0; slot < 6; slot++) {
            if (timer->side[side].actor[slot] != 0) {
                CLACT_DeleteActor((struct ClactActor *)timer->side[side].actor[slot]);
                timer->side[side].actor[slot] = 0;
            }
        }
    }
    if (timer->tickTask != 0) {
        TCB_DeleteTask((struct TcbTask *)timer->tickTask);
        timer->tickTask = 0;
    }
    if (timer->spareTask != 0) {
        TCB_DeleteTask((struct TcbTask *)timer->spareTask);
        timer->spareTask = 0;
    }
}

void BTLV_TIMER_SetVisible(BtlvTimer *timer, int side, int visible, int restart)
{
    if (timer->side[side].actor[0] != 0) {
        if (visible == 1 && restart == 1) {
            timer->startTick[side] = OS_GetTick();
            timer->animBase[side] = 0;
            BTLV_TIMER_Redraw(timer, side);
        }
        CLACT_SetUnitDrawEnable(timer->unit[side], visible);
    }
}

int BTLV_TIMER_IsExpired(BtlvTimer *timer, int side)
{
    u64 elapsed;

    elapsed = OS_GetTick() - timer->startTick[side];
    elapsed = (elapsed << 6) / 33514000ULL;
    return timer->limit[side] - (int)elapsed <= 0;
}

/*
 * note: the 0/1 icon offset is an enum-constant ternary (an int spelling flips the bne polarity).
 */
void BTLV_TIMER_Redraw(BtlvTimer *timer, int side)
{
    SidePair warningSeconds = sBtlvTimerWarningSeconds;
    int iconOffset = side == 0 ? BTLV_TIMER_SIDE_PLAYER : BTLV_TIMER_SIDE_ENEMY;
    int remaining = timer->limit[side] - (int)(((OS_GetTick() - timer->startTick[side]) * 64) / 33514000);
    int minutes, seconds, minuteTens, minuteOnes, secondTens, secondOnes;
    if (timer->side[side].actor[BTLV_TIMER_SLOT_ICON] == 0)
        return;
    if (remaining < 0)
        remaining = 0;
    minutes = remaining / 60;
    seconds = remaining % 60;
    minuteTens = minutes / 10;
    minuteOnes = minutes % 10;
    secondTens = seconds / 10;
    secondOnes = seconds % 10;
    if (remaining == warningSeconds.v[side])
        timer->animBase[side] = 13;
    CLACT_SetActorAnimSeq((struct ClactActor *)timer->side[side].actor[BTLV_TIMER_SLOT_ICON], iconOffset + timer->animBase[side]);
    if (minuteTens == 0) {
        CLACT_SetActorDrawEnable((struct ClactActor *)timer->side[side].actor[BTLV_TIMER_SLOT_MINUTE_TENS], 0);
    } else {
        CLACT_SetActorDrawEnable((struct ClactActor *)timer->side[side].actor[BTLV_TIMER_SLOT_MINUTE_TENS], 1);
        CLACT_SetActorAnimSeq((struct ClactActor *)timer->side[side].actor[BTLV_TIMER_SLOT_MINUTE_TENS], minuteTens + 3 + timer->animBase[side]);
    }
    if (minuteTens == 0 && minuteOnes == 0) {
        CLACT_SetActorDrawEnable((struct ClactActor *)timer->side[side].actor[BTLV_TIMER_SLOT_MINUTE_ONES], 0);
        CLACT_SetActorDrawEnable((struct ClactActor *)timer->side[side].actor[BTLV_TIMER_SLOT_COLON], 0);
    } else {
        CLACT_SetActorDrawEnable((struct ClactActor *)timer->side[side].actor[BTLV_TIMER_SLOT_MINUTE_ONES], 1);
        CLACT_SetActorDrawEnable((struct ClactActor *)timer->side[side].actor[BTLV_TIMER_SLOT_COLON], 1);
        CLACT_SetActorAnimSeq((struct ClactActor *)timer->side[side].actor[BTLV_TIMER_SLOT_MINUTE_ONES], minuteOnes + 3 + timer->animBase[side]);
        CLACT_SetActorAnimSeq((struct ClactActor *)timer->side[side].actor[BTLV_TIMER_SLOT_COLON], timer->animBase[side] + 2);
    }
    if (minuteTens == 0 && minuteOnes == 0 && secondTens == 0) {
        CLACT_SetActorDrawEnable((struct ClactActor *)timer->side[side].actor[BTLV_TIMER_SLOT_SECOND_TENS], 0);
    } else {
        CLACT_SetActorDrawEnable((struct ClactActor *)timer->side[side].actor[BTLV_TIMER_SLOT_SECOND_TENS], 1);
        CLACT_SetActorAnimSeq((struct ClactActor *)timer->side[side].actor[BTLV_TIMER_SLOT_SECOND_TENS], secondTens + 3 + timer->animBase[side]);
    }
    CLACT_SetActorAnimSeq((struct ClactActor *)timer->side[side].actor[BTLV_TIMER_SLOT_SECOND_ONES], secondOnes + 3 + timer->animBase[side]);
}

/*
 * Tick task of the timer: redraws both sides every frame.
 */
void BTLV_TIMER_TickTask(struct TcbTask *tcb, void *timerArg)
{
    BTLV_TIMER_Redraw((BtlvTimer *)timerArg, 0);
    BTLV_TIMER_Redraw((BtlvTimer *)timerArg, 1);
}
