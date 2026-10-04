/*
 * function: func_0219D9D8
 * address:  0x0219D9D8
 * packet:   pkt_ov009_0219D9D8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ParseSingleQR2Reply (sb_queryengine.o)
 *
 * symbols:
 *   g_021A7C90  0x021A7C90  data
 *   g_021A8104  0x021A8104  data
 *   func_020964E0  0x020964E0  arm
 *   func_0219D544  0x0219D544  arm  ov009
 *   func_0219D5C4  0x0219D5C4  arm  ov009
 *   func_0219F978  0x0219F978  arm  ov009
 *   func_0219D114  0x0219D114  arm  ov009
 *   func_0219E01C  0x0219E01C  arm  ov009
 *   func_020949F4  0x020949F4  arm
 *   func_0219E5B8  0x0219E5B8  arm  ov009
 *   func_0219E3CC  0x0219E3CC  arm  ov009
 *   func_0217F264  0x0217F264  arm  ov009
 *
 * The split and single branches each carry their own state |= 0x43; the compiler
 * cross-jumps them, which gives the object's popne / b shape after the bitmap test.
 */

typedef struct _SBServer {
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
    struct _SBServer *next;
    unsigned char splitResponseBitmap;
} _SBServer;

typedef struct _SBServerFIFO {
    _SBServer *first;
    _SBServer *last;
    int count;
} _SBServerFIFO;

typedef struct _SBQueryEngine {
    int queryversion;
    int maxupdates;
    _SBServerFIFO querylist;
    _SBServerFIFO pendinglist;
    int querysock;
    int icmpsock;
    unsigned int mypublicip;
    unsigned char serverkeys[40];
    int numserverkeys;
    void (*ListCallback)(struct _SBQueryEngine *engine, int reason, _SBServer *server, void *instance);
    void *instance;
} _SBQueryEngine;

extern char *g_021A7C90[];
extern char g_021A8104[];

typedef unsigned int   u32;
extern int func_020964E0(u32 a0);
extern void func_0219D544(_SBServerFIFO *fifo, _SBServer *server);
extern void func_0219D5C4(_SBQueryEngine *engine, _SBServer *server);
extern int func_0219F978(char *buf, int len);
extern int func_0219D114(char *keyname);
extern void func_0219E01C(_SBServer *server, char *keyname, char *value);
extern int func_020949F4(const char *s1, const char *s2, unsigned int n);
extern void func_0219E5B8(_SBServer *server, char *data, int len);
extern void func_0219E3CC(_SBServer *server, char *data, int len);
extern unsigned int func_0217F264(void);

void func_0219D9D8(_SBQueryEngine *engine, _SBServer *server, char *data, int len)
{
    int i;
    int dlen;

    if (data[0] != 0x00 && data[0] != 0x09)
        return;
    data += 5;
    len -= 5;
    if (server->state & 0x80) {
        server->state &= (unsigned char)~0x80;
        if (len > 0) {
            server->querychallenge = (unsigned int)func_020964E0((u32)data);
            func_0219D544(&engine->querylist, server);
            func_0219D5C4(engine, server);
            engine->ListCallback(engine, 3, server, engine->instance);
            return;
        }
    } else if (server->state & 0x04) {
        for (i = 0; i < engine->numserverkeys; i++) {
            dlen = func_0219F978(data, len);
            if (dlen < 0)
                break;
            if (!func_0219D114(g_021A7C90[engine->serverkeys[i]]))
                func_0219E01C(server, g_021A7C90[engine->serverkeys[i]], data);
            data += dlen;
            len -= dlen;
        }
        server->state |= 0x01 | 0x40;
    } else {
        if (*data && func_020949F4(g_021A8104, data, 8) == 0) {
            func_0219E5B8(server, data, len);
            if (server->splitResponseBitmap != 0xFF)
                return;
            server->state |= 0x02 | 0x01 | 0x40;
        } else {
            func_0219E3CC(server, data, len);
            server->state |= 0x02 | 0x01 | 0x40;
        }
    }
    server->state &= (unsigned char)~(0x04 | 0x08);
    server->updatetime = func_0217F264() - server->updatetime;
    func_0219D544(&engine->querylist, server);
    engine->ListCallback(engine, 0, server, engine->instance);
}
