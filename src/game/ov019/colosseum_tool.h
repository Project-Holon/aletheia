#ifndef GAME_OV019_COLOSSEUM_TOOL_H
#define GAME_OV019_COLOSSEUM_TOOL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of colosseum_tool.c, prototypes copied from their definitions. */

#include "../ov012/union_comm_types.h"

int COLOSSEUM_CheckAllEntered(ColosseumWork *colosseum);
int COLOSSEUM_CheckAllTrainerCardsReceived(ColosseumWork *colosseum);
int COLOSSEUM_IsPositionsReceived(ColosseumWork *colosseum);
void COLOSSEUM_ClearPositionsReceived(ColosseumWork *colosseum);
int COLOSSEUM_IsOnStandPos(void *a, int mode, unsigned *out);
int COLOSSEUM_CheckAllFinished(ColosseumWork *colosseum);
int COLOSSEUM_IsAnyFinished(ColosseumWork *colosseum);
int COLOSSEUM_IsOnCounterPos(void *a);
void COLOSSEUM_UpdateCommPlayers(ColosseumWork *work);
/* END mkheaders: generated region */

#endif
