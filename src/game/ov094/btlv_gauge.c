/*
 * file:     btlv_gauge.c
 * unit:     yes
 * function: BTLV_GAUGE_Create, BTLV_GAUGE_Delete, BTLV_GAUGE_FlashTaskMain, BTLV_GAUGE_InitSlotFromBattlePoke, BTLV_GAUGE_InitSlotFromPartyPoke, BTLV_GAUGE_LoadSlotResources, BTLV_GAUGE_ReleaseSlotResources, BTLV_GAUGE_UpdateSlot, BTLV_GAUGE_UpdateHpBarPixels, BTLV_GAUGE_DeleteSlotTask, BTLV_GAUGE_PlaceSlot, BTLV_GAUGE_StartHpChangeAnimated, BTLV_GAUGE_StartHpChangeInstant, BTLV_GAUGE_StartExpGain, BTLV_GAUGE_RefreshForLevelUp, BTLV_GAUGE_IsAnimating, BTLV_GAUGE_SetSideVisible, BTLV_GAUGE_SetSlotVisible, BTLV_GAUGE_IsSlotOccupied, BTLV_GAUGE_TakeSlotEvent, BTLV_GAUGE_StartHpChange, BTLV_GAUGE_UpdateHpAnim, BTLV_GAUGE_StartExpChange, BTLV_GAUGE_UpdateExpAnim, BTLV_GAUGE_StepValue, BTLV_GAUGE_CalcTileFill, BTLV_GAUGE_CalcPixelChange, BTLV_GAUGE_DrawNickname, BTLV_GAUGE_DrawGender, BTLV_GAUGE_DrawBar, BTLV_GAUGE_DrawHpNumbers, BTLV_GAUGE_DrawLevel, BTLV_GAUGE_DrawCaughtIcon, BTLV_GAUGE_DrawHpLoss, BTLV_GAUGE_UpdateLevelUp, BTLV_GAUGE_BobSlot, BTLV_GAUGE_SetStatusIcon, BTLV_GAUGE_SelectSlot, BTLV_GAUGE_IsLowHpBgmPlaying, BTLV_GAUGE_SetLowHpBgmPlaying, BTLV_GAUGE_SetSavedBgmNo, BTLV_GAUGE_SetBgmReplaced, BTLV_GAUGE_SetLowHpBgmSuppressed, BTLV_GAUGE_GetSlotHealthInfo, BTLV_GAUGE_RequestStop, BTLV_GAUGE_HideSlot, BTLV_GAUGE_UpdateLowHpBgm, BTLV_GAUGE_TaskSlideSlot, BTLV_GAUGE_TaskFlashPalettes, BTLV_GAUGE_SetBgmPlayerParam, BTLV_GAUGE_CalcBarPixels, BTLV_GAUGE_SetSlotBarsVisible
 * address:  0x02206BC8
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
 *   FX_SinCosTable_ 0x020A1B38 data a2
 *   TCB_DeleteTask 0x02030EAC arm
 *   TCB_AddTask  0x02030DA8  arm
 *   BTLV_GAUGE_StartHpChangeAnimated  0x02207B4C  thumb  ov094
 *   BTLV_GAUGE_StartHpChangeInstant  0x02207B68  thumb  ov094
 *   BTLV_GAUGE_StartExpGain 0x02207B84 thumb ov094
 *   BTLV_GAUGE_RefreshForLevelUp 0x02207BAC thumb ov094
 *   BTLV_GAUGE_RequestStop 0x022089AC thumb ov094
 *   BTLV_GAUGE_IsAnimating 0x02207C94 thumb ov094
 *   BTLV_GAUGE_SetSideVisible 0x02207CC4 thumb ov094
 *   BTLV_GAUGE_SetSlotVisible  0x02207D04  thumb  ov094
 *   BTLV_GAUGE_SetStatusIcon  0x02208814  thumb  ov094
 *   BTLV_GAUGE_SelectSlot 0x02208870 thumb ov094
 *   BTLV_GAUGE_IsSlotOccupied 0x02207D60 thumb ov094
 *   BTLV_GAUGE_GetSlotHealthInfo 0x02208958 thumb ov094
 *   PALANM_RequestFade  0x0202173C  thumb
 *   PALANM_GetFadeRequestBits  0x02021ED8  thumb
 *   BTLV_GAUGE_IsLowHpBgmPlaying 0x022088F4 thumb ov094
 *   BTLV_GAUGE_SetLowHpBgmPlaying  0x02208900  thumb  ov094
 *   BTLV_GAUGE_SetLowHpBgmSuppressed  0x0220893C  thumb  ov094
 *   GFL_USE_PopBgm  0x02005E9C  thumb
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   BTLV_GAUGE_SetSavedBgmNo  0x02208918  thumb  ov094
 *   BTLV_GAUGE_SetBgmReplaced  0x02208924  thumb  ov094
 *   TCBL_GetOwnedWork   0x02030EE8  arm
 *   KEY_GetTrg 0x020362DC arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   MIi_CpuClear16  0x02082A48  arm
 *   BTLV_GAUGE_PlaceSlot  0x022079C0  thumb  ov094
 *   GFL_USE_StopAllSe 0x02006210 thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   BGWINFRM_GetScaleRank 0x0202D034 thumb
 *   BTLV_GAUGE_HideSlot  0x022089BC  thumb  ov094
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
 *   BMP_Clear 0x02043B5C arm
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   GF_FONT_SetTextColor  0x0201DD78  thumb
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   MIi_CpuCopy16 0x02082A60 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   APP_ICON_GetArchiveId 0x020275E4 thumb
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   GF_FONT_GetTextColor  0x0201DE00  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   BTLV_GAUGE_TakeSlotEvent  0x02207D78  thumb  ov094
 *   APP_ICON_GetSealPaletteFileId 0x020276B8 thumb
 *   APP_ICON_GetSealAnimFileId 0x020276BC thumb
 *   APP_ICON_GetSealFrameFileId 0x020276C0 thumb
 *   APP_ICON_GetSealCellFileId 0x020276B4 thumb
 *   PALANM_BlendChannelMask 0x02022004 thumb
 *   ARC_UTIL_LoadScreenDataFromHandle 0x02049E74 arm
 *   GFL_USE_GetBgmNo 0x02005C44 thumb
 *   BTLV_GAUGE_TaskFlashPalettes 0x02208BFC thumb ov094
 *   gBtlvGaugeSourceFileName 0x0220AEC0 data a1
 *   gBtlvGaugeSlideInOffset 0x0220AABC data a2
 *   BTLV_GAUGE_SetBgmPlayerParam  0x02208D24  thumb  ov094
 *   BTLV_GAUGE_SetSlotBarsVisible 0x02208D50 thumb ov094
 *   BTLV_GAUGE_StepValue 0x02207F6C thumb ov094
 *   BTLV_GAUGE_DrawBar 0x022082FC thumb ov094
 *   BTLV_GAUGE_UpdateHpAnim 0x02207E1C thumb ov094
 *   BTLV_GAUGE_UpdateExpAnim 0x02207EF0 thumb ov094
 *   BTLV_GAUGE_UpdateLevelUp 0x022086F8 thumb ov094
 *   BTLV_GAUGE_BobSlot 0x022087C4 thumb ov094
 *   BTLV_GAUGE_UpdateLowHpBgm 0x022089D4 thumb ov094
 *   BTL_POKEPARAM_GetValue 0x021D59B4 thumb ov093
 *   BTL_POKEPARAM_GetSpecies 0x021D5444 thumb ov093
 *   POKE_TOOL_GetExpForLevel 0x02018584 thumb
 *   BTL_MAIN_CheckZukanSeen 0x021B8724 thumb ov093
 *   BTL_POKEPARAM_GetDisplayMon 0x021D5864 thumb ov093
 *   POKE_TOOL_GetGender 0x02017F00 thumb
 *   BTL_POKEPARAM_GetSickContRaw 0x021D6314 thumb ov093
 *   BTL_SICKCONT_IsKind1Index15 0x021E8A78 thumb ov093
 *   BTL_POKEPARAM_GetMajorStatusIndex 0x021D62A8 thumb ov093
 *   ZUKAN_SAVE_IsCaught 0x0200CED4 thumb
 *   POKE_TOOL_GetStatusCondition 0x02017F90 thumb
 *   gBtlvGaugeActorInit 0x0220AAC8 data
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   BTLV_GAUGE_DrawNickname 0x022080F4 thumb ov094
 *   BTLV_GAUGE_DrawGender 0x02208268 thumb ov094
 *   BTLV_GAUGE_DrawHpNumbers 0x02208420 thumb ov094
 *   BTLV_GAUGE_DrawLevel 0x02208550 thumb ov094
 *   BTLV_GAUGE_DrawCaughtIcon 0x02208650 thumb ov094
 *   BTLV_GAUGE_TaskSlideSlot 0x02208B10 thumb ov094
 *   BTLV_GAUGE_CalcBarPixels 0x02208D38 thumb ov094
 *   gBtlvGaugeSlideOutOffset     0x0220AAB4  data   ov094  a2
 *   CLACT_GetActorImageProxy  0x0204B7C8  arm  arm9
 *   BMP_Create  0x02043678  arm  arm9
 *   BMP_Delete  0x020437AC  arm  arm9
 *   BMP_GetPixels  0x020437D4  arm  arm9
 *   sGaugeBarOffsets  0x0220AAD0  data  ov094  a2
 *   sGaugeStatusIconOffsets  0x0220AAC0  data  ov094  a2
 *   sGaugeDefaultPositions  0x0220AAD8  data  ov094  a2
 *   sGaugeLayout2Positions  0x0220AB0C  data  ov094  a2
 *   sGaugeLayout3Positions  0x0220AB2C  data  ov094  a2
 *   CLACT_GetActorAnimSeq  0x0204B898  arm
 *   BTLV_GAUGE_UpdateHpBarPixels  0x0220793C  thumb  ov094
 *   PRINTSYS_MeasureWidestLine 0x0201D304 thumb
 *   WORDSET_FormatNumber 0x0201F35C thumb
 *   sGaugeStatusAnimTable     0x0220AAF0  data   ov094  a4
 *   sGaugeHomeOffset     0x0220AAB8  data  ov094  a2
 *   GFL_USE_IsBgmFading 0x02005E50 thumb
 *   BTLV_EFFECT_IsBgmSaved 0x021F882C thumb ov094
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 *   GFL_USE_PushBgm 0x02005E64 thumb
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   BTLV_EFFECT_GetPalanm 0x021F86E0 thumb ov094
 *   BTLV_EFFECT_GetOwner 0x021F86D4 thumb ov094
 *   sGaugeFlashMasks 0x0220AB4C data a4
 *   GFL_USE_SetBgmPaused  0x02005DE4  thumb  arm9
 *   BTLV_EFFECT_GetMode 0x021F8710 thumb ov094
 *   BTLV_EFFECT_GetCompetitorType 0x021F8720 thumb ov094
 *   GFL_NET_IsWifiGameKind  0x0200F300  thumb  arm9
 *   _u32_div_f                   0x0209C2B0  arm
 */
#include "btlv_effvm_types.h"
#include "btlv_gauge_types.h"

