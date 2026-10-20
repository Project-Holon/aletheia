/*
 * file:     iss_3ds_sys.c
 * unit:     yes
 * function: ISS_3DS_SYS_Create, ISS_3DS_SYS_Delete, ISS_3DS_SYS_Update, ISS_3DS_SYS_Enter, ISS_3DS_SYS_Leave, ISS_3DS_SYS_OnZoneChange, ISS_3DS_SYS_SetVolume, ISS_3DS_SYS_StartSource, ISS_3DS_SYS_IsSourceActive, ISS_3DS_SYS_SetSourcePos, ISS_3DS_SYS_SetCamera, ISS_3DS_SYS_ClearTable, ISS_3DS_SYS_LoadTable, ISS_3DS_SYS_FreeTable, ISS_3DS_SYS_SetTableIndex, ISS_3DS_SYS_FindTableIndex, ISS_3DS_SYS_ResetSources, ISS_3DS_SYS_StartSourceImpl, ISS_3DS_SYS_SetSourcePosImpl, ISS_3DS_SYS_SetCameraImpl, ISS_3DS_SYS_EnterImpl, ISS_3DS_SYS_LeaveImpl, ISS_3DS_SYS_UpdateImpl, ISS_3DS_SYS_OnZoneChangeImpl, ISS_3DS_SYS_SilenceActiveTracks, ISS_3DS_SYS_StepSourceVolume, ISS_3DS_SYS_StepSourcePan, ISS_3DS_SYS_CalcSourceVolume, ISS_3DS_SYS_RampVolumeUp, ISS_3DS_SYS_RampVolumeDown, ISS_3DS_SYS_ApplySourceVolume, ISS_3DS_SYS_CalcSourcePan, ISS_3DS_SYS_RampPanDown, ISS_3DS_SYS_RampPanUp, ISS_3DS_SYS_ApplySourcePan, ISS_3DS_SYS_StepMasterVolume, ISS_3DS_SYS_ScaleVolume
 * address:  0x0202B894
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from iss_3ds_sys.c by tools/splitfile.py.
 *
 * symbols:
 *   ISS_3DS_SYS_FileName  0x020A7738  data
 *   ISS_3DS_SYS_OnZoneChangeImpl  0x0202BB40  thumb
 *   ISS_3DS_SYS_SilenceActiveTracks  0x0202BB48  thumb
 *   GFL_USE_GetBgmNo  0x02005C44  thumb
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   ARC_TOOL_ReadHandleMember  0x0204932C  arm
 *   ARC_TOOL_GetHandleFileCount  0x0204961C  arm
 *   ISS_3DS_SYS_UpdateImpl  0x0202BAF4  thumb
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   GFL_USE_SetBgmTrackParams    0x02005EE0  thumb
 *   _fdiv                        0x0209CE10  arm
 *   _ffix                        0x0209C494  arm
 *   _fflt                        0x0209BDBC  arm
 *   _fmul                        0x0209C77C  arm
 *   _u32_div_f                   0x0209C2B0  arm
 */
#include "iss_sys_shared_types.h"

#include "gfl_heap_wrap.h"


#include "gfl_use.h"

Iss3dsSys;

extern void ISS_3DS_SYS_UpdateImpl(Iss3dsSys *sys);

extern void ISS_3DS_SYS_OnZoneChangeImpl(Iss3dsSys *sys);

#include "arc_tool.h"

struct ArcHandle;



extern void ISS_3DS_SYS_SilenceActiveTracks(Iss3dsSys *sys);

Iss3dsSys *ISS_3DS_SYS_Create(u32 heapId);

void ISS_3DS_SYS_Delete(Iss3dsSys *sys);

void ISS_3DS_SYS_Update(Iss3dsSys *sys);

void ISS_3DS_SYS_Enter(Iss3dsSys *sys);

void ISS_3DS_SYS_Leave(Iss3dsSys *sys);

void ISS_3DS_SYS_OnZoneChange(Iss3dsSys *sys);

