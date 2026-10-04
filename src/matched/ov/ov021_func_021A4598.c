/*
 * function: func_021A4598
 * address:  0x021A4598
 * packet:   pkt_ov021_021A4598
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Twin of ov021_func_021A4B98 with an extra tile-class check (ids
 * classed 0..3 by func_021AB158/164/170/17C) that returns 5.
 *
 * symbols:
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_021A4544  0x021A4544  thumb  ov021
 *   func_021A5264  0x021A5264  thumb  ov021
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021AB0F8  0x021AB0F8  thumb  ov021
 *   func_021AB158  0x021AB158  thumb  ov021
 *   func_021AB164  0x021AB164  thumb  ov021
 *   func_021AB170  0x021AB170  thumb  ov021
 *   func_021AB17C  0x021AB17C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_0216D3CC(int a0);
extern int func_021A4544(u8 *p, u32 r, u8 *q);
extern int func_021A5264(u8 *a, void *b, u32 c, int *d);
extern u16 func_021AB0F0(u32 attr);
extern u16 func_021AB0F8(u32 attr);
extern int func_021AB158(u16);
extern int func_021AB164(u16);
extern int func_021AB170(u16);
extern int func_021AB17C(u16);

int func_021A4598(u8 *a, void *b, u8 *c)
{
    int sp;
    u32 r;
    u16 k;
    u32 t;
    int cls;

    if (func_0216D3CC((int)b) == 0) {
        return 0;
    }
    if (*(u16 *)(c + 8) == 9) {
        return func_021A4544(a, (u32)b, c);
    }
    r = func_021A5264(a, b, *(u16 *)(c + 8), &sp);
    if (*(u32 *)(c + 16) == 1 && r != 0 && !(r & 0x10)) {
        r = 0;
    }
    if (sp != -1) {
        k = func_021AB0F0(sp);
        t = func_021AB0F8(sp);
        if (r & 2) {
            cls = 9;
            if (func_021AB158(k)) {
                cls = 0;
            } else if (func_021AB164(k)) {
                cls = 1;
            } else if (func_021AB170(k)) {
                cls = 2;
            } else if (func_021AB17C(k)) {
                cls = 3;
            }
            if (cls != 9 && cls == *(u16 *)(c + 8)) {
                return 5;
            }
        }
        if (r == 0) {
            if (!(t & 2)) {
                return 2;
            }
            if (*(u32 *)(c + 16) == 1) {
                return 2;
            }
        }
    }
    return 4;
}
