/*
 * file:     gds_socket.c
 * unit:     yes
 * function: GDS_SOCKET_Unlock, func_021D7CD4, GDS_SOCKET_Nop, GDS_SOCKET_InitTick, GDS_SOCKET_NopVoid, GDS_SOCKET_ThreadEntry, GDS_SOCKET_StartThread, GDS_SOCKET_IsDottedQuad, GDS_SOCKET_ResolveHost, GDS_SOCKET_OpenAndResolve, GDS_SOCKET_Close, GDS_SOCKET_Connect, GDS_SOCKET_Send, GDS_SOCKET_Receive, GDS_SOCKET_Sleep, GDS_SOCKET_WaitToken, GDS_SOCKET_NopBegin, GDS_SOCKET_InitSsl, GDS_SOCKET_Begin, GDS_SOCKET_Shutdown, GDS_SOCKET_GetState, GDS_SOCKET_GetError, GDS_SOCKET_GetReply, GDS_SOCKET_GetReplySize, GDS_SOCKET_GetMaxReplySize, GDS_SOCKET_SendUploadEntry, GDS_SOCKET_SendDownloadEntries, GDS_SOCKET_SendUploadVideo, GDS_SOCKET_SendSearchByCondition, GDS_SOCKET_SendSearchKind1, GDS_SOCKET_SendSearchKind3, GDS_SOCKET_SendSearchKind2, GDS_SOCKET_SendGetVideo, GDS_SOCKET_SendMarkVideo, GDS_SOCKET_GetRequestSize, GDS_SOCKET_GetMaxReplySizeOf, GDS_SOCKET_SslAuthCallback, GDS_SOCKET_InitSslTemplate, GDS_SOCKET_SetSslTemplate, GDS_SOCKET_SetSslAuthCallback, GDS_SOCKET_SetRootCa, GDS_SOCKET_CopySslTemplate, GDS_SOCKET_FreeSslServerName
 * address:  0x021D7CC0
 * region:   ov125
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Resolved: the ov121 region hint on the data symbol was contested by the
 * other overlays in the window; un-hinted, sole-ref/data picks the unique
 * overlay start, so the ABS32 pool relocation resolves (the PC24 to
 * func_02086078 was already `label`).
 * Addresses are Black-image addresses.
 * DWCi_Ndi_initLockGlobal from TwlDWC libdwcnd.TWL.HYB.a(dwci_nd.o),
 * dwci_nd.c:1644 (DWARF).  The body initialises the ov125 bss lock at
 * 0x021DA174 and reports success:
 *     OS_InitMutex(&gNdiLockGlobal);
 *     return TRUE;
 * 0x021D7CD4 is also a Thumb game function in overlapping ov120 (packet
 * pkt_021D7CD4); this ARM copy is the ov125 SDK one, hence the ov-qualified
 * packet and file names.
 * The neighbouring leaf wrappers GDS_SOCKET_Lock and GDS_SOCKET_Unlock load the
 * same pointer and tail-call OS_LockMutex / OS_UnlockMutex.
 * If the object's 0x800 field is set, hand it to GDS_SOCKET_Free and clear it.
 *
 * symbols:
 *   func_02086078  0x02086078  arm
 *   gGdsSocketMutex     0x021DA174  data  a4
 *   OS_InitMutex  0x02086004  arm
 *   OS_IsTickAvailable 0x02087058 arm
 *   OS_InitTick 0x02086FE8 arm
 *   gGdsSocket 0x021D9E40 data a4
 *   GDS_SOCKET_RunConnection  0x021D7874  arm  ov125
 *   gGdsConnectThread 0x021DA0B4 data a4
 *   gGdsConnectThreadStackTop 0x021D9640 data a4
 *   SOC_GetHostByName 0x0215F650 arm ov009
 *   func_0215FA9C 0x0215FA9C arm ov009
 *   gGdsHostName 0x021D9F80 data a4
 *   gGdsSslConnection 0x021DA258 data a4
 *   func_0215F428 0x0215F428 arm ov009
 *   CPS_Resolve 0x0215C910 arm ov009
 *   func_0215FC80 0x0215FC80 arm ov009
 *   SOC_Shutdown 0x0215F638 arm ov009
 *   SOC_Close 0x0215F644 arm ov009
 *   gGdsHostTail 0x021DA040 data a4
 *   OS_GetTick 0x020870D0 arm
 *   _ll_udiv 0x0209C00C arm
 *   func_0215F480 0x0215F480 arm ov009
 *   GDS_SOCKET_Lock 0x021D7CAC arm ov125
 *   func_0215F590 0x0215F590 arm ov009
 *   func_0215F4DC 0x0215F4DC arm ov009
 *   d_021D9E40b 0x021D9E40 data a4
 *   gGdsReceiveThread 0x021DA18C data a4 ov125
 *   OS_CreateThread 0x020853C0 arm
 *   OS_WakeupThreadDirect 0x02085868 arm
 *   OS_DestroyThread 0x020855BC arm
 *   OS_Sleep  0x02085A38  arm
 *   func_02167FA8 0x02167FA8 arm ov009
 *   func_02168040 0x02168040 arm ov009
 *   func_02059E38 0x02059E38 arm
 *   sGdsSvlService 0x021D8D30 data a4
 *   GDS_SOCKET_Start  0x021D7770  arm
 *   GDS_SOCKET_Reset  0x021D770C  arm ov125
 *   GDS_SOCKET_GetStateUnlocked 0x021D7BCC arm ov125
 *   GDS_SOCKET_GetErrorUnlocked  0x021D7C48  arm  ov125
 *   GDS_SOCKET_GetReplyUnlocked  0x021D7BDC  arm ov125
 *   GDS_SOCKET_GetReplySizeUnlocked  0x021D7C14  arm ov125
 *   GDS_SOCKET_SendRequest 0x021D7A10 arm ov125
 *   sGdsRequestIds 0x021D8CD0 data a4
 *   OS_GetLowEntropyData 0x02088168 arm
 *   CPS_SslAddRandomSeed 0x02162248 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   gGdsEntropyBuffer 0x021DAA8C data a4
 *   gGdsSslTemplatePtr 0x021DAA88 data a4
 *   gGdsSslTemplate 0x021DAAAC data a4
 *   sGdsRootCaList 0x021D8D38 data a4
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_0208CC78 0x0208CC78 arm
 *   GDS_SOCKET_Alloc 0x021D7C7C arm ov125
 *   STD_CopyString 0x0208CADC arm
 *   GDS_SOCKET_Free  0x021D7C90  arm  ov125
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed int s32;
typedef signed short s16;

#include "gds_rap_types.h"
#include "../ov009/cps_ssl_types.h"
#include "../ov009/qr2_types.h"

typedef unsigned long u32_021D8438;

typedef struct GdsRequestIdTable { int ids[8]; } GdsRequestIdTable;

extern void OS_UnlockMutex(void *mutex);
extern void OS_InitMutex(void *mutex);
extern int OS_IsTickAvailable(void);
extern void OS_InitTick(void);
extern void GDS_SOCKET_RunConnection(void);
extern void OS_CreateThread(void *thread, void (*func)(void *), int arg, void *stack, int stackSize, unsigned priority);
extern void OS_WakeupThreadDirect(void *thread);
extern SOCHostEnt *SOC_GetHostByName(const char *name);
extern char *SOC_InetNtoA(SOCInAddr addr);
extern char *func_02094798(char *dst, const char *src);
extern int SOC_Socket(int family, int type, int protocol);
extern unsigned long CPS_Resolve(char *name);
extern int SOCL_EnableSsl(int socket, CPSSslConnection *con);
extern int SOC_Shutdown(int socket, int how);
extern int SOC_Close(int socket);
extern u64 OS_GetTick(void);
extern int SOC_Connect(int socket, const SOCSockAddrIn *address);
extern void GDS_SOCKET_Lock(void);
extern int SOC_Send(int socket, void *buf, int len, int flags);
extern int SOC_Recv(int socket, void *buf, int len, int flags);
extern void OS_DestroyThread(void *thread);
extern void OS_Sleep(u32_021D8438 msec);
extern int DWC_SVLGetTokenAsync(const char *svl, DWCSvlResult *result);
extern int DWC_SVLProcess(void);
extern int DWC_GetLastErrorEx(int *errorCode, int *errorType);
extern void GDS_SOCKET_Start(const char *host, int port, GdsClientInfo *client);
extern void GDS_SOCKET_Reset(void);
extern unsigned GDS_SOCKET_GetStateUnlocked(void);
extern int GDS_SOCKET_GetErrorUnlocked(void);
extern void *GDS_SOCKET_GetReplyUnlocked(void);
extern int GDS_SOCKET_GetReplySizeUnlocked(void);
extern int GDS_SOCKET_SendRequest(int requestId, void *body, void *replyBuffer, int bodySize);
extern void *func_02092344(void *dest, const void *src, unsigned int n);
extern void OS_GetLowEntropyData(u32 *buffer);
extern void CPS_SslAddRandomSeed(void *seed, u32 size);
extern void MI_CpuFill8(void *dst, u32 value, u32 size);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern u32 STD_GetStringLength(const char *s);
extern char *GDS_SOCKET_Alloc(u32 size);
extern char *STD_CopyString(char *dst, const char *src);
void GDS_SOCKET_Free(int ptr);
void GDS_SOCKET_Unlock(void);
int func_021D7CD4(void);
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
void GDS_SOCKET_Begin(GdsClientInfo *client, const char *host, int port);
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
/* The connection object and the port tail are declared as unsized arrays: the
 * image addresses them that way here (a plain object compiles differently). */
