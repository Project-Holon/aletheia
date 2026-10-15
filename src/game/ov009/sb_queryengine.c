/*
 * file:     sb_queryengine.c
 * unit:     yes
 * function: FIFOAddRear, FIFOAddFront, FIFOGetFirst, FIFORemove, FIFOClear, QEStartQuery, SBQueryEngineInit, func_0219D8D8, SBEngineHaltUpdates, SBEngineCleanup, SBQueryEngineUpdateServer, ParseSingleQR2Reply, ParseSingleGOAReply, ParseSingleICMPReply, ProcessIncomingReplies, TimeoutOldQueries, QueueNextQueries, SBQueryEngineThink, SBQueryEngineAddQueryKey, SBQueryEngineRemoveServerFromFIFOs
 * address:  0x0219D4B4
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * GameSpy server browsing query engine, vendor object sb_queryengine.o
 * (libdwcgsserverbrowsing.TWL.HYB.a), merged from five unit files.
 *
 * SBQueryEngineSetPublicIP (0x0219D8D8) is 8 bytes: str r1, [r0, #0x28] ; bx lr.
 * ParseSingleICMPReply (0x0219DC24) returns the constant 1, so that its caller
 * can be compiled as a tail call.
 *
 * symbols:
 *   current_time     0x0217f264  arm
 *   sendto           0x0217eca4  arm
 *   FIFOAddRear      0x0219d4b4  arm
 *   g_021A80E8       0x021a80e8  data
 *   g_021A80F8       0x021a80f8  data
 *   SocketStartUp    0x0217f25c  arm
 *   socket           0x0217eb18  arm
 *   FIFOClear        0x0219d5b0  arm
 *   __GSIACResult    0x021acef8  data
 *   closesocket      0x0217eb2c  arm
 *   QEStartQuery  0x0219D5C4  arm  ov009
 *   g_021A7C90  0x021A7C90  data
 *   g_021A8104  0x021A8104  data
 *   atoi  0x020964E0  arm
 *   FIFORemove  0x0219D544  arm  ov009
 *   NTSLengthSB  0x0219F978  arm  ov009
 *   func_0219D114  0x0219D114  arm  ov009
 *   func_0219E01C  0x0219E01C  arm  ov009
 *   strncmp  0x020949F4  arm
 *   func_0219E5B8  0x0219E5B8  arm  ov009
 *   func_0219E3CC  0x0219E3CC  arm  ov009
 *   current_time  0x0217F264  arm  ov009
 *   strstr                   0x02094b20  arm
 *   SBServerParseKeyVals     0x0219e33c  arm
 *   g_021A8110               0x021a8110  data
 *   CanReceiveOnSocket       0x0217ef50  arm
 *   recvfrom                 0x0217ec60  arm
 *   ParseSingleQR2Reply      0x0219d9d8  arm
 */
#include "sb_server_types.h"

struct SOCSockAddrIn {
    unsigned char len;
    unsigned char family;
    unsigned short port;
    unsigned int addr;
};

typedef unsigned int   u32;

typedef unsigned char  u8;

extern unsigned int current_time(void);
extern int sendto(int sock, char *buf, int len, int flags,
                  struct SOCSockAddrIn *addr, int tolen);
extern void FIFOAddRear(SBServerFIFO *fifo, SBServer *server);
extern void SocketStartUp(void);
extern int socket(int pf, int type, int protocol);
extern void FIFOClear(SBServerFIFO *fifo);
extern int closesocket(int sock);
extern void QEStartQuery(SBQueryEngine *engine, SBServer *server);
extern int atoi(u32 a0);
int FIFORemove(SBServerFIFO *fifo, SBServer *server);
extern int NTSLengthSB(char *buf, int len);
extern int func_0219D114(char *keyname);
extern void func_0219E01C(SBServer *server, char *keyname, char *value);
extern int strncmp(const u8 *s1, const u8 *s2, u32 n);
extern void func_0219E5B8(SBServer *server, char *data, int len);
extern void func_0219E3CC(SBServer *server, char *data, int len);
extern char *strstr(const char *haystack, const char *needle);
extern void SBServerParseKeyVals(SBServer *server, char *keyvals);
extern int CanReceiveOnSocket(int sock);
extern int recvfrom(int sock, char *buf, int len, int flags,
                    struct SOCSockAddrIn *addr, int *fromlen);
extern void ParseSingleQR2Reply(SBQueryEngine *engine,
                                SBServer *server, char *data, int len);