struct ZukanSave;
struct BtlMain;
struct PalAnmSystem; /* palette animation system of the battle view */

#include "../ov093/btl_calc_types.h"

typedef union BtlSickCont BtlSickCont;

#include "../arm9/gfl_heap_wrap.h"
struct TcbTask;

#include "../arm9/tcb_list.h"
struct TcbSystem;


void BTLV_GAUGE_SetStatusIcon(BtlvGaugeWork *work, int status, int slotIdx);

#include "../arm9/gfl_use.h"
struct TcblSystem;

#include "../arm9/tcbl.h"


#include "../arm9/key.h"


#include "../arm9/mi_memory.h"

void BTLV_GAUGE_PlaceSlot(BtlvGaugeWork *work, int slotIdx, struct ClactVec2 *offset);


struct PokemonParam;

#include "../arm9/poke_tool.h"

#include "../arm9/clact.h"


#include "../arm9/arc_tool.h"




struct ClactActor;







#include "../arm9/palanm.h"


#include "../arm9/app_icon.h"







#include "../arm9/arc_util.h"


void BTLV_GAUGE_TaskFlashPalettes(struct TcbTask *task, void *arg);

void BTLV_GAUGE_SetBgmPlayerParam(int bgmParam);

void BTLV_GAUGE_SetSlotBarsVisible(BtlvGaugeWork *work, int slotIdx, int visible);

int BTLV_GAUGE_StepValue(int maxValue, int value, int delta, int *anim, u8 tileCount, int speed);

void BTLV_GAUGE_DrawBar(BtlvGaugeWork *work, int slotIdx, int kind);

void BTLV_GAUGE_UpdateHpAnim(BtlvGaugeWork *work, int slotIdx);

void BTLV_GAUGE_UpdateExpAnim(BtlvGaugeWork *work, int slotIdx);

void BTLV_GAUGE_UpdateLevelUp(BtlvGaugeWork *work, int slotIdx);

void BTLV_GAUGE_BobSlot(BtlvGaugeWork *work, int slotIdx);

void BTLV_GAUGE_UpdateLowHpBgm(BtlvGaugeWork *work);

extern int BTL_POKEPARAM_GetValue(struct BtlPokeParam *pp, int valueId);

extern u16 BTL_POKEPARAM_GetSpecies(struct BtlPokeParam *pp);


#include "../ov093/btl_main.h"

extern struct PokemonParam *BTL_POKEPARAM_GetDisplayMon(struct BtlPokeParam *pp);


#include "../ov093/btl_pokeparam.h"

#include "../ov093/btl_sickcont.h"


#include "../arm9/zukan_save.h"



void BTLV_GAUGE_DrawNickname(BtlvGaugeWork *work, BtlvGaugeSlot *slot, void *pokeParam);

void BTLV_GAUGE_DrawGender(BtlvGaugeWork *work, BtlvGaugeSlot *slot);

void BTLV_GAUGE_DrawHpNumbers(const BtlvGaugeWork *work, BtlvGaugeSlot *slot, int hp);

void BTLV_GAUGE_DrawLevel(BtlvGaugeWork *work, BtlvGaugeSlot *slot);

void BTLV_GAUGE_DrawCaughtIcon(BtlvGaugeWork *work, BtlvGaugeSlot *slot);

void BTLV_GAUGE_TaskSlideSlot(struct TcbTask *task, void *arg);

int BTLV_GAUGE_CalcBarPixels(int value, int maxValue, int scale);

#include "btlv_effect.h"




BtlvGaugeWork *BTLV_GAUGE_Create(void *font, u16 heapId);

void BTLV_GAUGE_Delete(BtlvGaugeWork *work);

void BTLV_GAUGE_FlashTaskMain(BtlvGaugeWork *work);

void BTLV_GAUGE_InitSlotFromBattlePoke(BtlvGaugeWork *work, struct BtlMain *battleMain, struct BtlPokeParam *battlePoke, int layout, int slotIdx);

void BTLV_GAUGE_InitSlotFromPartyPoke(BtlvGaugeWork *work, struct ZukanSave *zukanSave, void *partyPoke, int layout, int slotIdx);

void BTLV_GAUGE_LoadSlotResources(BtlvGaugeWork *work, int layout, int slotIdx);

void BTLV_GAUGE_ReleaseSlotResources(BtlvGaugeWork *work, int slotIdx);

void BTLV_GAUGE_UpdateSlot(BtlvGaugeWork *work, int layout, int slotIdx, void *pokeParam);

extern void BTLV_GAUGE_UpdateHpBarPixels(BtlvGaugeSlot *slot);

void BTLV_GAUGE_DeleteSlotTask(BtlvGaugeWork *work, int slotIdx);

extern const char gBtlvGaugeSourceFileName[];

extern const struct ClactVec2 gBtlvGaugeSlideInOffset;

extern const struct ActorInitParam gBtlvGaugeActorInit;

extern const struct ClactVec2 gBtlvGaugeSlideOutOffset;

BtlvGaugeWork *BTLV_GAUGE_Create(void *font, u16 heapId)
{
    BtlvGaugeTileFile *tileFile;
    struct ClactVec2 pos;
    struct ClactVec2 base;
    BtlvGaugeWork *work;
    int i;
    void *statusArc;
    BtlvGaugeFlashTask *task;
    int firstSlot, lastSlot, layout;

    work = GFL_HEAP_Alloc(heapId, sizeof(BtlvGaugeWork), 1, gBtlvGaugeSourceFileName, 0x14b);
    work->heapId = heapId;
    work->arcHandle = ARC_TOOL_CreateHandle(0xb, (u16)work->heapId);
    work->unit = CLACT_CreateUnit(0x28, 0, work->heapId);
    for (i = 0; i < 6; i++) {
        work->palRes[i] = CLACT_RegisterPalette(work->arcHandle, 0xa2, 0, (u16)(i * 0x20), work->heapId);
        PALANM_CopyHwPaletteToSlot(BTLV_EFFECT_GetPalanm(), 2, (u16)(CLACT_GetPaletteVramAddress(work->palRes[i], 0) >> 1), 0x20);
    }
    statusArc = ARC_TOOL_CreateHandle(APP_ICON_GetArchiveId(), (u16)((work->heapId & 0x7fff) | 0x8000));
    work->statusCharRes = CLACT_RegisterCharacter(statusArc, APP_ICON_GetSealPaletteFileId(), 0, 0, work->heapId);
    work->statusCellRes = CLACT_RegisterCellAnim(statusArc, APP_ICON_GetSealAnimFileId(1), APP_ICON_GetSealFrameFileId(1), work->heapId);
    work->statusPalRes[0] = CLACT_RegisterPalette(statusArc, APP_ICON_GetSealCellFileId(), 0, 0x100, work->heapId);
    work->statusPalRes[1] = CLACT_RegisterPalette(statusArc, APP_ICON_GetSealCellFileId(), 0, 0x120, work->heapId);
    PALANM_CopyHwPaletteToSlot(BTLV_EFFECT_GetPalanm(), 2, (u16)(CLACT_GetPaletteVramAddress(work->statusPalRes[0], 0) >> 1), 0x20);
    PALANM_CopyHwPaletteToSlot(BTLV_EFFECT_GetPalanm(), 2, (u16)(CLACT_GetPaletteVramAddress(work->statusPalRes[1], 0) >> 1), 0x20);
    PALANM_BlendChannelMask(BTLV_EFFECT_GetPalanm(), 2, 0x200, 8, 0);
    ARC_TOOL_DeleteHandle(statusArc);
    work->screenData = ARC_UTIL_LoadScreenDataFromHandle((void *)work->arcHandle, (u32)0xa4, (u32)0, (&tileFile), work->heapId);
    work->tileGfx = tileFile->pixels;
    work->font = font;
    work->savedBgmNo = GFL_USE_GetBgmNo();
    task = GFL_HEAP_Alloc(heapId, sizeof(BtlvGaugeFlashTask), 1, gBtlvGaugeSourceFileName, 0x185);
    task->work = work;
    work->flashTask = TCB_AddTask(BTLV_EFFECT_GetOwner(), BTLV_GAUGE_TaskFlashPalettes, task, 0);
    switch (BTLV_EFFECT_GetMode()) {
    case 0:
        firstSlot = 0;
        lastSlot = 1;
        layout = 0;
        break;
    case 1:
        firstSlot = 2;
        lastSlot = 5;
        layout = 1;
        break;
    case 2:
    default:
        firstSlot = 2;
        lastSlot = 7;
        layout = 2;
        break;
    case 3:
        firstSlot = 2;
        lastSlot = 7;
        layout = 3;
        break;
    }
    for (i = firstSlot; i <= lastSlot; i++) {
        base = gBtlvGaugeSlideInOffset;
        pos = base;
        if (i & 1)
            pos.x *= -1;
        BTLV_GAUGE_LoadSlotResources(work, layout, i);
        work->slots[i].layout = layout;
        BTLV_GAUGE_PlaceSlot(work, i, &pos);
    }
    return work;
}

void BTLV_GAUGE_Delete(BtlvGaugeWork *work)
{
    BtlvGaugeSlotIndex i;
    int j;

    for (i = BTLV_GAUGE_SLOT_FIRST; i < BTLV_GAUGE_SLOT_COUNT; i++) {
        BTLV_GAUGE_DeleteSlotTask(work, i);
        BTLV_GAUGE_ReleaseSlotResources(work, i);
    }
    if (work->flags.lowHpBgmPlaying) {
        GFL_USE_PopBgm();
        BTLV_GAUGE_SetBgmPlayerParam(0);
    }
    for (j = 0; j < 6; j++)
        CLACT_ReleasePalette(work->palRes[j]);
    CLACT_ReleaseCharacter(work->statusCharRes);
    CLACT_ReleaseCellAnim(work->statusCellRes);
    CLACT_ReleasePalette(work->statusPalRes[0]);
    CLACT_ReleasePalette(work->statusPalRes[1]);
    CLACT_DeleteUnit(work->unit);
    GFL_HEAP_Free(work->screenData);
    ARC_TOOL_DeleteHandle(work->arcHandle);
    GFL_HEAP_Free(TCBL_GetOwnedWork(work->flashTask));
    TCB_DeleteTask(work->flashTask);
    GFL_HEAP_Free(work);
}

/*
 * lever: int mode, i, found puts the scan index in r0 and found in r1; mode, found, i differed at seven bytes.
 */
