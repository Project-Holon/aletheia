/*
 * function: SBQueryEngineInit
 * address:  0x0219D864
 * packet:   pkt_ov009_0219D864
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Brings up the socket layer, then initialises the two FIFOs, the update
 * budget, the query version, the key buffer and the completion callback.
 *
 * sdk:      SBQueryEngineInit (libdwcgsserverbrowsing.TWL.HYB.a sb_queryengine.o)
 * symbols:
 *   SocketStartUp    0x0217f25c  arm
 *   socket           0x0217eb18  arm
 *   FIFOClear        0x0219d5b0  arm
 *   __GSIACResult    0x021acef8  data
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

extern void SocketStartUp(void);
extern int socket(int pf, int type, int protocol);
extern void FIFOClear(struct _SBServerFIFO *fifo);
extern int __GSIACResult;

void SBQueryEngineInit(struct _SBQueryEngine *engine, int maxupdates,
                       int queryversion, int lanBrowse,
                       void (*callback)(struct _SBQueryEngine *, int,
                                        struct _SBServer *, void *),
                       void *instance)
{
    if (lanBrowse == 0 && __GSIACResult != 1)
        return;

    SocketStartUp();

    engine->queryversion = queryversion;
    engine->maxupdates = maxupdates;
    engine->keycount = 0;
    engine->callback = callback;
    engine->instance = instance;
    engine->field28 = 0;
    engine->socket = socket(2, 2, 0);
    FIFOClear(&engine->active);
    FIFOClear(&engine->pending);
}
