/*
 * function: QEStartQuery
 * address:  0x0219D5C4
 * packet:   pkt_ov009_0219D5C4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     wave8: the 140 B / 78-site one-slot callee-saved rotation was the
 *           vendor's `pos` accumulation.  Writing the QR2 header as
 *           `pos = 0; queryBuffer[pos] = ...; pos++;` (instead of constant
 *           indices plus `pos = 7;`) and evaluating `challengeNBO` before the
 *           buffer writes reproduces the image's home of querySuccess in r4
 *           ahead of the params, and its store order.  See
 *           docs/idioms/a-pos-accumulation-settles-a-callee-saved-rotation.md.
 *
 * sdk:      QEStartQuery (libdwcgsserverbrowsing.TWL.HYB.a sb_queryengine.o)
 * symbols:
 *   current_time     0x0217f264  arm
 *   sendto           0x0217eca4  arm
 *   FIFOAddRear      0x0219d4b4  arm
 *   g_021A80E8       0x021a80e8  data
 *   g_021A80F8       0x021a80f8  data
 */

struct _SBServer {
    unsigned int ip;
    unsigned short port;
    char pad6[2];
    unsigned int ip2;
    unsigned short port2;
    char padE[6];
    unsigned char flags;
    unsigned char flags2;
    char pad16[6];
    unsigned char challenge[4];
    unsigned int field20;
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
    unsigned int publicIP;
    unsigned char keybuf[0x28];
    int keycount;
};

struct SOCSockAddrIn {
    unsigned char len;
    unsigned char family;
    unsigned short port;
    unsigned int addr;
};

extern unsigned int current_time(void);
extern int sendto(int sock, char *buf, int len, int flags,
                  struct SOCSockAddrIn *addr, int tolen);
extern void FIFOAddRear(struct _SBServerFIFO *fifo, struct _SBServer *server);
extern unsigned char g_021A80E8[];
extern unsigned char g_021A80F8[];

static void QEStartQuery(struct _SBQueryEngine *engine, struct _SBServer *server)
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
    *(unsigned int *)server->challenge = current_time();

    if (server->flags & 0x20)
        goto done;

    if (engine->queryversion == 1)
    {
        if (server->flags & 0x80)
        {
            queryBuffer[0] = 0xfe;
            queryBuffer[1] = 0xfd;
            queryBuffer[2] = 9;
            __memcpy(&queryBuffer[3], server->challenge, 4);
            queryLen = 7;
            goto send;
        }

        ip = server->field20;
        challengeNBO = ((ip >> 24) & 0xff) |
                       ((ip >> 8) & 0xff00) |
                       ((ip << 8) & 0xff0000) |
                       ((ip << 24) & 0xff000000);
        pos = 0;
        queryBuffer[pos] = 0xfe; pos++;
        queryBuffer[pos] = 0xfd; pos++;
        queryBuffer[pos] = 0; pos++;
        __memcpy(&queryBuffer[pos], server->challenge, 4);
        pos += 4;
        if (challengeNBO != 0)
        {
            __memcpy(&queryBuffer[pos], &challengeNBO, 4);
            pos += 4;
        }

        if (server->flags & 4)
        {
            queryBuffer[pos] = (unsigned char)engine->keycount;
            pos++;
            for (i = 0; i < engine->keycount; i++)
            {
                queryBuffer[pos] = engine->keybuf[i];
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

    if (server->flags & 4)
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
    if (server->ip == engine->publicIP && (server->flags2 & 2))
    {
        saddr.addr = server->ip2;
        saddr.port = server->port2;
    }
    else
    {
        saddr.addr = server->ip;
        saddr.port = server->port;
    }
    sendto(engine->socket, (char *)queryBuffer, queryLen, 0, &saddr, 8);
    querySuccess = 1;

done:
    if (!querySuccess)
    {
        *(unsigned int *)server->challenge = 0;
        return;
    }
    FIFOAddRear(&engine->pending, server);
}
