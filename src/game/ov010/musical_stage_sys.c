/*
 * file:     musical_stage_sys.c
 * unit:     yes
 * function: MUSICAL_STAGE_SYS_Init, MUSICAL_STAGE_SYS_Exit, MUSICAL_STAGE_SYS_Main, MUSICAL_STAGE_SYS_Create, MUSICAL_STAGE_SYS_Delete, MUSICAL_STAGE_SYS_SetLocalPerformer, MUSICAL_STAGE_SYS_CreateNpcPerformer, MUSICAL_STAGE_SYS_SetRemotePerformer, MUSICAL_STAGE_SYS_SetPerformerProp
 * address:  0x02156CE0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from musical_dressup_sys.c by tools/splitfile.py.
 *
 * symbols:
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   MUSICAL_MCSS_AllocSmall  0x021F685C  thumb  ov112
 *   MUSICAL_MCSS_LoadDistSave  0x021F68BC  thumb  ov112
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 *   MUSICAL_MCSS_FreeMon  0x021F6888  thumb
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   func_020315D4 0x020315D4 arm
 *   ov112_id       0x00000070  data
 *   STA_ACTING_Create  0x021F8480  thumb ov132
 *   STA_ACTING_Update  0x021F879C  thumb
 *   STA_ACTING_Delete  0x021F8640  thumb
 *   sMusicalStageSysFileName  0x02172754  data
 *   MUSICAL_MCSS_AllocMon  0x021F67E0  thumb  ov112
 *   MUSICAL_PROGRAM_Create 0x02157028 thumb ov010
 *   MUSICAL_PROGRAM_Delete 0x0215716C thumb ov010
 *   MUSICAL_PROGRAM_SplitBonus 0x02157174 thumb ov010
 */
#include "event_ircbattle_shared_types.h"
#include "musical_event_shared_types.h"

enum {
    MUSICAL_PERFORMER_LOCAL = 0,
    MUSICAL_PERFORMER_REMOTE = 1,
    MUSICAL_PERFORMER_NPC = 2
};

/* Work of the stage proc. */
typedef struct MusicalStageWork {
    MusicalStage *stage;
    void *ui;
    u32 unused;
} MusicalStageWork;

extern int func_02034AC4(s32 overlayId);

extern void func_02034A5C(s32 overlayId);

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 line);

extern u32 func_020307B0(void *ptr);

extern void GFL_HEAP_CreateChildHeap(u32 a, u32 b, u32 c);

extern void *MUSICAL_MCSS_AllocSmall(u32 heapId);

extern void MUSICAL_MCSS_LoadDistSave(void *musicalSystem, void *saveControl, void *session, u8 kind, u16 heapId);

extern void GFL_HEAP_DeleteChecked(u32 heapId);

extern int MUSICAL_MCSS_FreeMon(void *musicalSystem);

extern void *PROCSYS_AllocProcWork(void *proc, u32 size, u32 heapId);

extern void func_020315D4(void *proc);

extern void *STA_ACTING_Create(void *input, int heapId);

extern int STA_ACTING_Update(void *ui);

extern void STA_ACTING_Delete(void *ui);

extern MusicalPerformer *MUSICAL_MCSS_AllocMon(u16 monsNo, u8 form, u8 c, u8 d, u32 personality, u16 heapId);

extern u8 ov112_id[];

extern const char sMusicalStageSysFileName[];

int MUSICAL_STAGE_SYS_Init(void *proc, void *unused, MusicalStage *prevStage);

int MUSICAL_STAGE_SYS_Exit(void *proc, int unused, int keepStage, MusicalStageWork *work);

int MUSICAL_STAGE_SYS_Main(void *proc, int *state, int unused, MusicalStageWork *work);

MusicalStage *MUSICAL_STAGE_SYS_Create(u32 heapId, void *session);

int MUSICAL_STAGE_SYS_Delete(MusicalStage *stage);

int MUSICAL_STAGE_SYS_SetLocalPerformer(MusicalStage *stage, int slot, MusicalPerformer *performer);

void MUSICAL_STAGE_SYS_CreateNpcPerformer(MusicalStage *stage, u8 slot, u16 monsNo, u8 form, u32 personality, u16 appealBase, u16 heapId);

int MUSICAL_STAGE_SYS_SetRemotePerformer(MusicalStage *stage, int slot, MusicalPerformer *performer);

void MUSICAL_STAGE_SYS_SetPerformerProp(MusicalStage *stage, u8 slot, u8 bodySlot, u16 propId, s16 offset, u8 order);

