/*
 * file:     unit_0215FDA4_p01.c
 * unit:     yes
 * function: func_0215FDA4, func_0215FE3C
 * address:  0x0215FDA4
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02087988  0x02087988  arm
 *   func_020923F0  0x020923F0  arm
 *   func_02082D44  0x02082D44  arm
 *   func_0208799C  0x0208799C  arm
 *   g_021AA664  0x021AA664  data
 *   func_020870D0  0x020870D0  arm
 */
#include "../../matched/include/G_CPSSslSession.h"

typedef struct CPSSslSession CPSSslSession;

typedef struct CPSSslConnection {
    unsigned char master[0x30];
    unsigned char cache;                /* +0x30 */
    unsigned char pad31[0x74 - 0x31];
    unsigned char session_id[0x20];     /* +0x74 */
} CPSSslConnection;

typedef unsigned char  u8;

extern unsigned long func_02087988(void);
extern int func_020923F0(const u8 *a, const u8 *b, int n);
extern void func_02082D44(void *srcp, void *dstp, unsigned long size);
extern unsigned long func_0208799C(unsigned long state);
extern unsigned long long func_020870D0(void);
extern CPSSslSession g_021AA664[4];


/*
 * sdk:      find_session_from_id (libssl.TWL.HYB.a(ssl.o))
 */
static void func_0215FDA4(CPSSslConnection *con)
{
    int i;
    CPSSslSession *p;
    unsigned long enabled;

    enabled = func_02087988();
    con->cache = 0;
    for (i = 0; i < 4; i++) {
        p = &g_021AA664[i];
        if (p->valid != 0 && p->ip == 0 && p->port == 0 &&
            func_020923F0((const u8 *)p, con->session_id, 0x20) == 0) {
            func_02082D44(p->master, con, 0x30);
            con->cache = 1;
            break;
        }
    }
    func_0208799C(enabled);
}


/*
 * sdk:      find_session_from_IP (libssl.TWL.HYB.a(ssl.o))
 */
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
