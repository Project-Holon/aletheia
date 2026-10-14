/*
 * file:     enceff_name_cutin.c
 * unit:     yes
 * function: ENCEFF_BuildNameCutInKind10, ENCEFF_BuildNameCutInKind11, ENCEFF_BuildNameCutInKind12, ENCEFF_BuildNameCutInKind13, ENCEFF_BuildNameCutInKind14, ENCEFF_BuildNameCutInKind15, ENCEFF_BuildNameCutInKind16, ENCEFF_BuildNameCutInKind17, ENCEFF_BuildNameCutInKind18, ENCEFF_BuildNameCutInKind19, ENCEFF_BuildNameCutInKind20, ENCEFF_BuildNameCutInKind21, ENCEFF_BuildNameCutInKind22, ENCEFF_BuildNameCutInKind23, ENCEFF_BuildNameCutInKind24, ENCEFF_BuildNameCutInKind25, ENCEFF_BuildNameCutInKind26, ENCEFF_BuildNameCutInKind27, ENCEFF_BuildNameCutInKind28, ENCEFF_BuildNameCutInKind29, ENCEFF_BuildNameCutInKind30, ENCEFF_BuildNameCutInKind32, ENCEFF_BuildNameCutInKind33, ENCEFF_BuildNameCutInKind34, ENCEFF_BuildNameCutInKind03, ENCEFF_BuildNameCutInKind04, ENCEFF_StartNameCutIn, ENCEFF_NameCutInEventMain, ENCEFF_NameCutInFadeOutEventMain
 * address:  0x021F5260
 * region:   ov073
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap 0x0201210C thumb
 *   FIELDMAP_GetEncEff 0x02189A08 thumb ov021
 *   ENCEFF_AllocWork 0x021CF52C thumb ov021
 *   func_020122C0 0x020122C0 thumb
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   ENCEFF_GetWork  0x021CF560  thumb  ov021
 *   FIELDMAP_GetFld3dCi  0x02189A00  thumb  ov021
 *   FLD3D_CI_StartNameSequence  0x021C1DCC  thumb  ov021
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FADE_Start  0x0204E720  arm
 *   FADE_IsActive  0x0204E804  arm
 */
#include "../ov021/fieldmap_types.h"

struct GameSystem;
struct GameEvent;
struct EncEff;
typedef unsigned char u8;

typedef unsigned int u32;

typedef signed int s32;

/*
 * Overlay 73 holds 26 encounter effect builders. Each one is the build
 * function of one row of the effect table in enceff.c (rows 3, 4, 10 to 30,
 * 32 to 34) and starts the same name cut-in event with its own row of the
 * cut-in table (overlay 74). The event flashes the screen twice, then runs
 * the cut-in of fld3d_ci.c.
 */

/* Memory of the cut-in event, allocated in the ENCEFF effect work. */
typedef struct EncEffNameCutInWork {
    int flashCount;     /* 0x00: white flashes done */
    int tableIndex;     /* 0x04: row of the cut-in table */
    int fadeVariant;    /* 0x08: build argument of the effect table row */
} EncEffNameCutInWork;

typedef int (*GameEventMainFunc)(struct GameEvent *event, int *state);

