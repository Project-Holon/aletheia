/*
 * file:     unit_0218E3B0.c
 * unit:     yes
 * function: func_0218E3B0, func_0218E6DC, func_0218E91C, func_0218E9E8, func_0218ED58, func_0218EE48, func_0218EEC0, func_0218EF04, func_0218EFEC, func_0218F0B8, func_0218F0E8, func_0218F134, func_0218F150, func_0218F1E0, func_0218F248, func_0218F350, func_0218F4BC, func_0218F51C, gpiPeerLeftCallback, func_0218F65C, func_0218F7B8
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
 * symbols:
 *   func_0217D254  0x0217D254  arm  ov009
 *   func_02181010  0x02181010  arm  ov009
 *   func_0218FD9C  0x0218FD9C  arm  ov009
 *   func_02193734  0x02193734  arm  ov009
 *   func_0218946C  0x0218946C  arm  ov009
 *   func_0218949C  0x0218949C  arm  ov009
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 *   func_02190140  0x02190140  arm  ov009
 *   func_0218FF24  0x0218FF24  arm  ov009
 *   func_02094B20  0x02094B20  arm
 *   func_020949F4  0x020949F4  arm
 *   func_0218F1E0  0x0218F1E0  arm  ov009
 *   func_02189A7C  0x02189A7C  arm  ov009
 *   g_021A4E50     0x021A4E50  data
 *   g_021A4E7C     0x021A4E7C  data
 *   g_021A4E98     0x021A4E98  data
 *   g_021A4EA0     0x021A4EA0  data
 *   g_021A4EA8     0x021A4EA8  data
 *   g_021A4EB0     0x021A4EB0  data
 *   g_021A4EB8     0x021A4EB8  data
 *   g_021A4EC0     0x021A4EC0  data
 *   g_021A4EC8     0x021A4EC8  data
 *   g_021A4EEC     0x021A4EEC  data
 *   g_021A4EF4     0x021A4EF4  data
 *   func_02193418  0x02193418  arm  ov009
 *   func_020964E0  0x020964E0  arm
 *   func_02084F40  0x02084F40  arm
 *   func_0209477C  0x0209477C  arm
 *   func_021858A8  0x021858A8  arm  ov009
 *   func_020948E0  0x020948E0  arm
 *   g_021A4F14     0x021A4F14  data
 *   func_02184200  0x02184200  arm  ov009
 *   func_02184208  0x02184208  arm  ov009
 *   func_0218437C  0x0218437C  arm  ov009
 *   func_02184098  0x02184098  arm  ov009
 *   func_02189BE4  0x02189BE4  arm  ov009
 *   func_0217EAB0  0x0217EAB0  arm  ov009
 *   func_0217F1E0  0x0217F1E0  arm  ov009
 *   func_02189DFC  0x02189DFC  arm  ov009
 *   func_021889A0  0x021889A0  arm  ov009
 *   func_02188B0C  0x02188B0C  arm  ov009
 *   func_02188BA0  0x02188BA0  arm  ov009
 *   func_02192FD0  0x02192FD0  arm  ov009
 *   func_02189D28  0x02189D28  arm  ov009
 *   g_021A4F1C     0x021A4F1C  data
 *   g_021A4F2C     0x021A4F2C  data
 *   func_0217F264  0x0217F264  arm  ov009
 *   func_0218F900  0x0218F900  arm  ov009
 *   g_021A4F30  0x021A4F30  data
 *   gpiProcessPeerInitiatingConnection  0x0218E3B0  arm
 *   gpiProcessPeerAcceptingConnection   0x0218E6DC  arm
 *   gpiProcessPeerConnected             0x0218E9E8  arm
 *   gpiCheckTimedOutPeerOperations      0x0218ED58  arm
 *   gsifree     0x0217EAE0  arm
 *   ArrayFree   0x021841B0  arm
 *   func_021888C0  0x021888C0  arm  ov009
 *   func_0218EEC0  0x0218EEC0  arm  ov009
 *   g_021A4F4C  0x021A4F4C  data
 *   func_021814EC  0x021814EC  arm  ov009
 *   func_0218EE48  0x0218EE48  arm  ov009
 *   g_021A4F70  0x021A4F70  data
 *   func_020923B0  0x020923B0  arm
 *   func_02184144  0x02184144  arm  ov009
 *   gpiAddOperation  0x0218E114  arm
 *   gpiSendGetInfo   0x0218D40C  arm
 *   func_021810CC  0x021810cc  arm   ov009
 *   func_02193710  0x02193710  arm   ov009
 *   func_02189D78  0x02189d78  arm   ov009
 *   g_021A4F8C     0x021a4f8c  data
 *   func_021893C8  0x021893c8  arm   ov009
 *   func_0218934C  0x0218934c  arm   ov009
 *   func_02184234  0x02184234  arm   ov009
 *   g_021A4FC4     0x021a4fc4  data
 *   g_021A4FC8     0x021a4fc8  data
 *   g_021A4FD0     0x021a4fd0  data
 *   OS_SPrintf             0x02084F40  arm
 *   gpiSendOrBufferString  0x02189750  arm
 *   g_021A4FD8             0x021A4FD8  data
 *   func_02189750  0x02189750  arm  ov009
 *   func_0218964C  0x0218964C  arm  ov009
 *   gpiSendOrBufferChar  0x02189644  arm  ov009
 *   g_021A4FEC  0x021A4FEC  data
 *   g_021A4FF0  0x021A4FF0  data
 *   SOC_InetNtoA      0x0215FA9C  arm
 *   gsDebugFormat     0x0217D254  arm
 *   g_021A5000        0x021A5000  data
 *   func_0218F0E8  0x0218f0e8  arm   ov009
 *   func_0215FA9C  0x0215fa9c  arm   ov009
 *   func_0217EAC8  0x0217eac8  arm   ov009
 *   memcpy         0x02092344  arm
 *   g_021A5028     0x021a5028  data
 *   g_021A5070     0x021a5070  data
 *   g_021A50BC  0x021A50BC  data
 *   g_021A50E4  0x021A50E4  data
 *   g_021A5110  0x021A5110  data
 */
