/*
 * function: func_021BD0F4
 * address:  0x021BD0F4
 * packet:   pkt_ov088_021BD0F4
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020056A0  0x020056A0  thumb
 *   func_021BD0D8  0x021BD0D8  thumb  ov088
 */

extern void *func_020056A0(void (*)(void), void *, int);
extern void func_021BD0D8(void);

void func_021BD0F4(void **p)
{
    *p = func_020056A0(func_021BD0D8, p, 0);
}
