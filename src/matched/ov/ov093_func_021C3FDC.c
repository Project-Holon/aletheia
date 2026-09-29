/*
 * function: func_021C3FDC
 * address:  0x021C3FDC
 * packet:   pkt_ov093_021C3FDC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021BD2B4  0x021BD2B4  thumb  ov093
 *   func_021BD34C  0x021BD34C  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   func_021C195C  0x021C195C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 func_021D5440(u8 *p);
extern void func_021BD2B4(u32 *it, u8 *p);
extern int func_021BD34C(u32 *it, u8 *p, u8 **x);
extern int func_021B9A24(int c, int k);
extern void func_021C195C(u8 *p, u8 *q, u32 n);

void func_021C3FDC(u8 *p, u8 *a)
{
    u32 it;
    u8 *cur;
    int k = func_021D5440(a);
    func_021BD2B4(&it, p);
    while (func_021BD34C(&it, p, &cur)) {
        if (func_021B9A24(k, func_021D5440(cur)) == 0)
            func_021C195C(p, cur, 0);
    }
}