#include "gpi_types.h"
#include "qr2_types.h"

extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern int func_02181010(unsigned int ip, unsigned short port, int *state);
extern int func_0218FD9C(void **connection, int profileid, GPIProfile **pProfile);
extern void func_02193734(void **connection, char *string);
extern int func_0218946C(void **connection, GPIBuffer *buffer, const char *string);
extern int func_0218949C(void **connection, GPIBuffer *buffer, int value);
extern void func_0217EAE0(void *ptr);
extern int func_02190140(char *p);
extern void func_0218FF24(const int *p, void *profile);
extern char *func_02094B20(const char *s1, const char *s2);
extern int func_020949F4(const u8 *s1, const u8 *s2, u32 n);
extern int func_0218F1E0(void **connection, GPIPeer *peer);
extern int func_02189A7C(void **connection, unsigned int ip, unsigned short port, GPIBuffer *outputBuffer,
                         int *closed, int mustSend);
extern int func_02193418(const char *command, const char *key, char *value, int valueLen);
extern int func_020964E0(const char *s);
extern int func_02084F40(char *dst, const char *fmt, ...);
extern int func_0209477C(const u8 *s);
extern void func_021858A8(unsigned char *input, unsigned int len, char *output);
extern int func_020948E0(const char *s1, const char *s2);
extern int func_02184200(const int *p);
extern void *func_02184208(void *array, int n);
extern void func_0218437C(int a, int b);
extern long func_02184098(long *timer);
extern int func_02189BE4(void **connection, GPIBuffer *inputBuffer, char **message, int *type, int *plen);
extern void *func_0217EAB0(unsigned long size);
extern char *func_0217F1E0(char *src);
extern int func_02189DFC(void **connection, GPICallback callback, void *arg, GPIOperation *operation, int type);
int func_021889A0(void **connection, int profileid, int type, char *message, int sendOption, GPIPeerOp *peerOp);
int func_02188B0C(void **connection, GPIPeer *peer);
int func_02188BA0(void **connection, GPIPeer *peer, char *buffer);
extern void func_02192FD0(void **connection, void *peer, int unused, char *headers, char *buffer, int len);
extern int func_02189D28(void **connection, GPIBuffer *buffer);
extern unsigned int func_0217F264(void);
extern void func_0218F900(GPIPeer *peer, GPIPeerOp *operation);
extern int  gpiProcessPeerInitiatingConnection(void **connection, GPIPeer *peer);
extern int  gpiProcessPeerAcceptingConnection(void **connection, GPIPeer *peer);
extern int  gpiProcessPeerConnected(void **connection, GPIPeer *peer);
extern void gpiCheckTimedOutPeerOperations(void **connection, GPIPeer *peer);
extern void gsifree(void *ptr);
extern void ArrayFree(void *array);
extern int func_021888C0(void **connection, int profileid, int type, char *message);
extern void func_0218EEC0(void **connection, GPIPeer *peer);
extern int func_021814EC(void);
extern int func_0218EE48(void **connection, GPIPeer *peer);
extern void *func_020923B0(void *p, int c, u32 n);
extern void *func_02184144(int elemSize, int numElems, void (*freeFn)(void *));
extern int gpiAddOperation(void **connection, int type, void *data,
                           GPIOperation **op, int blocking,
                           void (*callback)(void **, void *, void *),
                           void *param);
