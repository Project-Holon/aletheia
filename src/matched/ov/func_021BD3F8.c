/*
 * function: func_021BD3F8
 * address:  0x021BD3F8
 * packet:   pkt_021BD3F8
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BD404 0x021BD404  thumb  ov208
 */

extern char *func_021BD404(void *mgr, int key);

void func_021BD3F8(void *mgr, int key)
{
    *(int *)(func_021BD404(mgr, key) + 0x34) = 1;
}

