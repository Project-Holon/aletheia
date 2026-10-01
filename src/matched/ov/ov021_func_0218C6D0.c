/*
 * function: func_0218C6D0
 * address:  0x0218C6D0
 * packet:   pkt_ov021_0218C6D0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02169510  0x02169510  thumb  ov010
 *   func_0207C9D0  0x0207C9D0  arm
 */

void func_02169510(int h, int *buf);
void func_0207C9D0(unsigned char *a, int *buf, int b);

void func_0218C6D0(int *p, int b)
{
    int buf[3];
    func_02169510(p[0], buf);
    func_0207C9D0((unsigned char *)p[3] + 4, buf, b);
}