void BTLV_GAUGE_FlashTaskMain(BtlvGaugeWork *work)
{
    int mode, i, found;
    KEY_GetTrg();
    if (work->flags.stopRequested) {
        mode = BTLV_EFFECT_GetMode();
        work->flags.stopRequested = 0;
        if (mode != 0 && mode != 1) {
            found = 0;
            for (i = 0; i < 8; i++) {
                if (work->slots[i].flags.hpAnimating) {
                    found = 1;
                    break;
                }
            }
            if (found == 0) {
                work->flags.altDisplay ^= 1;
                for (i = 0; i < 8; i++) {
                    if (!(i & 1) && work->slots[i].flags.visible == 1 && work->slots[i].flags.occupied) {
                        BTLV_GAUGE_SetSlotBarsVisible(work, i, 1);
                        BTLV_GAUGE_StepValue(work->slots[i].maxHp, work->slots[i].hp, 0, &work->slots[i].hpAnimValue, 6, 1);
                        BTLV_GAUGE_DrawBar(work, i, 0);
                    }
                }
            }
        }
    }
    for (i = 0; i < 8; i++) {
        if (work->slots[i].flags.hpAnimating)
            BTLV_GAUGE_UpdateHpAnim(work, i);
        if (work->slots[i].flags.expAnimating) {
            if (work->slots[i].flags.expStep == 0)
                GFL_USE_PlaySeDefaultVolume(BTLV_GAUGE_SE_EXP_TICK);
            BTLV_GAUGE_UpdateExpAnim(work, i);
        }
        if (work->slots[i].flags.startPending) {
            if (work->slots[i].flags.expStep < 16)
                work->slots[i].flags.expStep++;
            if (!work->slots[i].flags.expAnimating && work->slots[i].flags.expStep == 16) {
                GFL_USE_StopAllSe();
                work->slots[i].flags.expStep++;
                work->slots[i].flags.startPending = 0;
            }
        }
        if (work->slots[i].flags.levelUpPending)
            BTLV_GAUGE_UpdateLevelUp(work, i);
        if (work->slots[i].flags.selected)
            BTLV_GAUGE_BobSlot(work, i);
        if (work->slots[i].hpLossActor != 0 && work->slots[i].flags.hitFlashOn) {
            if (work->slots[i].flags.hitFlashFrames == 0 || !work->slots[i].flags.occupied || !work->slots[i].flags.visible) {
                CLACT_SetActorDrawEnable((struct ClactActor *)work->slots[i].hpLossActor, 0);
                work->slots[i].flags.hitFlashOn = 0;
            } else {
                CLACT_SetActorDrawEnable((struct ClactActor *)work->slots[i].hpLossActor, work->slots[i].flags.hitFlashFrames & 1);
                work->slots[i].flags.hitFlashFrames--;
            }
            if (work->flags.altDisplay && !(i & 1))
                CLACT_SetActorDrawEnable((struct ClactActor *)work->slots[i].hpLossActor, 0);
        }
    }
    if (!work->flags.lowHpBgmSuppressed)
        BTLV_GAUGE_UpdateLowHpBgm(work);
}

/*
 * trailing: 02207286..02207288 is two zero alignment bytes.
 *
 * Battle-side twin of BTLV_GAUGE_InitSlotFromPartyPoke (same slot layout).
 *
 * lever: BTL_POKEPARAM_GetSickContRaw returns a one-word struct (BtlSickCont) passed by value to
 * BTL_SICKCONT_IsKind1Index15, as in the ov093 callers. The struct-return temporary
 * reserves the extra frame word (push r3, sub sp #0x28, slot sp+0x24 never
 * touched) and that one change also flips the slot stores to share work + i*0x80
 * in a scratch register; with int prototypes both residues remained
 * (2026-10-01 note: slot pointer local, char* offsets, inline helpers,
 * nested sub-struct, u8 index, x/y locals were all inert).
 */
void BTLV_GAUGE_InitSlotFromBattlePoke(BtlvGaugeWork *work, struct BtlMain *battleMain, struct BtlPokeParam *battlePoke, int layout, int slotIdx)
{
    u32 levelBaseExp;
    u16 species;
    int statusIcon;

    MIi_CpuClear16(0, &work->slots[slotIdx].layout, 0x40);
    work->slots[slotIdx].hp = BTL_POKEPARAM_GetValue(battlePoke, BTLV_GAUGE_BPP_HP);
    work->slots[slotIdx].maxHp = BTL_POKEPARAM_GetValue(battlePoke, BTLV_GAUGE_BPP_MAX_HP);
    work->slots[slotIdx].hpAnimValue = 0x80000000;
    work->slots[slotIdx].hpDelta = 0;
    work->slots[slotIdx].level = BTL_POKEPARAM_GetValue(battlePoke, BTLV_GAUGE_BPP_LEVEL);
    work->slots[slotIdx].layout = layout;
    work->slots[slotIdx].side = slotIdx & 1;
    work->slots[slotIdx].flags.eventPending = 1;
    if (work->slots[slotIdx].level < 100) {
        levelBaseExp = POKE_TOOL_GetExpForLevel(BTL_POKEPARAM_GetSpecies(battlePoke), BTL_POKEPARAM_GetValue(battlePoke, BTLV_GAUGE_BPP_FORM), BTL_POKEPARAM_GetValue(battlePoke, BTLV_GAUGE_BPP_LEVEL));
        work->slots[slotIdx].exp = BTL_POKEPARAM_GetValue(battlePoke, BTLV_GAUGE_BPP_EXP) - levelBaseExp;
        work->slots[slotIdx].expMax = POKE_TOOL_GetExpForLevel(BTL_POKEPARAM_GetSpecies(battlePoke), BTL_POKEPARAM_GetValue(battlePoke, BTLV_GAUGE_BPP_FORM), BTL_POKEPARAM_GetValue(battlePoke, BTLV_GAUGE_BPP_LEVEL) + 1) - levelBaseExp;
    } else {
        work->slots[slotIdx].exp = 0;
        work->slots[slotIdx].expMax = 0;
    }
    work->slots[slotIdx].expAnimValue = 0x80000000;
    work->slots[slotIdx].expDelta = 0;
    work->slots[slotIdx].unused6e = 0;
    work->slots[slotIdx].caught = BTL_MAIN_CheckZukanSeen(battleMain, battlePoke);
    species = BTL_POKEPARAM_GetSpecies(battlePoke);
    if (species != 32 && species != 29)
        work->slots[slotIdx].gender = POKE_TOOL_GetGender(BTL_POKEPARAM_GetDisplayMon(battlePoke));
    else
        work->slots[slotIdx].gender = 2;
    if (BTL_SICKCONT_IsKind1Index15(BTL_POKEPARAM_GetSickContRaw(battlePoke, 5)) == 1 && BTL_POKEPARAM_GetMajorStatusIndex(battlePoke) == 5)
        statusIcon = 6;
    else
        statusIcon = BTL_POKEPARAM_GetMajorStatusIndex(battlePoke);
    BTLV_GAUGE_SetStatusIcon(work, statusIcon, slotIdx);
    BTLV_GAUGE_PlaceSlot(work, slotIdx, 0);
    BTLV_GAUGE_SetSlotBarsVisible(work, slotIdx, 1);
    BTLV_GAUGE_UpdateHpBarPixels(&work->slots[slotIdx]);
    BTLV_GAUGE_UpdateSlot(work, layout, slotIdx, BTL_POKEPARAM_GetDisplayMon(battlePoke));
}

/*
 * trailing: 0220742E..02207430 is two zero alignment bytes.
 * lever: slots are an array member of the object; raw offset casts gave 416 bytes and the wrong field-base spills, while the member form gives exact 422 bytes.
 */
void BTLV_GAUGE_InitSlotFromPartyPoke(BtlvGaugeWork *work, struct ZukanSave *zukanSave, void *partyPoke, int layout, int slotIdx)
{
    u32 speciesForExp, formForExp, levelBaseExp;
    u16 species;
    MIi_CpuClear16(0, &work->slots[slotIdx].layout, 0x40);
    work->slots[slotIdx].hp = POKE_TOOL_GetPartyValue(partyPoke, BTLV_PARTY_VALUE_HP, 0);
    work->slots[slotIdx].maxHp = POKE_TOOL_GetPartyValue(partyPoke, BTLV_PARTY_VALUE_MAX_HP, 0);
    work->slots[slotIdx].hpAnimValue = 0x80000000;
    work->slots[slotIdx].hpDelta = 0;
    work->slots[slotIdx].level = POKE_TOOL_GetPartyValue(partyPoke, BTLV_PARTY_VALUE_LEVEL, 0);
    work->slots[slotIdx].layout = layout;
    work->slots[slotIdx].side = slotIdx & 1;
    work->slots[slotIdx].flags.eventPending = 1;
    if (work->slots[slotIdx].level < 100) {
        speciesForExp = POKE_TOOL_GetPartyValue(partyPoke, BTLV_PARTY_VALUE_SPECIES, 0);
        formForExp = POKE_TOOL_GetPartyValue(partyPoke, BTLV_PARTY_VALUE_FORM, 0);
        levelBaseExp = POKE_TOOL_GetExpForLevel(speciesForExp, formForExp, work->slots[slotIdx].level);
        work->slots[slotIdx].exp = POKE_TOOL_GetPartyValue(partyPoke, BTLV_PARTY_VALUE_EXP, 0) - levelBaseExp;
        work->slots[slotIdx].expMax = POKE_TOOL_GetExpForLevel(speciesForExp, formForExp, work->slots[slotIdx].level + 1) - levelBaseExp;
    } else {
        work->slots[slotIdx].exp = 0;
        work->slots[slotIdx].expMax = 0;
    }
    work->slots[slotIdx].expAnimValue = 0x80000000;
    work->slots[slotIdx].expDelta = 0;
    work->slots[slotIdx].unused6e = 0;
    species = POKE_TOOL_GetPartyValue(partyPoke, BTLV_PARTY_VALUE_SPECIES, 0);
    work->slots[slotIdx].caught = ZUKAN_SAVE_IsCaught(zukanSave, species);
    if (species != 32 && species != 29)
        work->slots[slotIdx].gender = POKE_TOOL_GetGender(partyPoke);
    else
        work->slots[slotIdx].gender = 2;
    BTLV_GAUGE_SetStatusIcon(work, POKE_TOOL_GetStatusCondition(partyPoke), slotIdx);
    BTLV_GAUGE_PlaceSlot(work, slotIdx, 0);
    BTLV_GAUGE_SetSlotBarsVisible(work, slotIdx, 1);
    BTLV_GAUGE_UpdateHpBarPixels(&work->slots[slotIdx]);
    BTLV_GAUGE_UpdateSlot(work, layout, slotIdx, partyPoke);
}

