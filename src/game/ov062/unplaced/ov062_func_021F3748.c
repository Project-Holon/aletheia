/*
 * function: func_021F3748
 * address:  0x021F3748
 * packet:   pkt_ov062_021F3748
 * region:   ov062
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two-call wrapper.
 *
 * symbols:
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021BE580  0x021BE580  thumb  ov021
 */

extern void *func_02188D2C(void *fieldMap);
extern void func_021BE580(void *expObj);

/* Per-frame update: advances the model animes. */
void func_021F3748(void *fieldMap)
{
    func_021BE580(func_02188D2C(fieldMap));
}
