/*
 * function: func_021F7F1C
 * address:  0x021F7F1C
 * packet:   pkt_021FD1CC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_0220AF20     0x0220AF20  data
 *   func_021FFD9C  0x021FFD9C  thumb  ov094
 */

#include "../include/G_0220AF20.h"

extern struct G_0220AF20 *d_0220AF20;
extern int func_021FFD9C(char *p, int key);

int func_021F7F1C(int i)
{
    if (i < 8)
        return func_021FFD9C(*(char **)(((char *)d_0220AF20) + 0x190), i);
    if (*(int *)(((char *)d_0220AF20) + (i - 8) * 4 + 0x1f8) != -1)
        return 1;
    return 0;
}
