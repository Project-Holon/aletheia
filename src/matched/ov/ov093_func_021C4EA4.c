/*
 * function: func_021C4EA4
 * address:  0x021C4EA4
 * packet:   pkt_ov093_021C4EA4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C8810  0x021C8810  thumb  ov093
 *   func_021C20BC  0x021C20BC  thumb  ov093
 *   func_021C99A0  0x021C99A0  thumb  ov093
 *   func_021C8010  0x021C8010  thumb  ov093
 *   func_021C70E4  0x021C70E4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021C20D0  0x021C20D0  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 func_021D5440(u8 *p);
extern void func_021C8838(u8 *p, int a, int b);
extern void func_021C8860(u8 *p, u32 val);
extern void func_021C8810(u8 *p);
extern int func_021C20BC(u8 *p, u8 *a, int r);
extern void func_021C99A0(u8 *p, u8 *l);
extern int func_021C8010(u8 *p, u32 x);
extern void func_021C70E4(u8 *p, int a, int b, int c, int d, int e);
extern int func_021D59B4(u8 *p, int k);
extern int func_021C20D0(u8 *p, u8 *a, int c, u8 *l);

void func_021C4EA4(u8 *p, u8 *a, int k, int n)
{
    u8 x = func_021D5440(a);
    switch (k) {
    case 4:
        func_021C8838(p + 0x1AE4, 2, 396);
        func_021C8860(p + 0x1AE4, x);
        break;
    case 3:
        func_021C8838(p + 0x1AE4, 2, 399);
        func_021C8860(p + 0x1AE4, x);
        break;
    default:
        func_021C8810(p + 0x1AE4);
        break;
    }
    if (n > 0 && func_021C20BC(p, a, n) != 0) {
        func_021C99A0(p, p + 0x1AE4);
        func_021C8810(p + 0x1AE4);
        func_021C70E4(p, 0x290, func_021C8010(p, x), 6, 0, 0);
        if ((int)func_021D59B4(a, 0xd) <= n) {
            func_021C70E4(p, 0x255, 6, 6, 0, 0);
        }
        func_021C20D0(p, a, n, 0);
    }
}
