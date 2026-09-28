/*
 * function: func_021BC850
 * address:  0x021BC850
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BB954  0x021BB954  thumb  ov099
 *
 * Runs the setup for selector 0x54 with the true flag and stamps it 0x1CC bytes in.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern void func_021BB954(void *p, int b);

int func_021BC850(char *p, int v)
{
    func_021BB954(p, 1);
    *(u32 *)(p + 0x1CC) = 0x54;
    return v;
}
