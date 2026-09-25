/*
 * function: func_021E58BC
 * address:  0x021E58BC
 * packet:   pkt_021E58BC
 * region:   ov178
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E58F4  0x021E58F4  thumb  ov178
 *   func_021E5A90  0x021E5A90  thumb  ov178
 */
typedef unsigned int u32;

extern u32 func_021E58F4(void *d, u32 *c, u32 b);
extern u32 func_021E5A90(void *d, u32 *c, u32 b);

int func_021E58BC(u32 a, u32 b, u32 *c, void *d)
{
    u32 r;

    switch (c[1]) {
    case 0:
        r = func_021E58F4(d, c, b);
        break;
    case 1:
        r = func_021E5A90(d, c, b);
        break;
    }
    return r != 0;
}
