/*
 * function: SBServerListConnectAndQuery
 * address:  0x0219FFD4
 * packet:   pkt_ov009_0219FFD4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SBServerListConnectAndQuery (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 *
 * symbols:
 *   strlen  0x0209477C  arm
 *   ServerListConnect  0x0219FBB8  arm  ov009
 *   SetupListChallenge  0x0219FE44  arm  ov009
 *   BufferAddByte  0x0219FD40  arm  ov009
 *   BufferAddIntLE  0x0219FDB8  arm  ov009
 *   BufferAddNTS  0x0219FCF0  arm  ov009
 *   BufferAddData  0x0219FE10  arm  ov009
 *   BufferAddInt  0x0219FD64  arm  ov009
 *   func_0217EC90  0x0217EC90  arm  ov009
 *   SBServerListDisconnect  0x021A02E0  arm  ov009
 *   func_0217EAB0  0x0217EAB0  arm  ov009
 *   gSBEmptyString  0x021A8230  data
 */

#include "../arm9_sdk/libc/string.h"

#define SWAP16(x) ((unsigned short)((((x) >> 8) & 0xff) | (((x) << 8) & 0xff00)))
#define SWAP32(x) ((((x) >> 24) & 0xff) | (((x) >> 8) & 0xff00) | (((x) << 8) & 0xff0000) | (((x) << 24) & 0xff000000))

typedef struct SBServerList {
    int state;
    void *servers;
    void *keylist;
    char queryforgamename[36];
    char queryfromgamename[36];
    char queryfromkey[32];
    char mychallenge[8];
    char *inbuffer;
    int inbufferlen;
    char pad84[0x6a8 - 0x84];
    unsigned int srcip;
    unsigned short defaultport;
    char *lasterror;
    int slsocket;
    unsigned int lanstarttime;
    int fromgamever;
    char pad6c0[0x7c8 - 0x6c0];
    int queryoptions;
    int pstate;
} SBServerList;

typedef enum {
    sbe_noerror,
    sbe_socketerror,
    sbe_dnserror,
    sbe_connecterror,
    sbe_dataerror,
    sbe_allocerror,
    sbe_paramerror,
    sbe_duplicateupdateerror
} SBError;

extern SBError ServerListConnect(SBServerList *slist);
extern void SetupListChallenge(SBServerList *slist);
extern void BufferAddByte(char **buffer, unsigned char bval, int *len);
extern void BufferAddIntLE(char **buffer, int ival, int *len);
extern void BufferAddNTS(char **buffer, char *str, int *len);
extern void BufferAddData(char **buffer, char *data, int dlen, int *len);
extern void BufferAddInt(char **buffer, int ival, int *len);
extern int func_0217EC90(int sock, char *buf, int len, int flags);
extern void SBServerListDisconnect(SBServerList *slist);
extern void *func_0217EAB0(unsigned long size);
extern char gSBEmptyString[];

SBError SBServerListConnectAndQuery(SBServerList *slist, char *fieldList, char *serverFilter, int options, int maxServers)
{
    SBError err;
    int ret;
    int requestLen;
    unsigned short netLen;
    char *requestBuf;
    char outgoingRequest[1023];

    if (fieldList == 0)
        fieldList = gSBEmptyString;
    if (serverFilter == 0)
        serverFilter = gSBEmptyString;
    if (strlen(fieldList) > 256)
        return sbe_paramerror;
    if (strlen(serverFilter) > 511)
        return sbe_paramerror;
    err = ServerListConnect(slist);
    if (err != sbe_noerror)
        return err;
    slist->queryoptions = options;
    SetupListChallenge(slist);
    requestLen = 2;
    requestBuf = outgoingRequest + 2;
    BufferAddByte(&requestBuf, 0, &requestLen);
    BufferAddByte(&requestBuf, 1, &requestLen);
    BufferAddByte(&requestBuf, 3, &requestLen);
    BufferAddIntLE(&requestBuf, slist->fromgamever, &requestLen);
    BufferAddNTS(&requestBuf, slist->queryforgamename, &requestLen);
    BufferAddNTS(&requestBuf, slist->queryfromgamename, &requestLen);
    BufferAddData(&requestBuf, slist->mychallenge, 8, &requestLen);
    BufferAddNTS(&requestBuf, serverFilter, &requestLen);
    BufferAddNTS(&requestBuf, fieldList, &requestLen);
    BufferAddInt(&requestBuf, SWAP32((unsigned int)options), &requestLen);
    if (slist->queryoptions & 8)
        BufferAddInt(&requestBuf, slist->srcip, &requestLen);
    if (slist->queryoptions & 0x80)
        BufferAddIntLE(&requestBuf, maxServers, &requestLen);
    netLen = SWAP16((unsigned short)requestLen);
    memcpy(outgoingRequest, &netLen, 2);
    ret = func_0217EC90(slist->slsocket, outgoingRequest, requestLen, 0);
    if (ret <= 0) {
        SBServerListDisconnect(slist);
        return sbe_connecterror;
    }
    slist->state = 3;
    slist->pstate = 0;
    if (slist->inbuffer == 0) {
        slist->inbuffer = func_0217EAB0(0x1000);
        if (slist->inbuffer == 0)
            return sbe_allocerror;
        slist->inbufferlen = 0;
    }
    return sbe_noerror;
}
