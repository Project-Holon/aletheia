/*
 * function: func_021DEAF8
 * address:  0x021DEAF8
 * packet:   pkt_021DEAF8
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   (none)
 *
 * If the +0x0c cursor is live, forwards its first two words as the
 *  *  second and third arguments and the +0x08 block's +0x08 word as the
 *  *  first to func_021DE8AC (ov175).
 */

typedef unsigned long u32;

extern void func_021DE8AC(u32 a, u32 b, u32 c);

void func_021DEAF8(char *obj)
{
    u32 *cur = *(u32 **)(obj + 0xc);
    char *blk = *(char **)(obj + 8);
    if (cur == 0)
        return;
    func_021DE8AC(*(u32 *)(blk + 8), cur[0], cur[1]);
}