extern GdsSocket gGdsSocket[];
extern struct GdsHostTail gGdsHostTail[];
extern char gGdsSocketMutex[];
extern char gGdsConnectThread[];
extern char gGdsConnectThreadStackTop[];
extern char gGdsHostName[];
extern CPSSslConnection gGdsSslConnection;
extern GdsSocket d_021D9E40b;
extern char gGdsReceiveThread[];
extern const char sGdsSvlService[];
extern const GdsRequestIdTable sGdsRequestIds;
extern u32 gGdsEntropyBuffer[8];
extern CPSSslConnection gGdsSslTemplate;
extern CPSSslConnection *gGdsSslTemplatePtr;
extern SOCLCaInfo *sGdsRootCaList[];


void GDS_SOCKET_Unlock(void)
{
    OS_UnlockMutex(gGdsSocketMutex);
}


int func_021D7CD4(void)
{
    OS_InitMutex(gGdsSocketMutex);
    return 1;
}





int GDS_SOCKET_Nop(void *p){return 1;}





int GDS_SOCKET_InitTick(void){if(!OS_IsTickAvailable())OS_InitTick();gGdsSocket->threadPriority=16;return 1;}




void GDS_SOCKET_NopVoid(void){}




void GDS_SOCKET_ThreadEntry(void *p)
{
    GDS_SOCKET_RunConnection();
}








