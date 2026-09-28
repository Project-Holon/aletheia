/*
 * function: SBQueryEngineRemoveServerFromFIFOs
 * address:  0x0219DF04
 * packet:   pkt_ov009_0219DF04
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tries the pending FIFO first; only when the server was not there does it
 * attempt the active FIFO.
 *
 * sdk:      SBQueryEngineRemoveServerFromFIFOs (libdwcgsserverbrowsing.TWL.HYB.a sb_queryengine.o)
 * symbols:
 *   FIFORemove       0x0219d544  arm
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

extern int FIFORemove(struct _SBServerFIFO *fifo, struct _SBServer *server);

void SBQueryEngineRemoveServerFromFIFOs(struct _SBQueryEngine *engine,
                                        struct _SBServer *server)
{
    int ret = FIFORemove(&engine->pending, server);

    if (ret != 0)
        return;
    FIFORemove(&engine->active, server);
}
