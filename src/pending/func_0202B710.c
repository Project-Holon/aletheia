/*
 * function: func_0202B710
 * address:  0x0202B710
 * packet:   pkt_0202B6F8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 *
 * Blocked: 0202B8F4 (thumb, from header) has no witness outside 0202B710..0202B720. Every concrete byte reproduces.
 * status:   MATCH
 * symbols:
 *   func_0202B8F4  0x0202B8F4  thumb
 *
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_0202B8F4(u32 v);

void func_0202B710(u8 *o)
{
    if ((*(u32 *)(o + 0xc) & 1) == 0) {
        func_0202B8F4(*(u32 *)(o + 0x24));
    }
}
