#ifndef GAME_OV125_GDS_SOCKET_H
#define GAME_OV125_GDS_SOCKET_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gds_socket.c, prototypes copied from their definitions. */

struct BattleRecSave;

#include "../ov125/gds_rap_types.h"
#include "../types.h"
#include "../ov009/cps_ssl_types.h"

void GDS_SOCKET_Reset(void);
int GDS_SOCKET_Start(const char *host, int port, GdsClientInfo *client);
void GDS_SOCKET_ResetConnection(void);
void GDS_SOCKET_RunConnection(void);
int GDS_SOCKET_SendRequest(int requestId, void *body, void *replyBuffer, int bodySize);
unsigned int GDS_SOCKET_GetStateUnlocked(void);
void *GDS_SOCKET_GetReplyUnlocked(void);
int GDS_SOCKET_GetReplySizeUnlocked(void);
int GDS_SOCKET_GetErrorUnlocked(void);
char *GDS_SOCKET_Alloc(int size);
void GDS_SOCKET_Free(int ptr);
void GDS_SOCKET_Lock(void);
void GDS_SOCKET_Unlock(void);
int GDS_SOCKET_InitLock(void);
int GDS_SOCKET_Nop(void *p);
int GDS_SOCKET_InitTick(void);
void GDS_SOCKET_NopVoid(void);
void GDS_SOCKET_ThreadEntry(void *p);
int GDS_SOCKET_StartThread(void);
int GDS_SOCKET_IsDottedQuad(const char *s);
int GDS_SOCKET_ResolveHost(const char *name, char *out);
int GDS_SOCKET_OpenAndResolve(void);
void GDS_SOCKET_Close(void);
int GDS_SOCKET_Connect(void);
int GDS_SOCKET_Send(void);
void GDS_SOCKET_ReceiveThread(void *arg);
int GDS_SOCKET_Receive(void);
void GDS_SOCKET_Sleep(int msec);
int GDS_SOCKET_WaitToken(void);
void GDS_SOCKET_NopBegin(void);
void GDS_SOCKET_InitSsl(void);
int GDS_SOCKET_Begin(GdsClientInfo *client, const char *host, int port);
void GDS_SOCKET_Shutdown(void);
unsigned GDS_SOCKET_GetState(void);
int GDS_SOCKET_GetError(void);
void *GDS_SOCKET_GetReply(void);
int GDS_SOCKET_GetReplySize(void);
int GDS_SOCKET_GetMaxReplySize(int requestId);
int GDS_SOCKET_SendUploadEntry(const GdsEntryBlocks *entry, void *replyBuffer);
int GDS_SOCKET_SendDownloadEntries(int key, void *replyBuffer);
int GDS_SOCKET_SendUploadVideo(const struct BattleRecSave *video, const void *ticket, int ticketLength, void *replyBuffer);
int GDS_SOCKET_SendSearchByCondition(GdsSearchParams *params, void *replyBuffer);
int GDS_SOCKET_SendSearchKind1(int limit, void *replyBuffer);
int GDS_SOCKET_SendSearchKind3(int limit, void *replyBuffer);
int GDS_SOCKET_SendSearchKind2(int limit, void *replyBuffer);
int GDS_SOCKET_SendGetVideo(u32 dataNumberLo, u32 dataNumberHi, u32 version, void *replyBuffer);
int GDS_SOCKET_SendMarkVideo(u32 dataNumberLo, u32 dataNumberHi, void *replyBuffer);
int GDS_SOCKET_GetRequestSize(int requestId);
int GDS_SOCKET_GetMaxReplySizeOf(int requestId);
int GDS_SOCKET_SslAuthCallback(int result, CPSSslConnection *con, int level);
void GDS_SOCKET_InitSslTemplate(void);
void GDS_SOCKET_SetSslTemplate(CPSSslConnection *con);
void GDS_SOCKET_SetSslAuthCallback(int (*callback)(int, CPSSslConnection *, int));
void GDS_SOCKET_SetRootCa(SOCLCaInfo **rootCa, int count);
void GDS_SOCKET_CopySslTemplate(const char *host, CPSSslConnection *con);
void GDS_SOCKET_FreeSslServerName(CPSSslConnection *con);
/* END mkheaders: generated region */

#endif
