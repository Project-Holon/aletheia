/*
 * file:     btlv_b_gauge.c
 * unit:     yes
 * function: BTLV_B_GAUGE_CreatePartyBallBar, BTLV_B_GAUGE_DeletePartyBallBar, BTLV_B_GAUGE_IsPartyBallBarActive, BTLV_B_GAUGE_TaskPartyBallBar, BTLV_B_GAUGE_PartyBallBarTaskDeleted
 * address:  0x02208DAC
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
 *   TCB_AddTask  0x02030DA8  arm
 *   BTLV_B_GAUGE_CreatePartyBallBar  0x02208DAC  thumb  ov094
 *   BTLV_B_GAUGE_DeletePartyBallBar 0x02209068 thumb ov094
 *   BTLV_B_GAUGE_IsPartyBallBarActive 0x022090A4 thumb ov094
 *   TCBL_IsDeletePending   0x02030EE8  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   GFL_USE_PlaySeInSlot  0x0200616C  thumb
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_GetPaletteVramAddress 0x0204AEF4 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CLACT_GetActorSurfacePos  0x0204B454  arm
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   BTLV_EFFECT_GetPalanm 0x021F86E0 thumb ov094
 *   BTLV_EFFECT_GetOwner 0x021F86D4 thumb ov094
 *   BTLV_EFFECT_RegisterTask 0x021F896C thumb ov094
 *   sBtlvBGaugeFileName 0x0220AED0 data a4
 *   sPartyBallBarOrigins 0x0220AB6C data a4
 *   sPartyBallBarAnimSeq 0x0220AB7C data a4
 *   BTLV_EFFECT_DeleteTask 0x021F89BC thumb ov094
 */
#include "btlv_b_gauge_types.h"

#include "../arm9/clact.h"


#include "../arm9/gfl_use.h"
struct ClactActor;


#include "btlv_effect.h"


/* Original prototypes (docs/ORIGINAL_BUGS.tsv): ../arm9/gfl_heap_wrap.h */
#ifdef __MWERKS__
#define GFL_HEAP_Alloc GFL_HEAP_Alloc_header
#endif
#include "../arm9/gfl_heap_wrap.h"
#ifdef __MWERKS__
#undef GFL_HEAP_Alloc
void *GFL_HEAP_Alloc(u16 heapId, u32 size, int clear, const char *site, u16 tag);
#endif

/* Original prototypes (docs/ORIGINAL_BUGS.tsv): ../arm9/arc_tool.h */
#ifdef __MWERKS__
#define ARC_TOOL_CreateHandle ARC_TOOL_CreateHandle_header
#endif
#include "../arm9/arc_tool.h"
#ifdef __MWERKS__
#undef ARC_TOOL_CreateHandle
void *ARC_TOOL_CreateHandle(u32 archiveID, u16 heapID);
#endif






#include "../arm9/palanm.h"


struct TcbSystem;
struct TcbTask;

#include "../arm9/tcb_list.h"











#include "../arm9/tcbl.h"

BtlvPartyBallBar *BTLV_B_GAUGE_CreatePartyBallBar(const BtlvPartyBallBarParam *param, u32 heapId);

void BTLV_B_GAUGE_DeletePartyBallBar(BtlvPartyBallBar *bar);

int BTLV_B_GAUGE_IsPartyBallBarActive(BtlvPartyBallBar *bar);

void BTLV_B_GAUGE_TaskPartyBallBar(struct TcbTask *task, void *arg);

void BTLV_B_GAUGE_PartyBallBarTaskDeleted(void *task);

extern const char sBtlvBGaugeFileName[];

extern const BtlvPartyBallOrigin sPartyBallBarOrigins[];

extern const u32 sPartyBallBarAnimSeq[][5];

/*
 * Creates the party ball bar: six ball icons and a frame that slide in.
 * lever: const param lets the side load schedule above the pos zero stores;
 *   actorInit is initialised in an inner block (a top-level initializer is
 *   emitted at function entry); the stack locals are declared arc, heap,
 *   base so they land at 0x1c, 0x18, 0x14.
 */
