/*
 * function: func_021B89C0
 * address:  0x021B89C0
 * packet:   pkt_021B8230
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B89C0   0x021B89C0  thumb
 *
 * Thumb tail-call thunk into func_02085A38.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021B89C0.c \
 *       --func func_021B89C0 --addr 0x021B89C0 --region ov016 --cc dsi/1.1p1 --thumb
 */

extern void func_02085A38(unsigned int msec);

void func_021B89C0(unsigned int msec)
{
    func_02085A38(msec);
}
