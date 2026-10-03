/*
 * function: func_021EB584
 * address:  0x021EB584
 * packet:   pkt_ov093_021EB584
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207D55C  0x0207D55C  arm    arm9
 *   func_0204E720  0x0204E720  arm    arm9
 */
typedef unsigned short u16;
extern int func_0207D55C(volatile u16 *);
typedef signed int     s32;
typedef unsigned int   u32;
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
void func_021EB584(int a)
{
    if (func_0207D55C((volatile u16 *)0x0400006c) <= 0)
        func_0204E720(3, 0x10, 0, a);
    else
        func_0204E720(0xc, 0x10, 0, a);
}
