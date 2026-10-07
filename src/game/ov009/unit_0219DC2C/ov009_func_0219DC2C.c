/*
 * function: ProcessIncomingReplies
 * address:  0x0219DC2C
 * packet:   pkt_ov009_0219DC2C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Drains the receive socket, then walks the pending FIFO matching each
 * datagram's address against the server's key and alternate address; a
 * match is handed to the QR2, GOA or ICMP reply parser.
 *
 * sdk:      ProcessIncomingReplies (libdwcgsserverbrowsing.TWL.HYB.a sb_queryengine.o)
 * symbols:
 *   CanReceiveOnSocket       0x0217ef50  arm
 *   recvfrom                 0x0217ec60  arm
 *   ParseSingleICMPReply     0x0219dc24  arm
 *   ParseSingleQR2Reply      0x0219d9d8  arm
 *   ParseSingleGOAReply      0x0219db90  arm
 */

struct _SBServer {
    unsigned int ip;
    unsigned short port;
    char pad6[2];
    unsigned int ip2;
    unsigned short port2;
    char padE[2];
    unsigned int field10;
    char pad14;
    unsigned char flags;
    char pad16[14];
    struct _SBServer *next;
};

struct _SBServerFIFO {
    struct _SBServer *first;
    struct _SBServer *last;
    int count;
};

struct _SBQueryEngine {
    int queryversion;
    int maxupdates;
    struct _SBServerFIFO pending;
    struct _SBServerFIFO active;
    int socket;
    int field24;
    int field28;
    char keybuf[0x28];
    int keycount;
    void (*callback)(struct _SBQueryEngine *, int, struct _SBServer *, void *);
    void *instance;
};

struct SOCSockAddrIn {
    unsigned short family;
    unsigned short port;
    unsigned int addr;
};

extern int CanReceiveOnSocket(int sock);
extern int recvfrom(int sock, char *buf, int len, int flags,
                    struct SOCSockAddrIn *addr, int *fromlen);
extern int ParseSingleICMPReply(struct _SBQueryEngine *engine,
                                struct _SBServer *server, char *data, int len);
extern void ParseSingleQR2Reply(struct _SBQueryEngine *engine,
                                struct _SBServer *server, char *data, int len);
extern void ParseSingleGOAReply(struct _SBQueryEngine *engine,
                                struct _SBServer *server, char *data, int len);

static void ProcessIncomingReplies(struct _SBQueryEngine *engine, int icmpSocket)
{
    int i;
    char indata[2048];
    struct SOCSockAddrIn saddr;
    int saddrlen = 8;
    struct _SBServer *server;
    int recvSock = 0;

    if (icmpSocket == 0)
        recvSock = engine->socket;

    if (!CanReceiveOnSocket(recvSock))
        return;

    for (;;)
    {
        i = recvfrom(recvSock, indata, 0x7ff, 0, &saddr, &saddrlen);
        if (i == -1)
            return;
        indata[i] = 0;

        for (server = engine->pending.first; server != 0; server = server->next)
        {
            if (icmpSocket != 0 && (server->flags & 8) != 0 &&
                server->field10 == saddr.addr)
                goto matched;

            if (server->ip == saddr.addr &&
                (server->port == saddr.port || icmpSocket != 0))
                goto matched;

            if (server->ip != engine->field28)
                continue;
            if ((server->flags & 2) == 0)
                continue;
            if (server->ip2 != saddr.addr)
                continue;
            if (server->port2 != saddr.port)
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
