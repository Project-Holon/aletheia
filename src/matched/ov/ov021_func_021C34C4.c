/*
 * function: func_021C34C4
 * address:  0x021C34C4
 * packet:   pkt_ov021_021C34C4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Compatibility of the two deposited Pokemon, 0 when fewer than two (EXACT*: pad).
 *
 * symbols:
 *   func_0200BCB8  0x0200BCB8  thumb
 *   func_0200BC2C  0x0200BC2C  thumb
 *   func_021C36EC  0x021C36EC  thumb  ov021
 */

typedef unsigned char u8;

extern void *func_0200BC2C(void *e, int i);
extern int func_0200BCB8(void *e);
extern int func_021C36EC(void *a, void *b);

u8 func_021C34C4(void **p)
{
    void *a;

    if (func_0200BCB8(p[2]) < 2)
        return 0;
    a = func_0200BC2C(p[2], 0);
    return func_021C36EC(a, func_0200BC2C(p[2], 1));
}
