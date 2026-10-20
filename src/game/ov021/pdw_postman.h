#ifndef GAME_OV021_PDW_POSTMAN_H
#define GAME_OV021_PDW_POSTMAN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of pdw_postman.c, prototypes copied from their definitions. */

struct PdwPostmanListWin;
struct FieldMap;
struct PdwPostmanItem;
struct GameEvent;
struct GameData;
struct PdwPostmanSave;
struct GameSystem;
struct MysteryCard;
struct MysteryData;
typedef struct PdwPostmanListWin PdwPostmanListWin;
typedef struct PdwPostmanItem PdwPostmanItem;
typedef struct MysteryCard MysteryCard;

#include "../types.h"

PdwPostmanListWin *PDW_POSTMAN_CreateListWin(struct FieldMap *fieldMap, PdwPostmanItem *items, int itemCount);
int PDW_POSTMAN_DeleteListWin(PdwPostmanListWin *listWin);
void PDW_POSTMAN_PrintListWin(PdwPostmanListWin *listWin);
int PDW_POSTMAN_ListEvent(struct GameEvent *event, int *seq, void *eventWork);
PdwPostmanItem *PDW_POSTMAN_CreateReceivableList(struct GameData *gameData, u32 heapId, struct PdwPostmanSave *save, int *outCount);
void PDW_POSTMAN_ReceiveItems(struct GameData *gameData, int heapId, struct PdwPostmanSave *save);
int PDW_POSTMAN_CountUnreceivable(struct GameData *gameData, int heapId, struct PdwPostmanSave *save);
u32 PDW_POSTMAN_GetUnreceivableItem(struct GameData *gameData, int heapId, struct PdwPostmanSave *save, int index);
struct GameEvent *PDW_POSTMAN_CreateListEvent(struct GameSystem *gameSystem);
MysteryCard *PDW_POSTMAN_GetMysteryCard(struct MysteryData *data, int slot, MysteryCard *card);
MysteryCard *PDW_POSTMAN_FindMysteryCard(struct MysteryData *data, int *outSlot, MysteryCard *card);
void PDW_POSTMAN_SetMysteryReceived(struct MysteryData *data, u32 slot);
u8 PDW_POSTMAN_GetMysteryGiftType(struct MysteryData *data);
/* END mkheaders: generated region */

#endif
