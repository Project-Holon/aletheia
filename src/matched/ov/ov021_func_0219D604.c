/*
 * function: func_0219D604
 * address:  0x0219D604
 * packet:   pkt_ov021_0219D604
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C6580  0x021C6580  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct { u16 a; u16 b; } E4;
extern void func_021C6580(u32, u16);

void func_0219D604(u8 *s, u16 k)
{
    int i;
    int n = *(u16 *)(s + 8);
    E4 *e = *(E4 **)(s + 0xc);
    for (i = 0; i < n; i++, e++) {
        if (e->b == k) {
            func_021C6580(*(u32 *)(s + 4), e->a);
            e->b = 0xFFFF;
            return;
        }
    }
}
