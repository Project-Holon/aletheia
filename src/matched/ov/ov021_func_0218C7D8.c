/*
 * function: func_0218C7D8
 * address:  0x0218C7D8
 * packet:   pkt_ov021_0218C7D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0218C654  0x0218C654  thumb  ov021
 *   func_0218C724  0x0218C724  thumb  ov021
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
int func_0218C654(int a, int b, int c);
u8 *func_0218C724(u8 *owner, u32 *obj);

int func_0218C7D8(void *p, int b, int c)
{
    int r = func_0218C654((int)p, b, c);
    if (r == 0)
        return 0;
    return (int)func_0218C724(p, (u32 *)r);
}
