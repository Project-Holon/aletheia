/*
 * function: func_021BEFCC
 * address:  0x021BEFCC
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   func_021B9B58  0x021B9B58  arm  ov114
 *
 * blocker:
 *   MATCH: bytes identical; the single relocation to the unnamed ARM stub at 0x021B9B58 has no
 *   witness, because 0x021B9B58 is inside a data blob in asm/overlays/ov114.s (E59FC000 /
 *   E12FFF1C at 0x021B9B58, a second-level thunk to 0x02086028) and carries no func_ label.
 *
 * Tail-call thunk to the unnamed ARM stub at 0x021B9B58.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021B9B58(void);

void func_021BEFCC(void)
{
    func_021B9B58();
}
