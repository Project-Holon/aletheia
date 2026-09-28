/*
 * function: func_021C03D8
 * address:  0x021C03D8
 * packet:   pkt_ov093_021C03D8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D62A8  0x021D62A8  thumb  ov093
 *   func_021D6130  0x021D6130  thumb  ov093
 *   func_021C557C  0x021C557C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D62A8(u8 *p);
extern int func_021D6130(u8 *p);
extern void func_021C557C(u8 *p, u8 *a, int k, int flag);

void func_021C03D8(u8 *p, u8 *a)
{
    int k = func_021D62A8(a);
    if (k == 2 && func_021D6130(a) != 0) {
        func_021C557C(p, a, k, 1);
    }
}
