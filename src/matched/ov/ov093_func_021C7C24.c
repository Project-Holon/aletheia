/*
 * function: func_021C7C24
 * address:  0x021C7C24
 * packet:   pkt_ov093_021C7C24
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021B8DDC  0x021B8DDC  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 func_021D5440(u8 *p);
extern u8 func_021B8DDC(u32 x);
extern int func_021B9A24(unsigned int a, unsigned int b);

void func_021C7C24(u16 *p, int unused, u8 *b, u8 *c, int e)
{
    u8 x = func_021D5440(b);
    u8 y = func_021D5440(c);
    int mx = func_021B8DDC(x);
    int my = func_021B8DDC(y);
    u8 same = (func_021B9A24(x, y) == 0);
    u16 *q = 0;
    if (mx == 0) {
        if (same) {
            if (e == 0) {
                q = p;
            } else if (e > 3) {
                q = p + 1;
            } else if (e < 3) {
                q = p + 2;
            }
        }
    } else if (my == 0) {
        if (same) {
            if (e == 0) {
                q = p + 3;
            } else if (e > 3) {
                q = p + 4;
            } else if (e < 3) {
                q = p + 5;
            }
        }
    }
    if (q != 0) {
        if (*q < 9999) {
            *q += 1;
        }
    }
}