int GDS_SOCKET_StartThread(void) {
 OS_CreateThread(gGdsConnectThread, GDS_SOCKET_ThreadEntry, 0, gGdsConnectThreadStackTop, 0x800, gGdsSocket->threadPriority);
 OS_WakeupThreadDirect(gGdsConnectThread);
 return 1;
}









int GDS_SOCKET_IsDottedQuad(const char *s) {
 int digits=0, dots=0;
 while (*s) {
  if (*s >= '0' && *s <= '9') {
   if (++digits >= 4) return 0;
  } else if (*s == '.') {
   if (digits == 0) return 0;
   ++dots;
   digits=0;
   if(dots >= 4) return 0;
  } else return 0;
  ++s;
 }
 if(dots==3 && digits!=0) return 1;
 return 0;
}









int GDS_SOCKET_ResolveHost(const char *name, char *out) {
 SOCHostEnt *host;
 if (!GDS_SOCKET_IsDottedQuad(name)) {
  host=SOC_GetHostByName(name);
  if (host) {
   func_02094798(out, SOC_InetNtoA(*(SOCInAddr *)host->addrList[0]));
  } else return 0;
 } else {
  func_02094798(out,name);
 }
 return 1;
}







/*
 * lever: final halfword swap ORs the right-shifted half before the left-shifted half; reversing them left two byte mismatches.
 */
int GDS_SOCKET_OpenAndResolve(void)
{
    char address[16];
    u32 value;
    gGdsSocket->socket = SOC_Socket(2, 1, 0);
    if (gGdsSocket->socket == -1) {
        gGdsSocket->errorCode = 3;
        return 0;
    }
    if (!GDS_SOCKET_ResolveHost(gGdsHostName, address)) {
        gGdsSocket->errorCode = 5;
        return 0;
    }
    value = CPS_Resolve(address);
    value = ((value >> 8) & 0x00ff00ff) | ((value << 8) & 0xff00ff00);
    gGdsSocket->serverAddress = (value >> 16) | (value << 16);
    GDS_SOCKET_CopySslTemplate(gGdsHostName, &gGdsSslConnection);
    if (SOCL_EnableSsl(gGdsSocket->socket, &gGdsSslConnection) < 0) {
        gGdsSocket->errorCode = 15;
        return 0;
    }
    return 1;
}






