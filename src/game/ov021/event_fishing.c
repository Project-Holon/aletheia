/*
 * file:     event_fishing.c
 * unit:     yes
 * function: FISHING_CheckFacingWater, FISHING_CreateEvent, FISHING_EventMain, FISHING_StepCounter, FISHING_WaitBite, FISHING_ShowBiteMark, FISHING_HideBiteMark, FISHING_StartRodEffect, FISHING_EndRodEffect
 * address:  0x021C5C64
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Takes the FISHING_ helpers 021C5FA8..021C6054 from the head of field_g3dobj.c (lane FXC2).
 * Split from fldeff_splash.c at 0x021C5C64 (lane FXC, CL129: the fishing event; the FISHING_ helpers 021C5FA8..021C6054 were at the head of field_g3dobj.c).
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   abs_id_C2      0x000000C2  data
 *   ICA_ANIME_GetField1C  0x020120F4  thumb
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAME_EVENT_GetWork  0x020124E8  thumb
 *   GAME_DATA_GetTrainerRecord  0x02012F2C  thumb
 *   RECORD_AddOne  0x02008DF0  thumb
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FIELD_PLAYER_GetPosInDir  0x021A3364  thumb  ov021
 *   FIELDMAP_GetMoveKind  0x02188CFC  thumb  ov021
 *   FIELD_G3D_MAPPER_QueryNearestHit  0x0218DAEC  thumb
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb  ov021
 *   MAP_ATTR_IsLongHopEdge  0x021AB2E8  thumb  ov021
 *   MAP_ATTR_IsFishableWater  0x021AB3B0  thumb
 *   FLDMMDL_MOVE_AddDirVector  0x02164208  thumb  ov010
 *   FIELDMAP_GetEncount  0x02188CE8  thumb  ov021
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FIELD_PLAYER_GetFormSlot  0x021A34EC  thumb  ov021
 *   EFFECT_ENCOUNT_IsSpotAt  0x021AA900  thumb  ov021
 *   FIELD_ENCOUNT_CheckFishingEncount  0x021AA180  thumb  ov021
 *   FLDMMDL_SysPauseMove  0x0216D9A0  thumb  ov010
 *   FIELD_PLAYER_StartFormChange  0x021A2F48  thumb  ov021
 *   FIELD_PLAYER_StepFormChange  0x021A2F54  thumb  ov021
 *   FLDMMDL_SetDrawStatus  0x0216D674  thumb  ov010
 *   FISHING_StepCounter  0x021C5FA8  thumb  ov021
 *   FISHING_StartRodEffect  0x021C602C  thumb  ov021
 *   GFL_USE_GetRandomBelow  0x02005728  thumb
 *   FISHING_WaitBite  0x021C5FC0  thumb  ov021
 *   FISHING_ShowBiteMark  0x021C5FEC  thumb  ov021
 *   FISHING_HideBiteMark  0x021C6018  thumb  ov021
 *   FISHING_EndRodEffect  0x021C6054  thumb  ov021
 *   SCRIPT_SYS_CallScriptEvent  0x02158780  thumb  ov010
 *   EFFECT_ENCOUNT_Reset  0x021AA8EC  thumb  ov021
 *   BTL_SETUP_Delete  0x020130B4  thumb
 *   EVENT_BATTLE_CreateScriptedBattle  0x0216E7C8  thumb  ov010
 *   GAME_EVENT_ChangeEvent  0x0201235C  thumb
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   FLDEFF_GYOE_SetMMdl  0x021BB528  thumb  ov021
 *   FLDEFF_FISHING_SetAnimeSpeed  0x021AE01C  thumb  ov021
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 *   FLDEFF_FISHING_Start  0x021ADF94  thumb  ov021
 *   KEY_GetTrg  0x020362DC  arm  arm9
 */
#include "event_fishing_types.h"
#include "../ov010/fldmmdl_types.h"

struct BbActDesc;
struct BbActRec;
struct Obj;
struct Desc;
struct Ctx;
struct Sub02008C20Obj;
struct Self;
struct S0201235C;


typedef signed char    s8;



typedef struct FieldMap FieldMap;

/* Entry template for BILLBOARD_ACT_CreateEntries (0x24 bytes). */
typedef struct BbActDesc {
    u16 imageIdx;
    u16 scaleX;
    u16 scaleY;
    u8 alpha;
    u8 pad07;
    u32 visible;
    u32 animEnable;
    VecFx32 pos;
    void (*onEnd)(void);
    void *userData;
} BbActDesc;

