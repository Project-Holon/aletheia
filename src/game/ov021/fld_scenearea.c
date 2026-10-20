/*
 * file:     fld_scenearea.c
 * unit:     yes
 * function: FLD_SCENEAREA_Create, FLD_SCENEAREA_Delete, FLD_SCENEAREA_SetData, FLD_SCENEAREA_ClearData, FLD_SCENEAREA_Update, FLD_SCENEAREA_SetEnabled, FLD_SCENEAREA_GetCamera, FLD_SCENEAREA_GetFieldMap, FLD_SCENEAREA_HasCheck, FLD_SCENEAREA_HasAction, FLD_SCENEAREA_RunCheck, FLD_SCENEAREA_RunAction
 * address:  0x021AB5F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_effect.c at 0x021AB5F4: __FILE__ fld_scenearea.c on 0x021AB5F4 (create, first
 * function); 0x021AB768..0x021AB7C0 dispatch the callback tables only for 0x021AB660.
 *
 * symbols:
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   gFldSceneAreaFileName  0x021DDFC8  data  a4
 */
#include "fld_scenearea_types.h"

#include "../arm9/gfl_heap_wrap.h"
extern char gFldSceneAreaFileName[];

FldSceneArea *FLD_SCENEAREA_Create(int heapId, void *camera, void *fieldMap);
void FLD_SCENEAREA_Delete(FldSceneArea *sceneArea);
void FLD_SCENEAREA_SetData(FldSceneArea *sceneArea, FldSceneAreaRec *recs, u32 count, const FldSceneAreaCallbacks *callbacks);
void FLD_SCENEAREA_ClearData(FldSceneArea *sceneArea);
int FLD_SCENEAREA_Update(FldSceneArea *sceneArea, VecFx32 *pos);
void FLD_SCENEAREA_SetEnabled(FldSceneArea *sceneArea, u32 enabled);
void *FLD_SCENEAREA_GetCamera(FldSceneArea *sceneArea);
void *FLD_SCENEAREA_GetFieldMap(FldSceneArea *sceneArea);
int FLD_SCENEAREA_HasCheck(const FldSceneAreaCallbacks *callbacks, u32 checkId);
int FLD_SCENEAREA_HasAction(const FldSceneAreaCallbacks *callbacks, u32 actionId);
int FLD_SCENEAREA_RunCheck(const FldSceneAreaCallbacks *callbacks, int checkId, FldSceneArea *sceneArea, const FldSceneAreaRec *rec, VecFx32 *pos);
void FLD_SCENEAREA_RunAction(const FldSceneAreaCallbacks *callbacks, int actionId, FldSceneArea *sceneArea, const FldSceneAreaRec *rec, VecFx32 *pos);

/* 0x021DDFC8 is the "fld_scenearea.c" file-name string; 0x51 is its line. */
FldSceneArea *FLD_SCENEAREA_Create(int heapId, void *camera, void *fieldMap)
{
    FldSceneArea *sceneArea = GFL_HEAP_Alloc((u16)heapId, sizeof(FldSceneArea), 1, gFldSceneAreaFileName, 0x51);
    sceneArea->camera = camera;
    sceneArea->fieldMap = fieldMap;
    sceneArea->current = FLD_SCENEAREA_NO_AREA;
    sceneArea->enabled = 1;
    return sceneArea;
}

void FLD_SCENEAREA_Delete(FldSceneArea *sceneArea)
{
    FLD_SCENEAREA_ClearData(sceneArea);
    GFL_HEAP_Free(sceneArea);
}

/* Installs a record array (count entries) and the check and action tables. */
void FLD_SCENEAREA_SetData(FldSceneArea *sceneArea, FldSceneAreaRec *recs, u32 count, const FldSceneAreaCallbacks *callbacks)
{
    FLD_SCENEAREA_ClearData(sceneArea);
    sceneArea->recs = recs;
    sceneArea->callbacks = callbacks;
    sceneArea->count = count;
    sceneArea->current = FLD_SCENEAREA_NO_AREA;
}

/* Forgets the installed records. */
void FLD_SCENEAREA_ClearData(FldSceneArea *sceneArea)
{
    sceneArea->recs = 0;
    sceneArea->callbacks = 0;
    sceneArea->count = 0;
    sceneArea->current = FLD_SCENEAREA_NO_AREA;
}

