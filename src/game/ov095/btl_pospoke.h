#ifndef GAME_OV095_BTL_POSPOKE_H
#define GAME_OV095_BTL_POSPOKE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of btl_pospoke.c, prototypes copied from their definitions. */

struct BtlMain;
struct BtlSide;
struct BtlPokeParam;

#include "../ov093/btl_records_types.h"
#include "../types.h"

void BTL_POSPOKE_Init(BtlPosPoke *a, struct BtlMain *main, struct BtlSide *pokeCon, u32 rule);
void BTL_POSPOKE_SetupPos(BtlPosPoke *a, struct BtlMain *main, struct BtlSide *pokeCon, u8 d);
void BTL_POSPOKE_RemovePoke(BtlPosPoke *p, int b);
void BTL_POSPOKE_SetPoke(BtlPosPoke *p, int pos, int pokeId, struct BtlSide *pokeCon);
void BTL_POSPOKE_RotateInPoke(BtlPosPoke *p, u32 size, u32 category, struct BtlPokeParam *inPoke, struct BtlSide *pokeCon);
void BTL_POSPOKE_RegisterFoughtPokes(BtlPosPoke *a, int pos, struct BtlSide *pokeCon);
void BTL_POSPOKE_SwapPos(BtlPosPoke *p, int i, int j);
void BTL_POSPOKE_UpdatePosOfPoke(BtlPosPoke *a, int b);
u8 BTL_POSPOKE_GetEmptyPosList(BtlPosPoke *a, u8 clientId, u8 *out);
int BTL_POSPOKE_IsPokeInside(BtlPosPoke *p, u8 pokeId);
int BTL_POSPOKE_GetFieldPos(BtlPosPoke *p, struct BtlMain *main, u8 pokeId);
u8 BTL_POSPOKE_SearchPosByPokeId(BtlPosPoke *p, int pokeId);
int BTL_POSPOKE_GetPosByPokeId(BtlPosPoke *p, int i);
int BTL_POSPOKE_GetPokeIdAtPos(BtlPosPoke *p, u8 i);
/* END mkheaders: generated region */

#endif
