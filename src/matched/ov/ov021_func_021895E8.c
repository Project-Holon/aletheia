/*
 * function: func_021895E8
 * address:  0x021895E8
 * packet:   pkt_ov021_021895E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02013BD0  0x02013BD0  thumb
 *   func_0218F14C  0x0218F14C  thumb  ov021
 *   func_0218F134  0x0218F134  thumb  ov021
 */

unsigned short func_02013BD0(unsigned short id);
void func_0218F14C(int h, int r, int c);
void func_0218F134(int h);

void func_021895E8(unsigned char *p, int id, int c)
{
    int r = func_02013BD0(id);
    if (r != 0xFFFF)
        func_0218F14C(*(int *)(p + 0x10), r, c);
    else
        func_0218F134(*(int *)(p + 0x10));
}
