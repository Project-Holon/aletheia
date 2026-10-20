#ifndef GAME_OV090_PLIST_COMM_H
#define GAME_OV090_PLIST_COMM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of plist_comm.c, prototypes copied from their definitions. */

struct PartyListCommWork;
typedef struct PartyListCommWork PartyListCommWork;

#include "../types.h"

void PLIST_COMM_Start(PartyListCommWork *work);
void PLIST_COMM_End(void *unused);
void PLIST_COMM_Update(PartyListCommWork *work);
u32 PLIST_COMM_SendStatus(PartyListCommWork *work, u8 status, u16 selection);
void PLIST_COMM_OnStatusReceived(int netId, int size, u8 *data, PartyListCommWork *work);
void PLIST_COMM_StartSync(void *work, int syncNo);
int PLIST_COMM_IsSyncDoneOrFinished(PartyListCommWork *work, int syncNo);
/* END mkheaders: generated region */

#endif
