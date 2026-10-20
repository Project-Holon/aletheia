#ifndef GAME_ARM9_VM_H
#define GAME_ARM9_VM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of vm.c, prototypes copied from their definitions. */

#include "../arm9/script_vm_types.h"
#include "../types.h"

void VM_Reset(ScriptVm *vm);
ScriptVm *VM_Create(u32 heapId, const ScriptVmParams *params);
void VM_Delete(ScriptVm *vm);
void VM_Init(ScriptVm *vm, void *user);
void VM_Start(ScriptVm *vm, u8 *pc);
ScriptVm *VM_End(ScriptVm *vm);
int VM_Control(ScriptVm *vm);
void *VM_GetContext(ScriptVm *vm);
void VM_SetHook(ScriptVm *vm, ScriptHookFn hook, void *arg);
u16 VM_ReadU16(ScriptVm *vm);
u32 VM_GetU32(ScriptVm *vm);
void VM_PushStack(ScriptVm *vm, u32 value);
u32 VM_PopStack(ScriptVm *vm);
void VM_Jump(ScriptVm *vm, u8 *pc);
void VM_Call(ScriptVm *vm, u8 *pc);
u8 *VM_Return(ScriptVm *vm);
void VM_SetWait(ScriptVm *vm, ScriptWaitFn wait);
/* END mkheaders: generated region */

#endif
