/*
 * function: func_021D8198
 * address:  0x021D8198
 * packet:   pkt_021D8198
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DA148  0x021DA148  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void func_021DA148(void *);

void func_021D8198(char *p)
{
    void *x = *(void **)(p + 0x260);
    if (x != 0) {
        func_021DA148(x);
        *(u32 *)(p + 0x260) = 0;
    }
}
