/*
 * file:     unit_021B89C0.c
 * function: AOSSi_Sleep
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
 *   AOSSi_Sleep   0x021B89C0  thumb
 *
 * Thumb tail-call thunk into func_02085A38.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/AOSSi_Sleep.c \
 *       --func AOSSi_Sleep --addr 0x021B89C0 --region ov016 --cc dsi/1.1p1 --thumb
 */

extern void func_02085A38(unsigned int msec);

void AOSSi_Sleep(unsigned int msec)
{
    func_02085A38(msec);
}
