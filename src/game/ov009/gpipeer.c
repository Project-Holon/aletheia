/*
 * file:     gpipeer.c
 * unit:     yes
 * function: gpiProcessPeerInitiatingConnection, gpiProcessPeerAcceptingConnection, gpiPeerSendMessages, gpiProcessPeerConnected, gpiCheckTimedOutPeerOperations, gpiProcessPeer, gpiDestroyPeer, gpiRemovePeer, gpiProcessPeers, gpiGetPeerByProfile, gpiGetPeerByAddr, gpiFreeMessage, gpiAddPeer, gpiPeerGetSig, gpiPeerStartConnect, gpiPeerAddMessage, gpiPeerStartTransferMessage, gpiPeerFinishTransferMessage, gpiPeerLeftCallback, gpiPeerMessageCallback, gpiPeerAcceptedCallback, gpiPeerPingReplyCallback, gpiPeerAddOp, gpiPeerRemoveOp
 * address:  0x0218E3B0
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * sdk:      gpiPeerPingReplyCallback (libdwcgsgp.TWL.HYB.a(gpipeer.o))
 * notes:    a 4-byte `bx lr`; gpiStartConnect's relocation at +0x3C4
 *           (ABS32 gpiPeerPingReplyCallback) is the pool word at
 *           0x0218A5FC.  Seeded in layout/function_starts.txt.
 *
 * symbols:
 *   gsDebugFormat  0x0217D254  arm  ov009
 *   gsUdpEngineGetPeerState  0x02181010  arm  ov009
 *   gpiGetProfile  0x0218FD9C  arm  ov009
 *   gpiSetErrorString  0x02193734  arm  ov009
 *   gpiAppendStringToBuffer  0x0218946C  arm  ov009
 *   gpiAppendIntToBuffer  0x0218949C  arm  ov009
 *   gsifree  0x0217EAE0  arm  ov009
 *   gpiCanFreeProfile  0x02190140  arm  ov009
 *   gpiRemoveProfile  0x0218FF24  arm  ov009
 *   strstr  0x02094B20  arm
 *   strncmp  0x020949F4  arm
 *   gpiPeerGetSig  0x0218F1E0  arm  ov009
 *   gpiSendBufferToPeer  0x02189A7C  arm  ov009
 *   gGpiPeerDebugSignature     0x021A4E50  data
 *   gGpiPeerErrorConnecting     0x021A4E7C  data
 *   gGpiPeerKeyAuth     0x021A4E98  data
 *   gGpiPeerKeyPid     0x021A4EA0  data
 *   gGpiPeerKeyNick     0x021A4EA8  data
 *   gGpiPeerKeySig     0x021A4EB0  data
 *   gGpiPeerKeyFinal     0x021A4EB8  data
 *   gGpiPeerKeyANack     0x021A4EC0  data
 *   gGpiPeerErrorBuddyAuth     0x021A4EC8  data
 *   gGpiPeerKeyAAck     0x021A4EEC  data
 *   gGpiPeerErrorParsing     0x021A4EF4  data
 *   gpiValueForKey  0x02193418  arm  ov009
 *   atoi  0x020964E0  arm
 *   OS_SPrintf  0x02084F40  arm
 *   strlen  0x0209477C  arm
 *   GSMD5Digest  0x021858A8  arm  ov009
 *   strcmp  0x020948E0  arm
 *   gGpiPeerSigFmt     0x021A4F14  data
 *   ArrayLength  0x02184200  arm  ov009
 *   ArrayNth  0x02184208  arm  ov009
 *   ArrayDeleteAt  0x0218437C  arm  ov009
 *   gsiTimeNitro  0x02184098  arm  ov009
 *   gpiReadMessageFromBuffer  0x02189BE4  arm  ov009
 *   gsimalloc  0x0217EAB0  arm  ov009
 *   goastrdup  0x0217F1E0  arm  ov009
 *   gpiAddCallback  0x02189DFC  arm  ov009
 *   gpiSendBuddyMessage  0x021889A0  arm  ov009
 *   gpiBuddyHandleKeyRequest  0x02188B0C  arm  ov009
 *   gpiBuddyHandleKeyReply  0x02188BA0  arm  ov009
 *   gpiHandleTransferMessage  0x02192FD0  arm  ov009
 *   gpiClipBufferToPosition  0x02189D28  arm  ov009
 *   gGpiPeerErrorOutOfMemory     0x021A4F1C  data
 *   gGpiPeerStatusChar     0x021A4F2C  data
 *   current_time  0x0217F264  arm  ov009
 *   gGpiPeerDebugTimeout  0x021A4F30  data
 *   gpiProcessPeerInitiatingConnection  0x0218E3B0  arm
 *   gpiProcessPeerAcceptingConnection   0x0218E6DC  arm
 *   gpiProcessPeerConnected             0x0218E9E8  arm
 *   gpiCheckTimedOutPeerOperations      0x0218ED58  arm
 *   gsifree     0x0217EAE0  arm
 *   ArrayFree   0x021841B0  arm
 *   gpiSendServerBuddyMessage  0x021888C0  arm  ov009
 *   gpiDestroyPeer  0x0218EEC0  arm  ov009
 *   gGpiPeerDebugRemoveNotInList  0x021A4F4C  data
 *   gsUdpEngineThink  0x021814EC  arm  ov009
 *   gpiProcessPeer  0x0218EE48  arm  ov009
 *   gGpiPeerDebugDisconnected  0x021A4F70  data
 *   MSL_C_LIB_MemsetPtr  0x020923B0  arm
 *   ArrayNew  0x02184144  arm  ov009
 *   gpiAddOperation  0x0218E114  arm
 *   gpiSendGetInfo   0x0218D40C  arm
 *   gsUdpEngineStartTalkingToPeer  0x021810cc  arm   ov009
 *   gpiSetError  0x02193710  arm   ov009
 *   gpiCallErrorCallback  0x02189d78  arm   ov009
 *   gGpiPeerErrorStartingComm     0x021a4f8c  data
 *   gpiAppendStringToBufferLen  0x021893c8  arm   ov009
 *   gpiAppendCharToBuffer  0x0218934c  arm   ov009
 *   ArrayAppend  0x02184234  arm   ov009
 *   gGpiPeerKeyM     0x021a4fc4  data
 *   gGpiPeerKeyLen     0x021a4fc8  data
 *   gGpiPeerKeyMsgCont     0x021a4fd0  data
 *   OS_SPrintf             0x02084F40  arm
 *   gpiSendOrBufferString  0x02189750  arm
 *   gGpiPeerXferFmt             0x021A4FD8  data
 *   gpiSendOrBufferString  0x02189750  arm  ov009
 *   gpiSendOrBufferStringLenToPeer  0x0218964C  arm  ov009
 *   gpiSendOrBufferChar  0x02189644  arm  ov009
 *   gGpiPeerEmptyMsg  0x021A4FEC  data
 *   gGpiPeerLenMsgFmt  0x021A4FF0  data
 *   SOC_InetNtoA      0x0215FA9C  arm
 *   gsDebugFormat     0x0217D254  arm
 *   gGpiPeerDebugLeft        0x021A5000  data
 *   gpiGetPeerByAddr  0x0218f0e8  arm   ov009
 *   SOC_InetNtoA  0x0215fa9c  arm   ov009
 *   gsirealloc  0x0217eac8  arm   ov009
 *   memcpy         0x02092344  arm
 *   gGpiPeerDebugOomAlloc     0x021a5028  data
 *   gGpiPeerDebugOomRealloc     0x021a5070  data
 *   gGpiPeerDebugNotExist  0x021A50BC  data
 *   gGpiPeerDebugConnRejected  0x021A50E4  data
 *   gGpiPeerDebugConnAccepted  0x021A5110  data
 *   gGpiPeerDebugOpNotAdded     0x021A513C  data
 *   gGpiPeerDebugOpAdded     0x021A5158  data
 *   gGpiPeerDebugOpNotRemoved  0x021A5170  data
 *   gGpiPeerDebugOpRemoveNotInList  0x021A518C  data
 *   gGpiPeerDebugOpRemoved  0x021A51B8  data
 */