void GDS_SOCKET_Close(void) {
 if (gGdsSocket->socket == -1) return;
 SOC_Shutdown(gGdsSocket->socket, 2);
 SOC_Close(gGdsSocket->socket);
 gGdsSocket->socket = -1;
 GDS_SOCKET_FreeSslServerName(&gGdsSslConnection);
}






/*
 * lever: port byte swap keeps both explicit masks; timeout casts after unsigned 64-bit subtraction, preserving the original subs before the signed comparison.
 */
int GDS_SOCKET_Connect(void)
{
    SOCSockAddrIn address;
    int start, result;
    address.len = 8;
    address.family = 2;
    address.port = ((gGdsHostTail->port >> 8) & 0xff) | ((gGdsHostTail->port << 8) & 0xff00);
    address.addr.addr = gGdsSocket->serverAddress;
    start = OS_GetTick() / 0x7fd88;
    for (;;) {
        result = SOC_Connect(gGdsSocket->socket, &address);
        if (result >= 0) break;
        if (result == -26) {
            if (gGdsSocket->connectTimeout != 0 && (int)((OS_GetTick() / 0x7fd88) - start) >= gGdsSocket->connectTimeout) {
                gGdsSocket->errorCode = 10;
                return 0;
            }
        } else {
            if (result == -30) break;
            gGdsSocket->errorCode = 7;
            return 0;
        }
        GDS_SOCKET_Lock();
        if (gGdsSocket->cancelRequested == 1) {
            gGdsSocket->errorCode = GDS_SOCKET_ERROR_ABORTED;
            GDS_SOCKET_Unlock();
            return 0;
        }
        GDS_SOCKET_Unlock();
        GDS_SOCKET_Sleep(1);
    }
    return 1;
}







int GDS_SOCKET_Send(void)
{
    int start, count = 0, length, result;
    start = OS_GetTick() / 0x7fd88;
    for (;;) {
        length = gGdsSocket->sendSize - count;
        if (length > gGdsSocket->sendSize) length = gGdsSocket->sendSize;
        result = SOC_Send(gGdsSocket->socket, gGdsSocket->sendBuffer + count, length, 0);
        if (result != -6) {
            if (result < 0) {
                gGdsSocket->errorCode = 11;
                return 0;
            }
            count += result;
            if (count == gGdsSocket->sendSize) break;
        }
        if (gGdsSocket->sendTimeout != 0 && (int)((OS_GetTick() / 0x7fd88) - start) >= gGdsSocket->sendTimeout) {
            gGdsSocket->errorCode = 11;
            return 0;
        }
        GDS_SOCKET_Lock();
        if (gGdsSocket->cancelRequested == 1) {
            gGdsSocket->errorCode = GDS_SOCKET_ERROR_ABORTED;
            GDS_SOCKET_Unlock();
            return 0;
        }
        GDS_SOCKET_Unlock();
        GDS_SOCKET_Sleep(1);
    }
    return 1;
}







void GDS_SOCKET_ReceiveThread(void *arg)
{
    int count;
    for (;;) {
        count = gGdsSocket->receiveCount;
        GDS_SOCKET_Lock();
        if (!gGdsSocket->receiveReady) {
            gGdsSocket->receiveResult = SOC_Recv(gGdsSocket->socket, gGdsSocket->receiveBuffer + count, gGdsSocket->receiveSize - count, 0);
            gGdsSocket->receiveReady = 1;
        }
        GDS_SOCKET_Unlock();
        GDS_SOCKET_Sleep(1);
    }
}







