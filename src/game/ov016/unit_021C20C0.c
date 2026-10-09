/*
 * file:     unit_021C20C0.c
 * function: func_021C20C0
 * address:  0x021C20C0
 * packet:   pkt_021C20C0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C20C0   0x021C20C0  arm
 *
 * Two guarded func_021BCB28 calls keyed off func_021D6824.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C20C0.c \
 *       --func func_021C20C0 --addr 0x021C20C0 --region ov016 --cc dsi/1.1p1 --arm
 */

extern int func_021D6824(unsigned int f);
extern void func_021BCB28(signed char v);

void func_021C20C0(void)
{
    if (func_021D6824(1))
        func_021BCB28(1);
    if (func_021D6824(2))
        func_021BCB28(0);
}