#include "gsdebug.h"
#include "gpibuffer.h"
#include "gpi_types.h"
#include "darray.h"
#include "qr2_types.h"

extern int gsUdpEngineGetPeerState(unsigned int ip, unsigned short port, int *state);
#include "gpiprofile.h"
#include "gpiutility.h"
#include "gsmemory.h"
#include "../arm9/msl_string_str.h"
extern int gpiPeerGetSig(void **connection, GPIPeer *peer);
extern int gpiSendBufferToPeer(struct GPIConnection **connection, unsigned int ip, unsigned short port, struct GPIBuffer *outputBuffer, int *closed, int clipSentData);
#include "../arm9/msl_strtod.h"
#include "../arm9/os_printf.h"
#include "md5c.h"
struct DArrayImplementation;
extern void *ArrayNth(struct DArrayImplementation *array, int n);
#include "gstimernitro.h"
#include "gsplatformutil.h"
#include "gpicallback.h"
#include "gpibuddy.h"
#include "gpitransfer.h"
extern int gpiClipBufferToPosition(void **connection, GPIBuffer *buffer);
extern int  gpiProcessPeerInitiatingConnection(void **connection, GPIPeer *peer);
extern int  gpiProcessPeerAcceptingConnection(void **connection, GPIPeer *peer);
extern int  gpiProcessPeerConnected(void **connection, GPIPeer *peer);
extern void gpiCheckTimedOutPeerOperations(void **connection, GPIPeer *peer);
extern void ArrayFree(struct DArrayImplementation *array);
extern void gpiDestroyPeer(void **connection, GPIPeer *peer);
extern int gsUdpEngineThink(void);
static int gpiProcessPeer(void **connection, GPIPeer *peer);
#include "../arm9/msl_string_mem.h"
extern struct DArrayImplementation *ArrayNew(int elemSize, int numElems, void (*freeFn)(void *));
#include "gpioperation.h"
typedef int _GPResult;
#include "gpiinfo.h"
extern int gsUdpEngineStartTalkingToPeer(unsigned int ip, unsigned short port, char *msg, int timeOut);
extern int  gpiSendOrBufferString(void **connection, GPIPeer *peer,
                                  char *string);