void ISS_3DS_SYS_SetVolume(Iss3dsSys *sys, u32 volume);

void ISS_3DS_SYS_StartSource(Iss3dsSys *sys, int slot, int radius, int amp);

int ISS_3DS_SYS_IsSourceActive(Iss3dsSys *sys, int slot);

void ISS_3DS_SYS_SetSourcePos(Iss3dsSys *sys, int slot, const VecFx32 *pos);

void ISS_3DS_SYS_SetCamera(Iss3dsSys *sys, const int *cameraPos, const int *cameraTarget);

void ISS_3DS_SYS_ClearTable(Iss3dsSys *sys);

void ISS_3DS_SYS_LoadTable(Iss3dsSys *sys);

void ISS_3DS_SYS_FreeTable(Iss3dsSys *sys);

Iss3dsSys *ISS_3DS_SYS_SetTableIndex(Iss3dsSys *sys, u32 index);

u8 ISS_3DS_SYS_FindTableIndex(const Iss3dsSys *sys, u32 bgmId);

void ISS_3DS_SYS_ResetSources(Iss3dsSys *sys);

void ISS_3DS_SYS_StartSourceImpl(Iss3dsSys *sys, int slot, int radius, int amp);

void ISS_3DS_SYS_SetSourcePosImpl(Iss3dsSys *sys, int slot, const VecFx32 *pos);

void ISS_3DS_SYS_SetCameraImpl(Iss3dsSys *sys, const int *cameraPos, const int *cameraTarget);

void ISS_3DS_SYS_EnterImpl(Iss3dsSys *sys);

void ISS_3DS_SYS_LeaveImpl(Iss3dsSys *sys);

extern const char ISS_3DS_SYS_FileName[];

static inline void ISS_3DS_SYS_SetVec3(VecFx32 *dst, int x, int y, int z)
{
    dst->x = x;
    dst->y = y;
    dst->z = z;
}

/* Allocates and clears the 3D sound subsystem, then loads its BGM table. */
Iss3dsSys *ISS_3DS_SYS_Create(u32 heapId)
{
    Iss3dsSys *sys = GFL_HEAP_Alloc(heapId, sizeof(Iss3dsSys), 0, ISS_3DS_SYS_FileName, 0xa3);

    sys->heapId = (u16)heapId;
    sys->entered = 0;
    sys->targetVolume = 0x7f;
    sys->volume = 0x7f;
    sys->volumeStep = 4;
    sys->cameraPos.x = 0;
    sys->cameraPos.y = 0;
    sys->cameraPos.z = 0;
    sys->cameraTarget.x = 0;
    sys->cameraTarget.y = 0;
    sys->cameraTarget.z = 0;

    ISS_3DS_SYS_ResetSources(sys);
    ISS_3DS_SYS_ClearTable(sys);
    ISS_3DS_SYS_LoadTable(sys);
    return sys;
}

/* Frees the BGM table, then the object. */
void ISS_3DS_SYS_Delete(Iss3dsSys *sys)
{
    ISS_3DS_SYS_FreeTable(sys);
    GFL_HEAP_Free(sys);
}

/* The four thunks below are linker veneers into the 3D sound code:
 * update, enter, leave and zone change. */
void ISS_3DS_SYS_Update(Iss3dsSys *sys)
{
    ISS_3DS_SYS_UpdateImpl(sys);
}

void ISS_3DS_SYS_Enter(Iss3dsSys *sys)
{
    ISS_3DS_SYS_EnterImpl(sys);
}

void ISS_3DS_SYS_Leave(Iss3dsSys *sys)
{
    ISS_3DS_SYS_LeaveImpl(sys);
}

void ISS_3DS_SYS_OnZoneChange(Iss3dsSys *sys)
{
    ISS_3DS_SYS_OnZoneChangeImpl(sys);
}

/* Stores the volume, clamped to 0x7f. */
void ISS_3DS_SYS_SetVolume(Iss3dsSys *sys, u32 volume)
{
    if (volume > 0x7f) {
        volume = 0x7f;
    }
    sys->targetVolume = (u8)volume;
}

