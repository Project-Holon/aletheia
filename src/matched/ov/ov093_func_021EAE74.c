/*
 * function: func_021EAE74
 * address:  0x021EAE74
 * packet:   pkt_ov093_021EAE74
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EAE98  0x021EAE98  thumb  ov093
 */
typedef unsigned int u32;

extern void func_021EAE98(void *a, void *b);

void func_021EAE74(char *p, u32 a, u32 b)
{
    *(u32 *)(p + 0x160) = a;
    *(u32 *)(p + 0x164) = b;
    *(u32 *)(p + 0x16c) = 0;
    func_021EAE98(*(void **)(p + 0x180), p + 0x160);
}
