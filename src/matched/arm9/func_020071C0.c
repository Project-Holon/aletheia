/*
 * function: func_020071C0
 * address:  0x020071C0
 * packet:   pkt_020071C0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Thumb tail-call stub: loads p->field_0x10 and tail-calls func_02031E68.
 * Witness leaf for ov034 func_021F09BC.
 *
 * symbols:
 *   func_02031E68 0x02031E68 arm
 */

typedef unsigned int u32;

extern u32 func_02031E68(void *p);

u32 func_020071C0(char *p)
{
    return func_02031E68(*(void **)(p + 0x10));
}
