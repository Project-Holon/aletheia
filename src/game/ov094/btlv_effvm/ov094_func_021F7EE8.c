/*
 * function: func_021F7EE8
 * address:  0x021F7EE8
 * packet:   pkt_ov094_021F7EE8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf, filed as the blocker of ov093 callers (lane S15).
 *
 * symbols:
 *   d_0220AF20     0x0220AF20  data   ov094
 *   func_021FEEA8  0x021FEEA8  thumb  ov094
 */

typedef unsigned int u32;

extern char *d_0220AF20;
extern void func_021FEEA8(char *w, void *src, int key);

void func_021F7EE8(void *m, int key)
{
    func_021FEEA8(*(char **)(d_0220AF20 + 0x190), m, key);
}
