/*
 * function: func_021F4174
 * address:  0x021F4174
 * packet:   pkt_ov055_021F4174
 * region:   ov055
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_021F42AC  0x021F42AC  thumb  ov055
 *   func_021F3DD4  0x021F3DD4  thumb  ov055
 *   func_021F3DBC  0x021F3DBC  thumb  ov055
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_0216D454();
extern void func_0216D410(u32 a, u32 b);
extern int func_021F42AC(u8 *a, u32 b, u32 *c, u32 d, u32 e);
extern void func_021F3DD4(u8 *a, u32 b);
extern void func_021F3DBC(u8 *a);

void func_021F4174(u8 *a, u32 b)
{
    u32 loc;

    switch (a[1]) {
    case 0:
        if (func_0216D454(*(u32 *)(a + 0xc)) == 0) {
            return;
        }
        a[1] = a[1] + 1;
    case 1:
        if (*(u16 *)(a + 4) == 0) {
            a[1] = 2;
            return;
        }
        if (func_021F42AC(a, b, &loc, 2, 0)) {
            func_021F3DD4(a, loc);
        } else {
            func_0216D410(*(u32 *)(a + 0xc), (u16)(*(u16 *)(a + 0xa) + a[3]));
            *(u16 *)(a + 4) = *(u16 *)(a + 4) - 1;
        }
        a[1] = 0;
        return;
    case 2:
        func_021F3DBC(a);
        return;
    }
}
