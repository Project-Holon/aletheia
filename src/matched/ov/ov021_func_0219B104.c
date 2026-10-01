/*
 * function: func_0219B104
 * address:  0x0219B104
 * packet:   pkt_ov021_0219B104
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0219B120  0x0219B120  thumb  ov021
 *   func_0219B0D8  0x0219B0D8  thumb  ov021
 *   func_020056EC  0x020056EC  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 *func_0219B120(u32);
extern int func_0219B0D8(u32 *, u32);
extern u32 func_020056EC(u32 v);

u32 func_0219B104(u32 a, u32 b)
{
    u32 *t = func_0219B120(a);
    return t[func_020056EC(func_0219B0D8(t, b))];
}
