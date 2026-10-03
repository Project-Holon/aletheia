/*
 * function: func_0202800C
 * address:  0x0202800C
 * packet:   pkt_02027FEC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


extern u32 *func_02028084(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6,
                          u32 a7, u32 a8);
struct Cfg;
struct Descriptor;
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);

u32 *func_0202800C(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5, u32 a6, u32 a7,
                   u16 a8)
{
    u32 *p = func_02028084(a0, a1, a2, a3, a4, a5, a6, a7, a8);
    void *q = (void *)p[0];

    func_02045334(q);
    func_02045374(q);
    func_02041B6C(func_02045730(q));
    return p;
}
