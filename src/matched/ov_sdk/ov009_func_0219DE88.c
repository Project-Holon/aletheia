/*
 * function: SBQueryEngineThink
 * address:  0x0219DE88
 * packet:   pkt_ov009_0219DE88
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Once per frame: service replies, time out old queries, top up the queue,
 * and signal completion through the callback when nothing is left pending.
 *
 * sdk:      SBQueryEngineThink (libdwcgsserverbrowsing.TWL.HYB.a sb_queryengine.o)
 * symbols:
 *   ProcessIncomingReplies  0x0219dc2c  arm
 *   TimeoutOldQueries       0x0219ddb8  arm
 *   QueueNextQueries        0x0219de48  arm
 */

struct _SBServer {
    char pad[0x24];
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

extern void ProcessIncomingReplies(struct _SBQueryEngine *engine, int icmpSocket);
extern void TimeoutOldQueries(struct _SBQueryEngine *engine);
extern void QueueNextQueries(struct _SBQueryEngine *engine);

void SBQueryEngineThink(struct _SBQueryEngine *engine)
{
    if (engine->pending.count == 0)
        return;

    ProcessIncomingReplies(engine, 0);
    TimeoutOldQueries(engine);

    if (engine->active.count > 0)
        QueueNextQueries(engine);

    if (engine->pending.count == 0)
        engine->callback(engine, 2, 0, engine->instance);
}
