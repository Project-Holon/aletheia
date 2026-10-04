/*
 * function: func_0219EA24
 * address:  0x0219EA24
 * packet:   pkt_ov021_0219EA24
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0219EA40  0x0219EA40  thumb  ov021
 *   func_0219E9F8  0x0219E9F8  thumb  ov021
 *   func_020056EC  0x020056EC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern int func_0219EA40(int key);
extern int func_0219E9F8(u32 *arr, u32 v);
extern u32 func_020056EC(u32 v);

u32 func_0219EA24(u32 a, u32 b)
{
    u32 *t = (u32 *)func_0219EA40(a);
    return t[func_020056EC(func_0219E9F8(t, b))];
}