extern int gpiSendOrBufferString(void **connection, GPIPeer *peer, char *string);
extern int gpiSendOrBufferStringLenToPeer(void **connection, GPIPeer *peer, char *string, int stringLen);
#include "soc.h"
extern GPIPeer *gpiGetPeerByAddr(void **connection, unsigned int ip, unsigned short port);
int gpiPeerSendMessages(void **connection, GPIPeer *peer);
void gpiDestroyPeer(void **connection, GPIPeer *peer);
void gpiRemovePeer(void **connection, GPIPeer *peer);
int gpiProcessPeers(void **connection);
GPIPeer *gpiGetPeerByProfile(void **connection, int profileid);
GPIPeer *gpiGetPeerByAddr(void **connection, unsigned int ip, unsigned short port);
void gpiFreeMessage(void **p);
GPIPeer *gpiAddPeer(void **connection, int profileid, int initiate);
int gpiPeerGetSig(void **connection, GPIPeer *peer);
int gpiPeerStartConnect(void **connection, GPIPeer *peer);
int gpiPeerAddMessage(void **connection, GPIPeer *peer, int type, char *message);
int gpiPeerStartTransferMessage(void **connection, GPIPeer *peer, int type, GPITransferID *transferID);
int gpiPeerFinishTransferMessage(void **connection, GPIPeer *peer, char *message, int len);
void gpiPeerLeftCallback(unsigned int ip, unsigned short port, void *unused, void **connection);
void gpiPeerMessageCallback(unsigned int ip, unsigned short port, unsigned char *message, int messageLength, int unused, void *userData);
void gpiPeerAcceptedCallback(unsigned int ip, unsigned short port, int unused, int rejected, void *userData);
void gpiPeerPingReplyCallback(void);
void gpiPeerAddOp(GPIPeer *peer, GPIPeerOp *operation);
void gpiPeerRemoveOp(GPIPeer *peer, GPIPeerOp *operation);
extern char gGpiPeerDebugSignature[];
extern char gGpiPeerErrorConnecting[];
extern char gGpiPeerKeyAuth[];
extern char gGpiPeerKeyPid[];
extern char gGpiPeerKeyNick[];
extern char gGpiPeerKeySig[];
extern char gGpiPeerKeyFinal[];
extern char gGpiPeerKeyANack[];
extern char gGpiPeerErrorBuddyAuth[];
extern char gGpiPeerKeyAAck[];
extern char gGpiPeerErrorParsing[];
extern char gGpiPeerSigFmt[];
extern char gGpiPeerErrorOutOfMemory[];
extern char gGpiPeerStatusChar[];
extern char gGpiPeerDebugTimeout[];
extern char gGpiPeerDebugRemoveNotInList[];
extern char gGpiPeerDebugDisconnected[];
extern char gGpiPeerErrorStartingComm[];
extern char gGpiPeerKeyM[];
extern char gGpiPeerKeyLen[];
extern char gGpiPeerKeyMsgCont[];
extern char gGpiPeerXferFmt[];
extern char gGpiPeerEmptyMsg[];   /* "" -- the default when message is 0 */
extern char gGpiPeerLenMsgFmt[];   /* "\len\%d\msg\\\n" -- OS_SPrintf's format */
extern char gGpiPeerDebugLeft[];
extern char gGpiPeerDebugOomAlloc[];
extern char gGpiPeerDebugOomRealloc[];
extern char gGpiPeerDebugNotExist[];
extern char gGpiPeerDebugConnRejected[];
extern char gGpiPeerDebugConnAccepted[];
extern char gGpiPeerDebugOpNotAdded[];
extern char gGpiPeerDebugOpAdded[];
extern char gGpiPeerDebugOpNotRemoved[];
extern char gGpiPeerDebugOpRemoveNotInList[];
extern char gGpiPeerDebugOpRemoved[];








