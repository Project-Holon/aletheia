#ifndef GAME_OV010_BSUBWAY_COMM_H
#define GAME_OV010_BSUBWAY_COMM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of bsubway_comm.c, prototypes copied from their definitions. */

#include "../ov021/bsubway_scr_types.h"
#include "../types.h"

void BSUBWAY_COMM_NetInit(void *arg);
void *BSUBWAY_COMM_GetBeaconData(BsubwayScrWork *work);
int BSUBWAY_COMM_GetBeaconSize(void);
int BSUBWAY_COMM_CheckConnectService(int a, int b);
void BSUBWAY_COMM_AddCommandTable(u32 work);
void BSUBWAY_COMM_DeleteCommandTable(void *work);
void BSUBWAY_COMM_StartTimingSync(u16 timingNo);
int BSUBWAY_COMM_CheckTimingSync(int timingNo);
void BSUBWAY_COMM_SetSendPlayerData(BsubwayScrWork *work, void *gameData);
void BSUBWAY_COMM_SetSendTrainerData(BsubwayScrWork *work);
void BSUBWAY_COMM_SetSendRetireSelect(BsubwayScrWork *work, u16 retire);
void BSUBWAY_COMM_SetSendPlayMode(BsubwayScrWork *work);
void BSUBWAY_COMM_SetSendWord5(BsubwayScrWork *work, u32 value);
void BSUBWAY_COMM_SetSendWord6(BsubwayScrWork *work, u32 value);
void BSUBWAY_COMM_SetSendWord7(BsubwayScrWork *work, u32 value);
void BSUBWAY_COMM_SetSendData(BsubwayScrWork *work, u32 cmd, u16 arg);
int BSUBWAY_COMM_SendData(BsubwayScrWork *work);
void BSUBWAY_COMM_SetRecvMode(BsubwayScrWork *work, u8 mode);
int BSUBWAY_COMM_IsRecvEnd(BsubwayScrWork *work, u16 *result);
void BSUBWAY_COMM_RecvPlayerData(int netId, int size, const u16 *data, BsubwayScrWork *work);
void BSUBWAY_COMM_RecvTrainerData(u16 netId, int size, void *data, BsubwayScrWork *work);
void BSUBWAY_COMM_RecvRetireSelect(u16 netId, int size, u16 *data, BsubwayScrWork *work);
void BSUBWAY_COMM_RecvMyStatus(u16 netId, int size, void *data, BsubwayScrWork *work);
void BSUBWAY_COMM_RecvPlayMode(u16 netId, int size, u16 *data, BsubwayScrWork *work);
void BSUBWAY_COMM_RecvWord5(u16 netId, int size, u16 *data, BsubwayScrWork *work);
void BSUBWAY_COMM_RecvWord6(u16 netId, int size, u16 *data, BsubwayScrWork *work);
void BSUBWAY_COMM_RecvWord7(u16 netId, int size, u16 *data, BsubwayScrWork *work);
/* END mkheaders: generated region */

#endif
