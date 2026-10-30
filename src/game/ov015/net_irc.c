/*
 * file:     net_irc.c
 * unit:     yes
 * function: IRCNET_CbInit, IRCNET_CbConnect, IRCNET_CbResend, IRCNET_CbReturnTrue, IRCNET_CbStop, IRCNET_CbIsRunning, IRCNET_IsNotRunning, IRCNET_SendAndNotify, IRCNET_CbSetRecvCallback, IRCNET_CbIsLinkedReceiver, IRCNET_CbIsLinkLost, IRCNET_CbUpdate, IRCNET_CbCanSend, IRCNET_CbIsSendReady, IRCNET_CbHasPeer, IRCNET_CbIsConnected, IRCNET_CbIsLinkAlive, IRCNET_CbGetRunning, IRCNET_CbGetLinkState, IRCNET_CbIsClosing, IRCNET_CbOnConnect, IRCNET_CbSetTimeoutLimit, IRCNET_CbSetFilter, IRCNET_GetHandlerTable, IRCNET_SendPacket, IRCNET_InitWork, IRCNET_SetTimeoutLimit, IRCNET_Stop, IRCNET_SetRecvCallback, IRCNET_SetFilter, IRCNET_Start, IRCNET_IsRunning, IRCNET_IsSendReady, IRCNET_IsClosing, IRCNET_IsIdle, IRCNET_QueueSend, IRCNET_ResendPending, IRCNET_IsReceiver, IRCNET_OnRecv, IRCNET_IsSender, IRCNET_IsLinkLost, IRCNET_OnConnect, IRCNET_OnPeerFound, IRCNET_GetSenderFlag, IRCNET_IsLinkAlive, IRCNET_HasPeer, IRCNET_IsConnected, IRCNET_Update
 * address:  0x021797C0
 * region:   ov015
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The game's infrared link layer on top of libirc (irc.c): one work block, packets
 * with a sequence nibble pair, resend on a missed acknowledgement.
 *
 * symbols:
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *   gIrcNetHandlerTable  0x0217A9E0  data  a4
 *   gIrcNetAssertText  0x0217AAAC  data  ov015  a1
 *   gIrcNetWork  0x0217AAC0  data  ov015  a4
 *   GF_PANIC_Fail  0x02034714  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   GF_STANDARD_CalcCrc16  0x0203F1FC  arm
 *   WM_GetNextTgid  0x0208F1B4  arm
 *   GFL_USE_GetRandom  0x020056EC  thumb
 *   GFL_NET_HANDLE_RemoveHandle  0x0203A338  arm
 *   _u32_div_f  0x0209C2B0  arm
 *   IRC_Init  0x02179F74  arm  ov015
 *   IRC_Connect  0x02179FC4  arm  ov015
 *   IRC_IsSender  0x0217A014  arm  ov015
 *   IRC_IsConnect  0x0217A024  arm  ov015
 *   IRC_Shutdown  0x0217A134  arm  ov015
 *   IRC_Send  0x0217A148  arm  ov015
 *   IRC_Move  0x0217A334  arm  ov015
 *   IRC_SetRecvCallback  0x0217A584  arm  ov015
 *   IRC_GetUnitNumber  0x0217A5A4  arm  ov015
 */
#include "../types.h"
#include "../version.h"

#include "net_irc_types.h"
#include "../arm9/net_types.h"

extern IRCNetWork gIrcNetWork;
extern u8 gIrcNetAssertText[];
extern u8 gIrcNetHandlerTable[];

#include "../arm9/net.h"
#include "../arm9/gf_panic.h"
#include "../arm9/mi_memory.h"
#include "../arm9/gf_standard.h"
#include "../arm9/wm_sync.h"
#include "../arm9/gfl_use.h"
#include "../arm9/net_handle.h"
#include "irc.h"
#if LANGUAGE == LANGUAGE_JAPANESE
extern const char str_ja_0217A98C[];
extern const char str_ja_0217A998[];
extern const char str_ja_0217A9B0[];
extern const char str_ja_0217A9D0[];
extern const char str_ja_0217A9EC[];
#endif

