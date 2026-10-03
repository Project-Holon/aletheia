/*
 * function: ov021_func_021A47B4
 * address:  0x021A47B4
 * packet:   pkt_ov021_021A47B4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_021A4768  0x021A4768  thumb  ov021
 *   func_021A569C  0x021A569C  thumb  ov021
 *   func_021AB11C  0x021AB11C  thumb  ov021
 *   func_021A53A4  0x021A53A4  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern int func_0216D3CC(int a0);
extern int func_021A4768(u32, u32, u32);
extern int func_021A569C(int a, int b, int c, int *d);
extern int func_021AB11C(u32 attr);
extern int func_021A53A4(u32, u32);

int ov021_func_021A47B4(u32 a, u32 b, u8 *c)
{
    int sp;
    u32 r;
    if (func_0216D3CC(b) == 0) {
        return 0;
    }
    if (*(u16 *)(c + 8) == 9) {
        return func_021A4768(a, b, (u32)c);
    }
    r = func_021A569C(a, b, *(u16 *)(c + 8), &sp);
    if (sp != -1) {
        if (r & 0x100) {
            if (!(r & 0xFFFFFEFF)) {
                return 2;
            }
        } else if (func_021AB11C(sp) == 0) {
            func_021A53A4(a, 1);
            return 7;
        }
    }
    return 4;
}
