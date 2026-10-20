#ifndef GAME_OV093_BTL_MSG_H
#define GAME_OV093_BTL_MSG_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of btl_msg.c, prototypes copied from their definitions. */

struct BtlMain;
struct BtlPokeList;
struct WordSet;
struct Strbuf;

#include "../types.h"

void BTL_MSG_Init(struct BtlMain *battle, u32 clientId, struct BtlPokeList *pokeList, u32 heapId);
void BTL_MSG_Exit(void);
void BTL_MSG_SetPokeName(u8 pokeId, u32 slot);
void BTL_MSG_SetPokeSpecies(u8 pokeId, u32 slot);
void BTL_MSG_SetPokeNickname(u8 pokeId, u8 slot);
void BTL_MSG_SetClientValue(struct WordSet *wordSet, u8 slot, u8 clientId);
void BTL_MSG_SetClientName(struct WordSet *wordSet, u8 slot, u8 clientId);
void BTL_MSG_FormatArgs(struct Strbuf *dest, u16 msgId, u32 argCount, ...);
void BTL_MSG_FormatWithSide(struct Strbuf *dest, u16 msgId, u32 *args);
void BTL_MSG_BuildString(struct Strbuf *dest, u32 msgId, u32 *args);
void BTL_MSG_DispatchTagged(struct Strbuf *dest, u16 msgId, u32 *args);
u16 *BTL_MSG_FindWordTag(u16 *text, u32 *outGroup, u16 *outKind, u8 *outSlot);
u8 BTL_MSG_CountWordTags(struct Strbuf *text);
void BTL_MSG_ExpandTags(struct Strbuf *text, const u32 *values, struct WordSet *wordSet);
void BTL_MSG_BuildStandard(struct Strbuf *dest, u16 msgId, u32 *args);
void BTL_MSG_BuildStandardSingle(struct Strbuf *dest, u32 msgId, u32 *args);
void BTL_MSG_BuildStandardPair(struct Strbuf *dest, u16 msgId, u32 *args);
void BTL_MSG_BuildMoveEffectC(struct Strbuf *dest, int msgId, u32 *args);
void BTL_MSG_BuildClientAction(struct Strbuf *dest, u32 msgId, u32 *args);
void BTL_MSG_BuildItemUse(struct Strbuf *dest, u8 clientId, u16 entry);
void BTL_MSG_BuildPlainEntry(struct Strbuf *dest, u16 entry, int alternate);
void BTL_MSG_GetUiString(struct Strbuf *dest, u32 msgId);
void BTL_MSG_BuildUiString(struct Strbuf *dest, u32 msgId, u32 *args);
void BTL_MSG_BuildUiStringFlagged(struct Strbuf *dest, u32 msgId, u32 *args);
void BTL_MSG_BuildTrainerString(struct Strbuf *dest, u32 msgId, u32 *args);
void BTL_MSG_BuildTrainerStringBody(struct Strbuf *dest, u32 msgId, u32 *args);
void BTL_MSG_BuildBallStatusOpen(struct Strbuf *dest, u32 ball0, u32 ball1, u32 ball2, u32 ball3, u32 ball4, u32 ball5);
void BTL_MSG_BuildBallStatusRefresh(struct Strbuf *dest, u32 ball0, u32 ball1, u32 ball2, u32 ball3, u32 ball4, u32 ball5);
/* END mkheaders: generated region */

#endif