void IRCNET_OnRecv(u8 *pkt, u8 len, u8 type, u8 id);
int IRCNET_IsLinkAlive(void);
int IRCNET_IsLinkLost(void);
void IRCNET_Update(void);
u8 IRCNET_HasPeer(void);
int IRCNET_IsConnected(void);
void IRCNET_OnConnect(void);
void IRCNET_OnPeerFound(void);
int IRCNET_IsReceiver(void);
u8 IRCNET_IsSendReady(void);
u8 IRCNET_IsClosing(void);
int IRCNET_IsIdle(void);
void IRCNET_QueueSend(void *dst, u8 a, u8 b);
void IRCNET_ResendPending(void);
void IRCNET_SendPacket(void *dst, int n, u8 a, u8 b);
void IRCNET_InitWork(u32 a, u8 b);
void IRCNET_SetTimeoutLimit(int v);
void IRCNET_Stop(void);
void IRCNET_SetRecvCallback(IRCNetRecvFn v);
void IRCNET_SetFilter(IRCNetFilterFn a);
void IRCNET_Start(void);
unsigned char IRCNET_IsRunning(void);
extern unsigned char IRCNET_GetSenderFlag(void);
int IRCNET_IsSender(void);

int IRCNET_CbInit(void)
{
    GFLNetSession *a = GFL_NET_GetInitParam();
    GFLNetSession *b = GFL_NET_GetInitParam();

    IRCNET_InitWork(*(u32 *)b->init.reserved68, a->init.gameKind);
    IRCNET_Start();
    return 1;
}

int IRCNET_CbConnect(void)
{
    IRC_Connect();
    return 1;
}

int IRCNET_CbResend(void)
{
    IRCNET_ResendPending();
    return 0;
}

int IRCNET_CbReturnTrue(void)
{
    return 1;
}

int IRCNET_CbStop(void)
{
    IRCNET_Stop();
    return 1;
}

unsigned char IRCNET_CbIsRunning(void)
{
    return IRCNET_IsRunning();
}

int IRCNET_IsNotRunning(void)
{
    if (IRCNET_IsRunning() == 0)
        return 1;
    return 0;
}

int IRCNET_SendAndNotify(void *dst, int a, int unused, void (*cb)(int))
{
    IRCNET_QueueSend(dst, (u8)a, 0);
    if (cb != 0)
        cb(1);
    return 1;
}

int IRCNET_CbSetRecvCallback(IRCNetRecvFn v)
{
    IRCNET_SetRecvCallback(v);
    return 1;
}

int IRCNET_CbIsLinkedReceiver(void)
{
    if (IRCNET_IsLinkAlive())
        return IRCNET_IsReceiver();
    return 0;
}

int IRCNET_CbIsLinkLost(void)
{
    return IRCNET_IsLinkLost();
}

void IRCNET_CbUpdate(void)
{
    IRCNET_Update();
}

int IRCNET_CbCanSend(void)
{
    return IRCNET_IsIdle();
}

unsigned char IRCNET_CbIsSendReady(void)
{
    return IRCNET_IsSendReady();
}

unsigned char IRCNET_CbHasPeer(void)
{
    return IRCNET_HasPeer();
}

int IRCNET_CbIsConnected(void)
{
    return IRCNET_IsConnected();
}

int IRCNET_CbIsLinkAlive(void)
{
    return IRCNET_IsLinkAlive();
}

unsigned char IRCNET_CbGetRunning(void)
{
    return IRCNET_IsRunning();
}

int IRCNET_CbGetLinkState(void)
{
    if (IRCNET_IsLinkAlive())
        return 3;
    return 0;
}

unsigned char IRCNET_CbIsClosing(void)
{
    return IRCNET_IsClosing();
}

void IRCNET_CbOnConnect(void)
{
    IRCNET_OnConnect();
}

void IRCNET_CbSetTimeoutLimit(int v)
{
    IRCNET_SetTimeoutLimit(v);
}