extern int gpiSendGetInfo(void **connection, int profileid, int operationid);
extern int func_021810CC(unsigned int ip, unsigned short port, char *msg, int timeOut);
extern void func_02193710(void **connection, int code, char *string);
extern int func_02189D78(void **connection, int result, int fatal);
extern int func_021893C8(void **connection, GPIBuffer *buffer, char *src, int n);
extern int func_0218934C(void **connection, GPIBuffer *buffer, int c);
extern void func_02184234(void *array, void *elem);
extern int OS_SPrintf(char *dst, const char *fmt, ...);
extern int  gpiSendOrBufferString(void **connection, GPIPeer *peer,
                                  char *string);
extern int func_02189750(void **connection, GPIPeer *peer, char *string);
extern int func_0218964C(void **connection, GPIPeer *peer, char *string, int stringLen);
extern int gpiSendOrBufferChar();
extern char *SOC_InetNtoA(SOCInAddr in);
extern void gsDebugFormat(int theCat, int theType, int theLevel, char *theTokenStr, ...);
extern GPIPeer *func_0218F0E8(void **connection, unsigned int ip, unsigned short port);
extern char *func_0215FA9C(SOCInAddr in);
extern void *func_0217EAC8(void *ptr, unsigned int size);
extern void *memcpy(void *, const void *, unsigned int);
int func_0218E3B0(void **connection, GPIPeer *peer);
int func_0218E6DC(void **connection, GPIPeer *peer);
int func_0218E91C(void **connection, GPIPeer *peer);
int func_0218E9E8(void **connection, GPIPeer *peer);
void func_0218ED58(void **connection, GPIPeer *peer);
void gpiDestroyPeer(void **connection, GPIPeer *peer);
void func_0218EF04(void **connection, GPIPeer *peer);
int func_0218EFEC(void **connection);
GPIPeer *func_0218F0B8(void **connection, int profileid);
GPIPeer *gpiGetPeerByAddr(void **connection, unsigned int ip, unsigned short port);
void func_0218F134(void **p);
GPIPeer *func_0218F150(void **connection, int profileid, int initiate);
int gpiPeerGetSig(void **connection, GPIPeer *peer);
int func_0218F248(void **connection, GPIPeer *peer);
int func_0218F350(void **connection, GPIPeer *peer, int type, char *message);
int gpiPeerStartTransferMessage(void **connection, GPIPeer *peer, int type, GPITransferID *transferID);
int func_0218F51C(void **connection, GPIPeer *peer, char *message, int len);
void gpiPeerLeftCallback(unsigned int ip, unsigned short port, void *unused, void **connection);
void func_0218F65C(unsigned int ip, unsigned short port, unsigned char *message, int messageLength, int unused, void *userData);
void func_0218F7B8(unsigned int ip, unsigned short port, int unused, int rejected, void *userData);
extern char g_021A4E50[];
extern char g_021A4E7C[];
extern char g_021A4E98[];
extern char g_021A4EA0[];
extern char g_021A4EA8[];
extern char g_021A4EB0[];
extern char g_021A4EB8[];
extern char g_021A4EC0[];
extern char g_021A4EC8[];
extern char g_021A4EEC[];
extern char g_021A4EF4[];
extern char g_021A4F14[];
extern char g_021A4F1C[];
extern char g_021A4F2C[];
extern char g_021A4F30[];
extern char g_021A4F4C[];
extern char g_021A4F70[];
extern char g_021A4F8C[];
extern char g_021A4FC4[];
extern char g_021A4FC8[];
extern char g_021A4FD0[];
extern char g_021A4FD8[];
extern char g_021A4FEC[];   /* "" -- the default when message is 0 */
extern char g_021A4FF0[];   /* "\len\%d\msg\\\n" -- OS_SPrintf's format */
extern char g_021A5000[];
extern char g_021A5028[];
extern char g_021A5070[];
extern char g_021A50BC[];
extern char g_021A50E4[];
extern char g_021A5110[];