int GDS_SOCKET_Receive(void)
{
    u32 count = 0;
    int zero = 0;
    u32 word = -1;
    int start;
    int r;
    u64 t0;
    int ret = 0;

    t0 = OS_GetTick();
    OS_CreateThread(gGdsReceiveThread, GDS_SOCKET_ReceiveThread, 0, &d_021D9E40b, 0x800, gGdsSocket->threadPriority);
    gGdsSocket->receiveResult = -6;
    gGdsSocket->receiveCount = 0;
    gGdsSocket->receiveReady = 0;
    OS_WakeupThreadDirect(gGdsReceiveThread);
    start = t0 / 0x7fd88;
    for (;;) {
        if (gGdsSocket->receiveTimeout != 0 && (int)((OS_GetTick() / 0x7fd88) - start) >= gGdsSocket->receiveTimeout) {
            gGdsSocket->errorCode = 12;
            OS_DestroyThread(gGdsReceiveThread);
            return ret;
        }
        if (gGdsSocket->receiveReady == 0) {
            continue;
        }
        r = gGdsSocket->receiveResult;
        if (r != -6) {
            if (r <= 0) {
                gGdsSocket->errorCode = 9;
                OS_DestroyThread(gGdsReceiveThread);
                return 0;
            }
            count += r;
            if (count >= 4 && word == -1) {
                u8 *h = (u8 *)&word;
                u8 *q = gGdsSocket->receiveBuffer;
                h[0] = q[0]; h[1] = q[1]; h[2] = q[2]; h[3] = q[3];
            }
            if (count == word) {
                if (word != -1) {
                    gGdsSocket->receiveSize = word - 4;
                    break;
                }
            }
            gGdsSocket->receiveCount = count;
        }
        GDS_SOCKET_Lock();
        if (gGdsSocket->cancelRequested == 1) {
            gGdsSocket->errorCode = GDS_SOCKET_ERROR_ABORTED;
            GDS_SOCKET_Unlock();
            OS_DestroyThread(gGdsReceiveThread);
            return 0;
        }
        GDS_SOCKET_Unlock();
        gGdsSocket->receiveReady = zero;
        GDS_SOCKET_Sleep(1);
    }
    OS_DestroyThread(gGdsReceiveThread);
    return 1;
}









/*
 * ARM tail call: ldr ip, =target; bx ip (the form mwcc emits, as in ov009 DWCi_ProcessMatchSynPacketSub.c).
 */
void GDS_SOCKET_Sleep(int msec)
{
    OS_Sleep(msec);
}









#pragma opt_propagation off








int GDS_SOCKET_WaitToken(void)
{
    DWCSvlResult svl;
    int errorType, errorCode;
    int r;

    if (gGdsSocket->tokenReady == 1)
        return 1;
    if (DWC_SVLGetTokenAsync(sGdsSvlService, &svl) == 0) {
        gGdsSocket->errorCode = 0xE;
        return 0;
    }
    for (;;) {
        r = DWC_SVLProcess();
        if (r == 3) {
            GdsSvlToken *token = &gGdsSocket->client.svlToken;
            *token = *(GdsSvlToken *)svl.svlToken;
            *(GdsClientInfo *)(gGdsSocket->sendBuffer + 8) = gGdsSocket->client;
            gGdsSocket->tokenReady = 1;
            return 1;
        }
        if (r == 4) {
            DWC_GetLastErrorEx(&errorCode, &errorType);
            gGdsSocket->errorCode = 0xE;
            return 0;
        }
        if (r == 5) {
            gGdsSocket->errorCode = 0xE;
            return 0;
        }
        GDS_SOCKET_Lock();
        if (gGdsSocket->cancelRequested == 1) {
            gGdsSocket->errorCode = 0xD;
            GDS_SOCKET_Unlock();
            return 0;
        }
        GDS_SOCKET_Unlock();
        GDS_SOCKET_Sleep(1);
    }
}








#pragma opt_propagation reset








void GDS_SOCKET_NopBegin(void){}









/*
 * ARM tail call: ldr ip, =target; bx ip.
 */
void GDS_SOCKET_InitSsl(void)
{
    GDS_SOCKET_InitSslTemplate();
}









/*
 * Addresses are Black-image addresses.
 */
void GDS_SOCKET_Begin(GdsClientInfo *client, const char *host, int port)
{
    GDS_SOCKET_Start(host, port, client);
}







void GDS_SOCKET_Shutdown(void)
{
    GDS_SOCKET_Reset();
}





unsigned GDS_SOCKET_GetState(void) {unsigned v;GDS_SOCKET_Lock();v=GDS_SOCKET_GetStateUnlocked();GDS_SOCKET_Unlock();return v;}




int GDS_SOCKET_GetError(void)
{
    return GDS_SOCKET_GetErrorUnlocked();
}









void *GDS_SOCKET_GetReply(void)
{
    return GDS_SOCKET_GetReplyUnlocked();
}










