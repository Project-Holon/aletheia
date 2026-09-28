/*
 * function: SBEngineCleanup
 * address:  0x0219D8FC
 * packet:   pkt_ov009_0219D8FC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Closes the engine's socket, marks it invalid, then clears both FIFOs.
 *
 * sdk:      SBEngineCleanup (libdwcgsserverbrowsing.TWL.HYB.a sb_queryengine.o)
 * symbols:
 *   closesocket      0x0217eb2c  arm
 *   FIFOClear        0x0219d5b0  arm
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
};

extern int closesocket(int sock);
extern void FIFOClear(struct _SBServerFIFO *fifo);

void SBEngineCleanup(struct _SBQueryEngine *engine)
{
    closesocket(engine->socket);
    engine->socket = -1;
    FIFOClear(&engine->active);
    FIFOClear(&engine->pending);
}