/*
 * Per-frame update: finds the last record whose check accepts the position,
 * then runs the leave action of the old area and the enter action of the new
 * one, or the stay action while the area is unchanged. Returns the index of
 * the current area, or FLD_SCENEAREA_NO_AREA.
 *
 * The loop's id load is spelled as byte-base + i * sizeof + offset: with
 * recs[i].checkId, (recs + i)->checkId, a FldSceneAreaRec * local, a recs
 * local, or a cast through &recs[i], the records base and the
 * i * 0x48 product swap r3/r6 (7 bytes); int i and declaration order do
 * not move it.
 */
int FLD_SCENEAREA_Update(FldSceneArea *sceneArea, VecFx32 *pos)
{
    u32 i;
    int selected;

    if (sceneArea->enabled == 0)
        return FLD_SCENEAREA_NO_AREA;
    sceneArea->lastActionId = FLD_SCENEAREA_NO_ACTION;
    selected = FLD_SCENEAREA_NO_AREA;
    for (i = 0; i < sceneArea->count; i++) {
        if (FLD_SCENEAREA_RunCheck(sceneArea->callbacks, *(u16 *)((u8 *)sceneArea->recs + i * sizeof(FldSceneAreaRec) + FLD_SCENEAREA_REC_CHECK_ID_OFFSET), sceneArea, &sceneArea->recs[i], pos))
            selected = i;
    }
    if (selected != sceneArea->current) {
        if (sceneArea->current != FLD_SCENEAREA_NO_AREA) {
            FLD_SCENEAREA_RunAction(sceneArea->callbacks, sceneArea->recs[sceneArea->current].leaveActionId, sceneArea, &sceneArea->recs[sceneArea->current], pos);
            sceneArea->lastActionId = sceneArea->recs[sceneArea->current].leaveActionId;
        }
        if (selected != FLD_SCENEAREA_NO_AREA) {
            FLD_SCENEAREA_RunAction(sceneArea->callbacks, sceneArea->recs[selected].enterActionId, sceneArea, &sceneArea->recs[selected], pos);
            sceneArea->lastActionId = sceneArea->recs[selected].enterActionId;
        }
        sceneArea->current = selected;
    } else if (sceneArea->current != FLD_SCENEAREA_NO_AREA) {
        FLD_SCENEAREA_RunAction(sceneArea->callbacks, sceneArea->recs[sceneArea->current].stayActionId, sceneArea, &sceneArea->recs[sceneArea->current], pos);
        sceneArea->lastActionId = sceneArea->recs[sceneArea->current].stayActionId;
    }
    return sceneArea->current;
}

void FLD_SCENEAREA_SetEnabled(FldSceneArea *sceneArea, u32 enabled)
{
    sceneArea->enabled = enabled;
}

void *FLD_SCENEAREA_GetCamera(FldSceneArea *sceneArea)
{
    return sceneArea->camera;
}

void *FLD_SCENEAREA_GetFieldMap(FldSceneArea *sceneArea)
{
    return sceneArea->fieldMap;
}

/* 1 when the check table has an entry for the id. */
int FLD_SCENEAREA_HasCheck(const FldSceneAreaCallbacks *callbacks, u32 checkId)
{
    if (callbacks->checkCount > checkId) {
        if (callbacks->checks[checkId] != 0) {
            return 1;
        }
    }
    return 0;
}

/* 1 when the action table has an entry for the id. */
int FLD_SCENEAREA_HasAction(const FldSceneAreaCallbacks *callbacks, u32 actionId)
{
    if (callbacks->actionCount > actionId) {
        if (callbacks->actions[actionId] != 0) {
            return 1;
        }
    }
    return 0;
}

int FLD_SCENEAREA_RunCheck(const FldSceneAreaCallbacks *callbacks, int checkId, FldSceneArea *sceneArea, const FldSceneAreaRec *rec, VecFx32 *pos)
{
    if (FLD_SCENEAREA_HasCheck(callbacks, checkId)) {
        return callbacks->checks[checkId](sceneArea, rec, pos);
    }
    return 0;
}

void FLD_SCENEAREA_RunAction(const FldSceneAreaCallbacks *callbacks, int actionId, FldSceneArea *sceneArea, const FldSceneAreaRec *rec, VecFx32 *pos)
{
    if (FLD_SCENEAREA_HasAction(callbacks, actionId)) {
        callbacks->actions[actionId](sceneArea, rec, pos);
    }
}
