/*
 * function: func_02209A54
 * address:  0x02209A54
 * packet:   pkt_ov094_02209A54
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Task callback passed to func_020056A0 by func_02209784 (leaf of that
 * caller: its pool word 0x02209A55 names this unlabelled Thumb function).
 *
 * symbols:
 *   func_02030EE8  0x02030EE8  arm
 *   func_02040618  0x02040618  arm
 *   func_021F89BC  0x021F89BC  thumb  ov094
 */
extern int *func_02030EE8(void *h);
typedef unsigned int   u32;
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_021F89BC(void *h);

void func_02209A54(void *h)
{
    int *p = func_02030EE8(h);

    func_02040618(3, 0, p[0]);
    func_02040618(3, 3, p[1]);
    func_021F89BC(h);
}
