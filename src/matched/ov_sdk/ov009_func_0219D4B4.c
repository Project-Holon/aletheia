/*
 * function: func_0219D4B4
 * address:  0x0219D4B4
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Pushes a node onto a three-word list head: the node's +0x24 link is
 * cleared, the old head is linked to it, the tail is filled in when the list
 * was empty, and the count at +8 is bumped.
 *
 * symbols:
 *

 */

void func_0219D4B4(int *p, int *n)
{
    if (p[1] != 0) ((int *)p[1])[9] = (int)n;
    p[1] = (int)n;
    n[9] = 0;
    if (p[0] == 0) p[0] = (int)n;
    p[2]++;
}


