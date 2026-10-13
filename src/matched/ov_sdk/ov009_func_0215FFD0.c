/*
 * function: func_0215FFD0
 * address:  0x0215FFD0
 * packet:   pkt_ov009_0215FFD0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      purge_session (libssl.TWL.HYB.a(ssl.o))
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   func_020923F0  0x020923F0  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   g_021AA664  0x021AA664  data
 */

#include "../include/G_CPSSslSession.h"



typedef struct CPSSslSession CPSSslSession;

typedef struct CPSSslConnection {
    unsigned char pad0[0x74];
    unsigned char session_id[0x20];     /* +0x74 */
} CPSSslConnection;

extern struct CPSSslSession g_021AA664[4];

extern unsigned long OS_DisableInterrupts(void);
typedef unsigned char  u8;
extern int func_020923F0(const u8 *a, const u8 *b, int n);
extern unsigned long OS_RestoreInterrupts(unsigned long state);

static void func_0215FFD0(CPSSslConnection *con)
{
    int i;
    CPSSslSession *p;
    unsigned long enabled;

    enabled = OS_DisableInterrupts();
    for (i = 0; i < 4; i++) {
        p = &g_021AA664[i];
        if (p->valid != 0) {
            if (func_020923F0((const u8 *)p, con->session_id, 0x20) == 0) {
                p->valid = 0;
                break;
            }
        }
    }
    OS_RestoreInterrupts(enabled);
}