/* Starts a sound source in a free slot. */
void ISS_3DS_SYS_StartSource(Iss3dsSys *sys, int slot, int radius, int amp)
{
    ISS_3DS_SYS_StartSourceImpl(sys, slot, radius, amp);
}

/* Returns the active flag of a slot. */
int ISS_3DS_SYS_IsSourceActive(Iss3dsSys *sys, int slot)
{
    return sys->sources[slot].active;
}

void ISS_3DS_SYS_SetSourcePos(Iss3dsSys *sys, int slot, const VecFx32 *pos)
{
    ISS_3DS_SYS_SetSourcePosImpl(sys, slot, pos);
}

void ISS_3DS_SYS_SetCamera(Iss3dsSys *sys, const int *cameraPos, const int *cameraTarget)
{
    ISS_3DS_SYS_SetCameraImpl(sys, cameraPos, cameraTarget);
}

/* Empties the BGM table. */
void ISS_3DS_SYS_ClearTable(Iss3dsSys *sys)
{
    sys->table = 0;
    sys->tableCount = 0;
    sys->tableIndex = 0xff;
}

/* Loads the BGM table from archive 0xb9 into a heap block, one 8-byte entry
 * per archive member. */
void ISS_3DS_SYS_LoadTable(Iss3dsSys *sys)
{
    u32 heapId = sys->heapId;
    void *arc = ARC_TOOL_CreateHandle(0xb9, (u16)((heapId & 0x7fff) | 0x8000));
    u8 count = (u8)ARC_TOOL_GetHandleFileCount(arc);
    u32 i;

    sys->tableCount = count;
    sys->table = GFL_HEAP_Alloc(heapId, (u32)(count << 3), 0, ISS_3DS_SYS_FileName, 0x178);

    for (i = 0; i < (u32)count; i++) {
        ARC_TOOL_ReadHandleMember(arc, i, sys->table + i);
    }
    ARC_TOOL_DeleteHandle(arc);
}

/* Frees the BGM table and empties it. */
void ISS_3DS_SYS_FreeTable(Iss3dsSys *sys)
{
    GFL_HEAP_Free(sys->table);
    ISS_3DS_SYS_ClearTable(sys);
}

/* Selects a table entry; leaves the table index alone when it is unchanged. */
Iss3dsSys *ISS_3DS_SYS_SetTableIndex(Iss3dsSys *sys, u32 index)
{
    if (sys->tableIndex != index) {
        sys->tableIndex = (u8)index;
    } else {
        return sys;
    }
    return sys;
}

/* Finds the table entry for a BGM; 0xff when there is none. */
u8 ISS_3DS_SYS_FindTableIndex(const Iss3dsSys *sys, u32 bgmId)
{
    const Iss3dsTableEntry *table = sys->table;
    u8 count;
    u8 i;

    if (table == 0) {
        return 0xff;
    }

    count = sys->tableCount;
    for (i = 0; i < count; i++) {
        if (table[i].bgmId == bgmId) {
            return i;
        }
    }

    return 0xff;
}

/* Resets the slots (inactive, full amplitude, one track-mask bit each) and the
 * two level arrays.  The loop keeps its zero-trip guard because the counter is
 * an enum, and the level stores write 0 rather than the counter. */
void ISS_3DS_SYS_ResetSources(Iss3dsSys *sys)
{
    Iss3dsSourceIndex i;

    for (i = 0; i < ISS_3DS_SOURCE_MAX; i++) {
        sys->sources[i].active = 0;
        sys->sources[i].amplitude = 0x7f;
        sys->sources[i].trackMask = 1 << i;
        sys->volumeLevel[i] = 0;
        sys->panLevel[i] = 0;
    }
}

void ISS_3DS_SYS_StartSourceImpl(Iss3dsSys *sys, int slot, int radius, int amp)
{
    Iss3dsSource *s = &sys->sources[slot];

    if (s->active != 1) {
        s->active = 1;
        s->radius = radius;
        s->amplitude = amp;
    }
}

