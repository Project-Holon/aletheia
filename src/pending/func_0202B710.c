/*
 * function: func_0202B710
 * address:  0x0202B710
 * packet:   pkt_0202B710
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Blocked: the THM_CALL at +000A targets 0x0202B8F4, a four-byte Thumb linker
 * veneer (`00 4b 18 47` + its target word, the head of the identical run
 * 0x0202B8F4/8FC/904/90C).  It is artifact class: no C spelling produces it,
 * so it can never be a manifest entry and `literal` has no outside pool word
 * either (permanent).  Every concrete byte reproduces.
 * symbols:
 *   func_0202B8F4  0x0202B8F4  thumb
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
