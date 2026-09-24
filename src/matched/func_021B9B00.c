/*
 * function: func_021B9B00
 * address:  0x021B9B00
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * Fills the 0x64-byte header: type 0x15, sub-type 2, the four date fields from `a`, an 8-byte owner string and the three zero slots.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
extern void func_02082BCC(int, int, int);
extern u8 func_0200856C(int);
extern u8 func_02008570(int);
extern u32 func_02008530(int);
extern int func_020084F4(int);
extern void func_0201F41C(int, u8 *, int);

void func_021B9B00(u8 *p, int a)
{
    func_02082BCC((int)p, 0, 0x64);
    p[0] = 0x15;
    p[1] = 2;
    p[2] = func_0200856C(a);
    p[3] = func_02008570(a);
    *(u32 *)(p + 4) = func_02008530(a);
    func_0201F41C(func_020084F4(a), p + 8, 8);
    *(u32 *)(p + 0x18) = 0;
    *(u8 *)(p + 0x24) = 0;
    *(u32 *)(p + 0x5c) = 0;
}
