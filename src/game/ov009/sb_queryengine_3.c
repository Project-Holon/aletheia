/*
 * file:     sb_queryengine_3.c
 * unit:     yes
 * function: func_0219D8E0, func_0219D8FC, func_0219D928, func_0219D9D8, ParseSingleGOAReply
 * address:  0x0219D8E0
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
 *   func_0219D5B0  0x0219D5B0  arm  ov009
 *   closesocket      0x0217eb2c  arm
 *   FIFOClear        0x0219d5b0  arm
 *   func_0219D5C4  0x0219D5C4  arm  ov009
 *   func_0219D4E8  0x0219D4E8  arm  ov009
 *   func_0219D4B4  0x0219D4B4  arm  ov009
 *   g_021A7C90  0x021A7C90  data
 *   g_021A8104  0x021A8104  data
 *   func_020964E0  0x020964E0  arm
 *   func_0219D544  0x0219D544  arm  ov009
 *   func_0219F978  0x0219F978  arm  ov009
 *   func_0219D114  0x0219D114  arm  ov009
 *   func_0219E01C  0x0219E01C  arm  ov009
 *   func_020949F4  0x020949F4  arm
 *   func_0219E5B8  0x0219E5B8  arm  ov009
 *   func_0219E3CC  0x0219E3CC  arm  ov009
 *   func_0217F264  0x0217F264  arm  ov009
 *   strstr                   0x02094b20  arm
 *   SBServerParseKeyVals     0x0219e33c  arm
 *   current_time             0x0217f264  arm
 *   FIFORemove               0x0219d544  arm
 *   g_021A8110               0x021a8110  data
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

typedef unsigned int   u32;

typedef unsigned char  u8;

extern void func_0219D5B0(int *p);
extern int closesocket(int sock);
extern void FIFOClear(_SBServerFIFO *fifo);
extern void func_0219D5C4(_SBQueryEngine *engine, _SBServer *server);
extern void func_0219D4E8(int **p, int *q);
extern void func_0219D4B4(int *p, int *n);
extern int func_020964E0(u32 a0);
extern void func_0219D544(_SBServerFIFO *fifo, _SBServer *server);
extern int func_0219F978(char *buf, int len);
extern int func_0219D114(char *keyname);
extern void func_0219E01C(_SBServer *server, char *keyname, char *value);
extern int func_020949F4(const u8 *s1, const u8 *s2, u32 n);
extern void func_0219E5B8(_SBServer *server, char *data, int len);
extern void func_0219E3CC(_SBServer *server, char *data, int len);
extern unsigned int func_0217F264(void);
extern char *strstr(const char *haystack, const char *needle);
extern void SBServerParseKeyVals(_SBServer *server, char *keyvals);
extern unsigned int current_time(void);
extern int FIFORemove(_SBServerFIFO *fifo, _SBServer *server);
/* * Prepares the two blocks inside the argument. */ void func_0219D8E0(char *p);
void SBEngineCleanup(_SBQueryEngine *engine);
void func_0219D928(_SBQueryEngine *engine, _SBServer *server, int addfront, unsigned int querytype, int usequerychallenge);
void func_0219D9D8(_SBQueryEngine *engine, _SBServer *server, char *data, int len);
extern char *g_021A7C90[];
extern char g_021A8104[];
extern char g_021A8110[];




/*
 * Prepares the two blocks inside the argument.
 */
void func_0219D8E0(char *p)
{
    func_0219D5B0((int *)(p + 0x14));
    func_0219D5B0((int *)(p + 8));
}





void SBEngineCleanup(_SBQueryEngine *engine)
{
    closesocket(engine->querysock);
    engine->querysock = -1;
    FIFOClear(&engine->pendinglist);
    FIFOClear(&engine->querylist);
}




/*
 * sdk:      SBQueryEngineUpdateServer (libdwcgsserverbrowsing.TWL.HYB.a(sb_queryengine.o))
 */
void func_0219D928(_SBQueryEngine *engine, _SBServer *server, int addfront, unsigned int querytype, int usequerychallenge)
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
    if (engine->querylist.count < engine->maxupdates) {
        func_0219D5C4(engine, server);
        return;
    }
    if (addfront)
        func_0219D4E8((int **)(&engine->pendinglist), (int *)server);
    else
        func_0219D4B4((int *)(&engine->pendinglist), (int *)server);
}



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
        if (*data && func_020949F4((const u8 *)g_021A8104, (const u8 *)data, 8) == 0) {
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


static void ParseSingleGOAReply(_SBQueryEngine *engine,
                                _SBServer *server, char *data)
{
    int isfinal = strstr(data, g_021A8110) != 0;
    unsigned char flags;

    SBServerParseKeyVals(server, data);
    if (!isfinal)
        return;

    if (server->state & 4)
        flags = server->state | 0x41;
    else
        flags = server->state | 0x42;
    server->state = flags & 0xf3;

    server->updatetime = current_time() - server->updatetime;
    FIFORemove(&engine->querylist, server);
    engine->ListCallback(engine, 0, server, engine->instance);
}
