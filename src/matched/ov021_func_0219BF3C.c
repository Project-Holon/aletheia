/*
 * function: func_0219BF3C
 * address:  0x0219BF3C
 * packet:   pkt_0219BF3C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0216D69C  0x0216D69C  thumb
 */

typedef unsigned int u32;

void *func_0216D69C(void);

void func_0219BF3C(int a, u32 v)
{
    *(u32 *)((char *)func_0216D69C() + 4) = v;
}
