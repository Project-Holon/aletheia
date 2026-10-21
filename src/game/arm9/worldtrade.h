#ifndef GAME_ARM9_WORLDTRADE_H
#define GAME_ARM9_WORLDTRADE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of worldtrade.c, prototypes copied from their definitions. */

struct WorldTradeData;
struct SaveControl;

#include "../types.h"

struct WorldTradeData *WORLDTRADE_GetFromSave(struct SaveControl *save);
int WORLDTRADE_GetSize(void);
void WORLDTRADE_Init(struct WorldTradeData *trade);
u16 WORLDTRADE_GetIsDeposited(const struct WorldTradeData *trade);
void WORLDTRADE_SetIsDeposited(struct WorldTradeData *trade, u16 isDeposited);
void WORLDTRADE_CopyPokemon(struct WorldTradeData *trade, void *outPokemon);
void *WORLDTRADE_NoOp(void *x);
void WORLDTRADE_SetPokemon(struct WorldTradeData *trade, const void *pokemon, u32 boxPos);
void WORLDTRADE_SetLastTradeId(struct WorldTradeData *trade, u32 tradeId);
void WORLDTRADE_SetLastSearchId(struct WorldTradeData *trade, u32 searchId);
u16 WORLDTRADE_GetReturnBox(struct WorldTradeData *trade);
/* END mkheaders: generated region */

#endif
