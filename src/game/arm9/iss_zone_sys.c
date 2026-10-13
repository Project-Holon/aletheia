/*
 * file:     iss_zone_sys.c
 * unit:     yes
 * function: func_0202BAF4, func_0202BB40, func_0202BB48, func_0202BB68, func_0202BBB0, func_0202BBFC, func_0202BC48, func_0202BC60, func_0202BC78, func_0202BCA0, func_0202BDD0, func_0202BDE8, func_0202BE00, func_0202BE24, func_0202BE54, ISS_ZONE_SYS_Create, ISS_ZONE_SYS_Delete, ISS_ZONE_SYS_Update, ISS_ZONE_SYS_SwitchZone, ISS_ZONE_SYS_Start, ISS_ZONE_SYS_Stop, ISS_ZONE_SYS_LoadRecords, ISS_ZONE_SYS_SelectRecord, ISS_ZONE_SYS_ClearActive, ISS_ZONE_SYS_BeginFade, ISS_ZONE_SYS_FindRecord, ISS_ZONE_SYS_StepFade
 * address:  0x0202BAF4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   ISS_3DS_SYS_ResetSources  0x0202BA24  thumb
 *   VEC_Subtract   0x0207CA00  arm
 *   VEC_Mag        0x0207CBD0  arm
 *   FX_Div   0x0207C768  arm
 *   _fflt          0x0209BDBC  arm
 *   _fdiv          0x0209CE10  arm
 *   _fmul          0x0209C77C  arm
 *   _ffix          0x0209C494  arm
 *   VEC_Normalize     0x0207CCA4  arm
 *   VEC_CrossProduct  0x0207CAE8  arm
 *   VEC_DotProduct    0x0207CA68  arm
 *   _ll_mul           0x0209C054  arm
 *   _u32_div_f   0x0209C2B0  arm
 *   _ffltu  0x0209BE04  arm
 *   _fsub   0x0209CB8C  arm
 *   _f2s    0x0209C494  arm
 *   GFL_USE_SetBgmTrackParams  0x02005EE0  thumb
 *   GFL_USE_SetBgmTrackVolume  0x02005F24  thumb
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   ARC_TOOL_ReadHandleMemberRange  0x0204944C  arm
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
typedef signed long long s64;

/* Index of one 3D sound source of the iss_3ds_sys object (16 slots). */
typedef enum { ISS_3DS_SOURCE_FIRST, ISS_3DS_SOURCE_MAX = 16 } Iss3dsSourceIndex;

struct ArcFile;

struct Vec {
    s32 x, y, z;
};

/*
 * One 8-byte record of the zone table (archive 0x88). A track mask is a
 * bit mask over the tracks of the playing BGM.
 */
struct IssZoneRecord {
    u16 key;            /* zone key the record is selected by */
    u16 audibleMask;    /* tracks that sound in this zone */
    u16 mutedMask;      /* tracks that are silent in this zone */
    u16 fadeSteps;      /* length of the fade into this zone, in updates */
};

/*
 * The zone object (0x18 bytes) that iss_3ds_sys.c keeps at +0x1c of its own
 * object: the table of zone records and the state of the current fade
 * between two zones.
 */
struct IssZone {
    u32 active;                 /* 0: no record selected yet */
    u8  recordCount;
    u8  padding05[3];
    struct IssZoneRecord *records;
    u8  selected;               /* index of the selected record, 0xff: none */
    u8  padding0D;
    u16 fadeInMask;             /* tracks that fade in */
    u16 fadeOutMask;            /* tracks that fade out */
    u16 fadeSteps;              /* length of the running fade */
    u16 fadeStep;               /* updates done so far in the fade */
    u16 padding16;
};

/* One 3D sound source: a point that drives the volume and pan of some tracks. */
struct Iss3dsSource {
    u32 active;
    struct Vec pos;
    s32 radius;                 /* distance beyond which the source is silent */
    s32 amplitude;              /* volume at the source position */
    u16 trackMask;
    u16 padding1A;
};