/* Image record for BILLBOARD_ACT_CreateSlots. */
typedef struct BbActRec {
    void *resource;
    u8 type;
    u8 imageId;
    u8 cellWidth;
    u8 cellHeight;
    u32 count;
} BbActRec;

extern u32 MI_CpuFill8(void *p, int v, int n);
extern void GFL_USE_PlaySeDefaultVolume(u32 se);
struct Desc *GAME_EVENT_Create(void *owner, void *a, void *b, u32 size);
void *GAME_EVENT_GetWork(struct Obj *p);
extern void *ICA_ANIME_GetField1C(const struct Ctx *p);
extern void *GAME_DATA_GetTrainerRecord(int *p);
extern u32 RECORD_AddOne(struct Sub02008C20Obj *obj, int i);
extern u32 FIELDMAP_GetG3dMapper(u8 *p);
extern void *FIELDMAP_GetFieldPlayer(void *fieldMap);
extern void *FIELD_PLAYER_GetMmdl(u8 *p);
extern u16 FLDMMDL_GetDirDisp(void *p);
extern void FIELD_PLAYER_GetPosInDir(u32 *a, int b, int *out);
extern u32 FIELDMAP_GetMoveKind(u8 *p);
extern int FIELD_G3D_MAPPER_QueryNearestHit(u32 a, int *b, u32 *out);
extern u16 MAP_ATTR_GetTerrainId(u32 attr);
extern int MAP_ATTR_IsLongHopEdge(int id);
extern int MAP_ATTR_IsFishableWater(u16 id);
extern void FLDMMDL_MOVE_AddDirVector(int dir, int *p, int amt);
extern u32 FIELDMAP_GetEncount(u8 *p);
extern void *FIELDMAP_GetMmdlSys(u8 *q);
extern void FIELD_PLAYER_GetPos(unsigned char *id, VecFx32 *out);
extern int FIELD_PLAYER_GetFormSlot(u8 *p);
extern int EFFECT_ENCOUNT_IsSpotAt(struct Self *self, short *pos);
/* Retain the mode used to store f59 for the helper's second argument. */
extern struct Obj *FIELD_ENCOUNT_CheckFishingEncount(struct Ctx *ctx, int mode);
extern void FLDMMDL_SysPauseMove(void *o);
extern void FIELD_PLAYER_StartFormChange(u8 *p, u32 a1);
extern int FIELD_PLAYER_StepFormChange(u8 *p);
extern void FLDMMDL_SetDrawStatus(void *p, u16 v);
extern u32 GFL_USE_GetRandomBelow(u32 v);
extern int SCRIPT_SYS_CallScriptEvent(void *p, u16 b, int c, int d, u16 e);
extern void EFFECT_ENCOUNT_Reset(u8 *p);
extern int BTL_SETUP_Delete(int a0);
extern int EVENT_BATTLE_CreateScriptedBattle(int a0, int a1, int a2, int a3, int a4);
extern void GAME_EVENT_ChangeEvent(struct S0201235C *o, u32 *out);
int FISHING_StepCounter(FishingWork *w, u32 limit);
int FISHING_WaitBite(FishingWork *w, u32 limit);
void FISHING_ShowBiteMark(FishingWork *w);
void FISHING_HideBiteMark(FishingWork *w);
void FISHING_StartRodEffect(FishingWork *w);
void FISHING_EndRodEffect(FishingWork *w);
int FISHING_CheckFacingWater(u32 unused, void *fieldMap, VecFx32 *outPos);
void *FISHING_CreateEvent(struct FieldMap *fieldMap, void *gameSystem);
int FISHING_EventMain(void *task, int *state, FishingWork *work);
extern unsigned char abs_id_C2[];
extern u32 KEY_GetTrg(void);
extern void *FIELDMAP_GetEffect(void *fieldMap);
extern u32 FLDEFF_GYOE_SetMMdl(void *a, void *mmdl, u32 b, u32 c);
extern void FLDEFF_FISHING_SetAnimeSpeed(u32 effect, u16 v);
extern void FIELD_EFFECT_DeleteObject(u32 effect);
extern u32 FLDEFF_FISHING_Start(void *a, void *b, u32 c, int d);
int FISHING_CheckFacingWater(u32 unused, void *fieldMap, VecFx32 *outPos)
{
    int facingPos[3];
    u32 tileInfo[4];
    void *player;
    u32 mapData;
    u8 playerDir;

    mapData = FIELDMAP_GetG3dMapper((u8 *)fieldMap);
    player = FIELDMAP_GetFieldPlayer(fieldMap);
    playerDir = FLDMMDL_GetDirDisp(FIELD_PLAYER_GetMmdl(player));
    FIELD_PLAYER_GetPosInDir(player, playerDir, facingPos);
    if (FIELDMAP_GetMoveKind((u8 *)fieldMap) == 1)
        return 0;
    if (FIELD_G3D_MAPPER_QueryNearestHit(mapData, facingPos, tileInfo) == 0)
        return 0;
    if (MAP_ATTR_IsLongHopEdge(MAP_ATTR_GetTerrainId(tileInfo[2])) == 1) {
        FLDMMDL_MOVE_AddDirVector(playerDir, facingPos, 0x10000);
        if (FIELD_G3D_MAPPER_QueryNearestHit(mapData, facingPos, tileInfo) == 0)
            return 0;
    }
    if (MAP_ATTR_IsFishableWater(MAP_ATTR_GetTerrainId(tileInfo[2])) == 0)
        return 0;
    if (outPos != 0) {
        outPos->x = facingPos[0];
        outPos->y = tileInfo[3];
        outPos->z = facingPos[2];
    }
    return 1;
}