void ISS_3DS_SYS_SetSourcePosImpl(Iss3dsSys *sys, int slot, const VecFx32 *pos)
{
    Iss3dsSource *s = &sys->sources[slot];

    if (s->active != 0) {
        ISS_3DS_SYS_SetVec3(&s->pos, pos->x, pos->y, pos->z);
    }
}

void ISS_3DS_SYS_SetCameraImpl(Iss3dsSys *sys, const int *cameraPos, const int *cameraTarget)
{
    ISS_3DS_SYS_SetVec3(&sys->cameraPos, cameraPos[0], cameraPos[1], cameraPos[2]);
    ISS_3DS_SYS_SetVec3(&sys->cameraTarget, cameraTarget[0], cameraTarget[1], cameraTarget[2]);
}

/* Enter: once per entry, pick the table entry for the BGM now playing. */
void ISS_3DS_SYS_EnterImpl(Iss3dsSys *sys)
{
    if (sys->entered != 0) {
        return;
    }
    sys->entered = 1;
    ISS_3DS_SYS_SetTableIndex(sys, ISS_3DS_SYS_FindTableIndex(sys, GFL_USE_GetBgmNo()));
    ISS_3DS_SYS_SilenceActiveTracks(sys);
}

/* Leave: clears the entered flag (the test is redundant but original). */
void ISS_3DS_SYS_LeaveImpl(Iss3dsSys *sys)
{
    if (sys->entered != 0) {
        sys->entered = 0;
    }
}

/* Per-source volume and pan ramps (moved here from iss_zone_sys.c). */

#include "fx_vec.h"


#include "fx_cp.h"






void ISS_3DS_SYS_UpdateImpl(Iss3dsSys *sys);

void ISS_3DS_SYS_OnZoneChangeImpl(Iss3dsSys *sys);

void ISS_3DS_SYS_SilenceActiveTracks(Iss3dsSys *sys);

void ISS_3DS_SYS_StepSourceVolume(Iss3dsSys *sys, int sourceIndex);

void ISS_3DS_SYS_StepSourcePan(Iss3dsSys *sys, int sourceIndex);

s32 ISS_3DS_SYS_CalcSourceVolume(Iss3dsSource *source, const struct VecFx32 *cameraPos);

void ISS_3DS_SYS_RampVolumeUp(Iss3dsSys *sys, u32 sourceIndex, s32 cap);

void ISS_3DS_SYS_RampVolumeDown(Iss3dsSys *sys, u32 sourceIndex, s32 cap);

void ISS_3DS_SYS_ApplySourceVolume(Iss3dsSys *sys, u32 sourceIndex);

s32 ISS_3DS_SYS_CalcSourcePan(const Iss3dsSource *source, const struct VecFx32 *cameraPos, const struct VecFx32 *cameraTarget);

void ISS_3DS_SYS_RampPanDown(Iss3dsSys *sys, u32 sourceIndex, s32 cap);

void ISS_3DS_SYS_RampPanUp(Iss3dsSys *sys, u32 sourceIndex, s32 cap);

void ISS_3DS_SYS_ApplySourcePan(Iss3dsSys *sys, u32 sourceIndex);

void ISS_3DS_SYS_StepMasterVolume(Iss3dsSys *sys);

u32 ISS_3DS_SYS_ScaleVolume(Iss3dsSys *sys, u32 level, void *unused);

/*
 * iss_3ds_sys.c per-frame step: returns when +0x04 is zero, then runs the
 * four per-entry steps over every live entry of the 0x10-slot table.
 * The listing extent (84) runs into the 8-byte thunk at 0x0202BB40; the
 * function itself is 74 bytes.
 *
 * The kept `cmp r4, #0x10; bge` zero-trip guard is an enum-typed
 * counter (docs/idioms/an-enum-type-keeps-values-out-of-constant-folding.md),
 * the same lever as its sibling ISS_3DS_SYS_ResetSources.
 */