/* The part of the iss_3ds_sys object that this file reads. */
struct Iss3dsSys {
    u8  padding00[4];
    u32 enabled;
    u8  targetVolume;           /* master volume the ramp moves toward */
    u8  volume;                 /* current master volume (0..0x7f) */
    u8  volumeStep;             /* ramp step of volume per update */
    u8  padding0B;
    struct Vec listenerPos;
    struct Vec listenerTarget;  /* point the listener looks at */
    struct Iss3dsSource sources[ISS_3DS_SOURCE_MAX];
    s32 volumeLevel[ISS_3DS_SOURCE_MAX];    /* per-source volume, ramped */
    s32 panLevel[ISS_3DS_SOURCE_MAX];       /* per-source pan, ramped */
    struct IssZoneRecord *records;
    u8  recordCount;
    u8  activeRecord;           /* 0xff: none */
};

extern void ISS_3DS_SYS_ResetSources(struct Iss3dsSys *sys);
extern void VEC_Subtract(const struct Vec *a, const struct Vec *b,
                         struct Vec *out);
extern s32  VEC_Mag(const struct Vec *v);
extern u32 FX_Div(u32 numerator, u32 denominator);
extern void VEC_Normalize(const struct Vec *v, struct Vec *out);
extern void VEC_CrossProduct(const struct Vec *a, const struct Vec *b,
                             struct Vec *out);
extern s32  VEC_DotProduct(const struct Vec *a, const struct Vec *b);
extern void GFL_USE_SetBgmTrackParams(u32 trackMask, u32 paramKind, u32 unused, u32 value);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 line);
extern u32 func_020307B0(void *p);
extern void *func_020490F4(u32 archiveId, u32 heapId);
extern u16 func_0204961C(void *archive);
extern void ARC_TOOL_ReadHandleMemberRange(struct ArcFile *arc, u32 member, u32 offset, u32 size, void *dst);
extern void   ARC_TOOL_DeleteHandle(void *archive);
extern void GFL_USE_SetBgmTrackVolume(u32 trackMask, u32 volume);
extern float _ffltu(u32 v);
extern float _fdiv(float a, float b);
extern float _fmul(float a, float b);
extern float _fsub(float a, float b);
extern int   _f2s(float a);
void func_0202BAF4(struct Iss3dsSys *sys);
void func_0202BB40(struct Iss3dsSys *sys);
void func_0202BB48(struct Iss3dsSys *sys);
void func_0202BB68(struct Iss3dsSys *sys, int sourceIndex);
void func_0202BBB0(struct Iss3dsSys *sys, int sourceIndex);
s32 func_0202BBFC(struct Iss3dsSource *source, const struct Vec *listenerPos);
void sub_0202BC48(struct Iss3dsSys *sys, u32 sourceIndex, s32 cap);
void sub_0202BC60(struct Iss3dsSys *sys, u32 sourceIndex, s32 cap);
void func_0202BC78(struct Iss3dsSys *sys, u32 sourceIndex);
s32 func_0202BCA0(const struct Iss3dsSource *source, const struct Vec *listenerPos, const struct Vec *listenerTarget);
void sub_0202BDD0(struct Iss3dsSys *sys, u32 sourceIndex, s32 cap);
void sub_0202BDE8(struct Iss3dsSys *sys, u32 sourceIndex, s32 cap);
void func_0202BE00(struct Iss3dsSys *sys, u32 sourceIndex);
void func_0202BE24(struct Iss3dsSys *sys);
u32 func_0202BE54(struct Iss3dsSys *sys, u32 level, void *unused);
struct IssZone *ISS_ZONE_SYS_Create(u32 heapId);
void ISS_ZONE_SYS_Delete(struct IssZone *zone);
void ISS_ZONE_SYS_Update(struct IssZone *zone);
void ISS_ZONE_SYS_SwitchZone(struct IssZone *zone, u32 key);
void ISS_ZONE_SYS_Start(struct IssZone *zone, u16 key);
void ISS_ZONE_SYS_Stop(struct IssZone *zone);
void ISS_ZONE_SYS_LoadRecords(struct IssZone *zone, u32 heapId);
void ISS_ZONE_SYS_SelectRecord(struct IssZone *zone, u16 key);
void ISS_ZONE_SYS_ClearActive(u32 *active);
void ISS_ZONE_SYS_BeginFade(struct IssZone *zone, u32 key);
u32 ISS_ZONE_SYS_FindRecord(const struct IssZone *zone, u32 key);
void ISS_ZONE_SYS_StepFade(struct IssZone *zone);

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
void func_0202BAF4(struct Iss3dsSys *sys)
{
    Iss3dsSourceIndex i;

    if (sys->enabled == 0) {
        return;
    }
    func_0202BE24(sys);
    for (i = 0; i < 0x10; i++) {
        if (sys->sources[i].active != 0) {
            func_0202BB68(sys, i);
            func_0202BBB0(sys, i);
            func_0202BC78(sys, i);
            func_0202BE00(sys, i);
        }
    }
}

