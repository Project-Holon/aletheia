#ifndef GAME_OV010_DELIVERY_BEACON_H
#define GAME_OV010_DELIVERY_BEACON_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of delivery_beacon.c, prototypes copied from their definitions. */

struct DeliveryBeaconSlot;
struct DeliveryBeacon;
struct DeliveryBeaconParam;
struct DeliveryIrcAckView;
typedef struct DeliveryBeaconSlot DeliveryBeaconSlot;
typedef struct DeliveryBeacon DeliveryBeacon;
typedef struct DeliveryBeaconParam DeliveryBeaconParam;
typedef struct DeliveryIrcAckView DeliveryIrcAckView;

DeliveryBeaconSlot *DELIVERY_BEACON_GetCursorSlot(DeliveryBeacon *work);
int DELIVERY_BEACON_GetSlotSize(void);
int DELIVERY_BEACON_IsEqual(int lhs, int rhs);
void DELIVERY_BEACON_StepIdle(DeliveryBeacon *work);
DeliveryBeacon *DELIVERY_BEACON_Create(DeliveryBeaconParam *param);
void DELIVERY_BEACON_CheckDestSize(DeliveryBeacon *work);
int DELIVERY_BEACON_HasAllPieces(DeliveryBeacon *work);
void DELIVERY_BEACON_StepCollectPieces(DeliveryBeacon *work);
void DELIVERY_BEACON_DecodePieces(DeliveryBeacon *work);
void DELIVERY_BEACON_StepStartScan(DeliveryBeacon *work);
void DELIVERY_BEACON_OnSessionStarted(DeliveryBeacon *work);
int DELIVERY_BEACON_Start(DeliveryBeacon *work);
int DELIVERY_BEACON_HasAnyPiece(DeliveryBeacon *work);
int DELIVERY_BEACON_TryComplete(DeliveryBeacon *work);
void DELIVERY_BEACON_RunStep(DeliveryBeacon *work);
int DELIVERY_BEACON_Delete(DeliveryBeacon *work);
void DELIVERY_IRC_SetAckFlag(DeliveryIrcAckView *work);
/* END mkheaders: generated region */

#endif
