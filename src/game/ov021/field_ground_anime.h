#ifndef GAME_OV021_FIELD_GROUND_ANIME_H
#define GAME_OV021_FIELD_GROUND_ANIME_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_ground_anime.c, prototypes copied from their definitions. */

struct FieldGroundAnime;
struct GroundAnimeDesc;
struct GroundAnmEntry;
struct GroundAnmSet;
struct GroundTexAnmSet;
struct GroundTexAnm;
struct GroundTexAnmTable;
struct GroundTexKey;
struct GroundKeyTable;
struct GroundAnimeArgs;
struct GroundAnimeWork;
typedef struct FieldGroundAnime FieldGroundAnime;
typedef struct GroundAnimeDesc GroundAnimeDesc;
typedef struct GroundAnmEntry GroundAnmEntry;
typedef struct GroundAnmSet GroundAnmSet;
typedef struct GroundTexAnmSet GroundTexAnmSet;
typedef struct GroundTexAnm GroundTexAnm;
typedef struct GroundTexAnmTable GroundTexAnmTable;
typedef struct GroundTexKey GroundTexKey;
typedef struct GroundKeyTable GroundKeyTable;
typedef struct GroundAnimeArgs GroundAnimeArgs;
typedef struct GroundAnimeWork GroundAnimeWork;

#include "../types.h"
#include "../sdk_fx.h"

FieldGroundAnime *FIELD_GROUND_ANIME_Create(const GroundAnimeDesc *desc, void *modelRes, u16 heapId);
int FIELD_GROUND_ANIME_Delete(FieldGroundAnime *ground);
void FIELD_GROUND_ANIME_Update(FieldGroundAnime *ground);
GroundAnmEntry *FIELD_GROUND_ANIME_GetAnmEntry(FieldGroundAnime *ground, int index);
int FIELD_GROUND_ANIME_BindAnm(u32 entry, u32 fileRes, u32 texRes, u32 renderObj);
void FIELD_GROUND_ANIME_UnbindAnm(GroundAnmEntry *entry);
void FIELD_GROUND_ANIME_AnmSetInit(GroundAnmSet *set, u32 arcId, u32 memberId, u32 count, u16 heapId);
void FIELD_GROUND_ANIME_AnmSetFree(GroundAnmSet *set);
void FIELD_GROUND_ANIME_AnmSetUpdate(GroundAnmSet *set, u32 dt);
GroundAnmEntry *FIELD_GROUND_ANIME_AnmSetGetEntry(GroundAnmSet *set, int index);
int FIELD_GROUND_ANIME_AnmEntryFree(GroundAnmEntry *entry);
u32 FIELD_GROUND_ANIME_AnmEntryBind(GroundAnmEntry *entry, u32 fileRes, u32 texRes, u32 renderObj);
void FIELD_GROUND_ANIME_AnmEntryUnbind(GroundAnmEntry *entry);
int FIELD_GROUND_ANIME_AnmEntryUpdate(GroundAnmEntry *entry, int frame);
void FIELD_GROUND_ANIME_TexAnmSetInit(GroundTexAnmSet *set, u32 arcId, u32 memberId, void *modelRes, u16 heapId);
void FIELD_GROUND_ANIME_TexAnmSetFree(GroundTexAnmSet *set);
void FIELD_GROUND_ANIME_TexAnmSetUpdate(GroundTexAnmSet *set, int dt);
void FIELD_GROUND_ANIME_TexAnmInit(GroundTexAnm *anm, GroundTexAnmTable *table, u32 index, void *modelRes, u16 heapId);
void FIELD_GROUND_ANIME_TexAnmFree(GroundTexAnm *anm);
void FIELD_GROUND_ANIME_TexAnmUpdate(GroundTexAnm *anm, s32 dt);
int FIELD_GROUND_ANIME_TexAnmIsActive(GroundTexAnm *anm);
int FIELD_GROUND_ANIME_GetModelTexVramOffset(void *modelRes, void *animRes, u32 animTexIdx);
u32 FIELD_GROUND_ANIME_GetTexSize(void *animRes, u32 texIdx);
u8 *FIELD_GROUND_ANIME_GetTexData(void *animRes, u32 texIdx);
u32 FIELD_GROUND_ANIME_GetTexAnmKeyData(GroundTexAnmTable *table, u32 index);
u32 FIELD_GROUND_ANIME_GetTexAnmFile(GroundTexAnmTable *table, u32 index);
GroundTexKey FIELD_GROUND_ANIME_KeyTableGetKey(const GroundKeyTable *table, u32 group, u32 frame);
u32 FIELD_GROUND_ANIME_KeyTableGetGroupCount(GroundKeyTable *table);
u32 FIELD_GROUND_ANIME_KeyTableGetDuration(GroundKeyTable *table);
u16 FIELD_GROUND_ANIME_KeyTableGetLastKeyFrame(GroundKeyTable *table, int group);
void FIELD_GROUND_ANIME_KeyTableUnpack(u32 *keyFile, GroundKeyTable *out);
void FIELD_GROUND_ANIME_GetEntryPos(void *fieldMap, VecFx32 *out);
void FIELD_GROUND_ANIME_FreePlayerAcmd(void *a);
void *FIELD_GROUND_ANIME_CreateA(GroundAnimeArgs *args);
void FIELD_GROUND_ANIME_SetupStepsA(GroundAnimeWork *w);
int FIELD_GROUND_ANIME_MainA(void *task, int *state, GroundAnimeWork *work);
void *FIELD_GROUND_ANIME_CreateB(GroundAnimeArgs *args);
void FIELD_GROUND_ANIME_SetupStepsB(GroundAnimeWork *work);
int FIELD_GROUND_ANIME_MainB(void *task, int *state, GroundAnimeWork *work);
int FIELD_GROUND_ANIME_GetPlayerMoveMode(void *fieldMap);
void FIELD_GROUND_ANIME_GetPlayerPos(void *fieldMap, VecFx32 *out);
void FIELD_GROUND_ANIME_GetEntryPosByMapKind(void *fieldMap, VecFx32 *out);
void FIELD_GROUND_ANIME_GetGridEntryPos(void *fieldMap, VecFx32 *out);
void FIELD_GROUND_ANIME_GetRailEntryPos(void *fieldMap, VecFx32 *out);
u8 FIELD_GROUND_ANIME_GetCurrentStep(GroundAnimeWork *work);
u8 FIELD_GROUND_ANIME_GetNextStep(GroundAnimeWork *work);
void FIELD_GROUND_ANIME_AdvanceStep(GroundAnimeWork *work);
void FIELD_GROUND_ANIME_CreateBuildModel(GroundAnimeWork *work);
void FIELD_GROUND_ANIME_DeleteBuildModel(GroundAnimeWork *work);
int FIELD_GROUND_ANIME_IsBuildModelDone(GroundAnimeWork *work);
int FIELD_GROUND_ANIME_HasBuildModel(GroundAnimeWork *work);
void FIELD_GROUND_ANIME_PlayBuildModelForward(GroundAnimeWork *work);
void FIELD_GROUND_ANIME_PlayBuildModelReverse(GroundAnimeWork *work);
void FIELD_GROUND_ANIME_CallEnterEvent(void *task, GroundAnimeWork *work);
void FIELD_GROUND_ANIME_CallExitEvent(void *task, GroundAnimeWork *work);
int FIELD_GROUND_ANIME_ShouldPlayDoorSe(GroundAnimeWork *work);
/* END mkheaders: generated region */

#endif
