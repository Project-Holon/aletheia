/*
 * function: func_0202B6DC
 * address:  0x0202B6DC
 * packet:   pkt_0202B6CC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 *
 * Blocked: 0202AB38 (thumb, from header) has no witness outside 0202B6DC..0202B6EC. Every concrete byte reproduces.
 * status:   EXACT
 * closed:   blocker func_0202B6DC.c is now a manifest entry (matched class)
 * symbols:
 *   func_0202AB38  0x0202AB38  thumb
 *
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_0202AB38(u32 v);

void func_0202B6DC(u8 *o)
{
    if ((*(u32 *)(o + 0xc) & 1) == 0) {
        func_0202AB38(*(u32 *)(o + 0x10));
    }
}