void IRCNET_CbSetFilter(IRCNetFilterFn a)
{
    IRCNET_SetFilter(a);
}

/* Returns the IRCNet handler table at 0x0217A9E0 (204 bytes, 51 function
 * pointers; layout/data_objects.json lists it as a 51-entry numeric pool). */
void *IRCNET_GetHandlerTable(void)
{
    return gIrcNetHandlerTable;
}

void IRCNET_SendPacket(void *dst, int n, u8 a, u8 b)
{
    if ((unsigned)n >= 0xA6)
        GF_PANIC_Fail(PM_LANG_JA((const char *)gIrcNetAssertText, str_ja_0217A98C), PM_SRC_LINE(0, 0x8C), PM_LANG_JA((const char *)gIrcNetAssertText, str_ja_0217A998));
    gIrcNetWork.packet.type = a;
    gIrcNetWork.packet.seq = b;
    if (dst != 0)
        MI_CpuCopy8(dst, gIrcNetWork.packet.payload, 0xA6);
    gIrcNetWork.packet.checksum = GF_STANDARD_CalcCrc16(&gIrcNetWork.packet.type, n + 12);
    IRC_Send((u8 *)&gIrcNetWork.packet, (u8)(n + 14), a);
}

void IRCNET_InitWork(u32 a, u8 b)
{
    MI_CpuFill8(&gIrcNetWork, 0, sizeof(gIrcNetWork));
    gIrcNetWork.timeoutLimit = a;
    gIrcNetWork.randomByte = WM_GetNextTgid();
    IRC_Init(3);
    IRC_SetRecvCallback(IRCNET_OnRecv);
    gIrcNetWork.packet.senderId = GFL_USE_GetRandom(0);
    if (gIrcNetWork.packet.senderId == 0)
        gIrcNetWork.packet.senderId = 1;
    gIrcNetWork.packet.groupId = b;
}

void IRCNET_SetTimeoutLimit(int v)
{
    gIrcNetWork.timeoutLimit = v;
}

void IRCNET_Stop(void)
{
    if (gIrcNetWork.isRunning == 1)
        IRC_Shutdown();
    gIrcNetWork.isRunning = 0;
}

void IRCNET_SetRecvCallback(IRCNetRecvFn v)
{
    gIrcNetWork.recvCallback = v;
}

void IRCNET_SetFilter(IRCNetFilterFn a)
{
    gIrcNetWork.filter = a;
}

void IRCNET_Start(void)
{
    if (gIrcNetWork.isRunning != 0)
        GF_PANIC_Fail(PM_LANG_JA((const char *)gIrcNetAssertText, str_ja_0217A98C), PM_SRC_LINE(0, 0xF3), PM_LANG_JA((const char *)gIrcNetAssertText, str_ja_0217A9B0));
    gIrcNetWork.isRunning = 1;
}

unsigned char IRCNET_IsRunning(void)
{
    return gIrcNetWork.isRunning;
}

u8 IRCNET_IsSendReady(void)
{
    return gIrcNetWork.isSendReady;
}

u8 IRCNET_IsClosing(void)
{
    return gIrcNetWork.isClosing;
}

int IRCNET_IsIdle(void)
{
    if (gIrcNetWork.isSendReady == 1 && gIrcNetWork.isClosing == 0 && gIrcNetWork.linkTimer == 0 && gIrcNetWork.waitingAck == 0)
        return 1;
    return 0;
}

void IRCNET_QueueSend(void *dst, u8 a, u8 b)
{
    if (gIrcNetWork.isSendReady != 1)
        GF_PANIC_Fail(PM_LANG_JA((const char *)gIrcNetAssertText, str_ja_0217A98C), PM_SRC_LINE(0, 0x137), PM_LANG_JA((const char *)gIrcNetAssertText, str_ja_0217A9D0));
    IRCNET_SendPacket(dst, a, b, (u8)(gIrcNetWork.sendSeq | (gIrcNetWork.recvSeq << 4)));
    gIrcNetWork.pendingData = dst;
    gIrcNetWork.pendingSize = a;
    gIrcNetWork.pendingType = b;
    gIrcNetWork.resendSeq = gIrcNetWork.sendSeq;
    gIrcNetWork.waitingAck = 1;
    gIrcNetWork.isSendReady = 0;
}

