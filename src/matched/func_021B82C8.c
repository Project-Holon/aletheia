/*
 * function: func_021B82C8
 * address:  0x021B82C8
 * packet:   pkt_021B8230
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B82C8   0x021B82C8  thumb
 *
 * Thumb tail-call thunk into func_0215F428.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021B82C8.c \
 *       --func func_021B82C8 --addr 0x021B82C8 --region ov016 --cc dsi/1.1p1 --thumb
 */

extern void func_0215F428(void);

void func_021B82C8(void)
{
    func_0215F428();
}
