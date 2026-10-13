/*
 * function: NHTTPi_PostSendCallback
 * address:  0x021BEC74
 * packet:   pkt_ov114_021BEC74
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_PostSendCallback (libnhttp.TWL.HYB.a(d_nhttp_common.o))
 *
 * symbols:
 *   NHTTPi_GetConnection 0x021BEC00 arm ov114
 *   NHTTPi_Connection2Response 0x021BEBC8 arm ov114
 *   NHTTPi_SetPostDataBuffer 0x021BEE4C arm ov114
 */

typedef struct {
    char *label;
    void *value;
    unsigned long length;
    int offset;
} PostSendArg;

typedef struct Conn {
    char pad[0x1c];
    int (*callback)(struct Conn *, int, PostSendArg *);
    char pad2[4];
    void *f24;
    unsigned long f28;
} Conn;

extern struct Conn *NHTTPi_GetConnection(int a, int b);
extern int NHTTPi_Connection2Response(int a, int b);
extern int NHTTPi_SetPostDataBuffer(int a, int b, int c, int d);

int NHTTPi_PostSendCallback(void *mutexInfo_p, Conn *connection_p, char *label_p, int offset)
{
    PostSendArg arg;
    void *res_p;
    int ret = -1;

    if (NHTTPi_GetConnection((int)mutexInfo_p, (int)connection_p) != 0) {
        res_p = (void *)NHTTPi_Connection2Response((int)mutexInfo_p, (int)connection_p);
        if (res_p != 0 && connection_p->callback != 0) {
            arg.label = label_p;
            arg.value = connection_p->f24;
            arg.length = connection_p->f28;
            arg.offset = offset;
            ret = connection_p->callback(connection_p, 1, &arg);
            NHTTPi_SetPostDataBuffer((int)mutexInfo_p, (int)connection_p, (int)arg.value, arg.length);
        }
    }
    return ret;
}
