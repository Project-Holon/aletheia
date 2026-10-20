#ifndef GAME_ARM9_DAYCARE_H
#define GAME_ARM9_DAYCARE_H

/* Public functions of daycare.c, prototypes copied from their definitions. */

struct DaycareSave;
struct PokeParam;
struct DaycareSlot;
struct SaveControl;

#include "../types.h"

void DAYCARE_SetEggReady(struct DaycareSave *daycare);
void DAYCARE_ClearEggReady(struct DaycareSave *daycare);
struct PokeParam *DAYCARE_GetSlotMon(struct DaycareSave *daycare, s32 slot);
void DAYCARE_SetSlotMon(struct DaycareSave *daycare, s32 slot, const struct PokeParam *mon);
void DAYCARE_ClearSlot(struct DaycareSave *daycare, s32 slot);
u32 DAYCARE_GetEggReady(struct DaycareSave *daycare);
u32 DAYCARE_IsSlotInUse(struct DaycareSave *daycare, u32 slot);
u32 DAYCARE_GetInUseCount(struct DaycareSave *daycare);
u32 DAYCARE_GetSlotSteps(struct DaycareSave *daycare, u32 slot);
void DAYCARE_SwapSlots(struct DaycareSave *daycare, s32 slotA, s32 slotB);
void DAYCARE_AddSteps(struct DaycareSlot *slots, u32 steps);
u32 DAYCARE_GetSize(void);
void DAYCARE_Init(struct DaycareSave *daycare);
struct DaycareSave *DAYCARE_GetFromSave(struct SaveControl *save);

#endif
