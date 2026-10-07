/*
 * function: func_0216909C
 * address:  0x0216909C
 * packet:   pkt_ov009_0216909C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_InitGPProcessCount (dwc_friend.o)
 *
 * symbols:
 *   g_021AA860   0x021AA860  data
 *   func_020870D0  0x020870D0  arm
 */

#include "../include/G_FriendGlobal.h"

extern struct FriendGlobal g_021AA860;
extern unsigned long long func_020870D0(void);

void func_0216909C(void)
{
    char *p = *(char **)(((char *)&g_021AA860) + 0xc);

    if (p == 0) return;
    *(int *)(p + 8) = 0;
    *(unsigned long long *)(*(char **)(((char *)&g_021AA860) + 0xc) + 0xc) = func_020870D0();
}
