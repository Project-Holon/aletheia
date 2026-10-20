#ifndef GAME_OV010_DELIVERY_IRC_H
#define GAME_OV010_DELIVERY_IRC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of delivery_irc.c, prototypes copied from their definitions. */

struct DeliveryIrcKeyMsg;
struct DeliveryIrcWork;
struct DeliveryIrcRequest;
struct DeliveryIrcParam;
typedef struct DeliveryIrcKeyMsg DeliveryIrcKeyMsg;
typedef struct DeliveryIrcWork DeliveryIrcWork;
typedef struct DeliveryIrcRequest DeliveryIrcRequest;
typedef struct DeliveryIrcParam DeliveryIrcParam;

#include "../types.h"

void DELIVERY_IRC_StepIdle(void);
void DELIVERY_IRC_RecvCrc(int netId, int size, const DeliveryIrcKeyMsg *msg, DeliveryIrcWork *work);
void DELIVERY_IRC_RecvRequest(int netId, int size, const DeliveryIrcRequest *msg, DeliveryIrcWork *work);
void DELIVERY_IRC_RecvNotFound(int netId, int size, const int *msg, DeliveryIrcWork *work);
u8 *DELIVERY_IRC_GetRecvBuffer(int netId, DeliveryIrcWork *work);
void DELIVERY_IRC_StepEnd(DeliveryIrcWork *work);
void DELIVERY_IRC_StepFinish(DeliveryIrcWork *work);
void DELIVERY_IRC_StepExitParent(DeliveryIrcWork *work);
void DELIVERY_IRC_StepExitChild(DeliveryIrcWork *work);
void DELIVERY_IRC_StepWaitEndSync(DeliveryIrcWork *work);
void DELIVERY_IRC_StepStartEndSync(DeliveryIrcWork *work);
void DELIVERY_IRC_StepSendData(DeliveryIrcWork *work);
void DELIVERY_IRC_StepSendCrc(DeliveryIrcWork *work);
void DELIVERY_IRC_StepSearchEntry(DeliveryIrcWork *work);
void DELIVERY_IRC_StepSendRequest(DeliveryIrcWork *work);
void DELIVERY_IRC_StepWaitConnect(DeliveryIrcWork *work);
void DELIVERY_IRC_StepStartChangeover(DeliveryIrcWork *work);
void DELIVERY_IRC_StepWaitInit(DeliveryIrcWork *work);
void *DELIVERY_IRC_Create(const DeliveryIrcParam *param);
int DELIVERY_IRC_StartNet(DeliveryIrcWork *work);
int DELIVERY_IRC_Start(DeliveryIrcWork *work);
unsigned char DELIVERY_IRC_GetResult(DeliveryIrcWork *work);
void DELIVERY_IRC_Main(DeliveryIrcWork *work);
int DELIVERY_IRC_Delete(DeliveryIrcWork *work);
/* END mkheaders: generated region */

#endif