void BTLV_GAUGE_LoadSlotResources(BtlvGaugeWork *work, int layout, int slotIdx)
{
    int charFileId, cellFileId, cellAnimFileId, paletteFileId, palIdx, priorityBase, side;
    struct ActorInitParam actorInit;
    switch (layout) {
    case 0:
    case 1:
    default:
        charFileId = (slotIdx & 1) ? 0xa5 : 0xa8;
        cellFileId = (slotIdx & 1) ? 0xa6 : 0xa9;
        cellAnimFileId = (slotIdx & 1) ? 0xa7 : 0xaa;
        break;
    case 2:
    case 3:
        charFileId = (slotIdx & 1) ? 0xab : 0xae;
        cellFileId = (slotIdx & 1) ? 0xac : 0xaf;
        cellAnimFileId = (slotIdx & 1) ? 0xad : 0xb0;
        break;
    case 4:
        break;
    }
    if (layout == 3) {
        palIdx = slotIdx;
        if (slotIdx >= 2)
            palIdx = slotIdx - 2;
        paletteFileId = (slotIdx < 4) ? 0xa2 : 0xa3;
        CLACT_ReleasePalette(work->palRes[palIdx]);
        work->palRes[palIdx] = CLACT_RegisterPaletteEx(work->arcHandle, paletteFileId, 0, (u16)(palIdx << 5), 0, 1, work->heapId);
        PALANM_CopyHwPaletteToSlot(BTLV_EFFECT_GetPalanm(), 2, (u16)(CLACT_GetPaletteVramAddress(work->palRes[palIdx], 0) >> 1), 0x20);
    }
    work->slots[slotIdx].frameCharRes = CLACT_RegisterCharacter(work->arcHandle, charFileId, 0, 0, work->heapId);
    work->slots[slotIdx].frameCellRes = CLACT_RegisterCellAnim(work->arcHandle, cellFileId, cellAnimFileId, work->heapId);
    work->slots[slotIdx].numberCharRes = CLACT_RegisterCharacter(work->arcHandle, 0xba, 0, 0, work->heapId);
    work->slots[slotIdx].numberCellRes = CLACT_RegisterCellAnim(work->arcHandle, 0xbb, 0xbc, work->heapId);
    work->slots[slotIdx].barCharRes = CLACT_RegisterCharacter(work->arcHandle, 0xb1, 0, 0, work->heapId);
    work->slots[slotIdx].barCellRes = CLACT_RegisterCellAnim(work->arcHandle, 0xb2, 0xb3, work->heapId);
    work->slots[slotIdx].lossCharRes = CLACT_RegisterCharacter(work->arcHandle, 0xb4, 0, 0, work->heapId);
    work->slots[slotIdx].lossCellRes = CLACT_RegisterCellAnim(work->arcHandle, 0xb5, 0xb3, work->heapId);
    side = slotIdx & 1;
    if (side == 0) {
        work->slots[slotIdx].expCharRes = CLACT_RegisterCharacter(work->arcHandle, 0xb7, 0, 0, work->heapId);
        work->slots[slotIdx].expCellRes = CLACT_RegisterCellAnim(work->arcHandle, 0xb8, 0xb9, work->heapId);
    }
    actorInit = gBtlvGaugeActorInit;
    palIdx = slotIdx;
    if (slotIdx >= 2)
        palIdx = slotIdx - 2;
    priorityBase = (7 - slotIdx) * 3;
    actorInit.draw_priority = priorityBase + 2;
    work->slots[slotIdx].frameActor = CLACT_CreateActor(work->unit, work->slots[slotIdx].frameCharRes, work->palRes[palIdx], work->slots[slotIdx].frameCellRes, &actorInit, 0, work->heapId);
    actorInit.draw_priority = priorityBase + 1;
    work->slots[slotIdx].hpNumberActor = CLACT_CreateActor(work->unit, work->slots[slotIdx].numberCharRes, work->palRes[palIdx], work->slots[slotIdx].numberCellRes, &actorInit, 0, work->heapId);
    work->slots[slotIdx].hpBarActor = CLACT_CreateActor(work->unit, work->slots[slotIdx].barCharRes, work->palRes[palIdx], work->slots[slotIdx].barCellRes, &actorInit, 0, work->heapId);
    if (BTLV_EFFECT_GetMode() == 3 && slotIdx >= 4)
        work->slots[slotIdx].statusActor = CLACT_CreateActor(work->unit, work->statusCharRes, work->statusPalRes[1], work->statusCellRes, &actorInit, 0, work->heapId);
    else
        work->slots[slotIdx].statusActor = CLACT_CreateActor(work->unit, work->statusCharRes, work->statusPalRes[0], work->statusCellRes, &actorInit, 0, work->heapId);
    CLACT_SetActorAutoAnim((struct ClactActor *)work->slots[slotIdx].statusActor, 1);
    actorInit.draw_priority = priorityBase;
    work->slots[slotIdx].hpLossActor = CLACT_CreateActor(work->unit, work->slots[slotIdx].lossCharRes, work->palRes[palIdx], work->slots[slotIdx].lossCellRes, &actorInit, 0, work->heapId);
    CLACT_SetActorDrawEnable((struct ClactActor *)work->slots[slotIdx].hpLossActor, 0);
    if (side == 0 && layout != 2 && layout != 3)
        work->slots[slotIdx].expBarActor = CLACT_CreateActor(work->unit, work->slots[slotIdx].expCharRes, work->palRes[palIdx], work->slots[slotIdx].expCellRes, &actorInit, 0, work->heapId);
}

/*
 * extent: two zero bytes at 0220785A align the next function.
 * lever: indexed slots in the owning structure retain per-field bases;
 *   a raw offset or cast slot array caches the element and is 138/144 bytes.
 */
void BTLV_GAUGE_ReleaseSlotResources(BtlvGaugeWork *work, int slotIdx)
{
    if (work->slots[slotIdx].frameActor == 0)
        return;
    CLACT_ReleaseCharacter(work->slots[slotIdx].frameCharRes);
    CLACT_ReleaseCharacter(work->slots[slotIdx].numberCharRes);
    CLACT_ReleaseCharacter(work->slots[slotIdx].barCharRes);
    CLACT_ReleaseCharacter(work->slots[slotIdx].lossCharRes);
    CLACT_ReleaseCellAnim(work->slots[slotIdx].frameCellRes);
    CLACT_ReleaseCellAnim(work->slots[slotIdx].numberCellRes);
    CLACT_ReleaseCellAnim(work->slots[slotIdx].barCellRes);
    CLACT_ReleaseCellAnim(work->slots[slotIdx].lossCellRes);
    CLACT_DeleteActor((struct ClactActor *)work->slots[slotIdx].frameActor);
    CLACT_DeleteActor((struct ClactActor *)work->slots[slotIdx].hpNumberActor);
    CLACT_DeleteActor((struct ClactActor *)work->slots[slotIdx].hpBarActor);
    CLACT_DeleteActor((struct ClactActor *)work->slots[slotIdx].hpLossActor);
    CLACT_DeleteActor((struct ClactActor *)work->slots[slotIdx].statusActor);
    work->slots[slotIdx].frameActor = 0;
    work->slots[slotIdx].hpNumberActor = 0;
    work->slots[slotIdx].hpBarActor = 0;
    work->slots[slotIdx].hpLossActor = 0;
    work->slots[slotIdx].statusActor = 0;
    if ((slotIdx & 1) == 0) {
        CLACT_ReleaseCharacter(work->slots[slotIdx].expCharRes);
        CLACT_ReleaseCellAnim(work->slots[slotIdx].expCellRes);
    }
    if (work->slots[slotIdx].expBarActor != 0) {
        CLACT_DeleteActor((struct ClactActor *)work->slots[slotIdx].expBarActor);
        work->slots[slotIdx].expBarActor = 0;
    }
}

void BTLV_GAUGE_UpdateSlot(BtlvGaugeWork *work, int layout, int slotIdx, void *pokeParam)
{
    BTLV_GAUGE_StepValue(work->slots[slotIdx].maxHp, work->slots[slotIdx].hp, 0, &work->slots[slotIdx].hpAnimValue, 6, 1);
    BTLV_GAUGE_DrawBar(work, slotIdx, 0);
    if (work->slots[slotIdx].expBarActor != 0) {
        BTLV_GAUGE_StepValue(work->slots[slotIdx].expMax, work->slots[slotIdx].exp, 0, &work->slots[slotIdx].expAnimValue, 10, 1);
        BTLV_GAUGE_DrawBar(work, slotIdx, 1);
    }
    BTLV_GAUGE_DrawNickname(work, &work->slots[slotIdx], pokeParam);
    BTLV_GAUGE_DrawGender(work, &work->slots[slotIdx]);
    BTLV_GAUGE_DrawHpNumbers(work, &work->slots[slotIdx], work->slots[slotIdx].hp);
    BTLV_GAUGE_DrawLevel(work, &work->slots[slotIdx]);
    if (work->slots[slotIdx].side != 0 && BTLV_EFFECT_GetCompetitorType() == 0)
        BTLV_GAUGE_DrawCaughtIcon(work, &work->slots[slotIdx]);
    work->slots[slotIdx].flags.occupied = 1;
    work->slots[slotIdx].flags.slideCount = 2;
    work->slots[slotIdx].slideTask = TCB_AddTask(BTLV_EFFECT_GetOwner(), BTLV_GAUGE_TaskSlideSlot, &work->slots[slotIdx], 0);
}

void BTLV_GAUGE_UpdateHpBarPixels(BtlvGaugeSlot *slot)
{
    int hp = slot->hp;
    int maxHp = slot->maxHp;

    if (maxHp < 0x30)
        slot->hpBarPixels = (unsigned int)BTLV_GAUGE_CalcBarPixels(hp << 8, maxHp, 0x30) >> 8;
    else
        slot->hpBarPixels = (unsigned int)BTLV_GAUGE_CalcBarPixels(hp, maxHp, 0x30);
}

/*
 * lever: the occupied flag is cleared through a BtlvGaugeSlot array pointer while the other
 * accesses go through the work; the mixed bases keep the hoisted flag base of the original.
 */
/*
 * lever: the slot flags are reached through a hoisted byte pointer (work + 0x40 + 0x70) and a byte
 * offset; typed slot indexing allocates the registers differently (88 bytes instead of 96).
 */
void BTLV_GAUGE_DeleteSlotTask(BtlvGaugeWork *work, int slotIdx)
{
    char *slotFlagBase = (char *)work + 0xb0;
    int slotOffset = slotIdx * sizeof(BtlvGaugeSlot);
    void *task;

    if (((BtlvGaugeSlotFlags *)(slotFlagBase + slotOffset))->occupied) {
        struct ClactVec2 pt = gBtlvGaugeSlideOutOffset;

        if (slotIdx & 1)
            pt.x *= -1;
        BTLV_GAUGE_PlaceSlot(work, slotIdx, &pt);
        ((BtlvGaugeSlotFlags *)(slotFlagBase + slotOffset))->occupied = 0;
    }
    task = *(void **)((char *)work + slotOffset + 0xbc);
    if (task != 0) {
        TCB_DeleteTask(task);
        *(void **)((char *)work + slotOffset + 0xbc) = 0;
    }
}




#include "../arm9/strbuf.h"
struct Bmp;

typedef short s16_p07;
#include "../arm9/bmp.h"


#include "../arm9/gf_font.h"


#include "../arm9/printsys.h"
struct GfFont;


struct ImageProxy;





#include "../arm9/bgwinfrm.h"

#include "../arm9/wordset.h"










#include "../arm9/wifi_friend.h"



void BTLV_GAUGE_StartHpChangeAnimated(BtlvGaugeWork *work, int slotIdx, int newHp);

void BTLV_GAUGE_StartHpChangeInstant(BtlvGaugeWork *work, int slotIdx, int newHp);

void BTLV_GAUGE_StartExpGain(BtlvGaugeWork *work, int slotIdx, int gain);

void BTLV_GAUGE_RefreshForLevelUp(BtlvGaugeWork *work, struct BtlPokeParam *pp, int slotIdx);

int BTLV_GAUGE_IsAnimating(BtlvGaugeWork *work);

void BTLV_GAUGE_SetSideVisible(BtlvGaugeWork *work, int visible, int side);

void BTLV_GAUGE_SetSlotVisible(BtlvGaugeWork *work, int visible, int slotIdx);

