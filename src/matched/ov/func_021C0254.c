/*
 * function: func_021C0254
 * address:  0x021C0254
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BAD50  0x021BAD50  thumb  ov099
 *   func_021B9B64  0x021B9B64  thumb  ov099
 *
 * Runs the setup, stamps selector 0x83 and re-arms the block 0x274 bytes in.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern void func_021BAD50(int a);
extern void func_021B9B64(char *p);

int func_021C0254(char *p, int v)
{
    func_021BAD50((int)p);
    *(u32 *)(p + 0x1CC) = 0x83;
    func_021B9B64(p + 0x274);
    return v;
}
