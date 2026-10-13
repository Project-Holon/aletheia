/*
 * function: GFL_NET_RING_BUFF_Read
 * address:  0x020364D4
 * packet:   pkt_02036428
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Blocked: the PC24 at +0008 to 0x02036568 has no witness of any class and no
 * manifest entry is possible this pass: 0x02036568 is a 128-byte ARM function
 * whose C is byte-correct except an eight-instruction schedule permutation of
 * its loop tail (seven spellings measured, all identical) - a DIFF, see
 * docs/notes/pkt_02036568.c.txt.  The second site (GFL_NET_RING_BUFF_WrapPos) resolves as
 * `matched`.  Every concrete byte here reproduces.
 *
 * symbols:
 *   GFL_NET_RING_BUFF_Peek  0x02036568  arm
 *   GFL_NET_RING_BUFF_WrapPos  0x02036624  arm
 */
#include "../include/Obj01465.h"

extern int GFL_NET_RING_BUFF_Peek(void *p, unsigned char *dst, int len, int max);
extern int GFL_NET_RING_BUFF_WrapPos(void *p, int v);
int GFL_NET_RING_BUFF_Read(char *p, unsigned char *dst, int len, int max)
{
    int d = GFL_NET_RING_BUFF_Peek(p, dst, len, max);
    ((struct Obj01465 *)p)->fC = (short)GFL_NET_RING_BUFF_WrapPos(p, ((struct Obj01465 *)p)->fC + d);
    return d;
}
