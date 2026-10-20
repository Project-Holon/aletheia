#ifndef GAME_OV095_BTL_WAZAREC_H
#define GAME_OV095_BTL_WAZAREC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of btl_wazarec.c, prototypes copied from their definitions. */

#include "../ov093/btl_records_types.h"
#include "../types.h"

void BTL_WAZAREC_Init(BtlWazaRec *p);
void BTL_WAZAREC_Add(BtlWazaRec *p, u32 wazaId, u32 turn, u32 pokeId);
void BTL_WAZAREC_SetEffectiveLast(BtlWazaRec *p);
int BTL_WAZAREC_IsUsedWaza(BtlWazaRec *p, u32 wazaId, u32 turn);
int BTL_WAZAREC_GetUsedWazaCount(BtlWazaRec *p, u32 wazaId, u32 turn);
u16 BTL_WAZAREC_GetEffectiveWaza(BtlWazaRec *p, u32 turn);
/* END mkheaders: generated region */

#endif
