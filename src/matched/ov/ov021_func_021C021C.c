/*
 * function: func_021C021C
 * address:  0x021C021C
 * packet:   pkt_ov021_021C021C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188D38  0x02188D38  thumb  ov021
 *   func_021C029C  0x021C029C  thumb  ov021
 *   func_021C02F8  0x021C02F8  thumb  ov021
 *   func_021C0374  0x021C0374  thumb  ov021
 *   func_021C0360  0x021C0360  thumb  ov021
 *   func_021C6E48  0x021C6E48  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_02012374  0x02012374  thumb
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

extern u32 func_02188D38(u32 a);
extern void func_021C029C(u8 *p);
extern void func_021C02F8(u8 *p);
extern u32 func_021C0374(u8 *p);
extern void func_021C0360(u8 *p);
extern int func_021C6E48(u32 a);
extern void func_020061E4(u32 a);
extern void func_02012374(u32 a, u32 b);

int func_021C021C(u32 a, int *st, u8 *p)
{
    int n;

    u32 q;

    q = func_02188D38(*(u32 *)(p + 4));
    switch (*st) {
    case 0:
        func_021C029C(p);
        func_021C02F8(p);
        func_020061E4(0x6DF);
        *st = *st + 1;
        break;
    case 1:
        n = *(int *)(p + 0x74);
        *(int *)(p + 0x74) = n + 1;
        if (n > 0x23) {
            func_02012374(a, func_021C0374(p));
            *st = *st + 1;
            break;
        }
    case 2:
        if (func_021C6E48(q)) {
            func_020061E4(0x559);
            *st = *st + 1;
        }
        break;
    case 3:
        func_021C0360(p);
        return 1;
    }
    return 0;
}