MusicalShowProgram *MUSICAL_PROGRAM_Create(u32 heapId, MusicalSystemHead *musicalSystem, u16 maxLevel);

int MUSICAL_PROGRAM_Delete(MusicalShowProgram *program);

void MUSICAL_PROGRAM_SplitBonus(u32 heapId, MusicalShowProgram *program, MusicalStage *stage);

/*
 * Init of the stage proc: builds the stage (four NPC performers with their
 * props, the program and its split) or takes over the stage handed in. The
 * pooled 0x70 is ov112_id and the three colour masks come from one `mask`
 * local shifted.
 */
int MUSICAL_STAGE_SYS_Init(void *proc, void *unused, MusicalStage *prevStage)
{
    MusicalStageWork *work;
    u32 mask;

    GFL_HEAP_CreateChildHeap(1, 0x2E, 0xA8000);
    work = PROCSYS_AllocProcWork(proc, sizeof(MusicalStageWork), 0x2E);
    if (prevStage == 0) {
        func_02034AC4((u32)ov112_id);
        work->stage = MUSICAL_STAGE_SYS_Create(0x2E, 0);
        mask = 0xFF000000;
        MUSICAL_STAGE_SYS_CreateNpcPerformer(work->stage, 0, 0x147, 0, mask, 60, 0x2E);
        MUSICAL_STAGE_SYS_CreateNpcPerformer(work->stage, 1, 0x147, 0, mask >> 8, 120, 0x2E);
        MUSICAL_STAGE_SYS_CreateNpcPerformer(work->stage, 2, 0x147, 0, mask >> 16, -3, 0x2E);
        MUSICAL_STAGE_SYS_CreateNpcPerformer(work->stage, 3, 0x147, 0, 0x000000FF, -1, 0x2E);
        MUSICAL_STAGE_SYS_SetPerformerProp(work->stage, 0, 7, 0x13, 0, 0);
        MUSICAL_STAGE_SYS_SetPerformerProp(work->stage, 0, 8, 0x13, 0, 1);
        MUSICAL_STAGE_SYS_SetPerformerProp(work->stage, 0, 2, 0x10, 0, 2);
        MUSICAL_STAGE_SYS_SetPerformerProp(work->stage, 1, 1, 0x07, 0, 0);
        MUSICAL_STAGE_SYS_SetPerformerProp(work->stage, 1, 5, 0x09, 0, 1);
        MUSICAL_STAGE_SYS_SetPerformerProp(work->stage, 1, 7, 0x18, 0, 2);
        MUSICAL_STAGE_SYS_SetPerformerProp(work->stage, 1, 8, 0x2B, 0, 3);
        MUSICAL_STAGE_SYS_SetPerformerProp(work->stage, 2, 7, 0x1F, 0, 0);
        MUSICAL_STAGE_SYS_SetPerformerProp(work->stage, 2, 8, 0x1E, 0, 1);
        MUSICAL_STAGE_SYS_SetPerformerProp(work->stage, 2, 2, 0x0F, 0, 2);
        MUSICAL_STAGE_SYS_SetPerformerProp(work->stage, 3, 7, 0x1E, 0, 0);
        MUSICAL_STAGE_SYS_SetPerformerProp(work->stage, 3, 8, 0x1E, 0, 1);
        MUSICAL_STAGE_SYS_SetPerformerProp(work->stage, 3, 2, 0x15, 0, 2);
        work->stage->performers[1]->origin = MUSICAL_PERFORMER_LOCAL;
        GFL_HEAP_CreateChildHeap(1, 0x802C, 0x80000);
        work->stage->musicalSystem = MUSICAL_MCSS_AllocSmall(1);
        MUSICAL_MCSS_LoadDistSave(work->stage->musicalSystem, 0, 0, 0, 0x2C);
        work->stage->program = MUSICAL_PROGRAM_Create(0x2E, work->stage->musicalSystem, 0);
        MUSICAL_PROGRAM_SplitBonus(0x2E, work->stage->program, work->stage);
        work->stage->performers[0]->totalScore = 75;
        work->stage->performers[1]->totalScore = 45;
        work->stage->performers[2]->totalScore = 30;
        work->stage->performers[3]->totalScore = 0;
    } else {
        work->stage = prevStage;
    }
    return 1;
}

/*
 * Exit of the stage proc. With keepStage == 0 the stage and everything it
 * owns is freed here (performer 1 is flagged as an NPC performer first so
 * the stage frees it too).
 */
