/*
 * function: func_021D1C24
 * address:  0x021D1C24
 * packet:   pkt_ov021_021D1C24
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_021D1C8C  0x021D1C8C  thumb  ov021
 *   func_020124E8  0x020124E8  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02007B44  0x02007B44  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02012934  0x02012934  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02188C54  0x02188C54  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern u32 func_020122C0(u32 a, u32 b, void *c, u32 d);
extern int func_021D1C8C(void *proc, int *seq, void *w);
extern u32 *func_020124E8(void);
extern void func_02082BCC(void *p, int v, int n);
extern u32 func_020120F4(u32 a);
extern void func_02012EBC(void);
extern u32 func_02007B44(void);
extern void *func_02188CB4(unsigned char *p);
extern void *func_02012934(void *p);
extern u32 func_0201AB28(u32 a, u32 b);
extern u32 func_02188C54(u32 a);

u32 func_021D1C24(u32 a, u32 b, u32 c)
{
    u32 r;
    u32 *p;

    r = func_020122C0(a, 0, func_021D1C8C, 0x58);
    p = func_020124E8();
    func_02082BCC(p, 0, 0x58);
    p[1] = a;
    p[2] = func_020120F4(a);
    func_02012EBC();
    p[0] = func_02007B44();
    p[3] = b;
    p[4] = func_02188CB4((void *)b);
    p[5] = func_0201AB28(func_02012934(p[2]), c);
    p[7] = func_02188C54(p[3]);
    *((u8 *)p + 0x4e) = c;
    p[0x15] = 0;
    return r;
}
