/*
 * function: func_0215FE3C
 * address:  0x0215FE3C
 * packet:   pkt_ov009_0215FE3C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      find_session_from_IP (libssl.TWL.HYB.a(ssl.o))
 *
 * symbols:
 *   func_02087988  0x02087988  arm
 *   func_02082D44  0x02082D44  arm
 *   func_020870D0  0x020870D0  arm
 *   func_0208799C  0x0208799C  arm
 *   g_021AA664  0x021AA664  data
 */

#include "../include/G_CPSSslSession.h"

typedef struct CPSSslSession CPSSslSession;

typedef struct CPSSslConnection {
    unsigned char master[0x30];
    unsigned char cache;                /* +0x30 */
    unsigned char pad31[0x74 - 0x31];
    unsigned char session_id[0x20];     /* +0x74 */
} CPSSslConnection;

extern struct CPSSslSession g_021AA664[4];

extern unsigned long func_02087988(void);
extern void func_02082D44(void *srcp, void *dstp, unsigned long size);
extern unsigned long long func_020870D0(void);
extern unsigned long func_0208799C(unsigned long state);

static void func_0215FE3C(CPSSslConnection *con, unsigned long ip, unsigned short port)
{
    int i;
    CPSSslSession *p;
    unsigned long enabled;

    enabled = func_02087988();
    con->cache = 0;
    for (i = 0; i < 4; i++) {
        p = &g_021AA664[i];
        if (p->valid != 0 && p->ip == ip && p->port == port) {
            func_02082D44(p, con->session_id, 0x20);
            func_02082D44(p->master, con, 0x30);
            p->last_used = (unsigned long)(func_020870D0() >> 16);
            con->cache = 1;
            break;
        }
    }
    func_0208799C(enabled);
}