int func_0218E3B0(void **connection, GPIPeer *peer)
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
        func_0217D254(1, (char *)3, 0x1F, g_021A4E50, peer->profile);
        {
            int __result__ = func_0218F248(connection, peer);
            if (__result__ != 0)
                return __result__;
        }
        break;

    case 0x67:
        func_02181010(peer->ip, peer->port, &aPeerState);
        if (aPeerState == 1) {
            GPIPeer *pcurr;
            int freePeerSig = 1;

            if (!func_0218FD9C(connection, peer->profile, &pProfile)) {
                func_02193734(connection, g_021A4E7C);
                return 3;
            }

            func_0218946C(connection, &peer->outputBuffer, g_021A4E98);
            func_0218946C(connection, &peer->outputBuffer, g_021A4EA0);
            func_0218949C(connection, &peer->outputBuffer, iconnection->profileid);
            func_0218946C(connection, &peer->outputBuffer, g_021A4EA8);
            func_0218946C(connection, &peer->outputBuffer, iconnection->nick);
            func_0218946C(connection, &peer->outputBuffer, g_021A4EB0);
            func_0218946C(connection, &peer->outputBuffer, pProfile->peerSig);
            func_0218946C(connection, &peer->outputBuffer, g_021A4EB8);

            for (pcurr = iconnection->peerList; pcurr; pcurr = pcurr->pnext) {
                if (pcurr->profile == peer->profile && pcurr != peer && pcurr->state <= 0x67)
                    freePeerSig = 0;
            }

            if (freePeerSig) {
                func_0217EAE0(pProfile->peerSig);
                pProfile->peerSig = 0;
                if (func_02190140((char *)pProfile))
                    func_0218FF24((const int *)connection, pProfile);
            }

            peer->state = 0x68;
        }
        break;

    case 0x68:
        if (peer->inputBuffer.buffer)
            str = func_02094B20(peer->inputBuffer.buffer, g_021A4EB8);
        if (str) {
            *str = 0;
            str = peer->inputBuffer.buffer;
            if (!func_020949F4((const u8 *)str, (const u8 *)g_021A4EC0, 7)) {
                peer->nackCount++;
                if (peer->nackCount > 1) {
                    func_02193734(connection, g_021A4EC8);
                    return 3;
                }
                {
                    int __result__ = func_0218F1E0(connection, peer);
                    if (__result__ != 0)
                        return __result__;
                }
            } else if (func_020949F4((const u8 *)str, (const u8 *)g_021A4EEC, 6)) {
                func_02193734(connection, g_021A4EF4);
                return 3;
            }
            peer->state = 0x69;
            peer->inputBuffer.len = 0;
        }
        break;
    }

    if (peer->outputBuffer.len > 0) {
        result = func_02189A7C(connection, peer->ip, peer->port, &peer->outputBuffer, &connClosed, 1);
        if (connClosed || result)
            peer->state = 0x6A;
    }

    return 0;
}







