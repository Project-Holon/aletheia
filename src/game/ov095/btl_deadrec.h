#ifndef GAME_OV095_BTL_DEADREC_H
#define GAME_OV095_BTL_DEADREC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of btl_deadrec.c, prototypes copied from their definitions. */

#include "../ov093/btl_records_types.h"
#include "../types.h"

void BTL_DEADREC_ClearTurn(BtlDeadRecTurn *t);
void BTL_DEADREC_Init(BtlDeadRec *p);
void BTL_DEADREC_StartTurn(BtlDeadRec *p);
void BTL_DEADREC_Add(BtlDeadRec *p, u8 pokeId);
u8 BTL_DEADREC_GetCount(BtlDeadRec *p, u32 i);
u8 BTL_DEADREC_GetPokeId(BtlDeadRec *p, u32 i, u32 j);
u8 BTL_DEADREC_IsReported(BtlDeadRec *p, u32 i, u32 j);
void BTL_DEADREC_SetReported(BtlDeadRec *p, u32 i, u32 j);
u8 BTL_DEADREC_GetLastPokeId(BtlDeadRec *p);
/* END mkheaders: generated region */

#endif
