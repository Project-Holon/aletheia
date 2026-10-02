/*
 * function: func_021F87D4
 * address:  0x021F87D4
 * packet:   pkt_ov094_021F87D4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Witness leaf for ov093 func_021ED4E4: tail call (obj, v) to func_0220893C.
 *
 * symbols:
 *   d_0220AF20     0x0220AF20  data   ov094
 *   func_0220893C  0x0220893C  thumb  ov094
 */
typedef unsigned int u32;

typedef struct {
    char pad[0x1A4];
    void *obj;          /* 0x1A4 */
} Work;

extern Work *d_0220AF20;

extern void func_0220893C(void *o, u32 v);

void func_021F87D4(u32 v)
{
    func_0220893C(d_0220AF20->obj, v);
}