int func_0218E6DC(void **connection, GPIPeer *peer)
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

    func_02181010(peer->ip, peer->port, &aPeerState);
    if (aPeerState == 3) {
        peer->state = 0x6A;
        return 0;
    }

    str = (char *)(unsigned char *)func_02094B20((const char *)((const unsigned char *)peer->inputBuffer.buffer), (const char *)((const unsigned char *)g_021A4EB8));
    if (str) {
        *str = '\0';

        str = peer->inputBuffer.buffer;
        if (func_020949F4((const unsigned char *)str, (const unsigned char *)g_021A4E98, 6) == 0) {
            if (!func_02193418(str, g_021A4EA0, intValue, sizeof(intValue))) {
                peer->state = 0x6A;
                return 0;
            }
            pid = func_020964E0(intValue);

            if (!func_02193418(peer->inputBuffer.buffer, g_021A4EA8, nick, sizeof(nick))) {
                peer->state = 0x6A;
                return 0;
            }

            if (!func_02193418(peer->inputBuffer.buffer, g_021A4EB0, sig, sizeof(sig))) {
                peer->state = 0x6A;
                return 0;
            }

            func_02084F40(buffer, g_021A4F14, iconnection->password, iconnection->profileid, pid);
            func_021858A8((unsigned char *)buffer, func_0209477C((const u8 *)buffer), sigCheck);

            if (func_020948E0(sig, sigCheck) != 0) {
                func_0218946C(connection, &peer->outputBuffer, g_021A4EC0);
                func_0218946C(connection, &peer->outputBuffer, g_021A4EB8);
                func_02189A7C(connection, peer->ip, peer->port, &peer->outputBuffer, &connClosed, 1);
                peer->state = 0x6A;
                return 0;
            }

            func_0218946C(connection, &peer->outputBuffer, g_021A4EEC);
            func_0218946C(connection, &peer->outputBuffer, g_021A4EB8);

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






int func_0218E91C(void **connection, GPIPeer *peer)
{
    GPIMessage *message;
    int result;
    int connClosed;

    if (peer == 0)
        return 3;
    if (peer->outputBuffer.len != 0)
        return 0;
    while (func_02184200(peer->messages) != 0) {
        message = (GPIMessage *)func_02184208(peer->messages, 0);
        result = func_02189A7C(connection, peer->ip, peer->port, &message->buffer, &connClosed, 0);
        if (connClosed != 0 || result != 0) {
            peer->state = 0x6a;
            return 0;
        }
        if (message->buffer.pos != message->buffer.len)
            break;
        func_0218437C((int)peer->messages, 0);
    }
    return 0;
}





int func_0218E9E8(void **connection, GPIPeer *peer)
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
        result = func_02189A7C(connection, peer->ip, peer->port, &peer->outputBuffer, &connClosed, 1);
        if (connClosed || result) {
            peer->state = 0x6A;
            return 0;
        }
    }

    if (!peer->outputBuffer.len) {
        {
            int __result__ = func_0218E91C(connection, peer);
            if (__result__ != 0)
                return __result__;
        }
        if (peer->state == 0x6A)
            return 0;
    }

    if (peer->inputBuffer.len > 0)
        peer->timeout = func_02184098(0) + 10000;

    do {
        {
            int __result__ = func_02189BE4(connection, &peer->inputBuffer, &buffer, &type, &messageLen);
            if (__result__ != 0)
                return __result__;
        }

        if (buffer) {
            switch (type) {
            case 1:
                callback = iconnection->callbacks[3];
                if (callback.callback) {
                    GPRecvBuddyMessageArg *arg;
                    arg = (GPRecvBuddyMessageArg *)func_0217EAB0(sizeof(GPRecvBuddyMessageArg));
                    if (arg == 0) {
                        func_02193734(connection, g_021A4F1C);
                        return 1;
                    }
                    arg->profile = peer->profile;
                    arg->message = func_0217F1E0(buffer);
                    arg->date = func_02184098(0);
                    {
                        int __result__ = func_02189DFC(connection, callback, arg, 0, 2);
                        if (__result__ != 0)
                            return __result__;
                    }
                }
                break;

            case 5:
                callback = iconnection->callbacks[4];
                if (callback.callback) {
                    GPRecvBuddyUTMArg *arg;
                    arg = (GPRecvBuddyUTMArg *)func_0217EAB0(sizeof(GPRecvBuddyUTMArg));
                    if (arg == 0) {
                        func_02193734(connection, g_021A4F1C);
                        return 1;
                    }
                    arg->profile = peer->profile;
                    arg->message = func_0217F1E0(buffer);
                    arg->date = func_02184098(0);
                    {
                        int __result__ = func_02189DFC(connection, callback, arg, 0, 2);
                        if (__result__ != 0)
                            return __result__;
                    }
                }
                break;

            case 0x66:
                func_021889A0(connection, peer->profile, 0x67, g_021A4F2C, 0, 0);
                break;

            case 0x68:
                {
                    int __result__ = func_02188B0C(connection, peer);
                    if (__result__ != 0)
                        return __result__;
                }
                break;

            case 0x69:
                {
                    int __result__ = func_02188BA0(connection, peer, buffer);
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
                func_02192FD0(connection, peer, type, peer->inputBuffer.buffer, buffer, messageLen);
                break;

            default:
                break;
            }

            func_02189D28(connection, &peer->inputBuffer);
        }
    } while (buffer);

    func_02181010(peer->ip, peer->port, &aPeerState);
    if (aPeerState == 3)
        peer->state = 0x6A;

    return 0;
}







void func_0218ED58(void **connection, GPIPeer *peer)
{
    GPGetBuddyStatusInfoKeysArg *arg;
    GPICallback callback;
    GPIPeerOp *anIterator = peer->firstOp;

    if (peer == 0)
        return;
    for (; anIterator != 0 && anIterator != peer->lastOp; anIterator = anIterator->next) {
        if (anIterator->state == 2)
            continue;
        if (func_0217F264() <= anIterator->timeout)
            continue;
        if (anIterator->callback == 0)
            continue;
        if (anIterator->type == 0x68) {
            arg = (GPGetBuddyStatusInfoKeysArg *)func_0217EAB0(sizeof(GPGetBuddyStatusInfoKeysArg));
            callback.callback = anIterator->callback;
            callback.param = anIterator->userData;
            arg->keys = 0;
            arg->numKeys = 0;
            arg->values = 0;
            arg->profile = peer->profile;
            func_02189DFC(connection, callback, arg, 0, 0);
        }
        func_0217D254(1, (char *)4, 8, g_021A4F30);
        func_0218F900(peer, anIterator);
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
void func_0218EF04(void **connection, GPIPeer *peer)
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
                func_0217D254(1, (char *)4, 1, g_021A4F4C);
                return;
            }
            pprev = pprev->pnext;
        }
        pprev->pnext = peer->pnext;
    }
    while (func_02184200(peer->messages) != 0) {
        message = (GPIMessage *)func_02184208(peer->messages, 0);
        if (message->type < 100)
            func_021888C0(connection, peer->profile, message->type, message->buffer.buffer + message->start);
        func_0218437C((int)peer->messages, 0);
    }
    func_0218EEC0(connection, peer);
}