void ISS_3DS_SYS_UpdateImpl(Iss3dsSys *sys)
{
    Iss3dsSourceIndex i;

    if (sys->entered == 0) {
        return;
    }
    ISS_3DS_SYS_StepMasterVolume(sys);
    for (i = 0; i < 0x10; i++) {
        if (sys->sources[i].active != 0) {
            ISS_3DS_SYS_StepSourceVolume(sys, i);
            ISS_3DS_SYS_StepSourcePan(sys, i);
            ISS_3DS_SYS_ApplySourceVolume(sys, i);
            ISS_3DS_SYS_ApplySourcePan(sys, i);
        }
    }
}

/*
 * iss_3ds_sys.c: a bare tail-call thunk to ISS_3DS_SYS_ResetSources (ldr r3, [pc, #0];
 * bx r3; .word 0x0202BA25), the target of the thunk at 0x0202B90C.
 */
void ISS_3DS_SYS_OnZoneChangeImpl(Iss3dsSys *sys)
{
    ISS_3DS_SYS_ResetSources((Iss3dsSys *)sys);
}

/* Silences the tracks of the active record, when there is one. */
void ISS_3DS_SYS_SilenceActiveTracks(Iss3dsSys *sys)
{
    u8 record = sys->tableIndex;

    if (record != 0xff) {
        GFL_USE_SetBgmTrackVolume(sys->table[record].mutedMask, 0);
    }
}

/*
 * iss_3ds_sys.c, the per-slot twins that ISS_3DS_SYS_UpdateImpl steps: for a live
 * source (0x1c-byte stride at +0x24), compute the target level and move the
 * source's s32 level (volumeLevel or panLevel, indexed by sourceIndex) toward
 * it through the clamp helpers ISS_3DS_SYS_RampVolumeUp / ISS_3DS_SYS_RampPanDown / ISS_3DS_SYS_RampPanUp,
 * which take the computed level as their third argument.
 *
 * Callee arity is read from the callee bodies: both clamp helpers compare
 * against r2, so they are declared (sys, index, cap).
 */
void ISS_3DS_SYS_StepSourceVolume(Iss3dsSys *sys, int sourceIndex)
{
    Iss3dsSource *sources = sys->sources;
    s32 target;
    s32 level;

    if (sources[sourceIndex].active == 0) {
        return;
    }
    target = ISS_3DS_SYS_CalcSourceVolume(&sources[sourceIndex], &sys->cameraPos);
    level  = sys->volumeLevel[sourceIndex];
    if (level < target) {
        ISS_3DS_SYS_RampVolumeUp(sys, sourceIndex, target);
        return;
    }
    if (target < level) {
        ISS_3DS_SYS_RampVolumeDown(sys, sourceIndex, target);
    }
}

void ISS_3DS_SYS_StepSourcePan(Iss3dsSys *sys, int sourceIndex)
{
    Iss3dsSource *sources = sys->sources;
    s32 target;
    s32 level;

    if (sources[sourceIndex].active == 0) {
        return;
    }
    target = ISS_3DS_SYS_CalcSourcePan(&sources[sourceIndex], &sys->cameraPos, &sys->cameraTarget);
    level  = sys->panLevel[sourceIndex];
    if (target < level) {
        ISS_3DS_SYS_RampPanDown(sys, sourceIndex, target);
        return;
    }
    if (level < target) {
        ISS_3DS_SYS_RampPanUp(sys, sourceIndex, target);
    }
}

/*
 * Distance falloff: the source position is taken relative to the listener
 * point, and the remaining headroom (the radius less that distance) is
 * divided by the radius through the hardware divider FX_Div. The
 * quotient is an FX32, so it is scaled back by 4096.0f in float before
 * multiplying the amplitude and truncating; that is the pool word 0x45800000
 * at 0x0202BC44. Outside the radius the answer is 0.
 *
 * The compare is signed (bge), so the radius field is s32 and the
 * `mag >= radius` arm is the one written first.
 */
