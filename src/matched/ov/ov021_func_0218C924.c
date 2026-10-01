/*
 * function: func_0218C924
 * address:  0x0218C924
 * packet:   pkt_ov021_0218C924
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef struct { unsigned short a, b; } E;

unsigned short func_0218C924(unsigned char *p)
{
    if (p == 0)
        return 0;
    return (**(E ***)(p + 0x10))->b;
}
