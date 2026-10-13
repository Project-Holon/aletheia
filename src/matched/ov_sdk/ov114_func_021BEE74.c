/*
 * function: NHTTPi_SetBodyBuffer
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
 *   NHTTPi_Connection2Response 0x021BEBC8 arm ov114
 *   NHTTPi_GetConnection 0x021BEC00 arm ov114
 */

typedef struct {
    int f0;
    int f4;
    char pad[0x14];
    int f1c;
    char pad2[8];
    void *f28;
} Res;

struct Conn;
extern struct Conn *NHTTPi_GetConnection(int a, int b);
extern int NHTTPi_Connection2Response(int a, int b);

int NHTTPi_SetBodyBuffer(void *mutexInfo_p, void *handle, void *buf_p, unsigned long length, unsigned long offset)
{
    void *connection_p = NHTTPi_GetConnection((int)mutexInfo_p, (int)handle);
    if (connection_p) {
        Res *res_p = (Res *)NHTTPi_Connection2Response((int)mutexInfo_p, (int)connection_p);
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