int gpiProcessPeerInitiatingConnection(void **connection, GPIPeer *peer)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;
    char *str = 0;
    int connClosed;
    GPIProfile *pProfile;
    int result;
    int aPeerState;

    if (!peer)
        return 3;

    if (peer->state == 0x6A || peer->state == 0x64)
        return 3;

    switch (peer->state) {
    case 0x65:
        break;

    case 0x66:
        gsDebugFormat(1, 3, 0x1F, gGpiPeerDebugSignature, peer->profile);
        {
            int __result__ = gpiPeerStartConnect(connection, peer);
            if (__result__ != 0)
                return __result__;
        }
        break;

    case 0x67:
        gsUdpEngineGetPeerState(peer->ip, peer->port, &aPeerState);
        if (aPeerState == 1) {
            GPIPeer *pcurr;
            int freePeerSig = 1;

            if (!gpiGetProfile(connection, peer->profile, &pProfile)) {
                gpiSetErrorString(connection, gGpiPeerErrorConnecting);
                return 3;
            }

            gpiAppendStringToBuffer(connection, (&peer->outputBuffer), gGpiPeerKeyAuth);
            gpiAppendStringToBuffer(connection, (&peer->outputBuffer), gGpiPeerKeyPid);
            gpiAppendIntToBuffer(connection, (&peer->outputBuffer), iconnection->profileid);
            gpiAppendStringToBuffer(connection, (&peer->outputBuffer), gGpiPeerKeyNick);
            gpiAppendStringToBuffer(connection, (&peer->outputBuffer), iconnection->nick);
            gpiAppendStringToBuffer(connection, (&peer->outputBuffer), gGpiPeerKeySig);
            gpiAppendStringToBuffer(connection, (&peer->outputBuffer), pProfile->peerSig);
            gpiAppendStringToBuffer(connection, (&peer->outputBuffer), gGpiPeerKeyFinal);

            for (pcurr = iconnection->peerList; pcurr; pcurr = pcurr->pnext) {
                if (pcurr->profile == peer->profile && pcurr != peer && pcurr->state <= 0x67)
                    freePeerSig = 0;
            }

            if (freePeerSig) {
                gsifree(pProfile->peerSig);
                pProfile->peerSig = 0;
                if (gpiCanFreeProfile((char *)pProfile))
                    gpiRemoveProfile((void **)connection, pProfile);
            }

            peer->state = 0x68;
        }
        break;

    case 0x68:
        if (peer->inputBuffer.buffer)
            str = (char *)strstr(peer->inputBuffer.buffer, gGpiPeerKeyFinal);
        if (str) {
            *str = 0;
            str = peer->inputBuffer.buffer;
            if (!strncmp(str, gGpiPeerKeyANack, 7)) {
                peer->nackCount++;
                if (peer->nackCount > 1) {
                    gpiSetErrorString(connection, gGpiPeerErrorBuddyAuth);
                    return 3;
                }
                {
                    int __result__ = gpiPeerGetSig(connection, peer);
                    if (__result__ != 0)
                        return __result__;
                }
            } else if (strncmp(str, gGpiPeerKeyAAck, 6)) {
                gpiSetErrorString(connection, gGpiPeerErrorParsing);
                return 3;
            }
            peer->state = 0x69;
            peer->inputBuffer.len = 0;
        }
        break;
    }

    if (peer->outputBuffer.len > 0) {
        result = gpiSendBufferToPeer((struct GPIConnection **)connection, peer->ip, peer->port, &peer->outputBuffer, &connClosed, 1);
        if (connClosed || result)
            peer->state = 0x6A;
    }

    return 0;
}








int gpiProcessPeerAcceptingConnection(void **connection, GPIPeer *peer)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;
    int aPeerState;
    char *str;
    int connClosed;
    char intValue[16];
    int pid;
    char nick[31];
    char sig[33];
    char sigCheck[33];
    char buffer[256];

    if (peer->state != 0x68)
        return 3;

    gsUdpEngineGetPeerState(peer->ip, peer->port, &aPeerState);
    if (aPeerState == 3) {
        peer->state = 0x6A;
        return 0;
    }

    str = (char *)strstr(peer->inputBuffer.buffer, gGpiPeerKeyFinal);
    if (str) {
        *str = '\0';

        str = peer->inputBuffer.buffer;
        if (strncmp(str, gGpiPeerKeyAuth, 6) == 0) {
            if (!gpiValueForKey(str, gGpiPeerKeyPid, intValue, sizeof(intValue))) {
                peer->state = 0x6A;
                return 0;
            }
            pid = atoi(intValue);

            if (!gpiValueForKey(peer->inputBuffer.buffer, gGpiPeerKeyNick, nick, sizeof(nick))) {
                peer->state = 0x6A;
                return 0;
            }

            if (!gpiValueForKey(peer->inputBuffer.buffer, gGpiPeerKeySig, sig, sizeof(sig))) {
                peer->state = 0x6A;
                return 0;
            }

            OS_SPrintf(buffer, gGpiPeerSigFmt, iconnection->password, iconnection->profileid, pid);
            GSMD5Digest((unsigned char *)buffer, strlen(buffer), sigCheck);

            if (strcmp(sig, sigCheck) != 0) {
                gpiAppendStringToBuffer(connection, (&peer->outputBuffer), gGpiPeerKeyANack);
                gpiAppendStringToBuffer(connection, (&peer->outputBuffer), gGpiPeerKeyFinal);
                gpiSendBufferToPeer((struct GPIConnection **)connection, peer->ip, peer->port, &peer->outputBuffer, &connClosed, 1);
                peer->state = 0x6A;
                return 0;
            }

            gpiAppendStringToBuffer(connection, (&peer->outputBuffer), gGpiPeerKeyAAck);
            gpiAppendStringToBuffer(connection, (&peer->outputBuffer), gGpiPeerKeyFinal);

            peer->state = 0x69;
            peer->profile = pid;
        } else {
            peer->state = 0x6A;
            return 0;
        }

        peer->inputBuffer.len = 0;
    }

    return 0;
}







int gpiPeerSendMessages(void **connection, GPIPeer *peer)
{
    GPIMessage *message;
    int result;
    int connClosed;

    if (peer == 0)
        return 3;
    if (peer->outputBuffer.len != 0)
        return 0;
    while (ArrayLength(peer->messages) != 0) {
        message = (GPIMessage *)ArrayNth(peer->messages, 0);
        result = gpiSendBufferToPeer((struct GPIConnection **)connection, peer->ip, peer->port, &message->buffer, &connClosed, 0);
        if (connClosed != 0 || result != 0) {
            peer->state = 0x6a;
            return 0;
        }
        if (message->buffer.pos != message->buffer.len)
            break;
        ArrayDeleteAt(peer->messages, 0);
    }
    return 0;
}






