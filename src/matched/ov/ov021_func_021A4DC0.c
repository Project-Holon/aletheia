/*
 * function: func_021A4DC0
 * address:  0x021A4DC0
 * packet:   pkt_ov021_021A4DC0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A3A20  0x021A3A20  thumb  ov021
 *   func_021A5304  0x021A5304  thumb  ov021
 *   func_021A530C  0x021A530C  thumb  ov021
 *   func_021A3898  0x021A3898  thumb  ov021
 *   func_02163E34  0x02163E34  thumb  ov010
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021AB44C  0x021AB44C  thumb  ov021
 *   func_021A57C0  0x021A57C0  thumb  ov021
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_021A3964  0x021A3964  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_021A3A20(u32);
extern void func_021A5304(u32, u32);
extern void func_021A530C(u32, u32);
extern void func_021A3898(u32, int *);
extern int func_02163E34(u32, int *, u32 *);
extern u16 func_021AB0F0(u32 attr);
extern int func_021AB44C(int x);
extern int func_021A57C0(u32, u32);
extern int func_02197E7C(int a, int b);
extern void func_0216D410(u32, u32);
extern void func_021A3964(u32, u32);

void func_021A4DC0(u32 *a, u32 b, u32 *c)
{
    int buf[3];
    u32 v;
    u32 r;
    int f = 1;
    if (c[4] == 1) {
        r = 0x14;
        f = 0;
    } else if ((c[3] & 1) && (c[1] & 2)) {
        if (func_021A3A20(a[3]) == 0) {
            r = 0x10;
        } else {
            r = 0x58;
            func_021A5304((u32)a, 0x20);
            func_021A3898(a[3], buf);
            if (func_02163E34(b, buf, &v) != 0) {
                if (func_021AB44C(func_021AB0F0(v)) != 0) {
                    r = 0xc;
                    f = 0;
                    func_021A530C((u32)a, 0x20);
                }
            }
        }
    } else {
        r = 0xc;
    }
    if (f == 1) {
        if (func_021A57C0((u32)a, *(u16 *)(c + 2)) == 1) {
            switch (r) {
            case 0x10: r = 0x4c; break;
            case 0x58: r = 0xa3; break;
            case 0xc: r = 0xa7; break;
            }
        }
    }
    func_0216D410(b, func_02197E7C(*(u16 *)(c + 2), r));
    a[0] = 1;
    func_021A3964(a[3], 1);
}