/*
 * sdk:      gpiProcessPeers (libdwcgsgp.TWL.HYB.a(gpipeer.o))
 */
int func_0218EFEC(void **connection)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;
    GPIPeer *nextPeer;
    GPIPeer *peer;
    int result;

    func_021814EC();
    peer = iconnection->peerList;
    while (peer != 0) {
        nextPeer = peer->pnext;
        if (peer->state == 0x6a) {
            func_0217D254(1, (char *)4, 8, g_021A4F70, peer->profile);
            func_0218EF04(connection, peer);
        } else {
            result = func_0218EE48(connection, peer);
            if (peer->state == 0x6a || result != 0 || func_02184098(0) > peer->timeout) {
                func_0217D254(1, (char *)4, 8, g_021A4F70, peer->profile);
                func_0218EF04(connection, peer);
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
GPIPeer *func_0218F0B8(void **connection, int profileid)
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







void func_0218F134(void **p)
{
    func_0217EAE0(*p);
    *p = 0;
}







/*
 * sdk:      gpiAddPeer (libdwcgsgp.TWL.HYB.a(gpipeer.o))
 */
GPIPeer *func_0218F150(void **connection, int profileid, int initiate)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;
    GPIPeer *peer;

    peer = (GPIPeer *)func_0217EAB0(sizeof(GPIPeer));
    if (peer == 0)
        return 0;
    func_020923B0(peer, 0, sizeof(GPIPeer));
    peer->state = 0x64;
    peer->initiated = initiate;
    peer->profile = profileid;
    peer->timeout = func_02184098(0) + 10000;
    peer->pnext = iconnection->peerList;
    peer->messages = func_02184144(0x18, 0, (void (*)(void *))func_0218F134);
    iconnection->peerList = peer;
    peer->firstOp = 0;
    peer->lastOp = 0;
    peer->ptype = 0;
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
int func_0218F248(void **connection, GPIPeer *peer)
{
    GPIProfile *profile;
    GPIConnection *iconnection;
    int anError;
    int result;
    int aPeerState;

    iconnection = (GPIConnection *)*connection;
    if (!func_0218FD9C(connection, peer->profile, &profile)) {
        func_02193734(connection, g_021A4E7C);
        return 3;
    }
    if (profile->buddyStatusInfo) {
        func_02181010(profile->buddyStatusInfo->ip, profile->buddyStatusInfo->port, &aPeerState);
        if (aPeerState != 1 || aPeerState != 0) {
            anError = func_021810CC(profile->buddyStatusInfo->ip, profile->buddyStatusInfo->port,
                                    iconnection->mHeader, 10000);
            if (anError != 5) {
                func_02193710(connection, 5, g_021A4F8C);
                result = 3;
                func_02189D78(connection, result, 0);
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
int func_0218F350(void **connection, GPIPeer *peer, int type, char *message)
{
    int len;

    if (peer == 0)
        return 3;
    if (message == 0)
        return 3;
    len = func_0209477C((const u8 *)message);
    {
        GPIMessage gpiMessage = {0};
        gpiMessage.type = type;
        {
            int __result__ = func_0218946C(connection, &gpiMessage.buffer, g_021A4FC4);
            if (__result__ != 0)
                return __result__;
        }
        {
            int __result__ = func_0218949C(connection, &gpiMessage.buffer, type);
            if (__result__ != 0)
                return __result__;
        }
        {
            int __result__ = func_0218946C(connection, &gpiMessage.buffer, g_021A4FC8);
            if (__result__ != 0)
                return __result__;
        }
        {
            int __result__ = func_0218949C(connection, &gpiMessage.buffer, len);
            if (__result__ != 0)
                return __result__;
        }
        {
            int __result__ = func_0218946C(connection, &gpiMessage.buffer, g_021A4FD0);
            if (__result__ != 0)
                return __result__;
        }
        gpiMessage.start = gpiMessage.buffer.len;
        {
            int __result__ = func_021893C8(connection, &gpiMessage.buffer, message, len);
            if (__result__ != 0)
                return __result__;
        }
        {
            int __result__ = func_0218934C(connection, &gpiMessage.buffer, 0);
            if (__result__ != 0)
                return __result__;
        }
        func_02184234(peer->messages, &gpiMessage);
        peer->timeout = func_02184098(0) + 10000;
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
    OS_SPrintf(buffer, g_021A4FD8, type, profileid, count, time);
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
int func_0218F51C(void **connection, GPIPeer *peer, char *message, int len)
{
    char buffer[32];
    int result;

    if (peer == 0)
        return 3;
    if (message == 0)
        message = g_021A4FEC;
    if (len == -1)
        len = func_0209477C((const u8 *)message);
    func_02084F40(buffer, g_021A4FF0, len);
    result = func_02189750(connection, peer, buffer);
    if (result != 0)
        return result;
    result = func_0218964C(connection, peer, message, len);
    if (result != 0)
        return result;
    result = gpiSendOrBufferChar(connection, peer, 0);
    if (result != 0)
        return result;
    peer->timeout = func_02184098(0) + 10000;
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
    gsDebugFormat(1, 0, 8, g_021A5000, SOC_InetNtoA(anAddr), port,
                  aPeer->profile);
    aPeer->state = 0x6a;
}




/*
 * sdk:      gpiPeerMessageCallback (libdwcgsgp.TWL.HYB.a gpipeer.o)
 */
void func_0218F65C(unsigned int ip, unsigned short port, unsigned char *message,
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
    aPeer = func_0218F0E8(connection, ip, port);
    if (aPeer == 0) {
        aPeer = (GPIPeer *)func_0218F150(connection, -1, 0);
        if (aPeer != 0) {
            aPeer->state = 0x68;
            aPeer->ip = ip;
            aPeer->port = port;
        } else {
            func_0217D254(1, (char *)2, 1, g_021A5028, func_0215FA9C(anAddr), port);
            return;
        }
    }
    writePos = aPeer->inputBuffer.len;
    size = aPeer->inputBuffer.size;
    buff = aPeer->inputBuffer.buffer;
    if (messageLength > size - writePos) {
        size = writePos + (messageLength < 0x4000 ? 0x4000 : messageLength);
        reallocedBuff = func_0217EAC8(buff, size + 1);
        if (reallocedBuff == 0) {
            func_0217D254(1, (char *)2, 1, g_021A5070, func_0215FA9C(anAddr), port);
            func_0217EAE0(buff);
            func_02193734(connection, g_021A4F1C);
            func_02189D78(connection, 1, 0);
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


void func_0218F7B8(unsigned int ip, unsigned short port, int unused, int rejected, void *userData)
{
    SOCInAddr anAddr;
    GPIPeer *aPeer;

    anAddr.addr = ip;
    aPeer = func_0218F0E8((void **)userData, ip, port);
    if (aPeer == 0) {
        func_0217D254(1, 0, 1, g_021A50BC, func_0215FA9C(anAddr), port);
    } else if (rejected) {
        aPeer->state = 0x6a;
        func_0217D254(1, 0, 8, g_021A50E4, func_0215FA9C(anAddr), port);
        return;
    }
    func_0217D254(1, 0, 8, g_021A5110, func_0215FA9C(anAddr), port);
}
