/*
 * function: func_021EA354
 * address:  0x021EA354
 * packet:   pkt_ov093_021EA354
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status: EXACT*
 * note:     2026-10-03: byte-correct. The three callees are unlabelled Thumb tail-call stubs in
 *           ov094 (ov093 window does not hold them; the ov094 hint is right). Witnesses filed
 *           EXACT: src/matched/ov/ov094_func_021F853C.c, ov094_func_021F7E74.c,
 *           ov094_func_021F7E84.c. Once the integrator creates their shards, the `matched`
 *           class resolves the three sites through the ov094 hint; re-verify and file EXACT.
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
