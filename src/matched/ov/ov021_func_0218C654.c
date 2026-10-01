/*
 * function: func_0218C654
 * address:  0x0218C654
 * packet:   pkt_ov021_0218C654
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0218C9C4  0x0218C9C4  thumb  ov021
 *   func_0218C638  0x0218C638  thumb  ov021
 */

void func_0218C9C4(unsigned char *buf, int c);
int func_0218C638(int a, int b, unsigned char *buf);

int func_0218C654(int a, int b, int c)
{
    unsigned char buf[16];
    func_0218C9C4(buf, c);
    return func_0218C638(a, b, buf);
}
