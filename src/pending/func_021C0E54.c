/*
 * function: func_021C0E54
 * address:  0x021C0E54
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Tail-call veneer: `ldr r3, =0x021C0EC1; bx r3`.  The nine bytes of code
 * reproduce byte for byte; the one relocation field (the pool word holding
 * 0x021C0EC1) stays wildcarded because that in-overlay address has no
 * independent witness yet - it is not a traced function start in
 * asm/overlays/ov217.s and no matched entry pins it.
 *
 * Blocking site: the pool word in this veneer, whose target 0x021C0EC1 must
 * first be matched (or witnessed as a label) elsewhere in ov217.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef signed int     s32;

extern void func_021C0EC0(void);

void func_021C0E54(void)
{
    func_021C0EC0();
}