int gpiProcessPeerConnected(void **connection, GPIPeer *peer)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;
    int aPeerState;
    int connClosed;
    GPICallback callback;
    char *buffer;
    int type;
    int messageLen;
    int result;

    if (!peer)
        return 3;

    if (peer->outputBuffer.len) {
        result = gpiSendBufferToPeer((struct GPIConnection **)connection, peer->ip, peer->port, &peer->outputBuffer, &connClosed, 1);
        if (connClosed || result) {
            peer->state = 0x6A;
            return 0;
        }
    }

    if (!peer->outputBuffer.len) {
        {
            int __result__ = gpiPeerSendMessages(connection, peer);
            if (__result__ != 0)
                return __result__;
        }
        if (peer->state == 0x6A)
            return 0;
    }

    if (peer->inputBuffer.len > 0)
        peer->timeout = gsiTimeNitro(0) + 10000;

    do {
        {
            int __result__ = gpiReadMessageFromBuffer(connection, &peer->inputBuffer, &buffer, &type, &messageLen);
            if (__result__ != 0)
                return __result__;
        }

        if (buffer) {
            switch (type) {
            case 1:
                callback = iconnection->callbacks[3];
                if (callback.callback) {
                    GPRecvBuddyMessageArg *arg;
                    arg = (GPRecvBuddyMessageArg *)gsimalloc(sizeof(GPRecvBuddyMessageArg));
                    if (arg == 0) {
                        gpiSetErrorString(connection, gGpiPeerErrorOutOfMemory);
                        return 1;
                    }
                    arg->profile = peer->profile;
                    arg->message = goastrdup(buffer);
                    arg->date = gsiTimeNitro(0);
                    {
                        int __result__ = gpiAddCallback(connection, callback, arg, 0, 2);
                        if (__result__ != 0)
                            return __result__;
                    }
                }
                break;

            case 5:
                callback = iconnection->callbacks[4];
                if (callback.callback) {
                    GPRecvBuddyUTMArg *arg;
                    arg = (GPRecvBuddyUTMArg *)gsimalloc(sizeof(GPRecvBuddyUTMArg));
                    if (arg == 0) {
                        gpiSetErrorString(connection, gGpiPeerErrorOutOfMemory);
                        return 1;
                    }
                    arg->profile = peer->profile;
                    arg->message = goastrdup(buffer);
                    arg->date = gsiTimeNitro(0);
                    {
                        int __result__ = gpiAddCallback(connection, callback, arg, 0, 2);
                        if (__result__ != 0)
                            return __result__;
                    }
                }
                break;

            case 0x66:
                gpiSendBuddyMessage(connection, peer->profile, 0x67, gGpiPeerStatusChar, 0, 0);
                break;

            case 0x68:
                {
                    int __result__ = gpiBuddyHandleKeyRequest(connection, peer);
                    if (__result__ != 0)
                        return __result__;
                }
                break;

            case 0x69:
                {
                    int __result__ = gpiBuddyHandleKeyReply(connection, peer, buffer);
                    if (__result__ != 0)
                        return __result__;
                }
                break;

            case 200:
            case 201:
            case 202:
            case 203:
            case 204:
            case 205:
            case 206:
            case 207:
            case 208:
                gpiHandleTransferMessage(connection, peer, type, peer->inputBuffer.buffer, buffer, messageLen);
                break;

            default:
                break;
            }

            gpiClipBufferToPosition(connection, &peer->inputBuffer);
        }
    } while (buffer);

    gsUdpEngineGetPeerState(peer->ip, peer->port, &aPeerState);
    if (aPeerState == 3)
        peer->state = 0x6A;

    return 0;
}








void gpiCheckTimedOutPeerOperations(void **connection, GPIPeer *peer)
{
    GPGetBuddyStatusInfoKeysArg *arg;
    GPICallback callback;
    GPIPeerOp *anIterator = peer->firstOp;

    if (peer == 0)
        return;
    for (; anIterator != 0 && anIterator != peer->lastOp; anIterator = anIterator->next) {
        if (anIterator->state == 2)
            continue;
        if (current_time() <= anIterator->timeout)
            continue;
        if (anIterator->callback == 0)
            continue;
        if (anIterator->type == 0x68) {
            arg = (GPGetBuddyStatusInfoKeysArg *)gsimalloc(sizeof(GPGetBuddyStatusInfoKeysArg));
            callback.callback = anIterator->callback;
            callback.param = anIterator->userData;
            arg->keys = 0;
            arg->numKeys = 0;
            arg->values = 0;
            arg->profile = peer->profile;
            gpiAddCallback(connection, callback, arg, 0, 0);
        }
        gsDebugFormat(1, 4, 8, gGpiPeerDebugTimeout);
        gpiPeerRemoveOp(peer, anIterator);
    }
}









static int gpiProcessPeer(void **connection, GPIPeer *peer)
{
    int result = 0;

    if (peer->state == 100)
        return 3;
    if (peer->state != 0x69) {
        if (peer->initiated != 0)
            result = gpiProcessPeerInitiatingConnection(connection, peer);
        else
            result = gpiProcessPeerAcceptingConnection(connection, peer);
    }
    if (result == 0 && peer->state == 0x69) {
        result = gpiProcessPeerConnected(connection, peer);
        gpiCheckTimedOutPeerOperations(connection, peer);
    }
    return result;
}









void gpiDestroyPeer(void **connection, GPIPeer *peer)
{
    gsifree(peer->inputBuffer.buffer);
    peer->inputBuffer.buffer = 0;
    gsifree(peer->outputBuffer.buffer);
    peer->outputBuffer.buffer = 0;
    if (peer->messages != 0) {
        ArrayFree(peer->messages);
        peer->messages = 0;
    }
    gsifree(peer);
}









