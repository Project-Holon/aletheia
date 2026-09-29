/*
 * function: func_021F41F0
 * address:  0x021F41F0
 * packet:   pkt_ov055_021F41F0
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
 *   func_0216D5B4  0x0216D5B4  thumb  ov010
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_021F4318  0x021F4318  thumb  ov055
 *   func_021F42AC  0x021F42AC  thumb  ov055
 *   func_021F3DD4  0x021F3DD4  thumb  ov055
 *   func_021F3DBC  0x021F3DBC  thumb  ov055
 *   func_021F3D90  0x021F3D90  thumb  ov055
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_0216D454();
extern void func_0216D410(u32 a, u32 b);
extern void func_0216D5B4(u32 a, u32 b);
extern int func_021A3074();
extern int func_021F4318(u8 *a, void *b, u32 c, u32 d);
extern int func_021F42AC(u8 *a, u32 b, u32 *c, u32 d, u32 e);
extern void func_021F3DD4(u8 *a, u32 b);
extern void func_021F3DBC(u8 *a);
extern void func_021F3D90(u8 *a);

void func_021F41F0(u8 *a, u32 b, u32 c)
{
    u32 loc;
    void *x;

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
        x = (void *)func_021A3074(c);
        c = 1;
        if (func_021F4318(a, x, 1, 1)) {
            func_0216D5B4(*(u32 *)(a + 0xc), *(u16 *)(a + 6));
            return;
        }
        if (func_021F42AC(a, b, &loc, c, 0)) {
            func_021F3DD4(a, loc);
            func_0216D5B4(*(u32 *)(a + 0xc), 0x7d0);
            func_021F3D90(a);
        } else {
            func_0216D410(*(u32 *)(a + 0xc), (u16)(*(u16 *)(a + 0xa) + a[3]));
            *(u16 *)(a + 4) = *(u16 *)(a + 4) - 1;
            func_0216D5B4(*(u32 *)(a + 0xc), 0x7d0);
        }
        a[1] = 0;
        return;
    case 2:
        func_021F3DBC(a);
        return;
    }
}
