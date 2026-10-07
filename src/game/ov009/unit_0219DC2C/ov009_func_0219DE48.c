/*
 * function: QueueNextQueries
 * address:  0x0219DE48
 * packet:   pkt_ov009_0219DE48
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * While the pending count is under the update budget and the active FIFO is
 * non-empty, pop a server and start its query.
 *
 * sdk:      QueueNextQueries (libdwcgsserverbrowsing.TWL.HYB.a sb_queryengine.o)
 * symbols:
 *   FIFOGetFirst     0x0219d510  arm
 *   QEStartQuery     0x0219d5c4  arm
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
};

extern struct _SBServer *FIFOGetFirst(struct _SBServerFIFO *fifo);
extern void QEStartQuery(struct _SBQueryEngine *engine, struct _SBServer *server);

static void QueueNextQueries(struct _SBQueryEngine *engine)
{
    struct _SBServer *server;

    while (engine->pending.count < engine->maxupdates && engine->active.count > 0)
    {
        server = FIFOGetFirst(&engine->active);
        QEStartQuery(engine, server);
    }
}