int GDS_SOCKET_GetReplySize(void)
{
    return GDS_SOCKET_GetReplySizeUnlocked();
}










/*
 * ARM tail call: ldr ip, =target; bx ip.
 */
int GDS_SOCKET_GetMaxReplySize(int requestId)
{
    return GDS_SOCKET_GetMaxReplySizeOf(requestId);
}









int GDS_SOCKET_SendUploadEntry(const GdsEntryBlocks *entry, void *replyBuffer) {
 GdsEntryBlocks copy;
 copy = *entry;
 return GDS_SOCKET_SendRequest(GDS_REQUEST_UPLOAD_ENTRY, &copy, replyBuffer, -1);
}









int GDS_SOCKET_SendDownloadEntries(int key, void *replyBuffer) {
 GdsPacketDownload p;
 p.reserved0 = 0; p.reserved1 = 0; p.key = key;
 return GDS_SOCKET_SendRequest(GDS_REQUEST_DOWNLOAD_ENTRIES, &p, replyBuffer, -1);
}









int GDS_SOCKET_SendUploadVideo(const struct BattleRecSave *video, const void *ticket, int ticketLength, void *replyBuffer) {
 GdsPacketUploadVideo p={0};
 if (ticketLength > GDS_TICKET_MAX) return 0;
 p.video = *video;
 p.ticketLength = ticketLength;
 func_02092344(p.ticket, ticket, ticketLength);
 return GDS_SOCKET_SendRequest(GDS_REQUEST_UPLOAD_VIDEO, &p, replyBuffer, -1);
}









/*
 * lever: The source params pointer is non-const; const swaps the initial
 * strh lr,[sp] and mov r4,r1 (six concrete bytes differ).
 */
int GDS_SOCKET_SendSearchByCondition(GdsSearchParams *params, void *replyBuffer) {
 GdsPacketSearch p;
 p.searchKind = 0;
 p.params = *params;
 p.searchKind = 0; p.reserved = 0;
 return GDS_SOCKET_SendRequest(GDS_REQUEST_SEARCH_VIDEOS, &p, replyBuffer, -1);
}









int GDS_SOCKET_SendSearchKind1(int limit, void *replyBuffer) {
 GdsPacketSearch p = {0};
 p.params.limit = limit;
 p.searchKind = GDS_SEARCH_KIND_1; p.tail[0] = 0; p.tail[1] = 0; p.reserved = 0;
 return GDS_SOCKET_SendRequest(GDS_REQUEST_SEARCH_VIDEOS, &p, replyBuffer, -1);
}









int GDS_SOCKET_SendSearchKind3(int limit, void *replyBuffer) {
 GdsPacketSearch p = {0};
 p.params.limit = limit;
 p.searchKind = GDS_SEARCH_KIND_3; p.tail[0] = 0; p.tail[1] = 0; p.reserved = 0;
 return GDS_SOCKET_SendRequest(GDS_REQUEST_SEARCH_VIDEOS, &p, replyBuffer, -1);
}









int GDS_SOCKET_SendSearchKind2(int limit, void *replyBuffer) {
 GdsPacketSearch p = {0};
 p.params.limit = limit;
 p.searchKind = GDS_SEARCH_KIND_2; p.tail[0] = 0; p.tail[1] = 0; p.reserved = 0;
 return GDS_SOCKET_SendRequest(GDS_REQUEST_SEARCH_VIDEOS, &p, replyBuffer, -1);
}








int GDS_SOCKET_SendGetVideo(u32 dataNumberLo, u32 dataNumberHi, u32 version, void *replyBuffer)
{
    GdsPacketGetVideo p;
    p.dataNumberLo=dataNumberLo; p.dataNumberHi=dataNumberHi; p.version=version;
    return GDS_SOCKET_SendRequest(GDS_REQUEST_GET_VIDEO, &p, replyBuffer, -1);
}








int GDS_SOCKET_SendMarkVideo(u32 dataNumberLo, u32 dataNumberHi, void *replyBuffer)
{
    GdsPacketMarkVideo p;
    p.dataNumberLo=dataNumberLo; p.dataNumberHi=dataNumberHi;
    return GDS_SOCKET_SendRequest(GDS_REQUEST_MARK_VIDEO, &p, replyBuffer, -1);
}