void IRCNET_ResendPending(void)
{
    IRCNetWork *w = &gIrcNetWork;

    if (w->isSendReady == 1) {
        if (w->needResend == 1) {
            IRCNET_SendPacket(w->pendingData, w->pendingSize, w->pendingType, w->resendSeq | (gIrcNetWork.recvSeq << 4));
            w->needResend = 0;
        } else {
            IRCNET_SendPacket(0, 0, IRC_CMD_KEEPALIVE, w->resendSeq | (gIrcNetWork.recvSeq << 4));
        }
        w->isSendReady = 0;
    }
}

int IRCNET_IsReceiver(void)
{
    if (gIrcNetWork.isSenderRole != 1)
        return 1;
    return 0;
}

/*
 * Receive handler for one packet: rejects a length of 0 or over 0xB4 (the over-length case also
 * reports through GF_PANIC_Fail), checks the checksum against GF_STANDARD_CalcCrc16 over the rest, filters
 * on the group id (through the optional hook), tracks the two session ids, then hands the payload
 * to the receive callback once per new sequence number.
 */
void IRCNET_OnRecv(u8 *rawPacket, u8 len, u8 type, u8 id)
{
    IRCNetPacket *pkt = (IRCNetPacket *)rawPacket;
    u8 unused[6] = {0, 0, 0, 0, 0, 0};
    int lo;
    int hi;
    IRCNetFilterFn filter;
    IRCNetRecvFn recv;

    lo = pkt->seq & 0xF;
    hi = pkt->seq >> 4;
    gIrcNetWork.isSendReady = 1;
    if (len > 0xB4)
        GF_PANIC_Fail(PM_LANG_JA((const char *)gIrcNetAssertText, str_ja_0217A98C), PM_SRC_LINE(0, 0x19E), PM_LANG_JA((const char *)gIrcNetAssertText, str_ja_0217A9EC));
    if (!(len != 0 && len <= 0xB4))
        return;
    if (pkt->checksum != GF_STANDARD_CalcCrc16(rawPacket + 2, len - 2))
        return;
    filter = gIrcNetWork.filter;
    if (filter != 0) {
        if (!filter(gIrcNetWork.packet.groupId, pkt->groupId))
            return;
    } else {
        if (gIrcNetWork.packet.groupId != pkt->groupId)
            return;
    }
    if (pkt->targetId == gIrcNetWork.packet.senderId && pkt->senderId == gIrcNetWork.peerSessionId) {
        if (!gIrcNetWork.hasPeer) {
            IRCNET_OnPeerFound();
            gIrcNetWork.hasPeer = 1;
        }
    } else if (pkt->targetId == 0 && gIrcNetWork.peerSessionId == 0) {
        gIrcNetWork.packet.targetId = pkt->senderId;
        gIrcNetWork.peerSessionId = pkt->senderId;
        return;
    } else if (pkt->targetId == gIrcNetWork.packet.senderId && gIrcNetWork.peerSessionId == 0) {
        gIrcNetWork.packet.targetId = pkt->senderId;
        gIrcNetWork.peerSessionId = pkt->senderId;
    } else {
        if (gIrcNetWork.hasPeer)
            return;
        if (gIrcNetWork.peerSessionId == pkt->senderId)
            return;
        gIrcNetWork.peerSessionId = 0;
        return;
    }
    if (type >= 0xF0)
        return;
    if (gIrcNetWork.waitingAck == 1 && gIrcNetWork.needResend == 0) {
        if (hi == gIrcNetWork.sendSeq) {
            if (gIrcNetWork.sendSeq < 0xF)
                gIrcNetWork.sendSeq = gIrcNetWork.sendSeq + 1;
            else
                gIrcNetWork.sendSeq = 0;
            gIrcNetWork.waitingAck = 0;
        } else {
            gIrcNetWork.needResend = 1;
        }
    }
    if (type == IRC_CMD_KEEPALIVE)
        return;
    if (gIrcNetWork.recvSeq == lo)
        return;
    {
        int id = IRCNET_IsSender();
        recv = gIrcNetWork.recvCallback;
        if (recv == 0 || recv((u16)id, pkt->payload, (u16)(len - 0xE)) != 0)
            gIrcNetWork.recvSeq = lo;
    }
}

