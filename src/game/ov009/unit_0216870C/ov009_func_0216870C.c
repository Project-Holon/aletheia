/*
 * function: func_0216870C
 * address:  0x0216870C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tail call with the last argument moved to the fourth slot.
 *
 * symbols:
 *   func_02168724  0x02168724  arm  ov009
 */

typedef unsigned char  u8;
extern u8 func_02168724(void *friendData, u8 *maxEntry, u8 *numEntry, char *statusString);

u8 func_0216870C(int a, int b)
{
    return func_02168724((void *)a, 0, 0, (char *)b);
}

