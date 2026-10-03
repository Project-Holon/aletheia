/*
 * function: func_021E8A3C
 * address:  0x021E8A3C
 * packet:   pkt_021E8A3C
 * region:   ov177
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021E8DD4      0x021E8DD4  data
 *   func_02030734   0x02030734  arm
 *   func_02082BCC   0x02082BCC  arm
 *   func_021E8AA0   0x021E8AA0  thumb
 *
 * Allocate and clear a 0x10-byte record, attach a and b, and return it.
 */


extern unsigned char d_021E8DD4[];
extern void *func_02030734(unsigned int, unsigned int, int, const char *, unsigned short);
extern void func_02082BCC(int *, int, int);
extern void func_021E8AA0(int *, int);

int *func_021E8A3C(int a, int b, int c)
{
    int *p;
    p = func_02030734(c, 0x10, 0, (const char *)d_021E8DD4, 0x246);
    func_02082BCC(p, 0, 0x10);
    *(int *)((char *)p + 8) = a;
    func_021E8AA0(p, b);
    return p;
}
