/*
 * function: func_0219C2E0
 * address:  0x0219C2E0
 * packet:   pkt_ov021_0219C2E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0219C298  0x0219C298  thumb  ov021
 *   func_0219C2BC  0x0219C2BC  thumb  ov021
 *   d_021D53F4  0x021D53F4  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int func_0219C298(u32 a, int b, int c);
extern int func_0219C2BC(u32 a, int b, int c);
extern int d_021D53F4[][2];

int func_0219C2E0(u32 a, int b, int c)
{
    if (func_0219C298(a, b, c) == 0) {
        if (func_0219C2BC(a, b, c) == 0) {
            return 9;
        }
        b = d_021D53F4[b][c];
    }
    return b;
}