s32 ISS_3DS_SYS_CalcSourceVolume(Iss3dsSource *source, const struct VecFx32 *cameraPos)
{
    struct VecFx32 delta;
    s32 distance;
    float ratio;

    VEC_Subtract(&source->pos, cameraPos, &delta);
    distance = VEC_Mag(&delta);
    if (source->radius < distance) {
        return 0;
    }
    ratio = (float)(s32)FX_Div((s32)(source->radius - distance), (s32)source->radius) / 4096.0f;
    return (s32)((float)source->amplitude * ratio);
}

/*
 * A clamp-increment and a clamp-decrement on the same signed 32-bit array
 * (volumeLevel), indexed by the second argument and clamped against a
 * caller-supplied bound passed as the third: ISS_3DS_SYS_RampVolumeUp adds 0x10 and caps
 * at the bound from above, ISS_3DS_SYS_RampVolumeDown subtracts 0x10 and floors at the
 * bound from below.
 *
 * The comparison order in each is a deliberate `cmp`-operand tell
 * (docs/idioms/cmp-operand-order-names-the-temporary.md): ISS_3DS_SYS_RampVolumeUp
 * compares the bound against the computed value (`cmp r2, r1`), which is
 * what `if (cap < v)` compiles to, not `if (v > cap)`.
 */
void ISS_3DS_SYS_RampVolumeUp(Iss3dsSys *sys, u32 sourceIndex, s32 cap)
{
    s32 *levels = sys->volumeLevel;
    s32 level = levels[sourceIndex] + 0x10;

    if (cap < level) {
        level = cap;
    }
    levels[sourceIndex] = level;
}

void ISS_3DS_SYS_RampVolumeDown(Iss3dsSys *sys, u32 sourceIndex, s32 cap)
{
    s32 *levels = sys->volumeLevel;
    s32 level = levels[sourceIndex] - 0x10;

    if (level < cap) {
        level = cap;
    }
    levels[sourceIndex] = level;
}

/* Applies the master volume to the source's level and sets its tracks' volume. */
void ISS_3DS_SYS_ApplySourceVolume(Iss3dsSys *sys, u32 sourceIndex)
{
    u8 *slot = (u8 *)sys + sourceIndex * 4;
    int volume = ISS_3DS_SYS_ScaleVolume(sys, (u8)*(int *)(slot + 0x1E4), slot);

    GFL_USE_SetBgmTrackVolume(sys->sources[sourceIndex].trackMask, volume);
}

/*
 * Signed pan, -0x80..0x7f, for a source heard from a listener: build the
 * listener's right-hand axis by crossing its facing vector with world up
 * (and normalising twice, which is what the doubled VEC_Normalize pair is),
 * then project the listener-to-source direction onto it.  The three
 * _ll_mul + shift-by-12 triples are FX_Mul in its open form, scaling the
 * normalised axis by the source distance.
 *
 * The two vector arguments arrive as pointers and are copied into locals
 * before use; the ldm/stm pairs at the top are those copies, not aliasing
 * work (see docs/idioms/aggregate-assignment-is-ldm-stm.md).
 *
 * The 4096.0f divisor is the pool word 0x45800000 at 0x0202BDCC; 0x43000000
 * is 128.0f, materialised as movs #0x43 / lsls #0x18 rather than pooled.
 */