int BTLV_GAUGE_IsSlotOccupied(BtlvGaugeWork *work, int slotIdx);

int BTLV_GAUGE_TakeSlotEvent(BtlvGaugeWork *work, int slotIdx);

void BTLV_GAUGE_StartHpChange(BtlvGaugeWork *work, BtlvGaugeSlot *slot, int newHp);

void BTLV_GAUGE_StartExpChange(BtlvGaugeSlot *slot, int gain);

u8 BTLV_GAUGE_CalcTileFill(u32 maxValue, int value, int delta, int *anim, u8 *tileFill, u8 tileCount);

int BTLV_GAUGE_CalcPixelChange(int value, int delta, int maxValue, unsigned int tileCount);

void BTLV_GAUGE_DrawHpLoss(BtlvGaugeWork *work, BtlvGaugeSlot *slot, int barPixels);

void BTLV_GAUGE_SelectSlot(BtlvGaugeWork *work, int selectedSlot);

unsigned int BTLV_GAUGE_IsLowHpBgmPlaying(BtlvGaugeWork *work);

void BTLV_GAUGE_SetLowHpBgmPlaying(BtlvGaugeWork *work, int playing);

void BTLV_GAUGE_SetSavedBgmNo(BtlvGaugeWork *work, int bgmNo);

void BTLV_GAUGE_SetBgmReplaced(BtlvGaugeWork *work, int replaced);

void BTLV_GAUGE_SetLowHpBgmSuppressed(BtlvGaugeWork *work, int suppressed);

int BTLV_GAUGE_GetSlotHealthInfo(BtlvGaugeWork *work, int slotIdx, int *hpState, int *statusAnim);

void BTLV_GAUGE_RequestStop(BtlvGaugeWork *work);

void BTLV_GAUGE_HideSlot(BtlvGaugeWork *work, int slotIdx);

extern const BtlvGaugePointPair sGaugeBarOffsets;

extern const BtlvGaugePointPair sGaugeStatusIconOffsets;

extern const BtlvGaugePointSix sGaugeDefaultPositions;

extern const BtlvGaugePointEight sGaugeLayout2Positions;

extern const BtlvGaugePointEight sGaugeLayout3Positions;

extern s16 FX_SinCosTable_[];

extern BtlvGaugeStatusAnimTable sGaugeStatusAnimTable;

extern const struct ClactVec2 sGaugeHomeOffset;

extern const BtlvGaugeMaskTable sGaugeFlashMasks;

/* Moves the actors of one gauge to the position of its layout, plus an optional offset. */
void BTLV_GAUGE_PlaceSlot(BtlvGaugeWork *work, int slotIdx, struct ClactVec2 *offset)
{
    BtlvGaugePointSix defaultPositions;
    BtlvGaugePointEight layout2Positions;
    BtlvGaugePointEight layout3Positions;
    struct ClactVec2 pos;
    BtlvGaugePointPair barOffsets;
    BtlvGaugePointPair statusOffsets;
    int x;
    int y;

    barOffsets = sGaugeBarOffsets;
    statusOffsets = sGaugeStatusIconOffsets;
    defaultPositions = sGaugeDefaultPositions;
    layout2Positions = sGaugeLayout2Positions;
    layout3Positions = sGaugeLayout3Positions;
    if (work->slots[slotIdx].layout == 2) {
        x = layout2Positions.p[slotIdx].x;
        y = layout2Positions.p[slotIdx].y;
    } else if (work->slots[slotIdx].layout == 3) {
        x = layout3Positions.p[slotIdx].x;
        y = layout3Positions.p[slotIdx].y;
    } else {
        x = defaultPositions.p[slotIdx].x;
        y = defaultPositions.p[slotIdx].y;
    }
    if (offset != 0) {
        x += offset->x;
        y += offset->y;
    }
    pos.x = x;
    pos.y = y;
    CLACT_AddActorSurfacePos(work->slots[slotIdx].frameActor, &pos, 0);
    if ((slotIdx & 1) == 0 && work->slots[slotIdx].layout == 0) {
        pos.x = x + 16;
        pos.y = y + 13;
        CLACT_AddActorSurfacePos(work->slots[slotIdx].hpNumberActor, &pos, 0);
    } else if ((slotIdx & 1) == 0 && work->slots[slotIdx].layout != 1) {
        pos.x = x + 16;
        pos.y = y + 7;
        CLACT_AddActorSurfacePos(work->slots[slotIdx].hpNumberActor, &pos, 0);
    }
    pos.x = x + barOffsets.p[slotIdx & 1].x;
    pos.y = y + barOffsets.p[slotIdx & 1].y;
    CLACT_AddActorSurfacePos(work->slots[slotIdx].hpBarActor, &pos, 0);
    pos.x = x + statusOffsets.p[slotIdx & 1].x;
    pos.y = y + statusOffsets.p[slotIdx & 1].y;
    CLACT_AddActorSurfacePos(work->slots[slotIdx].statusActor, &pos, 0);
    if (work->slots[slotIdx].expBarActor != 0) {
        pos.x = x + 8;
        pos.y = y + 21;
        CLACT_AddActorSurfacePos(work->slots[slotIdx].expBarActor, &pos, 0);
    }
}

/* Starts an HP change with a per-frame speed of 1. */
void BTLV_GAUGE_StartHpChangeAnimated(BtlvGaugeWork *work, int slotIdx, int newHp)
{
    BTLV_GAUGE_StartHpChange(work, &work->slots[slotIdx], newHp);
    work->slots[slotIdx].hpAnimSpeed = 1;
}

/* Starts an HP change that jumps to the target (speed 0). */
void BTLV_GAUGE_StartHpChangeInstant(BtlvGaugeWork *work, int slotIdx, int newHp)
{
    BTLV_GAUGE_StartHpChange(work, &work->slots[slotIdx], newHp);
    work->slots[slotIdx].hpAnimSpeed = 0;
}

/* Starts an EXP gain on a slot. */
void BTLV_GAUGE_StartExpGain(BtlvGaugeWork *work, int slotIdx, int gain)
{
    work->slots[slotIdx].flags.expStep = 0;
    work->slots[slotIdx].flags.startPending = 1;
    BTLV_GAUGE_StartExpChange(&work->slots[slotIdx], gain);
}

/* Reloads HP, level and EXP span from the Pokemon after a level up and fills the EXP bar. */
void BTLV_GAUGE_RefreshForLevelUp(BtlvGaugeWork *work, struct BtlPokeParam *pp, int slotIdx)
{
    int remaining;
    u32 nextLevelExp;

    remaining = work->slots[slotIdx].expMax - work->slots[slotIdx].exp;
    work->slots[slotIdx].hp = BTL_POKEPARAM_GetValue(pp, BTLV_GAUGE_BPP_HP);
    work->slots[slotIdx].maxHp = BTL_POKEPARAM_GetValue(pp, BTLV_GAUGE_BPP_MAX_HP);
    work->slots[slotIdx].hpAnimValue = (int)0x80000000;
    work->slots[slotIdx].hpDelta = 0;
    work->slots[slotIdx].level = BTL_POKEPARAM_GetValue(pp, BTLV_GAUGE_BPP_LEVEL);
    nextLevelExp = POKE_TOOL_GetExpForLevel(BTL_POKEPARAM_GetSpecies(pp), BTL_POKEPARAM_GetValue(pp, BTLV_GAUGE_BPP_FORM), BTL_POKEPARAM_GetValue(pp, BTLV_GAUGE_BPP_LEVEL) + 1);
    work->slots[slotIdx].expPerLevel = nextLevelExp - POKE_TOOL_GetExpForLevel(BTL_POKEPARAM_GetSpecies(pp), BTL_POKEPARAM_GetValue(pp, BTLV_GAUGE_BPP_FORM), BTL_POKEPARAM_GetValue(pp, BTLV_GAUGE_BPP_LEVEL));
    work->slots[slotIdx].flags.levelUpPhase = 0;
    work->slots[slotIdx].flags.levelUpPending = 1;
    work->slots[slotIdx].flags.expStep = 0;
    work->slots[slotIdx].flags.startPending = 1;
    BTLV_GAUGE_StartExpChange(&work->slots[slotIdx], remaining);
}

/* Returns 1 while any gauge animation runs or is requested. */
int BTLV_GAUGE_IsAnimating(BtlvGaugeWork *work)
{
    int i;

    for (i = 0; i < BTLV_GAUGE_SLOT_COUNT; i++) {
        BtlvGaugeSlotFlags *flags;

        flags = &work->slots[i].flags;
        if (flags->hpAnimating || flags->expAnimating || flags->levelUpPending || flags->startPending) return 1;
    }
    return 0;
}

/*
 * Shows or hides the gauges of one side (2 = both sides).
 * Lever: an enum-typed loop counter keeps the entry guard (cmp r4,#8; bge)
 * that a plain int counter rotates away.
 */
void BTLV_GAUGE_SetSideVisible(BtlvGaugeWork *work, int visible, int side)
{
    BtlvGaugeSlotIndex i;

    for (i = BTLV_GAUGE_SLOT_FIRST; i < BTLV_GAUGE_SLOT_COUNT; i = (BtlvGaugeSlotIndex)(i + 1)) {
        if (side == 2 || side == work->slots[i].side) {
            if (work->slots[i].flags.occupied) {
                BTLV_GAUGE_SetSlotVisible(work, visible, (int)i);
            }
        }
    }
}

/* Shows or hides all actors of one gauge. */
void BTLV_GAUGE_SetSlotVisible(BtlvGaugeWork *work, int visible, int slotIdx)
{
    work->slots[slotIdx].flags.visible = visible;
    CLACT_SetActorDrawEnable((struct ClactActor *)work->slots[slotIdx].frameActor, visible);
    BTLV_GAUGE_SetSlotBarsVisible(work, slotIdx, visible);
    if (work->slots[slotIdx].expBarActor != 0) {
        CLACT_SetActorDrawEnable((struct ClactActor *)work->slots[slotIdx].expBarActor, visible);
    }
    if (work->slots[slotIdx].statusActor != 0) {
        if (CLACT_GetActorAnimSeq((struct ClactActor *)work->slots[slotIdx].statusActor) != 0) {
            CLACT_SetActorDrawEnable((struct ClactActor *)work->slots[slotIdx].statusActor, visible);
        }
    }
}

int BTLV_GAUGE_IsSlotOccupied(BtlvGaugeWork *work, int slotIdx)
{
    if (work->slots[slotIdx].flags.occupied) return 1;
    return 0;
}

/* Returns and clears the pending event flag of a slot. */
int BTLV_GAUGE_TakeSlotEvent(BtlvGaugeWork *work, int slotIdx)
{
    int pending = 0;

    if (work->slots[slotIdx].frameActor != 0) {
        BtlvGaugeSlotFlags *flags = &work->slots[slotIdx].flags;

        pending = flags->eventPending;
        flags->eventPending = 0;
    }
    return pending;
}

/*
 * Starts an HP change: the slot goes from its current HP to newHp.
 * Lever: slot->hp is read from the struct in both statements (no local), so
 * the load stays after the 0x50 store.
 */
