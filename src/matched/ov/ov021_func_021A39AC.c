/*
 * function: func_021A39AC
 * address:  0x021A39AC
 * packet:   pkt_ov021_021A39AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A398C  0x021A398C  thumb  ov021
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_021A3190  0x021A3190  thumb  ov021
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_021A3AD8  0x021A3AD8  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 func_021A398C(u8 *p);
void *func_021A3960(u8 *p);
u16 func_021A3190(int i, int j);
u16 func_0216D598(void *p);
void func_021A3AD8(u8 *p, int v);

void func_021A39AC(u8 *p, int a)
{
    u32 x = func_021A398C(p);
    void *h = func_021A3960(p);
    int v = func_021A3190(x, a);

    if (v != func_0216D598(h))
        func_021A3AD8(p, v);
    *(u16 *)(p + 0x2C) = 0;
}
