/*
 * function: bfloat
 * address:  0x02193BF0
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Stores two words at +8 and +0xc of the state object and returns +8 of it.
 *
 * symbols:
 *   g_021ADFD0  0x021ADFD0  data
 *   g_021ADFD8  0x021ADFD8  data
 */

extern char g_021ADFD0[];
extern char g_021ADFD8[];

char *bfloat(int a, int b)
{
    *(int *)(g_021ADFD0 + 8) = a;
    *(int *)(g_021ADFD0 + 0xc) = b;

    return g_021ADFD8;
}

