/*
 * function: ParseSingleGOAReply
 * address:  0x0219DB90
 * packet:   pkt_ov009_0219DB90
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Parses the key/value block, and only for a final reply marks the server
 * replied (clearing the timeout bits, writing the query age back into the
 * start-time field) and removes it from the pending FIFO. The callback fires
 * with reason 0.
 *
 * sdk:      ParseSingleGOAReply (libdwcgsserverbrowsing.TWL.HYB.a sb_queryengine.o)
 * symbols:
 *   strstr                   0x02094b20  arm
 *   SBServerParseKeyVals     0x0219e33c  arm
 *   current_time             0x0217f264  arm
 *   FIFORemove               0x0219d544  arm
 *   gSbQueryFinal               0x021a8110  data
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
    unsigned int field1c;
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
    void (*callback)(struct _SBQueryEngine *, int, struct _SBServer *, void *);
    void *instance;
};

extern char *strstr(const char *haystack, const char *needle);
extern void SBServerParseKeyVals(struct _SBServer *server, char *keyvals);
extern unsigned int current_time(void);
extern int FIFORemove(struct _SBServerFIFO *fifo, struct _SBServer *server);
extern char gSbQueryFinal[];

static void ParseSingleGOAReply(struct _SBQueryEngine *engine,
                                struct _SBServer *server, char *data)
{
    int isfinal = strstr(data, gSbQueryFinal) != 0;
    unsigned char flags;

    SBServerParseKeyVals(server, data);
    if (!isfinal)
        return;

    if (server->flags & 4)
        flags = server->flags | 0x41;
    else
        flags = server->flags | 0x42;
    server->flags = flags & 0xf3;

    server->field1c = current_time() - server->field1c;
    FIFORemove(&engine->pending, server);
    engine->callback(engine, 0, server, engine->instance);
}
