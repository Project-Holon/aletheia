/*
 * function: func_02197800
 * address:  0x02197800
 * packet:   pkt_ov021_02197800
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020279E8  0x020279E8  thumb
 *   func_02027A04  0x02027A04  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_020071F0  0x020071F0  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_02197644  0x02197644  thumb  ov021
 *   func_02196290  0x02196290  thumb  ov021
 *   func_02196228  0x02196228  thumb  ov021
 *   func_020414EC  0x020414EC  arm
 *   func_021962F4  0x021962F4  thumb  ov021
 *   func_02196034  0x02196034  thumb  ov021
 *   func_021977C0  0x021977C0  thumb  ov021
 *   func_02197798  0x02197798  thumb  ov021
 *   func_02196A4C  0x02196A4C  thumb  ov021
 *   func_02027858  0x02027858  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_020279E8(u32);
extern u32 func_02027A04(u32);
extern void func_02012EBC(u32);
extern u32 func_020071F0(void);
extern void func_02045CAC(u32, u32, u32);
extern void func_02197644(u8 *, u32);
extern void func_02196290(u8 *);
extern void func_02196228(u8 *p, int flag);
extern void func_020414EC(u32);
extern void func_021962F4(u8 *);
extern void func_02196034(u8 *, void (*)(), u32);
extern void func_021977C0(u8 *a);
extern void func_02197798(u8 *a);
extern void func_02196A4C(u8 *a);
extern void func_02027858(u32);

void func_02197800(u8 *a)
{
    if (func_020279E8(*(u32 *)(a + 0x2c0)) != 0) {
        if (func_02027A04(*(u32 *)(a + 0x2c0)) == 0) {
            func_02012EBC(*(u32 *)(a + 0x30));
            if (func_020071F0() != 0) {
                func_02045CAC(*(u32 *)(a + 0x28), 0x2d, *(u32 *)(a + 0x38));
                func_02197644(a, 0);
                func_02196034(a, func_021977C0, 0x7b9);
            } else {
                func_02045CAC(*(u32 *)(a + 0x28), 0x1c, *(u32 *)(a + 0x38));
                func_02197644(a, 1);
                func_02196290(a);
                func_02196034(a, func_02197798, 0x7bf);
            }
        } else {
            func_02196228(a, 0);
            func_020414EC(3);
            func_021962F4(a);
            *(u32 *)(a + 8) = 12;
            func_02196034(a, func_02196A4C, 0x7c7);
        }
        func_02027858(*(u32 *)(a + 0x2c0));
        *(u32 *)(a + 0x2c0) = 0;
    }
}
