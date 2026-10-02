/*
 * function: func_021BD3B4
 * address:  0x021BD3B4
 * packet:   pkt_021BD368
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BD43C 0x021BD43C  thumb  ov208
 *   func_021BD868 0x021BD868  thumb  ov208

 * Calls func_021BD43C then func_021BD868.
 */


extern void *func_021BD43C(void *mgr, int key);
extern int func_021BD868(const void *p);

int func_021BD3B4(void *mgr, int key)
{
    return func_021BD868(func_021BD43C(mgr, key));
}

