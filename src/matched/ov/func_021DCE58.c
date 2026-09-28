/*
 * function: func_021DCE58
 * address:  0x021DCE58
 * packet:   pkt_021DCE58
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Symbols:
 *   (none)
 *
 * Two-word setter on an ov175 context block: stores the caller's word at
 * +0x14 and hard-codes 4 at +0x1c.  A leaf with no prologue, so disasm.py
 * only found it through a branch target.
 */

typedef unsigned long u32;

void func_021DCE58(char *ctx, u32 v)
{
    *(u32 *)(ctx + 0x14) = v;
    *(u32 *)(ctx + 0x1c) = 4;
}
