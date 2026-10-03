/*
 * function: func_021B98A0
 * address:  0x021B98A0
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B984C  0x021B984C  thumb  ov114
 *
 *
 * Binds a 0x130-stride sub-table to the record and zeroes its first 0x130 bytes.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
extern void *func_0203D7C8(u32 a, u32 size, u32 c, u32 d);
extern void func_02082BCC(int, int, int);
extern void func_021B984C(u8 *, int);

void func_021B98A0(u8 *p, int a, int b, int c)
{
    void *q;

    if (p == 0)
        return;
    q = func_0203D7C8(a, b + 0x130, 0x021CE310, 0x1f5);
    *(u32 *)p = (u32)q;
    func_02082BCC((int)q, 0, b + 0x130);
    func_021B984C(p, c);
}
