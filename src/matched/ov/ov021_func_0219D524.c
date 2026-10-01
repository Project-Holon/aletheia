/*
 * function: func_0219D524
 * address:  0x0219D524
 * packet:   pkt_ov021_0219D524
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct { u16 a; u16 b; } E4;

u16 func_0219D524(u8 *s, u16 b, u16 a)
{
    int i;
    E4 *e = *(E4 **)(s + 0xc);
    int n = *(u16 *)(s + 8);
    for (i = 0; i < n; i++, e++) {
        if (e->b == 0xFFFF) {
            e->b = b;
            e->a = a;
            return i;
        }
    }
    return 0;
}