int GDS_SOCKET_GetRequestSize(int requestId)
{
    int size;
    switch (requestId) {
    case 0: size = 0x400; break;
    case GDS_REQUEST_UPLOAD_ENTRY: size = sizeof(GdsEntryBlocks); break;
    case GDS_REQUEST_DOWNLOAD_ENTRIES: size = sizeof(GdsPacketDownload); break;
    case GDS_REQUEST_UPLOAD_VIDEO: size = sizeof(GdsPacketUploadVideo); break;
    case GDS_REQUEST_SEARCH_VIDEOS: size = sizeof(GdsPacketSearch); break;
    case GDS_REQUEST_GET_VIDEO: size = sizeof(GdsPacketGetVideo); break;
    case GDS_REQUEST_MARK_VIDEO: size = sizeof(GdsPacketMarkVideo); break;
    default: return -1;
    }
    return size + GDS_WIRE_HEADER_SIZE;
}








int GDS_SOCKET_GetMaxReplySizeOf(int requestId)
{
    GdsRequestIdTable table = sGdsRequestIds;
    int size;
    int i;
    int got;
    switch (requestId) {
    case -1:
        size = -1;
        for (i = 0; ; i++) {
            if (table.ids[i] == -1) break;
            got = GDS_SOCKET_GetMaxReplySizeOf(table.ids[i]);
            if (got > size) size = got;
        }
        if (size == -1) return -1;
        break;
    case 0: size = 0x400; break;
    case GDS_REQUEST_UPLOAD_ENTRY: size = 8; break;
    case GDS_REQUEST_DOWNLOAD_ENTRIES: size = sizeof(u32) + GDS_DOWNLOAD_MAX * sizeof(GdsDownloadEntry); break;
    case GDS_REQUEST_UPLOAD_VIDEO: size = 8; break;
    case GDS_REQUEST_SEARCH_VIDEOS: size = sizeof(u32) + GDS_SEARCH_MAX * sizeof(GdsListingEntry); break;
    case GDS_REQUEST_GET_VIDEO: size = sizeof(GdsVideoEntry); break;
    case GDS_REQUEST_MARK_VIDEO: size = 0; break;
    default: return -1;
    }
    return size + 8;
}








/*
 * extent: eight-byte leaf ends at the handed lead 0x021D8B44.
 */
int GDS_SOCKET_SslAuthCallback(int result, CPSSslConnection *con, int level) { return 0; }







void GDS_SOCKET_InitSslTemplate(void)
{
    OS_GetLowEntropyData(gGdsEntropyBuffer);
    CPS_SslAddRandomSeed(gGdsEntropyBuffer, 32);
    if (gGdsSslTemplatePtr) return;
    MI_CpuFill8(&gGdsSslTemplate, 0, sizeof(CPSSslConnection));
    gGdsSslTemplate.f800 = 0;
    GDS_SOCKET_SetSslTemplate(&gGdsSslTemplate);
    GDS_SOCKET_SetRootCa(sGdsRootCaList, 1);
    GDS_SOCKET_SetSslAuthCallback(GDS_SOCKET_SslAuthCallback);
}







void GDS_SOCKET_SetSslTemplate(CPSSslConnection *con)
{
    if (con != 0) gGdsSslTemplatePtr = con;
    else gGdsSslTemplatePtr = &gGdsSslTemplate;
}






void GDS_SOCKET_SetSslAuthCallback(int (*callback)(int, CPSSslConnection *, int))
{
    gGdsSslTemplatePtr->f810 = callback;
}





/*
 * Addresses are Black-image addresses.
 */
void GDS_SOCKET_SetRootCa(SOCLCaInfo **rootCa, int count)
{
    gGdsSslTemplatePtr->rootCa = rootCa;
    gGdsSslTemplatePtr->rootCaNum = count;
}



void GDS_SOCKET_CopySslTemplate(const char *host, CPSSslConnection *con)
{
    MI_CpuCopy8(gGdsSslTemplatePtr, con, sizeof(CPSSslConnection));
    if (host) {
        con->f800 = GDS_SOCKET_Alloc(STD_GetStringLength(host) + 1);
        STD_CopyString(con->f800, host);
    }
}


void GDS_SOCKET_FreeSslServerName(CPSSslConnection *con)
{
    char *name;

    name = con->f800;
    if (name == 0)
        return;
    GDS_SOCKET_Free((int)name);
    con->f800 = 0;
}
