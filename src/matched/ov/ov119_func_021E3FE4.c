/*
 * function: func_021E3FE4
 * address:  0x021E3FE4
 * packet:   pkt_ov119_021E3FE4
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201F5DC  0x0201F5DC  thumb
 */

extern void *func_0201F5DC(void *, unsigned, unsigned, unsigned);

void func_021E3FE4(char *p)
{
    *(void **)(p + 0x644) = func_0201F5DC((void *)6, 15, 0, *(unsigned short *)(p + 0x5F4));
}
