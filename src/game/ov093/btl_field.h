#ifndef GAME_OV093_BTL_FIELD_H
#define GAME_OV093_BTL_FIELD_H




/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of btl_field.c, prototypes copied from their definitions. */

struct BtlSide;
struct BtlPokeParam;
struct BtlServerFlow;

#include "../ov093/btl_field_types.h"
#include "../types.h"
#include "../ov093/btl_pokeparam_types.h"

void BTL_FIELD_ResetSlot(BtlFieldState *state, u32 slot);
void BTL_FIELD_ResetStatic(int value);
int BTL_FIELD_GetCountdownValue(void);
int BTL_FIELD_GetCountdownCount(void);
int BTL_FIELD_SetCountdown(int value, int count);
u32 BTL_FIELD_TickCountdown(void);
int BTL_FIELD_RegisterStaticSlot(u32 slot, union SickCont key);
int BTL_FIELD_RemoveStaticSlot(int arg);
int BTL_FIELD_AddStaticSlotHolder(int slot, int value);
void BTL_FIELD_RemoveHolderFromStaticSlots(u32 pokeId);
int BTL_FIELD_IsMoveSealedByStaticSlot(struct BtlSide *side, struct BtlPokeParam *pokeParam, u16 moveId);
void BTL_FIELD_TickStaticSlots(void (*onExpire)(int, struct BtlServerFlow *), struct BtlServerFlow *arg);
int BTL_FIELD_IsStaticSlotInUse(int arg);
BtlFieldState *BTL_FIELD_Create(u32 heapId);
void BTL_FIELD_Delete(void *state);
void BTL_FIELD_Init(BtlFieldState *state, u32 value);
u8 BTL_FIELD_GetCountdownByte(BtlFieldCountdown *countdown);
int BTL_FIELD_GetCountdownCountIfSet(BtlFieldCountdown *countdown);
BtlFieldCountdown *BTL_FIELD_StoreCountdown(BtlFieldCountdown *countdown, int value, int count);
void BTL_FIELD_ClearCountdown(BtlFieldCountdown *countdown);
u32 BTL_FIELD_StepCountdown(BtlFieldCountdown *countdown);
int BTL_FIELD_RegisterSlot(BtlFieldState *state, u32 slot, union SickCont key, int allocHandle);
int BTL_FIELD_RemoveSlot(BtlFieldState *state, u32 slot);
int BTL_FIELD_AddSlotHolder(BtlFieldState *state, u32 slot, u32 pokeId);
void BTL_FIELD_RemoveHolderFromSlots(BtlFieldState *state, u32 pokeId);
int BTL_FIELD_IsMoveSealedBySlot(BtlFieldState *state, struct BtlSide *side, struct BtlPokeParam *pokeParam, u16 moveId);
void BTL_FIELD_TickSlots(BtlFieldState *state, void (*onExpire)(int, struct BtlServerFlow *), struct BtlServerFlow *arg);
int BTL_FIELD_IsSlotInUse(BtlFieldState *state, int slot);
/* END mkheaders: generated region */

#endif
