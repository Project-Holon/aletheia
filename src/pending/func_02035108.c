/*
 * function: func_02035108
 * address:  0x02035108
 * packet:   pkt_0203508C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * symbols:
 *   g_021469BC     0x021469BC  data
 *   func_02035100  0x02035100  arm
 *
 * Parked: every concrete byte is right; the one open site is the tail call
 * to 0x02035100, whose only reference image-wide is this pool word, so it has
 * no witness outside the range (not a manifest entry, not a func_ label, not
 * in layout/runtime_arm9.txt). The global pointer g_021469BC resolves on
 * `literal`. Closes when 0x02035100 gets a manifest entry or a second caller.
 */

typedef unsigned int u32;

extern u32 g_021469BC;
extern void func_02035100(u32 a);

void func_02035108(void)
{
    func_02035100(g_021469BC);
}