/*
 * Creates the fishing event task for the player facing water.
 */
void *FISHING_CreateEvent(struct FieldMap *fieldMap, void *gameSystem)
{
    void *task;
    FishingWork *work;
    int hasEncounter;

    task = GAME_EVENT_Create(gameSystem, 0, FISHING_EventMain, sizeof(FishingWork));
    work = GAME_EVENT_GetWork(task);
    MI_CpuFill8(work, 0, sizeof(FishingWork));
    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->gameData = ICA_ANIME_GetField1C(gameSystem);
    work->encount = (void *)FIELDMAP_GetEncount((u8 *)work->fieldMap);
    work->trainerRecord = GAME_DATA_GetTrainerRecord(work->gameData);
    work->mmdlSys = FIELDMAP_GetMmdlSys((u8 *)work->fieldMap);
    work->fieldPlayer = FIELDMAP_GetFieldPlayer(fieldMap);
    work->mmdl = FIELD_PLAYER_GetMmdl(work->fieldPlayer);
    work->playerDir = FLDMMDL_GetDirDisp(work->mmdl);
    FIELD_PLAYER_GetPos(work->fieldPlayer, &work->playerPos);
    work->playerState = FIELD_PLAYER_GetFormSlot(work->fieldPlayer);
    if (FISHING_CheckFacingWater((u32)work->gameData, work->fieldMap, &work->targetPos) == 0)
        work->noTarget = 1;
    work->targetGrid[0] = (work->targetPos.x >> 4) / 4096;
    work->targetGrid[1] = (work->targetPos.y >> 4) / 4096;
    work->targetGrid[2] = (work->targetPos.z >> 4) / 4096;
    if (EFFECT_ENCOUNT_IsSpotAt(work->encount, work->targetGrid))
        work->hasEncounter = hasEncounter = 1;
    else
        work->hasEncounter = hasEncounter = 0;
    work->wildEncounter = FIELD_ENCOUNT_CheckFishingEncount(work->encount, hasEncounter);
    FLDMMDL_SysPauseMove(work->mmdlSys);
    return task;
}

/*
 * Fishing event main. States: 0 start, 1 and 2 cast, 3 wait for a bite,
 * 4 bite (the player may pull), 5 no wild Pokemon (wait then give up),
 * 6 and 7 fish got away or nothing came, 8 and 9 give the player back,
 * 10 start the wild battle.
 */
