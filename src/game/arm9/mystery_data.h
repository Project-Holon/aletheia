#ifndef GAME_ARM9_MYSTERY_DATA_H
#define GAME_ARM9_MYSTERY_DATA_H

/* Public functions of mystery_data.c, prototypes copied from their definitions. */

struct MysteryData;
struct MysteryCard;
struct MysteryGiftPacket;
struct GameData;
struct SaveControl;

#include "../types.h"

u32 MYSTERY_DATA_GetWorkSize(void);
void MYSTERY_DATA_Init(u8 *buffer);
u32 MYSTERY_DATA_IsValidGiftType(u32 giftType);
int MYSTERY_DATA_CheckCardSpace(struct MysteryData *data);
int MYSTERY_DATA_CheckCardExist(struct MysteryData *data, u32 slot);
void MYSTERY_DATA_CloseCardGap(struct MysteryData *data, u32 slot);
struct MysteryCard *MYSTERY_DATA_GetCardPtr(struct MysteryData *data, u32 slot);
int MYSTERY_DATA_GetCard(struct MysteryData *data, u32 slot, void *out);
int MYSTERY_DATA_AddCard(struct MysteryData *data, const void *card);
void MYSTERY_DATA_DeleteCard(struct MysteryData *data, u32 slot);
u32 MYSTERY_DATA_HasCardSpace(struct MysteryData *data);
u32 MYSTERY_DATA_IsCardExist(struct MysteryData *data, u32 slot);
int MYSTERY_DATA_IsCardReceived(struct MysteryData *data, u32 slot);
void MYSTERY_DATA_SetCardReceived(struct MysteryData *data, u32 slot);
int MYSTERY_DATA_HasAnyCard(struct MysteryData *data);
int MYSTERY_DATA_IsEventFlag(struct MysteryData *data, u32 flag);
void MYSTERY_DATA_SetEventFlag(struct MysteryData *data, u32 flag);
int MYSTERY_DATA_CheckPacketCrc(struct MysteryGiftPacket *packet);
void MYSTERY_DATA_SwapCards(struct MysteryData *data, u32 slotA, u32 slotB);
void MYSTERY_DATA_SaveStart(struct MysteryData *data, struct GameData *gameData);
int MYSTERY_DATA_SaveMain(struct MysteryData *data, struct GameData *gameData);
struct MysteryData *MYSTERY_DATA_Create(struct SaveControl *save, int mode, u32 heapId);
void MYSTERY_DATA_Delete(struct MysteryData *data);
u32 MYSTERY_DATA_GetCardSlotNum(struct MysteryData *data);
int MYSTERY_DATA_IsMainSave(struct MysteryData *data);
void MYSTERY_DATA_Load(struct MysteryData *data, struct SaveControl *save, int mode, int heapId);
void MYSTERY_DATA_Unload(struct MysteryData *data);
u32 MYSTERY_DATA_GetSaveType(struct MysteryData *data);
u32 MYSTERY_DATA_GetCardMax(struct MysteryData *data);
u8 *MYSTERY_DATA_GetBuffer(struct MysteryData *data);
u8 *MYSTERY_DATA_GetEventFlags(struct MysteryData *data);
struct MysteryCard *MYSTERY_DATA_GetCardSlot(struct MysteryData *data, u32 slot);
void MYSTERY_DATA_Encrypt(struct MysteryData *data);
void MYSTERY_DATA_Decrypt(struct MysteryData *data);
void MYSTERY_DATA_EncryptBuffer(u8 *buffer, u32 saveType);
void MYSTERY_DATA_DecryptBuffer(u8 *buffer, u32 saveType);

#endif
