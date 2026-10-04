/*
 * function: func_021BEC74
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
 *   func_021BEC00 0x021BEC00 arm ov114
 *   func_021BEBC8 0x021BEBC8 arm ov114
 *   func_021BEE4C 0x021BEE4C arm ov114
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

extern Conn *func_021BEC00(void *mutexInfo_p, Conn *connection_p);
extern int func_021BEBC8(int a, int b);
extern int func_021BEE4C(int a, int b, int c, int d);

int func_021BEC74(void *mutexInfo_p, Conn *connection_p, char *label_p, int offset)
{
    PostSendArg arg;
    void *res_p;
    int ret = -1;

    if (func_021BEC00(mutexInfo_p, connection_p) != 0) {
        res_p = (void *)func_021BEBC8((int)mutexInfo_p, (int)connection_p);
        if (res_p != 0 && connection_p->callback != 0) {
            arg.label = label_p;
            arg.value = connection_p->f24;
            arg.length = connection_p->f28;
            arg.offset = offset;
            ret = connection_p->callback(connection_p, 1, &arg);
            func_021BEE4C((int)mutexInfo_p, (int)connection_p, (int)arg.value, arg.length);
        }
    }
    return ret;
}