/*
 * sdk:      gpiRemovePeer (libdwcgsgp.TWL.HYB.a(gpipeer.o))
 */
void gpiRemovePeer(void **connection, GPIPeer *peer)
{
    GPIMessage *message;
    GPIConnection *iconnection;
    GPIPeer *pprev;

    iconnection = (GPIConnection *)*connection;
    if (peer == 0 || (pprev = iconnection->peerList) == 0)
        return;
    if (pprev == peer) {
        iconnection->peerList = peer->pnext;
    } else {
        while (pprev->pnext != peer) {
            if (pprev->pnext == 0) {
                gsDebugFormat(1, 4, 1, gGpiPeerDebugRemoveNotInList);
                return;
            }
            pprev = pprev->pnext;
        }
        pprev->pnext = peer->pnext;
    }
    while (ArrayLength(peer->messages) != 0) {
        message = (GPIMessage *)ArrayNth(peer->messages, 0);
        if (message->type < 100)
            gpiSendServerBuddyMessage(connection, peer->profile, message->type, message->buffer.buffer + message->start);
        ArrayDeleteAt(peer->messages, 0);
    }
    gpiDestroyPeer(connection, peer);
}









/*
 * sdk:      gpiProcessPeers (libdwcgsgp.TWL.HYB.a(gpipeer.o))
 */
int gpiProcessPeers(void **connection)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;
    GPIPeer *nextPeer;
    GPIPeer *peer;
    int result;

    gsUdpEngineThink();
    peer = iconnection->peerList;
    while (peer != 0) {
        nextPeer = peer->pnext;
        if (peer->state == 0x6a) {
            gsDebugFormat(1, 4, 8, gGpiPeerDebugDisconnected, peer->profile);
            gpiRemovePeer(connection, peer);
        } else {
            result = gpiProcessPeer(connection, peer);
            if (peer->state == 0x6a || result != 0 || gsiTimeNitro(0) > peer->timeout) {
                gsDebugFormat(1, 4, 8, gGpiPeerDebugDisconnected, peer->profile);
                gpiRemovePeer(connection, peer);
            }
        }
        peer = nextPeer;
    }
    return 0;
}








/*
 * Walks the list hanging off the +0x5d8 member of the object and returns the
 * node whose +0x10 word equals v, or 0 when the list runs out.
 */
GPIPeer *gpiGetPeerByProfile(void **connection, int profileid)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;
    GPIPeer *peer = iconnection->peerList;

    while (peer != 0) {
        if (peer->profile == profileid)
            return peer;
        peer = peer->pnext;
    }
    return 0;
}








GPIPeer *gpiGetPeerByAddr(void **connection, unsigned int ip, unsigned short port)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;
    GPIPeer *pcurr;

    if (ip == 0 && port == 0)
        return 0;
    for (pcurr = iconnection->peerList; pcurr != 0; pcurr = pcurr->pnext) {
        if (pcurr->ip == ip && pcurr->port == port)
            return pcurr;
    }
    return 0;
}








void gpiFreeMessage(void **p)
{
    gsifree(*p);
    *p = 0;
}








/*
 * sdk:      gpiAddPeer (libdwcgsgp.TWL.HYB.a(gpipeer.o))
 */
GPIPeer *gpiAddPeer(void **connection, int profileid, int initiate)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;
    GPIPeer *peer;

    peer = (GPIPeer *)gsimalloc(sizeof(GPIPeer));
    if (peer == 0)
        return 0;
    MSL_C_LIB_MemsetPtr(peer, 0, sizeof(GPIPeer));
    peer->state = 0x64;
    peer->initiated = initiate;
    peer->profile = profileid;
    peer->timeout = gsiTimeNitro(0) + 10000;
    peer->pnext = iconnection->peerList;
    peer->messages = ArrayNew(0x18, 0, (void (*)(void *))gpiFreeMessage);
    iconnection->peerList = peer;
    peer->firstOp = 0;
    peer->lastOp = 0;
    peer->queueHead = 0;
    return peer;
}








int gpiPeerGetSig(void **connection, GPIPeer *peer)
{
    GPIOperation *operation;
    int result;

    result = gpiAddOperation(connection, 2, 0, &operation, 0, 0, 0);
    if (result != 0)
        return result;
    result = gpiSendGetInfo(connection, peer->profile, operation->id);
    if (result == 0) {
        peer->state = 0x65;
        return 0;
    }
    return result;
}








/*
 * sdk:      gpiPeerStartConnect (libdwcgsgp.TWL.HYB.a gpipeer.o)
 */
