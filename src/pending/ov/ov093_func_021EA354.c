/*
 * function: func_021EA354
 * address:  0x021EA354
 * packet:   pkt_ov093_021EA354
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH*
 * note:     2026-10-02: byte-correct; relocations to func_021F853C, func_021F7E74 and
 *           func_021F7E84 stay wildcarded (no outside witness: only this function branches to
 *           021F853C and 021F7E84; 021F7E74 is matched only under ov135). Not a tiny leaf, so no witness filed.
 *
 * symbols:
 *   func_021F7F1C  0x021F7F1C  thumb  ov094
 *   func_021F853C  0x021F853C  thumb  ov094
 *   func_021F7E74  0x021F7E74  thumb  ov094
 *   func_021F7E84  0x021F7E84  thumb  ov094
 */
extern int func_021F7F1C(int i);
extern int func_021F853C(int i);
extern int func_021F7E74(int i);
extern int func_021F7E84(int i);

void func_021EA354(void *ctx, int a, int b)
{
    if (func_021F7F1C(a) != 0) {
        if (b != func_021F853C(a)) {
            if (b == 1) {
                func_021F7E74(a);
            } else {
                func_021F7E84(a);
            }
        }
    }
}