void FIFOAddFront(SBServerFIFO *fifo, SBServer *server);
SBServer *FIFOGetFirst(SBServerFIFO *fifo);
void SBQueryEngineInit(SBQueryEngine *engine, int maxupdates, int queryversion, int lanBrowse, SBEngineCB callback, void *instance);
void func_0219D8D8(SBQueryEngine *engine, unsigned int publicip);
void SBEngineHaltUpdates(SBQueryEngine *engine);
void SBEngineCleanup(SBQueryEngine *engine);
void SBQueryEngineUpdateServer(SBQueryEngine *engine, SBServer *server, int addfront, unsigned int querytype, int usequerychallenge);
int ParseSingleICMPReply(SBQueryEngine *engine, SBServer *server, char *data, int len);
void SBQueryEngineThink(SBQueryEngine *engine);
void SBQueryEngineAddQueryKey(SBQueryEngine *engine, unsigned char key);
void SBQueryEngineRemoveServerFromFIFOs(SBQueryEngine *engine, SBServer *server);
extern unsigned char g_021A80E8[];
extern unsigned char g_021A80F8[];
extern int __GSIACResult;
extern char *g_021A7C90[];
extern char g_021A8104[];
extern char g_021A8110[];



void FIFOAddRear(SBServerFIFO *fifo, SBServer *server)
{
    if (fifo->last != 0)
        fifo->last->next = server;
    fifo->last = server;
    server->next = 0;
    if (fifo->first == 0)
        fifo->first = server;
    fifo->count++;
}



void FIFOAddFront(SBServerFIFO *fifo, SBServer *server)
{
    server->next = fifo->first;
    fifo->first = server;
    if (fifo->last == 0)
        fifo->last = server;
    fifo->count++;
}




SBServer *FIFOGetFirst(SBServerFIFO *fifo)
{
    SBServer *hold = fifo->first;

    if (hold != 0)
    {
        fifo->first = hold->next;
        if (fifo->first == 0)
            fifo->last = 0;
        fifo->count = fifo->count - 1;
    }
    return hold;
}




int FIFORemove(SBServerFIFO *fifo, SBServer *server)
{
    SBServer *hold = fifo->first;
    SBServer *prev = 0;

    while (hold != 0)
    {
        if (hold == server)
        {
            if (prev != 0)
                prev->next = hold->next;
            if (fifo->first == hold)
                fifo->first = hold->next;
            if (fifo->last == hold)
                fifo->last = prev;
            fifo->count = fifo->count - 1;
            return 1;
        }
        prev = hold;
        hold = hold->next;
    }
    return 0;
}



void FIFOClear(SBServerFIFO *fifo)
{
    fifo->last = 0;
    fifo->first = 0;
    fifo->count = 0;
}




static void QEStartQuery(SBQueryEngine *engine, SBServer *server)
{
    int querySuccess = 0;
    unsigned char queryBuffer[256];
    int queryLen;
    struct SOCSockAddrIn saddr;
    unsigned int challengeNBO;
    unsigned int ip;
    int pos;
    int i;

    saddr.family = 2;
    server->updatetime = current_time();

    if (server->state & 0x20)
        goto done;

    if (engine->queryversion == 1)
    {
        if (server->state & 0x80)
        {
            queryBuffer[0] = 0xfe;
            queryBuffer[1] = 0xfd;
            queryBuffer[2] = 9;
            __memcpy(&queryBuffer[3], &server->updatetime, 4);
            queryLen = 7;
            goto send;
        }

        ip = server->querychallenge;
        challengeNBO = ((ip >> 24) & 0xff) |
                       ((ip >> 8) & 0xff00) |
                       ((ip << 8) & 0xff0000) |
                       ((ip << 24) & 0xff000000);
        pos = 0;
        queryBuffer[pos] = 0xfe; pos++;
        queryBuffer[pos] = 0xfd; pos++;
        queryBuffer[pos] = 0; pos++;
        __memcpy(&queryBuffer[pos], &server->updatetime, 4);
        pos += 4;
        if (challengeNBO != 0)
        {
            __memcpy(&queryBuffer[pos], &challengeNBO, 4);
            pos += 4;
        }

        if (server->state & 4)
        {
            queryBuffer[pos] = (unsigned char)engine->numserverkeys;
            pos++;
            for (i = 0; i < engine->numserverkeys; i++)
            {
                queryBuffer[pos] = engine->serverkeys[i];
                pos++;
            }
            queryBuffer[pos] = 0;
            queryBuffer[pos + 1] = 0;
            queryLen = pos + 2;
        }
        else
        {
            queryBuffer[pos] = 0xff;
            queryBuffer[pos + 1] = 0xff;
            queryBuffer[pos + 2] = 0xff;
            queryBuffer[pos + 3] = 1;
            queryLen = pos + 4;
        }
        goto send;
    }

    if (server->state & 4)
    {
        __memcpy(queryBuffer, g_021A80E8, 13);
        queryLen = 13;
    }
    else
    {
        __memcpy(queryBuffer, g_021A80F8, 8);
        queryLen = 8;
    }

send:
    if (server->publicip == engine->mypublicip && (server->flags & 2))
    {
        saddr.addr = server->privateip;
        saddr.port = server->privateport;
    }
    else
    {
        saddr.addr = server->publicip;
        saddr.port = server->publicport;
    }
    sendto(engine->querysock, (char *)queryBuffer, queryLen, 0, &saddr, 8);
    querySuccess = 1;

done:
    if (!querySuccess)
    {
        server->updatetime = 0;
        return;
    }
    FIFOAddRear(&engine->querylist, server);
}




