/*
 * function: func_021DECA0
 * address:  0x021DECA0
 * packet:   pkt_021DECA0
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021DE2E0  0x021DE2E0  arm
 *
 * Five-argument forward to func_021DE2E0 (ov175): the object itself is the
 * first argument, its +0x0c cursor is passed bare and +4, and the +0x08
 * block contributes its fifth and fourth words.
 */

typedef unsigned long u32;

extern void func_021DE2E0(u32 a, u32 b, u32 c, u32 d, u32 e);

void func_021DECA0(char *obj)
{
    u32 *ip = *(u32 **)(obj + 8);
    u32 v = *(u32 *)(obj + 0xc);
    func_021DE2E0((u32)obj, v + 4, v, ip[4], ip[3]);
}