void BTLV_GAUGE_StartHpChange(BtlvGaugeWork *work, BtlvGaugeSlot *slot, int newHp)
{
    struct ClactVec2 pos;

    slot->hpAnimValue = 0x80000000;
    slot->hpDelta = slot->hp - newHp;
    if (slot->hp < 0) {
        slot->hp = 0;
    }
    if (slot->hp > slot->maxHp) {
        slot->hp = slot->maxHp;
    }
    slot->flags.hpAnimating = 1;
    if (slot->hpDelta > 0) {
        BTLV_GAUGE_UpdateHpBarPixels(slot);
        CLACT_GetActorSurfacePos(slot->hpBarActor, &pos, 0);
        pos.x = pos.x - (s16)(0x30 - slot->hpBarPixels);
        CLACT_AddActorSurfacePos(slot->hpLossActor, &pos, 0);
        CLACT_SetActorDrawEnable((struct ClactActor *)slot->hpLossActor, 1);
        BTLV_GAUGE_DrawHpLoss(work, slot, slot->hpBarPixels);
    }
}

/* One frame of the HP bar animation. */
void BTLV_GAUGE_UpdateHpAnim(BtlvGaugeWork *work, int slotIdx)
{
    BtlvGaugeSlot *slot;
    int shownHp;

    slot = &work->slots[slotIdx];
    shownHp = BTLV_GAUGE_StepValue(slot->maxHp, slot->hp, slot->hpDelta, &slot->hpAnimValue, (int)6, (u16)slot->hpAnimSpeed);
    BTLV_GAUGE_DrawBar(work, slotIdx, 0);
    if (shownHp == -1) {
        slot->hp = slot->hp - slot->hpDelta;
        BTLV_GAUGE_DrawHpNumbers(work, slot, slot->hp);
        slot->flags.hpAnimating = 0;
        slot->hpAnimValue = 0;
        if (slot->hpDelta > 0) {
            slot->flags.hitFlashFrames = 18;
            slot->flags.hitFlashOn = 1;
        }
    } else {
        BTLV_GAUGE_DrawHpNumbers(work, slot, shownHp);
    }
}

/*
 * Starts an EXP change of gain points (clamped to the bar).
 * Lever: the clamp bound slot->expMax is read from the struct twice (no local).
 */
void BTLV_GAUGE_StartExpChange(BtlvGaugeSlot *slot, int gain)
{
    int exp;
    int newExp;

    if (slot->level != 100) {
        exp = slot->exp;
        slot->expAnimValue = 0x80000000;
        newExp = exp + gain;
        if (newExp < 0) {
            gain -= newExp;
        }
        newExp = exp + gain;
        if (newExp > slot->expMax) {
            gain -= newExp - slot->expMax;
        }
        slot->expDelta = -gain;
        if (slot->exp < 0) {
            slot->exp = 0;
        }
        if (slot->exp > slot->expMax) {
            slot->exp = slot->expMax;
        }
        slot->flags.expAnimating = 1;
    }
}

/* One frame of the EXP bar animation. */
void BTLV_GAUGE_UpdateExpAnim(BtlvGaugeWork *work, int slotIdx)
{
    BtlvGaugeSlot *slot;
    int pixelsPerStep;
    int speed;
    int shownExp;

    slot = &work->slots[slotIdx];
    pixelsPerStep = BTLV_GAUGE_CalcPixelChange(slot->exp, slot->expDelta, slot->expMax, 10);
    if (pixelsPerStep == 0) {
        pixelsPerStep = 1;
    }
    speed = slot->expDelta / pixelsPerStep;
    if (speed < 0) {
        speed = -speed;
    }
    if (speed == 0) {
        speed = 1;
    }
    shownExp = BTLV_GAUGE_StepValue(slot->expMax, slot->exp, slot->expDelta, &slot->expAnimValue, (int)10, (u16)speed);
    BTLV_GAUGE_DrawBar(work, slotIdx, 1);
    if (shownExp == -1) {
        slot->exp = slot->exp - slot->expDelta;
        slot->flags.expAnimating = 0;
        slot->expAnimValue = 0;
    }
}

/*
 * Steps a gauge value toward value - delta. anim is the fixed-point
 * accumulator (0x80000000 = not started). Returns the value to show, or -1
 * when the target is reached.
 */
int BTLV_GAUGE_StepValue(int maxValue, int value, int delta, int *anim, u8 tileCount, int speed)
{
    u8 tilePixels;
    int goal;
    int shown;
    int pixelStep;

    tilePixels = tileCount * 8;
    if (*anim == (int)0x80000000) {
        if (maxValue < tilePixels)
            *anim = value << 8;
        else
            *anim = value;
    }
    goal = value - delta;
    if (goal < 0)
        goal = 0;
    else if (goal > maxValue)
        goal = maxValue;
    if (maxValue < tilePixels) {
        if (goal == (*anim >> 8) && (*anim & 0xff) == 0)
            return -1;
    } else if (goal == *anim) {
        return -1;
    }
    if (maxValue < tilePixels) {
        pixelStep = (maxValue << 8) / tilePixels;
        if (delta < 0) {
            *anim += pixelStep;
            shown = *anim >> 8;
            if (shown >= goal || speed == 0) {
                *anim = goal << 8;
                return goal;
            }
        } else {
            *anim -= pixelStep;
            shown = *anim >> 8;
            if ((*anim & 0xff) > 0)
                shown++;
            if (shown <= goal || speed == 0) {
                *anim = goal << 8;
                return goal;
            }
        }
    } else {
        if (delta < 0) {
            *anim += speed;
            if (*anim > goal || speed == 0)
                *anim = goal;
        } else {
            *anim -= speed;
            if (*anim < goal || speed == 0)
                *anim = goal;
        }
        shown = *anim;
    }
    return shown;
}

/*
 * Fills tileFill[0..tileCount-1] with the filled pixels (0..8) of each bar
 * tile and returns the total filled pixels.
 * Levers: tileCount is a u8 stack parameter (ldrb [sp,#0x1c]); the return value is a
 * separate copy `result` of the running count (declared before the loop index j
 * so result takes r2 and j r3).
 */
u8 BTLV_GAUGE_CalcTileFill(u32 maxValue, int value, int delta, int *anim, u8 *tileFill, u8 tileCount)
{
    int goal;
    int i;
    u32 totalPixels;
    u32 pixels;
    u32 result;
    int j;

    goal = value - delta;
    if (goal < 0) {
        goal = 0;
    } else if (goal > (int)maxValue) {
        goal = maxValue;
    }
    totalPixels = tileCount * 8;
    for (i = 0; i < tileCount; i++) {
        tileFill[i] = 0;
    }
    if (maxValue < totalPixels) {
        pixels = (*anim * totalPixels) / maxValue >> 8;
    } else {
        pixels = (*anim * totalPixels) / maxValue;
    }
    result = pixels;
    if (pixels == 0 && goal > 0) {
        result = 1;
        tileFill[0] = 1;
    } else {
        for (j = 0; j < tileCount; j++) {
            if (pixels >= 8) {
                tileFill[j] = 8;
                pixels -= 8;
            } else {
                tileFill[j] = pixels;
                break;
            }
        }
    }
    return result;
}

/* Returns the number of bar pixels that value - delta differs from value. */
int BTLV_GAUGE_CalcPixelChange(int value, int delta, int maxValue, unsigned int tileCount)
{
    int totalPixels;
    int goal;
    int pixelsBefore;
    int pixelsAfter;
    int diff;

    totalPixels = (tileCount << 27) >> 24;
    goal = value - delta;
    if (goal < 0) {
        goal = 0;
    } else if (goal > maxValue) {
        goal = maxValue;
    }
    pixelsBefore = (value * totalPixels) / maxValue;
    pixelsAfter = (goal * totalPixels) / maxValue;
    diff = (signed char)pixelsBefore - (signed char)pixelsAfter;
    diff = (signed char)diff;
    if (diff < 0) {
        diff = -diff;
    }
    return diff;
}

/*
 * Draws the nickname of pokeParam on the frame actor.
 * lever: an enum VRAM base assigned in both copy arms prevents folding
 *   each base-plus-offset into a separate literal pool word.
 */
void BTLV_GAUGE_DrawNickname(BtlvGaugeWork *work, BtlvGaugeSlot *slot, void *pokeParam)
{
    struct Strbuf *name;
    struct BmpData *bmp;
    char *pixels;
    BtlvGaugeImageProxy proxy;
    u8 textColor[3];
    BtlvGaugeVramBase vram;

    name = STRBUF_Create(12, (u16)((work->heapId & 0x7fff) | 0x8000));
    bmp = (struct BmpData *)BMP_Create(8, 2, 32, (u16)((work->heapId & 0x7fff) | 0x8000));
    BMP_Clear((struct Bmp *)bmp, 0);
    POKE_TOOL_GetPartyValue(pokeParam, (u32)BTLV_PARTY_VALUE_NICKNAME, (uptr)name);
    GF_FONT_GetTextColor(&textColor[2], &textColor[1], &textColor[0]);
    GF_FONT_SetTextColor(1, 4, 0);
    if ((int)PRINTSYS_MeasureWidestLine(name, work->font, 0) > 48)
        PRINTSYS_Print((struct Bmp *)bmp, 2, 5, name, work->font);
    else
        PRINTSYS_Print((struct Bmp *)bmp, 8, 5, name, work->font);
    GF_FONT_SetTextColor(textColor[2], textColor[1], textColor[0]);
    pixels = BMP_GetPixels((struct Bmp *)bmp);
    CLACT_GetActorImageProxy((char *)slot->frameActor, (struct ImageProxy *)(&proxy));
    if (slot->side != 0) {
        vram = BTLV_GAUGE_OBJ_VRAM;
        MIi_CpuCopy16(pixels, (void *)(vram + 0x40 + proxy.vramOffset), 0xc0);
        MIi_CpuCopy16(pixels + 0x100, (void *)(vram + 0x140 + proxy.vramOffset), 0xc0);
        MIi_CpuCopy16(pixels + 0xc0, (void *)(vram + 0x400 + proxy.vramOffset), 0x40);
        MIi_CpuCopy16(pixels + 0x1c0, (void *)(vram + 0x500 + proxy.vramOffset), 0x40);
    } else {
        vram = BTLV_GAUGE_OBJ_VRAM;
        MIi_CpuCopy16(pixels, (void *)(vram + 0x20 + proxy.vramOffset), 0xe0);
        MIi_CpuCopy16(pixels + 0x100, (void *)(vram + 0x120 + proxy.vramOffset), 0xe0);
        MIi_CpuCopy16(pixels + 0xe0, (void *)(vram + 0x400 + proxy.vramOffset), 0x20);
        MIi_CpuCopy16(pixels + 0x1e0, (void *)(vram + 0x500 + proxy.vramOffset), 0x20);
    }
    STRBUF_Delete(name);
    BMP_Delete((struct Bmp *)bmp);
}

