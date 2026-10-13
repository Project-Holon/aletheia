/*
 * file:     sb_server_11.c
 * function: func_0219E900
 * address:  0x0219E900
 * packet:   pkt_ov009_0219E900
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SBAllocServer (libdwcgsserverbrowsing.TWL.HYB.a(sb_server.o))
 *
 * symbols:
 *   func_0217EAB0  0x0217EAB0  arm  ov009
 *   func_02184638  0x02184638  arm  ov009
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 *   func_0219E8D4  0x0219E8D4  arm  ov009
 *   func_0219E89C  0x0219E89C  arm  ov009
 *   func_0219E8C4  0x0219E8C4  arm  ov009
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

extern void *func_0217EAB0(unsigned long size);
extern void *func_02184638(int elemSize, int nBuckets, int nChains, int (*hashFn)(void *, int),
                           int (*compFn)(void *, void *), void (*freeFn)(void *));
extern void func_0217EAE0(void *ptr);
extern int func_0219E8D4(void *a, void *b);
extern void func_0219E89C(void *elem);
extern int func_0219E8C4(void *elem, int numbuckets);

struct SBServer *func_0219E900(int unused, unsigned int publicip, unsigned short publicport)
{
    struct SBServer *server;

    server = func_0217EAB0(sizeof(struct SBServer));
    if (server == 0)
        return 0;
    server->keyvals = func_02184638(8, 8, 4, func_0219E8C4, func_0219E8D4, func_0219E89C);
    if (server->keyvals == 0) {
        func_0217EAE0(server);
        return 0;
    }
    server->state = 0;
    server->flags = 0;
    server->next = 0;
    server->updatetime = 0;
    server->icmpip = 0;
    server->publicip = publicip;
    server->publicport = publicport;
    server->privateip = 0;
    server->privateport = 0;
    return server;
}
