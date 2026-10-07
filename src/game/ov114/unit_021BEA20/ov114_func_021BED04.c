/*
 * function: func_021BED04
 * address:  0x021BED04
 * packet:   pkt_ov114_021BED04
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_BufferFullCallback (libnhttp.TWL.HYB.a(d_nhttp_common.o))
 *
 * symbols:
 *   func_021BEC00 0x021BEC00 arm ov114
 *   func_021BEBC8 0x021BEBC8 arm ov114
 *   func_021BEE74 0x021BEE74 arm ov114
 */

typedef struct {
    void *buf;
    unsigned long length;
    unsigned long offset;
} BodyBufArg;

typedef struct {
    int f0;
    unsigned long offset;
    char pad[0x14];
    unsigned long length;
    char pad2[8];
    void *buf;
} Res;

typedef struct Conn {
    char pad[0x1c];
    int (*callback)(struct Conn *, int, BodyBufArg *);
} Conn;

extern struct Conn *func_021BEC00(int a, int b);
extern int func_021BEBC8(int a, int b);
extern int func_021BEE74(void *mutexInfo_p, void *handle, void *buf_p, unsigned long length, unsigned long offset);

void func_021BED04(void *mutexInfo_p, Conn *connection_p)
{
    BodyBufArg arg;
    Res *res_p;

    if (func_021BEC00((int)mutexInfo_p, (int)connection_p) != 0) {
        res_p = (Res *)func_021BEBC8((int)mutexInfo_p, (int)connection_p);
        if (res_p != 0 && connection_p->callback != 0) {
            arg.buf = res_p->buf;
            arg.length = res_p->length;
            arg.offset = res_p->offset;
            connection_p->callback(connection_p, 2, &arg);
            func_021BEE74(mutexInfo_p, connection_p, arg.buf, arg.length, arg.offset);
        }
    }
}