extern struct GameSystem *GAME_EVENT_GetGameSystem(struct GameEvent *event);
extern struct FieldMap *GAMESYSTEM_GetFieldMap(const struct GameSystem *gameSystem);
extern struct EncEff *FIELDMAP_GetEncEff(struct FieldMap *fieldMap);
extern struct Fld3dCi *FIELDMAP_GetFld3dCi(struct FieldMap *fieldMap);
extern void *ENCEFF_AllocWork(struct EncEff *eff, u32 size, u32 heapId);
extern EncEffNameCutInWork *ENCEFF_GetWork(struct EncEff *eff);
extern struct GameEvent *func_020122C0(void *owner, void *arg, GameEventMainFunc main, u32 workSize);
extern void GAME_EVENT_CallEvent(struct GameEvent *parent, struct GameEvent *child);
extern struct GameEvent *FLD3D_CI_StartNameSequence(struct GameSystem *gameSystem, struct Fld3dCi *ci, int tableIndex, int fadeVariant);
extern void FADE_Start(u32 flags, s32 start, s32 end, s32 step);
extern int FADE_IsActive(void);
struct GameEvent *ENCEFF_BuildNameCutInKind10(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *ENCEFF_BuildNameCutInKind11(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *ENCEFF_BuildNameCutInKind12(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *ENCEFF_BuildNameCutInKind13(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *ENCEFF_BuildNameCutInKind14(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *ENCEFF_BuildNameCutInKind15(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *ENCEFF_BuildNameCutInKind16(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *ENCEFF_BuildNameCutInKind17(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *ENCEFF_BuildNameCutInKind18(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *ENCEFF_BuildNameCutInKind19(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *ENCEFF_BuildNameCutInKind20(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *ENCEFF_BuildNameCutInKind21(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *ENCEFF_BuildNameCutInKind22(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *ENCEFF_BuildNameCutInKind23(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *ENCEFF_BuildNameCutInKind24(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *ENCEFF_BuildNameCutInKind25(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *ENCEFF_BuildNameCutInKind26(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *ENCEFF_BuildNameCutInKind27(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *ENCEFF_BuildNameCutInKind28(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *ENCEFF_BuildNameCutInKind29(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *ENCEFF_BuildNameCutInKind30(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *ENCEFF_BuildNameCutInKind32(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *ENCEFF_BuildNameCutInKind33(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *ENCEFF_BuildNameCutInKind34(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *ENCEFF_BuildNameCutInKind03(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *ENCEFF_BuildNameCutInKind04(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *ENCEFF_StartNameCutIn(struct GameSystem *gameSystem, struct FieldMap *unusedFieldMap, int tableIndex, int fadeVariant);
int ENCEFF_NameCutInEventMain(struct GameEvent *event, int *state);
int ENCEFF_NameCutInFadeOutEventMain(struct GameEvent *event, int *state);



/* Build function of effect table row 10 (cut-in table row 0). */
struct GameEvent *ENCEFF_BuildNameCutInKind10(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return ENCEFF_StartNameCutIn(gameSystem, fieldMap, 0, fadeVariant);
}



/* Build function of effect table row 11 (cut-in table row 1). */
struct GameEvent *ENCEFF_BuildNameCutInKind11(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return ENCEFF_StartNameCutIn(gameSystem, fieldMap, 1, fadeVariant);
}



/* Build function of effect table row 12 (cut-in table row 2). */
struct GameEvent *ENCEFF_BuildNameCutInKind12(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return ENCEFF_StartNameCutIn(gameSystem, fieldMap, 2, fadeVariant);
}



/* Build function of effect table row 13 (cut-in table row 3). */
struct GameEvent *ENCEFF_BuildNameCutInKind13(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return ENCEFF_StartNameCutIn(gameSystem, fieldMap, 3, fadeVariant);
}



/* Build function of effect table row 14 (cut-in table row 4). */
struct GameEvent *ENCEFF_BuildNameCutInKind14(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return ENCEFF_StartNameCutIn(gameSystem, fieldMap, 4, fadeVariant);
}



/* Build function of effect table row 15 (cut-in table row 5). */
struct GameEvent *ENCEFF_BuildNameCutInKind15(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return ENCEFF_StartNameCutIn(gameSystem, fieldMap, 5, fadeVariant);
}



/* Build function of effect table row 16 (cut-in table row 6). */
struct GameEvent *ENCEFF_BuildNameCutInKind16(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return ENCEFF_StartNameCutIn(gameSystem, fieldMap, 6, fadeVariant);
}



/* Build function of effect table row 17 (cut-in table row 7). */
struct GameEvent *ENCEFF_BuildNameCutInKind17(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return ENCEFF_StartNameCutIn(gameSystem, fieldMap, 7, fadeVariant);
}



/* Build function of effect table row 18 (cut-in table row 8). */
struct GameEvent *ENCEFF_BuildNameCutInKind18(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return ENCEFF_StartNameCutIn(gameSystem, fieldMap, 8, fadeVariant);
}



/* Build function of effect table row 19 (cut-in table row 9). */
struct GameEvent *ENCEFF_BuildNameCutInKind19(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return ENCEFF_StartNameCutIn(gameSystem, fieldMap, 9, fadeVariant);
}



/* Build function of effect table row 20 (cut-in table row 10). */
struct GameEvent *ENCEFF_BuildNameCutInKind20(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return ENCEFF_StartNameCutIn(gameSystem, fieldMap, 10, fadeVariant);
}



/* Build function of effect table row 21 (cut-in table row 11). */
struct GameEvent *ENCEFF_BuildNameCutInKind21(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return ENCEFF_StartNameCutIn(gameSystem, fieldMap, 11, fadeVariant);
}



/* Build function of effect table row 22 (cut-in table row 12). */
struct GameEvent *ENCEFF_BuildNameCutInKind22(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return ENCEFF_StartNameCutIn(gameSystem, fieldMap, 12, fadeVariant);
}



/* Build function of effect table row 23 (cut-in table row 13). */
struct GameEvent *ENCEFF_BuildNameCutInKind23(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return ENCEFF_StartNameCutIn(gameSystem, fieldMap, 13, fadeVariant);
}



/* Build function of effect table row 24 (cut-in table row 14). */
struct GameEvent *ENCEFF_BuildNameCutInKind24(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return ENCEFF_StartNameCutIn(gameSystem, fieldMap, 14, fadeVariant);
}



/* Build function of effect table row 25 (cut-in table row 15). */
struct GameEvent *ENCEFF_BuildNameCutInKind25(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return ENCEFF_StartNameCutIn(gameSystem, fieldMap, 15, fadeVariant);
}



/* Build function of effect table row 26 (cut-in table row 16). */
struct GameEvent *ENCEFF_BuildNameCutInKind26(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return ENCEFF_StartNameCutIn(gameSystem, fieldMap, 16, fadeVariant);
}



/* Build function of effect table row 27 (cut-in table row 17). */
struct GameEvent *ENCEFF_BuildNameCutInKind27(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return ENCEFF_StartNameCutIn(gameSystem, fieldMap, 17, fadeVariant);
}



/* Build function of effect table row 28 (cut-in table row 18). */
struct GameEvent *ENCEFF_BuildNameCutInKind28(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return ENCEFF_StartNameCutIn(gameSystem, fieldMap, 18, fadeVariant);
}



/* Build function of effect table row 29 (cut-in table row 19). */
struct GameEvent *ENCEFF_BuildNameCutInKind29(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return ENCEFF_StartNameCutIn(gameSystem, fieldMap, 19, fadeVariant);
}



/* Build function of effect table row 30 (cut-in table row 20). */
struct GameEvent *ENCEFF_BuildNameCutInKind30(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return ENCEFF_StartNameCutIn(gameSystem, fieldMap, 20, fadeVariant);
}



/* Build function of effect table row 32 (cut-in table row 21). */
struct GameEvent *ENCEFF_BuildNameCutInKind32(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return ENCEFF_StartNameCutIn(gameSystem, fieldMap, 21, fadeVariant);
}



/* Build function of effect table row 33 (cut-in table row 22). */
struct GameEvent *ENCEFF_BuildNameCutInKind33(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return ENCEFF_StartNameCutIn(gameSystem, fieldMap, 22, fadeVariant);
}



/* Build function of effect table row 34 (cut-in table row 23). */
struct GameEvent *ENCEFF_BuildNameCutInKind34(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return ENCEFF_StartNameCutIn(gameSystem, fieldMap, 23, fadeVariant);
}



/* Build function of effect table row 3 (cut-in table row 24). */
struct GameEvent *ENCEFF_BuildNameCutInKind03(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return ENCEFF_StartNameCutIn(gameSystem, fieldMap, 24, fadeVariant);
}



/* Build function of effect table row 4 (cut-in table row 25). */
struct GameEvent *ENCEFF_BuildNameCutInKind04(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return ENCEFF_StartNameCutIn(gameSystem, fieldMap, 25, fadeVariant);
}


/* Starts the name cut-in event for one row of the cut-in table. */
struct GameEvent *ENCEFF_StartNameCutIn(struct GameSystem *gameSystem, struct FieldMap *unusedFieldMap, int tableIndex, int fadeVariant)
{
    EncEffNameCutInWork *work;

    work = ENCEFF_AllocWork(FIELDMAP_GetEncEff(GAMESYSTEM_GetFieldMap(gameSystem)), 12, 0x50);
    work->flashCount = 0;
    work->tableIndex = tableIndex;
    work->fadeVariant = fadeVariant;
    return func_020122C0(gameSystem, 0, ENCEFF_NameCutInEventMain, 0);
}


/*
 * Main step of the name cut-in event. States 0 to 2 flash the screen white
 * (fade out then in, twice); state 2 then starts the cut-in, or a plain fade
 * out when the cut-in cannot start; state 3 ends the event.
 */
int ENCEFF_NameCutInEventMain(struct GameEvent *event, int *state)
{
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    EncEffNameCutInWork *work;
    struct GameEvent *child;

    gameSystem = GAME_EVENT_GetGameSystem(event);
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    work = ENCEFF_GetWork(FIELDMAP_GetEncEff(fieldMap));
    switch (*state) {
    case 0:
        FADE_Start(4, 0, 0x10, 0);
        *state = *state + 1;
    case 1:
        if (FADE_IsActive() == 0) {
            FADE_Start(4, 0x10, 0, 0);
            *state = *state + 1;
        }
        break;
    case 2:
        if (FADE_IsActive() == 0) {
            work->flashCount = work->flashCount + 1;
            if (work->flashCount < 2) {
                FADE_Start(4, 0, 0x10, 0);
                *state = 1;
            } else {
                child = FLD3D_CI_StartNameSequence(gameSystem, FIELDMAP_GetFld3dCi(fieldMap), work->tableIndex, work->fadeVariant);
                if (child != 0) {
                    GAME_EVENT_CallEvent(event, child);
                } else {
                    child = func_020122C0(gameSystem, event, ENCEFF_NameCutInFadeOutEventMain, 0);
                    GAME_EVENT_CallEvent(event, child);
                }
                *state = *state + 1;
            }
        }
        break;
    case 3:
        return 1;
    }
    return 0;
}


/*
 * Event run when the name cut-in cannot start: fades both screens to black
 * (flags 3) and ends when the fade is done. The field map lookup result is
 * not used.
 */
int ENCEFF_NameCutInFadeOutEventMain(struct GameEvent *event, int *state)
{
    GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem(event));
    switch (*state) {
    case 0:
        FADE_Start(3, 0, 0x10, 3);
        *state = *state + 1;
        break;
    case 1:
        if (FADE_IsActive() == 0) {
            return 1;
        }
        break;
    }
    return 0;
}
