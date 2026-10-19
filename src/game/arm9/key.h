#ifndef GAME_ARM9_KEY_H
#define GAME_ARM9_KEY_H

/* Public functions of key.c, prototypes copied from their definitions. */

#include "../arm9/touchpanel_shared_types.h"

KeyWork *KEY_Create(u32 heapId);
void KEY_MainSys(UiCtx *ui);
void KEY_Main(void);
void KEY_ApplyControlMode(KeyWork *key);
void KEY_SetRepeatSpeedSys(UiCtx *ui, int speed, int wait);
void KEY_SetRepeatSpeed(int speed, int wait);
void KEY_SetControlModeTableSys(UiCtx *ui, const KeyConvEntry *table);
void KEY_SetControlModeTable(const KeyConvEntry *table);
u32 KEY_GetTrgSys(UiCtx *ui);
u32 KEY_GetTrg(void);
u32 KEY_GetContSys(UiCtx *ui);
u32 KEY_GetCont(void);
u32 KEY_GetRepeatSys(UiCtx *ui);
u32 KEY_GetRepeat(void);
void KEY_GetRepeatSpeedSys(UiCtx *ui, u32 *speed, u32 *wait);
void KEY_GetRepeatSpeed(u32 *speed, u32 *wait);
void KEY_ClearFrameRateWork(UiCtx *ui);
void KEY_SetTrg(UiCtx *ui, int trg, int trg30);
void KEY_SetCont(UiCtx *ui, int cont, int cont30);
void KEY_SetRepeat(UiCtx *ui, int repeat, int repeat30);

#endif
