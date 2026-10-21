#ifndef GAME_OV091_PLIST_MESSAGE_H
#define GAME_OV091_PLIST_MESSAGE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of plist_message.c, prototypes copied from their definitions. */

struct PokelistWork;

#include "../ov091/plist_message_types.h"
#include "../ov091/pokelist_types.h"
#include "../types.h"

PlistMessage *PLIST_MESSAGE_Create(PokelistWork *work);
void PLIST_MESSAGE_Destroy(PokelistWork *work, PlistMessage *msg);
void PLIST_MESSAGE_Update(PokelistWork *work, PlistMessage *msg);
void PLIST_MESSAGE_OpenWindow(PokelistWork *work, PlistMessage *msg, u32 kind);
void PLIST_MESSAGE_CloseWindow(PokelistWork *work, PlistMessage *msg);
int PLIST_MESSAGE_IsWindowOpen(PokelistWork *work, PlistMessage *msg);
void PLIST_MESSAGE_PrintText(PokelistWork *work, PlistMessage *msg, u32 messageId);
void PLIST_MESSAGE_StartStream(PokelistWork *work, PlistMessage *msg, u32 messageId, u32 waitForKey);
int PLIST_MESSAGE_IsIdle(PokelistWork *work, PlistMessage *msg);
PlistStreamCbRet PLIST_MESSAGE_StreamCallback(PlistStreamCbArg command);
void PLIST_MESSAGE_CreateWordSet(PokelistWork *work, PlistMessage *msg);
void PLIST_MESSAGE_DestroyWordSet(PokelistWork *work, PlistMessage *msg);
void PLIST_MESSAGE_SetWordSetPokemon(struct PokelistWork *unused, PlistMessage *msg, u32 index, void *mon);
void PLIST_MESSAGE_SetWordSetItem(struct PokelistWork *unused, PlistMessage *msg, u32 index, u32 itemId);
void PLIST_MESSAGE_SetWordSetItemAlt(struct PokelistWork *unused, PlistMessage *msg, u32 index, u32 itemId);
void PLIST_MESSAGE_SetWordSetMove(struct PokelistWork *unused, PlistMessage *msg, u32 index, u32 moveId);
void PLIST_MESSAGE_SetWordSetValue(struct PokelistWork *unused, PlistMessage *msg, u32 index, u32 value);
void PLIST_MESSAGE_SetWordSetNumber(struct PokelistWork *unused, PlistMessage *msg, u32 index, int number, unsigned char digits);
void PLIST_MESSAGE_SetWordSetString(struct PokelistWork *unused, PlistMessage *msg, u32 index, const void *src, int n);
void PLIST_MESSAGE_RedrawWindow(PokelistWork *work, PlistMessage *msg);
void PLIST_MESSAGE_LoadWindowFrame(PokelistWork *work, struct PlistMessage *unused);
void PLIST_MESSAGE_RequestPrompt(PokelistWork *work, PlistMessage *msg);
void PLIST_MESSAGE_DrawKeyCursorMark(struct PokelistWork *unused, PlistMessage *msg);
/* END mkheaders: generated region */

#endif