void SBQueryEngineInit(SBQueryEngine *engine, int maxupdates,
                       int queryversion, int lanBrowse,
                       SBEngineCB callback,
                       void *instance)
{
    if (lanBrowse == 0 && __GSIACResult != 1)
        return;

    SocketStartUp();

    engine->queryversion = queryversion;
    engine->maxupdates = maxupdates;
    engine->numserverkeys = 0;
    engine->ListCallback = callback;
    engine->instance = instance;
    engine->mypublicip = 0;
    engine->querysock = socket(2, 2, 0);
    FIFOClear(&engine->pendinglist);
    FIFOClear(&engine->querylist);
}


void func_0219D8D8(SBQueryEngine *engine, unsigned int publicip)
{
    engine->mypublicip = publicip;
}





void SBEngineHaltUpdates(SBQueryEngine *engine)
{
    FIFOClear(&engine->pendinglist);
    FIFOClear(&engine->querylist);
}






void SBEngineCleanup(SBQueryEngine *engine)
{
    closesocket(engine->querysock);
    engine->querysock = -1;
    FIFOClear(&engine->pendinglist);
    FIFOClear(&engine->querylist);
}





/*
 * sdk:      SBQueryEngineUpdateServer (libdwcgsserverbrowsing.TWL.HYB.a(sb_queryengine.o))
 */
void SBQueryEngineUpdateServer(SBQueryEngine *engine, SBServer *server, int addfront, unsigned int querytype, int usequerychallenge)
{
    server->state &= 0x43;
    server->splitResponseBitmap = 0;
    server->querychallenge = 0;
    if (querytype == 2)
        return;
    if (querytype == 0)
        server->state |= 4;
    else if (querytype == 1)
        server->state |= 8;
    else if (querytype == 2)
        server->state |= 0x20;
    else
        return;
    if (usequerychallenge && querytype <= 1)
        server->state |= 0x80;
    if (engine->querylist.count < engine->maxupdates) {
        QEStartQuery(engine, server);
        return;
    }
    if (addfront)
        FIFOAddFront(&engine->pendinglist, server);
    else
        FIFOAddRear(&engine->pendinglist, server);
}




void ParseSingleQR2Reply(SBQueryEngine *engine, SBServer *server, char *data, int len)
{
    int i;
    int dlen;

    if (data[0] != 0x00 && data[0] != 0x09)
        return;
    data += 5;
    len -= 5;
    if (server->state & 0x80) {
        server->state &= (unsigned char)~0x80;
        if (len > 0) {
            server->querychallenge = (unsigned int)atoi((u32)data);
            FIFORemove(&engine->querylist, server);
            QEStartQuery(engine, server);
            engine->ListCallback(engine, 3, server, engine->instance);
            return;
        }
    } else if (server->state & 0x04) {
        for (i = 0; i < engine->numserverkeys; i++) {
            dlen = NTSLengthSB(data, len);
            if (dlen < 0)
                break;
            if (!func_0219D114(g_021A7C90[engine->serverkeys[i]]))
                func_0219E01C(server, g_021A7C90[engine->serverkeys[i]], data);
            data += dlen;
            len -= dlen;
        }
        server->state |= 0x01 | 0x40;
    } else {
        if (*data && strncmp((const u8 *)g_021A8104, (const u8 *)data, 8) == 0) {
            func_0219E5B8(server, data, len);
            if (server->splitResponseBitmap != 0xFF)
                return;
            server->state |= 0x02 | 0x01 | 0x40;
        } else {
            func_0219E3CC(server, data, len);
            server->state |= 0x02 | 0x01 | 0x40;
        }
    }
    server->state &= (unsigned char)~(0x04 | 0x08);
    server->updatetime = current_time() - server->updatetime;
    FIFORemove(&engine->querylist, server);
    engine->ListCallback(engine, 0, server, engine->instance);
}



