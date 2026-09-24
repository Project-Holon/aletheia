/*
 * function: func_021B9574
 * address:  0x021B9574
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  the tail call targets 0x021BA094, which carries no func_
 *           label in asm/overlays/ov172.s (disasm did not trace it here), so the
 *           pool word has no witness inside this region.  The label exists in the
 *           ov093/ov217/ov221 listings, so a second caller or a region token for
 *           the target unblocks it.  Every concrete byte reproduces.
 *
 * Tail call passing the field at +0x10.
 *
 * symbols:
 *   func_021BA094  0x021BA094  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_021BA094(u32 v);

void func_021B9574(int unused, char *p)
{
    func_021BA094(*(u32 *)(p + 0x10));
}
