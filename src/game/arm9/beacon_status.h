#ifndef GAME_ARM9_BEACON_STATUS_H
#define GAME_ARM9_BEACON_STATUS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of beacon_status.c, prototypes copied from their definitions. */

struct BeaconStatus;
struct StrBuf;
typedef struct BeaconStatus BeaconStatus;

#include "../types.h"

BeaconStatus *BEACON_STATUS_Create(u32 heapId, u32 msgHeapId);
void BEACON_STATUS_Delete(BeaconStatus *bs);
u8 *BEACON_STATUS_GetLog(BeaconStatus *bs);
u8 BEACON_STATUS_GetViewTop(BeaconStatus *bs);
void BEACON_STATUS_SetViewTop(BeaconStatus *bs, int top);
struct StrBuf *BEACON_STATUS_GetMessage(BeaconStatus *bs);
u16 *BEACON_STATUS_GetViewFlags(BeaconStatus *bs);
int BEACON_STATUS_IsLocked(void);
void BEACON_STATUS_DoNothing(void);
/* END mkheaders: generated region */

typedef struct BeaconStatus BeaconStatus;

#endif
