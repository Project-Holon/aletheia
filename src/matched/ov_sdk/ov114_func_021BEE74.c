/*
 * function: func_021BEE74
 * address:  0x021BEE74
 * packet:   pkt_ov114_021BEE74
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_SetBodyBuffer (libnhttp.TWL.HYB.a(d_nhttp_common.o))
 *
 * symbols:
 *   func_021BEBC8 0x021BEBC8 arm ov114
 *   func_021BEC00 0x021BEC00 arm ov114
 */

typedef struct {
    int f0;
    int f4;
    char pad[0x14];
    int f1c;
    char pad2[8];
    void *f28;
} Res;

extern void *func_021BEC00(void *mutexInfo_p, void *handle);
extern Res *func_021BEBC8(void *mutexInfo_p, void *connection_p);

int func_021BEE74(void *mutexInfo_p, void *handle, void *buf_p, unsigned long length, unsigned long offset)
{
    void *connection_p = func_021BEC00(mutexInfo_p, handle);
    if (connection_p) {
        Res *res_p = func_021BEBC8(mutexInfo_p, connection_p);
        if (res_p == 0) {
            return -1;
        }
        res_p->f28 = buf_p;
        res_p->f1c = length;
        res_p->f4 = offset;
        return 0;
    }
    return -1;
}