int FISHING_EventMain(void *task, int *state, FishingWork *work)
{
    int result;

    switch (*state) {
    case 0:
        if (work->noTarget != 0) {
            *state = 8;
            break;
        }
        FIELD_PLAYER_StartFormChange((u8 *)work->fieldPlayer, 0x200);
        (*state)++;
    case 1:
        if (FIELD_PLAYER_StepFormChange((u8 *)work->fieldPlayer) != 1)
            break;
        FLDMMDL_SetDrawStatus(work->mmdl, 0);
        GFL_USE_PlaySeDefaultVolume(0x684);
        (*state)++;
        break;
    case 2:
        if (FISHING_StepCounter(work, 15) == 0)
            break;
        FISHING_StartRodEffect(work);
        if (work->wildEncounter == 0) {
            *state = 5;
            break;
        }
        work->biteDelay = GFL_USE_GetRandomBelow(0x5a) + 0x1e;
        (*state)++;
        break;
    case 3:
        result = FISHING_WaitBite(work, work->biteDelay);
        if (result == 1) {
            *state = 6;
            break;
        }
        if (result != 2)
            break;
        FISHING_ShowBiteMark(work);
        (*state)++;
        break;
    case 4:
        result = FISHING_WaitBite(work, 0x1e);
        if (result == 0)
            break;
        FISHING_HideBiteMark(work);
        if (result == 1) {
            FISHING_EndRodEffect(work);
            FLDMMDL_SetDrawStatus(work->mmdl, 3);
            SCRIPT_SYS_CallScriptEvent(task, (u16)0x2796, (u32)0, (u32)0, (u32)0x15);
            *state = 10;
            break;
        }
        if (result != 2)
            break;
        RECORD_AddOne((struct Sub02008C20Obj *)work->trainerRecord, 0x50);
        *state = 7;
        break;
    case 5:
        result = FISHING_WaitBite(work, 0x78);
        if (result != 2) {
            if (result == 1)
                *state = 6;
            break;
        }
    case 6:
    case 7:
        FISHING_EndRodEffect(work);
        if (work->wildEncounter != 0) {
            if (work->hasEncounter == 1)
                EFFECT_ENCOUNT_Reset(work->encount);
            BTL_SETUP_Delete((int)work->wildEncounter);
        }
        FLDMMDL_SetDrawStatus(work->mmdl, 1);
        SCRIPT_SYS_CallScriptEvent(task, (u16)(*state + 0x2792), (u32)0, (u32)0, (u32)0x15);
        *state = 8;
        break;
    case 8:
        FIELD_PLAYER_StartFormChange((u8 *)work->fieldPlayer, 8);
        *state = 9;
    case 9:
        if (FIELD_PLAYER_StepFormChange((u8 *)work->fieldPlayer) == 1)
            return 1;
        break;
    case 10:
        RECORD_AddOne((struct Sub02008C20Obj *)work->trainerRecord, 8);
        GAME_EVENT_ChangeEvent(task, (u32 *)EVENT_BATTLE_CreateScriptedBattle((int)work->gameSystem, (int)work->fieldMap, (int)work->wildEncounter, 0, (u8)(work->hasEncounter == 1 ? 1 : 4)));
        return 0;
    }
    return 0;
}

int FISHING_StepCounter(FishingWork *w, u32 limit)
{
    if (w->counter++ < limit)
        return 0;
    w->counter = 0;
    return 1;
}

/*
 * Wait step: 1 on a key press, 2 on timeout, otherwise 0.
 */
int FISHING_WaitBite(FishingWork *w, u32 limit)
{
    u32 n = w->counter;

    w->counter = n + 1;
    if (n < limit) {
        if (KEY_GetTrg() & 1) {
            w->counter = 0;
            return 1;
        }
    } else {
        w->counter = 0;
        return 2;
    }
    return 0;
}

/*
 * Switches the player model to mode 2 and shows the exclamation mark and rod effects.
 */
void FISHING_ShowBiteMark(FishingWork *w)
{
    void *effectSys = FIELDMAP_GetEffect(w->fieldMap);

    FLDMMDL_SetDrawStatus(w->mmdl, 2);
    w->exclamEffect = FLDEFF_GYOE_SetMMdl(effectSys, w->mmdl, 0, 1);
    FLDEFF_FISHING_SetAnimeSpeed(w->rodEffect, 1);
}

void FISHING_HideBiteMark(FishingWork *w)
{
    if (w->exclamEffect != 0) {
        FIELD_EFFECT_DeleteObject(w->exclamEffect);
        w->exclamEffect = 0;
    }
}

void FISHING_StartRodEffect(FishingWork *w)
{
    w->rodEffect = FLDEFF_FISHING_Start(FIELDMAP_GetEffect(w->fieldMap), &w->targetPos, w->playerDir, w->targetPos.y == w->playerPos.y);
}

void FISHING_EndRodEffect(FishingWork *w)
{
    if (w->rodEffect != 0) {
        FIELD_EFFECT_DeleteObject(w->rodEffect);
        w->rodEffect = 0;
    }
}
