/*
 * function: func_021B7640
 * address:  0x021B7640
 * packet:   pkt_ov021_021B7640
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201292C  0x0201292C  thumb
 *   func_02030734  0x02030734  arm
 *   func_02009310  0x02009310  thumb
 *   func_02009330  0x02009330  thumb
 *   func_02007E3C  0x02007E3C  thumb
 *   d_021DE288     0x021DE288  data   ov021  a1
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Pair {
    u16 a;
    u16 b;
} Pair;

extern void *func_0201292C(u32 a);
extern Pair *func_02030734(u32 heap, u32 size, u32 a, const u8 *file, u32 line);
extern u16 func_02009310(u32 a, u32 i);
extern u16 func_02009330(u32 a, u32 i);
extern int func_02007E3C(void *a, u32 b, u32 c, u32 d);
extern u8 d_021DE288[];

Pair *func_021B7640(u32 a, u32 b, u32 c, int *d)
{
    Pair *buf;
    void *h;
    int n;
    int i;
    u16 x;
    u16 y;

    h = func_0201292C(a);
    buf = func_02030734(b, 0x50, 1, d_021DE288, 0x14d);
    i = 0;
    n = 0;
    for (; i < 0x14; i++) {
        x = func_02009310(c, i);
        y = func_02009330(c, i);
        if (x != 0 && func_02007E3C(h, x, y, b) == 1) {
            buf[n].a = x;
            buf[n].b = y;
            n++;
        }
    }
    *d = n;
    return buf;
}
