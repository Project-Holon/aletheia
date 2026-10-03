/*
 * function: func_021C81D0
 * address:  0x021C81D0
 * packet:   pkt_ov093_021C81D0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BD2B4  0x021BD2B4  thumb  ov093
 *   func_021BD34C  0x021BD34C  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021C81C8  0x021C81C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void func_021BD2B4(u8 *it, u8 **q);
extern int func_021BD34C(u8 *it, u8 **q, u8 **x);
extern u8 func_021D5440(u8 *p);
extern u16 func_021C81C8(u8 *p, u8 *x, int flag);

u16 func_021C81D0(u8 *p, u8 *a, u32 y)
{
    u32 it;
    u8 *x;
    u16 n;
    u32 base = func_021C81C8(p, a, y);
    int k = func_021D5440(a);
    n = 0;
    func_021BD2B4((u8 *)&it, (u8 **)p);
    while (func_021BD34C((u8 *)&it, (u8 **)p, &x)) {
        if (k != func_021D5440(x)) {
            if (func_021C81C8(p, x, y) > base) {
                n++;
            }
        }
    }
    return n;
}
