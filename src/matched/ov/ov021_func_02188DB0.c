/*
 * function: func_02188DB0
 * address:  0x02188DB0
 * packet:   pkt_ov021_02188DB0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02051E74  0x02051E74  arm
 *   func_0207D59C  0x0207D59C  arm
 *   func_0204044C  0x0204044C  arm
 *   func_02190270  0x02190270  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void func_02051E74(void *buf, u32 a, u32 b, u32 c, u32 d);
extern void func_0207D59C(u32 a, void *buf, u32 b, u32 c, u32 d, u32 e);
extern void func_0204044C(u32 a);
extern void func_02190270(u32 a);

void func_02188DB0(u8 *a)
{
    u32 buf[4];

    func_02051E74(buf, 0, 0x1000, 0x1000, 0);
    func_0207D59C(0x04000020, buf, 0, 0, 0, 0);
    func_0204044C(3);
    func_02190270(*(u32 *)(a + 0x28));
}