/*
 * iss_3ds_sys.c: a bare tail-call thunk to ISS_3DS_SYS_ResetSources (ldr r3, [pc, #0];
 * bx r3; .word 0x0202BA25), the target of the thunk at 0x0202B90C.
 */
void func_0202BB40(struct Iss3dsSys *sys)
{
    ISS_3DS_SYS_ResetSources(sys);
}

/* Silences the tracks of the active record, when there is one. */
void func_0202BB48(struct Iss3dsSys *sys)
{
    u8 record = sys->activeRecord;

    if (record != 0xff) {
        GFL_USE_SetBgmTrackVolume(sys->records[record].mutedMask, 0);
    }
}

/*
 * iss_3ds_sys.c, the per-slot twins that func_0202BAF4 steps: for a live
 * source (0x1c-byte stride at +0x24), compute the target level and move the
 * source's s32 level (volumeLevel or panLevel, indexed by sourceIndex) toward
 * it through the clamp helpers sub_0202BC48 / sub_0202BDD0 / sub_0202BDE8,
 * which take the computed level as their third argument.
 *
 * Callee arity is read from the callee bodies: both clamp helpers compare
 * against r2, so they are declared (sys, index, cap).
 */
void func_0202BB68(struct Iss3dsSys *sys, int sourceIndex)
{
    struct Iss3dsSource *sources = sys->sources;
    s32 target;
    s32 level;

    if (sources[sourceIndex].active == 0) {
        return;
    }
    target = func_0202BBFC(&sources[sourceIndex], &sys->listenerPos);
    level  = sys->volumeLevel[sourceIndex];
    if (level < target) {
        sub_0202BC48(sys, sourceIndex, target);
        return;
    }
    if (target < level) {
        sub_0202BC60(sys, sourceIndex, target);
    }
}