BtlvPartyBallBar *BTLV_B_GAUGE_CreatePartyBallBar(const BtlvPartyBallBarParam *param, u32 heapId)
{
    void *arc;
    int fullHeapId;
    int baseX;
    BtlvPartyBallBar *bar;
    BtlvPartyBallTaskArg *taskArg;
    int i;

    fullHeapId = (heapId & 0x7fff) | 0x8000;
    bar = GFL_HEAP_Alloc(fullHeapId, sizeof(BtlvPartyBallBar), 1, sBtlvBGaugeFileName, 0x7a);
    arc = ARC_TOOL_CreateHandle(0xb, fullHeapId);
    bar->heapId = fullHeapId;
    bar->unit = CLACT_CreateUnit(7, 0, bar->heapId);
    bar->charRes = CLACT_RegisterCharacter(arc, 0xbd, 0, 0, bar->heapId);
    bar->cellRes = CLACT_RegisterCellAnim(arc, 0xbf, 0xc0, bar->heapId);
    bar->palRes = CLACT_RegisterPalette(arc, 0xbe, 0, 0xc0, bar->heapId);
    PALANM_CopyHwPaletteToSlot(BTLV_EFFECT_GetPalanm(), 2, (u16)(CLACT_GetPaletteVramAddress(bar->palRes, 0) >> 1), 0x20);
    {
    struct ActorInitParam actorInit = {0, 0, 0, 0};
    int side = param->side;
    baseX = sPartyBallBarOrigins[side].ballX;
    actorInit.x = baseX + (side == 0 ? 0x80 : -0x80);
    actorInit.y = sPartyBallBarOrigins[param->side].ballY;
    for (i = 0; i < 6; i++) {
        bar->entries[i].actor = CLACT_CreateActor(bar->unit, bar->charRes, bar->palRes, bar->cellRes, &actorInit, 0, bar->heapId);
        CLACT_GetActorSurfacePos(bar->entries[i].actor, &bar->entries[i].pos, 0);
        CLACT_SetActorAutoAnim((struct ClactActor *)bar->entries[i].actor, 1);
        CLACT_SetActorAnimSeq((struct ClactActor *)bar->entries[i].actor, sPartyBallBarAnimSeq[param->side][param->ballKind[i]]);
        bar->entries[i].finalAnim = sPartyBallBarAnimSeq[2][param->ballKind[i]];
        bar->entries[i].wait = (i + 1) * 6;
        bar->entries[i].homeX = baseX;
        bar->entries[i].goalX = baseX + (i + 1) * (param->side == 0 ? -2 : 2);
        bar->entries[i].stepX = param->side == 0 ? -12 : 12;
        baseX += param->side == 0 ? 15 : -15;
    }
    actorInit.x = sPartyBallBarOrigins[param->side].frameX + (param->side == 0 ? 0x80 : -0x80);
    actorInit.y = sPartyBallBarOrigins[param->side].frameY;
    bar->entries[i].actor = CLACT_CreateActor(bar->unit, bar->charRes, bar->palRes, bar->cellRes, &actorInit, 0, bar->heapId);
    CLACT_GetActorSurfacePos(bar->entries[i].actor, &bar->entries[i].pos, 0);
    CLACT_SetActorAutoAnim((struct ClactActor *)bar->entries[i].actor, 1);
    CLACT_SetActorAnimSeq((struct ClactActor *)bar->entries[i].actor, sPartyBallBarAnimSeq[param->side][4]);
    bar->entries[i].finalAnim = sPartyBallBarAnimSeq[param->side][4];
    bar->entries[i].wait = 0;
    bar->entries[i].homeX = bar->entries[i].goalX = sPartyBallBarOrigins[param->side].frameX;
    bar->entries[i].stepX = param->side == 0 ? -0x10 : 0x10;
    taskArg = GFL_HEAP_Alloc(fullHeapId, sizeof(BtlvPartyBallTaskArg), 0, sBtlvBGaugeFileName, 0xec);
    taskArg->bar = bar;
    BTLV_EFFECT_RegisterTask(TCB_AddTask(BTLV_EFFECT_GetOwner(), BTLV_B_GAUGE_TaskPartyBallBar, taskArg, 0), BTLV_B_GAUGE_PartyBallBarTaskDeleted, 0);
    bar->active = 1;
    ARC_TOOL_DeleteHandle(arc);
    GFL_USE_PlaySeDefaultVolume(BTLV_GAUGE_SE_BALL_BAR_START);
    return bar;
    }
}

