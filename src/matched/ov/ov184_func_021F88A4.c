/*
 * function: func_021F88A4
 * address:  0x021F88A4
 * packet:   pkt_021F88A4
 * region:   ov184
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021FEEC0  0x021FEEC0  thumb  ov186
 *   func_021FBDA4  0x021FBDA4  thumb  ov186
 *   func_021FC1F8  0x021FC1F8  thumb  ov186
 *   func_021FC610  0x021FC610  thumb  ov186
 *   func_021F3AF0  0x021F3AF0  thumb  ov112
 */
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_021FEEC0(u32 a, u32 b, u32 c);
extern void func_021FBDA4(u32 a, u32 b);
extern void func_021FC1F8(u32 a, u32 b);
extern void func_021FC610(u32 a, u16 b);
extern u32 func_021F3AF0(u32 a, u16 b);

void func_021F88A4(char *p, char *q)
{
    if (*(u32 *)p != 0)
        return;
    func_021FEEC0(*(u32 *)(q + 4), 0, 0);
    func_021FBDA4(*(u32 *)(q + 0xc), 0);
    func_021FC1F8(*(u32 *)(q + 0xc), 0);
    func_021FC610(*(u32 *)(q + 8), *(u16 *)(p + 0x24));
    *(u32 *)p = func_021F3AF0(*(u32 *)(p + 0x28), *(u16 *)(p + 0x24));
}
