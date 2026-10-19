/*
 * file:     iss_zone_sys.c
 * unit:     yes
 * function: ISS_ZONE_SYS_Create, ISS_ZONE_SYS_Delete, ISS_ZONE_SYS_Update, ISS_ZONE_SYS_SwitchZone, ISS_ZONE_SYS_Start, ISS_ZONE_SYS_Stop, ISS_ZONE_SYS_LoadRecords, ISS_ZONE_SYS_SelectRecord, ISS_ZONE_SYS_ClearActive, ISS_ZONE_SYS_BeginFade, ISS_ZONE_SYS_FindRecord, ISS_ZONE_SYS_StepFade
 * address:  0x0202BE68
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
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   ARC_TOOL_GetHandleFileCount  0x0204961C  arm
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

extern void VEC_Subtract(const struct Vec *a, const struct Vec *b,
                         struct Vec *out);
extern s32  VEC_Mag(const struct Vec *v);
extern u32 FX_Div(u32 numerator, u32 denominator);
extern void VEC_Normalize(const struct Vec *v, struct Vec *out);
extern void VEC_CrossProduct(const struct Vec *a, const struct Vec *b,
                             struct Vec *out);
extern s32  VEC_DotProduct(const struct Vec *a, const struct Vec *b);
extern void GFL_USE_SetBgmTrackParams(u32 trackMask, u32 paramKind, u32 unused, u32 value);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 line);
extern u32 GFL_HEAP_Free(void *p);
extern void *ARC_TOOL_CreateHandle(u32 archiveID, u16 heapID);
extern u16 ARC_TOOL_GetHandleFileCount(void *archive);
struct ArcHandle;
extern void ARC_TOOL_ReadHandleMemberRange(struct ArcHandle *arc, u32 memberIdx, u32 offset, u32 size, void *dst);
extern void   ARC_TOOL_DeleteHandle(void *archive);
extern void GFL_USE_SetBgmTrackVolume(u32 trackMask, u32 volume);
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
 * Allocates a 0x18-byte iss_zone_sys zone object through the debug allocator
 * (the allocator's __FILE__ word is the anchor at 0x0202BEA0, the same
 * 0x020A7748 that ISS_ZONE_SYS_LoadRecords pools; 0x55 is the line number), clears its
 * fields with the one exception that selected takes 0xff ("no record"), and
 * loads the record table.
 */
struct IssZone *ISS_ZONE_SYS_Create(u32 heapId)
{
    struct IssZone *zone = (struct IssZone *)GFL_HEAP_Alloc(heapId, 0x18, 0,
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
        GFL_HEAP_Free(zone->records);
    }
    GFL_HEAP_Free(zone);
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
    void *archive = ARC_TOOL_CreateHandle(0x88, (u16)((heapId & 0x7fff) | 0x8000));
    int   count = ARC_TOOL_GetHandleFileCount(archive);
    int   i;

    zone->recordCount = (u8)count;
    zone->records = (struct IssZoneRecord *)GFL_HEAP_Alloc(heapId, (u32)(count << 3), 0,
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
        GFL_USE_SetBgmTrackVolume(trackMask, (int)(127.0f * ((float)(zone->fadeStep) / (float)(zone->fadeSteps))));
    }
    trackMask = zone->fadeOutMask;
    if (trackMask != 0) {
        GFL_USE_SetBgmTrackVolume(trackMask, (int)(127.0f * (1.0f - ((float)(zone->fadeStep) / (float)(zone->fadeSteps)))));
    }
}
