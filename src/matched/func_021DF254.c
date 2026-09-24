/*
 * function: func_021DF254
 * address:  0x021DF254
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EF224  0x021EF224  thumb  ov170
 *
 * Sub-system id wrap test: the id from func_021EF224, offset by the frame
 * delta and the p[0x19] carry, is reduced modulo p[0x15] and compared with
 * p[0x14]; 0xff on mismatch.
 *   CLOSES the last byte: the image's `blo` over the p[0x15] fold needs the
 *   test UNSIGNED.  With `int w` the same body emits `blt` (00 db) and is one
 *   byte out; `unsigned w` (or an unsigned cast on the bound) emits `blo`.
 */

extern int func_021EF224(int, int);
int func_021DF254(char *p)
{
    int v = func_021EF224(*(int *)(*(int *)(p + 0x2c) + 0xA180),
                          *(int *)(*(int *)(p + 0x2c) + 0xA184));
    unsigned w;
    if (v == 0xff)
        return v;
    w = v - 0x24 + *(unsigned char *)(p + 0x19);
    if (w >= *(unsigned char *)(p + 0x15))
        w -= *(unsigned char *)(p + 0x15);
    if (w == *(unsigned char *)(p + 0x14))
        return 0xff;
    return v;
}