static void ParseSingleGOAReply(SBQueryEngine *engine,
                                SBServer *server, char *data, int len)
{
    int isfinal = strstr(data, g_021A8110) != 0;
    unsigned char flags;

    SBServerParseKeyVals(server, data);
    if (!isfinal)
        return;

    if (server->state & 4)
        flags = server->state | 0x41;
    else
        flags = server->state | 0x42;
    server->state = flags & 0xf3;

    server->updatetime = current_time() - server->updatetime;
    FIFORemove(&engine->querylist, server);
    engine->ListCallback(engine, 0, server, engine->instance);
}

int ParseSingleICMPReply(SBQueryEngine *engine, SBServer *server, char *data, int len)
{
    return 1;
}



static void ProcessIncomingReplies(SBQueryEngine *engine, int icmpSocket)
{
    int i;
    char indata[2048];
    struct SOCSockAddrIn saddr;
    int saddrlen = 8;
    SBServer *server;
    int recvSock = 0;

    if (icmpSocket == 0)
        recvSock = engine->querysock;

    if (!CanReceiveOnSocket(recvSock))
        return;

    for (;;)
    {
        i = recvfrom(recvSock, indata, 0x7ff, 0, &saddr, &saddrlen);
        if (i == -1)
            return;
        indata[i] = 0;

        for (server = engine->querylist.first; server != 0; server = server->next)
        {
            if (icmpSocket != 0 && (server->flags & 8) != 0 &&
                server->icmpip == saddr.addr)
                goto matched;

            if (server->publicip == saddr.addr &&
                (server->publicport == saddr.port || icmpSocket != 0))
                goto matched;

            if (server->publicip != engine->mypublicip)
                continue;
            if ((server->flags & 2) == 0)
                continue;
            if (server->privateip != saddr.addr)
                continue;
            if (server->privateport != saddr.port)
                continue;

        matched:
            if (icmpSocket != 0)
            {
                if (ParseSingleICMPReply(engine, server, indata, i) != 0)
                    goto done;
            }
            else if (engine->queryversion == 1)
            {
                ParseSingleQR2Reply(engine, server, indata, i);
                goto done;
            }
            else
            {
                ParseSingleGOAReply(engine, server, indata, i);
                goto done;
            }
        }

    done:
        if (!CanReceiveOnSocket(recvSock))
            return;
    }
}



static void TimeoutOldQueries(SBQueryEngine *engine)
{
    unsigned int ctime = current_time();

    if (engine->querylist.first == 0)
        return;

    while (engine->querylist.first != 0)
    {
        if (ctime <= engine->querylist.first->updatetime + 0x9c4)
            return;

        engine->querylist.first->flags |= 0x10;
        engine->querylist.first->updatetime = 0x9c4;
        engine->querylist.first->flags &= 0xd3;
        engine->ListCallback(engine, 1, engine->querylist.first, engine->instance);
        FIFOGetFirst(&engine->querylist);
    }
}




static void QueueNextQueries(SBQueryEngine *engine)
{
    SBServer *server;

    while (engine->querylist.count < engine->maxupdates && engine->pendinglist.count > 0)
    {
        server = FIFOGetFirst(&engine->pendinglist);
        QEStartQuery(engine, server);
    }
}



void SBQueryEngineThink(SBQueryEngine *engine)
{
    if (engine->querylist.count == 0)
        return;

    ProcessIncomingReplies(engine, 0);
    TimeoutOldQueries(engine);

    if (engine->pendinglist.count > 0)
        QueueNextQueries(engine);

    if (engine->querylist.count == 0)
        engine->ListCallback(engine, 2, 0, engine->instance);
}



void SBQueryEngineAddQueryKey(SBQueryEngine *engine, unsigned char key)
{
    int n = engine->numserverkeys;

    if (n < 0x28) {
        engine->numserverkeys = n + 1;
        engine->serverkeys[n] = key;
    }
}



void SBQueryEngineRemoveServerFromFIFOs(SBQueryEngine *engine,
                                        SBServer *server)
{
    int ret = FIFORemove(&engine->querylist, server);

    if (ret != 0)
        return;
    FIFORemove(&engine->pendinglist, server);
}
