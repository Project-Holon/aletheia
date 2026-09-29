/*
 * function: func_021A0C74
 * address:  0x021A0C74
 * packet:   pkt_ov021_021A0C74
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A0A50  0x021A0A50  thumb  ov021
 *   func_021A0B34  0x021A0B34  thumb  ov021
 *   func_021A0980  0x021A0980  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

extern void func_021A0A50(void *a, void *b, u32 c, u32 d);
extern s32 func_021A0B34(void *a);
extern void func_021A0980(void *a, void *b, void *c, u32 d);

s32 func_021A0C74(u16 *a, void *b, void *c, void *d)
{
    switch (a[0]) {
    case 1:
        func_021A0A50(b, c, a[3], a[1]);
        a[0] = 2;
        break;
    case 2:
        if (func_021A0B34(b) == 0) {
            if (a[2] != 0xFFFF) {
                func_021A0980(b, c, d, a[2]);
            }
            a[0] = 3;
        }
        break;
    case 3:
        if (func_021A0B34(b) == 0) {
            a[0] = 0;
        }
        break;
    case 0:
        return 1;
    }
    return 0;
}
