/*
 * file:     unit_021C11EC.c
 * function: func_021C11EC
 * address:  0x021C11EC
 * packet:   pkt_021C11D4
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C11EC   0x021C11EC  arm
 *
 * ARM tail-call thunk into func_021D3D8C.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C11EC.c \
 *       --func func_021C11EC --addr 0x021C11EC --region ov016 --cc dsi/1.1p1 --arm
 */

extern int func_021D3D8C(void);

void func_021C11EC(void)
{
    func_021D3D8C();
}
