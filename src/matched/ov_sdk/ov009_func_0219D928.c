/*
 * function: func_0219D928
 * address:  0x0219D928
 * packet:   pkt_ov009_0219D928
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SBQueryEngineUpdateServer (libdwcgsserverbrowsing.TWL.HYB.a(sb_queryengine.o))
 *
 * symbols:
 *   func_0219D5C4  0x0219D5C4  arm  ov009
 *   func_0219D4E8  0x0219D4E8  arm  ov009
 *   func_0219D4B4  0x0219D4B4  arm  ov009
 */

struct SBServer {
    unsigned int publicip;
    unsigned short publicport;
    unsigned int privateip;
    unsigned short privateport;
    unsigned int icmpip;
    unsigned char state;
    unsigned char flags;
    void *keyvals;
    unsigned int updatetime;
    unsigned int querychallenge;
    struct SBServer *next;
    unsigned char splitResponseBitmap;
};

struct SBServerFIFO {
    int a, b, c;
};

struct SBQueryEngine {
    int queryversion;
    int maxupdates;
    struct SBServerFIFO querylist;
    struct SBServerFIFO pendinglist;
};

extern void func_0219D5C4(struct SBQueryEngine *engine, struct SBServer *server);
extern void func_0219D4E8(struct SBServerFIFO *fifo, struct SBServer *server);
extern void func_0219D4B4(struct SBServerFIFO *fifo, struct SBServer *server);

void func_0219D928(struct SBQueryEngine *engine, struct SBServer *server, int addfront, unsigned int querytype, int usequerychallenge)
{
    server->state &= 0x43;
    server->splitResponseBitmap = 0;
    server->querychallenge = 0;
    if (querytype == 2)
        return;
    if (querytype == 0)
        server->state |= 4;
    else if (querytype == 1)
        server->state |= 8;
    else if (querytype == 2)
        server->state |= 0x20;
    else
        return;
    if (usequerychallenge && querytype <= 1)
        server->state |= 0x80;
    if (engine->querylist.c < engine->maxupdates) {
        func_0219D5C4(engine, server);
        return;
    }
    if (addfront)
        func_0219D4E8(&engine->pendinglist, server);
    else
        func_0219D4B4(&engine->pendinglist, server);
}
