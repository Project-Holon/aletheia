/*
 * function: func_02199F30
 * address:  0x02199F30
 * packet:   pkt_ov021_02199F30
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct { int x, y, z; } Vec;
extern void func_0216D8C0(u32, const Vec *);
extern void func_0216D7CC(u32);

int func_02199F30(u32 a)
{
    Vec t = {0, 0, 0};
    func_0216D8C0(a, &t);
    func_0216D7CC(a);
    return 1;
}
