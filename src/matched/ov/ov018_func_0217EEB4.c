/*
 * function: func_0217EEB4
 * address:  0x0217EEB4
 * packet:   pkt_ov018_0217EEB4
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204989C  0x0204989C  arm
 *   func_02045374  0x02045374  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_0217F1E8  0x0217F1E8  thumb  ov018
 *   func_0217F240  0x0217F240  thumb  ov018
 */

typedef unsigned char u8;

typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_0204989C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 flags);
extern void func_02045374(int);
extern void func_02041B6C(u32 bit);
extern int func_0217F1E8(int *);
extern void func_0217F240(int *, int);

void func_0217EEB4(int *p)
{
    int n;

    n = 0;
    if (*((u8 *)p + 0x11f) == 0) {
        if (*((u8 *)p + 0xda) > 1) {
            func_0204989C(0x24, 7, 6, 0, 0x800, 1, 0x15);
            *((u8 *)p + 0x11f) = 1;
            n++;
        }
    } else {
        if (*((u8 *)p + 0xda) <= 1) {
            func_0204989C(0x24, 6, 6, 0, 0x800, 1, 0x15);
            *((u8 *)p + 0x11f) = 0;
            n++;
        }
    }
    if (n != 0) {
        func_02045374(p[0x44 / 4]);
        func_02045374(p[0x4c / 4]);
        func_02041B6C(6);
        if (func_0217F1E8(p) == 1) {
            func_0217F240(p, 1);
        }
    }
}
