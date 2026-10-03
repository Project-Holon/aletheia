/*
 * function: func_021D7FF8
 * address:  0x021D7FF8
 * packet:   pkt_ov093_021D7FF8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9B94  0x021B9B94  thumb  ov093
 *   func_021B9C00  0x021B9C00  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   d_021F042D     0x021F042D  data  ov093  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

struct Q1;
struct S2;
u8 func_021B9B94(struct Q1 *p);
extern u8 *func_021B9C00(struct S2 *p, u32 i);
extern int func_021D59B4(u8 *p, int k);
extern u8 d_021F042D[];

u32 func_021D7FF8(u32 a, void *b)
{
    u32 n = func_021B9B94(b);
    u32 m = 1;
    u32 i;
    u32 v;

    for (i = 0; i < n; i++) {
        v = func_021D59B4(func_021B9C00(b, (u8)i), 0xf);
        if (v > m)
            m = v;
    }
    if (a >= 9)
        a = 8;
    return d_021F042D[a] * (m << 2);
}
