/*
 * function: func_021C017C
 * address:  0x021C017C
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9B64  0x021B9B64  thumb  ov099
 *   func_021BAAB8  0x021BAAB8  thumb  ov099
 *
 * Re-arms, runs the seven/zero setup and stamps selector 0x20.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern void func_021B9B64(char *p);
extern void func_021BAAB8(char *p, int a, int b);

int func_021C017C(char *p, int v)
{
    func_021B9B64(p + 0x274);
    func_021BAAB8(p, 7, 0);
    *(u32 *)(p + 0x1CC) = 0x20;
    return v;
}