int gpiPeerStartConnect(void **connection, GPIPeer *peer)
{
    GPIProfile *profile;
    GPIConnection *iconnection;
    int anError;
    int result;
    int aPeerState;

    iconnection = (GPIConnection *)*connection;
    if (!gpiGetProfile(connection, peer->profile, &profile)) {
        gpiSetErrorString(connection, gGpiPeerErrorConnecting);
        return 3;
    }
    if (profile->buddyStatusInfo) {
        gsUdpEngineGetPeerState(profile->buddyStatusInfo->ip, profile->buddyStatusInfo->port, &aPeerState);
        if (aPeerState != 1 || aPeerState != 0) {
            anError = gsUdpEngineStartTalkingToPeer(profile->buddyStatusInfo->ip, profile->buddyStatusInfo->port,
                                    iconnection->mHeader, 10000);
            if (anError != 5) {
                gpiSetError(connection, (int)5, gGpiPeerErrorStartingComm);
                result = 3;
                gpiCallErrorCallback(connection, result, 0);
                return result;
            }
        }
        peer->ip = profile->buddyStatusInfo->ip;
        peer->port = profile->buddyStatusInfo->port;
    }
    peer->state = 0x67;
    return 0;
}







/*
 * sdk:      gpiPeerAddMessage (libdwcgsgp.TWL.HYB.a gpipeer.o)
 */
int gpiPeerAddMessage(void **connection, GPIPeer *peer, int type, char *message)
{
    int len;

    if (peer == 0)
        return 3;
    if (message == 0)
        return 3;
    len = strlen(message);
    {
        GPIMessage gpiMessage = {0};
        gpiMessage.type = type;
        {
            int __result__ = gpiAppendStringToBuffer(connection, (&gpiMessage.buffer), gGpiPeerKeyM);
            if (__result__ != 0)
                return __result__;
        }
        {
            int __result__ = gpiAppendIntToBuffer(connection, (&gpiMessage.buffer), type);
            if (__result__ != 0)
                return __result__;
        }
        {
            int __result__ = gpiAppendStringToBuffer(connection, (&gpiMessage.buffer), gGpiPeerKeyLen);
            if (__result__ != 0)
                return __result__;
        }
        {
            int __result__ = gpiAppendIntToBuffer(connection, (&gpiMessage.buffer), len);
            if (__result__ != 0)
                return __result__;
        }
        {
            int __result__ = gpiAppendStringToBuffer(connection, (&gpiMessage.buffer), gGpiPeerKeyMsgCont);
            if (__result__ != 0)
                return __result__;
        }
        gpiMessage.start = gpiMessage.buffer.len;
        {
            int __result__ = gpiAppendStringToBufferLen(connection, (&gpiMessage.buffer), message, len);
            if (__result__ != 0)
                return __result__;
        }
        {
            int __result__ = gpiAppendCharToBuffer(connection, (&gpiMessage.buffer), 0);
            if (__result__ != 0)
                return __result__;
        }
        ArrayAppend(peer->messages, &gpiMessage);
        peer->timeout = gsiTimeNitro(0) + 10000;
        return 0;
    }
}







int gpiPeerStartTransferMessage(void **connection, GPIPeer *peer,
                                int type, GPITransferID *transferID)
{
    char buffer[64];
    int profileid;
    unsigned int count;
    unsigned int time;

    profileid = transferID->profileid;
    count = transferID->count;
    time = transferID->time;
    if (transferID == 0)
        return 3;
    OS_SPrintf(buffer, gGpiPeerXferFmt, type, profileid, count, time);
    return gpiSendOrBufferString(connection, peer, buffer);
}







/*
 * Byte-correct (216/216), 8 of 8 relocation sites resolved.
 *
 * The two pool words at the end are in the order the code first names them:
 * the `ldreq` at +0028 (the `message == 0` default) addresses +00D0, which the
 * image fills with 0x021A4FEC -- the compiler's 1-byte empty string @15025 --
 * and the `ldr` at +0044 (OS_SPrintf's format) addresses +00D4 = 0x021A4FF0,
 * "\len\%d\msg\\\n", @15026.  Spelling them the other way round still
 * reproduces every instruction, because the pool slots are the same either
 * way, but the two words come out exchanged and `sole-ref/self`, which
 * compares the word it is about to write with the ROM word at the site,
 * refuses both.  Both literals are attested by the overlay's own image
 * (ov009 window, the only two candidate windows holding them are ov009 and
 * ov021 and only ov009's bytes are read, the function under test living there).
 *
 * The DWARF carries three separate `enum _GPResult __result__` locals, all in
 * r0, one per if-chain, so the original almost certainly declared a result in
 * each of three sibling blocks rather than reusing one.  The single `result`
 * below colours identically -- r0 in all three, r4 never live across a call --
 * and reproduces all 216 bytes, so the extra scopes buy nothing here.
 *
 * sdk:      gpiPeerFinishTransferMessage (libdwcgsgp.TWL.HYB.a(gpipeer.o))
 */
int gpiPeerFinishTransferMessage(void **connection, GPIPeer *peer, char *message, int len)
{
    char buffer[32];
    int result;

    if (peer == 0)
        return 3;
    if (message == 0)
        message = gGpiPeerEmptyMsg;
    if (len == -1)
        len = strlen(message);
    OS_SPrintf(buffer, gGpiPeerLenMsgFmt, len);
    result = gpiSendOrBufferString(connection, peer, buffer);
    if (result != 0)
        return result;
    result = gpiSendOrBufferStringLenToPeer(connection, (GPIPeer *)peer, message, len);
    if (result != 0)
        return result;
    result = gpiSendOrBufferChar(connection, peer, 0);
    if (result != 0)
        return result;
    peer->timeout = gsiTimeNitro(0) + 10000;
    return 0;
}





