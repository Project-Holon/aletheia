/*
 * function: find_session_from_IP
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
 *   OS_DisableInterrupts  0x02087988  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   func_020870D0  0x020870D0  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   gCpsSslSessionCache  0x021AA664  data
 */

#include "../include/G_CPSSslSession.h"

typedef struct CPSSslSession CPSSslSession;

typedef struct CPSSslConnection {
    unsigned char master[0x30];
    unsigned char cache;                /* +0x30 */
    unsigned char pad31[0x74 - 0x31];
    unsigned char session_id[0x20];     /* +0x74 */
} CPSSslConnection;

extern struct CPSSslSession gCpsSslSessionCache[4];

extern unsigned long OS_DisableInterrupts(void);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern unsigned long long func_020870D0(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);

static void find_session_from_IP(CPSSslConnection *con, unsigned long ip, unsigned short port)
{
    int i;
    CPSSslSession *p;
    unsigned long enabled;

    enabled = OS_DisableInterrupts();
    con->cache = 0;
    for (i = 0; i < 4; i++) {
        p = &gCpsSslSessionCache[i];
        if (p->valid != 0 && p->ip == ip && p->port == port) {
            MI_CpuCopy8(p, con->session_id, 0x20);
            MI_CpuCopy8(p->master, con, 0x30);
            p->last_used = (unsigned long)(func_020870D0() >> 16);
            con->cache = 1;
            break;
        }
    }
    OS_RestoreInterrupts(enabled);
}
