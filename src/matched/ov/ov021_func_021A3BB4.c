/*
 * function: func_021A3BB4
 * address:  0x021A3BB4
 * packet:   pkt_ov021_021A3BB4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A3C3C  0x021A3C3C  thumb  ov021
 *   func_021A3C54  0x021A3C54  thumb  ov021
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_0216D608  0x0216D608  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_021A3C3C(u32 keys);
extern int func_021A3C54(u32 keys);
extern void *func_021A3960(u8 *p);
extern u16 func_0216D608(void *p);

u16 func_021A3BB4(u8 *p, u32 keys)
{
    u32 a;
    u32 b;
    u32 c;
    u32 h1;
    u32 h2;

    a = func_021A3C3C(keys);
    b = func_021A3C54(keys);
    if (a == 9) {
        return b;
    }
    if (b == 9) {
        return a;
    }
    c = func_0216D608(func_021A3960(p));
    h1 = *(u16 *)(p + 0x20);
    h2 = *(u16 *)(p + 0x22);
    if (c != 9) {
        if (a == h1 && b == h2) {
            if (b == c) {
                return b;
            }
            if (a == c) {
                return a;
            }
        }
        if (b != h2) {
            return b;
        }
        return a;
    }
    return b;
}
