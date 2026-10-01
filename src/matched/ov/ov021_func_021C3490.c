/*
 * function: func_021C3490
 * address:  0x021C3490
 * packet:   pkt_ov021_021C3490
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Levels gained by the slot-i day-care Pokemon (EXACT*: pad).
 *
 * symbols:
 *   func_0200BC2C  0x0200BC2C  thumb
 *   func_021C341C  0x021C341C  thumb  ov021
 */

typedef unsigned int u32;

extern void *func_0200BC2C(void *e, int i);
extern u32 func_02017E1C(void *mon, u32 id, u32 v);
extern int func_021C341C(void **p, int i);

int func_021C3490(void **p, int i)
{
    int lv = func_02017E1C(func_0200BC2C(p[2], i), 0x9E, 0);

    return func_021C341C(p, i) - lv;
}
