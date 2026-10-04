/*
 * function: func_021A5044
 * address:  0x021A5044
 * packet:   pkt_ov021_021A5044
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A5788  0x021A5788  thumb  ov021
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021AB41C  0x021AB41C  thumb  ov021
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021AC528  0x021AC528  thumb  ov021
 *   func_021A57C0  0x021A57C0  thumb  ov021
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_021A3964  0x021A3964  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_021A5788(u32, u32, u32 *);
extern u16 func_021AB0F0(u32 attr);
extern int func_021AB41C(int x);
extern u32 func_02188CD0(u8 *p);
extern void func_021AC528(u32, u32);
extern int func_021A57C0(u8 *p, int dir);
extern int func_02197E7C(int a, int b);
extern void func_0216D410(u32, u32);
extern void func_021A3964(u8 *p, u32 v);

void func_021A5044(u32 *a, u32 b, u32 *c)
{
    u32 v;
    u32 r;
    int f = 1;
    if (c[4] == 1) {
        r = 0x14;
        f = 0;
    } else {
        r = 0x14;
        if (func_021A5788((u32)a, 9, &v) == 1) {
            if (func_021AB41C(func_021AB0F0(v)) == 1) {
                r = 0x9b;
                func_021AC528(b, func_02188CD0((u8 *)a[4]));
            }
        }
    }
    if (f == 1) {
        if (func_021A57C0((u8 *)((u32)a), *(u16 *)(c + 2)) == 1) {
            if (r == 0x14) {
                r = 0x10;
            }
        }
    }
    func_0216D410(b, func_02197E7C(*(u16 *)(c + 2), r));
    a[0] = 1;
    func_021A3964((u8 *)a[3], 1);
}
