/*
 * function: func_02156330
 * address:  0x02156330
 * packet:   pkt_ov009_02156330
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Leaf blocker of the ov099 func_021BC104 +0022 call site. Sibling of
 * func_02156BC4 (same block, halfword at +0x782); this one stamps +0x794.
 *
 * symbols:
 *   g_021A8264  0x021A8264  data  ov009
 */

typedef unsigned short u16;

extern int g_021A8264;

void func_02156330(void)
{
    *(u16 *)((char *)(int *)g_021A8264 + 0x794) = 1;
}
