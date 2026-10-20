#ifndef GAME_OV010_SCRIPT_SYS_H
#define GAME_OV010_SCRIPT_SYS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of script_sys.c, prototypes copied from their definitions. */

struct ScriptSys;
struct ScriptEventWork;
typedef struct ScriptSys ScriptSys;
typedef struct ScriptEventWork ScriptEventWork;

#include "../types.h"
#include "../arm9/script_vm_types.h"

void *SCRIPT_SYS_CallScriptEvent(void *parentEvent, u16 scriptId, void *target, void *parentWork, u16 reserved);
void *SCRIPT_SYS_ChangeScriptEvent(void *event, u16 scriptId, void *target, int reserved);
int SCRIPT_SYS_HasVm(void *scriptWork, int index);
ScriptSys *SCRIPT_SYS_Create(u32 heapId);
void SCRIPT_SYS_Delete(ScriptSys *sys);
int SCRIPT_SYS_Main(ScriptSys *sys);
int SCRIPT_SYS_AddVm(ScriptSys *sys, ScriptVm *vm);
ScriptVm *SCRIPT_SYS_GetVm(ScriptSys *sys, int index);
void SCRIPT_SYS_ChangeNextEvent(void *event, void *nextEvent);
void SCRIPT_SYS_SetNextEvent(ScriptSys *sys, void *nextEvent);
void SCRIPT_SYS_CallEndCallback(ScriptSys *sys, void *event);
int SCRIPT_SYS_HasEndCallback(ScriptSys *sys);
u16 SCRIPT_SYS_GetZoneId(void *fieldSys);
int SCRIPT_SYS_EventMain(void *event, int *seq, ScriptEventWork *eventWork);
void SCRIPT_SYS_CallEvent(void *scriptWork, void *task);
void SCRIPT_SYS_SetNextEventFromWork(void *scriptWork, void *nextEvent);
int SCRIPT_SYS_AddScript(void *scriptWork, u16 zoneId, u16 scriptId);
ScriptSys *SCRIPT_SYS_GetFromWork(void *scriptWork);
void SCRIPT_SYS_ClearLocalWork(void *eventFlags);
void SCRIPT_SYS_RunInitScript(void *fieldSys, int reserved);
void SCRIPT_SYS_RunRecoverScript(void *fieldSys, int reserved);
void SCRIPT_SYS_RunScriptNow(void *fieldSys, void *scriptWork, u16 scriptId, int mode);
int SCRIPT_SYS_RunSpecialScript(void *fieldSys, int reserved, int key, int mode);
void SCRIPT_SYS_RunFieldInitScript(void *fieldSys, int reserved);
void SCRIPT_SYS_RunFieldRecoverScript(void *fieldSys, int reserved);
void SCRIPT_SYS_RunZoneChangeScript(void *fieldSys, int reserved);
void *SCRIPT_SYS_CreateSceneChangeEvent(void *fieldSys, int reserved);
u16 SCRIPT_SYS_FindSpecialScript(const u8 *table, int key);
u16 SCRIPT_SYS_FindSceneScript(const void *eventWork, const u8 *list, u32 key);
ScriptVm *SCRIPT_SYS_CreateVm(u16 heapId, void *scriptWork, u16 zoneId, u16 scriptId, int mode);
void SCRIPT_SYS_DeleteVm(ScriptVm *vm);
u16 SCRIPT_SYS_GetScriptFileId(unsigned zoneId, unsigned scriptId, u16 *outFileId, u16 *outTextBank, u16 *outTextMsgId);
u8 *SCRIPT_SYS_LoadScriptFile(int fileId, int heapId);
int SCRIPT_SYS_IsZoneScriptId(u16 scriptId);
int SCRIPT_SYS_IsChildScript(int mode);
void SCRIPT_SYS_ForceExitNet(void);
int SCRIPT_SYS_CheckCommandPermit(ScriptVm *vm, void *cmdWork, void *fieldSys, u32 cmdIndex);
void SCRIPT_SYS_SetCommandCheck(ScriptVm *vm);
/* END mkheaders: generated region */

#endif
