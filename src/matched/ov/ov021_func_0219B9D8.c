/*
 * function: func_0219B9D8
 * address:  0x0219B9D8
 * packet:   pkt_ov021_0219B9D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216DEE0  0x0216DEE0  thumb  ov010
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0216D67C(u32);
extern u32 func_0216DEE0(u32);
extern int func_0216D83C(u32);
extern int func_0216D86C(u32);

int func_0219B9D8(u32 a, u8 *s)
{
    u32 o = func_0216DEE0(func_0216D67C(a));
    int x;
    int y;
    if (o != 0) {
        x = func_0216D83C(o);
        y = func_0216D86C(o);
        if (x != *(s16 *)(s + 2) || y != *(s16 *)(s + 4)) {
            return 1;
        }
    }
    return 0;
}
