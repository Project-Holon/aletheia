#ifndef GAME_ARM9_BOX_SAVEDATA_H
#define GAME_ARM9_BOX_SAVEDATA_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of box_savedata.c, prototypes copied from their definitions. */

struct BoxSaveHeader;
struct GameData;
struct BoxPokemon;
struct Strbuf;

#include "../types.h"

void BOX_SAVEDATA_Init(struct BoxSaveHeader *header);
u32 BOX_SAVEDATA_GetSize(void);
void BOX_SAVEDATA_InitHeader(struct BoxSaveHeader *header);
struct BoxSaveHeader *BOX_SAVEDATA_GetHeader(struct GameData *gameData);
int BOX_SAVEDATA_AddPokemon(struct GameData *gameData, const struct BoxPokemon *mon);
int BOX_SAVEDATA_AddPokemonToBox(struct GameData *gameData, u32 box, const struct BoxPokemon *mon);
int BOX_SAVEDATA_SetPokemon(struct GameData *gameData, u32 box, u32 slot, const struct BoxPokemon *mon);
void BOX_SAVEDATA_SwapPokemon(struct GameData *gameData, u32 box1, u32 slot1, u32 box2, u32 slot2);
void BOX_SAVEDATA_ClearPokemon(struct GameData *gameData, u32 box, u32 slot);
u32 BOX_SAVEDATA_GetCurrentBox(struct GameData *gameData);
u8 BOX_SAVEDATA_GetUsableBoxCount(struct GameData *gameData);
u8 BOX_SAVEDATA_UnlockBoxes(struct GameData *gameData);
int BOX_SAVEDATA_FindFreeSlot(struct GameData *gameData, int *pBox, int *pSlot);
int BOX_SAVEDATA_CountFreeSlots(struct GameData *gameData);
int BOX_SAVEDATA_CountFreeSlotsInBox(struct GameData *gameData, u32 box);
void BOX_SAVEDATA_SetCurrentBox(struct GameData *gameData, u32 box);
u8 BOX_SAVEDATA_GetWallpaper(struct GameData *gameData, u32 box);
void BOX_SAVEDATA_SetWallpaper(struct GameData *gameData, u32 box, u8 wallpaper);
void BOX_SAVEDATA_GetBoxName(struct GameData *gameData, u32 box, struct Strbuf *dest);
void BOX_SAVEDATA_SetBoxName(struct GameData *gameData, u32 box, const struct Strbuf *name);
int BOX_SAVEDATA_CountPokemonInBox(struct GameData *gameData, u32 box);
int BOX_SAVEDATA_CountNonEggPokemonInBox(struct GameData *gameData, u32 box);
int BOX_SAVEDATA_CountPokemon(struct GameData *gameData);
int BOX_SAVEDATA_CountNonEggPokemon(struct GameData *gameData);
int BOX_SAVEDATA_GetPokemonValue(struct GameData *gameData, u32 box, u32 slot, int field, int arg);
struct BoxPokemon *BOX_SAVEDATA_GetPokemon(struct GameData *gameData, u32 box, u32 slot);
void BOX_SAVEDATA_SetFlags(struct GameData *gameData, u32 bits);
int BOX_SAVEDATA_CheckFlags(struct GameData *gameData, u32 bits);
u32 BOX_SAVEDATA_GetBoxPageSize(void);
u32 *BOX_SAVEDATA_CreateWordHolder(u32 heapId, u32 value);
void BOX_SAVEDATA_Delete(void *memory);
void BOX_SAVEDATA_ClearBoxPage(struct BoxPokemon *boxMons);
u32 BOX_SAVEDATA_GetBoxDataSize(void);
struct BoxPokemon *BOX_SAVEDATA_GetBoxPokemon(struct GameData *gameData, u32 box);
/* END mkheaders: generated region */

#endif
