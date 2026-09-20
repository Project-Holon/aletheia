/*
 * function: func_020729C0
 * address:  0x020729C0
 * packet:   pkt_020729C0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_0214DEC0  0x0214DEC0  data
 */

struct Global0214DEC0_2 {
    char pad[4];
    int flags4;
};

extern struct Global0214DEC0_2 g_0214DEC0;

int func_020729C0(void)
{
    int bit = 1;
    int flags = g_0214DEC0.flags4;
    int i;
    for (i = 0; i < 8; i++) {
        if ((flags & bit) == 0) {
            g_0214DEC0.flags4 |= bit;
            return i;
        }
        bit <<= 1;
    }
    return -1;
}
