/*
 * function: func_0217449C
 * address: 0x0217449C
 * packet: pkt_ov011_0217449C
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: existing follower ov011_func_021744D0.c stays separate.
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u8 low : 4; u8 flags : 2; u8 high : 2; } F93F;
u32 func_020399A8(void);
u32 func_0203D1A4(u32 p);
void func_0217449C(int a, int b, u8 *c, u8 *p)
{
    if (a != func_0203D1A4(func_020399A8())) {
        ((F93F *)(p + 0x93f))->flags |= *c;
    }
}
