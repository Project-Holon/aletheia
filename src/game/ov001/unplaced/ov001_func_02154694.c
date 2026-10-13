/*
 * function: func_02154694
 * address:  0x02154694
 * packet:   pkt_ov001_02154694
 * region:   ov001
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk to func_0215466C, stored as a callback by ov021
 * func_021B4CDC (pool word 0x02154695).
 *
 * symbols:
 *   func_0215466C  0x0215466C  thumb  ov001
 */

extern void *func_0215466C(void *gameSystem, int a);

/* Overlay entry point: forwards to the event constructor. */
void *func_02154694(void *gameSystem, int a)
{
    return func_0215466C(gameSystem, a);
}
