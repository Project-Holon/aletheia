/*
 * function: CallReqCallback
 * address:  0x0219451C
 * packet:   pkt_ov009_0219451C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CallReqCallback (gstats.o)
 *
 * symbols:
 *   ArrayLength 0x02184200  arm
 *   func_02184208 0x02184208  arm
 *   ArrayDeleteAt 0x0218437C  arm
 *   gGstatsConn   0x021ADFE0  data
 */

#include "../include/G_StatsConn.h"

typedef struct {
    int type;
    int localid;
    int profileid;
    int extra0;
    int extra1;
    void *userdata;
    void *callback;
} serverreq_t;

extern int ArrayLength(const int *p);
extern serverreq_t *func_02184208(void *array, int n);
extern void ArrayDeleteAt(int a, int b);
extern struct StatsConn gGstatsConn;

void CallReqCallback(int reqindex, int success, long modified, char *data, int length)
{
    serverreq_t *req;

    if (reqindex < 0 || reqindex >= ArrayLength((void *)((int *)&gGstatsConn)[5]))
        return;
    req = func_02184208((void *)((int *)&gGstatsConn)[5], reqindex);
    if (req->callback != 0) {
        switch (req->type) {
        case 0:
            ((void (*)(int, int, int, char *, void *))req->callback)(req->localid, req->profileid, success, data, req->userdata);
            break;
        case 1:
            ((void (*)(int, int, int, int, int, long, char *, int, void *))req->callback)(req->localid, req->profileid, req->extra0, req->extra1, success, modified, data, length, req->userdata);
            break;
        case 2:
            ((void (*)(int, int, int, int, int, long, void *))req->callback)(req->localid, req->profileid, req->extra0, req->extra1, success, modified, req->userdata);
            break;
        case 3:
            ((void (*)(int, int, int, void *))req->callback)(req->localid, req->profileid, success, req->userdata);
            break;
        }
    }
    ArrayDeleteAt((int)((void *)((int *)&gGstatsConn)[5]), reqindex);
}
