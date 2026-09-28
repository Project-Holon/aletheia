/*
 * function: func_021FD070
 * address:  0x021FD070
 * packet:   pkt_021FD1CC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
struct OneBit {
    unsigned int v : 1;
};

extern struct OneBit *func_02011324(int a);

int func_021FD070(int a, int b)
{
    int r = b;

    if (func_02011324(a)->v)
        r ^= 1;
    return r;
}
