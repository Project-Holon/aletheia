/*
 * file:     unit_0219DC2C.c
 * unit:     yes
 * function: ProcessIncomingReplies, TimeoutOldQueries, QueueNextQueries, func_0219DE88, func_0219DEE8, func_0219DF04
 * address:  0x0219DC2C
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
 *   CanReceiveOnSocket       0x0217ef50  arm
 *   recvfrom                 0x0217ec60  arm
 *   ParseSingleICMPReply     0x0219dc24  arm
 *   ParseSingleQR2Reply      0x0219d9d8  arm
 *   ParseSingleGOAReply      0x0219db90  arm
 *   current_time     0x0217f264  arm
 *   FIFOGetFirst     0x0219d510  arm
 *   QEStartQuery     0x0219d5c4  arm
 *   FIFORemove       0x0219d544  arm
 */
typedef struct _SBServer {
    unsigned int publicip;
    unsigned short publicport;
    unsigned int privateip;
    unsigned short privateport;
    unsigned int icmpip;
    unsigned char state;
    unsigned char flags;
    void *keyvals;
    unsigned int updatetime;
    unsigned int querychallenge;
    struct _SBServer *next;
    unsigned char splitResponseBitmap;
} _SBServer;

typedef struct _SBServerFIFO {
    _SBServer *first;
    _SBServer *last;
    int count;
} _SBServerFIFO;

typedef struct _SBQueryEngine {
    int queryversion;
    int maxupdates;
    _SBServerFIFO querylist;
    _SBServerFIFO pendinglist;
    int querysock;
    int icmpsock;
    unsigned int mypublicip;
    unsigned char serverkeys[40];
    int numserverkeys;
    void (*ListCallback)(struct _SBQueryEngine *engine, int reason, _SBServer *server, void *instance);
    void *instance;
} _SBQueryEngine;

struct SOCSockAddrIn {
    unsigned short family;
    unsigned short port;
    unsigned int addr;
};

extern int CanReceiveOnSocket(int sock);
extern int recvfrom(int sock, char *buf, int len, int flags,
                    struct SOCSockAddrIn *addr, int *fromlen);
extern int ParseSingleICMPReply(_SBQueryEngine *engine,
                                _SBServer *server, char *data, int len);
extern void ParseSingleQR2Reply(_SBQueryEngine *engine,
                                _SBServer *server, char *data, int len);
extern void ParseSingleGOAReply(_SBQueryEngine *engine,
                                _SBServer *server, char *data, int len);
extern unsigned int current_time(void);
extern _SBServer *FIFOGetFirst(_SBServerFIFO *fifo);
extern void QEStartQuery(_SBQueryEngine *engine, _SBServer *server);
extern int FIFORemove(_SBServerFIFO *fifo, _SBServer *server);
void SBQueryEngineThink(_SBQueryEngine *engine);
/* * Appends the byte while the count at +0x54 is under 0x28. */ void func_0219DEE8(char *p, int v);
void SBQueryEngineRemoveServerFromFIFOs(_SBQueryEngine *engine, _SBServer *server);


static void ProcessIncomingReplies(_SBQueryEngine *engine, int icmpSocket)
{
    int i;
    char indata[2048];
    struct SOCSockAddrIn saddr;
    int saddrlen = 8;
    _SBServer *server;
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


static void TimeoutOldQueries(_SBQueryEngine *engine)
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



static void QueueNextQueries(_SBQueryEngine *engine)
{
    _SBServer *server;

    while (engine->querylist.count < engine->maxupdates && engine->pendinglist.count > 0)
    {
        server = FIFOGetFirst(&engine->pendinglist);
        QEStartQuery(engine, server);
    }
}


void SBQueryEngineThink(_SBQueryEngine *engine)
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


/*
 * Appends the byte while the count at +0x54 is under 0x28.
 */
void func_0219DEE8(char *p, int v)
{
    int n = *(int *)(p + 0x54);

    if (n < 0x28) {
        *(int *)(p + 0x54) = n + 1;
        *(char *)(p + 0x2c + n) = v;
    }
}



void SBQueryEngineRemoveServerFromFIFOs(_SBQueryEngine *engine,
                                        _SBServer *server)
{
    int ret = FIFORemove(&engine->querylist, server);

    if (ret != 0)
        return;
    FIFORemove(&engine->pendinglist, server);
}
