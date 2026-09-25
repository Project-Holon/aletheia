/*
 * function: func_021F9CF4
 * address:  0x021F9CF4
 * packet:   pkt_021F9CF4
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F9EDC  0x021F9EDC  thumb
 *
 * Addresses are Black-image addresses.
 */

extern void *func_021F9EDC(void *, int);

void func_021F9CF4(char *p)
{
    *(void **)(p + 0xbc) = func_021F9EDC(*(void **)(p + 0x6c), 0x36);
}
