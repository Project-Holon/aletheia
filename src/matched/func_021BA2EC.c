/*
 * function: func_021BA2EC
 * address:  0x021BA2EC
 * packet:   pkt_021BA2EC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BA2EC   0x021BA2EC  thumb
 *
 * Call func_02087C6C, then return 1.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021BA2EC.c \
 *       --func func_021BA2EC --addr 0x021BA2EC --region ov016 --cc dsi/1.1p1 --thumb
 */

extern void func_02087C6C(void);

int func_021BA2EC(void)
{
    func_02087C6C();
    return 1;
}
