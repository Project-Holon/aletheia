/*
 * function: NHTTPi_ReceivedCallback
 * address:  0x021BED90
 * packet:   pkt_ov114_021BED90
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_ReceivedCallback (libnhttp.TWL.HYB.a(d_nhttp_common.o))
 *
 * symbols:
 *   NHTTPi_GetConnection 0x021BEC00 arm ov114
 *   NHTTPi_Connection2Response 0x021BEBC8 arm ov114
 *   NHTTPi_SetBodyBuffer 0x021BEE74 arm ov114
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

extern struct Conn *NHTTPi_GetConnection(int a, int b);
extern int NHTTPi_Connection2Response(int a, int b);
extern int NHTTPi_SetBodyBuffer(void *mutexInfo_p, void *handle, void *buf_p, unsigned long length, unsigned long offset);

void NHTTPi_ReceivedCallback(void *mutexInfo_p, Conn *connection_p)
{
    BodyBufArg arg;
    Res *res_p;

    if (NHTTPi_GetConnection((int)mutexInfo_p, (int)connection_p) != 0) {
        res_p = (Res *)NHTTPi_Connection2Response((int)mutexInfo_p, (int)connection_p);
        if (res_p != 0 && connection_p->callback != 0) {
            arg.buf = res_p->buf;
            arg.length = res_p->length;
            arg.offset = res_p->offset;
            connection_p->callback(connection_p, 3, &arg);
            NHTTPi_SetBodyBuffer(mutexInfo_p, connection_p, arg.buf, arg.length, arg.offset);
        }
    }
}
