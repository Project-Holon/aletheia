/*
 * function: func_021B82DC
 * address:  0x021B82DC
 * packet:   pkt_021B8230
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B82DC   0x021B82DC  thumb
 *
 * Thumb tail-call thunk into func_0215F644.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021B82DC.c \
 *       --func func_021B82DC --addr 0x021B82DC --region ov016 --cc dsi/1.1p1 --thumb
 */

extern void func_0215F644(void);

void func_021B82DC(void)
{
    func_0215F644();
}
