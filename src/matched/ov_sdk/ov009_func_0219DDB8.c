/*
 * function: TimeoutOldQueries
 * address:  0x0219DDB8
 * packet:   pkt_ov009_0219DDB8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Pops pending servers whose 2500-tick deadline has passed, marking them
 * timed out and reporting each through the callback.
 *
 * sdk:      TimeoutOldQueries (libdwcgsserverbrowsing.TWL.HYB.a sb_queryengine.o)
 * symbols:
 *   current_time     0x0217f264  arm
 *   FIFOGetFirst     0x0219d510  arm
 */

struct _SBServer {
    char pad0[0x15];
    unsigned char flags;
    char pad1[6];
    int field1c;
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

extern unsigned int current_time(void);
extern struct _SBServer *FIFOGetFirst(struct _SBServerFIFO *fifo);

static void TimeoutOldQueries(struct _SBQueryEngine *engine)
{
    unsigned int ctime = current_time();

    if (engine->pending.first == 0)
        return;

    while (engine->pending.first != 0)
    {
        if (ctime <= engine->pending.first->field1c + 0x9c4)
            return;

        engine->pending.first->flags |= 0x10;
        engine->pending.first->field1c = 0x9c4;
        engine->pending.first->flags &= 0xd3;
        engine->callback(engine, 1, engine->pending.first, engine->instance);
        FIFOGetFirst(&engine->pending);
    }
}
