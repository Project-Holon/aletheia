/*
 * function: func_021575DC
 * address:  0x021575DC
 * packet:   pkt_ov009_021575DC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPS_CalmDown (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   func_02087988  0x02087988  arm
 *   func_0208574C  0x0208574C  arm
 *   func_02085868  0x02085868  arm
 *   func_0208799C  0x0208799C  arm
 *   g_021A85E4  0x021A85E4  data
 *   g_021A826C  0x021A826C  data
 */

#include "../include/G_021A85E4.h"

struct net_vars {
    char pad0[0x58];
    unsigned long calm;
};

extern struct G_021A85E4 g_021A85E4;
extern struct net_vars g_021A826C;
extern unsigned long func_02087988(void);
extern int func_0208574C(void *thread);
extern void func_02085868(void *thread);
extern unsigned long func_0208799C(unsigned long state);

int func_021575DC(void)
{
    unsigned long enable = func_02087988();
    int result = func_0208574C(((char *)&g_021A85E4));

    if (result == 0 && g_021A826C.calm == 0) {
        g_021A826C.calm = 1;
        func_02085868(((char *)&g_021A85E4));
    }
    func_0208799C(enable);
    return result;
}