int MUSICAL_STAGE_SYS_Exit(void *proc, int unused, int keepStage, MusicalStageWork *work)
{
    if (keepStage == 0) {
        MUSICAL_PROGRAM_Delete(work->stage->program);
        MUSICAL_MCSS_FreeMon(work->stage->musicalSystem);
        GFL_HEAP_DeleteChecked(0x2c);
        work->stage->performers[1]->origin = MUSICAL_PERFORMER_NPC;
        MUSICAL_STAGE_SYS_Delete(work->stage);
        func_02034A5C((u32)ov112_id);
    }
    func_020315D4(proc);
    GFL_HEAP_DeleteChecked(0x2e);
    return 1;
}

/*
 * Main of the stage proc: start the stage UI, wait for it, close it.
 */
int MUSICAL_STAGE_SYS_Main(void *proc, int *state, int unused, MusicalStageWork *work)
{
    switch (*state) {
    case 0:
        work->ui = STA_ACTING_Create(work->stage, 0x2e);
        *state = 1;
        break;
    case 1:
        if (STA_ACTING_Update(work->ui) == 1)
            *state = 2;
        break;
    case 2:
        STA_ACTING_Delete(work->ui);
        return 1;
    }
    return 0;
}

/*
 * Creates an empty stage for a session.
 */
MusicalStage *MUSICAL_STAGE_SYS_Create(u32 heapId, void *session)
{
    MusicalStage *stage;
    u8 i;

    stage = func_02030734(heapId, 0x20, 0, sMusicalStageSysFileName, 0xBE);
    stage->session = session;
    for (i = 0; i < 4; i++)
        stage->performers[i] = 0;
    return stage;
}

/*
 * Frees the NPC performers of the stage and the stage itself.
 */
int MUSICAL_STAGE_SYS_Delete(MusicalStage *stage){
    u8 i;

    for (i = 0; i < 4; i++) {
        if (stage->performers[i] != 0 && stage->performers[i]->origin == MUSICAL_PERFORMER_NPC)
            func_020307B0(stage->performers[i]);
    }
    func_020307B0(stage);
}

/*
 * Puts the local performer in a stage slot.
 * stand-in: the integer form (stage + 4 computed first, then the byte
 * offset) is the only one that keeps the base add ahead of the shift; the
 * plain stage->performers[slot] form compiles to shift, add, store.
 */
int MUSICAL_STAGE_SYS_SetLocalPerformer(MusicalStage *stage, int slot, MusicalPerformer *performer)
{
    int list;
    int offset;

    list = (int)stage + 4;
    offset = slot << 2;
    *(MusicalPerformer **)((char *)list + offset) = performer;
    performer->origin = MUSICAL_PERFORMER_LOCAL;
    return MUSICAL_PERFORMER_LOCAL;
}

/*
 * Creates an NPC performer (species, form, personality, appeal base) in a
 * stage slot.
 */
void MUSICAL_STAGE_SYS_CreateNpcPerformer(MusicalStage *stage, u8 slot, u16 monsNo, u8 form, u32 personality, u16 appealBase, u16 heapId)
{
    stage->performers[slot] = MUSICAL_MCSS_AllocMon(monsNo, form, 0, 0, personality, heapId);
    stage->performers[slot]->origin = MUSICAL_PERFORMER_NPC;
    stage->performers[slot]->appealBase = appealBase;
}

/*
 * Puts a peer's performer in a stage slot. Same integer form as
 * MUSICAL_STAGE_SYS_SetLocalPerformer (stand-in, same reason).
 */
int MUSICAL_STAGE_SYS_SetRemotePerformer(MusicalStage *stage, int slot, MusicalPerformer *performer)
{
    int list;
    int offset;

    list = (int)stage + 4;
    offset = slot << 2;
    *(MusicalPerformer **)((char *)list + offset) = performer;
    performer->origin = MUSICAL_PERFORMER_REMOTE;
    return MUSICAL_PERFORMER_REMOTE;
}

/*
 * Equips a prop on a performer: body slot, prop, offset, list order.
 */
void MUSICAL_STAGE_SYS_SetPerformerProp(MusicalStage *stage, u8 slot, u8 bodySlot, u16 propId, s16 offset, u8 order)
{
    MusicalPerformer *performer;

    performer = stage->performers[slot];
    performer->equips[bodySlot].propId = propId;
    performer->equips[bodySlot].offset = offset;
    performer->equips[bodySlot].order = order;
}
