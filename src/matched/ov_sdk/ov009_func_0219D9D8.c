/*
 * function: ParseSingleQR2Reply
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
 *   gQr2RegKeys  0x021A7C90  data
 *   gSbQuerySplitNum  0x021A8104  data
 *   atoi  0x020964E0  arm
 *   FIFORemove  0x0219D544  arm  ov009
 *   QEStartQuery  0x0219D5C4  arm  ov009
 *   NTSLengthSB  0x0219F978  arm  ov009
 *   qr2_internal_is_master_only_key  0x0219D114  arm  ov009
 *   func_0219E01C  0x0219E01C  arm  ov009
 *   strncmp  0x020949F4  arm
 *   SBServerParseQR2FullKeysSplit  0x0219E5B8  arm  ov009
 *   SBServerParseQR2FullKeysSingle  0x0219E3CC  arm  ov009
 *   current_time  0x0217F264  arm  ov009
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

extern char *gQr2RegKeys[];
extern char gSbQuerySplitNum[];

typedef unsigned int   u32;
extern int atoi(u32 a0);
extern void FIFORemove(_SBServerFIFO *fifo, _SBServer *server);
extern void QEStartQuery(_SBQueryEngine *engine, _SBServer *server);
extern int NTSLengthSB(char *buf, int len);
extern int qr2_internal_is_master_only_key(char *keyname);
extern void func_0219E01C(_SBServer *server, char *keyname, char *value);
typedef unsigned char  u8;
extern int strncmp(const u8 *s1, const u8 *s2, u32 n);
extern void SBServerParseQR2FullKeysSplit(_SBServer *server, char *data, int len);
extern void SBServerParseQR2FullKeysSingle(_SBServer *server, char *data, int len);
extern unsigned int current_time(void);

void ParseSingleQR2Reply(_SBQueryEngine *engine, _SBServer *server, char *data, int len)
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
            server->querychallenge = (unsigned int)atoi((u32)data);
            FIFORemove(&engine->querylist, server);
            QEStartQuery(engine, server);
            engine->ListCallback(engine, 3, server, engine->instance);
            return;
        }
    } else if (server->state & 0x04) {
        for (i = 0; i < engine->numserverkeys; i++) {
            dlen = NTSLengthSB(data, len);
            if (dlen < 0)
                break;
            if (!qr2_internal_is_master_only_key(gQr2RegKeys[engine->serverkeys[i]]))
                func_0219E01C(server, gQr2RegKeys[engine->serverkeys[i]], data);
            data += dlen;
            len -= dlen;
        }
        server->state |= 0x01 | 0x40;
    } else {
        if (*data && strncmp((const u8 *)gSbQuerySplitNum, (const u8 *)data, 8) == 0) {
            SBServerParseQR2FullKeysSplit(server, data, len);
            if (server->splitResponseBitmap != 0xFF)
                return;
            server->state |= 0x02 | 0x01 | 0x40;
        } else {
            SBServerParseQR2FullKeysSingle(server, data, len);
            server->state |= 0x02 | 0x01 | 0x40;
        }
    }
    server->state &= (unsigned char)~(0x04 | 0x08);
    server->updatetime = current_time() - server->updatetime;
    FIFORemove(&engine->querylist, server);
    engine->ListCallback(engine, 0, server, engine->instance);
}
