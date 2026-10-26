#ifndef GAME_OV172_CTVT_COMM_H
#define GAME_OV172_CTVT_COMM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of ctvt_comm.c, prototypes copied from their definitions. */

struct CtvtWork;
struct CtvtComm;

#include "../types.h"

struct CtvtComm *CTVT_COMM_Create(void *work, u16 heapId);
void CTVT_COMM_Delete(void *work, char *comm);
void CTVT_COMM_Main(void *work, char *comm);
void CTVT_COMM_StartSession(void *work, void *comm);
void CTVT_COMM_StopSession(struct CtvtWork *work, struct CtvtComm *comm);
u32 CTVT_COMM_IsSessionEnded(int unused, char *comm);
void CTVT_COMM_SetRequestedMode(char *unused, char *comm, u32 mode);
u32 CTVT_COMM_GetNetMode(struct CtvtWork *unused, struct CtvtComm *comm);
void CTVT_COMM_SetConnectMac(char *unused, char *comm, const u8 *mac);
int CTVT_COMM_IsNetReady(void *unused, void *comm);
u8 *CTVT_COMM_GetMyStatus(u8 *comm);
int CTVT_COMM_GetStatusBlockSize(void);
int CTVT_COMM_IsModeSupported(int mode, int kind);
int CTVT_COMM_MatchPeerName(void *probe, void *commArg);
void CTVT_COMM_Update(void *work, char *comm);
void CTVT_COMM_SetScanWait(void *work, char *comm);
void CTVT_COMM_UpdateMembers(void *work, char *comm);
int CTVT_COMM_FindPeerName(unsigned char *comm, unsigned char *probe);
void CTVT_COMM_ClearPeerSlot(int unused, int unused2, void *slot);
void CTVT_COMM_UpdatePeerSlot(void *work, void *comm, int *slot, int slotIdx);
void CTVT_COMM_SendSlotHit(void *work, u32 *comm, u32 value);
u32 CTVT_COMM_SendCommand(void *work, void *comm, u8 command, u32 value);
void CTVT_COMM_HandleMessage(int sender, int size, u32 *msg, char *comm);
int CTVT_COMM_SendVoiceData(void *work, char *comm, u16 *packet);
int CTVT_COMM_ResetVoiceRecord(void *work, char *comm);
void CTVT_COMM_ReceiveVoicePacket(int unused1, int unused2, int unused3, char *comm);
u32 CTVT_COMM_SendStrokeQueue(int unused, char *comm);
void CTVT_COMM_PushStrokes(int work, u32 size, char *strokes, char *comm);
int CTVT_COMM_SendPeerStatus(int unused, char *comm);
void CTVT_COMM_ClaimSlot(int slot, void *unused1, void *unused2, char *comm);
char *CTVT_COMM_GetSlotName(int slot, char *comm);
void CTVT_COMM_SetTimingSync(struct CtvtWork *work, struct CtvtComm *unused, u32 command);
int CTVT_COMM_IsTimingSync(struct CtvtWork *work, struct CtvtComm *unused, u32 command);
u32 CTVT_COMM_GetHandleNetId(void *unused, char *unused2);
u8 CTVT_COMM_GetMarkerSlot(void *unused, char *comm);
int CTVT_COMM_IsPostBusy(void *unused, u8 *comm);
u8 *CTVT_COMM_GetMyStatusPtr(void *unused, u8 *comm);
void *CTVT_COMM_GetVoiceRecord(void *unused, char *comm);
u32 CTVT_COMM_GetSlotConnected(void *unused, char *comm, int slot);
char *CTVT_COMM_GetSlotParam(int unused, char *comm, int slot);
char *CTVT_COMM_GetPeerStatus(int unused, char *comm);
u32 CTVT_COMM_IsSlotActive(void *unused, char *comm, int slot);
u8 CTVT_COMM_GetSlotReady(void *unused, char *comm, int slot);
struct CtvtStroke *CTVT_COMM_PopStroke(struct CtvtWork *unused, struct CtvtComm *comm, int *full);
void CTVT_COMM_AdvanceWriteCursor(struct CtvtWork *unused, struct CtvtComm *comm);
void CTVT_COMM_ResetSlotTimer(void *unused, u8 *comm);
u32 CTVT_COMM_IsSlotTimerDone(void *unused, u8 *comm);
u32 CTVT_COMM_GetVoiceStatePending(void *unused, u8 *comm);
/* END mkheaders: generated region */

#endif