void gpiPeerLeftCallback(unsigned int ip, unsigned short port, void *unused,
                         void **connection)
{
    SOCInAddr anAddr;
    GPIPeer *aPeer;

    anAddr.addr = ip;
    aPeer = gpiGetPeerByAddr(connection, ip, port);
    if (aPeer == 0)
        return;
    gsDebugFormat(1, 0, 8, gGpiPeerDebugLeft, SOC_InetNtoA(anAddr), port,
                  aPeer->profile);
    aPeer->state = 0x6a;
}





/*
 * sdk:      gpiPeerMessageCallback (libdwcgsgp.TWL.HYB.a gpipeer.o)
 */
void gpiPeerMessageCallback(unsigned int ip, unsigned short port, unsigned char *message,
                   int messageLength, int unused, void *userData)
{
    void **connection;
    GPIPeer *aPeer;
    char *buff;
    int writePos;
    int size;
    SOCInAddr anAddr;
    char *reallocedBuff;

    connection = (void **)userData;
    anAddr.addr = ip;
    aPeer = gpiGetPeerByAddr(connection, ip, port);
    if (aPeer == 0) {
        aPeer = (GPIPeer *)gpiAddPeer(connection, -1, 0);
        if (aPeer != 0) {
            aPeer->state = 0x68;
            aPeer->ip = ip;
            aPeer->port = port;
        } else {
            gsDebugFormat(1, 2, 1, gGpiPeerDebugOomAlloc, SOC_InetNtoA(anAddr), port);
            return;
        }
    }
    writePos = aPeer->inputBuffer.len;
    size = aPeer->inputBuffer.size;
    buff = aPeer->inputBuffer.buffer;
    if (messageLength > size - writePos) {
        size = writePos + (messageLength < 0x4000 ? 0x4000 : messageLength);
        reallocedBuff = gsirealloc(buff, size + 1);
        if (reallocedBuff == 0) {
            gsDebugFormat(1, 2, 1, gGpiPeerDebugOomRealloc, SOC_InetNtoA(anAddr), port);
            gsifree(buff);
            gpiSetErrorString(connection, gGpiPeerErrorOutOfMemory);
            gpiCallErrorCallback(connection, 1, 0);
            return;
        }
        buff = reallocedBuff;
    }
    memcpy(buff + writePos, message, messageLength);
    aPeer->inputBuffer.buffer = buff;
    aPeer->inputBuffer.len += messageLength;
    aPeer->inputBuffer.size = size;
    buff[aPeer->inputBuffer.len] = 0;
}



void gpiPeerAcceptedCallback(unsigned int ip, unsigned short port, int unused, int rejected, void *userData)
{
    SOCInAddr anAddr;
    GPIPeer *aPeer;

    anAddr.addr = ip;
    aPeer = gpiGetPeerByAddr((void **)userData, ip, port);
    if (aPeer == 0) {
        gsDebugFormat(1, 0, 1, gGpiPeerDebugNotExist, SOC_InetNtoA(anAddr), port);
    } else if (rejected) {
        aPeer->state = 0x6a;
        gsDebugFormat(1, 0, 8, gGpiPeerDebugConnRejected, SOC_InetNtoA(anAddr), port);
        return;
    }
    gsDebugFormat(1, 0, 8, gGpiPeerDebugConnAccepted, SOC_InetNtoA(anAddr), port);
}

void gpiPeerPingReplyCallback(void)
{
}



void gpiPeerAddOp(GPIPeer *peer, GPIPeerOp *operation)
{
    if (peer == 0 || operation == 0) {
        gsDebugFormat(1, 4, 2, gGpiPeerDebugOpNotAdded);
        return;
    }
    if (peer->queueHead == 0) {
        peer->firstOp = operation;
        peer->lastOp = operation;
        peer->queueHead = operation;
    } else {
        if (peer->firstOp == peer->lastOp) {
            peer->firstOp->next = operation;
            peer->lastOp = operation;
        } else {
            peer->lastOp->next = operation;
            peer->lastOp = operation;
        }
    }
    gsDebugFormat(1, 4, 8, gGpiPeerDebugOpAdded);
}



void gpiPeerRemoveOp(GPIPeer *peer, GPIPeerOp *operation)
{
    GPIPeerOp *aPrevOp;

    if (peer == 0 || operation == 0) {
        gsDebugFormat(1, 4, 2, gGpiPeerDebugOpNotRemoved);
        return;
    }
    if (peer->queueHead == 0) {
        gsDebugFormat(1, 4, 2, gGpiPeerDebugOpNotRemoved);
        return;
    }
    if (peer->firstOp == peer->lastOp && peer->firstOp == operation) {
        GPIPeerOp *pnext = operation->next;

        peer->lastOp = pnext;
        peer->firstOp = pnext;
        peer->queueHead = pnext;
    } else if (peer->firstOp == operation) {
        peer->firstOp = peer->firstOp->next;
        peer->queueHead = peer->firstOp;
    } else {
        aPrevOp = peer->firstOp;
        while (aPrevOp->next != operation) {
            if (aPrevOp->next == 0) {
                gsDebugFormat(1, 4, 1, gGpiPeerDebugOpRemoveNotInList);
                return;
            }
            aPrevOp = aPrevOp->next;
        }
        aPrevOp->next = operation->next;
    }
    gsDebugFormat(1, 4, 8, gGpiPeerDebugOpRemoved);
    gsifree(operation);
}
