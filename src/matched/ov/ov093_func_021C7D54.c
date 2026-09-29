/*
 * function: func_021C7D54
 * address:  0x021C7D54
 * packet:   pkt_ov093_021C7D54
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BD2B4  0x021BD2B4  thumb  ov093
 *   func_021BD34C  0x021BD34C  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void func_021BD2B4(u32 *it, u8 *p);
extern int func_021BD34C(u32 *it, u8 *p, u32 *x);
extern u8 func_021D5440(u32 x);
extern int func_021B9A24(u8 *k, int v);

u8 func_021C7D54(u8 *p, u8 *k, u8 *out)
{
    u32 it;
    u32 x;
    u8 n = 0;
    func_021BD2B4(&it, p);
    while (func_021BD34C(&it, p, &x)) {
        if (func_021B9A24(k, func_021D5440(x)) == 0) {
            out[n++] = func_021D5440(x);
        }
    }
    return n;
}
