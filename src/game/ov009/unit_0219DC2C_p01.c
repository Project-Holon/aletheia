/*
 * file:     unit_0219DC2C_p01.c
 * unit:     yes
 * function: func_0219DE88, func_0219DEE8, func_0219DF04
 * address:  0x0219DE88
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
 *   ProcessIncomingReplies  0x0219dc2c  arm
 *   TimeoutOldQueries       0x0219ddb8  arm
 *   QueueNextQueries        0x0219de48  arm
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

struct _SBQueryEngine_0219DE88 {
    int queryversion;
    int maxupdates;
    struct _SBServerFIFO pending;
    struct _SBServerFIFO active;
    int socket;
    int field24;
    int field28;
    char keybuf[0x28];
    int keycount;
    void (*callback)(struct _SBQueryEngine_0219DE88 *, int, struct _SBServer *, void *);
    void *instance;
};

struct _SBQueryEngine_0219DF04 {
    int queryversion;
    int maxupdates;
    struct _SBServerFIFO pending;
    struct _SBServerFIFO active;
};

extern void ProcessIncomingReplies(struct _SBQueryEngine_0219DE88 *engine, int icmpSocket);
extern void TimeoutOldQueries(struct _SBQueryEngine_0219DE88 *engine);
extern void QueueNextQueries(struct _SBQueryEngine_0219DE88 *engine);
extern int FIFORemove(struct _SBServerFIFO *fifo, struct _SBServer *server);
void SBQueryEngineThink(struct _SBQueryEngine_0219DE88 *engine);
void func_0219DEE8(char *p, int v);
void SBQueryEngineRemoveServerFromFIFOs(struct _SBQueryEngine_0219DF04 *engine, struct _SBServer *server);


void SBQueryEngineThink(struct _SBQueryEngine_0219DE88 *engine)
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


void SBQueryEngineRemoveServerFromFIFOs(struct _SBQueryEngine_0219DF04 *engine,
                                        struct _SBServer *server)
{
    int ret = FIFORemove(&engine->pending, server);

    if (ret != 0)
        return;
    FIFORemove(&engine->active, server);
}