int IRCNET_IsSender(void)
{
    if (IRCNET_GetSenderFlag() == 1)
        return 1;
    return 0;
}

int IRCNET_IsLinkLost(void)
{
    if (gIrcNetWork.isRunning == 0)
        return 0;
    if (gIrcNetWork.hasFailed != 0)
        return 1;
    if (gIrcNetWork.isActive == 1) {
        if (IRCNET_IsLinkAlive() == 0)
            return 1;
    }
    return 0;
}

void IRCNET_OnConnect(void)
{
    gIrcNetWork.isSenderRole = IRC_IsSender();
    gIrcNetWork.unitNumber = IRC_GetUnitNumber();
    gIrcNetWork.isActive = 1;
    gIrcNetWork.sendSeq = 0;
    gIrcNetWork.recvSeq = 14;
    if (gIrcNetWork.isSenderRole != 1)
        gIrcNetWork.isSendReady = 1;
}

void IRCNET_OnPeerFound(void)
{
    gIrcNetWork.isSenderRole = IRC_IsSender();
    gIrcNetWork.unitNumber = IRC_GetUnitNumber();
}

u8 IRCNET_GetSenderFlag(void)
{
    return gIrcNetWork.isSenderRole;
}

int IRCNET_IsLinkAlive(void)
{
    u32 limit;
    u32 timer;

    if (IRC_IsConnect() == 1)
        return 1;
    limit = gIrcNetWork.timeoutLimit;
    timer = gIrcNetWork.linkTimer;
    if (timer < limit || (timer == 0 && limit == 0))
        return 1;
    return 0;
}

u8 IRCNET_HasPeer(void)
{
    return gIrcNetWork.hasPeer;
}

int IRCNET_IsConnected(void)
{
    return IRC_IsConnect();
}

void IRCNET_Update(void)
{
    IRCNetWork *w = &gIrcNetWork;

    if (w->isActive != 0 || w->linkTimer < w->timeoutLimit || w->linkTimer == 0) {
        if (w->linkTimer == 0)
            IRC_Move();
        if (w->isActive != 1)
            return;
        if (w->linkTimer != 0) {
            if (IRC_IsConnect() == 1) {
                w->linkTimer = 0;
                if (IRC_IsSender() == 1)
                    w->isSendReady = 0;
                else
                    w->isSendReady = 1;
                if (w->waitingAck == 1)
                    w->needResend = 1;
                return;
            }
            if (w->linkTimer < 5) {
                w->linkTimer++;
                return;
            }
            if (w->linkTimer == 5) {
                IRC_Init(3);
                IRC_SetRecvCallback(IRCNET_OnRecv);
                w->linkTimer++;
                return;
            }
            IRC_Move();
            if (w->linkTimer < w->timeoutLimit) {
                if (w->isSenderRole == 1 && w->linkTimer % 5 == 0)
                    IRC_Connect();
                w->linkTimer++;
                return;
            }
            w->isActive = 0;
            w->hasFailed = 1;
            GFL_NET_HANDLE_RemoveHandle(1 - IRCNET_IsReceiver());
            IRC_Shutdown();
        } else {
            if (IRC_IsConnect() != 0)
                return;
            if (w->timeoutLimit != 0) {
                IRC_Shutdown();
                w->linkTimer = 1;
                return;
            }
            w->isActive = 0;
            w->hasFailed = 1;
            w->linkTimer = 0xFFFF;
            GFL_NET_HANDLE_RemoveHandle(1 - IRCNET_IsReceiver());
            IRC_Shutdown();
        }
    }
}
