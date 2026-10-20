#ifndef GAME_OV010_COMM_PLAYER_H
#define GAME_OV010_COMM_PLAYER_H

typedef struct Entry32 Entry32;
typedef struct CommPlayerWork CommPlayerWork;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of comm_player.c, prototypes copied from their definitions. */

struct Entry32;
struct CommPlayerWork;
typedef struct Entry32 Entry32;
typedef struct CommPlayerWork CommPlayerWork;

#include "../types.h"
#include "../ov010/comm_player_types.h"

u8 QUESTIONNAIRE_GetAnswerBitOffset(u32 id);
u8 QUESTIONNAIRE_GetAnswerMax(u32 i);
u8 SYMBOL_MAP_GetGroup(u8 *p);
u8 SYMBOL_MAP_GetSymbolIndex(u8 *p);
u8 SYMBOL_MAP_CopyEntryRange(Entry32 *list, Entry32 *out, u32 cap, u32 start, int count);
u16 SYMBOL_MAP_GetEntryPage0First(Entry32 *list, Entry32 *out, u32 cap, u8 *count);
int SYMBOL_MAP_GetEntryPage0Second(Entry32 *list, Entry32 *out, u32 cap, u8 *count);
u16 SYMBOL_MAP_GetEntryPage10(Entry32 *list, Entry32 *out, u32 cap, u32 page, u8 *n);
u16 SYMBOL_MAP_GetEntryPage20(Entry32 *list, Entry32 *out, u32 cap, u32 page, u8 *n);
u16 SYMBOL_MAP_GetEntryPage(Entry32 *list, Entry32 *out, u32 cap, int page, u8 *n);
void *COMM_PLAYER_Create(int playerMax, void *gameSystem, u16 heapId, int sysOption);
void COMM_PLAYER_Delete(void *gameSystem, CommPlayerWork *work);
void COMM_PLAYER_Update(void *gameSystem, CommPlayerWork *work);
void COMM_PLAYER_Add(CommPlayerWork *work, int index, int objCode, CommPlayerPackage *package);
void COMM_PLAYER_Del(CommPlayerWork *work, int index);
void COMM_PLAYER_Suspend(CommPlayerWork *work);
void COMM_PLAYER_Resume(CommPlayerWork *work);
void COMM_PLAYER_ClearPending(CommPlayerWork *work);
int COMM_PLAYER_CheckOccupy(CommPlayerWork *work, int index);
u16 COMM_PLAYER_GetObjCode(CommPlayerWork *work, int index);
void COMM_PLAYER_SetPackage(CommPlayerWork *work, int index, CommPlayerPackage *package);
int COMM_PLAYER_UpdateMyPackage(CommPlayerWork *work, CommPlayerPackage *out);
int COMM_PLAYER_SearchGridPos(CommPlayerWork *work, s16 gridX, int gridY, s16 gridZ, int *outId, u32 *searchIndex);
int COMM_PLAYER_SetEffect(CommPlayerWork *work, int index);
u32 COMM_PLAYER_GetMmdl(CommPlayerWork *work, int index);
int COMM_PLAYER_CheckActive(CommPlayerWork *work, int index);
void COMM_PLAYER_CreateSys(void *gameSystem, CommPlayerWork *work);
/* END mkheaders: generated region */

#endif
