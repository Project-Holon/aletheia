/*
 * function: func_02169568
 * address:  0x02169568
 * packet:   pkt_ov009_02169568
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_EndUpdateServers (dwc_friend.o)
 *
 * symbols:
 *   g_021AA860  0x021AA860  data
 */

#include "../include/G_FriendGlobal.h"

extern struct FriendGlobal g_021AA860;

void func_02169568(void)
{
    (*(void (*)(int, unsigned char, int))(*(int *)(*(char **)(((char *)&g_021AA860) + 0xc) + 0x2c)))(
        0,
        *(unsigned char *)(*(char **)(((char *)&g_021AA860) + 0xc) + 0x1d),
        *(int *)(*(char **)(((char *)&g_021AA860) + 0xc) + 0x30));
    *(int *)(*(char **)(((char *)&g_021AA860) + 0xc)) = 2;
}
