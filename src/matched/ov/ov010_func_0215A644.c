/*
 * function: func_0215A644
 * address:  0x0215A644
 * packet:   pkt_ov010_0215A644
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (setter through the pointer at +0x20), filed as a blocker
 * of ov021 func_021C459C / func_021C4628.
 */

typedef unsigned int u32;

void func_0215A644(void *p, u32 v)
{
    *(u32 *)(*(char **)((char *)p + 0x20) + 0x10) = v;
}
