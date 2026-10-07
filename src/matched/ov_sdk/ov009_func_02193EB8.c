/*
 * function: func_02193EB8
 * address:  0x02193EB8
 * packet:   pkt_ov009_02193EB8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      xcode_buf (gstats.o)
 *
 * symbols:
 *   g_021A57C8   0x021A57C8  data
 */

#include "../include/G_StatsSocket.h"

extern struct StatsSocket g_021A57C8;

void func_02193EB8(char *buf, int len)
{
    int i;
    char *pos;

    pos = (*(char * *)&g_021A57C8);
    for (i = 0; i < len; i++) {
        buf[i] ^= *pos;
        pos++;
        if (*pos == 0)
            pos = (*(char * *)&g_021A57C8);
    }
}
