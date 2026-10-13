/*
 * file:     fld_scenearea.c
 * unit:     yes
 * function: func_021AB5F4, func_021AB624, func_021AB634, func_021AB650, func_021AB660, func_021AB75C, func_021AB760, func_021AB764, func_021AB768, func_021AB780, func_021AB798, func_021AB7C0
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
 *   func_020307B0  0x020307B0  arm
 *   func_02030734  0x02030734  arm
 *   d_021DDFC8  0x021DDFC8  data  a4
 */
#include "fld_scenearea_types.h"

extern u32 func_020307B0(void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 line);
extern char d_021DDFC8[];

FldSceneArea *func_021AB5F4(int heapId, void *camera, void *fieldMap);
void func_021AB624(FldSceneArea *sceneArea);
void func_021AB634(FldSceneArea *sceneArea, FldSceneAreaRec *recs, u32 count, const FldSceneAreaCallbacks *callbacks);
void func_021AB650(FldSceneArea *sceneArea);
int func_021AB660(FldSceneArea *sceneArea, VecFx32 *pos);
void func_021AB75C(FldSceneArea *sceneArea, u32 enabled);
void *func_021AB760(FldSceneArea *sceneArea);
void *func_021AB764(FldSceneArea *sceneArea);
int func_021AB768(const FldSceneAreaCallbacks *callbacks, u32 checkId);
int func_021AB780(const FldSceneAreaCallbacks *callbacks, u32 actionId);
int func_021AB798(const FldSceneAreaCallbacks *callbacks, int checkId, FldSceneArea *sceneArea, const FldSceneAreaRec *rec, VecFx32 *pos);
void func_021AB7C0(const FldSceneAreaCallbacks *callbacks, int actionId, FldSceneArea *sceneArea, const FldSceneAreaRec *rec, VecFx32 *pos);

/* 0x021DDFC8 is the "fld_scenearea.c" file-name string; 0x51 is its line. */
FldSceneArea *func_021AB5F4(int heapId, void *camera, void *fieldMap)
{
    FldSceneArea *sceneArea = func_02030734((u16)heapId, sizeof(FldSceneArea), 1, d_021DDFC8, 0x51);
    sceneArea->camera = camera;
    sceneArea->fieldMap = fieldMap;
    sceneArea->current = FLD_SCENEAREA_NO_AREA;
    sceneArea->enabled = 1;
    return sceneArea;
}

void func_021AB624(FldSceneArea *sceneArea)
{
    func_021AB650(sceneArea);
    func_020307B0(sceneArea);
}

/* Installs a record array (count entries) and the check and action tables. */
void func_021AB634(FldSceneArea *sceneArea, FldSceneAreaRec *recs, u32 count, const FldSceneAreaCallbacks *callbacks)
{
    func_021AB650(sceneArea);
    sceneArea->recs = recs;
    sceneArea->callbacks = callbacks;
    sceneArea->count = count;
    sceneArea->current = FLD_SCENEAREA_NO_AREA;
}

/* Forgets the installed records. */
void func_021AB650(FldSceneArea *sceneArea)
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
int func_021AB660(FldSceneArea *sceneArea, VecFx32 *pos)
{
    u32 i;
    int selected;

    if (sceneArea->enabled == 0)
        return FLD_SCENEAREA_NO_AREA;
    sceneArea->lastActionId = FLD_SCENEAREA_NO_ACTION;
    selected = FLD_SCENEAREA_NO_AREA;
    for (i = 0; i < sceneArea->count; i++) {
        if (func_021AB798(sceneArea->callbacks, *(u16 *)((u8 *)sceneArea->recs + i * sizeof(FldSceneAreaRec) + FLD_SCENEAREA_REC_CHECK_ID_OFFSET), sceneArea, &sceneArea->recs[i], pos))
            selected = i;
    }
    if (selected != sceneArea->current) {
        if (sceneArea->current != FLD_SCENEAREA_NO_AREA) {
            func_021AB7C0(sceneArea->callbacks, sceneArea->recs[sceneArea->current].leaveActionId, sceneArea, &sceneArea->recs[sceneArea->current], pos);
            sceneArea->lastActionId = sceneArea->recs[sceneArea->current].leaveActionId;
        }
        if (selected != FLD_SCENEAREA_NO_AREA) {
            func_021AB7C0(sceneArea->callbacks, sceneArea->recs[selected].enterActionId, sceneArea, &sceneArea->recs[selected], pos);
            sceneArea->lastActionId = sceneArea->recs[selected].enterActionId;
        }
        sceneArea->current = selected;
    } else if (sceneArea->current != FLD_SCENEAREA_NO_AREA) {
        func_021AB7C0(sceneArea->callbacks, sceneArea->recs[sceneArea->current].stayActionId, sceneArea, &sceneArea->recs[sceneArea->current], pos);
        sceneArea->lastActionId = sceneArea->recs[sceneArea->current].stayActionId;
    }
    return sceneArea->current;
}

void func_021AB75C(FldSceneArea *sceneArea, u32 enabled)
{
    sceneArea->enabled = enabled;
}

void *func_021AB760(FldSceneArea *sceneArea)
{
    return sceneArea->camera;
}

void *func_021AB764(FldSceneArea *sceneArea)
{
    return sceneArea->fieldMap;
}

/* 1 when the check table has an entry for the id. */
int func_021AB768(const FldSceneAreaCallbacks *callbacks, u32 checkId)
{
    if (callbacks->checkCount > checkId) {
        if (callbacks->checks[checkId] != 0) {
            return 1;
        }
    }
    return 0;
}

/* 1 when the action table has an entry for the id. */
int func_021AB780(const FldSceneAreaCallbacks *callbacks, u32 actionId)
{
    if (callbacks->actionCount > actionId) {
        if (callbacks->actions[actionId] != 0) {
            return 1;
        }
    }
    return 0;
}

int func_021AB798(const FldSceneAreaCallbacks *callbacks, int checkId, FldSceneArea *sceneArea, const FldSceneAreaRec *rec, VecFx32 *pos)
{
    if (func_021AB768(callbacks, checkId)) {
        return callbacks->checks[checkId](sceneArea, rec, pos);
    }
    return 0;
}

void func_021AB7C0(const FldSceneAreaCallbacks *callbacks, int actionId, FldSceneArea *sceneArea, const FldSceneAreaRec *rec, VecFx32 *pos)
{
    if (func_021AB780(callbacks, actionId)) {
        callbacks->actions[actionId](sceneArea, rec, pos);
    }
}
