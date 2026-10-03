/*
 * function: func_021D7EB4
 * address:  0x021D7EB4
 * packet:   pkt_ov093_021D7EB4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5444  0x021D5444  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_02019C90  0x02019C90  thumb
 *   _u32_div_f     0x0209C2B0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

struct QF;
u16 func_021D5444(struct QF *p);
extern int func_021D59B4(u8 *p, int k);
u32 func_02019C90(u16 a, u16 b, u32 k);

u32 func_021D7EB4(void *a)
{
    int s = func_021D5444(a);
    u16 x = func_021D59B4(a, 0x13);
    u16 y = func_021D59B4(a, 0xf);
    u32 v = func_02019C90(s, x, 9);
    return (v * y) / 5;
}
