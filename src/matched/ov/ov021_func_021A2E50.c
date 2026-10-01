/*
 * function: func_021A2E50
 * address:  0x021A2E50
 * packet:   pkt_ov021_021A2E50
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_021A36E4  0x021A36E4  thumb  ov021
 *   d_021DDEA8     0x021DDEA8  data  a4
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern int d_021DDEA8;

void *func_02030734(int a, int b, int c, void *d, int e);
u32 func_021A36E4(int a, u32 b, int c, int d, u16 heap);

u32 *func_021A2E50(int a, u32 b, int c, int d, u16 heap)
{
    u32 *o = (u32 *)func_02030734(heap, 0x10, 1, &d_021DDEA8, 0x4C);

    o[0] = b;
    o[1] = func_021A36E4(a, b, c, d, heap);
    return o;
}
