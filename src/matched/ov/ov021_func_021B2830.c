/*
 * function: func_021B2830
 * address:  0x021B2830
 * packet:   pkt_ov021_021B2830
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02011330  0x02011330  thumb
 *   func_0204E720  0x0204E720  arm
 */

typedef unsigned int u32;

extern u32 func_02011330(u32);
typedef signed int     s32;
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);

int func_021B2830(u32 a)
{
    u32 w = func_02011330(a);
    u32 x = func_02011330(a);
    u32 y = func_02011330(a);
    u32 z = func_02011330(a);

    func_0204E720(w, x, y, z);
    return 0;
}