/* Draws the gender symbol on the frame actor. */
void BTLV_GAUGE_DrawGender(BtlvGaugeWork *work, BtlvGaugeSlot *slot)
{
    BtlvGaugeImageProxy proxy;
    int srcTop;
    int srcBottom;
    BtlvGaugeVramBase vram;

    srcTop = slot->gender * 64 + 0x380;
    srcBottom = slot->gender * 64 + 0x3a0;
    if (slot->gender == 2) {
        srcTop = 0x660;
        srcBottom = 0x660;
    }
    CLACT_GetActorImageProxy((char *)slot->frameActor, (struct ImageProxy *)(&proxy));
    if (slot->side != 0) {
        vram = BTLV_GAUGE_OBJ_VRAM;
        MIi_CpuCopy16(work->tileGfx + srcTop, (void *)(vram + 0x440 + proxy.vramOffset), 0x20);
        MIi_CpuCopy16(work->tileGfx + srcBottom, (void *)(vram + 0x540 + proxy.vramOffset), 0x20);
    } else {
        vram = BTLV_GAUGE_OBJ_VRAM;
        MIi_CpuCopy16(work->tileGfx + srcTop, (void *)(vram + 0x420 + proxy.vramOffset), 0x20);
        MIi_CpuCopy16(work->tileGfx + srcBottom, (void *)(vram + 0x520 + proxy.vramOffset), 0x20);
    }
}

/*
 * Draws the tiles of a bar: kind 0 is the HP bar, kind 1 the EXP bar.
 * trailing: 0220841E..02208420 is two bytes of zero alignment padding.
 * lever: u8 count retains the result spill; enum VRAM base preserves add
 *   order and register home; zero the loop counter before assigning base.
 */
void BTLV_GAUGE_DrawBar(BtlvGaugeWork *work, int slotIdx, int kind)
{
    BtlvGaugeSlot *slot;
    u8 tileFill[10];
    BtlvGaugeImageProxy proxy;
    int colorOffset, shownValue;
    u8 barPixels, i;
    BtlvGaugeVramBase base;

    slot = &work->slots[slotIdx];
    switch (kind) {
    case 0:
        if (work->flags.altDisplay && !(slotIdx & 1)) break;
        CLACT_GetActorImageProxy((char *)slot->hpBarActor, (struct ImageProxy *)(&proxy));
        barPixels = BTLV_GAUGE_CalcTileFill(slot->maxHp, slot->hp, slot->hpDelta, &slot->hpAnimValue, tileFill, 6);
        shownValue = slot->hpAnimValue;
        if (slot->maxHp < 48) shownValue >>= 8;
        switch (BGWINFRM_GetScaleRank(shownValue, slot->maxHp)) {
        case 0: colorOffset = 0; break;
        case 1: colorOffset = 0x120; break;
        case 2:
        default: colorOffset = 0x240; break;
        }
        for (i = 0; i < 6; i++) {
            base = BTLV_GAUGE_OBJ_VRAM;
            MIi_CpuCopy16(work->tileGfx + (colorOffset + tileFill[i] * 32), (void *)(proxy.vramOffset + (base + (i + 1) * 32)), 32);
        }
        if (slot->hpDelta > 0) BTLV_GAUGE_DrawHpLoss(work, slot, barPixels);
        break;
    case 1:
        if (slot->expBarActor == 0) break;
        CLACT_GetActorImageProxy((char *)slot->expBarActor, (struct ImageProxy *)(&proxy));
        BTLV_GAUGE_CalcTileFill(slot->expMax, slot->exp, slot->expDelta, &slot->expAnimValue, tileFill, 10);
        if (slot->level == 100) {
            for (i = 0; i < 10; i++) tileFill[i] = 0;
        }
        i = 0;
        base = BTLV_GAUGE_OBJ_VRAM;
        for (; i < 10; i++) {
            MIi_CpuCopy16(work->tileGfx + (tileFill[i] * 32 + 0x400), (void *)(proxy.vramOffset + (base + (i + 1) * 32)), 32);
        }
        break;
    }
}

/* Draws the "current/max" HP numbers (player side only). */
void BTLV_GAUGE_DrawHpNumbers(const BtlvGaugeWork *work, BtlvGaugeSlot *slot, int hp)
{
    BtlvGaugeImageProxy proxy;
    u16 curTile[3];
    u16 maxTile[3];
    int i, maxHp, maxIdx;
    BtlvGaugeVramBase base;
    if (slot->hpNumberActor != 0) {
        CLACT_GetActorImageProxy((char *)slot->hpNumberActor, (struct ImageProxy *)(&proxy));
        for (i = 0; i < 3; i++) {
            curTile[i] = 0x660;
            maxTile[i] = 0x660;
        }
        if (hp >= 100) {
            curTile[0] = hp / 100 * 32 + 0x520;
            hp %= 100;
        }
        if (hp >= 10 || curTile[0] != 0x660) {
            curTile[1] = hp / 10 * 32 + 0x520;
            hp %= 10;
        }
        curTile[2] = hp * 32 + 0x520;
        maxHp = slot->maxHp;
        maxIdx = 0;
        if (maxHp >= 100) {
            maxTile[maxIdx] = maxHp / 100 * 32 + 0x520;
            maxHp %= 100;
            maxIdx++;
        }
        if (maxHp >= 10 || maxIdx != 0) {
            maxTile[maxIdx] = maxHp / 10 * 32 + 0x520;
            maxHp %= 10;
            maxIdx++;
        }
        maxTile[maxIdx] = maxHp * 32 + 0x520;
        i = 0;
        base = BTLV_GAUGE_OBJ_VRAM;
        for (; i < 3; i++) {
            MIi_CpuCopy16(work->tileGfx + curTile[i], (void *)(proxy.vramOffset + (base + i * 32)), 32);
            MIi_CpuCopy16(work->tileGfx + maxTile[i], (void *)(proxy.vramOffset + (base + (i + 4) * 32)), 32);
        }
    }
}

/*
 * Draws the level ("Lv" and number) on the frame actor.
 */
void BTLV_GAUGE_DrawLevel(BtlvGaugeWork *work, BtlvGaugeSlot *slot)
{
    struct Strbuf *text;
    struct BmpData *bmp;
    char *pixels;
    BtlvGaugeImageProxy proxy;
    u8 textColor[3];
    BtlvGaugeVramBase base;
    text = STRBUF_Create(4, (u16)((work->heapId & 0x7fff) | 0x8000));
    bmp = (struct BmpData *)BMP_Create(3, 2, 32, (u16)((work->heapId & 0x7fff) | 0x8000));
    BMP_Clear((struct Bmp *)bmp, 0);
    WORDSET_FormatNumber(text, slot->level, 3, 0, 0);
    GF_FONT_GetTextColor(&textColor[2], &textColor[1], &textColor[0]);
    GF_FONT_SetTextColor(1, 4, 0);
    PRINTSYS_Print((struct Bmp *)bmp, 0, 5, text, work->font);
    GF_FONT_SetTextColor(textColor[2], textColor[1], textColor[0]);
    pixels = BMP_GetPixels((struct Bmp *)bmp);
    CLACT_GetActorImageProxy((char *)slot->frameActor, (struct ImageProxy *)(&proxy));
    if (slot->side != 0) {
        base = BTLV_GAUGE_OBJ_VRAM;
        MIi_CpuCopy16(pixels, (void *)(base + 0x480 + proxy.vramOffset), 0x60);
        MIi_CpuCopy16(pixels + 0x60, (void *)(base + 0x580 + proxy.vramOffset), 0x60);
    } else {
        base = BTLV_GAUGE_OBJ_VRAM;
        MIi_CpuCopy16(pixels, (void *)(base + 0x460 + proxy.vramOffset), 0x60);
        MIi_CpuCopy16(pixels + 0x60, (void *)(base + 0x560 + proxy.vramOffset), 0x60);
    }
    STRBUF_Delete(text);
    BMP_Delete((struct Bmp *)bmp);
}

/* Draws the "already caught" icon (blank when not caught). */
void BTLV_GAUGE_DrawCaughtIcon(BtlvGaugeWork *work, BtlvGaugeSlot *slot)
{
    BtlvGaugeImageProxy proxy;
    int srcOffset;
    BtlvGaugeVramBase vram;

    srcOffset = 0x360;
    if (slot->caught == 0)
        srcOffset = 0x660;
    CLACT_GetActorImageProxy((char *)slot->frameActor, (struct ImageProxy *)(&proxy));
    vram = BTLV_GAUGE_OBJ_VRAM;
    MIi_CpuCopy16(work->tileGfx + srcOffset, (void *)(vram + 0x120 + proxy.vramOffset), 0x20);
}

/* Draws the tiles of the HP-loss marker: barPixels is the new fill, hpBarPixels the old one. */
void BTLV_GAUGE_DrawHpLoss(BtlvGaugeWork *work, BtlvGaugeSlot *slot, int barPixels)
{
    u8 tileFill[6];
    BtlvGaugeImageProxy proxy;
    int lostPixels;
    int i;
    BtlvGaugeVramBase vram;

    lostPixels = slot->hpBarPixels - barPixels;
    for (i = 0; i < 6; i++)
        tileFill[i] = 8;
    for (i = 5; i >= 0; i--) {
        if (lostPixels >= 8) {
            tileFill[i] = 0;
            lostPixels -= 8;
        } else {
            tileFill[i] = 8 - lostPixels;
            break;
        }
    }
    CLACT_GetActorImageProxy((char *)slot->hpLossActor, (struct ImageProxy *)(&proxy));

    i = 0;
    vram = BTLV_GAUGE_OBJ_VRAM;
    for (; i < 6; i++)
        MIi_CpuCopy16(work->tileGfx + (tileFill[i] * 32 + 0x6a0), (void *)(vram + i * 32 + proxy.vramOffset), 0x20);
}

/* Level-up sequence of one slot: sound, then redraw of bars, numbers and level. */
void BTLV_GAUGE_UpdateLevelUp(BtlvGaugeWork *work, int slotIdx)
{
    BtlvGaugeSlot *slot;
    slot = &work->slots[slotIdx];
    if (slot->flags.expAnimating == 0) {
        switch (slot->flags.levelUpPhase) {
        case 0:
            GFL_USE_PlaySeDefaultVolume(BTLV_GAUGE_SE_LEVEL_UP);
            slot->flags.levelUpPhase++;
            break;
        case 1:
            slot->flags.levelUpPhase++;
            break;
        case 2:
            slot->exp = 0;
            slot->expMax = slot->expPerLevel;
            slot->expAnimValue = 0x80000000;
            slot->expDelta = 0;
            BTLV_GAUGE_StepValue(slot->maxHp, slot->hp, 0, &slot->hpAnimValue, 6, 1);
            BTLV_GAUGE_StepValue(slot->expMax, slot->exp, 0, &slot->expAnimValue, 10, 1);
            BTLV_GAUGE_DrawBar(work, slotIdx, 0);
            BTLV_GAUGE_DrawBar(work, slotIdx, 1);
            BTLV_GAUGE_DrawHpNumbers(work, slot, slot->hp);
            BTLV_GAUGE_DrawLevel(work, slot);
            slot->flags.levelUpPending = 0;
            break;
        }
    }
}

/*
 * Bobs the gauge of a slot with the sine of the work angle.
 * Lever: the angle is read into an int local (asrs, not lsrs).
 */
