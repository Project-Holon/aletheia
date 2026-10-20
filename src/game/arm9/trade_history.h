#ifndef GAME_ARM9_TRADE_HISTORY_H
#define GAME_ARM9_TRADE_HISTORY_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of trade_history.c, prototypes copied from their definitions. */

struct TradeHistory;
struct MyStatus;
struct SaveControl;

#include "../types.h"

u32 TRADE_HISTORY_GetSize(void);
void TRADE_HISTORY_Init(struct TradeHistory *history);
int TRADE_HISTORY_FindPartner(struct TradeHistory *history, u32 id);
void TRADE_HISTORY_AddPartner(struct TradeHistory *history, struct MyStatus *status);
u32 TRADE_HISTORY_GetPartnerId(struct TradeHistory *history, u32 slot);
struct MyStatus *TRADE_HISTORY_GetPartner(struct TradeHistory *history, u32 slot);
u32 TRADE_HISTORY_HasPartner(struct TradeHistory *history, u32 id);
int TRADE_HISTORY_GetPartnerCount(struct TradeHistory *history);
u32 TRADE_HISTORY_GetTradeCount(const struct TradeHistory *history);
void TRADE_HISTORY_IncrementTradeCount(struct TradeHistory *history);
struct TradeHistory *TRADE_HISTORY_GetFromSave(struct SaveControl *save);
/* END mkheaders: generated region */

#endif
