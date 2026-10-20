#ifndef GAME_TWL_MI_SHAREDWRAM_H
#define GAME_TWL_MI_SHAREDWRAM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of mi_sharedWram.c, prototypes copied from their definitions. */

#include "../types.h"

u32 MIi_GetWramBank_A(u32 bank);
u32 MIi_GetWramBank_B(u32 bank);
u32 MIi_GetWramBank_C(u32 bank);
void MIi_SetWramBankMaster_A(u32 bank, u32 master);
void MIi_SetWramBankMaster_B(u32 bank, u32 master);
void MIi_SetWramBankMaster_C(u32 bank, u32 master);
void MIi_SetWramBankMaster(u32 type, u32 bank, u32 master);
void MIi_SetWramBankEnable_A(u32 bank, u32 enable);
void MIi_SetWramBankEnable_B(u32 bank, u32 enable);
void MIi_SetWramBankEnable_C(u32 bank, u32 enable);
void MIi_SetWramBankEnable(u32 type, u32 bank, u32 enable);
u32 MI_GetWramBankMaster_A(u32 bank);
u32 MI_GetWramBankMaster_B(u32 bank);
u32 MI_GetWramBankMaster_C(u32 bank);
u32 MI_GetWramBankMaster(u32 type, u32 bank);
u32 MI_GetWramMapStart_A(void);
u32 MI_GetWramMapStart_B(void);
u32 MI_GetWramMapStart_C(void);
u32 MI_GetWramMapStart(u32 type);
u32 MIi_GetAddress_A(u32 bank);
void MIi_InitWramManager(void);
void MIi_CallbackForPxi(int tag, u32 data, BOOL err);
u32 MIi_DoAllocWram(u32 ch, int num, u32 proc);
u32 MI_AllocWramSlot(u32 ch, int start, int num, u32 proc);
u32 MIi_DoAllocWramSlot(u32 ch, int start, int num, u32 proc);
u32 MI_FreeWram(u32 ch, u32 proc);
u32 MIi_DoFreeWram(u32 ch, u32 proc);
u32 MI_FreeWramSlot(u32 ch, int start, int num, u32 proc);
u32 MIi_DoFreeWramSlot(u32 ch, int start, int num, u32 proc);
u32 MIi_DoSwitchWram(u32 ch, u32 proc, u32 newProc);
u32 MIi_DoSwitchWramSlot(u32 ch, int start, int num, u32 proc, u32 newProc);
u32 MIi_DoReserveWram(u32 ch, int num, u32 proc);
u32 MIi_DoReserveWramSlot(u32 ch, int start, int num, u32 proc);
u32 MI_CancelWram(u32 ch, u32 proc);
u32 MIi_DoCancelWram(u32 ch, u32 proc);
u32 MIi_DoCancelWramSlot(u32 ch, int start, int num, u32 proc);
u32 MIi_DoGetAllocatableWramSlot(u32 ch, u32 proc);
u32 MI_IsWramSlotUsed(u32 ch, u32 idx);
void MIi_SendToPxi(u32 err, u32 data);
void MIi_TakeApartData(u32 data, u32 *cmd, u32 *ch, u32 *sub, u32 *arg);
void MI_LockWramManager(u16 *id);
void MI_UnlockWramManager(u32 id);
u32 MIi_LockWramManagerDI(u16 *id);
void MIi_UnlockWramManagerRI(u32 id, u32 irq);
/* END mkheaders: generated region */

#endif
