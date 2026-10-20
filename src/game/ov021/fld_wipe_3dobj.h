#ifndef GAME_OV021_FLD_WIPE_3DOBJ_H
#define GAME_OV021_FLD_WIPE_3DOBJ_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fld_wipe_3dobj.c, prototypes copied from their definitions. */

struct ScrCmdWork;
struct WipeMapChangeWork;
typedef struct ScrCmdWork ScrCmdWork;
typedef struct WipeMapChangeWork WipeMapChangeWork;

#include "../ov021/field_flash_shared_types.h"
#include "../types.h"
#include "../arm9/script_vm_types.h"
#include "../ov020/event_mapchange_types.h"
#include "../ov020/event_mapchange_types.h"

FldWipe3dObj *FLD_WIPE_3DOBJ_Create(u32 heapId);
int FLD_WIPE_3DOBJ_Delete(FldWipe3dObj *obj);
void FLD_WIPE_3DOBJ_Draw(FldWipe3dObj *obj, int size, int alpha);
int SCRCMD_StartFld3dCi(ScriptVm *vm, ScrCmdWork *work);
int SCRCMD_StartFld3dCiByVar(ScriptVm *vm, ScrCmdWork *work);
int SCRCMD_RunFld3dCiMain(ScriptVm *vm, ScrCmdWork *work);
int SCRCMD_StartFld3dCiByTable(ScriptVm *vm, ScrCmdWork *work);
GameEvent *FLD_WIPE_3DOBJ_CreateMapChangeEvent(GameSystem *gameSystem, int unused, int zoneId);
int FLD_WIPE_3DOBJ_MapChangeEventMain(GameEvent *event, int *seq, WipeMapChangeWork *work);
int FLD_WIPE_3DOBJ_FadeOutEventMain(GameEvent *event, int *seq);
/* END mkheaders: generated region */

#endif