void BTLV_GAUGE_BobSlot(BtlvGaugeWork *work, int slotIdx)
{
    struct ClactVec2 offset;
    int angle;

    offset.x = -16;
    angle = work->flags.bobAngle;
    offset.y = FX_SinCosTable_[2 * (angle >> 4)] / 0x800;
    work->flags.bobAngle += 0x400;
    BTLV_GAUGE_PlaceSlot(work, slotIdx, &offset);
}

/* Sets the status icon of a slot (0 hides it). */
void BTLV_GAUGE_SetStatusIcon(BtlvGaugeWork *work, int status, int slotIdx)
{
    BtlvGaugeStatusAnimTable statusAnim = sGaugeStatusAnimTable;

    if (work->slots[slotIdx].statusActor != 0) {
        if (status == 0) {
            CLACT_SetActorDrawEnable((struct ClactActor *)work->slots[slotIdx].statusActor, 0);
            CLACT_SetActorAnimSeq((struct ClactActor *)work->slots[slotIdx].statusActor, 0);
        } else {
            CLACT_SetActorDrawEnable((struct ClactActor *)work->slots[slotIdx].statusActor, 1);
            CLACT_SetActorAnimSeq((struct ClactActor *)work->slots[slotIdx].statusActor, statusAnim.anim[status]);
        }
    }
}

/* Raises the selected target slot and puts back the previous one (8 = none). */
void BTLV_GAUGE_SelectSlot(BtlvGaugeWork *work, int selectedSlot)
{
    struct ClactVec2 resetOffset;
    struct ClactVec2 homeOffset = sGaugeHomeOffset;
    int i;

    for (i = 0; i < 8; i++) {
        if (work->slots[i].frameActor != 0 && work->slots[i].flags.selected) {
            resetOffset = homeOffset;
            work->slots[i].flags.selected = 0;
            BTLV_GAUGE_PlaceSlot(work, i, &resetOffset);
        }
    }
    if (selectedSlot != 8) {
        work->slots[selectedSlot].flags.selected = 1;
        work->flags.bobAngle = 0;
    }
}

unsigned int BTLV_GAUGE_IsLowHpBgmPlaying(BtlvGaugeWork *work)
{
    return work->flags.lowHpBgmPlaying;
}

void BTLV_GAUGE_SetLowHpBgmPlaying(BtlvGaugeWork *work, int playing)
{
    work->flags.lowHpBgmPlaying = playing;
}

void BTLV_GAUGE_SetSavedBgmNo(BtlvGaugeWork *work, int bgmNo)
{
    work->savedBgmNo = bgmNo;
}

void BTLV_GAUGE_SetBgmReplaced(BtlvGaugeWork *work, int replaced)
{
    work->flags.bgmReplaced = replaced;
}

void BTLV_GAUGE_SetLowHpBgmSuppressed(BtlvGaugeWork *work, int suppressed)
{
    work->flags.lowHpBgmSuppressed = suppressed;
}

/* Returns 1 and the HP state and status icon animation of a shown slot, else 0 (state 0, anim 8). */
int BTLV_GAUGE_GetSlotHealthInfo(BtlvGaugeWork *work, int slotIdx, int *hpState, int *statusAnim)
{
    if (work->slots[slotIdx].frameActor == 0 || !work->slots[slotIdx].flags.occupied || work->slots[slotIdx].flags.hidden) {
        *hpState = 0;
        *statusAnim = 8;
        return 0;
    }
    *hpState = BGWINFRM_GetScaleRank(work->slots[slotIdx].hp, work->slots[slotIdx].maxHp);
    *statusAnim = CLACT_GetActorAnimSeq((struct ClactActor *)work->slots[slotIdx].statusActor);
    if (*statusAnim == 0)
        *statusAnim = 8;
    return 1;
}

void BTLV_GAUGE_RequestStop(BtlvGaugeWork *work)
{
    work->flags.stopRequested = 1;
}

void BTLV_GAUGE_HideSlot(BtlvGaugeWork *work, int slotIdx)
{
    if (work->slots[slotIdx].frameActor != 0)
        work->slots[slotIdx].flags.hidden = 1;
}

/* Switches to the low HP music when a player gauge is red and back when none is. */
void BTLV_GAUGE_UpdateLowHpBgm(BtlvGaugeWork *work)
{
    int busy, found, i;
    if (work->flags.bgmChangePending) {
        if (GFL_USE_IsBgmFading() != 0) return;
        work->flags.bgmChangePending = 0;
        if (work->flags.lowHpBgmPlaying) {
            GFL_USE_PopBgm();
            if (!work->flags.bgmReplaced && BTLV_EFFECT_IsBgmSaved() != 0) {
                GFL_USE_CancelChangeAndPlayBgm(work->savedBgmNo, 0xffff);
                work->flags.bgmReplaced = 1;
            } else {
                BTLV_GAUGE_SetBgmPlayerParam(0);
            }
            GFL_USE_FadeInBgmFull(24);
        } else {
            BTLV_GAUGE_SetBgmPlayerParam(1);
            GFL_USE_PushBgm();
            GFL_USE_CancelChangeAndPlayBgm(BTLV_GAUGE_BGM_LOW_HP, 0xffff);
        }
        work->flags.lowHpBgmPlaying ^= 1;
        return;
    }
    busy = 0;
    found = 0;
    for (i = 0; i < 8; i++) {
        if (work->slots[i].flags.hpAnimating || work->slots[i].flags.expAnimating || work->slots[i].flags.levelUpPending) {
            busy = 1;
        } else if (work->slots[i].side == 0 && work->slots[i].flags.occupied && work->slots[i].layout != 4) {
            if (BGWINFRM_GetScaleRank(work->slots[i].hp, work->slots[i].maxHp) == 2) found = 1;
        }
    }
    if (!work->flags.lowHpBgmPlaying && work->savedBgmNo != GFL_USE_GetBgmNo()) return;
    if (busy != 0) return;
    if ((work->flags.lowHpBgmPlaying && found == 0) || (!work->flags.lowHpBgmPlaying && found == 1)) {
        work->flags.bgmChangePending = 1;
        GFL_USE_FadeOutBgm(8);
    }
}

/* Task: slides the actors of one slot sideways, eight pixels per frame. */
void BTLV_GAUGE_TaskSlideSlot(struct TcbTask *task, void *arg)
{
    BtlvGaugeSlot *slot = arg;
    int step;
    struct ClactVec2 pos;
    if (slot->side != 0) step = 8;
    else step = -8;
    CLACT_GetActorSurfacePos(slot->frameActor, &pos, 0);
    pos.x += (s16)step;
    CLACT_AddActorSurfacePos(slot->frameActor, &pos, 0);
    CLACT_GetActorSurfacePos(slot->hpBarActor, &pos, 0);
    pos.x += (s16)step;
    CLACT_AddActorSurfacePos(slot->hpBarActor, &pos, 0);
    CLACT_GetActorSurfacePos(slot->statusActor, &pos, 0);
    pos.x += (s16)step;
    CLACT_AddActorSurfacePos(slot->statusActor, &pos, 0);
    if (slot->side == 0) {
        CLACT_GetActorSurfacePos(slot->hpNumberActor, &pos, 0);
        pos.x += (s16)step;
        CLACT_AddActorSurfacePos(slot->hpNumberActor, &pos, 0);
    }
    if (slot->expBarActor != 0) {
        CLACT_GetActorSurfacePos(slot->expBarActor, &pos, 0);
        pos.x += (s16)step;
        CLACT_AddActorSurfacePos(slot->expBarActor, &pos, 0);
    }
    slot->flags.slideCount--;
    if (slot->flags.slideCount == 0) {
        TCB_DeleteTask(task);
        slot->slideTask = 0;
    }
}

/*
 * Task: flashes the palettes of the active slots of the owner three times.
 * lever: owner->slots[i] preserves the base/index register ordering;
 *   raw-offset casts and a named raw owner leave four bytes out.
 */
void BTLV_GAUGE_TaskFlashPalettes(struct TcbTask *task, void *arg)
{
    BtlvGaugeFlashTask *flash = arg;
    BtlvGaugeMaskTable masks = sGaugeFlashMasks;
    int i;
    PaletteFade *palAnm;
    switch (flash->state) {
    case 0:
        flash->mask = 0;
        for (i = 0; i < 8; i++) {
            if (flash->work->slots[i].flags.hpAnimating && flash->work->slots[i].hpDelta > 0)
                flash->mask |= masks.bits[i];
        }
        if (flash->mask) {
            palAnm = BTLV_EFFECT_GetPalanm();
            PALANM_RequestFade(palAnm, 4, flash->mask, 0, 0, 8, 16, BTLV_EFFECT_GetOwner());
            flash->state = 1;
        }
        break;
    case 1:
        if (!PALANM_GetFadeRequestBits(BTLV_EFFECT_GetPalanm())) {
            palAnm = BTLV_EFFECT_GetPalanm();
            PALANM_RequestFade(palAnm, 4, flash->mask, 0, 8, 0, 16, BTLV_EFFECT_GetOwner());
            flash->state = 2;
        }
        break;
    case 2:
        if (!PALANM_GetFadeRequestBits(BTLV_EFFECT_GetPalanm())) {
            flash->count++;
            if (flash->count == 3) {
                flash->count = 0;
                flash->state = 3;
            } else {
                flash->state = 0;
            }
        }
        break;
    case 3:
        for (i = 0; i < 8; i++) {
            if (flash->work->slots[i].flags.hpAnimating)
                break;
        }
        if (i == 8)
            flash->state = 0;
        break;
    }
}

/* Sets the BGM player parameter unless the player is locked. */
void BTLV_GAUGE_SetBgmPlayerParam(int bgmParam)
{
    if (GFL_NET_IsWifiGameKind() != 1)
        GFL_USE_SetBgmPaused(bgmParam);
}

/* Returns value * scale / maxValue, at least 1 when value is not 0. */
int BTLV_GAUGE_CalcBarPixels(int value, int maxValue, int scale)
{
    int result = (u32)(value * scale) / maxValue;
    if (result == 0 && value != 0)
        result = 1;
    return result;
}

/*
 * Shows or hides the number and bar actors of a slot. On layouts 2 and 3 only one
 * of the two shows, chosen by the alternate display flag.
 * Lever: the flag word at 0x440 is a bitfield struct (bit 4 read as
 * lsls #27 / lsrs #31); a plain u32 with `(f >> 4) & 1` gives lsrs/ands
 * and a different register assignment.
 */
void BTLV_GAUGE_SetSlotBarsVisible(BtlvGaugeWork *work, int slotIdx, int visible)
{
    if ((work->slots[slotIdx].layout == 2 || work->slots[slotIdx].layout == 3) && visible == 1 && (slotIdx & 1) == 0) {
        CLACT_SetActorDrawEnable((struct ClactActor *)work->slots[slotIdx].hpNumberActor, work->flags.altDisplay);
        CLACT_SetActorDrawEnable((struct ClactActor *)work->slots[slotIdx].hpBarActor, work->flags.altDisplay ? 0 : 1);
    } else {
        CLACT_SetActorDrawEnable((struct ClactActor *)work->slots[slotIdx].hpNumberActor, visible);
        CLACT_SetActorDrawEnable((struct ClactActor *)work->slots[slotIdx].hpBarActor, visible);
    }
}
