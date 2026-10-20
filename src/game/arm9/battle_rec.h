#ifndef GAME_ARM9_BATTLE_REC_H
#define GAME_ARM9_BATTLE_REC_H

/* Public functions of battle_rec.c, prototypes copied from their definitions. */

struct BattleRecSave;
struct SaveControl;
struct GameData;
struct BattleRecHeader;
struct BattleRecBody;

#include "../types.h"

struct BattleRecSave *BATTLE_REC_Create(u32 heap);
void BATTLE_REC_AllocWork(u32 heap);
void BATTLE_REC_FreeWork(void);
void BATTLE_REC_Delete(struct BattleRecSave *rec);
u32 BATTLE_REC_GetWorkSize(void);
void BATTLE_REC_Clear(struct BattleRecSave *rec);
u32 BATTLE_REC_IsDataExist(void);
void BATTLE_REC_ClearWork(void);
void BATTLE_REC_DecodeWork(void);
void BATTLE_REC_EncodeWork(void);
u32 BATTLE_REC_LoadToWork(struct SaveControl *save, struct BattleRecSave *rec, u32 heap, u32 *result, u32 id);
u32 BATTLE_REC_Load(struct SaveControl *save, u16 heap, u32 *result, u32 id);
struct BattleRecSave *BATTLE_REC_LoadAlloc(struct SaveControl *save, u32 heap, u32 *result, u32 id);
u32 BATTLE_REC_VerifyAndCloseSave(struct SaveControl *save, u32 heap, u32 *result, u32 id);
u32 BATTLE_REC_SaveSeq(struct GameData *gameData, struct BattleRecSave *rec, u32 id, u16 *seq, u16 heap);
u32 BATTLE_REC_BeginSave(struct GameData *gameData, u16 heap, u32 modeIndex, u32 battleCount, u32 id, u16 *seq, u16 *subSeq);
void BATTLE_REC_GetModeLayout(u16 mode, s32 *sides, s32 *members);
void BATTLE_REC_MakeHeader(struct SaveControl *save, struct BattleRecHeader *head, const struct BattleRecBody *body, u32 modeIndex, u32 battleCount);
u32 BATTLE_REC_IsMagicBroken(struct SaveControl *save, struct BattleRecSave *rec);
u32 BATTLE_REC_IsValid(struct SaveControl *save, struct BattleRecSave *rec);
void BATTLE_REC_Decode(void *data, u32 size, u32 code);
void BATTLE_REC_Encode(void *data, u32 size, u32 code);
struct BattleRecSave *BATTLE_REC_GetWork(void);
struct BattleRecBody *BATTLE_REC_GetBody(void);
struct BattleRecHeader *BATTLE_REC_GetHeader(void);
struct BattleRecHeader *BATTLE_REC_GetHeaderOf(struct BattleRecSave *rec);
void BATTLE_REC_SetData(const void *profile, const struct BattleRecHeader *head, const struct BattleRecBody *body);
u64 BATTLE_REC_GetHeaderParam(const struct BattleRecHeader *head, int param, int index);
u32 BATTLE_REC_IsVersionSupported(u32 version);
void BATTLE_REC_SetBodyCrc(struct BattleRecBody *body);
void BATTLE_REC_LoadToolOverlay(void);
void BATTLE_REC_UnloadToolOverlay(void);

#endif
