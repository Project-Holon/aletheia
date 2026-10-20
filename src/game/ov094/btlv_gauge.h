#ifndef GAME_OV094_BTLV_GAUGE_H
#define GAME_OV094_BTLV_GAUGE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of btlv_gauge.c, prototypes copied from their definitions. */

struct BtlMain;
struct BtlPokeParam;
struct ZukanSave;
struct ClactVec2;
struct TcbTask;

#include "../ov094/btlv_gauge_types.h"
#include "../types.h"

BtlvGaugeWork *BTLV_GAUGE_Create(void *font, u16 heapId);
void BTLV_GAUGE_Delete(BtlvGaugeWork *work);
void BTLV_GAUGE_FlashTaskMain(BtlvGaugeWork *work);
void BTLV_GAUGE_InitSlotFromBattlePoke(BtlvGaugeWork *work, struct BtlMain *battleMain, struct BtlPokeParam *battlePoke, int layout, int slotIdx);
void BTLV_GAUGE_InitSlotFromPartyPoke(BtlvGaugeWork *work, struct ZukanSave *zukanSave, void *partyPoke, int layout, int slotIdx);
void BTLV_GAUGE_LoadSlotResources(BtlvGaugeWork *work, int layout, int slotIdx);
void BTLV_GAUGE_ReleaseSlotResources(BtlvGaugeWork *work, int slotIdx);
void BTLV_GAUGE_UpdateSlot(BtlvGaugeWork *work, int layout, int slotIdx, void *pokeParam);
void BTLV_GAUGE_UpdateHpBarPixels(BtlvGaugeSlot *slot);
void BTLV_GAUGE_DeleteSlotTask(BtlvGaugeWork *work, int slotIdx);
void BTLV_GAUGE_PlaceSlot(BtlvGaugeWork *work, int slotIdx, struct ClactVec2 *offset);
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
void BTLV_GAUGE_UpdateHpAnim(BtlvGaugeWork *work, int slotIdx);
void BTLV_GAUGE_StartExpChange(BtlvGaugeSlot *slot, int gain);
void BTLV_GAUGE_UpdateExpAnim(BtlvGaugeWork *work, int slotIdx);
int BTLV_GAUGE_StepValue(int maxValue, int value, int delta, int *anim, u8 tileCount, int speed);
u8 BTLV_GAUGE_CalcTileFill(u32 maxValue, int value, int delta, int *anim, u8 *tileFill, u8 tileCount);
int BTLV_GAUGE_CalcPixelChange(int value, int delta, int maxValue, unsigned int tileCount);
void BTLV_GAUGE_DrawNickname(BtlvGaugeWork *work, BtlvGaugeSlot *slot, void *pokeParam);
void BTLV_GAUGE_DrawGender(BtlvGaugeWork *work, BtlvGaugeSlot *slot);
void BTLV_GAUGE_DrawBar(BtlvGaugeWork *work, int slotIdx, int kind);
void BTLV_GAUGE_DrawHpNumbers(const BtlvGaugeWork *work, BtlvGaugeSlot *slot, int hp);
void BTLV_GAUGE_DrawLevel(BtlvGaugeWork *work, BtlvGaugeSlot *slot);
void BTLV_GAUGE_DrawCaughtIcon(BtlvGaugeWork *work, BtlvGaugeSlot *slot);
void BTLV_GAUGE_DrawHpLoss(BtlvGaugeWork *work, BtlvGaugeSlot *slot, int barPixels);
void BTLV_GAUGE_UpdateLevelUp(BtlvGaugeWork *work, int slotIdx);
void BTLV_GAUGE_BobSlot(BtlvGaugeWork *work, int slotIdx);
void BTLV_GAUGE_SetStatusIcon(BtlvGaugeWork *work, int status, int slotIdx);
void BTLV_GAUGE_SelectSlot(BtlvGaugeWork *work, int selectedSlot);
unsigned int BTLV_GAUGE_IsLowHpBgmPlaying(BtlvGaugeWork *work);
void BTLV_GAUGE_SetLowHpBgmPlaying(BtlvGaugeWork *work, int playing);
void BTLV_GAUGE_SetSavedBgmNo(BtlvGaugeWork *work, int bgmNo);
void BTLV_GAUGE_SetBgmReplaced(BtlvGaugeWork *work, int replaced);
void BTLV_GAUGE_SetLowHpBgmSuppressed(BtlvGaugeWork *work, int suppressed);
int BTLV_GAUGE_GetSlotHealthInfo(BtlvGaugeWork *work, int slotIdx, int *hpState, int *statusAnim);
void BTLV_GAUGE_RequestStop(BtlvGaugeWork *work);
void BTLV_GAUGE_HideSlot(BtlvGaugeWork *work, int slotIdx);
void BTLV_GAUGE_UpdateLowHpBgm(BtlvGaugeWork *work);
void BTLV_GAUGE_TaskSlideSlot(struct TcbTask *task, void *arg);
void BTLV_GAUGE_TaskFlashPalettes(struct TcbTask *task, void *arg);
void BTLV_GAUGE_SetBgmPlayerParam(int bgmParam);
int BTLV_GAUGE_CalcBarPixels(int value, int maxValue, int scale);
void BTLV_GAUGE_SetSlotBarsVisible(BtlvGaugeWork *work, int slotIdx, int visible);
/* END mkheaders: generated region */

#endif