s32 ISS_3DS_SYS_CalcSourcePan(const Iss3dsSource *source, const struct VecFx32 *cameraPos,
                  const struct VecFx32 *cameraTarget)
{
    struct VecFx32 facing;
    struct VecFx32 toSource;
    struct VecFx32 horizontal;
    struct VecFx32 up;
    struct VecFx32 verticalPart;
    struct VecFx32 right;
    struct VecFx32 upAxis;
    struct VecFx32 facingUnit;
    struct VecFx32 listener;
    struct VecFx32 target;
    struct VecFx32 sourcePos;
    s32 height;
    s32 pan;

    listener = *cameraPos;
    target = *cameraTarget;
    sourcePos = source->pos;
    VEC_Subtract(&target, &listener, &facing);
    VEC_Subtract(&sourcePos, &listener, &toSource);

    up.x = 0;
    up.y = 0x1000;
    up.z = 0;
    VEC_Normalize(&facing, &facingUnit);
    VEC_CrossProduct(&facingUnit, &up, &right);
    VEC_Normalize(&right, &right);
    VEC_CrossProduct(&right, &facingUnit, &upAxis);
    VEC_Normalize(&upAxis, &upAxis);
    VEC_Normalize(&upAxis, &upAxis);

    height = VEC_DotProduct(&toSource, &upAxis);
    verticalPart.x = (s32)(((s64)upAxis.x * height + 0x800) >> 12);
    verticalPart.y = (s32)(((s64)upAxis.y * height + 0x800) >> 12);
    verticalPart.z = (s32)(((s64)upAxis.z * height + 0x800) >> 12);

    VEC_Subtract(&toSource, &verticalPart, &horizontal);
    VEC_Normalize(&horizontal, &horizontal);
    pan = (s32)((float)VEC_DotProduct(&right, &horizontal) / 4096.0f * 128.0f);
    if (pan < -0x80) {
        pan = -0x80;
    }
    if (pan > 0x7f) {
        pan = 0x7f;
    }
    return pan;
}

/*
 * A clamp-decrement on the same shape as ISS_3DS_SYS_RampVolumeDown, on panLevel (offset
 * 0x224 of the object) with a different step (0x20). Matched as a
 * one-function unit rather than with `one`: this function is followed by two
 * bytes of inter-section padding before the next label.
 */
void ISS_3DS_SYS_RampPanDown(Iss3dsSys *sys, u32 sourceIndex, s32 cap)
{
    s32 *levels = sys->panLevel;
    s32 level = levels[sourceIndex] - 0x20;

    if (level < cap) {
        level = cap;
    }
    levels[sourceIndex] = level;
}

/*
 * A clamp-increment on the same shape as ISS_3DS_SYS_RampVolumeUp, on panLevel (offset
 * 0x224) with step 0x20. Matched as a one-function unit rather than with
 * `one`, for the same trailing-padding reason as ISS_3DS_SYS_RampPanDown.
 */
void ISS_3DS_SYS_RampPanUp(Iss3dsSys *sys, u32 sourceIndex, s32 cap)
{
    s32 *levels = sys->panLevel;
    s32 level = levels[sourceIndex] + 0x20;

    if (cap < level) {
        level = cap;
    }
    levels[sourceIndex] = level;
}

/*
 * Sets the pan of one source's tracks (trackMask halfword at +0x3c of the
 * object) to its panLevel (+0x224 array).
 */
void ISS_3DS_SYS_ApplySourcePan(Iss3dsSys *sys, u32 sourceIndex)
{
    GFL_USE_SetBgmTrackParams(sys->sources[sourceIndex].trackMask, 0x100, 0,
                  sys->panLevel[sourceIndex]);
}

/*
 * Moves the master volume one step toward targetVolume: a full step when
 * the distance is at least volumeStep, the exact distance otherwise.
 */
void ISS_3DS_SYS_StepMasterVolume(Iss3dsSys *sys)
{
    int target = sys->targetVolume;
    int current = sys->volume;
    int diff;
    int abs_diff;
    int step;

    if (current == target) {
        return;
    }

    diff = target - current;
    abs_diff = diff;
    if (diff <= 0) {
        abs_diff = -diff;
    }

    step = sys->volumeStep;
    if (abs_diff >= step) {
        if (diff < 0) {
            diff = -step;
        } else {
            diff = step;
        }
    }

    sys->volume += diff;
}

/*
 * Returns (volume * level) / 0x7f truncated to a byte: the source level
 * scaled by the master volume. The third argument is unused.
 */
u32 ISS_3DS_SYS_ScaleVolume(Iss3dsSys *sys, u32 level, void *unused)
{
    return (u8)((sys->volume * level) / 0x7f);
}