/* Deletes the party ball bar actors and resources and frees the bar. */
void BTLV_B_GAUGE_DeletePartyBallBar(BtlvPartyBallBar *bar)
{
    int i;

    for (i = 0; i < 7; i++)
        CLACT_DeleteActor((struct ClactActor *)bar->entries[i].actor);
    CLACT_ReleaseCharacter(bar->charRes);
    CLACT_ReleasePalette(bar->palRes);
    CLACT_ReleaseCellAnim(bar->cellRes);
    CLACT_DeleteUnit(bar->unit);
    GFL_HEAP_Free(bar);
}

/* Returns 1 while the party ball bar task runs. */
int BTLV_B_GAUGE_IsPartyBallBarActive(BtlvPartyBallBar *bar)
{
    if (bar->active != 0)
        return 1;
    return 0;
}

/*
 * Task: state 0 slides the balls in, state 1 settles them at their home x.
 * lever: set busy before decrementing the delay; reversed statements
 *   interchange the movs and str at +002C/+002E. Locals for the bar or the entry
 *   change the code, so the full path is repeated.
 */
void BTLV_B_GAUGE_TaskPartyBallBar(struct TcbTask *task, void *arg)
{
    BtlvPartyBallTaskArg *taskArg = arg;
    int i;
    int busy = 0;
    int sound;
    switch (taskArg->bar->state) {
    case 0:
        for (i = 0; i < 7; i++) {
            if (taskArg->bar->entries[i].wait != 0) {
                busy = 1;
                taskArg->bar->entries[i].wait--;
            } else if (taskArg->bar->entries[i].stepX != 0) {
                taskArg->bar->entries[i].pos.x += (s16)taskArg->bar->entries[i].stepX;
                busy = 1;
                if (taskArg->bar->entries[i].stepX > 0) {
                    if (taskArg->bar->entries[i].pos.x >= taskArg->bar->entries[i].goalX) {
                        taskArg->bar->entries[i].pos.x = taskArg->bar->entries[i].goalX;
                        taskArg->bar->entries[i].stepX = 0;
                    }
                } else {
                    if (taskArg->bar->entries[i].pos.x <= taskArg->bar->entries[i].goalX) {
                        taskArg->bar->entries[i].pos.x = taskArg->bar->entries[i].goalX;
                        taskArg->bar->entries[i].stepX = 0;
                    }
                }
                CLACT_AddActorSurfacePos(taskArg->bar->entries[i].actor, &taskArg->bar->entries[i].pos, 0);
                if (taskArg->bar->entries[i].stepX == 0) {
                    CLACT_SetActorAnimSeq((struct ClactActor *)taskArg->bar->entries[i].actor, taskArg->bar->entries[i].finalAnim);
                    switch (taskArg->bar->entries[i].finalAnim) {
                    case 9: sound = BTLV_GAUGE_SE_BALL_ALT; break;
                    case 10:
                    case 11: sound = 0; break;
                    default: sound = BTLV_GAUGE_SE_BALL_SETTLE; break;
                    }
                    if (sound != 0) {
                        GFL_USE_PlaySeInSlot(sound, taskArg->bar->sound);
                        taskArg->bar->sound ^= 1;
                    }
                }
            }
        }
        if (!busy) taskArg->bar->state++;
        break;
    case 1:
        for (i = 0; i < 7; i++) {
            if (taskArg->bar->entries[i].pos.x < taskArg->bar->entries[i].homeX) {
                taskArg->bar->entries[i].pos.x += 2;
                if (taskArg->bar->entries[i].pos.x >= taskArg->bar->entries[i].homeX)
                    taskArg->bar->entries[i].pos.x = taskArg->bar->entries[i].homeX;
                busy = 1;
            } else if (taskArg->bar->entries[i].pos.x > taskArg->bar->entries[i].homeX) {
                taskArg->bar->entries[i].pos.x -= 2;
                if (taskArg->bar->entries[i].pos.x <= taskArg->bar->entries[i].homeX)
                    taskArg->bar->entries[i].pos.x = taskArg->bar->entries[i].homeX;
                busy = 1;
            }
            CLACT_AddActorSurfacePos(taskArg->bar->entries[i].actor, &taskArg->bar->entries[i].pos, 0);
        }
        if (!busy) BTLV_EFFECT_DeleteTask(task);
        break;
    }
}

/* Delete callback of the party ball bar task: marks the bar as no longer running. */
void BTLV_B_GAUGE_PartyBallBarTaskDeleted(void *task)
{
    ((BtlvPartyBallTaskArg *)TCBL_IsDeletePending(task))->bar->active = 0;
}