void func_0202BBB0(struct Iss3dsSys *sys, int sourceIndex)
{
    struct Iss3dsSource *sources = sys->sources;
    s32 target;
    s32 level;

    if (sources[sourceIndex].active == 0) {
        return;
    }
    target = func_0202BCA0(&sources[sourceIndex], &sys->listenerPos, &sys->listenerTarget);
    level  = sys->panLevel[sourceIndex];
    if (target < level) {
        sub_0202BDD0(sys, sourceIndex, target);
        return;
    }
    if (level < target) {
        sub_0202BDE8(sys, sourceIndex, target);
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
s32 func_0202BBFC(struct Iss3dsSource *source, const struct Vec *listenerPos)
{
    struct Vec delta;
    s32 distance;
    float ratio;

    VEC_Subtract(&source->pos, listenerPos, &delta);
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
 * caller-supplied bound passed as the third: sub_0202BC48 adds 0x10 and caps
 * at the bound from above, sub_0202BC60 subtracts 0x10 and floors at the
 * bound from below.
 *
 * The comparison order in each is a deliberate `cmp`-operand tell
 * (docs/idioms/cmp-operand-order-names-the-temporary.md): sub_0202BC48
 * compares the bound against the computed value (`cmp r2, r1`), which is
 * what `if (cap < v)` compiles to, not `if (v > cap)`.
 */
void sub_0202BC48(struct Iss3dsSys *sys, u32 sourceIndex, s32 cap)
{
    s32 *levels = sys->volumeLevel;
    s32 level = levels[sourceIndex] + 0x10;

    if (cap < level) {
        level = cap;
    }
    levels[sourceIndex] = level;
}

void sub_0202BC60(struct Iss3dsSys *sys, u32 sourceIndex, s32 cap)
{
    s32 *levels = sys->volumeLevel;
    s32 level = levels[sourceIndex] - 0x10;

    if (level < cap) {
        level = cap;
    }
    levels[sourceIndex] = level;
}

/* Applies the master volume to the source's level and sets its tracks' volume. */
void func_0202BC78(struct Iss3dsSys *sys, u32 sourceIndex)
{
    u8 *slot = (u8 *)sys + sourceIndex * 4;
    int volume = func_0202BE54(sys, (u8)*(int *)(slot + 0x1E4), slot);

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
s32 func_0202BCA0(const struct Iss3dsSource *source, const struct Vec *listenerPos,
                  const struct Vec *listenerTarget)
{
    struct Vec facing;
    struct Vec toSource;
    struct Vec horizontal;
    struct Vec up;
    struct Vec verticalPart;
    struct Vec right;
    struct Vec upAxis;
    struct Vec facingUnit;
    struct Vec listener;
    struct Vec target;
    struct Vec sourcePos;
    s32 height;
    s32 pan;

    listener = *listenerPos;
    target = *listenerTarget;
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
 * A clamp-decrement on the same shape as sub_0202BC60, on panLevel (offset
 * 0x224 of the object) with a different step (0x20). Matched as a
 * one-function unit rather than with `one`: this function is followed by two
 * bytes of inter-section padding before the next label.
 */
void sub_0202BDD0(struct Iss3dsSys *sys, u32 sourceIndex, s32 cap)
{
    s32 *levels = sys->panLevel;
    s32 level = levels[sourceIndex] - 0x20;

    if (level < cap) {
        level = cap;
    }
    levels[sourceIndex] = level;
}

/*
 * A clamp-increment on the same shape as sub_0202BC48, on panLevel (offset
 * 0x224) with step 0x20. Matched as a one-function unit rather than with
 * `one`, for the same trailing-padding reason as sub_0202BDD0.
 */
void sub_0202BDE8(struct Iss3dsSys *sys, u32 sourceIndex, s32 cap)
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
void func_0202BE00(struct Iss3dsSys *sys, u32 sourceIndex)
{
    GFL_USE_SetBgmTrackParams(sys->sources[sourceIndex].trackMask, 0x100, 0,
                  sys->panLevel[sourceIndex]);
}

/*
 * Moves the master volume one step toward targetVolume: a full step when
 * the distance is at least volumeStep, the exact distance otherwise.
 */
void func_0202BE24(struct Iss3dsSys *sys)
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
u32 func_0202BE54(struct Iss3dsSys *sys, u32 level, void *unused)
{
    return (u8)((sys->volume * level) / 0x7f);
}

/*
 * Allocates a 0x18-byte iss_zone_sys zone object through the debug allocator
 * (the allocator's __FILE__ word is the anchor at 0x0202BEA0, the same
 * 0x020A7748 that ISS_ZONE_SYS_LoadRecords pools; 0x55 is the line number), clears its
 * fields with the one exception that selected takes 0xff ("no record"), and
 * loads the record table.
 */
struct IssZone *ISS_ZONE_SYS_Create(u32 heapId)
{
    struct IssZone *zone = (struct IssZone *)func_02030734(heapId, 0x18, 0,
                                                           (const void *)0x020A7748, 0x55);

    zone->active = 0;
    zone->recordCount = 0;
    zone->records = 0;
    zone->selected = 0xff;
    zone->fadeInMask = 0;
    zone->fadeOutMask = 0;
    zone->fadeSteps = 0;
    zone->fadeStep = 0;
    ISS_ZONE_SYS_LoadRecords(zone, heapId);
    return zone;
}

/* Releases the record table when set, then the zone object itself. */
void ISS_ZONE_SYS_Delete(struct IssZone *zone)
{
    if (zone->records != 0) {
        func_020307B0(zone->records);
    }
    func_020307B0(zone);
}

/* Per-frame update: runs the fade step when a record is selected. */
void ISS_ZONE_SYS_Update(struct IssZone *zone)
{
    if (zone->active != 0) {
        ISS_ZONE_SYS_StepFade(zone);
    }
}

/*
 * Guarded forward: only when a record is selected does the fade to the
 * record of `key` start (ISS_ZONE_SYS_BeginFade).
 */
void ISS_ZONE_SYS_SwitchZone(struct IssZone *zone, u32 key)
{
    if (zone->active != 0) {
        ISS_ZONE_SYS_BeginFade(zone, key);
    }
}

/*
 * A four-byte tail-call thunk to ISS_ZONE_SYS_SelectRecord: one PROGBITS section per
 * function means this compiler cannot encode a displacement to another
 * function, so the target's address materialises through a literal pool word
 * and a `bx` (docs/idioms/tail-call-is-a-pool-word-and-bx.md).  The pool
 * word's low bit carries the Thumb bit, so the extern is declared Thumb.
 */
void ISS_ZONE_SYS_Start(struct IssZone *zone, u16 key)
{
    ISS_ZONE_SYS_SelectRecord(zone, key);
}

/* Tail-call thunk to ISS_ZONE_SYS_ClearActive. */
void ISS_ZONE_SYS_Stop(struct IssZone *zone)
{
    ISS_ZONE_SYS_ClearActive((u32 *)zone);
}

/*
 * Opens the zone archive (id 0x88) with the caller's heap id, sizes the
 * record table from the archive's member count and allocates it, then reads
 * every 8-byte record into the table and closes the archive.  The record
 * table is at +8 and the count byte at +4; the count stays a signed int
 * (the guard is `ble`).
 *
 * The five-argument read is the same call ARC_TOOL_ReadHandleMemberRange makes from its other
 * sites; the buffer is its own stack word because the argument count already
 * spends r0-r3.
 */
void ISS_ZONE_SYS_LoadRecords(struct IssZone *zone, u32 heapId)
{
    void *archive = func_020490F4(0x88, (u16)((heapId & 0x7fff) | 0x8000));
    int   count = func_0204961C(archive);
    int   i;

    zone->recordCount = (u8)count;
    zone->records = (struct IssZoneRecord *)func_02030734(heapId, (u32)(count << 3), 0,
                                         (const void *)0x020A7748, 0xd2);

    for (i = 0; i < count; i++) {
        ARC_TOOL_ReadHandleMemberRange(archive, (u32)i, 0, 8,
                      (void *)((u32)zone->records + ((u32)i << 3)));
    }
    ARC_TOOL_DeleteHandle(archive);
}

/*
 * Selects the record ISS_ZONE_SYS_FindRecord matches for the caller's key and latches
 * it into the zone: selected keeps the index, fadeInMask and fadeOutMask take
 * the record's audible and muted masks, fadeSteps is 1 and fadeStep 0 (so the
 * next update completes the switch), and active marks the zone live.  A
 * non-zero active word means "already selected", and 0xff means "no match";
 * both leave the zone untouched.
 */
void ISS_ZONE_SYS_SelectRecord(struct IssZone *zone, u16 key)
{
    u32 index;

    if (zone->active != 0) {
        return;
    }
    index = ISS_ZONE_SYS_FindRecord(zone, key);
    if (index == 0xff) {
        return;
    }
    zone->selected = (u8)index;
    zone->active = 1;
    zone->fadeInMask = zone->records[index].audibleMask;
    zone->fadeOutMask = zone->records[index].mutedMask;
    zone->fadeSteps = 1;
    zone->fadeStep = 0;
}

/* Clears the active word of the zone, when set. */
void ISS_ZONE_SYS_ClearActive(u32 *active)
{
    if (*active != 0) {
        *active = 0;
    }
}

/*
 * Starts the fade from the selected record to the record ISS_ZONE_SYS_FindRecord
 * finds for the caller's key: the tracks muted in the old record and audible
 * in the new one fade in (fadeInMask), the tracks audible in the old and
 * muted in the new fade out (fadeOutMask), fadeSteps takes the new record's
 * length and selected records the new selection.
 *
 * The spelling that matters here is the object as a struct with named members:
 * with `u8 *p` and literal offsets the allocator puts p in r4 and sel in r5,
 * twenty bytes of register numbering away.  Reading `selected` first, calling
 * ISS_ZONE_SYS_FindRecord on the same object and only then loading `records` is what puts
 * the old index in r4, the zone in r5 and the table in r6, which is the original.
 */
void ISS_ZONE_SYS_BeginFade(struct IssZone *zone, u32 key)
{
    u8 oldIndex;
    u32 newIndex;
    const struct IssZoneRecord *records;

    oldIndex = zone->selected;
    newIndex = ISS_ZONE_SYS_FindRecord(zone, key);
    records = zone->records;
    if (newIndex == 0xff) {
        return;
    }
    zone->fadeInMask = records[oldIndex].mutedMask & records[newIndex].audibleMask;
    zone->fadeOutMask = records[oldIndex].audibleMask & records[newIndex].mutedMask;
    zone->fadeSteps = records[newIndex].fadeSteps;
    zone->fadeStep = 0;
    zone->selected = (u8)newIndex;
}

/* Returns the index of the record with the given key, 0xff when none has it. */
u32 ISS_ZONE_SYS_FindRecord(const struct IssZone *zone, u32 key)
{
    u8 i;

    for (i = 0; i < zone->recordCount; i++) {
        if (zone->records[i].key == key) {
            return i;
        }
    }

    return 0xff;
}

/*
 * The fade step: while fadeSteps exceeds the running fadeStep counter, bump
 * the counter and push a volume to the fadeInMask and fadeOutMask tracks
 * (GFL_USE_SetBgmTrackVolume).  The two differ only in the numerator: the first scales
 * the counter, the second the counter brought round by one.
 *
 * Each track mask is bound to a local before the counter is stored and before
 * the division, which is what keeps it in the callee-saved r4 across the five
 * soft-float calls; read at the call site it is reloaded instead and the
 * frame loses a register and its numbering shifts.  Both arms re-read the two
 * u16 fields rather than sharing a computed quotient, which is why each is
 * loaded and converted twice.
 *
 * The counter bump is the one spelling that matters: `zone->fadeStep =
 * zone->fadeStep + 1;` compiles the same increment but lands the guard's two
 * u16 loads in the opposite r0/r1 pair, four concrete bytes away from the
 * original, while `+= 1` reproduces it.  See
 * docs/idioms/a-compound-assignment-on-a-field-flips-the-guards-register-pair.md.
 *
 * The soft-float helpers are MSL/runtime.a's; this front end names them
 * _ffltu, _fdiv, _fmul, _fsub and _f2s, which is what the relocations carry.
 */
void ISS_ZONE_SYS_StepFade(struct IssZone *zone)
{
    u16 trackMask;

    if (zone->fadeSteps <= zone->fadeStep) {
        return;
    }
    trackMask = zone->fadeInMask;
    zone->fadeStep += 1;
    if (trackMask != 0) {
        GFL_USE_SetBgmTrackVolume(trackMask, _f2s(_fmul(127.0f,
                                      _fdiv(_ffltu(zone->fadeStep),
                                            _ffltu(zone->fadeSteps)))));
    }
    trackMask = zone->fadeOutMask;
    if (trackMask != 0) {
        GFL_USE_SetBgmTrackVolume(trackMask, _f2s(_fmul(127.0f,
                                      _fsub(1.0f,
                                            _fdiv(_ffltu(zone->fadeStep),
                                                  _ffltu(zone->fadeSteps))))));
    }
}
