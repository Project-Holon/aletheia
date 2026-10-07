/*
 * function: func_02168DA4
 * address:  0x02168DA4
 * packet:   pkt_02156B70
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021AA860  0x021AA860  data
 *
 * Fill the descriptor hanging off the global at 0x021AA860 (+0x0c): six
 * arguments land at +0x2c..+0x40, four status bytes are cleared, the state
 * word is set to 1, and the +0x1f counter is bumped twice -- once only when
 * the +0x18 word is zero.
 */

#include "../include/G_FriendGlobal.h"

extern struct FriendGlobal g_021AA860;

void func_02168DA4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    *(int *)(*(char **)(((char *)&g_021AA860) + 0x0c) + 0x2c) = a2;
    *(int *)(*(char **)(((char *)&g_021AA860) + 0x0c) + 0x30) = a3;
    *(int *)(*(char **)(((char *)&g_021AA860) + 0x0c) + 0x34) = a4;
    *(int *)(*(char **)(((char *)&g_021AA860) + 0x0c) + 0x38) = a5;
    *(int *)(*(char **)(((char *)&g_021AA860) + 0x0c) + 0x3c) = a6;
    *(int *)(*(char **)(((char *)&g_021AA860) + 0x0c) + 0x40) = a7;
    *(char *)(*(char **)(((char *)&g_021AA860) + 0x0c) + 0x1d) = 0;
    *(char *)(*(char **)(((char *)&g_021AA860) + 0x0c) + 0x1e) = 0;
    *(char *)(*(char **)(((char *)&g_021AA860) + 0x0c) + 0x1f) = 0;
    *(char *)(*(char **)(((char *)&g_021AA860) + 0x0c) + 0x1c) = 0;
    *(int *)(*(char **)(((char *)&g_021AA860) + 0x0c) + 0x00) = 1;

    if (*(int *)(*(char **)(((char *)&g_021AA860) + 0x0c) + 0x18) == 0)
        *(unsigned char *)(*(char **)(((char *)&g_021AA860) + 0x0c) + 0x1f) += 1;

    *(unsigned char *)(*(char **)(((char *)&g_021AA860) + 0x0c) + 0x1f) += 1;
}
