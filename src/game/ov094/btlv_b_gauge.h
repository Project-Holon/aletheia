#ifndef GAME_OV094_BTLV_B_GAUGE_H
#define GAME_OV094_BTLV_B_GAUGE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of btlv_b_gauge.c, prototypes copied from their definitions. */

struct TcbTask;

#include "../ov094/btlv_b_gauge_types.h"
#include "../ov094/btlv_b_gauge_types.h"
#include "../types.h"

BtlvPartyBallBar *BTLV_B_GAUGE_CreatePartyBallBar(const BtlvPartyBallBarParam *param, u32 heapId);
void BTLV_B_GAUGE_DeletePartyBallBar(BtlvPartyBallBar *bar);
int BTLV_B_GAUGE_IsPartyBallBarActive(BtlvPartyBallBar *bar);
void BTLV_B_GAUGE_TaskPartyBallBar(struct TcbTask *task, void *arg);
void BTLV_B_GAUGE_PartyBallBarTaskDeleted(void *task);
/* END mkheaders: generated region */

#endif
