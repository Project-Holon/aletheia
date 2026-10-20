#ifndef GAME_OV021_FLD_TRADE_H
#define GAME_OV021_FLD_TRADE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fld_trade.c, prototypes copied from their definitions. */

struct FldTradeHolder;
struct FldTradeData;
struct FldTradeEvent;
typedef struct FldTradeHolder FldTradeHolder;
typedef struct FldTradeData FldTradeData;
typedef struct FldTradeEvent FldTradeEvent;

#include "../types.h"

FldTradeHolder *FLD_TRADE_Create(u32 heapId, u32 tradeId);
void FLD_TRADE_Delete(FldTradeHolder *holder);
u32 FLD_TRADE_GetWantedSpecies(FldTradeHolder *holder);
u32 FLD_TRADE_GetWantedGender(FldTradeHolder *holder);
void *FLD_TRADE_GetMessageString(u32 heapId, u32 msgId);
void FLD_TRADE_BuildPokemon(void *gameData, u16 heapId, void *mon, FldTradeData *data, u32 tradeId);
void FLD_TRADE_DumpPokemonParams(int mon);
void FLD_TRADE_DumpTradeData(FldTradeData *data);
int FLD_TRADE_EventMain(void *event, u32 *seq, FldTradeEvent *work);
void *FLD_TRADE_CreateEvent(void *gsys, u32 tradeId, u32 partyIndex);
/* END mkheaders: generated region */

#endif
