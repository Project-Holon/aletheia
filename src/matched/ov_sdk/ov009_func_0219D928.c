/*
 * function: SBQueryEngineUpdateServer
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
 *   QEStartQuery  0x0219D5C4  arm  ov009
 *   FIFOAddFront  0x0219D4E8  arm  ov009
 *   FIFOAddRear  0x0219D4B4  arm  ov009
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

extern void QEStartQuery(struct SBQueryEngine *engine, struct SBServer *server);
extern void FIFOAddFront(int **p, int *q);
extern void FIFOAddRear(int *p, int *n);

void SBQueryEngineUpdateServer(struct SBQueryEngine *engine, struct SBServer *server, int addfront, unsigned int querytype, int usequerychallenge)
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
        QEStartQuery(engine, server);
        return;
    }
    if (addfront)
        FIFOAddFront((int **)(&engine->pendinglist), (int *)server);
    else
        FIFOAddRear((int *)(&engine->pendinglist), (int *)server);
}
